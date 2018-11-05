object FDDistH: TFDDistH
  Left = 192
  Top = 140
  Width = 311
  Height = 227
  Caption = 'Distance Horizontale entre Tâches'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 32
    Width = 42
    Height = 13
    Caption = 'Distance'
  end
  object Edit1: TEdit
    Left = 80
    Top = 32
    Width = 49
    Height = 21
    TabOrder = 0
    Text = '40'
  end
  object Button1: TButton
    Left = 184
    Top = 32
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 184
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 184
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
    OnClick = Button3Click
  end
end
