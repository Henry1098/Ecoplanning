object FDformSem: TFDformSem
  Left = 349
  Top = 227
  Width = 303
  Height = 213
  Caption = 'Format / Semaine'
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
    Left = 24
    Top = 8
    Width = 126
    Height = 13
    Caption = 'Format Semaine Calendrier'
  end
  object ComboBox1: TComboBox
    Left = 24
    Top = 32
    Width = 145
    Height = 137
    Style = csSimple
    ItemHeight = 13
    TabOrder = 0
    Items.Strings = (
      '31 Janvier 2005'
      '31 Jan 05'
      '31 Janvier'
      '31 Jan'
      '31 J'
      '31/1/05'
      '31/1'
      'Aucun')
  end
  object btOK: TButton
    Left = 200
    Top = 48
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
  end
  object btAnnul: TButton
    Left = 200
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
  end
  object btAide: TButton
    Left = 200
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
  end
end
