object fCalendar: TfCalendar
  Left = 378
  Top = 174
  Width = 516
  Height = 638
  Caption = 'Calendriers'
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
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 16
    Width = 151
    Height = 13
    Caption = 'Selectionner un Calendrier'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lMonth: TLabel
    Left = 240
    Top = 16
    Width = 82
    Height = 13
    Caption = 'Mois En Cours'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 512
    Width = 61
    Height = 13
    Caption = 'Commentaire'
  end
  object lbCal: TListBox
    Left = 240
    Top = 40
    Width = 201
    Height = 441
    ItemHeight = 13
    TabOrder = 0
    TabWidth = 8
    OnDblClick = lbCalDblClick
  end
  object GroupBox1: TGroupBox
    Left = 56
    Top = 208
    Width = 121
    Height = 145
    Caption = 'Week-End'
    TabOrder = 1
    object cb1: TCheckBox
      Left = 16
      Top = 16
      Width = 97
      Height = 17
      Caption = 'Lundi'
      TabOrder = 0
    end
    object cb2: TCheckBox
      Left = 16
      Top = 32
      Width = 97
      Height = 17
      Caption = 'Mardi'
      TabOrder = 1
    end
    object cb3: TCheckBox
      Left = 16
      Top = 48
      Width = 97
      Height = 17
      Caption = 'Mercredi'
      TabOrder = 2
    end
    object cb4: TCheckBox
      Left = 16
      Top = 64
      Width = 97
      Height = 17
      Caption = 'Jeudi'
      TabOrder = 3
    end
    object cb5: TCheckBox
      Left = 16
      Top = 80
      Width = 97
      Height = 17
      Caption = 'Vendredi'
      TabOrder = 4
    end
    object cb6: TCheckBox
      Left = 16
      Top = 96
      Width = 97
      Height = 17
      Caption = 'Samedi'
      TabOrder = 5
    end
    object cb7: TCheckBox
      Left = 16
      Top = 112
      Width = 97
      Height = 17
      Caption = 'Dimanche'
      TabOrder = 6
    end
  end
  object BitBtn1: TBitBtn
    Left = 16
    Top = 176
    Width = 105
    Height = 25
    Caption = 'Année Précédente'
    TabOrder = 2
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 16
    Top = 144
    Width = 105
    Height = 25
    Caption = 'Mois Précédent'
    TabOrder = 3
    OnClick = BitBtn2Click
  end
  object BitBtn3: TBitBtn
    Left = 120
    Top = 144
    Width = 105
    Height = 25
    Caption = 'Mois Suivant'
    TabOrder = 4
    OnClick = BitBtn3Click
  end
  object BitBtn4: TBitBtn
    Left = 120
    Top = 176
    Width = 105
    Height = 25
    Caption = 'Année Suivante'
    TabOrder = 5
    OnClick = BitBtn4Click
  end
  object ComboBox1: TComboBox
    Left = 56
    Top = 40
    Width = 137
    Height = 97
    Style = csSimple
    ItemHeight = 13
    TabOrder = 6
    OnClick = ComboBox1Click
    Items.Strings = (
      'Standard'
      'Semaines Continues'
      'Calendrier 3'
      'Calendrier 4'
      'Calendrier 5')
  end
  object Button1: TButton
    Left = 40
    Top = 384
    Width = 153
    Height = 25
    Caption = 'Générer Nouveau Week-End'
    TabOrder = 7
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 48
    Top = 416
    Width = 129
    Height = 25
    Caption = 'Sauver et Quitter'
    TabOrder = 8
    OnClick = Button2Click
  end
  object mComment: TMemo
    Left = 24
    Top = 528
    Width = 465
    Height = 65
    TabOrder = 9
  end
  object btAide: TButton
    Left = 48
    Top = 448
    Width = 129
    Height = 25
    Caption = 'Annuler'
    TabOrder = 10
    OnClick = btAideClick
  end
  object Button4: TButton
    Left = 48
    Top = 480
    Width = 129
    Height = 25
    Caption = 'Aide'
    TabOrder = 11
    OnClick = Button4Click
  end
end
