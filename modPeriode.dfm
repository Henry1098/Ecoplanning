object Period: TPeriod
  Left = 192
  Top = 122
  Width = 466
  Height = 234
  Caption = 'Choisir une Période du Projet'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 88
    Top = 152
    Width = 275
    Height = 13
    Caption = 'Au prélable, ivous devrez filtrer les tâches de cette période'
  end
  object Label2: TLabel
    Left = 24
    Top = 32
    Width = 131
    Height = 13
    Caption = 'Date de Début (JJ/MM/AA)'
  end
  object Label3: TLabel
    Left = 24
    Top = 72
    Width = 116
    Height = 13
    Caption = 'Date de Fin (JJ/MM/AA)'
  end
  object Button1: TButton
    Left = 336
    Top = 32
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 336
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 184
    Top = 32
    Width = 105
    Height = 21
    TabOrder = 2
    Text = '../../..'
  end
  object Edit2: TEdit
    Left = 184
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '../../..'
  end
end
