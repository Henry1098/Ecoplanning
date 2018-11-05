object FDformA: TFDformA
  Left = 192
  Top = 114
  Width = 305
  Height = 167
  Caption = 'Formats Années'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 76
    Height = 13
    Caption = 'Formats Années'
  end
  object ComboBox1: TComboBox
    Left = 16
    Top = 32
    Width = 145
    Height = 73
    Style = csSimple
    ItemHeight = 13
    TabOrder = 0
    Items.Strings = (
      '2005'
      '05'
      'Aucun')
  end
  object btOK: TButton
    Left = 184
    Top = 24
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
  end
  object btAnnul: TButton
    Left = 184
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
  end
  object btAide: TButton
    Left = 184
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
  end
end
