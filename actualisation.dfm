object Actual: TActual
  Left = 357
  Top = 240
  Width = 554
  Height = 359
  Caption = 'Actualisation'
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 129
    Height = 13
    Caption = ' Actualisations Enregistrées'
  end
  object Label2: TLabel
    Left = 264
    Top = 192
    Width = 151
    Height = 13
    Caption = 'Date Actualisation Sélectionnée'
  end
  object Label3: TLabel
    Left = 48
    Top = 192
    Width = 90
    Height = 13
    Caption = 'Fichier Sélectionné'
  end
  object ListBox1: TListBox
    Left = 8
    Top = 24
    Width = 217
    Height = 161
    ItemHeight = 13
    Sorted = True
    TabOrder = 0
    OnClick = ListBox1Click
  end
  object MonthCalendar1: TMonthCalendar
    Left = 240
    Top = 24
    Width = 197
    Height = 154
    Date = 38412
    ShowTodayCircle = False
    TabOrder = 1
    OnClick = MonthCalendar1Click
  end
  object Edit1: TEdit
    Left = 296
    Top = 216
    Width = 97
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 24
    Top = 248
    Width = 185
    Height = 25
    Caption = 'Rappeller une Actualisation'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 456
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 456
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 5
  end
  object eFile: TEdit
    Left = 8
    Top = 216
    Width = 217
    Height = 21
    TabOrder = 6
  end
  object Button4: TButton
    Left = 264
    Top = 248
    Width = 169
    Height = 25
    Caption = 'Créer Nouvelle Actualisation'
    TabOrder = 7
    OnClick = Button4Click
  end
  object btEff: TButton
    Left = 24
    Top = 288
    Width = 185
    Height = 25
    Caption = 'Effacer Dernière Actualisation'
    TabOrder = 8
    OnClick = btEffClick
  end
  object Button5: TButton
    Left = 456
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Quitter'
    TabOrder = 9
    OnClick = Button5Click
  end
end
