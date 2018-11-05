object NewTask: TNewTask
  Left = 434
  Top = 357
  Width = 413
  Height = 305
  Caption = 'Nouvelle tâche en fin de liste'
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
    Left = 32
    Top = 24
    Width = 96
    Height = 13
    Caption = 'Tache Numéro : '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 32
    Top = 56
    Width = 86
    Height = 13
    Caption = 'Libéllé de la tâche'
  end
  object Label3: TLabel
    Left = 32
    Top = 120
    Width = 90
    Height = 13
    Caption = 'Durée prévisionelle'
  end
  object Label4: TLabel
    Left = 88
    Top = 152
    Width = 31
    Height = 13
    Caption = 'Jour(s)'
  end
  object Edit1: TEdit
    Left = 32
    Top = 80
    Width = 249
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 32
    Top = 144
    Width = 33
    Height = 21
    TabOrder = 1
    Text = '1'
  end
  object Button1: TButton
    Left = 24
    Top = 200
    Width = 75
    Height = 25
    Caption = 'Valider'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 128
    Top = 200
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 232
    Top = 200
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 4
  end
  object Edit3: TEdit
    Left = 144
    Top = 24
    Width = 49
    Height = 21
    TabOrder = 5
  end
end
