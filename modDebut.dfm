object DateProjet: TDateProjet
  Left = 452
  Top = 270
  Width = 351
  Height = 331
  Caption = 'Date de Début du Projet'
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
    Left = 48
    Top = 200
    Width = 128
    Height = 13
    Caption = 'Date de Début Prévisonnel'
  end
  object MonthCalendar1: TMonthCalendar
    Left = 8
    Top = 24
    Width = 207
    Height = 154
    Date = 38639.4398215046
    ShowTodayCircle = False
    TabOrder = 0
    OnClick = MonthCalendar1Click
  end
  object eDebPrev: TEdit
    Left = 48
    Top = 224
    Width = 129
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 248
    Top = 48
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 248
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 248
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 4
    OnClick = Button3Click
  end
end
