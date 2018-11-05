object Hauteur: THauteur
  Left = 425
  Top = 293
  Width = 298
  Height = 148
  Caption = 'Hauteur Ligne'
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
    Left = 56
    Top = 8
    Width = 30
    Height = 13
    Caption = 'Valeur'
  end
  object Edit1: TEdit
    Left = 56
    Top = 32
    Width = 113
    Height = 21
    TabOrder = 0
  end
  object btOK: TButton
    Left = 32
    Top = 72
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = btOKClick
  end
  object btAnnul: TButton
    Left = 120
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
    OnClick = btAnnulClick
  end
end
