object PrepPlanning: TPrepPlanning
  Left = 85
  Top = 222
  Width = 1382
  Height = 740
  Caption = 'Préparation Planning'
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
    Left = 24
    Top = 8
    Width = 186
    Height = 16
    Caption = 'Liste Plannings Mémorisés'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 520
    Top = 50
    Width = 37
    Height = 13
    Caption = 'Aucun'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    OnContextPopup = Label3ContextPopup
  end
  object Label5: TLabel
    Left = 520
    Top = 84
    Width = 37
    Height = 13
    Caption = 'Aucun'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    OnContextPopup = Label5ContextPopup
  end
  object Label7: TLabel
    Left = 520
    Top = 116
    Width = 37
    Height = 13
    Caption = 'Aucun'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    OnContextPopup = Label7ContextPopup
  end
  object Label8: TLabel
    Left = 368
    Top = 480
    Width = 118
    Height = 16
    Caption = 'Titre du Planning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 368
    Top = 528
    Width = 79
    Height = 13
    Caption = 'Commentaires'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label10: TLabel
    Left = 40
    Top = 288
    Width = 198
    Height = 16
    Caption = 'Paramétrage  page planning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label11: TLabel
    Left = 40
    Top = 416
    Width = 110
    Height = 13
    Caption = 'Caractéristiques tâches'
  end
  object Label12: TLabel
    Left = 40
    Top = 440
    Width = 78
    Height = 13
    Caption = 'Corps du graphe'
  end
  object Label13: TLabel
    Left = 40
    Top = 528
    Width = 79
    Height = 13
    Caption = 'Titre des bandes'
  end
  object Bevel2: TBevel
    Left = 16
    Top = 312
    Width = 281
    Height = 249
  end
  object Bevel3: TBevel
    Left = 336
    Top = 496
    Width = 545
    Height = 137
  end
  object Bevel5: TBevel
    Left = 344
    Top = 152
    Width = 193
    Height = 105
  end
  object Label15: TLabel
    Left = 288
    Top = 128
    Width = 51
    Height = 13
    Caption = 'Préseance'
    Visible = False
  end
  object Label16: TLabel
    Left = 712
    Top = 232
    Width = 52
    Height = 16
    Caption = 'Actions'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label22: TLabel
    Left = 344
    Top = 8
    Width = 108
    Height = 13
    Caption = 'Planning en Cours '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label23: TLabel
    Left = 504
    Top = 8
    Width = 37
    Height = 13
    Caption = 'Aucun'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label21: TLabel
    Left = 584
    Top = 144
    Width = 85
    Height = 16
    Caption = 'Informations'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 512
    Top = 40
    Width = 401
    Height = 97
  end
  object Bevel4: TBevel
    Left = 344
    Top = 40
    Width = 161
    Height = 105
  end
  object Label14: TLabel
    Left = 688
    Top = 376
    Width = 124
    Height = 13
    Caption = '(Pour un premier Planning)'
  end
  object Label17: TLabel
    Left = 40
    Top = 320
    Width = 76
    Height = 13
    Caption = 'Marge du Cadre'
  end
  object Label18: TLabel
    Left = 40
    Top = 344
    Width = 52
    Height = 13
    Caption = 'Trait Cadre'
  end
  object Label2: TLabel
    Left = 872
    Top = 216
    Width = 6
    Height = 13
    Caption = '0'
    Visible = False
  end
  object lbPlanning: TListBox
    Left = 8
    Top = 40
    Width = 273
    Height = 209
    ItemHeight = 13
    TabOrder = 0
    OnClick = lbPlanningClick
  end
  object Button1: TButton
    Left = 352
    Top = 80
    Width = 145
    Height = 25
    Caption = 'Filtre'
    TabOrder = 1
    OnClick = Button1Click
    OnContextPopup = Button1ContextPopup
  end
  object Button2: TButton
    Left = 352
    Top = 48
    Width = 145
    Height = 25
    Caption = 'Trier / Grouper'
    TabOrder = 2
    OnClick = Button2Click
    OnContextPopup = Button2ContextPopup
  end
  object Button3: TButton
    Left = 352
    Top = 112
    Width = 145
    Height = 25
    Caption = 'Colonnes Grille Gantt'
    TabOrder = 3
    OnClick = Button3Click
    OnContextPopup = Button3ContextPopup
  end
  object eMemoire: TEdit
    Left = 360
    Top = 504
    Width = 505
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
  end
  object mPlanning: TMemo
    Left = 360
    Top = 544
    Width = 505
    Height = 65
    TabOrder = 5
    OnKeyUp = mPlanningKeyUp
  end
  object Button6: TButton
    Left = 760
    Top = 264
    Width = 129
    Height = 25
    Caption = 'Mémoriser Planning'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 608
    Top = 416
    Width = 129
    Height = 21
    Caption = 'Annuler'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 768
    Top = 416
    Width = 121
    Height = 21
    Caption = 'Aide'
    TabOrder = 8
    OnClick = Button8Click
  end
  object GroupBox1: TGroupBox
    Left = 328
    Top = 336
    Width = 249
    Height = 81
    Caption = 'Type de Planning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    object rb1: TRadioButton
      Left = 8
      Top = 24
      Width = 145
      Height = 17
      Caption = 'Planning Prévisionnel'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = rb1Click
    end
    object rb2: TRadioButton
      Left = 8
      Top = 48
      Width = 161
      Height = 17
      Caption = 'Planning Prévisonnel et Réel'
      TabOrder = 1
      OnClick = rb2Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 352
    Top = 160
    Width = 177
    Height = 89
    Caption = 'Genre de Planning'
    TabOrder = 10
    object rb11: TRadioButton
      Left = 16
      Top = 24
      Width = 121
      Height = 17
      Caption = 'Planning Compressé'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = rb11Click
    end
    object rb12: TRadioButton
      Left = 16
      Top = 48
      Width = 113
      Height = 17
      Caption = 'Planning Gantt'
      TabOrder = 1
      OnClick = rb12Click
    end
  end
  object cb1: TCheckBox
    Left = 336
    Top = 424
    Width = 153
    Height = 17
    Caption = 'Lignes brisées Actualisation'
    TabOrder = 11
    OnClick = cb1Click
  end
  object cb2: TCheckBox
    Left = 336
    Top = 304
    Width = 129
    Height = 17
    Caption = 'Gant avec grille'
    TabOrder = 12
    OnClick = cb2Click
  end
  object cb4: TCheckBox
    Left = 40
    Top = 368
    Width = 97
    Height = 17
    Caption = 'En-tête'
    Checked = True
    State = cbChecked
    TabOrder = 13
    OnClick = cb4Click
  end
  object cb5: TCheckBox
    Left = 40
    Top = 392
    Width = 97
    Height = 17
    Caption = 'Calendrier Haut'
    Checked = True
    State = cbChecked
    TabOrder = 14
    OnClick = cb5Click
  end
  object cb6: TCheckBox
    Left = 40
    Top = 464
    Width = 97
    Height = 17
    Caption = 'Calendrier Bas'
    Checked = True
    State = cbChecked
    TabOrder = 15
    OnClick = cb6Click
  end
  object btEntete: TButton
    Left = 160
    Top = 368
    Width = 121
    Height = 17
    Caption = 'Description En-tête'
    TabOrder = 16
    OnClick = btEnteteClick
  end
  object btCal: TButton
    Left = 160
    Top = 392
    Width = 121
    Height = 17
    Caption = 'Description Calendrier'
    TabOrder = 17
    OnClick = btCalClick
  end
  object cb7: TCheckBox
    Left = 40
    Top = 496
    Width = 97
    Height = 17
    Caption = 'Pied de page'
    Checked = True
    State = cbChecked
    TabOrder = 18
    OnClick = cb7Click
  end
  object btTaches: TButton
    Left = 160
    Top = 416
    Width = 121
    Height = 17
    Caption = 'Description tâches'
    TabOrder = 19
    OnClick = btTachesClick
  end
  object btCorps: TButton
    Left = 160
    Top = 440
    Width = 121
    Height = 17
    Caption = 'Description corps'
    TabOrder = 20
    OnClick = btCorpsClick
  end
  object btPied: TButton
    Left = 160
    Top = 496
    Width = 121
    Height = 17
    Caption = 'Description pied de page'
    TabOrder = 21
    OnClick = btPiedClick
  end
  object btLignes: TButton
    Left = 160
    Top = 528
    Width = 121
    Height = 17
    Caption = 'Modifications'
    TabOrder = 22
    OnClick = btLignesClick
  end
  object btOK: TButton
    Left = 496
    Top = 440
    Width = 89
    Height = 21
    Caption = 'OK'
    TabOrder = 23
    Visible = False
    OnClick = btOKClick
  end
  object btCadre: TButton
    Left = 160
    Top = 344
    Width = 121
    Height = 17
    Caption = 'Description du cadre'
    TabOrder = 24
    OnClick = btCadreClick
  end
  object btM: TButton
    Left = 160
    Top = 320
    Width = 121
    Height = 17
    Caption = 'Description des marges'
    TabOrder = 25
    OnClick = btMClick
  end
  object Button9: TButton
    Left = 608
    Top = 264
    Width = 129
    Height = 25
    Caption = 'Créer Planning'
    TabOrder = 26
    OnClick = Button9Click
  end
  object BitBtn1: TBitBtn
    Left = 304
    Top = 144
    Width = 25
    Height = 25
    TabOrder = 27
    Visible = False
    OnClick = BitBtn1Click
    Glyph.Data = {
      72010000424D7201000000000000760000002800000015000000150000000100
      040000000000FC00000000000000000000001000000000000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
      8888888880008888888888888888888880008888888888888888888880008888
      8888888888888888800088888888888888888888800088888888888888888888
      8000866666666666666666668000886666666666666666688000888666666666
      6666668880008888666666666666688880008888866666666666888880008888
      8866666666688888800088888886666666888888800088888888666668888888
      8000888888888666888888888000888888888868888888888000888888888888
      8888888880008888888888888888888880008888888888888888888880008888
      88888888888888888000888888888888888888888000}
  end
  object BitBtn2: TBitBtn
    Left = 304
    Top = 176
    Width = 25
    Height = 25
    TabOrder = 28
    Visible = False
    OnClick = BitBtn2Click
    Glyph.Data = {
      72010000424D7201000000000000760000002800000015000000150000000100
      040000000000FC00000000000000000000001000000000000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
      8888888880008888888888888888888880008888888888888888888880008888
      8888888888888888800088888888888888888888800088888888886888888888
      8000888888888666888888888000888888886666688888888000888888866666
      6688888880008888886666666668888880008888866666666666888880008888
      6666666666666888800088866666666666666688800088666666666666666668
      8000866666666666666666668000888888888888888888888000888888888888
      8888888880008888888888888888888880008888888888888888888880008888
      88888888888888888000888888888888888888888000}
  end
  object btAppliquer: TButton
    Left = 768
    Top = 304
    Width = 121
    Height = 25
    Caption = 'Appliquer Planning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 29
    OnClick = btAppliquerClick
  end
  object btSuppr: TButton
    Left = 608
    Top = 304
    Width = 129
    Height = 25
    Caption = 'Supprimer Planning'
    TabOrder = 30
    OnClick = btSupprClick
  end
  object cbEbauche: TCheckBox
    Left = 696
    Top = 352
    Width = 121
    Height = 17
    Caption = 'Ebauche Planning'
    TabOrder = 31
    OnClick = cbEbaucheClick
  end
  object Button4: TButton
    Left = 8
    Top = 256
    Width = 113
    Height = 17
    Caption = 'Tri de la Liste'
    TabOrder = 32
    OnClick = Button4Click
  end
  object Memo1: TMemo
    Left = 544
    Top = 168
    Width = 185
    Height = 57
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Pour enregistrer un Planning, '
      'il faut que la désignation commence'
      ' obligatoirement par une lettre !!!')
    ParentFont = False
    TabOrder = 33
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 264
  end
end
