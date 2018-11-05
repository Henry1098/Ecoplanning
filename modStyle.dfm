object FDStyle: TFDStyle
  Left = 527
  Top = 300
  Width = 288
  Height = 198
  Caption = 'Styles'
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
  object Button1: TButton
    Left = 168
    Top = 16
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 168
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 168
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 2
    OnClick = Button3Click
  end
  object cbStyle: TComboBox
    Left = 32
    Top = 24
    Width = 97
    Height = 105
    Style = csSimple
    ItemHeight = 13
    TabOrder = 3
    Items.Strings = (
      '___________'
      '_  _  _  _  _  _'
      '. . . . . . . . . . . '
      '_ . _ . _ . _ . _'
      '_ .. _ .. _ .. _ ..')
  end
end
