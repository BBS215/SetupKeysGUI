/*++

Copyright (c) Microsoft 1998, All Rights Reserved

Module Name:

    hid.h

Abstract:

    This module contains the declarations and definitions for use with the
    hid user mode client sample driver.

Environment:

    Kernel & user mode

--*/

#ifndef HID_H
#define HID_H

#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201) // nameless struct/union

#include "hidsdi.h"
#include "setupapi.h"
#include <tchar.h>



typedef struct _SP_FNCLASS_DEVICE_DATA {
   DWORD cbSize;
   GUID  FunctionClassGuid;
   TCHAR DevicePath [ANYSIZE_ARRAY];
} SP_FNCLASS_DEVICE_DATA, *PSP_FNCLASS_DEVICE_DATA;

BOOLEAN
SetupDiGetFunctionClassDeviceInfo (
   IN    HDEVINFO                DeviceInfoSet,
   IN    PSP_DEVINFO_DATA        DeviceInfoData,
   OUT   PSP_FNCLASS_DEVICE_DATA FunctionClassDeviceData,
   IN    DWORD                   FunctionClassDeviceDataSize,
   OUT   PDWORD                  RequiredSize
   );

#define ASSERT(x)

//
// A structure to hold the steady state data received from the hid device.
// Each time a read packet is received we fill in this structure.
// Each time we wish to write to a hid device we fill in this structure.
// This structure is here only for convenience.  Most real applications will
// have a more efficient way of moving the hid data to the read, write, and
// feature routines.
//
typedef struct _HID_DATA {
   BOOLEAN     IsButtonData;
   UCHAR       Reserved;
   USAGE       UsagePage;   // The usage page for which we are looking.
   ULONG       Status;      // The last status returned from the accessor function
                            // when updating this field.
   ULONG       ReportID;    // ReportID for this given data structure
   BOOLEAN     IsDataSet;   // Variable to track whether a given data structure
                            //  has already been added to a report structure

   union {
      struct {
         ULONG       UsageMin;       // Variables to track the usage minimum and max
         ULONG       UsageMax;       // If equal, then only a single usage
         ULONG       MaxUsageLength; // Usages buffer length.
         PUSAGE      Usages;         // list of usages (buttons ``down'' on the device.

      } ButtonData;
      struct {
         USAGE       Usage; // The usage describing this value;
         USHORT      Reserved;

         ULONG       Value;
         LONG        ScaledValue;
      } ValueData;
   };
} HID_DATA, *PHID_DATA;

typedef struct _HID_DEVICE {
    PTCHAR                DevicePath;
    HANDLE               HidDevice; // A file handle to the hid device.
    BOOL                 OpenedForRead;
    BOOL                 OpenedForWrite;
    BOOL                 OpenedOverlapped;
    BOOL                 OpenedExclusive;

    PHIDP_PREPARSED_DATA Ppd; // The opaque parser info describing this device
    HIDP_CAPS            Caps; // The Capabilities of this hid device.
    HIDD_ATTRIBUTES      Attributes;

    PCHAR                InputReportBuffer;
    _Field_size_(InputDataLength)
    PHID_DATA            InputData; // array of hid data structures
    ULONG                InputDataLength; // Num elements in this array.
    PHIDP_BUTTON_CAPS    InputButtonCaps;
    PHIDP_VALUE_CAPS     InputValueCaps;

    PCHAR                OutputReportBuffer;
    _Field_size_(OutputDataLength)
    PHID_DATA            OutputData;
    ULONG                OutputDataLength;
    PHIDP_BUTTON_CAPS    OutputButtonCaps;
    PHIDP_VALUE_CAPS     OutputValueCaps;

    PCHAR                FeatureReportBuffer;
    _Field_size_(FeatureDataLength) PHID_DATA            FeatureData;
    ULONG                FeatureDataLength;
    PHIDP_BUTTON_CAPS    FeatureButtonCaps;
    PHIDP_VALUE_CAPS     FeatureValueCaps;
} HID_DEVICE, *PHID_DEVICE;

typedef BOOL(__stdcall* t_SetupDiDestroyDeviceInfoList)(_In_ HDEVINFO);
typedef BOOL(__stdcall* t_SetupDiEnumDeviceInterfaces)
(_In_ HDEVINFO,
	_In_opt_ PSP_DEVINFO_DATA,
	_In_ CONST GUID*,
	_In_ DWORD,
	_Out_ PSP_DEVICE_INTERFACE_DATA);
typedef BOOL(__stdcall* t_SetupDiGetDeviceInterfaceDetailA)
(_In_ HDEVINFO,
	_In_ PSP_DEVICE_INTERFACE_DATA,
	_Inout_updates_bytes_to_opt_(DeviceInterfaceDetailDataSize, *RequiredSize) PSP_DEVICE_INTERFACE_DETAIL_DATA_A,
	_In_ DWORD,
	_Out_opt_ _Out_range_(>= , sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA_A)) PDWORD,
	_Out_opt_ PSP_DEVINFO_DATA);
typedef BOOL(__stdcall* t_SetupDiGetDeviceInterfaceDetailW)
(_In_ HDEVINFO,
	_In_ PSP_DEVICE_INTERFACE_DATA,
	_Out_writes_bytes_to_opt_(DeviceInterfaceDetailDataSize, *RequiredSize) PSP_DEVICE_INTERFACE_DETAIL_DATA_W,
	_In_ DWORD,
	_Out_opt_ _Out_range_(>= , sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA_W)) PDWORD,
	_Out_opt_ PSP_DEVINFO_DATA);
#ifdef UNICODE
#define dll_SetupDiGetDeviceInterfaceDetail dll_SetupDiGetDeviceInterfaceDetailW
#else
#define dll_SetupDiGetDeviceInterfaceDetail dll_SetupDiGetDeviceInterfaceDetailA
#endif
typedef HDEVINFO(__stdcall* t_SetupDiGetClassDevsA)
(_In_opt_ CONST GUID *,
	_In_opt_ PCSTR,
	_In_opt_ HWND,
	_In_ DWORD);
typedef HDEVINFO(__stdcall* t_SetupDiGetClassDevsW)
(_In_opt_ CONST GUID *,
	_In_opt_ PCWSTR,
	_In_opt_ HWND,
	_In_ DWORD);
#ifdef UNICODE
#define dll_SetupDiGetClassDevs dll_SetupDiGetClassDevsW
#else
#define dll_SetupDiGetClassDevs dll_SetupDiGetClassDevsA
#endif
typedef void (__stdcall* t_HidD_GetHidGuid)(OUT LPGUID);
typedef NTSTATUS(__stdcall* t_HidP_SetUsageValue)
	(_In_ HIDP_REPORT_TYPE,
	_In_ USAGE,
	_In_opt_ USHORT,
	_In_ USAGE,
	_In_ ULONG,
	_In_ PHIDP_PREPARSED_DATA,
	_Inout_updates_bytes_(ReportLength) PCHAR,
	_In_ ULONG);
typedef BOOLEAN(__stdcall* t_HidD_GetInputReport)
	(_In_ HANDLE,
	_Out_writes_bytes_(ReportBufferLength) PVOID,
	_In_ ULONG);
typedef NTSTATUS(__stdcall* t_HidP_GetCaps)
	(_In_      PHIDP_PREPARSED_DATA,
	_Out_     PHIDP_CAPS);
typedef NTSTATUS(__stdcall* t_HidP_GetButtonCaps)
	(_In_       HIDP_REPORT_TYPE,
	_Out_writes_to_(*ButtonCapsLength, *ButtonCapsLength) PHIDP_BUTTON_CAPS,
	_Inout_    PUSHORT,
	_In_       PHIDP_PREPARSED_DATA);
typedef NTSTATUS(__stdcall* t_HidP_GetValueCaps)
	(_In_       HIDP_REPORT_TYPE,
	_Out_writes_to_(*ValueCapsLength, *ValueCapsLength) PHIDP_VALUE_CAPS,
	_Inout_    PUSHORT,
	_In_       PHIDP_PREPARSED_DATA);
typedef ULONG(__stdcall* t_HidP_MaxUsageListLength)
	(_In_ HIDP_REPORT_TYPE,
	_In_opt_ USAGE, // Optional
	_In_ PHIDP_PREPARSED_DATA);
typedef BOOLEAN(__stdcall* t_HidD_GetAttributes)
	(_In_  HANDLE,
	_Out_ PHIDD_ATTRIBUTES);
typedef BOOLEAN(__stdcall* t_HidD_GetPreparsedData)
	(_In_   HANDLE,
	_Out_ _When_(return != 0, __drv_allocatesMem(Mem))  PHIDP_PREPARSED_DATA  *);
typedef BOOLEAN(__stdcall* t_HidD_FreePreparsedData)(_In_ __drv_freesMem(Mem) PHIDP_PREPARSED_DATA);

extern t_SetupDiDestroyDeviceInfoList		dll_SetupDiDestroyDeviceInfoList;
extern t_SetupDiEnumDeviceInterfaces		dll_SetupDiEnumDeviceInterfaces;
extern t_SetupDiGetDeviceInterfaceDetailA	dll_SetupDiGetDeviceInterfaceDetailA;
extern t_SetupDiGetDeviceInterfaceDetailW	dll_SetupDiGetDeviceInterfaceDetailW;
extern t_SetupDiGetClassDevsA				dll_SetupDiGetClassDevsA;
extern t_SetupDiGetClassDevsW				dll_SetupDiGetClassDevsW;
extern t_HidD_GetHidGuid					dll_HidD_GetHidGuid;
extern t_HidP_SetUsageValue					dll_HidP_SetUsageValue;
extern t_HidD_GetInputReport				dll_HidD_GetInputReport;
extern t_HidP_GetCaps						dll_HidP_GetCaps;
extern t_HidP_GetButtonCaps					dll_HidP_GetButtonCaps;
extern t_HidP_GetValueCaps					dll_HidP_GetValueCaps;
extern t_HidP_MaxUsageListLength			dll_HidP_MaxUsageListLength;
extern t_HidD_GetAttributes					dll_HidD_GetAttributes;
extern t_HidD_GetPreparsedData				dll_HidD_GetPreparsedData;
extern t_HidD_FreePreparsedData				dll_HidD_FreePreparsedData;

int LoadHIDLib(void);
void UnloadHIDLib(void);

BOOLEAN
OpenHidDevice (
    _In_     LPTSTR          DevicePath,
    _In_     BOOL           HasReadAccess,
    _In_     BOOL           HasWriteAccess,
    _In_     BOOL           IsOverlapped,
    _In_     BOOL           IsExclusive,
    _Out_    PHID_DEVICE    HidDevice
);

BOOLEAN
FindKnownHidDevices (
   OUT PHID_DEVICE * HidDevices, // A array of struct _HID_DEVICE
   OUT PULONG        NumberDevices // the length of this array.
   );

BOOLEAN
FillDeviceInfo(
    IN  PHID_DEVICE HidDevice
);

VOID
CloseHidDevices (
   OUT PHID_DEVICE   HidDevices, // A array of struct _HID_DEVICE
   OUT ULONG         NumberDevices // the length of this array.
   );

VOID
CloseHidDevice (
    IN PHID_DEVICE   HidDevice
    );


BOOLEAN
Read (
   PHID_DEVICE    HidDevice
   );

BOOLEAN
ReadOverlapped (
    PHID_DEVICE     HidDevice,
    HANDLE          CompletionEvent,
    LPOVERLAPPED    Overlap
   );

BOOLEAN
Write (
   PHID_DEVICE    HidDevice
   );

BOOLEAN
UnpackReport (
   _In_reads_bytes_(ReportBufferLength)PCHAR ReportBuffer,
   IN       USHORT               ReportBufferLength,
   IN       HIDP_REPORT_TYPE     ReportType,
   IN OUT   PHID_DATA            Data,
   IN       ULONG                DataLength,
   IN       PHIDP_PREPARSED_DATA Ppd
   );

BOOLEAN
PackReport (
   _Out_writes_bytes_(ReportBufferLength)PCHAR ReportBuffer,
   IN       USHORT               ReportBufferLength,
   IN       HIDP_REPORT_TYPE     ReportType,
   IN       PHID_DATA            Data,
   IN       ULONG                DataLength,
   IN       PHIDP_PREPARSED_DATA Ppd
   );

BOOLEAN
SetFeature (
   PHID_DEVICE    HidDevice
   );

BOOLEAN
GetFeature (
   PHID_DEVICE    HidDevice
   );

#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4201)
#endif

#endif


