object AffSucc: TAffSucc
  Left = 391
  Top = 203
  Width = 360
  Height = 257
  Caption = 'Lier une Tache à des Successeurs'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 232
    Top = 16
    Width = 46
    Height = 13
    Caption = 'Décalage'
  end
  object Label2: TLabel
    Left = 16
    Top = 24
    Width = 86
    Height = 13
    Caption = 'Numéro de Tache'
  end
  object Button1: TButton
    Left = 224
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Executer'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 120
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 224
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 216
    Top = 48
    Width = 81
    Height = 21
    TabOrder = 3
    Text = '0'
  end
  object RadioGroup1: TRadioGroup
    Left = 24
    Top = 72
    Width = 129
    Height = 137
    Caption = 'Liens'
    TabOrder = 4
  end
  object rb1: TRadioButton
    Left = 32
    Top = 96
    Width = 113
    Height = 17
    Caption = 'Fin - Début'
    Checked = True
    TabOrder = 5
    TabStop = True
  end
  object rb2: TRadioButton
    Left = 32
    Top = 136
    Width = 113
    Height = 17
    Caption = 'Fin - Fin'
    TabOrder = 6
  end
  object rb3: TRadioButton
    Left = 32
    Top = 176
    Width = 113
    Height = 17
    Caption = 'Début - Début'
    TabOrder = 7
  end
  object Edit2: TEdit
    Left = 120
    Top = 16
    Width = 49
    Height = 21
    TabOrder = 8
  end
end
