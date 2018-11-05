object Choix: TChoix
  Left = 485
  Top = 294
  Width = 243
  Height = 227
  Caption = 'Filtres Tâches'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 40
    Top = 16
    Width = 161
    Height = 25
    Caption = 'Utiliser Filtres Mémorisés'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 48
    Width = 161
    Height = 25
    Caption = 'Compléter-Créer Nouveau Filtre'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button4: TButton
    Left = 40
    Top = 136
    Width = 161
    Height = 25
    Caption = 'Aide'
    TabOrder = 2
  end
  object Button5: TButton
    Left = 40
    Top = 104
    Width = 161
    Height = 25
    Caption = 'OK'
    TabOrder = 3
    OnClick = Button5Click
  end
end
