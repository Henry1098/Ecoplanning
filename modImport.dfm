object Import: TImport
  Left = 370
  Top = 321
  Width = 404
  Height = 234
  Caption = 'Import Données'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Button2: TButton
    Left = 304
    Top = 16
    Width = 81
    Height = 25
    Caption = 'Quitter'
    TabOrder = 0
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 312
    Top = 56
    Width = 73
    Height = 25
    Caption = 'Aide'
    TabOrder = 1
  end
  object Button4: TButton
    Left = 72
    Top = 16
    Width = 113
    Height = 25
    Caption = 'Plannings'
    TabOrder = 2
    OnClick = Button4Click
  end
  object Button1: TButton
    Left = 72
    Top = 64
    Width = 113
    Height = 25
    Caption = 'Tris'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button5: TButton
    Left = 72
    Top = 112
    Width = 113
    Height = 25
    Caption = 'Filtres'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 72
    Top = 160
    Width = 113
    Height = 25
    Caption = 'Colonnes'
    TabOrder = 5
    OnClick = Button6Click
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Plannings|*.pln|Tris|*.tri|Filtres|*.fil|Colonnes|*.col'
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofEnableSizing]
    Left = 8
  end
end
