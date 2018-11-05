object DOC: TDOC
  Left = 192
  Top = 124
  Width = 889
  Height = 656
  Caption = 'Documentation'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 32
    Top = 8
    Width = 97
    Height = 25
    Caption = 'Fermer Fenetre'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 152
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Imprimer'
    TabOrder = 1
    OnClick = Button2Click
  end
  object CppWebBrowser1: TCppWebBrowser
    Left = 40
    Top = 56
    Width = 809
    Height = 545
    TabStop = True
    TabOrder = 2
    ControlData = {
      4C0000009D530000543800000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
end
