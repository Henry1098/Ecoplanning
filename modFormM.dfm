object FDformM: TFDformM
  Left = 192
  Top = 114
  Width = 293
  Height = 210
  Caption = 'Formats / Mois'
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
    Left = 8
    Top = 8
    Width = 112
    Height = 13
    Caption = 'Formats Mois Calendrier'
  end
  object ComboBox1: TComboBox
    Left = 16
    Top = 32
    Width = 145
    Height = 137
    Style = csSimple
    ItemHeight = 13
    TabOrder = 0
    Items.Strings = (
      'Janvier 2005'
      'Jan 96'
      'Jan'
      'J 96'
      'J'
      '1,2...'
      'Mois 1, Mois 2'
      'Aucun')
  end
  object btOK: TButton
    Left = 192
    Top = 40
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
  end
  object btAnnul: TButton
    Left = 192
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
  end
  object btAide: TButton
    Left = 192
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
  end
end
