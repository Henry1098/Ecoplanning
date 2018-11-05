object PrepRapport: TPrepRapport
  Left = 474
  Top = 140
  Width = 679
  Height = 577
  Caption = 'Préparation Rapport'
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
    Top = 8
    Width = 182
    Height = 16
    Caption = 'Liste Rapports Mémorisés'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 256
    Top = 80
    Width = 53
    Height = 13
    Caption = 'Filtre Utilisé'
  end
  object Label3: TLabel
    Left = 336
    Top = 48
    Width = 39
    Height = 13
    Caption = 'Label3'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 248
    Top = 48
    Width = 62
    Height = 13
    Caption = 'Trier Grouper'
  end
  object Label5: TLabel
    Left = 336
    Top = 80
    Width = 39
    Height = 13
    Caption = 'Label5'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 240
    Top = 112
    Width = 85
    Height = 13
    Caption = 'Colonnes Rapport'
  end
  object Label7: TLabel
    Left = 336
    Top = 112
    Width = 39
    Height = 13
    Caption = 'Label7'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 344
    Top = 304
    Width = 114
    Height = 16
    Caption = 'Titre du Rapport'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 344
    Top = 352
    Width = 66
    Height = 13
    Caption = 'Commentaires'
  end
  object Label11: TLabel
    Left = 536
    Top = 8
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
  object Bevel1: TBevel
    Left = 232
    Top = 32
    Width = 241
    Height = 113
  end
  object Label15: TLabel
    Left = 176
    Top = 112
    Width = 51
    Height = 13
    Caption = 'Préseance'
  end
  object Label12: TLabel
    Left = 296
    Top = 8
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
  object Label13: TLabel
    Left = 240
    Top = 160
    Width = 83
    Height = 13
    Caption = 'Rapport en Cours'
  end
  object Label23: TLabel
    Left = 336
    Top = 160
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
  object Bevel2: TBevel
    Left = 488
    Top = 32
    Width = 169
    Height = 113
  end
  object Label14: TLabel
    Left = 24
    Top = 264
    Width = 151
    Height = 16
    Caption = 'Paramétrage Rapport'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label16: TLabel
    Left = 24
    Top = 472
    Width = 47
    Height = 13
    Caption = 'Colonnes '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label17: TLabel
    Left = 24
    Top = 500
    Width = 109
    Height = 13
    Caption = 'Regroupement Bandes'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Bevel3: TBevel
    Left = 336
    Top = 296
    Width = 321
    Height = 201
  end
  object Bevel5: TBevel
    Left = 8
    Top = 280
    Width = 297
    Height = 153
  end
  object Bevel6: TBevel
    Left = 8
    Top = 448
    Width = 297
    Height = 81
  end
  object lbRapport: TListBox
    Left = 16
    Top = 40
    Width = 153
    Height = 209
    ItemHeight = 13
    TabOrder = 0
    OnClick = lbRapportClick
  end
  object Button1: TButton
    Left = 504
    Top = 72
    Width = 145
    Height = 25
    Caption = 'Filtre'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 504
    Top = 40
    Width = 145
    Height = 25
    Caption = 'Trier / Grouper'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 504
    Top = 104
    Width = 145
    Height = 25
    Caption = 'Colonnes Rapport'
    TabOrder = 3
    OnClick = Button3Click
  end
  object eMemoire: TEdit
    Left = 344
    Top = 328
    Width = 257
    Height = 21
    TabOrder = 4
  end
  object mRapport: TMemo
    Left = 344
    Top = 368
    Width = 297
    Height = 121
    TabOrder = 5
    OnChange = mRapportChange
  end
  object Button6: TButton
    Left = 504
    Top = 232
    Width = 145
    Height = 25
    Caption = 'Mémoriser'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 456
    Top = 504
    Width = 89
    Height = 25
    Caption = 'Annuler'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 560
    Top = 504
    Width = 89
    Height = 25
    Caption = 'Aide'
    TabOrder = 8
  end
  object btAppliquer: TButton
    Left = 504
    Top = 264
    Width = 145
    Height = 25
    Caption = 'Appliquer'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    OnClick = btAppliquerClick
  end
  object BitBtn1: TBitBtn
    Left = 184
    Top = 128
    Width = 25
    Height = 25
    TabOrder = 10
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
    Left = 184
    Top = 152
    Width = 25
    Height = 25
    TabOrder = 11
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
  object btCreer: TButton
    Left = 504
    Top = 200
    Width = 145
    Height = 25
    Caption = 'Créer Rapport'
    TabOrder = 12
    OnClick = btCreerClick
  end
  object btOK: TButton
    Left = 344
    Top = 504
    Width = 97
    Height = 25
    Caption = 'OK'
    TabOrder = 13
    OnClick = btOKClick
  end
  object cbMarge: TCheckBox
    Left = 16
    Top = 288
    Width = 113
    Height = 17
    Caption = 'Marges du Cadre'
    Checked = True
    State = cbChecked
    TabOrder = 14
    OnClick = cbMargeClick
  end
  object btMarges: TButton
    Left = 168
    Top = 288
    Width = 121
    Height = 17
    Caption = 'Description Marges'
    TabOrder = 15
    OnClick = btMargesClick
  end
  object btDonCol: TButton
    Left = 168
    Top = 464
    Width = 121
    Height = 17
    Caption = 'Données Colonnes'
    TabOrder = 16
    OnClick = btDonColClick
  end
  object btTitLig: TButton
    Left = 168
    Top = 496
    Width = 121
    Height = 17
    Caption = 'Modifications'
    TabOrder = 17
    OnClick = btTitLigClick
  end
  object btSuppr: TButton
    Left = 504
    Top = 168
    Width = 145
    Height = 25
    Caption = 'Suppression Rapport'
    TabOrder = 18
    OnClick = btSupprClick
  end
  object cb3: TCheckBox
    Left = 16
    Top = 312
    Width = 97
    Height = 17
    Caption = 'Trait Cadre'
    Checked = True
    State = cbChecked
    TabOrder = 19
    OnClick = cb3Click
  end
  object btCadre: TButton
    Left = 168
    Top = 312
    Width = 121
    Height = 17
    Caption = 'Description du Cadre'
    TabOrder = 20
    OnClick = btCadreClick
  end
  object cb4: TCheckBox
    Left = 16
    Top = 336
    Width = 97
    Height = 17
    Caption = 'En-tête'
    Checked = True
    State = cbChecked
    TabOrder = 21
    OnClick = cb4Click
  end
  object btEntete: TButton
    Left = 168
    Top = 336
    Width = 121
    Height = 17
    Caption = 'Description En-tête'
    TabOrder = 22
    OnClick = btEnteteClick
  end
  object cb7: TCheckBox
    Left = 16
    Top = 384
    Width = 97
    Height = 17
    Caption = 'Pied de page'
    TabOrder = 23
    OnClick = cb7Click
  end
  object btPied: TButton
    Left = 168
    Top = 384
    Width = 121
    Height = 17
    Caption = 'Description pied de page'
    TabOrder = 24
    OnClick = btPiedClick
  end
  object cbETPage: TCheckBox
    Left = 40
    Top = 360
    Width = 153
    Height = 17
    Caption = 'En-TêteToutes les Pages '
    TabOrder = 25
    OnClick = cbETPageClick
  end
  object cbPied: TCheckBox
    Left = 40
    Top = 408
    Width = 161
    Height = 17
    Caption = 'Pied Toutes les Page'
    TabOrder = 26
    OnClick = cbPiedClick
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 184
    Top = 40
  end
end
