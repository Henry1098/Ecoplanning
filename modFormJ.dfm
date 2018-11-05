object FDformJour: TFDformJour
  Left = 425
  Top = 267
  Width = 304
  Height = 229
  Caption = 'Format / Jour'
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
    Top = 16
    Width = 55
    Height = 13
    Caption = 'Format Jour'
  end
  object ComboBox1: TComboBox
    Left = 24
    Top = 40
    Width = 145
    Height = 129
    Style = csSimple
    ItemHeight = 13
    TabOrder = 0
    Items.Strings = (
      'Vendredi'
      'Ven'
      'V'
      '31/01/05'
      '31/01'
      '1,2...'
      'Jour1, Jour2 ...'
      'Aucun')
  end
  object bTOK: TButton
    Left = 200
    Top = 56
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
  end
  object btAnnul: TButton
    Left = 200
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
  end
  object btAide: TButton
    Left = 200
    Top = 120
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
  end
end
