object FormTestDES8: TFormTestDES8
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Test DES8 - Sending Commands'
  ClientHeight = 685
  ClientWidth = 1216
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 225
    Height = 685
    Align = alLeft
    BevelOuter = bvSpace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    StyleElements = []
    object Label1: TLabel
      Left = 57
      Top = 8
      Width = 63
      Height = 13
      Caption = 'Commands'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelError: TLabel
      Left = 10
      Top = 577
      Width = 24
      Height = 13
      Caption = '0000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LbEventInitReady: TLabel
      Left = 10
      Top = 596
      Width = 24
      Height = 13
      Caption = '0000'
    end
    object labelErrorForDataReq: TLabel
      Left = 191
      Top = 543
      Width = 8
      Height = 16
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblNameErrDataReq: TLabel
      Left = 9
      Top = 543
      Width = 176
      Height = 13
      Caption = 'Number Error For Data Request'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object rb_Start_Continuous_recording: TRadioButton
      Left = 16
      Top = 257
      Width = 185
      Height = 17
      Caption = 'Start Continuous recording into DT'
      TabOrder = 0
      OnClick = rb_Start_Continuous_recordingClick
    end
    object rb_Stop_Continuous_recording: TRadioButton
      Left = 16
      Top = 280
      Width = 185
      Height = 17
      Caption = 'Stop Continuous recording into DT'
      TabOrder = 1
      OnClick = rb_Stop_Continuous_recordingClick
    end
    object rb_Query_Word_state_device: TRadioButton
      Left = 16
      Top = 234
      Width = 153
      Height = 17
      Caption = 'Query Wordstate device'
      TabOrder = 2
      OnClick = rb_Query_Word_state_deviceClick
    end
    object rb_SettingTransmitSpeed: TRadioButton
      Left = 16
      Top = 211
      Width = 201
      Height = 17
      Caption = 'Setting Transmit speed (Down. Tool)'
      Enabled = False
      TabOrder = 3
      OnClick = rb_SettingTransmitSpeedClick
    end
    object rb_Echo: TRadioButton
      Left = 16
      Top = 188
      Width = 113
      Height = 17
      Caption = 'Echo'
      TabOrder = 4
      OnClick = rb_EchoClick
    end
    object rb_Start_Auto_calibr_magnetic_sensors: TRadioButton
      Left = 16
      Top = 165
      Width = 185
      Height = 17
      Caption = 'Start Autocalibr magnetic sensors'
      TabOrder = 5
      OnClick = rb_Start_Auto_calibr_magnetic_sensorsClick
    end
    object rb_Setting_Pot_gain_offset: TRadioButton
      Left = 16
      Top = 142
      Width = 161
      Height = 17
      Caption = 'Setting Pot. gain and offset'
      TabOrder = 6
      OnClick = rb_Setting_Pot_gain_offsetClick
    end
    object rb_Data_Request: TRadioButton
      Left = 16
      Top = 119
      Width = 113
      Height = 17
      Caption = 'Data Request'
      TabOrder = 7
      OnClick = rb_Data_RequestClick
    end
    object rb_Init_Gyro_Acceler_sensors: TRadioButton
      Left = 16
      Top = 96
      Width = 161
      Height = 17
      Caption = 'Init Gyro Acceler sensors'
      TabOrder = 8
      OnClick = rb_Init_Gyro_Acceler_sensorsClick
    end
    object rb_Ping: TRadioButton
      Left = 16
      Top = 27
      Width = 113
      Height = 17
      Caption = 'Ping'
      Checked = True
      TabOrder = 9
      TabStop = True
      OnClick = rb_PingClick
    end
    object rb_Init_Magnetic_sensors: TRadioButton
      Left = 16
      Top = 73
      Width = 137
      Height = 17
      Caption = 'Init Magnetic sensors'
      TabOrder = 10
      OnClick = rb_Init_Magnetic_sensorsClick
    end
    object rb_Init_Sonde: TRadioButton
      Left = 16
      Top = 50
      Width = 113
      Height = 17
      Caption = 'Init Sonde'
      TabOrder = 11
      OnClick = rb_Init_SondeClick
    end
    object Panel2: TPanel
      Left = 1
      Top = 647
      Width = 223
      Height = 37
      Align = alBottom
      BevelInner = bvLowered
      TabOrder = 12
      object btn_Send_Command: TButton
        Left = 15
        Top = 8
        Width = 99
        Height = 22
        Caption = 'Send Command'
        TabOrder = 0
        StyleElements = []
        OnClick = btn_Send_CommandClick
      end
      object pnl_response_command: TPanel
        Left = 125
        Top = 9
        Width = 20
        Height = 20
        Hint = 'Successful/Error Command to DT'
        BevelInner = bvSpace
        BevelKind = bkSoft
        BevelOuter = bvSpace
        ParentBackground = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
      end
      object pnlEventControlChNunBlHID: TPanel
        Left = 175
        Top = 11
        Width = 17
        Height = 17
        Hint = 'Control Event ChangeNumBlockHID'
        BevelInner = bvSpace
        BevelKind = bkSoft
        ParentBackground = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
      end
      object pnlEventControlMethodOnChage: TPanel
        Left = 151
        Top = 11
        Width = 18
        Height = 17
        Hint = 'Control Event MethodOnChage'
        BevelInner = bvSpace
        BevelKind = bkSoft
        ParentBackground = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
      end
    end
    object rb_Reset_SpeedMove: TRadioButton
      Left = 16
      Top = 303
      Width = 113
      Height = 17
      Caption = 'Reset Speed Move'
      TabOrder = 13
      OnClick = rb_Reset_SpeedMoveClick
    end
    object rb_Reset_Azimuth: TRadioButton
      Left = 16
      Top = 326
      Width = 113
      Height = 17
      Caption = 'Reset Azimuth'
      TabOrder = 14
      OnClick = rb_Reset_AzimuthClick
    end
    object chkAutoRandomComm: TCheckBox
      Left = 19
      Top = 461
      Width = 137
      Height = 17
      Caption = 'AutoRandom Command'
      TabOrder = 15
      OnClick = chkAutoRandomCommClick
    end
    object chkCycleComman: TCheckBox
      Left = 19
      Top = 492
      Width = 121
      Height = 17
      Caption = 'Cycle Command'
      TabOrder = 16
      OnClick = chkCycleCommanClick
    end
    object rb_Set_Service_Parameters: TRadioButton
      Left = 16
      Top = 349
      Width = 113
      Height = 17
      Caption = 'Set Service Parameters'
      TabOrder = 17
      OnClick = rb_Set_Service_ParametersClick
    end
    object rb_SetTime: TRadioButton
      Left = 16
      Top = 372
      Width = 113
      Height = 17
      Caption = 'Set Time to DT'
      TabOrder = 18
      OnClick = rb_SetTimeClick
    end
    object rb_SetDepth: TRadioButton
      Left = 16
      Top = 395
      Width = 113
      Height = 17
      Caption = 'Set Depth to DT'
      TabOrder = 19
      OnClick = rb_SetDepthClick
    end
    object chkSetDepthDataReq: TCheckBox
      Left = 19
      Top = 515
      Width = 201
      Height = 17
      Caption = 'Cycle SetDepth DataRequest'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 20
      OnClick = chkSetDepthDataReqClick
    end
  end
  object Panel3: TPanel
    Left = 225
    Top = 0
    Width = 991
    Height = 685
    Align = alClient
    BevelOuter = bvSpace
    Caption = 'Panel3'
    ShowCaption = False
    TabOrder = 1
    object Label2: TLabel
      Left = 22
      Top = 8
      Width = 169
      Height = 13
      Caption = 'The contents of the command'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object IxObjectInspector1: TIxObjectInspector
      Left = 1
      Top = 43
      Width = 256
      Height = 641
      Align = alCustom
      Color = clBtnFace
      DeleteBlanks = False
      DisplayKinds = [tkInteger, tkChar, tkEnumeration, tkFloat, tkString, tkSet, tkClass, tkWChar, tkLString, tkWString, tkVariant, tkInterface, tkInt64]
      DynamicTitleCaptions = True
      ValueFont.Charset = DEFAULT_CHARSET
      ValueFont.Color = clNavy
      ValueFont.Height = -11
      ValueFont.Name = 'MS Sans Serif'
      ValueFont.Style = []
      CategoryFont.Charset = DEFAULT_CHARSET
      CategoryFont.Color = clHighlight
      CategoryFont.Height = -11
      CategoryFont.Name = 'MS Sans Serif'
      CategoryFont.Style = [fsBold]
      TitleCaptionFont.Charset = DEFAULT_CHARSET
      TitleCaptionFont.Color = clWindowText
      TitleCaptionFont.Height = -11
      TitleCaptionFont.Name = 'MS Sans Serif'
      TitleCaptionFont.Style = []
      Indent = 11
      PathDelimiter = '.'
      Sorted = False
      TabOrder = 0
      TitleCaptions.Strings = (
        'Command Description'
        'Command Data')
      InplaceCollections = True
      InplaceTStringsOptions = []
      StringsItemFormat = 'Items[%d]'
      CollectionItemFormat = 'Items[%d]'
      OnPropertyChanged = IxObjectInspector1PropertyChanged
      ValueChangedFont.Charset = DEFAULT_CHARSET
      ValueChangedFont.Color = clNavy
      ValueChangedFont.Height = -11
      ValueChangedFont.Name = 'MS Sans Serif'
      ValueChangedFont.Style = [fsBold]
      Objects = <>
      Items.Categories.Strings = (
        'Action=Action'
        'Align=Layout'
        'Align=Visual'
        'Anchors=Layout'
        'BiDiMode=Locale'
        'BiDiMode=Localizable'
        'BorderStyle=Visual'
        'Caption=Action'
        'CategoryFont=Localizable'
        'Color=Visual'
        'Component=Linkage'
        'Constraints=Layout'
        'Constraints=Localizable'
        'Ctl3D=Legacy'
        'Cursor=Visual'
        'DockSite=Drag, Drop and Docking'
        'DragKind=Drag, Drop and Docking'
        'DragMode=Drag, Drop and Docking'
        'Enabled=Action'
        'Enabled=Input'
        'Enabled=Visual'
        'Filters=Database'
        'FixedColor=Visual'
        'Font=Localizable'
        'Font=Visual'
        'Height=Layout'
        'Height=Localizable'
        'Height=Visual'
        'HelpContext=Action'
        'HelpContext=Help and Hints'
        'HelpKeyword=Help and Hints'
        'HelpType=Help and Hints'
        'Hint=Action'
        'Hint=Help and Hints'
        'Hint=Localizable'
        'Left=Layout'
        'Left=Localizable'
        'Left=Visual'
        'ParentBiDiMode=Linkage'
        'ParentBiDiMode=Localizable'
        'ParentColor=Visual'
        'ParentCtl3D=Legacy'
        'ParentFont=Localizable'
        'ParentFont=Visual'
        'ParentShowHint=Help and Hints'
        'PopupMenu=Linkage'
        'ShowHint=Help and Hints'
        'TabOrder=Layout'
        'TabStop=Layout'
        'Top=Layout'
        'Top=Localizable'
        'Top=Visual'
        'UseDockManager=Drag, Drop and Docking'
        'ValueChangedFont=Localizable'
        'ValueChangedFont=Visual'
        'ValueFont=Localizable'
        'ValueFont=Visual'
        'Visible=Action'
        'Visible=Visual'
        'Width=Layout'
        'Width=Localizable'
        'Width=Visual')
      Items.DefaultCategoryName = 'Miscellaneous'
      Items = <>
      ColWidths = (
        150
        101)
      RowHeights = (
        18
        18)
      HPresets = <
        item
          HiddenItemClass = 'TIxTComponentPropertyPreset'
          TypeNames.Strings = (
            'TComponent')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clMaroon
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TComponent Drop Down List Property Editor'
          ParentTypeKinds = [tkUnknown]
          EditStyle = esPickList
          Actions = [pftEditStyle, pftValidate, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTFontNamePropertyPreset'
          TypeNames.Strings = (
            'TFontName')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'Font Drop Down List Property Editor'
          ParentTypeKinds = [tkUnknown]
          EditStyle = esPickList
          Actions = [pftEditStyle, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTColorPropertyPreset'
          TypeNames.Strings = (
            'TColor')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'Color Drop Down List Property Editor'
          ParentTypeKinds = [tkUnknown]
          Actions = [pftEditStyle, pftValidate, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTCursorPropertyPreset'
          TypeNames.Strings = (
            'TCursor')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'Cursor Drop Down List Property Editor'
          ParentTypeKinds = [tkUnknown]
          Actions = [pftEditStyle, pftValidate, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTFontDlgPropertyPreset'
          TypeNames.Strings = (
            'TFont')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'Font Editor Dialog Property Editor'
          ParentTypeKinds = [tkUnknown]
          Actions = [pftEditStyle, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTStringsPropertyPreset'
          TypeNames.Strings = (
            'TStrings')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TStrings Property Editor'
          ParentTypeKinds = [tkUnknown]
          Actions = [pftEditStyle, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTPicturePropertyPreset'
          TypeNames.Strings = (
            'TPicture'
            'TBitmap')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TPicture Property Editor'
          ParentTypeKinds = [tkUnknown]
          Actions = [pftEditStyle, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTCollectionPropertyPreset'
          TypeNames.Strings = (
            'TCollection')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TCollection Property Editor'
          ParentTypeKinds = [tkUnknown]
          Actions = [pftEditStyle, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTDatePropertyPreset'
          TypeNames.Strings = (
            'TDate')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TDate Property Editor'
          ParentTypeKinds = [tkUnknown]
          EditMask = '!90/00/0000;1;_'
          Actions = [pftEditStyle, pftEditMask, pftValidate, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTTimePropertyPreset'
          TypeNames.Strings = (
            'TTime')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TTime Property Editor'
          ParentTypeKinds = [tkUnknown]
          EditMask = '!90:00:00 >LL;1;_'
          Actions = [pftEditMask, pftValidate, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTDateTimePropertyPreset'
          TypeNames.Strings = (
            'TDateTime')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TDateTime Property Editor'
          ParentTypeKinds = [tkUnknown]
          EditMask = '!90/00/0000 90:00:00 >LL;1;_'
          Actions = [pftEditStyle, pftEditMask, pftValidate, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTFilenamePropertyPreset'
          MatchTypes = [mtPropertyType]
          TypeKinds = [tkLString]
          TypeNames.Strings = (
            'TFilename')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TFilename Dialog Property editor'
          ParentTypeKinds = [tkUnknown]
          EditStyle = esEllipsis
          Actions = [pftEditStyle, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTModalResultPropertyPreset'
          TypeNames.Strings = (
            'TModalResult')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TModalResult Property Editor'
          ParentTypeKinds = [tkUnknown]
          PickList.Strings = (
            'mrNone'
            'mrOk'
            'mrCancel'
            'mrAbort'
            'mrRetry'
            'mrIgnore'
            'mrYes'
            'mrNo'
            'mrAll'
            'mrNoToAll'
            'mrYesToAll')
          Actions = [pftEditStyle, pftValidate, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
        end
        item
          HiddenItemClass = 'TIxTINIStringsPropertyPreset'
          TypeNames.Strings = (
            'TStrings'
            'TStrings')
          ParentClassNames.Strings = (
            'TValueListEditor'
            'TIxCustomItemListEditor')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'INI TStrings Property Editor'
          PropNames.Strings = (
            'Strings')
          ParentTypeKinds = [tkUnknown]
          Actions = [pftEditStyle, pftFont, pftValueFont]
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTListItemsDlgPropertyPreset'
          TypeNames.Strings = (
            'TListItems')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TListItems Dialog Property Editor'
          ParentTypeKinds = [tkUnknown]
          Actions = [pftEditStyle, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTTreeNodesDlgPropertyPreset'
          TypeNames.Strings = (
            'TTreeNodes')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TTreeNodes Dialog Property Editor'
          ParentTypeKinds = [tkUnknown]
          Actions = [pftEditStyle, pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxTParentComponentPropertyPreset'
          MatchTypes = [mtParentPropertyType]
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TComponent Subcomponent Properties Font'
          ParentTypeNames.Strings = (
            'TComponent')
          Actions = [pftFont, pftValueFont]
          TypeNamesEmpty = True
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxPropertyPreset'
          MatchTypes = [mtPropertyType]
          TypeKinds = [tkClass]
          TypeNames.Strings = (
            'TCollection')
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'TCollection Hint Property'
          ParentTypeKinds = [tkUnknown]
          Actions = [pftFont, pftValueFont]
          ParentClassNamesEmpty = True
          PropNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end
        item
          HiddenItemClass = 'TIxFilenamePropPropertyPreset'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ValueFont.Charset = DEFAULT_CHARSET
          ValueFont.Color = clWindowText
          ValueFont.Height = -11
          ValueFont.Name = 'MS Sans Serif'
          ValueFont.Style = []
          Name = 'Filename property Dialog Property Editor'
          PropNames.Strings = (
            'filename')
          ParentTypeKinds = [tkUnknown]
          EditStyle = esEllipsis
          Actions = [pftEditStyle, pftFont, pftValueFont]
          TypeNamesEmpty = True
          ParentClassNamesEmpty = True
          ParentPropNamesEmpty = True
          ParentTypeNamesEmpty = True
          PickListEmpty = True
        end>
    end
    object Chart1: TChart
      Left = 263
      Top = 4
      Width = 730
      Height = 358
      BackWall.Visible = False
      Legend.Visible = False
      MarginBottom = 0
      MarginLeft = 0
      MarginRight = 0
      MarginTop = 0
      Title.Text.Strings = (
        'TChart')
      Title.Visible = False
      BottomAxis.Axis.SmallSpace = 1
      ClipPoints = False
      Emboss.Color = clWhite
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMaximum = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.LabelsFormat.ShapeStyle = fosRoundRectangle
      LeftAxis.Maximum = 17000000.000000000000000000
      Shadow.Color = clWhite
      View3D = False
      View3DOptions.Orthogonal = False
      Zoom.Pen.Mode = pmNotXor
      Color = clWhite
      PopupMenu = pmPointFromMainSonde
      TabOrder = 1
      OnMouseDown = Chart1MouseDown
      DefaultCanvas = 'TGDIPlusCanvas'
      ColorPaletteIndex = 13
      object lblNumPointsForChart: TLabel
        Left = 640
        Top = 2
        Width = 9
        Height = 19
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Series1: TFastLineSeries
        LinePen.Color = 10708548
        LinePen.Width = 4
        LinePen.SmallSpace = 1
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
        object TeeFunction1: TAddTeeFunction
          CalcByValue = False
        end
      end
      object fstForChoicePoint: TFastLineSeries
        SeriesColor = clRed
        LinePen.Color = clRed
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series2: TFastLineSeries
        LinePen.Color = 10708548
        LinePen.Width = 4
        LinePen.SmallSpace = 1
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
        object TeeFunction2: TAddTeeFunction
          CalcByValue = False
        end
      end
    end
    object Chart2: TChart
      Left = 263
      Top = 368
      Width = 730
      Height = 309
      BackWall.Visible = False
      Legend.Visible = False
      MarginBottom = 0
      MarginLeft = 0
      MarginRight = 0
      MarginTop = 5
      Title.Text.Strings = (
        'TChart')
      Title.Visible = False
      BottomAxis.Axis.SmallSpace = 1
      ClipPoints = False
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMaximum = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.Maximum = 65535.000000000000000000
      LeftAxis.Minimum = -5000.000000000000000000
      View3D = False
      View3DOptions.Orthogonal = False
      Zoom.Pen.Mode = pmNotXor
      Color = clWhite
      PopupMenu = pmPointFromMagnSens
      TabOrder = 2
      OnMouseDown = Chart2MouseDown
      DefaultCanvas = 'TGDIPlusCanvas'
      ColorPaletteIndex = 13
      object lblNumPointsForChartMagnSens: TLabel
        Left = 648
        Top = 10
        Width = 9
        Height = 19
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object FastLineSeries1: TFastLineSeries
        LinePen.Color = 10708548
        LinePen.Width = 4
        LinePen.SmallSpace = 1
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
        object AddTeeFunction1: TAddTeeFunction
          CalcByValue = False
        end
      end
      object FastLineSeries2: TFastLineSeries
        LinePen.Color = 3513587
        LinePen.Width = 4
        LinePen.SmallSpace = 1
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries3: TFastLineSeries
        LinePen.Color = 1330417
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries4: TFastLineSeries
        LinePen.Color = 11048782
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries5: TFastLineSeries
        LinePen.Color = 7028779
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries6: TFastLineSeries
        LinePen.Color = 6519581
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries7: TFastLineSeries
        LinePen.Color = 919731
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries8: TFastLineSeries
        LinePen.Color = 6144242
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries9: TFastLineSeries
        LinePen.Color = 10401629
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries10: TFastLineSeries
        LinePen.Color = 7368816
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries11: TFastLineSeries
        LinePen.Color = 9300723
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries12: TFastLineSeries
        LinePen.Color = 11842740
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries13: TFastLineSeries
        LinePen.Color = 10708548
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries14: TFastLineSeries
        LinePen.Color = 3513587
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries15: TFastLineSeries
        LinePen.Color = 1330417
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object FastLineSeries16: TFastLineSeries
        LinePen.Color = 11048782
        LinePen.Width = 5
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object fstForChoicePointMagnSens: TFastLineSeries
        SeriesColor = clRed
        LinePen.Color = clRed
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
  end
  object TimerForControlEvent: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = TimerForControlEventTimer
    Left = 400
    Top = 232
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = Timer2Timer
    Left = 321
    Top = 208
  end
  object pmPointFromMainSonde: TPopupMenu
    Images = ImageList1
    Left = 120
    Top = 592
    object N11: TMenuItem
      Caption = 'N1'
      SubMenuImages = ImageList1
      ImageIndex = 4
      OnClick = N11Click
    end
    object N21: TMenuItem
      Caption = 'N2'
      ImageIndex = 3
      OnClick = N21Click
    end
  end
  object ImageList1: TImageList
    Left = 305
    Top = 456
    Bitmap = {
      494C010105000800C00010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00
      00FFFF0000FFFF0000FFFF0000FFFF0000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF000000002929290079777900A8A5A50096949400525151000C0B0B000000
      0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000
      0000000000002929293679777998A8A5A5CD969494BA525151690C0B0B0F0000
      000000000000000000000000000000000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFFFFFFFFFFFFFFFFF000000003D3C
      3C00E9E7E600D6D5DC009C9CCA008E8FCA009C9CC900AEAEBD00C6C2C1008E8B
      8D000202020000000000FFFFFFFFFFFFFFFF0000000000000000000000003D3C
      3C4FE9E7E6FDA7C9B2FF5CB37BFF65C580FF6AC784FF6FB384FFBCC1B9FF8E8B
      8DB702020203000000000000000000000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFFFFFFFFF000000007A777A00E2E2
      E0003F3FCA003E3ED8004949D7005C5CDC007575E0008C8CE7009A9AED009C9C
      BA00B9B5B6000F0F0F0000000000FFFFFFFF00000000000000007A777A9ECCDB
      CDFF40BA68FF3CD15BFF3ED15CFF51D56BFF6BDA83FF86E29BFF94E6A7FF6AB4
      83FFB9B5B6F20F0F0F130000000000000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFFFFFFFFF6D6B6C00C7C6CE001D1D
      B9002727AF002929B9002B2BC9003737D4004B4BD8005E5EDD007272E1008080
      E4008686CB00B5B1B00003030300FFFFFFFF000000006D6B6C8CA1BDACFF25B4
      41FF17862EFF1A8830FF1F9D39FF25BA45FF36CE58FF51D46EFF65D97EFF72DD
      89FF66C087FFB5B1B0F00303030400000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0E0E0E00E2DFD7001B1BB3002626
      AC002626AB002828B4002A2ABD002D2DCC003636D4004242D6004B4BD8005959
      DB006A6ADF009191BF0089868700000000000E0E0E12E0DFD6FF209F38FF1365
      25FF166327FF19702CFF1D8534FF239E40FF27B549FF2BC84DFF37D058FF47D1
      65FF53D46DFF5CB17CFF898687B300000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF908E8F005959B1002C2CC6002929
      B7002828B5002929B8002A2ABB002B2BC3002D2DCB002F2FD0003232D3003535
      D3004646D7005858DF00C4BFB9000B0B0B00908E8FB730965DFF16772BFF1875
      2CFF19732DFF1C7C31FF1F8537FF22933CFF259F41FF29AD47FF27B347FF25B9
      46FF2BCA4CFF4ED269FFADBAA7FE0B0B0B0E008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFD3CECA005151D5003535D3002C2C
      CB002A2AC2002A2AC0002A2ABF002A2AC0002A2AC0002B2BC0002B2BC0002B2B
      C0002C2CC8004040D6009A99BE00504F4F00D3CECAFC2BBF49FF1FA73BFF2094
      3BFF1E8937FF1F8937FF208A39FF208E39FF21913CFF22943DFF22963DFF2091
      3AFF21A23BFF23C042FF57B074FF504F4F66008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFC4C1C0008383E8006C6CDF003C3C
      D4003535D3002D2DCF002C2CC9002B2BC2002A2ABC002929BA002828B2002626
      AC002626AF002D2DCE006161C20093909000C4C1C0FF5FD878FF4CD86AFF25B4
      46FF26A945FF249D40FF22973DFF21903BFF1F8C38FF1F8637FF1E7F33FF1B74
      2FFF197C2FFF1B9A35FF35BD54FF939090B8008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFBAB6B700A4A4EF008F8FE6006E6E
      DF004B4BD7004040D4003434D2002D2DCC002A2AC0002929B8002626AC002424
      A2002424A0002A2ABF004C4CBE00A6A3A200BAB6B7FF87E49BFF78DE8FFF5EDC
      7BFF2AC74DFF2BBB4BFF27A845FF259C3FFF208F3AFF1E8436FF1B752FFF1662
      27FF156426FF17822DFF27B041FFA6A3A2CD008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFC2BEBD00B9B9F400A8A8EC009696
      E8007575E1005454DA004747D7003939D3002C2CCD002929BD002626B0002424
      A10023239E002A2ABB006B6AB60075727300C2BEBDFF98E6ABFF96E6A9FF83E2
      98FF68DD84FF2FD156FF2DC450FF29B048FF249C40FF208939FF1B742FFF155F
      26FF145F24FF17772AFF2AA74CFF75727393008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFC0BBBB00B8B8E400BBBBEF00ABAB
      ED009E9EE9008787E5005858DB004B4BD7003B3BD4002E2ECE002929BC002626
      AC002828B4002828C500BAB8C30029282800C0BBBBF47CDC92FFA9EAB6FF9EE8
      AEFF8FE5A2FF7AE191FF40D662FF2BC84FFF28B348FF249D40FF1E8435FF176C
      2BFF19782DFF177B2BFF67B079FF29282834008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF4E4D4D00A7A5AF00CCCCF600BEBE
      F100B2B2EE00A4A4EA009797E8007C7CE2005757DA003A3AD4002B2BCC002929
      C3002E2ED0002525BD00DEDCD600000000004E4D4D636DB47DFFB9EEC6FFAEEC
      BDFFA6EBB5FF96E7A9FF88E49DFF69DD83FF3DD15FFF29B549FF20973BFF1C8D
      34FF1C9033FF1C9637FFDCDBD3F300000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFFFFFFFFFC1BCBC00B5B5D200CDCD
      F500C1C1F100B8B8F000A8A8ED009999E9008484E4007070DF005F5FDC005959
      DB004747DC00D5D5D7003A383900FFFFFFFF00000000C1BCBCFA7AD790FFBEF0
      C9FFB4ECC1FFA9EBB7FF9AE7ABFF87E39CFF6EDD87FF51D76FFF3AD25AFF2FCD
      4EFF21B93EFF90C29BFF3A38394A00000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFFFFFFFFF0B0B0B00BDB9B700B5B5
      D100D2D2F900C6C6F200BCBCEF00B0B0ED00A2A2EB009595E8008787E5007272
      E200BDBCC6007978780000000000FFFFFFFF000000000B0B0B0EBDB9B7FF7DD9
      93FFC0F0CAFFB5ECC2FFABEBB8FF9EE8AFFF8EE5A0FF7ADE91FF61D67AFF4DD2
      67FF6EB380FF797878990000000000000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFFFFFFFFFFFFFFFFF0A0A0A00BEBA
      B900A19FA600BFBFE200CBCBF800C2C2F500B9B9F300A8A9EC00A2A2D100DDDB
      D6006C6A6A0000000000FFFFFFFFFFFFFFFF00000000000000000A0A0A0DBEBA
      B9F661B373FF8CE09EFFB3ECC0FFAFEDBCFFA2E9B2FF8DE3A0FF58CB74FFBBD3
      BAFF6C6A6A89000000000000000000000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFFFFFFFF00FFFFFFFFFFFFFFFFFFFF
      FFFF4C4B4B00C1BDBC00C1BEBD00BAB6B700C7C4C400CDCAC7008C8A8A000E0D
      0D00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000
      00004C4B4B62C1BDBCF3C1BEBDFFBAB6B7FFC7C4C4FFCDCAC7F98C8A8AB10E0D
      0D1200000000000000000000000000000000008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF008000FF008000FF008000FF0080
      00FF008000FF008000FF008000FF008000FF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F00F000000000000C00300000000
      0000800100000000000080010000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008001000000000000800100000000
      0000C003000000000000F00F0000000000000000000000000000000000000000
      000000000000}
  end
  object pmPointFromMagnSens: TPopupMenu
    Left = 544
    Top = 536
    object Vs_Sin: TMenuItem
      Caption = 'Vs_Sin'
      OnClick = Vs_SinClick
    end
    object Vs_Cos: TMenuItem
      Caption = 'Vs_Cos'
      Checked = True
      OnClick = Vs_CosClick
    end
  end
end
