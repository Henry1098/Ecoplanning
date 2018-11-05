object FDformT: TFDformT
  Left = 429
  Top = 240
  Width = 282
  Height = 197
  Caption = 'Formats Trimestre'
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
    Width = 112
    Height = 13
    Caption = 'Formats pour Trimestres'
  end
  object ComboBox1: TComboBox
    Left = 16
    Top = 32
    Width = 145
    Height = 113
    Style = csSimple
    ItemHeight = 13
    TabOrder = 0
    Items.Strings = (
      'Tri 1 05'
      'Tri 1'
      'T1 05'
      '1T 05'
      '1, 2...'
      'Aucun')
  end
  object btOK: TButton
    Left = 184
    Top = 32
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
  end
  object btAnnul: TButton
    Left = 184
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
  end
  object btAide: TButton
    Left = 184
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
  end
end
