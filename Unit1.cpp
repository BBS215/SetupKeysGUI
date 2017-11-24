//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "setupkeys.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int is_connected = 0;
uint16_t Device_VID;
uint16_t Device_PID;
uint16_t Device_UsagePage;
uint16_t Device_Usage;
t_KeySettings_Panel g_KeySettings_Panel[MAX_KEY_COUNT];
t_KeySettings g_KeySettings_Device[MAX_KEY_COUNT];
//t_KeySettings g_KeySettings_Active[MAX_KEY_COUNT];
TStringList *p_Empty_sc_List = NULL;
TStringList *p_STD_Keyboard_sc_List = NULL;
TStringList *p_EXT1_Keyboard_sc_List = NULL;
TStringList *p_EXT2_Keyboard_sc_List = NULL;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void Init_sc_List(void)
{
	p_Empty_sc_List = new TStringList();
	if (!p_Empty_sc_List) return;
	p_Empty_sc_List->Insert(0, L"00 - No Event");

	p_STD_Keyboard_sc_List = new TStringList();
	if (!p_STD_Keyboard_sc_List) return;
	p_STD_Keyboard_sc_List->Insert(0, L"00 - No Event");
	p_STD_Keyboard_sc_List->Insert(1, L"01 - ERROR_ROLLOVER");
	p_STD_Keyboard_sc_List->Insert(2, L"02 - POST_FAIL");
	p_STD_Keyboard_sc_List->Insert(3, L"03 - ERROR_UNDEFINED");
	p_STD_Keyboard_sc_List->Insert(4, L"04 - A");
	p_STD_Keyboard_sc_List->Insert(5, L"05 - B");
	p_STD_Keyboard_sc_List->Insert(6, L"06 - C");
	p_STD_Keyboard_sc_List->Insert(7, L"07 - D");
	p_STD_Keyboard_sc_List->Insert(8, L"08 - E");
	p_STD_Keyboard_sc_List->Insert(9, L"09 - F");
	p_STD_Keyboard_sc_List->Insert(10, L"0A - G");
	p_STD_Keyboard_sc_List->Insert(11, L"0B - H");
	p_STD_Keyboard_sc_List->Insert(12, L"0C - I");
	p_STD_Keyboard_sc_List->Insert(13, L"0D - J");
	p_STD_Keyboard_sc_List->Insert(14, L"0E - K");
	p_STD_Keyboard_sc_List->Insert(15, L"0F - L");
	p_STD_Keyboard_sc_List->Insert(16, L"10 - M");
	p_STD_Keyboard_sc_List->Insert(17, L"11 - N");
	p_STD_Keyboard_sc_List->Insert(18, L"12 - O");
	p_STD_Keyboard_sc_List->Insert(19, L"13 - P");
	p_STD_Keyboard_sc_List->Insert(20, L"14 - Q");
	p_STD_Keyboard_sc_List->Insert(21, L"15 - R");
	p_STD_Keyboard_sc_List->Insert(22, L"16 - S");
	p_STD_Keyboard_sc_List->Insert(23, L"17 - T");
	p_STD_Keyboard_sc_List->Insert(24, L"18 - U");
	p_STD_Keyboard_sc_List->Insert(25, L"19 - V");
	p_STD_Keyboard_sc_List->Insert(26, L"1A - W");
	p_STD_Keyboard_sc_List->Insert(27, L"1B - X");
	p_STD_Keyboard_sc_List->Insert(28, L"1C - Y");
	p_STD_Keyboard_sc_List->Insert(29, L"1D - Z");
	p_STD_Keyboard_sc_List->Insert(30, L"1E - 1_AND_EXCLAMATION");
	p_STD_Keyboard_sc_List->Insert(31, L"1F - 2_AND_AT");
	p_STD_Keyboard_sc_List->Insert(32, L"20 - 3_AND_HASHMARK");
	p_STD_Keyboard_sc_List->Insert(33, L"21 - 4_AND_DOLLAR");
	p_STD_Keyboard_sc_List->Insert(34, L"22 - 5_AND_PERCENTAGE");
	p_STD_Keyboard_sc_List->Insert(35, L"23 - 6_AND_CARET");
	p_STD_Keyboard_sc_List->Insert(36, L"24 - 7_AND_AMPERSAND");
	p_STD_Keyboard_sc_List->Insert(37, L"25 - 8_AND_ASTERISK");
	p_STD_Keyboard_sc_List->Insert(38, L"26 - 9_AND_OPENING_PARENTHESIS");
	p_STD_Keyboard_sc_List->Insert(39, L"27 - 0_AND_CLOSING_PARENTHESIS");
	p_STD_Keyboard_sc_List->Insert(40, L"28 - ENTER");
	p_STD_Keyboard_sc_List->Insert(41, L"29 - ESCAPE");
	p_STD_Keyboard_sc_List->Insert(42, L"2A - BACKSPACE");
	p_STD_Keyboard_sc_List->Insert(43, L"2B - TAB");
	p_STD_Keyboard_sc_List->Insert(44, L"2C - SPACE");
	p_STD_Keyboard_sc_List->Insert(45, L"2D - MINUS_AND_UNDERSCORE");
	p_STD_Keyboard_sc_List->Insert(46, L"2E - EQUAL_AND_PLUS");
	p_STD_Keyboard_sc_List->Insert(47, L"2F - OPENING_BRACKET_AND_BRACE");
	p_STD_Keyboard_sc_List->Insert(48, L"30 - CLOSING_BRACKET_AND_BRACE");
	p_STD_Keyboard_sc_List->Insert(49, L"31 - BACKSLASH_AND_PIPE");
	p_STD_Keyboard_sc_List->Insert(50, L"32 - NON_US_HASHMARK_AND_TILDE");
	p_STD_Keyboard_sc_List->Insert(51, L"33 - SEMICOLON_AND_COLON");
	p_STD_Keyboard_sc_List->Insert(52, L"34 - APOSTROPHE_AND_QUOTE");
	p_STD_Keyboard_sc_List->Insert(53, L"35 - GRAVE_ACCENT_AND_TILDE");
	p_STD_Keyboard_sc_List->Insert(54, L"36 - COMMA_AND_LESS_THAN_SIGN");
	p_STD_Keyboard_sc_List->Insert(55, L"37 - DOT_AND_GREATER_THAN_SIGN");
	p_STD_Keyboard_sc_List->Insert(56, L"38 - SLASH_AND_QUESTION_MARK");
	p_STD_Keyboard_sc_List->Insert(57, L"39 - CAPS_LOCK");
	p_STD_Keyboard_sc_List->Insert(58, L"3A - F1");
	p_STD_Keyboard_sc_List->Insert(59, L"3B - F2");
	p_STD_Keyboard_sc_List->Insert(60, L"3C - F3");
	p_STD_Keyboard_sc_List->Insert(61, L"3D - F4");
	p_STD_Keyboard_sc_List->Insert(62, L"3E - F5");
	p_STD_Keyboard_sc_List->Insert(63, L"3F - F6");
	p_STD_Keyboard_sc_List->Insert(64, L"40 - F7");
	p_STD_Keyboard_sc_List->Insert(65, L"41 - F8");
	p_STD_Keyboard_sc_List->Insert(66, L"42 - F9");
	p_STD_Keyboard_sc_List->Insert(67, L"43 - F10");
	p_STD_Keyboard_sc_List->Insert(68, L"44 - F11");
	p_STD_Keyboard_sc_List->Insert(69, L"45 - F12");
	p_STD_Keyboard_sc_List->Insert(70, L"46 - PRINT_SCREEN");
	p_STD_Keyboard_sc_List->Insert(71, L"47 - SCROLL_LOCK");
	p_STD_Keyboard_sc_List->Insert(72, L"48 - PAUSE");
	p_STD_Keyboard_sc_List->Insert(73, L"49 - INSERT");
	p_STD_Keyboard_sc_List->Insert(74, L"4A - HOME");
	p_STD_Keyboard_sc_List->Insert(75, L"4B - PAGE_UP");
	p_STD_Keyboard_sc_List->Insert(76, L"4C - DELETE");
	p_STD_Keyboard_sc_List->Insert(77, L"4D - END");
	p_STD_Keyboard_sc_List->Insert(78, L"4E - PAGE_DOWN");
	p_STD_Keyboard_sc_List->Insert(79, L"4F - RIGHT_ARROW");
	p_STD_Keyboard_sc_List->Insert(80, L"50 - LEFT_ARROW");
	p_STD_Keyboard_sc_List->Insert(81, L"51 - DOWN_ARROW");
	p_STD_Keyboard_sc_List->Insert(82, L"52 - UP_ARROW");
	p_STD_Keyboard_sc_List->Insert(83, L"53 - NUM_LOCK");
	p_STD_Keyboard_sc_List->Insert(84, L"54 - KEYPAD_SLASH");
	p_STD_Keyboard_sc_List->Insert(85, L"55 - KEYPAD_ASTERISK");
	p_STD_Keyboard_sc_List->Insert(86, L"56 - KEYPAD_MINUS");
	p_STD_Keyboard_sc_List->Insert(87, L"57 - KEYPAD_PLUS");
	p_STD_Keyboard_sc_List->Insert(88, L"58 - KEYPAD_ENTER");
	p_STD_Keyboard_sc_List->Insert(89, L"59 - KEYPAD_1_AND_END");
	p_STD_Keyboard_sc_List->Insert(90, L"5A - KEYPAD_2_AND_DOWN_ARROW");
	p_STD_Keyboard_sc_List->Insert(91, L"5B - KEYPAD_3_AND_PAGE_DOWN");
	p_STD_Keyboard_sc_List->Insert(92, L"5C - KEYPAD_4_AND_LEFT_ARROW");
	p_STD_Keyboard_sc_List->Insert(93, L"5D - KEYPAD_5");
	p_STD_Keyboard_sc_List->Insert(94, L"5E - KEYPAD_6_AND_RIGHT_ARROW");
	p_STD_Keyboard_sc_List->Insert(95, L"5F - KEYPAD_7_AND_HOME");
	p_STD_Keyboard_sc_List->Insert(96, L"60 - KEYPAD_8_AND_UP_ARROW");
	p_STD_Keyboard_sc_List->Insert(97, L"61 - KEYPAD_9_AND_PAGE_UP");
	p_STD_Keyboard_sc_List->Insert(98, L"62 - KEYPAD_0_AND_INSERT");
	p_STD_Keyboard_sc_List->Insert(99, L"63 - KEYPAD_DOT_AND_DELETE");
	p_STD_Keyboard_sc_List->Insert(100, L"64 - NON_US_BACKSLASH_AND_PIPE");
	p_STD_Keyboard_sc_List->Insert(101, L"65 - APPLICATION");
	p_STD_Keyboard_sc_List->Insert(102, L"66 - POWER");
	p_STD_Keyboard_sc_List->Insert(103, L"67 - KEYPAD_EQUAL_SIGN");
	p_STD_Keyboard_sc_List->Insert(104, L"68 - F13");
	p_STD_Keyboard_sc_List->Insert(105, L"69 - F14");
	p_STD_Keyboard_sc_List->Insert(106, L"6A - F15");
	p_STD_Keyboard_sc_List->Insert(107, L"6B - F16");
	p_STD_Keyboard_sc_List->Insert(108, L"6C - F17");
	p_STD_Keyboard_sc_List->Insert(109, L"6D - F18");
	p_STD_Keyboard_sc_List->Insert(110, L"6E - F19");
	p_STD_Keyboard_sc_List->Insert(111, L"6F - F20");
	p_STD_Keyboard_sc_List->Insert(112, L"70 - F21");
	p_STD_Keyboard_sc_List->Insert(113, L"71 - F22");
	p_STD_Keyboard_sc_List->Insert(114, L"72 - F23");
	p_STD_Keyboard_sc_List->Insert(115, L"73 - F24");
	p_STD_Keyboard_sc_List->Insert(116, L"74 - EXECUTE");
	p_STD_Keyboard_sc_List->Insert(117, L"75 - HELP");
	p_STD_Keyboard_sc_List->Insert(118, L"76 - MENU");
	p_STD_Keyboard_sc_List->Insert(119, L"77 - SELECT");
	p_STD_Keyboard_sc_List->Insert(120, L"78 - STOP");
	p_STD_Keyboard_sc_List->Insert(121, L"79 - AGAIN");
	p_STD_Keyboard_sc_List->Insert(122, L"7A - UNDO");
	p_STD_Keyboard_sc_List->Insert(123, L"7B - CUT");
	p_STD_Keyboard_sc_List->Insert(124, L"7C - COPY");
	p_STD_Keyboard_sc_List->Insert(125, L"7D - PASTE");
	p_STD_Keyboard_sc_List->Insert(126, L"7E - FIND");
	p_STD_Keyboard_sc_List->Insert(127, L"7F - MUTE");
	p_STD_Keyboard_sc_List->Insert(128, L"80 - VOLUME_UP");
	p_STD_Keyboard_sc_List->Insert(129, L"81 - VOLUME_DOWN");
	p_STD_Keyboard_sc_List->Insert(130, L"82 - LOCKING_CAPS_LOCK");
	p_STD_Keyboard_sc_List->Insert(131, L"83 - LOCKING_NUM_LOCK");
	p_STD_Keyboard_sc_List->Insert(132, L"84 - LOCKING_SCROLL_LOCK");
	p_STD_Keyboard_sc_List->Insert(133, L"85 - KEYPAD_COMMA");
	p_STD_Keyboard_sc_List->Insert(134, L"86 - KEYPAD_EQUAL_SIGN_AS400");
	p_STD_Keyboard_sc_List->Insert(135, L"87 - INTERNATIONAL1");
	p_STD_Keyboard_sc_List->Insert(136, L"88 - INTERNATIONAL2");
	p_STD_Keyboard_sc_List->Insert(137, L"89 - INTERNATIONAL3");
	p_STD_Keyboard_sc_List->Insert(138, L"8A - INTERNATIONAL4");
	p_STD_Keyboard_sc_List->Insert(139, L"8B - INTERNATIONAL5");
	p_STD_Keyboard_sc_List->Insert(140, L"8C - INTERNATIONAL6");
	p_STD_Keyboard_sc_List->Insert(141, L"8D - INTERNATIONAL7");
	p_STD_Keyboard_sc_List->Insert(142, L"8E - INTERNATIONAL8");
	p_STD_Keyboard_sc_List->Insert(143, L"8F - INTERNATIONAL9");
	p_STD_Keyboard_sc_List->Insert(144, L"90 - LANG1");
	p_STD_Keyboard_sc_List->Insert(145, L"91 - LANG2");
	p_STD_Keyboard_sc_List->Insert(146, L"92 - LANG3");
	p_STD_Keyboard_sc_List->Insert(147, L"93 - LANG4");
	p_STD_Keyboard_sc_List->Insert(148, L"94 - LANG5");
	p_STD_Keyboard_sc_List->Insert(149, L"95 - LANG6");
	p_STD_Keyboard_sc_List->Insert(150, L"96 - LANG7");
	p_STD_Keyboard_sc_List->Insert(151, L"97 - LANG8");
	p_STD_Keyboard_sc_List->Insert(152, L"98 - LANG9");
	p_STD_Keyboard_sc_List->Insert(153, L"99 - ALTERNATE_ERASE");
	p_STD_Keyboard_sc_List->Insert(154, L"9A - SYSREQ");
	p_STD_Keyboard_sc_List->Insert(155, L"9B - CANCEL");
	p_STD_Keyboard_sc_List->Insert(156, L"9C - CLEAR");
	p_STD_Keyboard_sc_List->Insert(157, L"9D - PRIOR");
	p_STD_Keyboard_sc_List->Insert(158, L"9E - RETURN");
	p_STD_Keyboard_sc_List->Insert(159, L"9F - SEPARATOR");
	p_STD_Keyboard_sc_List->Insert(160, L"A0 - OUT");
	p_STD_Keyboard_sc_List->Insert(161, L"A1 - OPER");
	p_STD_Keyboard_sc_List->Insert(162, L"A2 - CLEAR_AND_AGAIN");
	p_STD_Keyboard_sc_List->Insert(163, L"A3 - CRSEL_AND_PROPS");
	p_STD_Keyboard_sc_List->Insert(164, L"A4 - EXSEL");
	p_STD_Keyboard_sc_List->Insert(165, L"A5 - Reserved");
	p_STD_Keyboard_sc_List->Insert(166, L"A6 - Reserved");
	p_STD_Keyboard_sc_List->Insert(167, L"A7 - Reserved");
	p_STD_Keyboard_sc_List->Insert(168, L"A8 - Reserved");
	p_STD_Keyboard_sc_List->Insert(169, L"A9 - Reserved");
	p_STD_Keyboard_sc_List->Insert(170, L"AA - Reserved");
	p_STD_Keyboard_sc_List->Insert(171, L"AB - Reserved");
	p_STD_Keyboard_sc_List->Insert(172, L"AC - Reserved");
	p_STD_Keyboard_sc_List->Insert(173, L"AD - Reserved");
	p_STD_Keyboard_sc_List->Insert(174, L"AE - Reserved");
	p_STD_Keyboard_sc_List->Insert(175, L"AF - Reserved");
	p_STD_Keyboard_sc_List->Insert(176, L"B0 - KEYPAD_00");
	p_STD_Keyboard_sc_List->Insert(177, L"B1 - KEYPAD_000");
	p_STD_Keyboard_sc_List->Insert(178, L"B2 - THOUSANDS_SEPARATOR");
	p_STD_Keyboard_sc_List->Insert(179, L"B3 - DECIMAL_SEPARATOR");
	p_STD_Keyboard_sc_List->Insert(180, L"B4 - CURRENCY_UNIT");
	p_STD_Keyboard_sc_List->Insert(181, L"B5 - CURRENCY_SUB_UNIT");
	p_STD_Keyboard_sc_List->Insert(182, L"B6 - KEYPAD_OPENING_PARENTHESIS");
	p_STD_Keyboard_sc_List->Insert(183, L"B7 - KEYPAD_CLOSING_PARENTHESIS");
	p_STD_Keyboard_sc_List->Insert(184, L"B8 - KEYPAD_OPENING_BRACE");
	p_STD_Keyboard_sc_List->Insert(185, L"B9 - KEYPAD_CLOSING_BRACE");
	p_STD_Keyboard_sc_List->Insert(186, L"BA - KEYPAD_TAB");
	p_STD_Keyboard_sc_List->Insert(187, L"BB - KEYPAD_BACKSPACE");
	p_STD_Keyboard_sc_List->Insert(188, L"BC - KEYPAD_A");
	p_STD_Keyboard_sc_List->Insert(189, L"BD - KEYPAD_B");
	p_STD_Keyboard_sc_List->Insert(190, L"BE - KEYPAD_C");
	p_STD_Keyboard_sc_List->Insert(191, L"BF - KEYPAD_D");
	p_STD_Keyboard_sc_List->Insert(192, L"C0 - KEYPAD_E");
	p_STD_Keyboard_sc_List->Insert(193, L"C1 - KEYPAD_F");
	p_STD_Keyboard_sc_List->Insert(194, L"C2 - KEYPAD_XOR");
	p_STD_Keyboard_sc_List->Insert(195, L"C3 - KEYPAD_CARET");
	p_STD_Keyboard_sc_List->Insert(196, L"C4 - KEYPAD_PERCENTAGE");
	p_STD_Keyboard_sc_List->Insert(197, L"C5 - KEYPAD_LESS_THAN_SIGN");
	p_STD_Keyboard_sc_List->Insert(198, L"C6 - KEYPAD_GREATER_THAN_SIGN");
	p_STD_Keyboard_sc_List->Insert(199, L"C7 - KEYPAD_AMP");
	p_STD_Keyboard_sc_List->Insert(200, L"C8 - KEYPAD_AMP_AMP");
	p_STD_Keyboard_sc_List->Insert(201, L"C9 - KEYPAD_PIPE");
	p_STD_Keyboard_sc_List->Insert(202, L"CA - KEYPAD_PIPE_PIPE");
	p_STD_Keyboard_sc_List->Insert(203, L"CB - KEYPAD_COLON");
	p_STD_Keyboard_sc_List->Insert(204, L"CC - KEYPAD_HASHMARK");
	p_STD_Keyboard_sc_List->Insert(205, L"CD - KEYPAD_SPACE");
	p_STD_Keyboard_sc_List->Insert(206, L"CE - KEYPAD_AT");
	p_STD_Keyboard_sc_List->Insert(207, L"CF - KEYPAD_EXCLAMATION_SIGN");
	p_STD_Keyboard_sc_List->Insert(208, L"D0 - KEYPAD_MEMORY_STORE");
	p_STD_Keyboard_sc_List->Insert(209, L"D1 - KEYPAD_MEMORY_RECALL");
	p_STD_Keyboard_sc_List->Insert(210, L"D2 - KEYPAD_MEMORY_CLEAR");
	p_STD_Keyboard_sc_List->Insert(211, L"D3 - KEYPAD_MEMORY_ADD");
	p_STD_Keyboard_sc_List->Insert(212, L"D4 - KEYPAD_MEMORY_SUBTRACT");
	p_STD_Keyboard_sc_List->Insert(213, L"D5 - KEYPAD_MEMORY_MULTIPLY");
	p_STD_Keyboard_sc_List->Insert(214, L"D6 - KEYPAD_MEMORY_DIVIDE");
	p_STD_Keyboard_sc_List->Insert(215, L"D7 - KEYPAD_PLUS_AND_MINUS");
	p_STD_Keyboard_sc_List->Insert(216, L"D8 - KEYPAD_CLEAR");
	p_STD_Keyboard_sc_List->Insert(217, L"D9 - KEYPAD_CLEAR_ENTRY");
	p_STD_Keyboard_sc_List->Insert(218, L"DA - KEYPAD_BINARY");
	p_STD_Keyboard_sc_List->Insert(219, L"DB - KEYPAD_OCTAL");
	p_STD_Keyboard_sc_List->Insert(220, L"DC - KEYPAD_DECIMAL");
	p_STD_Keyboard_sc_List->Insert(221, L"DD - KEYPAD_HEXADECIMAL");
	p_STD_Keyboard_sc_List->Insert(222, L"DE - Reserved");
	p_STD_Keyboard_sc_List->Insert(223, L"DF - Reserved");
	p_STD_Keyboard_sc_List->Insert(224, L"E0 - LEFT_CONTROL");
	p_STD_Keyboard_sc_List->Insert(225, L"E1 - LEFT_SHIFT");
	p_STD_Keyboard_sc_List->Insert(226, L"E2 - LEFT_ALT");
	p_STD_Keyboard_sc_List->Insert(227, L"E3 - LEFT_GUI");
	p_STD_Keyboard_sc_List->Insert(228, L"E4 - RIGHT_CONTROL");
	p_STD_Keyboard_sc_List->Insert(229, L"E5 - RIGHT_SHIFT");
	p_STD_Keyboard_sc_List->Insert(230, L"E6 - RIGHT_ALT");
	p_STD_Keyboard_sc_List->Insert(231, L"E7 - RIGHT_GUI");

	p_EXT1_Keyboard_sc_List = new TStringList();
	if (!p_EXT1_Keyboard_sc_List) return;
	p_EXT1_Keyboard_sc_List->Add(L"00 - No Event");
	/// 31 01-1F	Reserved
	p_EXT1_Keyboard_sc_List->Add(L"20 - +10");
	p_EXT1_Keyboard_sc_List->Add(L"21 - +100");
	p_EXT1_Keyboard_sc_List->Add(L"22 - AM/PM");
	/// 13 23-3F	Reserved
	p_EXT1_Keyboard_sc_List->Add(L"30 - Power");
	p_EXT1_Keyboard_sc_List->Add(L"31 - Reset");
	p_EXT1_Keyboard_sc_List->Add(L"32 - Sleep");
	p_EXT1_Keyboard_sc_List->Add(L"33 - Sleep After");
	p_EXT1_Keyboard_sc_List->Add(L"34 - Sleep Mode");
	p_EXT1_Keyboard_sc_List->Add(L"35 - Illumination");
	p_EXT1_Keyboard_sc_List->Add(L"36 - Function Buttons");
	p_EXT1_Keyboard_sc_List->Add(L"37 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"38 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"39 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"3A - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"3B - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"3C - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"3D - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"3E - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"3F - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"40 - Menu");
	p_EXT1_Keyboard_sc_List->Add(L"41 - Menu Pick");
	p_EXT1_Keyboard_sc_List->Add(L"42 - Menu Up");
	p_EXT1_Keyboard_sc_List->Add(L"43 - Menu Down");
	p_EXT1_Keyboard_sc_List->Add(L"44 - Menu Left");
	p_EXT1_Keyboard_sc_List->Add(L"45 - Menu Right");
	p_EXT1_Keyboard_sc_List->Add(L"46 - Menu Escape");
	p_EXT1_Keyboard_sc_List->Add(L"47 - Menu Value Increase");
	p_EXT1_Keyboard_sc_List->Add(L"48 - Menu Value Decrease");
	/// 23 49-5F	Reserved
	p_EXT1_Keyboard_sc_List->Add(L"60 - Data On Screen");
	p_EXT1_Keyboard_sc_List->Add(L"61 - Closed Caption");
	p_EXT1_Keyboard_sc_List->Add(L"62 - Closed Caption Select");
	p_EXT1_Keyboard_sc_List->Add(L"63 - VCR/TV");
	p_EXT1_Keyboard_sc_List->Add(L"64 - Broadcast Mode");
	p_EXT1_Keyboard_sc_List->Add(L"65 - Snapshot");
	p_EXT1_Keyboard_sc_List->Add(L"66 - Still");
	/// 25 67-7F	Reserved
	p_EXT1_Keyboard_sc_List->Add(L"80 - Selection");
	p_EXT1_Keyboard_sc_List->Add(L"81 - Assign Selection");
	p_EXT1_Keyboard_sc_List->Add(L"82 - Mode Step");
	p_EXT1_Keyboard_sc_List->Add(L"83 - Recall Last");
	p_EXT1_Keyboard_sc_List->Add(L"84 - Enter Channel");
	p_EXT1_Keyboard_sc_List->Add(L"85 - Order Movie");
	p_EXT1_Keyboard_sc_List->Add(L"86 - Channel");
	p_EXT1_Keyboard_sc_List->Add(L"87 - Media Selection");
	p_EXT1_Keyboard_sc_List->Add(L"88 - Media Select Computer");
	p_EXT1_Keyboard_sc_List->Add(L"89 - Media Select TV");
	p_EXT1_Keyboard_sc_List->Add(L"8A - Media Select WWW");
	p_EXT1_Keyboard_sc_List->Add(L"8B - Media Select DVD");
	p_EXT1_Keyboard_sc_List->Add(L"8C - Media Select Telephone");
	p_EXT1_Keyboard_sc_List->Add(L"8D - Media Select Program Guide");
	p_EXT1_Keyboard_sc_List->Add(L"8E - Media Select Video Phone");
	p_EXT1_Keyboard_sc_List->Add(L"8F - Media Select Games");
	p_EXT1_Keyboard_sc_List->Add(L"90 - Media Select Messages");
	p_EXT1_Keyboard_sc_List->Add(L"91 - Media Select CD");
	p_EXT1_Keyboard_sc_List->Add(L"92 - Media Select VCR");
	p_EXT1_Keyboard_sc_List->Add(L"93 - Media Select Tuner");
	p_EXT1_Keyboard_sc_List->Add(L"94 - Quit");
	p_EXT1_Keyboard_sc_List->Add(L"95 - Help");
	p_EXT1_Keyboard_sc_List->Add(L"96 - Media Select Tape");
	p_EXT1_Keyboard_sc_List->Add(L"97 - Media Select Cable");
	p_EXT1_Keyboard_sc_List->Add(L"98 - Media Select Satellite");
	p_EXT1_Keyboard_sc_List->Add(L"99 - Media Select Security");
	p_EXT1_Keyboard_sc_List->Add(L"9A - Media Select Home");
	p_EXT1_Keyboard_sc_List->Add(L"9B - Media Select Call");
	p_EXT1_Keyboard_sc_List->Add(L"9C - Channel Increment");
	p_EXT1_Keyboard_sc_List->Add(L"9D - Channel Decrement");
	p_EXT1_Keyboard_sc_List->Add(L"9E - Media Select SAP");
	p_EXT1_Keyboard_sc_List->Add(L"9F - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"A0 - VCR Plus");
	p_EXT1_Keyboard_sc_List->Add(L"A1 - Once");
	p_EXT1_Keyboard_sc_List->Add(L"A2 - Daily");
	p_EXT1_Keyboard_sc_List->Add(L"A3 - Weekly");
	p_EXT1_Keyboard_sc_List->Add(L"A4 - Monthly");
	p_EXT1_Keyboard_sc_List->Add(L"A5 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"A6 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"A7 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"A8 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"A9 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"AA - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"AB - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"AC - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"AD - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"AE - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"AF - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"B0 - Play");
	p_EXT1_Keyboard_sc_List->Add(L"B1 - Pause");
	p_EXT1_Keyboard_sc_List->Add(L"B2 - Record");
	p_EXT1_Keyboard_sc_List->Add(L"B3 - Fast Forward");
	p_EXT1_Keyboard_sc_List->Add(L"B4 - Rewind");
	p_EXT1_Keyboard_sc_List->Add(L"B5 - Scan Next Track");
	p_EXT1_Keyboard_sc_List->Add(L"B6 - Scan Previous Track");
	p_EXT1_Keyboard_sc_List->Add(L"B7 - Stop");
	p_EXT1_Keyboard_sc_List->Add(L"B8 - Eject");
	p_EXT1_Keyboard_sc_List->Add(L"B9 - Random Play");
	p_EXT1_Keyboard_sc_List->Add(L"BA - Select Disc");
	p_EXT1_Keyboard_sc_List->Add(L"BB - Enter Disc");
	p_EXT1_Keyboard_sc_List->Add(L"BC - Repeat");
	p_EXT1_Keyboard_sc_List->Add(L"BD - Tracking");
	p_EXT1_Keyboard_sc_List->Add(L"BE - Track Normal");
	p_EXT1_Keyboard_sc_List->Add(L"BF - Slow Tracking");
	p_EXT1_Keyboard_sc_List->Add(L"C0 - Frame Forward");
	p_EXT1_Keyboard_sc_List->Add(L"C1 - Frame Back");
	p_EXT1_Keyboard_sc_List->Add(L"C2 - Mark");
	p_EXT1_Keyboard_sc_List->Add(L"C3 - Clear Mark");
	p_EXT1_Keyboard_sc_List->Add(L"C4 - Repeat From Mark");
	p_EXT1_Keyboard_sc_List->Add(L"C5 - Return To Mark");
	p_EXT1_Keyboard_sc_List->Add(L"C6 - Search Mark Forward");
	p_EXT1_Keyboard_sc_List->Add(L"C7 - Search Mark Backwards");
	p_EXT1_Keyboard_sc_List->Add(L"C8 - Counter Reset");
	p_EXT1_Keyboard_sc_List->Add(L"C9 - Show Counter");
	p_EXT1_Keyboard_sc_List->Add(L"CA - Tracking Increment");
	p_EXT1_Keyboard_sc_List->Add(L"CB - Tracking Decrement");
	p_EXT1_Keyboard_sc_List->Add(L"CC - Stop/Eject");
	p_EXT1_Keyboard_sc_List->Add(L"CD - Play/Pause");
	p_EXT1_Keyboard_sc_List->Add(L"CE - Play/Skip");
	/// 17 CF-DF	Reserved
	p_EXT1_Keyboard_sc_List->Add(L"E0 - Volume");
	p_EXT1_Keyboard_sc_List->Add(L"E1 - Balance");
	p_EXT1_Keyboard_sc_List->Add(L"E2 - Mute");
	p_EXT1_Keyboard_sc_List->Add(L"E3 - Bass");
	p_EXT1_Keyboard_sc_List->Add(L"E4 - Treble");
	p_EXT1_Keyboard_sc_List->Add(L"E5 - Bass Boost");
	p_EXT1_Keyboard_sc_List->Add(L"E6 - Surround Mode");
	p_EXT1_Keyboard_sc_List->Add(L"E7 - Loudness");
	p_EXT1_Keyboard_sc_List->Add(L"E8 - MPX");
	p_EXT1_Keyboard_sc_List->Add(L"E9 - Volume Increment");
	p_EXT1_Keyboard_sc_List->Add(L"EA - Volume Decrement");
	p_EXT1_Keyboard_sc_List->Add(L"EB - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"EC - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"ED - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"EE - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"EF - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"F0 - Speed Select");
	p_EXT1_Keyboard_sc_List->Add(L"F1 - Playback Speed");
	p_EXT1_Keyboard_sc_List->Add(L"F2 - Standard Play");
	p_EXT1_Keyboard_sc_List->Add(L"F3 - Long Play");
	p_EXT1_Keyboard_sc_List->Add(L"F4 - Extended Play");
	p_EXT1_Keyboard_sc_List->Add(L"F5 - Slow");
	p_EXT1_Keyboard_sc_List->Add(L"F6 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"F7 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"F8 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"F9 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"FA - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"FB - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"FC - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"FD - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"FE - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"FF - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"100 - Fan Enable");
	p_EXT1_Keyboard_sc_List->Add(L"101 - Fan Speed");
	p_EXT1_Keyboard_sc_List->Add(L"102 - Light Enable");
	p_EXT1_Keyboard_sc_List->Add(L"103 - Light Illumination Level");
	p_EXT1_Keyboard_sc_List->Add(L"104 - Climate Control Enable");
	p_EXT1_Keyboard_sc_List->Add(L"105 - Room Temperature");
	p_EXT1_Keyboard_sc_List->Add(L"106 - Security Enable");
	p_EXT1_Keyboard_sc_List->Add(L"107 - Fire Alarm");
	p_EXT1_Keyboard_sc_List->Add(L"108 - Police Alarm");
	p_EXT1_Keyboard_sc_List->Add(L"109 - Proximity");
	p_EXT1_Keyboard_sc_List->Add(L"10A - Motion");
	p_EXT1_Keyboard_sc_List->Add(L"10B - Duress Alarm");
	p_EXT1_Keyboard_sc_List->Add(L"10C - Holdup Alarm");
	p_EXT1_Keyboard_sc_List->Add(L"10D - Medical Alarm");
	/// 66 10E-14F	Reserved
	p_EXT1_Keyboard_sc_List->Add(L"150 - Balance Right");
	p_EXT1_Keyboard_sc_List->Add(L"151 - Balance Left");
	p_EXT1_Keyboard_sc_List->Add(L"152 - Bass Increment");
	p_EXT1_Keyboard_sc_List->Add(L"153 - Bass Decrement");
	p_EXT1_Keyboard_sc_List->Add(L"154 - Treble Increment");
	p_EXT1_Keyboard_sc_List->Add(L"155 - Treble Decrement");
	p_EXT1_Keyboard_sc_List->Add(L"156 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"157 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"158 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"159 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"15A - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"15B - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"15C - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"15D - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"15E - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"15F - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"160 - Speaker System");
	p_EXT1_Keyboard_sc_List->Add(L"161 - Channel Left");
	p_EXT1_Keyboard_sc_List->Add(L"162 - Channel Right");
	p_EXT1_Keyboard_sc_List->Add(L"163 - Channel Center");
	p_EXT1_Keyboard_sc_List->Add(L"164 - Channel Front");
	p_EXT1_Keyboard_sc_List->Add(L"165 - Channel Center Front");
	p_EXT1_Keyboard_sc_List->Add(L"166 - Channel Side");
	p_EXT1_Keyboard_sc_List->Add(L"167 - Channel Surround");
	p_EXT1_Keyboard_sc_List->Add(L"168 - Channel Low Freq Enhancement");
	p_EXT1_Keyboard_sc_List->Add(L"169 - Channel Top");
	p_EXT1_Keyboard_sc_List->Add(L"16A - Channel Unknown");
	p_EXT1_Keyboard_sc_List->Add(L"16B - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"16C - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"16D - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"16E - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"16F - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"170 - Sub-channel");
	p_EXT1_Keyboard_sc_List->Add(L"171 - Sub-channel Increment");
	p_EXT1_Keyboard_sc_List->Add(L"172 - Sub-channel Decrement");
	p_EXT1_Keyboard_sc_List->Add(L"173 - Alternate Audio Increment");
	p_EXT1_Keyboard_sc_List->Add(L"174 - Alternate Audio Decrement");
	p_EXT1_Keyboard_sc_List->Add(L"175 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"176 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"177 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"178 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"179 - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"17A - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"17B - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"17C - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"17D - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"17E - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"17F - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"180 - Application Launch Buttons");
	p_EXT1_Keyboard_sc_List->Add(L"181 - AL Launch Button Config Tool");
	p_EXT1_Keyboard_sc_List->Add(L"182 - AL Programmable Button Config");
	p_EXT1_Keyboard_sc_List->Add(L"183 - AL Consumer Control Config");
	p_EXT1_Keyboard_sc_List->Add(L"184 - AL Word Processor");
	p_EXT1_Keyboard_sc_List->Add(L"185 - AL Text Editor");
	p_EXT1_Keyboard_sc_List->Add(L"186 - AL Spreadsheet");
	p_EXT1_Keyboard_sc_List->Add(L"187 - AL Graphics Editor");
	p_EXT1_Keyboard_sc_List->Add(L"188 - AL Presentation App");
	p_EXT1_Keyboard_sc_List->Add(L"189 - AL Database App");
	p_EXT1_Keyboard_sc_List->Add(L"18A - AL Email Reader");
	p_EXT1_Keyboard_sc_List->Add(L"18B - AL Newsreader");
	p_EXT1_Keyboard_sc_List->Add(L"18C - AL Voicemail");
	p_EXT1_Keyboard_sc_List->Add(L"18D - AL Contacts/Address Book");
	p_EXT1_Keyboard_sc_List->Add(L"18E - AL Calendar/Schedule");
	p_EXT1_Keyboard_sc_List->Add(L"18F - AL Task/Project Manager");
	p_EXT1_Keyboard_sc_List->Add(L"190 - AL Log/Journal/Timecard");
	p_EXT1_Keyboard_sc_List->Add(L"191 - AL Checkbook/Finance");
	p_EXT1_Keyboard_sc_List->Add(L"192 - AL Calculator");
	p_EXT1_Keyboard_sc_List->Add(L"193 - AL A/V Capture/Playback");
	p_EXT1_Keyboard_sc_List->Add(L"194 - AL Local Machine Browser");
	p_EXT1_Keyboard_sc_List->Add(L"195 - AL LAN/WAN Browser");
	p_EXT1_Keyboard_sc_List->Add(L"196 - AL Internet Browser");
	p_EXT1_Keyboard_sc_List->Add(L"197 - AL Remote Net/ISP Connect");
	p_EXT1_Keyboard_sc_List->Add(L"198 - AL Network Conference");
	p_EXT1_Keyboard_sc_List->Add(L"199 - AL Network Chat");
	p_EXT1_Keyboard_sc_List->Add(L"19A - AL Telephony/Dialer");
	p_EXT1_Keyboard_sc_List->Add(L"19B - AL Logon");
	p_EXT1_Keyboard_sc_List->Add(L"19C - AL Logoff");
	p_EXT1_Keyboard_sc_List->Add(L"19D - AL Logon/Logoff");
	p_EXT1_Keyboard_sc_List->Add(L"19E - AL Terminal Lock/Screensaver");
	p_EXT1_Keyboard_sc_List->Add(L"19F - AL Control Panel");
	p_EXT1_Keyboard_sc_List->Add(L"1A0 - AL Command Line Processor/Run");
	p_EXT1_Keyboard_sc_List->Add(L"1A1 - AL Process/Task Manager");
	p_EXT1_Keyboard_sc_List->Add(L"1A2 - AL Select Task/App");
	p_EXT1_Keyboard_sc_List->Add(L"1A3 - AL Next Task/App");
	p_EXT1_Keyboard_sc_List->Add(L"1A4 - AL Previous Task/App");
	p_EXT1_Keyboard_sc_List->Add(L"1A5 - AL Preemptive Halt Task/App");
	p_EXT1_Keyboard_sc_List->Add(L"1A6 - AL Integrated Help Center");
	p_EXT1_Keyboard_sc_List->Add(L"1A7 - AL Documents");
	p_EXT1_Keyboard_sc_List->Add(L"1A8 - AL Thesaurus");
	p_EXT1_Keyboard_sc_List->Add(L"1A9 - AL Dictionary");
	p_EXT1_Keyboard_sc_List->Add(L"1AA - AL Desktop");
	p_EXT1_Keyboard_sc_List->Add(L"1AB - AL Spell Check");
	p_EXT1_Keyboard_sc_List->Add(L"1AC - AL Grammar Check");
	p_EXT1_Keyboard_sc_List->Add(L"1AD - AL Wireless Status");
	p_EXT1_Keyboard_sc_List->Add(L"1AE - AL Keyboard Layout");
	p_EXT1_Keyboard_sc_List->Add(L"1AF - AL Virus Protection");
	p_EXT1_Keyboard_sc_List->Add(L"1B0 - AL Encryption");
	p_EXT1_Keyboard_sc_List->Add(L"1B1 - AL Screen Saver");
	p_EXT1_Keyboard_sc_List->Add(L"1B2 - AL Alarms");
	p_EXT1_Keyboard_sc_List->Add(L"1B3 - AL Clock");
	p_EXT1_Keyboard_sc_List->Add(L"1B4 - AL File Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1B5 - AL Power Status");
	p_EXT1_Keyboard_sc_List->Add(L"1B6 - AL Image  Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1B7 - AL Audio  Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1B8 - AL Movie  Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1B9 - AL Digital Rights Manager");
	p_EXT1_Keyboard_sc_List->Add(L"1BA - AL Digital Wallet");
	p_EXT1_Keyboard_sc_List->Add(L"1BB - Reserved");
	p_EXT1_Keyboard_sc_List->Add(L"1BC - AL Instant Messaging");
	p_EXT1_Keyboard_sc_List->Add(L"1BD - AL OEM Features/Tips Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1BE - AL OEM Help");
	p_EXT1_Keyboard_sc_List->Add(L"1BF - AL Online Community");
	p_EXT1_Keyboard_sc_List->Add(L"1C0 - AL Entertainment Content Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1C1 - AL Online Shopping Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1C2 - AL SmartCard Information/Help");
	p_EXT1_Keyboard_sc_List->Add(L"1C3 - AL Market Monitor Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1C4 - AL Customized News Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1C5 - AL Online Activity Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1C6 - AL Research/Search Browser");
	p_EXT1_Keyboard_sc_List->Add(L"1C7 - AL Audio Player");
	/// 56 1C8-1FF	Reserved
	p_EXT1_Keyboard_sc_List->Add(L"200 - Generic GUI App Controls");
	p_EXT1_Keyboard_sc_List->Add(L"201 - AC New");
	p_EXT1_Keyboard_sc_List->Add(L"202 - AC Open");
	p_EXT1_Keyboard_sc_List->Add(L"203 - AC Close");
	p_EXT1_Keyboard_sc_List->Add(L"204 - AC Exit");
	p_EXT1_Keyboard_sc_List->Add(L"205 - AC Maximize");
	p_EXT1_Keyboard_sc_List->Add(L"206 - AC Minimize");
	p_EXT1_Keyboard_sc_List->Add(L"207 - AC Save");
	p_EXT1_Keyboard_sc_List->Add(L"208 - AC Print");
	p_EXT1_Keyboard_sc_List->Add(L"209 - AC Properties");
	/// 16 20A-219	Reserved
	p_EXT1_Keyboard_sc_List->Add(L"21A - AC Undo");
	p_EXT1_Keyboard_sc_List->Add(L"21B - AC Copy");
	p_EXT1_Keyboard_sc_List->Add(L"21C - AC Cut");
	p_EXT1_Keyboard_sc_List->Add(L"21D - AC Paste");
	p_EXT1_Keyboard_sc_List->Add(L"21E - AC Select All");
	p_EXT1_Keyboard_sc_List->Add(L"21F - AC Find");
	p_EXT1_Keyboard_sc_List->Add(L"220 - AC Find and Replace");
	p_EXT1_Keyboard_sc_List->Add(L"221 - AC Search");
	p_EXT1_Keyboard_sc_List->Add(L"222 - AC Go To");
	p_EXT1_Keyboard_sc_List->Add(L"223 - AC Home");
	p_EXT1_Keyboard_sc_List->Add(L"224 - AC Back");
	p_EXT1_Keyboard_sc_List->Add(L"225 - AC Forward");
	p_EXT1_Keyboard_sc_List->Add(L"226 - AC Stop");
	p_EXT1_Keyboard_sc_List->Add(L"227 - AC Refresh");
	p_EXT1_Keyboard_sc_List->Add(L"228 - AC Previous Link");
	p_EXT1_Keyboard_sc_List->Add(L"229 - AC Next Link");
	p_EXT1_Keyboard_sc_List->Add(L"22A - AC Bookmarks");
	p_EXT1_Keyboard_sc_List->Add(L"22B - AC History");
	p_EXT1_Keyboard_sc_List->Add(L"22C - AC Subscriptions");
	p_EXT1_Keyboard_sc_List->Add(L"22D - AC Zoom In");
	p_EXT1_Keyboard_sc_List->Add(L"22E - AC Zoom Out");
	p_EXT1_Keyboard_sc_List->Add(L"22F - AC Zoom");
	p_EXT1_Keyboard_sc_List->Add(L"230 - AC Full Screen View");
	p_EXT1_Keyboard_sc_List->Add(L"231 - AC Normal View");
	p_EXT1_Keyboard_sc_List->Add(L"232 - AC View Toggle");
	p_EXT1_Keyboard_sc_List->Add(L"233 - AC Scroll Up");
	p_EXT1_Keyboard_sc_List->Add(L"234 - AC Scroll Down");
	p_EXT1_Keyboard_sc_List->Add(L"235 - AC Scroll");
	p_EXT1_Keyboard_sc_List->Add(L"236 - AC Pan Left");
	p_EXT1_Keyboard_sc_List->Add(L"237 - AC Pan Right");
	p_EXT1_Keyboard_sc_List->Add(L"238 - AC Pan");
	p_EXT1_Keyboard_sc_List->Add(L"239 - AC New Window");
	p_EXT1_Keyboard_sc_List->Add(L"23A - AC Tile Horizontally");
	p_EXT1_Keyboard_sc_List->Add(L"23B - AC Tile Vertically");
	p_EXT1_Keyboard_sc_List->Add(L"23C - AC Format");
	p_EXT1_Keyboard_sc_List->Add(L"23D - AC Edit");
	p_EXT1_Keyboard_sc_List->Add(L"23E - AC Bold");
	p_EXT1_Keyboard_sc_List->Add(L"23F - AC Italics");
	p_EXT1_Keyboard_sc_List->Add(L"240 - AC Underline");
	p_EXT1_Keyboard_sc_List->Add(L"241 - AC Strikethrough");
	p_EXT1_Keyboard_sc_List->Add(L"242 - AC Subscript");
	p_EXT1_Keyboard_sc_List->Add(L"243 - AC Superscript");
	p_EXT1_Keyboard_sc_List->Add(L"244 - AC All Caps");
	p_EXT1_Keyboard_sc_List->Add(L"245 - AC Rotate");
	p_EXT1_Keyboard_sc_List->Add(L"246 - AC Resize");
	p_EXT1_Keyboard_sc_List->Add(L"247 - AC Flip horizontal");
	p_EXT1_Keyboard_sc_List->Add(L"248 - AC Flip Vertical");
	p_EXT1_Keyboard_sc_List->Add(L"249 - AC Mirror Horizontal");
	p_EXT1_Keyboard_sc_List->Add(L"24A - AC Mirror Vertical");
	p_EXT1_Keyboard_sc_List->Add(L"24B - AC Font Select");
	p_EXT1_Keyboard_sc_List->Add(L"24C - AC Font Color");
	p_EXT1_Keyboard_sc_List->Add(L"24D - AC Font Size");
	p_EXT1_Keyboard_sc_List->Add(L"24E - AC Justify Left");
	p_EXT1_Keyboard_sc_List->Add(L"24F - AC Justify Center H");
	p_EXT1_Keyboard_sc_List->Add(L"250 - AC Justify Right");
	p_EXT1_Keyboard_sc_List->Add(L"251 - AC Justify Block H");
	p_EXT1_Keyboard_sc_List->Add(L"252 - AC Justify Top");
	p_EXT1_Keyboard_sc_List->Add(L"253 - AC Justify Center V");
	p_EXT1_Keyboard_sc_List->Add(L"254 - AC Justify Bottom");
	p_EXT1_Keyboard_sc_List->Add(L"255 - AC Justify Block V");
	p_EXT1_Keyboard_sc_List->Add(L"256 - AC Indent Decrease");
	p_EXT1_Keyboard_sc_List->Add(L"257 - AC Indent Increase");
	p_EXT1_Keyboard_sc_List->Add(L"258 - AC Numbered List");
	p_EXT1_Keyboard_sc_List->Add(L"259 - AC Restart Numbering");
	p_EXT1_Keyboard_sc_List->Add(L"25A - AC Bulleted List");
	p_EXT1_Keyboard_sc_List->Add(L"25B - AC Promote");
	p_EXT1_Keyboard_sc_List->Add(L"25C - AC Demote");
	p_EXT1_Keyboard_sc_List->Add(L"25D - AC Yes");
	p_EXT1_Keyboard_sc_List->Add(L"25E - AC No");
	p_EXT1_Keyboard_sc_List->Add(L"25F - AC Cancel");
	p_EXT1_Keyboard_sc_List->Add(L"260 - AC Catalog");
	p_EXT1_Keyboard_sc_List->Add(L"261 - AC Buy/Checkout");
	p_EXT1_Keyboard_sc_List->Add(L"262 - AC Add to Cart");
	p_EXT1_Keyboard_sc_List->Add(L"263 - AC Expand");
	p_EXT1_Keyboard_sc_List->Add(L"264 - AC Expand All");
	p_EXT1_Keyboard_sc_List->Add(L"265 - AC Collapse");
	p_EXT1_Keyboard_sc_List->Add(L"266 - AC Collapse All");
	p_EXT1_Keyboard_sc_List->Add(L"267 - AC Print Preview");
	p_EXT1_Keyboard_sc_List->Add(L"268 - AC Paste Special");
	p_EXT1_Keyboard_sc_List->Add(L"269 - AC Insert Mode");
	p_EXT1_Keyboard_sc_List->Add(L"26A - AC Delete");
	p_EXT1_Keyboard_sc_List->Add(L"26B - AC Lock");
	p_EXT1_Keyboard_sc_List->Add(L"26C - AC Unlock");
	p_EXT1_Keyboard_sc_List->Add(L"26D - AC Protect");
	p_EXT1_Keyboard_sc_List->Add(L"26E - AC Unprotect");
	p_EXT1_Keyboard_sc_List->Add(L"26F - AC Attach Comment");
	p_EXT1_Keyboard_sc_List->Add(L"270 - AC Delete Comment");
	p_EXT1_Keyboard_sc_List->Add(L"271 - AC View Comment");
	p_EXT1_Keyboard_sc_List->Add(L"272 - AC Select Word");
	p_EXT1_Keyboard_sc_List->Add(L"273 - AC Select Sentence");
	p_EXT1_Keyboard_sc_List->Add(L"274 - AC Select Paragraph");
	p_EXT1_Keyboard_sc_List->Add(L"275 - AC Select Column");
	p_EXT1_Keyboard_sc_List->Add(L"276 - AC Select Row");
	p_EXT1_Keyboard_sc_List->Add(L"277 - AC Select Table");
	p_EXT1_Keyboard_sc_List->Add(L"278 - AC Select Object");
	p_EXT1_Keyboard_sc_List->Add(L"279 - AC Redo/Repeat");
	p_EXT1_Keyboard_sc_List->Add(L"27A - AC Sort");
	p_EXT1_Keyboard_sc_List->Add(L"27B - AC Sort Ascending");
	p_EXT1_Keyboard_sc_List->Add(L"27C - AC Sort Descending");
	p_EXT1_Keyboard_sc_List->Add(L"27D - AC Filter");
	p_EXT1_Keyboard_sc_List->Add(L"27E - AC Set Clock");
	p_EXT1_Keyboard_sc_List->Add(L"27F - AC View Clock");
	p_EXT1_Keyboard_sc_List->Add(L"280 - AC Select Time Zone");
	p_EXT1_Keyboard_sc_List->Add(L"281 - AC Edit Time Zones");
	p_EXT1_Keyboard_sc_List->Add(L"282 - AC Set Alarm");
	p_EXT1_Keyboard_sc_List->Add(L"283 - AC Clear Alarm");
	p_EXT1_Keyboard_sc_List->Add(L"284 - AC Snooze Alarm");
	p_EXT1_Keyboard_sc_List->Add(L"285 - AC Reset Alarm");
	p_EXT1_Keyboard_sc_List->Add(L"286 - AC Synchronize");
	p_EXT1_Keyboard_sc_List->Add(L"287 - AC Send/Receive");
	p_EXT1_Keyboard_sc_List->Add(L"288 - AC Send To");
	p_EXT1_Keyboard_sc_List->Add(L"289 - AC Reply");
	p_EXT1_Keyboard_sc_List->Add(L"28A - AC Reply All");
	p_EXT1_Keyboard_sc_List->Add(L"28B - AC Forward Msg");
	p_EXT1_Keyboard_sc_List->Add(L"28C - AC Send");
	p_EXT1_Keyboard_sc_List->Add(L"28D - AC Attach File");
	p_EXT1_Keyboard_sc_List->Add(L"28E - AC Upload");
	p_EXT1_Keyboard_sc_List->Add(L"28F - AC Download (Save Target As)");
	p_EXT1_Keyboard_sc_List->Add(L"290 - AC Set Borders");
	p_EXT1_Keyboard_sc_List->Add(L"291 - AC Insert Row");
	p_EXT1_Keyboard_sc_List->Add(L"292 - AC Insert Column");
	p_EXT1_Keyboard_sc_List->Add(L"293 - AC Insert File");
	p_EXT1_Keyboard_sc_List->Add(L"294 - AC Insert Picture");
	p_EXT1_Keyboard_sc_List->Add(L"295 - AC Insert Object");
	p_EXT1_Keyboard_sc_List->Add(L"296 - AC Insert Symbol");
	p_EXT1_Keyboard_sc_List->Add(L"297 - AC Save and Close");
	p_EXT1_Keyboard_sc_List->Add(L"298 - AC Rename");
	p_EXT1_Keyboard_sc_List->Add(L"299 - AC Merge");
	p_EXT1_Keyboard_sc_List->Add(L"29A - AC Split");
	p_EXT1_Keyboard_sc_List->Add(L"29B - AC Disribute Horizontally");
	p_EXT1_Keyboard_sc_List->Add(L"29C - AC Distribute Vertically");

	p_EXT2_Keyboard_sc_List = new TStringList();
	if (!p_EXT2_Keyboard_sc_List) return;
	p_EXT2_Keyboard_sc_List->Insert(0, L"00 - No Event");
	p_EXT2_Keyboard_sc_List->Insert(1, L"81 - SYSTEM POWER DOWN");
	p_EXT2_Keyboard_sc_List->Insert(2, L"82 - SYSTEM SLEEP");
	p_EXT2_Keyboard_sc_List->Insert(3, L"83 - SYSTEM WAKE UP");
	p_EXT2_Keyboard_sc_List->Insert(4, L"84 - SYSTEM CONTEXT MENU");
	p_EXT2_Keyboard_sc_List->Insert(5, L"85 - SYSTEM MAIN MENU");
	p_EXT2_Keyboard_sc_List->Insert(6, L"86 - SYSTEM APP MENU");
	p_EXT2_Keyboard_sc_List->Insert(7, L"87 - SYSTEM MENU HELP");
	p_EXT2_Keyboard_sc_List->Insert(8, L"88 - SYSTEM MENU EXIT");
	p_EXT2_Keyboard_sc_List->Insert(9, L"89 - SYSTEM MENU SELECT");
	p_EXT2_Keyboard_sc_List->Insert(10, L"8A - SYSTEM MENU RIGHT");
	p_EXT2_Keyboard_sc_List->Insert(11, L"8B - SYSTEM MENU LEFT");
	p_EXT2_Keyboard_sc_List->Insert(12, L"8C - SYSTEM MENU UP");
	p_EXT2_Keyboard_sc_List->Insert(13, L"8D - SYSTEM MENU DOWN");
}

void Destroy_sc_List(void)
{
	delete p_Empty_sc_List;
	delete p_STD_Keyboard_sc_List;
	delete p_EXT1_Keyboard_sc_List;
	delete p_EXT2_Keyboard_sc_List;
}

void Init_KeySettings_Panel(void)
{
	g_KeySettings_Panel[0].Panel = 				Form1->Panel_key0;
	g_KeySettings_Panel[0].CheckBox_save = 		Form1->CheckBox_save_key0;
	g_KeySettings_Panel[0].ComboBox_kb =		Form1->ComboBox_kb_key0;
	g_KeySettings_Panel[0].ComboBox_sc = 		Form1->ComboBox_sc_key0;
	g_KeySettings_Panel[0].CheckBox_lctl = 		Form1->CheckBox_lctl_key0;
	g_KeySettings_Panel[0].CheckBox_lshift = 	Form1->CheckBox_lshift_key0;
	g_KeySettings_Panel[0].CheckBox_lalt =      Form1->CheckBox_lalt_key0;
	g_KeySettings_Panel[0].CheckBox_lwin =      Form1->CheckBox_lwin_key0;
	g_KeySettings_Panel[0].CheckBox_rctl =      Form1->CheckBox_rctl_key0;
	g_KeySettings_Panel[0].CheckBox_rshift = 	Form1->CheckBox_rshift_key0;
	g_KeySettings_Panel[0].CheckBox_ralt = 		Form1->CheckBox_ralt_key0;
	g_KeySettings_Panel[0].CheckBox_rwin = 		Form1->CheckBox_rwin_key0;

	g_KeySettings_Panel[1].Panel = 				Form1->Panel_key1;
	g_KeySettings_Panel[1].CheckBox_save = 		Form1->CheckBox_save_key1;
	g_KeySettings_Panel[1].ComboBox_kb =		Form1->ComboBox_kb_key1;
	g_KeySettings_Panel[1].ComboBox_sc = 		Form1->ComboBox_sc_key1;
	g_KeySettings_Panel[1].CheckBox_lctl = 		Form1->CheckBox_lctl_key1;
	g_KeySettings_Panel[1].CheckBox_lshift = 	Form1->CheckBox_lshift_key1;
	g_KeySettings_Panel[1].CheckBox_lalt =      Form1->CheckBox_lalt_key1;
	g_KeySettings_Panel[1].CheckBox_lwin =      Form1->CheckBox_lwin_key1;
	g_KeySettings_Panel[1].CheckBox_rctl =      Form1->CheckBox_rctl_key1;
	g_KeySettings_Panel[1].CheckBox_rshift = 	Form1->CheckBox_rshift_key1;
	g_KeySettings_Panel[1].CheckBox_ralt = 		Form1->CheckBox_ralt_key1;
	g_KeySettings_Panel[1].CheckBox_rwin = 		Form1->CheckBox_rwin_key1;

	g_KeySettings_Panel[2].Panel = 				Form1->Panel_key2;
	g_KeySettings_Panel[2].CheckBox_save = 		Form1->CheckBox_save_key2;
	g_KeySettings_Panel[2].ComboBox_kb =		Form1->ComboBox_kb_key2;
	g_KeySettings_Panel[2].ComboBox_sc = 		Form1->ComboBox_sc_key2;
	g_KeySettings_Panel[2].CheckBox_lctl = 		Form1->CheckBox_lctl_key2;
	g_KeySettings_Panel[2].CheckBox_lshift = 	Form1->CheckBox_lshift_key2;
	g_KeySettings_Panel[2].CheckBox_lalt =      Form1->CheckBox_lalt_key2;
	g_KeySettings_Panel[2].CheckBox_lwin =      Form1->CheckBox_lwin_key2;
	g_KeySettings_Panel[2].CheckBox_rctl =      Form1->CheckBox_rctl_key2;
	g_KeySettings_Panel[2].CheckBox_rshift = 	Form1->CheckBox_rshift_key2;
	g_KeySettings_Panel[2].CheckBox_ralt = 		Form1->CheckBox_ralt_key2;
	g_KeySettings_Panel[2].CheckBox_rwin = 		Form1->CheckBox_rwin_key2;

	g_KeySettings_Panel[3].Panel = 				Form1->Panel_key3;
	g_KeySettings_Panel[3].CheckBox_save = 		Form1->CheckBox_save_key3;
	g_KeySettings_Panel[3].ComboBox_kb =		Form1->ComboBox_kb_key3;
	g_KeySettings_Panel[3].ComboBox_sc = 		Form1->ComboBox_sc_key3;
	g_KeySettings_Panel[3].CheckBox_lctl = 		Form1->CheckBox_lctl_key3;
	g_KeySettings_Panel[3].CheckBox_lshift = 	Form1->CheckBox_lshift_key3;
	g_KeySettings_Panel[3].CheckBox_lalt =      Form1->CheckBox_lalt_key3;
	g_KeySettings_Panel[3].CheckBox_lwin =      Form1->CheckBox_lwin_key3;
	g_KeySettings_Panel[3].CheckBox_rctl =      Form1->CheckBox_rctl_key3;
	g_KeySettings_Panel[3].CheckBox_rshift = 	Form1->CheckBox_rshift_key3;
	g_KeySettings_Panel[3].CheckBox_ralt = 		Form1->CheckBox_ralt_key3;
	g_KeySettings_Panel[3].CheckBox_rwin = 		Form1->CheckBox_rwin_key3;

	g_KeySettings_Panel[4].Panel = 				Form1->Panel_key4;
	g_KeySettings_Panel[4].CheckBox_save = 		Form1->CheckBox_save_key4;
	g_KeySettings_Panel[4].ComboBox_kb =		Form1->ComboBox_kb_key4;
	g_KeySettings_Panel[4].ComboBox_sc = 		Form1->ComboBox_sc_key4;
	g_KeySettings_Panel[4].CheckBox_lctl = 		Form1->CheckBox_lctl_key4;
	g_KeySettings_Panel[4].CheckBox_lshift = 	Form1->CheckBox_lshift_key4;
	g_KeySettings_Panel[4].CheckBox_lalt =      Form1->CheckBox_lalt_key4;
	g_KeySettings_Panel[4].CheckBox_lwin =      Form1->CheckBox_lwin_key4;
	g_KeySettings_Panel[4].CheckBox_rctl =      Form1->CheckBox_rctl_key4;
	g_KeySettings_Panel[4].CheckBox_rshift = 	Form1->CheckBox_rshift_key4;
	g_KeySettings_Panel[4].CheckBox_ralt = 		Form1->CheckBox_ralt_key4;
	g_KeySettings_Panel[4].CheckBox_rwin = 		Form1->CheckBox_rwin_key4;

	g_KeySettings_Panel[5].Panel = 				Form1->Panel_key5;
	g_KeySettings_Panel[5].CheckBox_save = 		Form1->CheckBox_save_key5;
	g_KeySettings_Panel[5].ComboBox_kb =		Form1->ComboBox_kb_key5;
	g_KeySettings_Panel[5].ComboBox_sc = 		Form1->ComboBox_sc_key5;
	g_KeySettings_Panel[5].CheckBox_lctl = 		Form1->CheckBox_lctl_key5;
	g_KeySettings_Panel[5].CheckBox_lshift = 	Form1->CheckBox_lshift_key5;
	g_KeySettings_Panel[5].CheckBox_lalt =      Form1->CheckBox_lalt_key5;
	g_KeySettings_Panel[5].CheckBox_lwin =      Form1->CheckBox_lwin_key5;
	g_KeySettings_Panel[5].CheckBox_rctl =      Form1->CheckBox_rctl_key5;
	g_KeySettings_Panel[5].CheckBox_rshift = 	Form1->CheckBox_rshift_key5;
	g_KeySettings_Panel[5].CheckBox_ralt = 		Form1->CheckBox_ralt_key5;
	g_KeySettings_Panel[5].CheckBox_rwin = 		Form1->CheckBox_rwin_key5;

	g_KeySettings_Panel[6].Panel = 				Form1->Panel_key6;
	g_KeySettings_Panel[6].CheckBox_save = 		Form1->CheckBox_save_key6;
	g_KeySettings_Panel[6].ComboBox_kb =		Form1->ComboBox_kb_key6;
	g_KeySettings_Panel[6].ComboBox_sc = 		Form1->ComboBox_sc_key6;
	g_KeySettings_Panel[6].CheckBox_lctl = 		Form1->CheckBox_lctl_key6;
	g_KeySettings_Panel[6].CheckBox_lshift = 	Form1->CheckBox_lshift_key6;
	g_KeySettings_Panel[6].CheckBox_lalt =      Form1->CheckBox_lalt_key6;
	g_KeySettings_Panel[6].CheckBox_lwin =      Form1->CheckBox_lwin_key6;
	g_KeySettings_Panel[6].CheckBox_rctl =      Form1->CheckBox_rctl_key6;
	g_KeySettings_Panel[6].CheckBox_rshift = 	Form1->CheckBox_rshift_key6;
	g_KeySettings_Panel[6].CheckBox_ralt = 		Form1->CheckBox_ralt_key6;
	g_KeySettings_Panel[6].CheckBox_rwin = 		Form1->CheckBox_rwin_key6;

	g_KeySettings_Panel[7].Panel = 				Form1->Panel_key7;
	g_KeySettings_Panel[7].CheckBox_save = 		Form1->CheckBox_save_key7;
	g_KeySettings_Panel[7].ComboBox_kb =		Form1->ComboBox_kb_key7;
	g_KeySettings_Panel[7].ComboBox_sc = 		Form1->ComboBox_sc_key7;
	g_KeySettings_Panel[7].CheckBox_lctl = 		Form1->CheckBox_lctl_key7;
	g_KeySettings_Panel[7].CheckBox_lshift = 	Form1->CheckBox_lshift_key7;
	g_KeySettings_Panel[7].CheckBox_lalt =      Form1->CheckBox_lalt_key7;
	g_KeySettings_Panel[7].CheckBox_lwin =      Form1->CheckBox_lwin_key7;
	g_KeySettings_Panel[7].CheckBox_rctl =      Form1->CheckBox_rctl_key7;
	g_KeySettings_Panel[7].CheckBox_rshift = 	Form1->CheckBox_rshift_key7;
	g_KeySettings_Panel[7].CheckBox_ralt = 		Form1->CheckBox_ralt_key7;
	g_KeySettings_Panel[7].CheckBox_rwin = 		Form1->CheckBox_rwin_key7;

	g_KeySettings_Panel[8].Panel = 				Form1->Panel_key8;
	g_KeySettings_Panel[8].CheckBox_save = 		Form1->CheckBox_save_key8;
	g_KeySettings_Panel[8].ComboBox_kb =		Form1->ComboBox_kb_key8;
	g_KeySettings_Panel[8].ComboBox_sc = 		Form1->ComboBox_sc_key8;
	g_KeySettings_Panel[8].CheckBox_lctl = 		Form1->CheckBox_lctl_key8;
	g_KeySettings_Panel[8].CheckBox_lshift = 	Form1->CheckBox_lshift_key8;
	g_KeySettings_Panel[8].CheckBox_lalt =      Form1->CheckBox_lalt_key8;
	g_KeySettings_Panel[8].CheckBox_lwin =      Form1->CheckBox_lwin_key8;
	g_KeySettings_Panel[8].CheckBox_rctl =      Form1->CheckBox_rctl_key8;
	g_KeySettings_Panel[8].CheckBox_rshift = 	Form1->CheckBox_rshift_key8;
	g_KeySettings_Panel[8].CheckBox_ralt = 		Form1->CheckBox_ralt_key8;
	g_KeySettings_Panel[8].CheckBox_rwin = 		Form1->CheckBox_rwin_key8;

	g_KeySettings_Panel[9].Panel = 				Form1->Panel_key9;
	g_KeySettings_Panel[9].CheckBox_save = 		Form1->CheckBox_save_key9;
	g_KeySettings_Panel[9].ComboBox_kb =		Form1->ComboBox_kb_key9;
	g_KeySettings_Panel[9].ComboBox_sc = 		Form1->ComboBox_sc_key9;
	g_KeySettings_Panel[9].CheckBox_lctl = 		Form1->CheckBox_lctl_key9;
	g_KeySettings_Panel[9].CheckBox_lshift = 	Form1->CheckBox_lshift_key9;
	g_KeySettings_Panel[9].CheckBox_lalt =      Form1->CheckBox_lalt_key9;
	g_KeySettings_Panel[9].CheckBox_lwin =      Form1->CheckBox_lwin_key9;
	g_KeySettings_Panel[9].CheckBox_rctl =      Form1->CheckBox_rctl_key9;
	g_KeySettings_Panel[9].CheckBox_rshift = 	Form1->CheckBox_rshift_key9;
	g_KeySettings_Panel[9].CheckBox_ralt = 		Form1->CheckBox_ralt_key9;
	g_KeySettings_Panel[9].CheckBox_rwin = 		Form1->CheckBox_rwin_key9;

	g_KeySettings_Panel[10].Panel = 			Form1->Panel_key10;
	g_KeySettings_Panel[10].CheckBox_save = 	Form1->CheckBox_save_key10;
	g_KeySettings_Panel[10].ComboBox_kb =		Form1->ComboBox_kb_key10;
	g_KeySettings_Panel[10].ComboBox_sc = 		Form1->ComboBox_sc_key10;
	g_KeySettings_Panel[10].CheckBox_lctl = 	Form1->CheckBox_lctl_key10;
	g_KeySettings_Panel[10].CheckBox_lshift = 	Form1->CheckBox_lshift_key10;
	g_KeySettings_Panel[10].CheckBox_lalt =     Form1->CheckBox_lalt_key10;
	g_KeySettings_Panel[10].CheckBox_lwin =     Form1->CheckBox_lwin_key10;
	g_KeySettings_Panel[10].CheckBox_rctl =     Form1->CheckBox_rctl_key10;
	g_KeySettings_Panel[10].CheckBox_rshift = 	Form1->CheckBox_rshift_key10;
	g_KeySettings_Panel[10].CheckBox_ralt = 	Form1->CheckBox_ralt_key10;
	g_KeySettings_Panel[10].CheckBox_rwin = 	Form1->CheckBox_rwin_key10;

	g_KeySettings_Panel[11].Panel = 			Form1->Panel_key11;
	g_KeySettings_Panel[11].CheckBox_save = 	Form1->CheckBox_save_key11;
	g_KeySettings_Panel[11].ComboBox_kb =		Form1->ComboBox_kb_key11;
	g_KeySettings_Panel[11].ComboBox_sc = 		Form1->ComboBox_sc_key11;
	g_KeySettings_Panel[11].CheckBox_lctl = 	Form1->CheckBox_lctl_key11;
	g_KeySettings_Panel[11].CheckBox_lshift = 	Form1->CheckBox_lshift_key11;
	g_KeySettings_Panel[11].CheckBox_lalt =     Form1->CheckBox_lalt_key11;
	g_KeySettings_Panel[11].CheckBox_lwin =     Form1->CheckBox_lwin_key11;
	g_KeySettings_Panel[11].CheckBox_rctl =     Form1->CheckBox_rctl_key11;
	g_KeySettings_Panel[11].CheckBox_rshift = 	Form1->CheckBox_rshift_key11;
	g_KeySettings_Panel[11].CheckBox_ralt = 	Form1->CheckBox_ralt_key11;
	g_KeySettings_Panel[11].CheckBox_rwin = 	Form1->CheckBox_rwin_key11;

	g_KeySettings_Panel[12].Panel = 			Form1->Panel_key12;
	g_KeySettings_Panel[12].CheckBox_save = 	Form1->CheckBox_save_key12;
	g_KeySettings_Panel[12].ComboBox_kb =		Form1->ComboBox_kb_key12;
	g_KeySettings_Panel[12].ComboBox_sc = 		Form1->ComboBox_sc_key12;
	g_KeySettings_Panel[12].CheckBox_lctl = 	Form1->CheckBox_lctl_key12;
	g_KeySettings_Panel[12].CheckBox_lshift = 	Form1->CheckBox_lshift_key12;
	g_KeySettings_Panel[12].CheckBox_lalt =     Form1->CheckBox_lalt_key12;
	g_KeySettings_Panel[12].CheckBox_lwin =     Form1->CheckBox_lwin_key12;
	g_KeySettings_Panel[12].CheckBox_rctl =     Form1->CheckBox_rctl_key12;
	g_KeySettings_Panel[12].CheckBox_rshift = 	Form1->CheckBox_rshift_key12;
	g_KeySettings_Panel[12].CheckBox_ralt = 	Form1->CheckBox_ralt_key12;
	g_KeySettings_Panel[12].CheckBox_rwin = 	Form1->CheckBox_rwin_key12;

	g_KeySettings_Panel[13].Panel = 			Form1->Panel_key13;
	g_KeySettings_Panel[13].CheckBox_save = 	Form1->CheckBox_save_key13;
	g_KeySettings_Panel[13].ComboBox_kb =		Form1->ComboBox_kb_key13;
	g_KeySettings_Panel[13].ComboBox_sc = 		Form1->ComboBox_sc_key13;
	g_KeySettings_Panel[13].CheckBox_lctl = 	Form1->CheckBox_lctl_key13;
	g_KeySettings_Panel[13].CheckBox_lshift = 	Form1->CheckBox_lshift_key13;
	g_KeySettings_Panel[13].CheckBox_lalt =     Form1->CheckBox_lalt_key13;
	g_KeySettings_Panel[13].CheckBox_lwin =     Form1->CheckBox_lwin_key13;
	g_KeySettings_Panel[13].CheckBox_rctl =     Form1->CheckBox_rctl_key13;
	g_KeySettings_Panel[13].CheckBox_rshift = 	Form1->CheckBox_rshift_key13;
	g_KeySettings_Panel[13].CheckBox_ralt = 	Form1->CheckBox_ralt_key13;
	g_KeySettings_Panel[13].CheckBox_rwin = 	Form1->CheckBox_rwin_key13;

	g_KeySettings_Panel[14].Panel = 			Form1->Panel_key14;
	g_KeySettings_Panel[14].CheckBox_save = 	Form1->CheckBox_save_key14;
	g_KeySettings_Panel[14].ComboBox_kb =		Form1->ComboBox_kb_key14;
	g_KeySettings_Panel[14].ComboBox_sc = 		Form1->ComboBox_sc_key14;
	g_KeySettings_Panel[14].CheckBox_lctl = 	Form1->CheckBox_lctl_key14;
	g_KeySettings_Panel[14].CheckBox_lshift = 	Form1->CheckBox_lshift_key14;
	g_KeySettings_Panel[14].CheckBox_lalt =     Form1->CheckBox_lalt_key14;
	g_KeySettings_Panel[14].CheckBox_lwin =     Form1->CheckBox_lwin_key14;
	g_KeySettings_Panel[14].CheckBox_rctl =     Form1->CheckBox_rctl_key14;
	g_KeySettings_Panel[14].CheckBox_rshift = 	Form1->CheckBox_rshift_key14;
	g_KeySettings_Panel[14].CheckBox_ralt = 	Form1->CheckBox_ralt_key14;
	g_KeySettings_Panel[14].CheckBox_rwin = 	Form1->CheckBox_rwin_key14;

	g_KeySettings_Panel[15].Panel = 			Form1->Panel_key15;
	g_KeySettings_Panel[15].CheckBox_save = 	Form1->CheckBox_save_key15;
	g_KeySettings_Panel[15].ComboBox_kb =		Form1->ComboBox_kb_key15;
	g_KeySettings_Panel[15].ComboBox_sc = 		Form1->ComboBox_sc_key15;
	g_KeySettings_Panel[15].CheckBox_lctl = 	Form1->CheckBox_lctl_key15;
	g_KeySettings_Panel[15].CheckBox_lshift = 	Form1->CheckBox_lshift_key15;
	g_KeySettings_Panel[15].CheckBox_lalt =     Form1->CheckBox_lalt_key15;
	g_KeySettings_Panel[15].CheckBox_lwin =     Form1->CheckBox_lwin_key15;
	g_KeySettings_Panel[15].CheckBox_rctl =     Form1->CheckBox_rctl_key15;
	g_KeySettings_Panel[15].CheckBox_rshift = 	Form1->CheckBox_rshift_key15;
	g_KeySettings_Panel[15].CheckBox_ralt = 	Form1->CheckBox_ralt_key15;
	g_KeySettings_Panel[15].CheckBox_rwin = 	Form1->CheckBox_rwin_key15;
}

void Update_sc_List(t_KeySettings KeySettings, uint32_t key_num)
{
	if (key_num >= MAX_KEY_COUNT) return;
	switch(KeySettings.usage_page) {
		case STD_KEYBOARD_USAGE_PAGE:
			g_KeySettings_Panel[key_num].ComboBox_sc->Items = p_STD_Keyboard_sc_List;
			if (KeySettings.scancode <= 0xE7)
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode;
			else g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = 0;
			break;
		case EXT1_KEYBOARD_USAGE_PAGE:
			g_KeySettings_Panel[key_num].ComboBox_sc->Items = p_EXT1_Keyboard_sc_List;
			if ((KeySettings.scancode >= 0x20)&&(KeySettings.scancode <= 0x22)){
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode - (31);
			} else
			if ((KeySettings.scancode >= 0x30)&&(KeySettings.scancode <= 0x48)){
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode - (31+13);
			} else
			if ((KeySettings.scancode >= 0x60)&&(KeySettings.scancode <= 0x66)){
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode - (31+13+23);
			} else
			if ((KeySettings.scancode >= 0x80)&&(KeySettings.scancode <= 0xCE)){
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode - (31+13+23+25);
			} else
			if ((KeySettings.scancode >= 0xE0)&&(KeySettings.scancode <= 0x10D)){
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode - (31+13+23+25+17);
			} else
			if ((KeySettings.scancode >= 0x150)&&(KeySettings.scancode <= 0x1C7)){
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode - (31+13+23+25+17+66);
			} else
			if ((KeySettings.scancode >= 0x200)&&(KeySettings.scancode <= 0x209)){
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode - (31+13+23+25+17+66+56);
			} else
			if ((KeySettings.scancode >= 0x21A)&&(KeySettings.scancode <= 0x29C)){
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode - (31+13+23+25+17+66+56+16);
			} else g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = 0;
			break;
		case EXT2_KEYBOARD_USAGE_PAGE:
			g_KeySettings_Panel[key_num].ComboBox_sc->Items = p_EXT2_Keyboard_sc_List;
			if ((KeySettings.scancode >= 0x81)&&(KeySettings.scancode <= 0x8d))
				g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = KeySettings.scancode - 0x80;
			else g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = 0;
			break;
		default:
			g_KeySettings_Panel[key_num].ComboBox_sc->Items = p_Empty_sc_List;
			g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex = 0;
			break;
	}
	if (KeySettings.usage_page == STD_KEYBOARD_USAGE_PAGE) {
		g_KeySettings_Panel[key_num].CheckBox_lctl->Enabled = true;
		g_KeySettings_Panel[key_num].CheckBox_lshift->Enabled = true;
		g_KeySettings_Panel[key_num].CheckBox_lalt->Enabled = true;
		g_KeySettings_Panel[key_num].CheckBox_lwin->Enabled = true;
		g_KeySettings_Panel[key_num].CheckBox_rctl->Enabled = true;
		g_KeySettings_Panel[key_num].CheckBox_rshift->Enabled = true;
		g_KeySettings_Panel[key_num].CheckBox_ralt->Enabled = true;
		g_KeySettings_Panel[key_num].CheckBox_rwin->Enabled = true;
	} else {
		g_KeySettings_Panel[key_num].CheckBox_lctl->Enabled = false;
		g_KeySettings_Panel[key_num].CheckBox_lshift->Enabled = false;
		g_KeySettings_Panel[key_num].CheckBox_lalt->Enabled = false;
		g_KeySettings_Panel[key_num].CheckBox_lwin->Enabled = false;
		g_KeySettings_Panel[key_num].CheckBox_rctl->Enabled = false;
		g_KeySettings_Panel[key_num].CheckBox_rshift->Enabled = false;
		g_KeySettings_Panel[key_num].CheckBox_ralt->Enabled = false;
		g_KeySettings_Panel[key_num].CheckBox_rwin->Enabled = false;

		g_KeySettings_Panel[key_num].CheckBox_lctl->Checked = false;
		g_KeySettings_Panel[key_num].CheckBox_lshift->Checked = false;
		g_KeySettings_Panel[key_num].CheckBox_lalt->Checked = false;
		g_KeySettings_Panel[key_num].CheckBox_lwin->Checked = false;
		g_KeySettings_Panel[key_num].CheckBox_rctl->Checked = false;
		g_KeySettings_Panel[key_num].CheckBox_rshift->Checked = false;
		g_KeySettings_Panel[key_num].CheckBox_ralt->Checked = false;
		g_KeySettings_Panel[key_num].CheckBox_rwin->Checked = false;
	}
}

void Sync_Settings_to_panel(t_KeySettings KeySettings, uint32_t key_num)
{
	if (key_num >= MAX_KEY_COUNT) return;
	if (KeySettings.active) g_KeySettings_Panel[key_num].Panel->Visible = true;
	else g_KeySettings_Panel[key_num].Panel->Visible = false;
	if (KeySettings.save_flag) g_KeySettings_Panel[key_num].CheckBox_save->Checked = true;
	else g_KeySettings_Panel[key_num].CheckBox_save->Checked = false;
	switch(KeySettings.usage_page) {
		case STD_KEYBOARD_USAGE_PAGE:
			g_KeySettings_Panel[key_num].ComboBox_kb->ItemIndex = 1;
			break;
		case EXT1_KEYBOARD_USAGE_PAGE:
			g_KeySettings_Panel[key_num].ComboBox_kb->ItemIndex = 2;
			break;
		case EXT2_KEYBOARD_USAGE_PAGE:
			g_KeySettings_Panel[key_num].ComboBox_kb->ItemIndex = 3;
			break;
		default:
			g_KeySettings_Panel[key_num].ComboBox_kb->ItemIndex = 0;
			break;
	}

	Update_sc_List(KeySettings, key_num);

	if (KeySettings.modifiers & HID_KEYBOARD_MODIFIER_LEFTCTRL)
		g_KeySettings_Panel[key_num].CheckBox_lctl->Checked = true;
	else g_KeySettings_Panel[key_num].CheckBox_lctl->Checked = false;
	if (KeySettings.modifiers & HID_KEYBOARD_MODIFIER_LEFTSHIFT)
		g_KeySettings_Panel[key_num].CheckBox_lshift->Checked = true;
	else g_KeySettings_Panel[key_num].CheckBox_lshift->Checked = false;
	if (KeySettings.modifiers & HID_KEYBOARD_MODIFIER_LEFTALT)
		g_KeySettings_Panel[key_num].CheckBox_lalt->Checked = true;
	else g_KeySettings_Panel[key_num].CheckBox_lalt->Checked = false;
	if (KeySettings.modifiers & HID_KEYBOARD_MODIFIER_LEFTGUI)
		g_KeySettings_Panel[key_num].CheckBox_lwin->Checked = true;
	else g_KeySettings_Panel[key_num].CheckBox_lwin->Checked = false;
	if (KeySettings.modifiers & HID_KEYBOARD_MODIFIER_RIGHTCTRL)
		g_KeySettings_Panel[key_num].CheckBox_rctl->Checked = true;
	else g_KeySettings_Panel[key_num].CheckBox_rctl->Checked = false;
	if (KeySettings.modifiers & HID_KEYBOARD_MODIFIER_RIGHTSHIFT)
		g_KeySettings_Panel[key_num].CheckBox_rshift->Checked = true;
	else g_KeySettings_Panel[key_num].CheckBox_rshift->Checked = false;
	if (KeySettings.modifiers & HID_KEYBOARD_MODIFIER_RIGHTALT)
		g_KeySettings_Panel[key_num].CheckBox_ralt->Checked = true;
	else g_KeySettings_Panel[key_num].CheckBox_ralt->Checked = false;
	if (KeySettings.modifiers & HID_KEYBOARD_MODIFIER_RIGHTGUI)
		g_KeySettings_Panel[key_num].CheckBox_rwin->Checked = true;
	else g_KeySettings_Panel[key_num].CheckBox_rwin->Checked = false;
}

void Key_Settings_changed(uint32_t key_num)
{
	if (key_num >= MAX_KEY_COUNT) return;
	g_KeySettings_Panel[key_num].CheckBox_save->Checked = true;
}

void KB_Changed(uint32_t key_num)
{
	if (key_num >= MAX_KEY_COUNT) return;
	switch(g_KeySettings_Panel[key_num].ComboBox_kb->ItemIndex) {
		case 1:
			g_KeySettings_Device[key_num].usage_page = STD_KEYBOARD_USAGE_PAGE;
			break;
		case 2:
			g_KeySettings_Device[key_num].usage_page = EXT1_KEYBOARD_USAGE_PAGE;
			break;
		case 3:
			g_KeySettings_Device[key_num].usage_page = EXT2_KEYBOARD_USAGE_PAGE;
			break;
		default:
			g_KeySettings_Device[key_num].usage_page = 0;
			break;
	}
	g_KeySettings_Device[key_num].scancode = 0;
	Update_sc_List(g_KeySettings_Device[key_num], key_num);
}

void DeviceDisconnect(void)
{
	int i;
	is_connected = 0;
	Form1->Label_status->Caption = L"Не подключено";
	Form1->Label_status->Font->Color = clRed;
	Form1->Button_write->Enabled = false;
	/// Reset settings
	for(i=0;i< MAX_KEY_COUNT;i++) {
		memset(&g_KeySettings_Device[i], 0, sizeof(t_KeySettings));
		Sync_Settings_to_panel(g_KeySettings_Device[i], i);
	}
}


void Device_ReadSettings(void)
{
	int ret = 0;
	int i;
	/// Disconnect
	DeviceDisconnect();
	/// Connect
	Device_VID = (uint16_t)wcstoul(Form1->Edit_VID->Text.c_str(), NULL, 16);
	Device_PID = (uint16_t)wcstoul(Form1->Edit_PID->Text.c_str(), NULL, 16);
	Device_UsagePage = (uint16_t)wcstoul(Form1->Edit_UsagePage->Text.c_str(), NULL, 16);
	Device_Usage = (uint16_t)wcstoul(Form1->Edit_Usage->Text.c_str(), NULL, 16);
	ret = Check_ConnectDevice(Device_VID, Device_PID, Device_UsagePage, Device_Usage);
	if (ret < 0) return; // not connected
	is_connected = 1;
	Form1->Label_status->Caption = L"Подключено";
	Form1->Label_status->Font->Color = clGreen;
	/// Read settings
	for(i=0;i< MAX_KEY_COUNT;i++)
	{
		ret = Read_Key_Settings(i, &g_KeySettings_Device[i].usage_page,
			&g_KeySettings_Device[i].modifiers, &g_KeySettings_Device[i].scancode,
			Device_VID, Device_PID, Device_UsagePage, Device_Usage);
		if (ret == 0) {
			g_KeySettings_Device[i].active = 1;
			if (g_KeySettings_Device[i].usage_page != STD_KEYBOARD_USAGE_PAGE)
				g_KeySettings_Device[i].modifiers = 0;
		} else {
			Form1->Label_status->Caption = L"Ошибка чтения настроек";
			Form1->Label_status->Font->Color = clRed;
			break;
		}
		Sync_Settings_to_panel(g_KeySettings_Device[i], i);
	}
	if (ret == 0) {
		Form1->Label_status->Caption = L"Настройки считаны";
		Form1->Label_status->Font->Color = clGreen;
		Form1->Button_write->Enabled = true;
	}
}

void Sync_Settings_to_struct(t_KeySettings &KeySettings, uint32_t key_num)
{
	if (key_num >= MAX_KEY_COUNT) return;
	if (g_KeySettings_Panel[key_num].Panel->Visible) KeySettings.active = 1;
	else KeySettings.active = 0;
	if (g_KeySettings_Panel[key_num].CheckBox_save->Checked) KeySettings.save_flag = 1;
	else KeySettings.save_flag = 0;
	switch(g_KeySettings_Panel[key_num].ComboBox_kb->ItemIndex) {
		case 1:
			KeySettings.usage_page = STD_KEYBOARD_USAGE_PAGE;
			if (g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= 0xE7)
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex;
			else KeySettings.scancode = 0;
			break;
		case 2:
			KeySettings.usage_page = EXT1_KEYBOARD_USAGE_PAGE;
			if ((g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex >= (0x20-(31)))&&
				(g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= (0x22-(31))))
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex + (31);
			else
			if ((g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex >= (0x30-(31+13)))&&
				(g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= (0x48-(31+13))))
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex + (31+13);
			else
			if ((g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex >= (0x60-(31+13+23)))&&
				(g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= (0x66-(31+13+23))))
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex + (31+13+23);
			else
			if ((g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex >= (0x80-(31+13+23+25)))&&
				(g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= (0xCE-(31+13+23+25))))
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex + (31+13+23+25);
			else
			if ((g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex >= (0xE0-(31+13+23+25+17)))&&
				(g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= (0x10D-(31+13+23+25+17))))
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex + (31+13+23+25+17);
			else
			if ((g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex >= (0x150-(31+13+23+25+17+66)))&&
				(g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= (0x1C7-(31+13+23+25+17+66))))
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex + (31+13+23+25+17+66);
			else
			if ((g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex >= (0x200-(31+13+23+25+17+66+56)))&&
				(g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= (0x209-(31+13+23+25+17+66+56))))
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex + (31+13+23+25+17+66+56);
			else
			if ((g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex >= (0x21A-(31+13+23+25+17+66+56+16)))&&
				(g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= (0x29C-(31+13+23+25+17+66+56+16))))
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex + (31+13+23+25+17+66+56+16);
			else KeySettings.scancode = 0;
			break;
		case 3:
			KeySettings.usage_page = EXT2_KEYBOARD_USAGE_PAGE;
			if ((g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex >= (0x81-0x80))&&
				(g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex <= (0x8d-0x80)))
				KeySettings.scancode = g_KeySettings_Panel[key_num].ComboBox_sc->ItemIndex + 0x80;
			else KeySettings.scancode = 0;
			break;
		default:
			KeySettings.usage_page = 0;
			KeySettings.scancode = 0;
			break;
	}
	KeySettings.modifiers = 0;
	if (g_KeySettings_Panel[key_num].CheckBox_lctl->Checked)
		KeySettings.modifiers |= HID_KEYBOARD_MODIFIER_LEFTCTRL;
	if (g_KeySettings_Panel[key_num].CheckBox_lshift->Checked)
		KeySettings.modifiers |= HID_KEYBOARD_MODIFIER_LEFTSHIFT;
	if (g_KeySettings_Panel[key_num].CheckBox_lalt->Checked)
		KeySettings.modifiers |= HID_KEYBOARD_MODIFIER_LEFTALT;
	if (g_KeySettings_Panel[key_num].CheckBox_lwin->Checked)
		KeySettings.modifiers |= HID_KEYBOARD_MODIFIER_LEFTGUI;
	if (g_KeySettings_Panel[key_num].CheckBox_rctl->Checked)
		KeySettings.modifiers |= HID_KEYBOARD_MODIFIER_RIGHTCTRL;
	if (g_KeySettings_Panel[key_num].CheckBox_rshift->Checked)
		KeySettings.modifiers |= HID_KEYBOARD_MODIFIER_RIGHTSHIFT;
	if (g_KeySettings_Panel[key_num].CheckBox_ralt->Checked)
		KeySettings.modifiers |= HID_KEYBOARD_MODIFIER_RIGHTALT;
	if (g_KeySettings_Panel[key_num].CheckBox_rwin->Checked)
		KeySettings.modifiers |= HID_KEYBOARD_MODIFIER_RIGHTGUI;
}

void Device_WriteSettings(void)
{
	int ret = 0;
	int i;
	if (!is_connected) return;
	Form1->Button_write->Enabled = false;
	Form1->Label_status->Caption = L"Запись настроек...";
	Form1->Label_status->Font->Color = clRed;
	/// Write settings
	for(i=0;i< MAX_KEY_COUNT;i++)
	{
		Sync_Settings_to_struct(g_KeySettings_Device[i], i);
		if ((g_KeySettings_Device[i].active)&&(g_KeySettings_Device[i].save_flag)) {
			ret = Write_Key_Settings(i, g_KeySettings_Device[i].usage_page,
				g_KeySettings_Device[i].modifiers, g_KeySettings_Device[i].scancode,
				Device_VID, Device_PID, Device_UsagePage, Device_Usage);
			if (ret < 0) {
				Form1->Label_status->Caption = L"Ошибка записи настроек!";
				Form1->Label_status->Font->Color = clRed;
				break;
			} else {
				g_KeySettings_Device[i].save_flag = 0;
				Sync_Settings_to_panel(g_KeySettings_Device[i], i);
			}
		}
	}
	if (ret >= 0) {
		Form1->Label_status->Caption = L"Настройки записаны";
		Form1->Label_status->Font->Color = clGreen;
	}
	Form1->Button_write->Enabled = true;
}

void __fastcall TForm1::Button_readClick(TObject *Sender)
{
	Form1->Button_read->Enabled = false;
	Device_ReadSettings();
	Form1->Button_read->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Init_sc_List();
	Init_KeySettings_Panel();
	if (LoadHIDLib()) {
		MessageBox(NULL, L"Ошибка! HID.DLL либо SETUPAPI.DLL не может быть загружен.", L"Ошибка", 0);
		Form1->Close();
		return;
	}
	Device_ReadSettings();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	UnloadHIDLib();
	Destroy_sc_List();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit_VIDKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (((Key >= L'0')&&(Key <= '9'))
		||((Key >= L'a')&&(Key <= 'f'))
		||(Key == L'\b'))
	{
	 // OK
	} else {
		Key = 0;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox_sc_key0Change(TObject *Sender)
{
	Key_Settings_changed(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key0Change(TObject *Sender)
{
	Key_Settings_changed(0);
	KB_Changed(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key1Change(TObject *Sender)
{
	Key_Settings_changed(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key1Change(TObject *Sender)
{
	Key_Settings_changed(1);
	KB_Changed(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key2Change(TObject *Sender)
{
	Key_Settings_changed(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key2Change(TObject *Sender)
{
	Key_Settings_changed(2);
	KB_Changed(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key3Change(TObject *Sender)
{
	Key_Settings_changed(3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key3Change(TObject *Sender)
{
	Key_Settings_changed(3);
	KB_Changed(3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key4Change(TObject *Sender)
{
	Key_Settings_changed(4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key4Change(TObject *Sender)
{
	Key_Settings_changed(4);
	KB_Changed(4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key5Change(TObject *Sender)
{
	Key_Settings_changed(5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key5Change(TObject *Sender)
{
	Key_Settings_changed(5);
	KB_Changed(5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key6Change(TObject *Sender)
{
	Key_Settings_changed(6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key6Change(TObject *Sender)
{
	Key_Settings_changed(6);
	KB_Changed(6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key7Change(TObject *Sender)
{
	Key_Settings_changed(7);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key7Change(TObject *Sender)
{
	Key_Settings_changed(7);
	KB_Changed(7);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key8Change(TObject *Sender)
{
	Key_Settings_changed(8);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key8Change(TObject *Sender)
{
	Key_Settings_changed(8);
	KB_Changed(8);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key9Change(TObject *Sender)
{
	Key_Settings_changed(9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key9Change(TObject *Sender)
{
	Key_Settings_changed(9);
	KB_Changed(9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key10Change(TObject *Sender)
{
	Key_Settings_changed(10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key10Change(TObject *Sender)
{
	Key_Settings_changed(10);
	KB_Changed(10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key11Change(TObject *Sender)
{
	Key_Settings_changed(11);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key11Change(TObject *Sender)
{
	Key_Settings_changed(11);
	KB_Changed(11);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key12Change(TObject *Sender)
{
	Key_Settings_changed(12);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key12Change(TObject *Sender)
{
	Key_Settings_changed(12);
	KB_Changed(12);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key13Change(TObject *Sender)
{
	Key_Settings_changed(13);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key13Change(TObject *Sender)
{
	Key_Settings_changed(13);
	KB_Changed(13);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key14Change(TObject *Sender)
{
	Key_Settings_changed(14);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key14Change(TObject *Sender)
{
	Key_Settings_changed(14);
	KB_Changed(14);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_sc_key15Change(TObject *Sender)
{
	Key_Settings_changed(15);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox_kb_key15Change(TObject *Sender)
{
	Key_Settings_changed(15);
	KB_Changed(15);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button_writeClick(TObject *Sender)
{
	Device_WriteSettings();
}
//---------------------------------------------------------------------------

