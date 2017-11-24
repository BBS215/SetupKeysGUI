#pragma once

#ifdef __cplusplus
extern "C" {
#endif
int LoadHIDLib(void);
void UnloadHIDLib(void);
int Check_ConnectDevice(uint16_t Device_VID, uint16_t Device_PID, uint16_t Device_UsagePage, uint16_t Device_Usage);
int Write_Key_Settings(uint8_t key_num, uint8_t usage_page, uint8_t modifiers, uint16_t scancode,
		uint16_t Device_VID, uint16_t Device_PID, uint16_t Device_UsagePage, uint16_t Device_Usage);
int Read_Key_Settings(uint8_t key_num, uint8_t *p_usage_page, uint8_t *p_modifiers, uint16_t *p_scancode,
		uint16_t Device_VID, uint16_t Device_PID, uint16_t Device_UsagePage, uint16_t Device_Usage);

#ifdef __cplusplus
}
#endif

