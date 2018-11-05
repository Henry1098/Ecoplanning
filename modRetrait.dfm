object Retrait: TRetrait
  Left = 343
  Top = 291
  BorderStyle = bsNone
  Caption = ' Retrait Horizontal'
  ClientHeight = 131
  ClientWidth = 227
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 56
    Top = 8
    Width = 81
    Height = 13
    Caption = 'Retrait Horizontal'
  end
  object Edit1: TEdit
    Left = 32
    Top = 32
    Width = 129
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 16
    Top = 80
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 104
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
    OnClick = Button2Click
  end
end
