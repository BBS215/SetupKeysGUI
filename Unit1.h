//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

#define MAX_KEY_COUNT   16
#define STD_KEYBOARD_USAGE_PAGE 						0x7
#define EXT1_KEYBOARD_USAGE_PAGE 						0xC
#define EXT2_KEYBOARD_USAGE_PAGE 						0x1
#define HID_KEYBOARD_MODIFIER_LEFTCTRL                  (1 << 0)
#define HID_KEYBOARD_MODIFIER_LEFTSHIFT                 (1 << 1)
#define HID_KEYBOARD_MODIFIER_LEFTALT                   (1 << 2)
#define HID_KEYBOARD_MODIFIER_LEFTGUI                   (1 << 3)
#define HID_KEYBOARD_MODIFIER_RIGHTCTRL                 (1 << 4)
#define HID_KEYBOARD_MODIFIER_RIGHTSHIFT                (1 << 5)
#define HID_KEYBOARD_MODIFIER_RIGHTALT                  (1 << 6)
#define HID_KEYBOARD_MODIFIER_RIGHTGUI                  (1 << 7)

typedef struct s_KeySettings_Panel {
	TPanel *Panel;
	TCheckBox *CheckBox_save;
	TComboBox *ComboBox_kb;
	TComboBox *ComboBox_sc;
	TCheckBox *CheckBox_lctl;
	TCheckBox *CheckBox_lshift;
	TCheckBox *CheckBox_lalt;
	TCheckBox *CheckBox_lwin;
	TCheckBox *CheckBox_rctl;
	TCheckBox *CheckBox_rshift;
	TCheckBox *CheckBox_ralt;
	TCheckBox *CheckBox_rwin;
} t_KeySettings_Panel;

typedef struct s_KeySettings {
	uint8_t active;
	uint8_t usage_page;
	uint8_t modifiers;
	uint16_t scancode;
	uint8_t save_flag;
} t_KeySettings;


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button_read;
	TEdit *Edit_VID;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit_PID;
	TEdit *Edit_UsagePage;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit_Usage;
	TLabel *Label_status;
	TPanel *Panel_key0;
	TLabel *Label6;
	TLabel *Label7;
	TComboBox *ComboBox_kb_key0;
	TLabel *Label8;
	TComboBox *ComboBox_sc_key0;
	TCheckBox *CheckBox_lctl_key0;
	TCheckBox *CheckBox_lshift_key0;
	TCheckBox *CheckBox_lalt_key0;
	TCheckBox *CheckBox_lwin_key0;
	TCheckBox *CheckBox_rctl_key0;
	TCheckBox *CheckBox_rshift_key0;
	TCheckBox *CheckBox_ralt_key0;
	TCheckBox *CheckBox_rwin_key0;
	TPanel *Panel_key1;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TComboBox *ComboBox_kb_key1;
	TComboBox *ComboBox_sc_key1;
	TCheckBox *CheckBox_lctl_key1;
	TCheckBox *CheckBox_lshift_key1;
	TCheckBox *CheckBox_lalt_key1;
	TCheckBox *CheckBox_lwin_key1;
	TCheckBox *CheckBox_rctl_key1;
	TCheckBox *CheckBox_rshift_key1;
	TCheckBox *CheckBox_ralt_key1;
	TCheckBox *CheckBox_rwin_key1;
	TPanel *Panel_key2;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TComboBox *ComboBox_kb_key2;
	TComboBox *ComboBox_sc_key2;
	TCheckBox *CheckBox_lctl_key2;
	TCheckBox *CheckBox_lshift_key2;
	TCheckBox *CheckBox_lalt_key2;
	TCheckBox *CheckBox_lwin_key2;
	TCheckBox *CheckBox_rctl_key2;
	TCheckBox *CheckBox_rshift_key2;
	TCheckBox *CheckBox_ralt_key2;
	TCheckBox *CheckBox_rwin_key2;
	TPanel *Panel_key3;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TComboBox *ComboBox_kb_key3;
	TComboBox *ComboBox_sc_key3;
	TCheckBox *CheckBox_lctl_key3;
	TCheckBox *CheckBox_lshift_key3;
	TCheckBox *CheckBox_lalt_key3;
	TCheckBox *CheckBox_lwin_key3;
	TCheckBox *CheckBox_rctl_key3;
	TCheckBox *CheckBox_rshift_key3;
	TCheckBox *CheckBox_ralt_key3;
	TCheckBox *CheckBox_rwin_key3;
	TPanel *Panel_key4;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TComboBox *ComboBox_kb_key4;
	TComboBox *ComboBox_sc_key4;
	TCheckBox *CheckBox_lctl_key4;
	TCheckBox *CheckBox_lshift_key4;
	TCheckBox *CheckBox_lalt_key4;
	TCheckBox *CheckBox_lwin_key4;
	TCheckBox *CheckBox_rctl_key4;
	TCheckBox *CheckBox_rshift_key4;
	TCheckBox *CheckBox_ralt_key4;
	TCheckBox *CheckBox_rwin_key4;
	TPanel *Panel_key5;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TComboBox *ComboBox_kb_key5;
	TComboBox *ComboBox_sc_key5;
	TCheckBox *CheckBox_lctl_key5;
	TCheckBox *CheckBox_lshift_key5;
	TCheckBox *CheckBox_lalt_key5;
	TCheckBox *CheckBox_lwin_key5;
	TCheckBox *CheckBox_rctl_key5;
	TCheckBox *CheckBox_rshift_key5;
	TCheckBox *CheckBox_ralt_key5;
	TCheckBox *CheckBox_rwin_key5;
	TPanel *Panel_key6;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TComboBox *ComboBox_kb_key6;
	TComboBox *ComboBox_sc_key6;
	TCheckBox *CheckBox_lctl_key6;
	TCheckBox *CheckBox_lshift_key6;
	TCheckBox *CheckBox_lalt_key6;
	TCheckBox *CheckBox_lwin_key6;
	TCheckBox *CheckBox_rctl_key6;
	TCheckBox *CheckBox_rshift_key6;
	TCheckBox *CheckBox_ralt_key6;
	TCheckBox *CheckBox_rwin_key6;
	TPanel *Panel_key7;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TComboBox *ComboBox_kb_key7;
	TComboBox *ComboBox_sc_key7;
	TCheckBox *CheckBox_lctl_key7;
	TCheckBox *CheckBox_lshift_key7;
	TCheckBox *CheckBox_lalt_key7;
	TCheckBox *CheckBox_lwin_key7;
	TCheckBox *CheckBox_rctl_key7;
	TCheckBox *CheckBox_rshift_key7;
	TCheckBox *CheckBox_ralt_key7;
	TCheckBox *CheckBox_rwin_key7;
	TPanel *Panel_key8;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TComboBox *ComboBox_kb_key8;
	TComboBox *ComboBox_sc_key8;
	TCheckBox *CheckBox_lctl_key8;
	TCheckBox *CheckBox_lshift_key8;
	TCheckBox *CheckBox_lalt_key8;
	TCheckBox *CheckBox_lwin_key8;
	TCheckBox *CheckBox_rctl_key8;
	TCheckBox *CheckBox_rshift_key8;
	TCheckBox *CheckBox_ralt_key8;
	TCheckBox *CheckBox_rwin_key8;
	TPanel *Panel_key9;
	TLabel *Label33;
	TLabel *Label34;
	TLabel *Label35;
	TComboBox *ComboBox_kb_key9;
	TComboBox *ComboBox_sc_key9;
	TCheckBox *CheckBox_lctl_key9;
	TCheckBox *CheckBox_lshift_key9;
	TCheckBox *CheckBox_lalt_key9;
	TCheckBox *CheckBox_lwin_key9;
	TCheckBox *CheckBox_rctl_key9;
	TCheckBox *CheckBox_rshift_key9;
	TCheckBox *CheckBox_ralt_key9;
	TCheckBox *CheckBox_rwin_key9;
	TPanel *Panel_key10;
	TLabel *Label36;
	TLabel *Label37;
	TLabel *Label38;
	TComboBox *ComboBox_kb_key10;
	TComboBox *ComboBox_sc_key10;
	TCheckBox *CheckBox_lctl_key10;
	TCheckBox *CheckBox_lshift_key10;
	TCheckBox *CheckBox_lalt_key10;
	TCheckBox *CheckBox_lwin_key10;
	TCheckBox *CheckBox_rctl_key10;
	TCheckBox *CheckBox_rshift_key10;
	TCheckBox *CheckBox_ralt_key10;
	TCheckBox *CheckBox_rwin_key10;
	TPanel *Panel_key11;
	TLabel *Label39;
	TLabel *Label40;
	TLabel *Label41;
	TComboBox *ComboBox_kb_key11;
	TComboBox *ComboBox_sc_key11;
	TCheckBox *CheckBox_lctl_key11;
	TCheckBox *CheckBox_lshift_key11;
	TCheckBox *CheckBox_lalt_key11;
	TCheckBox *CheckBox_lwin_key11;
	TCheckBox *CheckBox_rctl_key11;
	TCheckBox *CheckBox_rshift_key11;
	TCheckBox *CheckBox_ralt_key11;
	TCheckBox *CheckBox_rwin_key11;
	TPanel *Panel_key12;
	TLabel *Label42;
	TLabel *Label43;
	TLabel *Label44;
	TComboBox *ComboBox_kb_key12;
	TComboBox *ComboBox_sc_key12;
	TCheckBox *CheckBox_lctl_key12;
	TCheckBox *CheckBox_lshift_key12;
	TCheckBox *CheckBox_lalt_key12;
	TCheckBox *CheckBox_lwin_key12;
	TCheckBox *CheckBox_rctl_key12;
	TCheckBox *CheckBox_rshift_key12;
	TCheckBox *CheckBox_ralt_key12;
	TCheckBox *CheckBox_rwin_key12;
	TPanel *Panel_key13;
	TLabel *Label45;
	TLabel *Label46;
	TLabel *Label47;
	TComboBox *ComboBox_kb_key13;
	TComboBox *ComboBox_sc_key13;
	TCheckBox *CheckBox_lctl_key13;
	TCheckBox *CheckBox_lshift_key13;
	TCheckBox *CheckBox_lalt_key13;
	TCheckBox *CheckBox_lwin_key13;
	TCheckBox *CheckBox_rctl_key13;
	TCheckBox *CheckBox_rshift_key13;
	TCheckBox *CheckBox_ralt_key13;
	TCheckBox *CheckBox_rwin_key13;
	TPanel *Panel_key14;
	TLabel *Label48;
	TLabel *Label49;
	TLabel *Label50;
	TComboBox *ComboBox_kb_key14;
	TComboBox *ComboBox_sc_key14;
	TCheckBox *CheckBox_lctl_key14;
	TCheckBox *CheckBox_lshift_key14;
	TCheckBox *CheckBox_lalt_key14;
	TCheckBox *CheckBox_lwin_key14;
	TCheckBox *CheckBox_rctl_key14;
	TCheckBox *CheckBox_rshift_key14;
	TCheckBox *CheckBox_ralt_key14;
	TCheckBox *CheckBox_rwin_key14;
	TPanel *Panel_key15;
	TLabel *Label51;
	TLabel *Label52;
	TLabel *Label53;
	TComboBox *ComboBox_kb_key15;
	TComboBox *ComboBox_sc_key15;
	TCheckBox *CheckBox_lctl_key15;
	TCheckBox *CheckBox_lshift_key15;
	TCheckBox *CheckBox_lalt_key15;
	TCheckBox *CheckBox_lwin_key15;
	TCheckBox *CheckBox_rctl_key15;
	TCheckBox *CheckBox_rshift_key15;
	TCheckBox *CheckBox_ralt_key15;
	TCheckBox *CheckBox_rwin_key15;
	TButton *Button_write;
	TCheckBox *CheckBox_save_key0;
	TCheckBox *CheckBox_save_key1;
	TCheckBox *CheckBox_save_key2;
	TCheckBox *CheckBox_save_key3;
	TCheckBox *CheckBox_save_key4;
	TCheckBox *CheckBox_save_key5;
	TCheckBox *CheckBox_save_key6;
	TCheckBox *CheckBox_save_key7;
	TCheckBox *CheckBox_save_key8;
	TCheckBox *CheckBox_save_key9;
	TCheckBox *CheckBox_save_key10;
	TCheckBox *CheckBox_save_key11;
	TCheckBox *CheckBox_save_key12;
	TCheckBox *CheckBox_save_key13;
	TCheckBox *CheckBox_save_key14;
	TCheckBox *CheckBox_save_key15;
	void __fastcall Button_readClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Edit_VIDKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ComboBox_sc_key0Change(TObject *Sender);
	void __fastcall ComboBox_kb_key0Change(TObject *Sender);
	void __fastcall ComboBox_sc_key1Change(TObject *Sender);
	void __fastcall ComboBox_kb_key1Change(TObject *Sender);
	void __fastcall ComboBox_sc_key2Change(TObject *Sender);
	void __fastcall ComboBox_kb_key2Change(TObject *Sender);
	void __fastcall ComboBox_sc_key3Change(TObject *Sender);
	void __fastcall ComboBox_kb_key3Change(TObject *Sender);
	void __fastcall ComboBox_sc_key4Change(TObject *Sender);
	void __fastcall ComboBox_kb_key4Change(TObject *Sender);
	void __fastcall ComboBox_sc_key5Change(TObject *Sender);
	void __fastcall ComboBox_kb_key5Change(TObject *Sender);
	void __fastcall ComboBox_sc_key6Change(TObject *Sender);
	void __fastcall ComboBox_kb_key6Change(TObject *Sender);
	void __fastcall ComboBox_sc_key7Change(TObject *Sender);
	void __fastcall ComboBox_kb_key7Change(TObject *Sender);
	void __fastcall ComboBox_sc_key8Change(TObject *Sender);
	void __fastcall ComboBox_kb_key8Change(TObject *Sender);
	void __fastcall ComboBox_sc_key9Change(TObject *Sender);
	void __fastcall ComboBox_kb_key9Change(TObject *Sender);
	void __fastcall ComboBox_sc_key10Change(TObject *Sender);
	void __fastcall ComboBox_kb_key10Change(TObject *Sender);
	void __fastcall ComboBox_sc_key11Change(TObject *Sender);
	void __fastcall ComboBox_kb_key11Change(TObject *Sender);
	void __fastcall ComboBox_sc_key12Change(TObject *Sender);
	void __fastcall ComboBox_kb_key12Change(TObject *Sender);
	void __fastcall ComboBox_sc_key13Change(TObject *Sender);
	void __fastcall ComboBox_kb_key13Change(TObject *Sender);
	void __fastcall ComboBox_sc_key14Change(TObject *Sender);
	void __fastcall ComboBox_kb_key14Change(TObject *Sender);
	void __fastcall ComboBox_sc_key15Change(TObject *Sender);
	void __fastcall ComboBox_kb_key15Change(TObject *Sender);
	void __fastcall Button_writeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
