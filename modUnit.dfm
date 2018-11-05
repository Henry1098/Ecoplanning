object FDunit: TFDunit
  Left = 303
  Top = 226
  Width = 295
  Height = 180
  Caption = 'Unités Calendrier'
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
    Left = 32
    Top = 8
    Width = 80
    Height = 13
    Caption = 'Unités Calendrier'
  end
  object ComboBox1: TComboBox
    Left = 32
    Top = 32
    Width = 145
    Height = 97
    Style = csSimple
    ItemHeight = 13
    TabOrder = 0
    Items.Strings = (
      'Jour'
      'Semaine'
      'Mois'
      'Trimestre'
      'Année')
  end
  object btOK: TButton
    Left = 200
    Top = 24
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
  end
  object btAnnul: TButton
    Left = 200
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
  end
  object btAide: TButton
    Left = 200
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
  end
end
