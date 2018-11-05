object FDEpaisseur: TFDEpaisseur
  Left = 547
  Top = 307
  Width = 345
  Height = 238
  Caption = 'Epaisseur Trait'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 72
    Top = 16
    Width = 96
    Height = 13
    Caption = 'Epaisseur en mm'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object btOK: TButton
    Left = 240
    Top = 16
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = btOKClick
  end
  object btAnnul: TButton
    Left = 240
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 1
    OnClick = btAnnulClick
  end
  object btAide: TButton
    Left = 240
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 2
    OnClick = btAideClick
  end
  object cbE: TComboBox
    Left = 48
    Top = 40
    Width = 145
    Height = 145
    Style = csSimple
    ItemHeight = 13
    TabOrder = 3
    Items.Strings = (
      '0.10'
      '0.20'
      '0.50'
      '0.80'
      '1.00'
      '1.50'
      '2.00'
      '2.50'
      '3.00'
      '4.00'
      '5.00')
  end
end
