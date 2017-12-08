object Form1: TForm1
  Left = 0
  Top = 0
  VertScrollBar.ButtonSize = 10
  VertScrollBar.Tracking = True
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'SetupKeysGUI'
  ClientHeight = 587
  ClientWidth = 1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 13
    Width = 64
    Height = 13
    Caption = 'VendorID: 0x'
  end
  object Label2: TLabel
    Left = 128
    Top = 13
    Width = 67
    Height = 13
    Caption = 'ProductID: 0x'
  end
  object Label3: TLabel
    Left = 247
    Top = 13
    Width = 76
    Height = 13
    Caption = 'Usage Page: 0x'
  end
  object Label4: TLabel
    Left = 375
    Top = 13
    Width = 49
    Height = 13
    Caption = 'Usage: 0x'
  end
  object Label_status: TLabel
    Left = 476
    Top = 13
    Width = 80
    Height = 13
    Caption = #1053#1077' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1086
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Button_read: TButton
    Left = 630
    Top = 8
    Width = 112
    Height = 25
    Caption = #1057#1095#1080#1090#1072#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
    TabOrder = 0
    OnClick = Button_readClick
  end
  object Edit_VID: TEdit
    Left = 75
    Top = 10
    Width = 44
    Height = 21
    CharCase = ecLowerCase
    MaxLength = 4
    TabOrder = 1
    Text = '043b'
    OnKeyPress = Edit_VIDKeyPress
  end
  object Edit_PID: TEdit
    Left = 197
    Top = 10
    Width = 44
    Height = 21
    CharCase = ecLowerCase
    MaxLength = 4
    TabOrder = 2
    Text = '0325'
    OnKeyPress = Edit_VIDKeyPress
  end
  object Edit_UsagePage: TEdit
    Left = 325
    Top = 10
    Width = 44
    Height = 21
    CharCase = ecLowerCase
    MaxLength = 4
    TabOrder = 3
    Text = '01'
    OnKeyPress = Edit_VIDKeyPress
  end
  object Edit_Usage: TEdit
    Left = 426
    Top = 10
    Width = 44
    Height = 21
    CharCase = ecLowerCase
    MaxLength = 4
    TabOrder = 4
    Text = '80'
    OnKeyPress = Edit_VIDKeyPress
  end
  object Panel_key0: TPanel
    Left = 8
    Top = 44
    Width = 267
    Height = 129
    Caption = 'Panel_key0'
    ShowCaption = False
    TabOrder = 5
    object Label6: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 0'
    end
    object Label7: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label8: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key0: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key0Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key0: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      BiDiMode = bdLeftToRight
      ItemIndex = 0
      ParentBiDiMode = False
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key0Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key0: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key0Change
    end
    object CheckBox_lshift_key0: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key0Change
    end
    object CheckBox_lalt_key0: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key0Change
    end
    object CheckBox_lwin_key0: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key0Change
    end
    object CheckBox_rctl_key0: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key0Change
    end
    object CheckBox_rshift_key0: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key0Change
    end
    object CheckBox_ralt_key0: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key0Change
    end
    object CheckBox_rwin_key0: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key0Change
    end
    object CheckBox_save_key0: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key1: TPanel
    Left = 8
    Top = 179
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 6
    object Label9: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 1'
    end
    object Label10: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label11: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key1: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key1Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key1: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key1Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key1: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key1Change
    end
    object CheckBox_lshift_key1: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key1Change
    end
    object CheckBox_lalt_key1: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key1Change
    end
    object CheckBox_lwin_key1: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key1Change
    end
    object CheckBox_rctl_key1: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key1Change
    end
    object CheckBox_rshift_key1: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key1Change
    end
    object CheckBox_ralt_key1: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key1Change
    end
    object CheckBox_rwin_key1: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key1Change
    end
    object CheckBox_save_key1: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key2: TPanel
    Left = 8
    Top = 314
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 7
    object Label12: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 2'
    end
    object Label13: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label14: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key2: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key2Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key2: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key2Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key2: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key2Change
    end
    object CheckBox_lshift_key2: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key2Change
    end
    object CheckBox_lalt_key2: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key2Change
    end
    object CheckBox_lwin_key2: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key2Change
    end
    object CheckBox_rctl_key2: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key2Change
    end
    object CheckBox_rshift_key2: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key2Change
    end
    object CheckBox_ralt_key2: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key2Change
    end
    object CheckBox_rwin_key2: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key2Change
    end
    object CheckBox_save_key2: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key3: TPanel
    Left = 8
    Top = 449
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 8
    object Label15: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 3'
    end
    object Label16: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label17: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key3: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key3Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key3: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key3Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key3: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key3Change
    end
    object CheckBox_lshift_key3: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key3Change
    end
    object CheckBox_lalt_key3: TCheckBox
      Left = 122
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key3Change
    end
    object CheckBox_lwin_key3: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key3Change
    end
    object CheckBox_rctl_key3: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key3Change
    end
    object CheckBox_rshift_key3: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key3Change
    end
    object CheckBox_ralt_key3: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key3Change
    end
    object CheckBox_rwin_key3: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key3Change
    end
    object CheckBox_save_key3: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key4: TPanel
    Left = 281
    Top = 44
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 9
    object Label18: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 4'
    end
    object Label19: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label20: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key4: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key4Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key4: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key4Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key4: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key4Change
    end
    object CheckBox_lshift_key4: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key4Change
    end
    object CheckBox_lalt_key4: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key4Change
    end
    object CheckBox_lwin_key4: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key4Change
    end
    object CheckBox_rctl_key4: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key4Change
    end
    object CheckBox_rshift_key4: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key4Change
    end
    object CheckBox_ralt_key4: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key4Change
    end
    object CheckBox_rwin_key4: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key4Change
    end
    object CheckBox_save_key4: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key5: TPanel
    Left = 281
    Top = 179
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 10
    object Label21: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 5'
    end
    object Label22: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label23: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key5: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key5Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key5: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key5Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key5: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key5Change
    end
    object CheckBox_lshift_key5: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key5Change
    end
    object CheckBox_lalt_key5: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key5Change
    end
    object CheckBox_lwin_key5: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key5Change
    end
    object CheckBox_rctl_key5: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key5Change
    end
    object CheckBox_rshift_key5: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key5Change
    end
    object CheckBox_ralt_key5: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key5Change
    end
    object CheckBox_rwin_key5: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key5Change
    end
    object CheckBox_save_key5: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key6: TPanel
    Left = 281
    Top = 314
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 11
    object Label24: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 6'
    end
    object Label25: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label26: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key6: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key6Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key6: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key6Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key6: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key6Change
    end
    object CheckBox_lshift_key6: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key6Change
    end
    object CheckBox_lalt_key6: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key6Change
    end
    object CheckBox_lwin_key6: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key6Change
    end
    object CheckBox_rctl_key6: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key6Change
    end
    object CheckBox_rshift_key6: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key6Change
    end
    object CheckBox_ralt_key6: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key6Change
    end
    object CheckBox_rwin_key6: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key6Change
    end
    object CheckBox_save_key6: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key7: TPanel
    Left = 281
    Top = 449
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 12
    object Label27: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 7'
    end
    object Label28: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label29: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key7: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key7Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key7: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key7Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key7: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key7Change
    end
    object CheckBox_lshift_key7: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key7Change
    end
    object CheckBox_lalt_key7: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key7Change
    end
    object CheckBox_lwin_key7: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key7Change
    end
    object CheckBox_rctl_key7: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key7Change
    end
    object CheckBox_rshift_key7: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key7Change
    end
    object CheckBox_ralt_key7: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key7Change
    end
    object CheckBox_rwin_key7: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key7Change
    end
    object CheckBox_save_key7: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key8: TPanel
    Left = 554
    Top = 44
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 13
    object Label30: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 8'
    end
    object Label31: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label32: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key8: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key8Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key8: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key8Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key8: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key8Change
    end
    object CheckBox_lshift_key8: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key8Change
    end
    object CheckBox_lalt_key8: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key8Change
    end
    object CheckBox_lwin_key8: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key8Change
    end
    object CheckBox_rctl_key8: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key8Change
    end
    object CheckBox_rshift_key8: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key8Change
    end
    object CheckBox_ralt_key8: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key8Change
    end
    object CheckBox_rwin_key8: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key8Change
    end
    object CheckBox_save_key8: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key9: TPanel
    Left = 554
    Top = 179
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 14
    object Label33: TLabel
      Left = 6
      Top = 5
      Width = 54
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 9'
    end
    object Label34: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label35: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key9: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key9Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key9: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key9Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key9: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key9Change
    end
    object CheckBox_lshift_key9: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key9Change
    end
    object CheckBox_lalt_key9: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key9Change
    end
    object CheckBox_lwin_key9: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key9Change
    end
    object CheckBox_rctl_key9: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key9Change
    end
    object CheckBox_rshift_key9: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key9Change
    end
    object CheckBox_ralt_key9: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key9Change
    end
    object CheckBox_rwin_key9: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key9Change
    end
    object CheckBox_save_key9: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key10: TPanel
    Left = 554
    Top = 314
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 15
    object Label36: TLabel
      Left = 6
      Top = 5
      Width = 60
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 10'
    end
    object Label37: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label38: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key10: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key10Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key10: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key10Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key10: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key10Change
    end
    object CheckBox_lshift_key10: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key10Change
    end
    object CheckBox_lalt_key10: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key10Change
    end
    object CheckBox_lwin_key10: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key10Change
    end
    object CheckBox_rctl_key10: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key10Change
    end
    object CheckBox_rshift_key10: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key10Change
    end
    object CheckBox_ralt_key10: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key10Change
    end
    object CheckBox_rwin_key10: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key10Change
    end
    object CheckBox_save_key10: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key11: TPanel
    Left = 554
    Top = 449
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 16
    object Label39: TLabel
      Left = 6
      Top = 5
      Width = 60
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 11'
    end
    object Label40: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label41: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key11: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key11Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key11: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key11Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key11: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key11Change
    end
    object CheckBox_lshift_key11: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key11Change
    end
    object CheckBox_lalt_key11: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key11Change
    end
    object CheckBox_lwin_key11: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key11Change
    end
    object CheckBox_rctl_key11: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key11Change
    end
    object CheckBox_rshift_key11: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key11Change
    end
    object CheckBox_ralt_key11: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key11Change
    end
    object CheckBox_rwin_key11: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key11Change
    end
    object CheckBox_save_key11: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key12: TPanel
    Left = 827
    Top = 44
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 17
    object Label42: TLabel
      Left = 6
      Top = 5
      Width = 60
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 12'
    end
    object Label43: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label44: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key12: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key12Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key12: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key12Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key12: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key12Change
    end
    object CheckBox_lshift_key12: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key12Change
    end
    object CheckBox_lalt_key12: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key12Change
    end
    object CheckBox_lwin_key12: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key12Change
    end
    object CheckBox_rctl_key12: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key12Change
    end
    object CheckBox_rshift_key12: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key12Change
    end
    object CheckBox_ralt_key12: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key12Change
    end
    object CheckBox_rwin_key12: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key12Change
    end
    object CheckBox_save_key12: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key13: TPanel
    Left = 827
    Top = 179
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 18
    object Label45: TLabel
      Left = 6
      Top = 5
      Width = 60
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 13'
    end
    object Label46: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label47: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key13: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key13Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key13: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key13Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key13: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key13Change
    end
    object CheckBox_lshift_key13: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key13Change
    end
    object CheckBox_lalt_key13: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key13Change
    end
    object CheckBox_lwin_key13: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key13Change
    end
    object CheckBox_rctl_key13: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key13Change
    end
    object CheckBox_rshift_key13: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key13Change
    end
    object CheckBox_ralt_key13: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key13Change
    end
    object CheckBox_rwin_key13: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key13Change
    end
    object CheckBox_save_key13: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key14: TPanel
    Left = 827
    Top = 314
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 19
    object Label48: TLabel
      Left = 6
      Top = 5
      Width = 60
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 14'
    end
    object Label49: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label50: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key14: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key14Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key14: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key14Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key14: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key14Change
    end
    object CheckBox_lshift_key14: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key14Change
    end
    object CheckBox_lalt_key14: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key14Change
    end
    object CheckBox_lwin_key14: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key14Change
    end
    object CheckBox_rctl_key14: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key14Change
    end
    object CheckBox_rshift_key14: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key14Change
    end
    object CheckBox_ralt_key14: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key14Change
    end
    object CheckBox_rwin_key14: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key14Change
    end
    object CheckBox_save_key14: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Panel_key15: TPanel
    Left = 827
    Top = 449
    Width = 267
    Height = 129
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 20
    object Label51: TLabel
      Left = 6
      Top = 5
      Width = 60
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1096#1072' 15'
    end
    object Label52: TLabel
      Left = 6
      Top = 27
      Width = 65
      Height = 13
      Caption = #1050#1083#1072#1074#1080#1072#1090#1091#1088#1072':'
    end
    object Label53: TLabel
      Left = 6
      Top = 54
      Width = 39
      Height = 13
      Caption = #1050#1086#1076': 0x'
    end
    object ComboBox_kb_key15: TComboBox
      Left = 77
      Top = 24
      Width = 184
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = #1054#1090#1082#1083#1102#1095#1077#1085#1086
      OnChange = ComboBox_kb_key15Change
      Items.Strings = (
        #1054#1090#1082#1083#1102#1095#1077#1085#1086
        #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072#1103
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 1'
        #1056#1072#1089#1096#1080#1088#1077#1085#1085#1072#1103' 2')
    end
    object ComboBox_sc_key15: TComboBox
      Left = 51
      Top = 51
      Width = 210
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 1
      Text = '00 - No event'
      OnChange = ComboBox_sc_key15Change
      Items.Strings = (
        '00 - No event')
    end
    object CheckBox_lctl_key15: TCheckBox
      Left = 6
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LControl'
      TabOrder = 2
      OnEnter = ComboBox_sc_key15Change
    end
    object CheckBox_lshift_key15: TCheckBox
      Left = 67
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LShift'
      TabOrder = 3
      OnEnter = ComboBox_sc_key15Change
    end
    object CheckBox_lalt_key15: TCheckBox
      Left = 120
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LAlt'
      TabOrder = 4
      OnEnter = ComboBox_sc_key15Change
    end
    object CheckBox_lwin_key15: TCheckBox
      Left = 160
      Top = 82
      Width = 65
      Height = 17
      Caption = 'LWin'
      TabOrder = 5
      OnEnter = ComboBox_sc_key15Change
    end
    object CheckBox_rctl_key15: TCheckBox
      Left = 6
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RControl'
      TabOrder = 6
      OnEnter = ComboBox_sc_key15Change
    end
    object CheckBox_rshift_key15: TCheckBox
      Left = 67
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RShift'
      TabOrder = 7
      OnEnter = ComboBox_sc_key15Change
    end
    object CheckBox_ralt_key15: TCheckBox
      Left = 120
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RAlt'
      TabOrder = 8
      OnEnter = ComboBox_sc_key15Change
    end
    object CheckBox_rwin_key15: TCheckBox
      Left = 160
      Top = 105
      Width = 65
      Height = 17
      Caption = 'RWin'
      TabOrder = 9
      OnEnter = ComboBox_sc_key15Change
    end
    object CheckBox_save_key15: TCheckBox
      Left = 196
      Top = 4
      Width = 65
      Height = 17
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 10
    end
  end
  object Button_write: TButton
    Left = 748
    Top = 8
    Width = 118
    Height = 25
    Caption = #1047#1072#1087#1080#1089#1072#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
    TabOrder = 21
    OnClick = Button_writeClick
  end
  object Button_Load_from_File: TButton
    Left = 872
    Top = 8
    Width = 113
    Height = 25
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1080#1079' '#1092#1072#1081#1083#1072
    TabOrder = 22
    OnClick = Button_Load_from_FileClick
  end
  object Button_Save_to_File: TButton
    Left = 991
    Top = 8
    Width = 104
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083
    TabOrder = 23
    OnClick = Button_Save_to_FileClick
  end
  object SaveDialog1: TSaveDialog
    FileName = 'settings.ini'
    Filter = 'INI files|*.ini|ALL files|*.*'
    Left = 1064
    Top = 120
  end
  object OpenDialog1: TOpenDialog
    Filter = 'INI files|*.ini|ALL files|*.*'
    Left = 1032
    Top = 120
  end
end
