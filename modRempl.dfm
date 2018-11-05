object RemplTC: TRemplTC
  Left = 414
  Top = 351
  Width = 340
  Height = 239
  Caption = 'Remplacer Données  Désignation Tâches'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 137
    Height = 13
    Caption = 'Champ : Désignation Tâches'
  end
  object Label2: TLabel
    Left = 24
    Top = 56
    Width = 51
    Height = 13
    Caption = 'Remplacer'
  end
  object Label3: TLabel
    Left = 24
    Top = 120
    Width = 16
    Height = 13
    Caption = 'Par'
  end
  object eMask: TEdit
    Left = 24
    Top = 80
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '*'
  end
  object eMot: TEdit
    Left = 24
    Top = 144
    Width = 161
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 224
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Remplacer'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 224
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 4
    OnClick = Button3Click
  end
end
