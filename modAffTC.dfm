object AffData: TAffData
  Left = 410
  Top = 76
  Width = 446
  Height = 377
  Caption = 'Affecter Données aux Taches Cochées'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 110
    Height = 13
    Caption = 'Sélectionner un Champ'
  end
  object Label2: TLabel
    Left = 16
    Top = 216
    Width = 30
    Height = 13
    Caption = 'Valeur'
  end
  object Label3: TLabel
    Left = 216
    Top = 8
    Width = 101
    Height = 13
    Caption = 'Champ Sélectionné : '
  end
  object lChamp: TLabel
    Left = 216
    Top = 32
    Width = 71
    Height = 13
    Caption = '__________'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 248
    Top = 64
    Width = 108
    Height = 13
    Caption = 'Affecter une valeur de '
  end
  object Label5: TLabel
    Left = 240
    Top = 80
    Width = 115
    Height = 13
    Caption = 'Critères ou Sous-Critères'
  end
  object eVal: TEdit
    Left = 16
    Top = 240
    Width = 169
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 192
    Top = 296
    Width = 75
    Height = 25
    Caption = 'Exécuter'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 272
    Top = 296
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 352
    Top = 296
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
    OnClick = Button3Click
  end
  object ListBox1: TListBox
    Left = 16
    Top = 24
    Width = 169
    Height = 161
    ItemHeight = 13
    TabOrder = 4
    OnClick = ListBox1Click
  end
  object ListBox2: TListBox
    Left = 208
    Top = 96
    Width = 217
    Height = 177
    ItemHeight = 13
    TabOrder = 5
    OnClick = ListBox2Click
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 302
    Width = 153
    Height = 17
    Caption = 'Décocher après traitement'
    TabOrder = 6
  end
end
