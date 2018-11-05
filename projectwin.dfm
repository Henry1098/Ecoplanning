object fProjet: TfProjet
  Left = 377
  Top = 153
  Width = 552
  Height = 527
  BiDiMode = bdLeftToRight
  Caption = 'Définition de Projet'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  ParentBiDiMode = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 224
    Width = 67
    Height = 13
    Caption = 'Code Projet'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 16
    Top = 272
    Width = 51
    Height = 13
    Caption = 'Titre Projet'
  end
  object Label9: TLabel
    Left = 16
    Top = 8
    Width = 147
    Height = 13
    Caption = 'Date : Début Prévisionnel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 216
    Top = 8
    Width = 168
    Height = 13
    Caption = 'Répertoire du nouveau Projet'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 240
    Top = 240
    Width = 5
    Height = 13
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 160
    Top = 240
    Width = 49
    Height = 13
    Caption = 'Répertoire'
  end
  object Label6: TLabel
    Left = 8
    Top = 320
    Width = 62
    Height = 13
    Caption = 'Observations'
  end
  object ENomProj: TEdit
    Left = 8
    Top = 240
    Width = 129
    Height = 21
    TabOrder = 0
    OnExit = ENomProjExit
  end
  object eTitre: TEdit
    Left = 8
    Top = 288
    Width = 497
    Height = 21
    TabOrder = 1
  end
  object btHelp: TButton
    Left = 400
    Top = 72
    Width = 121
    Height = 25
    Caption = 'Aide'
    TabOrder = 2
    OnClick = btHelpClick
  end
  object btSaveCont: TButton
    Left = 400
    Top = 8
    Width = 121
    Height = 25
    Caption = 'Sauvegarder/Continuer'
    TabOrder = 3
    OnClick = btSaveContClick
  end
  object eDebPrev: TEdit
    Left = 56
    Top = 32
    Width = 73
    Height = 21
    TabOrder = 4
  end
  object Button1: TButton
    Left = 400
    Top = 40
    Width = 121
    Height = 25
    Caption = 'Annuler'
    TabOrder = 5
    OnClick = Button1Click
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 232
    Top = 64
    Width = 145
    Height = 153
    ItemHeight = 16
    TabOrder = 6
    OnClick = DirectoryListBox1Click
  end
  object DriveComboBox1: TDriveComboBox
    Left = 232
    Top = 32
    Width = 145
    Height = 19
    TabOrder = 7
    OnChange = DriveComboBox1Change
  end
  object Memo1: TMemo
    Left = 8
    Top = 336
    Width = 497
    Height = 89
    TabOrder = 8
  end
  object btImport: TButton
    Left = 40
    Top = 448
    Width = 193
    Height = 25
    Caption = 'Importer Fichiers TACHES/LIAISONS'
    TabOrder = 9
    OnClick = btImportClick
  end
  object MonthCalendar1: TMonthCalendar
    Left = 16
    Top = 64
    Width = 191
    Height = 154
    Date = 39094.6494396296
    ShowTodayCircle = False
    TabOrder = 10
    OnClick = MonthCalendar1Click
  end
  object Button2: TButton
    Left = 280
    Top = 448
    Width = 201
    Height = 25
    Caption = 'Importer Fichiers Conversion Project'
    TabOrder = 11
    OnClick = Button2Click
  end
  object OpenDialog1: TOpenDialog
    Left = 408
    Top = 152
  end
end
