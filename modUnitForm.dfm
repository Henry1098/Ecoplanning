object FDUnitForm: TFDUnitForm
  Left = 192
  Top = 114
  Width = 298
  Height = 399
  Caption = 'Unité / Format'
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
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 25
    Height = 13
    Caption = 'Unité'
  end
  object Label2: TLabel
    Left = 24
    Top = 144
    Width = 32
    Height = 13
    Caption = 'Format'
  end
  object cbUnit: TComboBox
    Left = 24
    Top = 40
    Width = 145
    Height = 97
    Style = csSimple
    ItemHeight = 13
    TabOrder = 0
    OnClick = cbUnitClick
    Items.Strings = (
      'Jour'
      'Semaine'
      'Mois'
      'Trimestre'
      'Année')
  end
  object cbForm: TComboBox
    Left = 24
    Top = 168
    Width = 145
    Height = 169
    Style = csSimple
    ItemHeight = 13
    TabOrder = 1
    OnClick = cbFormClick
  end
  object btOK: TButton
    Left = 184
    Top = 72
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = btOKClick
  end
  object btAnnul: TButton
    Left = 184
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 3
    OnClick = btAnnulClick
  end
  object btAide: TButton
    Left = 184
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 4
    OnClick = btAideClick
  end
end
