#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "setupkeys.h"
#include "hid.h"

#define CONFIGURE_KEYS_REPORT_ID	(BYTE)0x3
#define READ_KEYS_REPORT_ID			(BYTE)0x4
#define CONFIGURE_KEYS_DELAY_MS		100

void usleep(__int64 usec)
{
	HANDLE timer;
	LARGE_INTEGER ft;

	ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}

PHID_DEVICE Find_My_Keyboard(PHID_DEVICE deviceList, ULONG numDevices,
						uint16_t Device_VID, uint16_t Device_PID, uint16_t Device_UsagePage, uint16_t Device_Usage)
{
	ULONG i;
	PHID_DEVICE my_device = NULL;
	if (!deviceList) return NULL;
	if (!numDevices) return NULL;
	for (i = 0; i < numDevices; i++)
	{
		if (INVALID_HANDLE_VALUE != deviceList[i].HidDevice)
		{
			if ((deviceList[i].Attributes.VendorID == Device_VID) &&
				(deviceList[i].Attributes.ProductID == Device_PID) &&
				(deviceList[i].Caps.UsagePage == Device_UsagePage) &&
				(deviceList[i].Caps.Usage == Device_Usage))
			{
				my_device = &deviceList[i];
				break;
			}
		}
	}
	return my_device;
}

int Write_to_device(uint8_t *p_buffer, uint8_t buf_size, uint16_t Device_VID, uint16_t Device_PID, uint16_t Device_UsagePage, uint16_t Device_Usage)
{
	HID_DEVICE			writeDevice;
	DWORD				bytesWritten = 0;
	BOOL				status = FALSE;
	ULONG				SetUsageStatus = 0;
	uint8_t				write_buffer[8];
	int					ret = 0;
	PHID_DEVICE			deviceList = NULL;
	ULONG				numDevices = 0;
	PHID_DEVICE			pDevice = NULL;

	if (!p_buffer) return -1;
	if (!buf_size) return -2;
	if (buf_size > 8) return -3;
	ZeroMemory(&writeDevice, sizeof(writeDevice));
	ZeroMemory(&write_buffer, 8);
	memcpy(write_buffer, p_buffer, buf_size);

	FindKnownHidDevices(&deviceList, &numDevices);
	pDevice = Find_My_Keyboard(deviceList, numDevices, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
	if (!pDevice) {
		if (deviceList) {
			free(deviceList);
			deviceList = NULL;
		}
		return -4;
	}

	status = OpenHidDevice(pDevice->DevicePath,
		FALSE,
		TRUE,
		FALSE,
		FALSE,
		&writeDevice);
	if (deviceList) {
		free(deviceList);
		deviceList = NULL;
		pDevice = NULL;
	}
	if (!status) return -5;

	SetUsageStatus = dll_HidP_SetUsageValue(HidP_Output,
		writeDevice.OutputData->UsagePage,
		0, // All Collections
		writeDevice.OutputData->ValueData.Usage,
		writeDevice.OutputData->ValueData.Value,
		writeDevice.Ppd,
		writeDevice.OutputReportBuffer,
		writeDevice.Caps.OutputReportByteLength);

	if (SetUsageStatus != HIDP_STATUS_SUCCESS)
	{
		ret = -6;
	} else {
		status = WriteFile(writeDevice.HidDevice,
			write_buffer,
			writeDevice.Caps.OutputReportByteLength,
			&bytesWritten,
			NULL);
		if (!status) ret = -7;
		if ((status) && (bytesWritten != (uint32_t)writeDevice.Caps.OutputReportByteLength)) ret = -8;
	}
	CloseHidDevice(&writeDevice);
	return ret;
}

int Read_from_device(_In_ BYTE reportID, _Out_ uint8_t *p_buffer, _In_ uint8_t buf_size,
	uint16_t Device_VID, uint16_t Device_PID, uint16_t Device_UsagePage, uint16_t Device_Usage)
{
	HID_DEVICE  syncDevice;
	BOOL status;
	PHID_DEVICE deviceList = NULL;
	ULONG       numDevices = 0;
	PHID_DEVICE	pDevice = NULL;
	int ret = 0;

	if (!p_buffer) return -1;
	if (!buf_size) return -2;

	RtlZeroMemory(&syncDevice, sizeof(syncDevice));

	FindKnownHidDevices(&deviceList, &numDevices);
	pDevice = Find_My_Keyboard(deviceList, numDevices, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
	if (!pDevice) {
		if (deviceList) {
			free(deviceList);
			deviceList = NULL;
		}
		return -3;
	}

	status = OpenHidDevice(pDevice->DevicePath,
		TRUE,
		FALSE,
		FALSE,
		FALSE,
		&syncDevice);
	if (deviceList) {
		free(deviceList);
		deviceList = NULL;
		pDevice = NULL;
	}
	if (!status) return -4;

	syncDevice.InputReportBuffer[0] = reportID;
	status = dll_HidD_GetInputReport(syncDevice.HidDevice,
		syncDevice.InputReportBuffer,
		syncDevice.Caps.InputReportByteLength);
	if (!status)
	{
		//printf("HidD_GetInputReport() failed. Error: 0x%X\n", GetLastError());
		ret = -5;
	} else {
		ZeroMemory(p_buffer, buf_size);
		ret = (syncDevice.Caps.InputReportByteLength<buf_size)?syncDevice.Caps.InputReportByteLength:buf_size;
		memcpy(p_buffer, syncDevice.InputReportBuffer, ret);
	}
	CloseHidDevice(&syncDevice);
	return ret;
}

int Read_Key_Settings(uint8_t key_num, uint8_t *p_usage_page, uint8_t *p_modifiers, uint16_t *p_scancode,
				uint16_t Device_VID, uint16_t Device_PID, uint16_t Device_UsagePage, uint16_t Device_Usage)
{
	uint8_t buf[6];
	int ret;
	int retry_count = 15; // 15 sec

	buf[0] = READ_KEYS_REPORT_ID;
	buf[1] = key_num;
	ret = Write_to_device(buf, 2, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
	while ((ret) && (retry_count)) {
		usleep(1 * 1000 * 1000); // 1 sec
		buf[0] = READ_KEYS_REPORT_ID;
		buf[1] = key_num;
		ret = Write_to_device(buf, 2, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
		retry_count--;
	};
	if (ret < 0) return -2;
	ZeroMemory(buf, 6);
	ret = Read_from_device(READ_KEYS_REPORT_ID, buf, 6, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
	if (ret < 6) return -3;
	if (buf[0] != READ_KEYS_REPORT_ID) return -4;
	if (buf[1] != key_num) return -5;
	if (p_usage_page) *p_usage_page = buf[2];
	if (p_modifiers) *p_modifiers = buf[3];
	if (p_scancode) *p_scancode = (uint16_t)((uint16_t)buf[4] | ((uint16_t)(buf[5]) << 8));
	return 0;
}

int Write_Key_Settings(uint8_t key_num, uint8_t usage_page, uint8_t modifiers, uint16_t scancode,
			uint16_t Device_VID, uint16_t Device_PID, uint16_t Device_UsagePage, uint16_t Device_Usage)
{
	uint8_t buf[6];
	int retry_count = 15; // 15 sec
	int ret;
	buf[0] = CONFIGURE_KEYS_REPORT_ID;
	buf[1] = key_num;
	buf[2] = usage_page;
	buf[3] = modifiers;
	buf[4] = (uint8_t)(scancode & 0xFF);
	buf[5] = (uint8_t)((scancode >> 8) & 0xFF);
	ret = Write_to_device(buf, 6, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
	if (ret < 0) return -2;
	usleep(CONFIGURE_KEYS_DELAY_MS * 1000);
	buf[0] = READ_KEYS_REPORT_ID;
	buf[1] = key_num;
	ret = Write_to_device(buf, 2, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
	while ((ret) && (retry_count)) {
		usleep(1 * 1000 * 1000); // 1 sec
		buf[0] = READ_KEYS_REPORT_ID;
		buf[1] = key_num;
		ret = Write_to_device(buf, 2, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
		retry_count--;
	};
	if (ret < 0) return -3;
	ZeroMemory(buf, 6);
	ret = Read_from_device(READ_KEYS_REPORT_ID, buf, 6, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
	if (ret < 6) return -4;
	if (buf[0] != READ_KEYS_REPORT_ID) return -5;
	if (buf[1] != key_num) return -6;
	if (buf[2] != usage_page) return -7;
	if (buf[3] != modifiers) return -8;
	if ((uint16_t)((uint16_t)buf[4] | ((uint16_t)(buf[5]) << 8)) != scancode) return -9;
	return 0;
}

int Check_ConnectDevice(uint16_t Device_VID, uint16_t Device_PID, uint16_t Device_UsagePage, uint16_t Device_Usage)
{
	PHID_DEVICE 	deviceList = NULL;
	ULONG       	numDevices = 0;
	PHID_DEVICE		pDevice = NULL;
	int 			ret = 0;

	FindKnownHidDevices(&deviceList, &numDevices);
	pDevice = Find_My_Keyboard(deviceList, numDevices, Device_VID, Device_PID, Device_UsagePage, Device_Usage);
	if (!pDevice) ret = -1;
	else ret = 0;
	if (deviceList) {
		free(deviceList);
		deviceList = NULL;
	}
	return ret;
}

