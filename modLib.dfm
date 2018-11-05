object Libel: TLibel
  Left = 499
  Top = 296
  Width = 365
  Height = 156
  Caption = 'Libellé Texte'
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
    Left = 16
    Top = 16
    Width = 30
    Height = 13
    Caption = 'Valeur'
  end
  object Edit1: TEdit
    Left = 16
    Top = 40
    Width = 321
    Height = 21
    TabOrder = 0
  end
  object btOK: TButton
    Left = 88
    Top = 80
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = btOKClick
  end
  object btAnnul: TButton
    Left = 184
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
    OnClick = btAnnulClick
  end
end
