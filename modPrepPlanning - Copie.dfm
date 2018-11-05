object PrepPlanning: TPrepPlanning
  Left = 235
  Top = 107
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
    Left = 872
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
    Left = 440
    Top = 52
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
    Left = 352
    Top = 448
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
    Top = 520
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
  object Bevel2: TBevel
    Left = 24
    Top = 288
    Width = 305
    Height = 249
  end
  object Bevel3: TBevel
    Left = 344
    Top = 440
    Width = 545
    Height = 145
  end
  object Bevel5: TBevel
    Left = 344
    Top = 264
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
    Left = 648
    Top = 264
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
    Width = 205
    Height = 13
    Caption = 'Configuration du Planning en Cours '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label23: TLabel
    Left = 632
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
    Left = 560
    Top = 152
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
  object Bevel4: TBevel
    Left = 352
    Top = 200
    Width = 929
    Height = 57
  end
  object Label14: TLabel
    Left = 552
    Top = 408
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
  object Label19: TLabel
    Left = 664
    Top = 154
    Width = 112
    Height = 13
    Caption = '(Clic droite pour effacer)'
  end
  object Label4: TLabel
    Left = 816
    Top = 48
    Width = 34
    Height = 13
    Caption = 'Le Tri'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label20: TLabel
    Left = 352
    Top = 48
    Width = 47
    Height = 13
    Caption = 'Le Filtre'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbPlanning: TListBox
    Left = 8
    Top = 40
    Width = 329
    Height = 209
    ItemHeight = 13
    TabOrder = 0
    OnClick = lbPlanningClick
  end
  object Button1: TButton
    Left = 360
    Top = 216
    Width = 177
    Height = 33
    Caption = 'Modifier Filtre'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
    OnContextPopup = Button1ContextPopup
  end
  object Button2: TButton
    Left = 560
    Top = 216
    Width = 161
    Height = 33
    Caption = 'Modifier Trier / Grouper'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button2Click
    OnContextPopup = Button2ContextPopup
  end
  object Button3: TButton
    Left = 744
    Top = 216
    Width = 161
    Height = 33
    Caption = 'Colonnes Grille Gantt'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = Button3Click
    OnContextPopup = Button3ContextPopup
  end
  object eMemoire: TEdit
    Left = 352
    Top = 472
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
    Left = 352
    Top = 504
    Width = 505
    Height = 65
    TabOrder = 5
    OnKeyUp = mPlanningKeyUp
  end
  object Button6: TButton
    Left = 696
    Top = 288
    Width = 129
    Height = 25
    Caption = 'Mémoriser Planning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 696
    Top = 384
    Width = 129
    Height = 21
    Caption = 'Annuler'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 880
    Top = 320
    Width = 97
    Height = 33
    Caption = 'Aide'
    TabOrder = 8
    OnClick = Button8Click
  end
  object GroupBox1: TGroupBox
    Left = 1080
    Top = 336
    Width = 201
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
    Top = 272
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
    Left = 352
    Top = 400
    Width = 153
    Height = 17
    Caption = 'Lignes brisées Actualisation'
    TabOrder = 11
    OnClick = cb1Click
  end
  object cb2: TCheckBox
    Left = 352
    Top = 376
    Width = 129
    Height = 17
    Caption = 'Gant avec grille'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
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
    Width = 153
    Height = 17
    Caption = 'Description En-tête'
    TabOrder = 16
    OnClick = btEnteteClick
  end
  object btCal: TButton
    Left = 160
    Top = 392
    Width = 153
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
    Width = 153
    Height = 17
    Caption = 'Description tâches'
    TabOrder = 19
    OnClick = btTachesClick
  end
  object btCorps: TButton
    Left = 160
    Top = 440
    Width = 153
    Height = 17
    Caption = 'Description corps'
    TabOrder = 20
    OnClick = btCorpsClick
  end
  object btPied: TButton
    Left = 160
    Top = 496
    Width = 145
    Height = 17
    Caption = 'Description pied de page'
    TabOrder = 21
    OnClick = btPiedClick
  end
  object btOK: TButton
    Left = 552
    Top = 432
    Width = 89
    Height = 21
    Caption = 'OK'
    TabOrder = 22
    Visible = False
    OnClick = btOKClick
  end
  object btCadre: TButton
    Left = 160
    Top = 344
    Width = 153
    Height = 17
    Caption = 'Description du cadre'
    TabOrder = 23
    OnClick = btCadreClick
  end
  object btM: TButton
    Left = 160
    Top = 320
    Width = 153
    Height = 17
    Caption = 'Description des marges'
    TabOrder = 24
    OnClick = btMClick
  end
  object Button9: TButton
    Left = 544
    Top = 288
    Width = 129
    Height = 25
    Caption = 'Créer Planning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 25
    OnClick = Button9Click
  end
  object BitBtn1: TBitBtn
    Left = 304
    Top = 144
    Width = 25
    Height = 25
    TabOrder = 26
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
    TabOrder = 27
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
    Left = 696
    Top = 336
    Width = 121
    Height = 25
    Caption = 'Appliquer Planning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 28
    OnClick = btAppliquerClick
  end
  object btSuppr: TButton
    Left = 544
    Top = 336
    Width = 129
    Height = 25
    Caption = 'Supprimer Planning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 29
    OnClick = btSupprClick
  end
  object cbEbauche: TCheckBox
    Left = 552
    Top = 384
    Width = 121
    Height = 17
    Caption = 'Ebauche Planning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 30
    OnClick = cbEbaucheClick
  end
  object Button4: TButton
    Left = 8
    Top = 256
    Width = 113
    Height = 17
    Caption = 'Tri de la Liste'
    TabOrder = 31
    OnClick = Button4Click
  end
  object AdvStringGrid1: TAdvStringGrid
    Left = 352
    Top = 72
    Width = 457
    Height = 120
    Cursor = crDefault
    ColCount = 4
    DefaultRowHeight = 21
    DefaultDrawing = False
    FixedCols = 0
    RowCount = 2
    FixedRows = 1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    GridLineWidth = 1
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected]
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 32
    GridLineColor = clSilver
    ActiveCellShow = False
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ActiveCellColor = clGray
    ActiveCellColorTo = clNone
    Bands.PrimaryColor = clInfoBk
    Bands.PrimaryLength = 1
    Bands.SecondaryColor = clWindow
    Bands.SecondaryLength = 1
    Bands.Print = False
    AutoNumAlign = False
    AutoSize = False
    VAlignment = vtaTop
    EnhTextSize = False
    EnhRowColMove = True
    SizeWithForm = False
    Multilinecells = False
    DragDropSettings.OleAcceptFiles = True
    DragDropSettings.OleAcceptText = True
    SortSettings.AutoColumnMerge = False
    SortSettings.Column = 0
    SortSettings.Show = False
    SortSettings.IndexShow = False
    SortSettings.IndexColor = clYellow
    SortSettings.Full = True
    SortSettings.SingleColumn = False
    SortSettings.IgnoreBlanks = False
    SortSettings.BlankPos = blFirst
    SortSettings.AutoFormat = True
    SortSettings.Direction = sdAscending
    SortSettings.InitSortDirection = sdAscending
    SortSettings.FixedCols = False
    SortSettings.NormalCellsOnly = False
    SortSettings.Row = 0
    SortSettings.UndoSort = False
    FloatingFooter.Color = clBtnFace
    FloatingFooter.Column = 0
    FloatingFooter.FooterStyle = fsFixedLastRow
    FloatingFooter.Visible = False
    ControlLook.Color = clBlack
    ControlLook.CommentColor = clRed
    ControlLook.CheckSize = 15
    ControlLook.RadioSize = 10
    ControlLook.ControlStyle = csWinXP
    ControlLook.DropDownAlwaysVisible = False
    ControlLook.ProgressMarginX = 2
    ControlLook.ProgressMarginY = 2
    EnableBlink = False
    EnableHTML = True
    EnableWheel = True
    Flat = False
    Look = glXP
    HintColor = clInfoBk
    SelectionColor = 15387318
    SelectionTextColor = clBlack
    SelectionRectangle = False
    SelectionResizer = False
    SelectionRTFKeep = False
    HintShowCells = False
    HintShowLargeText = False
    HintShowSizing = False
    PrintSettings.FooterSize = 0
    PrintSettings.HeaderSize = 0
    PrintSettings.Time = ppNone
    PrintSettings.Date = ppNone
    PrintSettings.DateFormat = 'dd/mm/yyyy'
    PrintSettings.PageNr = ppNone
    PrintSettings.Title = ppNone
    PrintSettings.Font.Charset = DEFAULT_CHARSET
    PrintSettings.Font.Color = clWindowText
    PrintSettings.Font.Height = -11
    PrintSettings.Font.Name = 'MS Sans Serif'
    PrintSettings.Font.Style = []
    PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
    PrintSettings.FixedFont.Color = clWindowText
    PrintSettings.FixedFont.Height = -11
    PrintSettings.FixedFont.Name = 'MS Sans Serif'
    PrintSettings.FixedFont.Style = []
    PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
    PrintSettings.HeaderFont.Color = clWindowText
    PrintSettings.HeaderFont.Height = -11
    PrintSettings.HeaderFont.Name = 'MS Sans Serif'
    PrintSettings.HeaderFont.Style = []
    PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
    PrintSettings.FooterFont.Color = clWindowText
    PrintSettings.FooterFont.Height = -11
    PrintSettings.FooterFont.Name = 'MS Sans Serif'
    PrintSettings.FooterFont.Style = []
    PrintSettings.Borders = pbSingle
    PrintSettings.BorderStyle = psSolid
    PrintSettings.Centered = True
    PrintSettings.RepeatFixedRows = False
    PrintSettings.RepeatFixedCols = False
    PrintSettings.LeftSize = 0
    PrintSettings.RightSize = 0
    PrintSettings.ColumnSpacing = 0
    PrintSettings.RowSpacing = 0
    PrintSettings.TitleSpacing = 0
    PrintSettings.Orientation = poPortrait
    PrintSettings.PageNumberOffset = 0
    PrintSettings.MaxPagesOffset = 0
    PrintSettings.FixedWidth = 0
    PrintSettings.FixedHeight = 0
    PrintSettings.UseFixedHeight = False
    PrintSettings.UseFixedWidth = False
    PrintSettings.FitToPage = fpNever
    PrintSettings.PageNumSep = '/'
    PrintSettings.NoAutoSize = False
    PrintSettings.NoAutoSizeRow = False
    PrintSettings.PrintGraphics = False
    PrintSettings.UseDisplayFont = True
    HTMLSettings.Width = 100
    HTMLSettings.XHTML = False
    Navigation.AdvanceDirection = adLeftRight
    Navigation.InsertPosition = pInsertBefore
    Navigation.HomeEndKey = heFirstLastColumn
    Navigation.TabToNextAtEnd = False
    Navigation.TabAdvanceDirection = adLeftRight
    ColumnSize.Location = clRegistry
    CellNode.Color = clSilver
    CellNode.ExpandOne = False
    CellNode.NodeColor = clBlack
    CellNode.NodeIndent = 12
    CellNode.TreeColor = clSilver
    MaxEditLength = 0
    Grouping.HeaderColor = clNone
    Grouping.HeaderColorTo = clNone
    Grouping.HeaderTextColor = clNone
    Grouping.MergeHeader = False
    Grouping.MergeSummary = False
    Grouping.Summary = False
    Grouping.SummaryColor = clNone
    Grouping.SummaryColorTo = clNone
    Grouping.SummaryTextColor = clNone
    IntelliPan = ipVertical
    URLColor = clBlue
    URLShow = False
    URLFull = False
    URLEdit = False
    ScrollType = ssNormal
    ScrollColor = clNone
    ScrollWidth = 17
    ScrollSynch = False
    ScrollProportional = False
    ScrollHints = shNone
    OemConvert = False
    FixedFooters = 0
    FixedRightCols = 0
    FixedColWidth = 64
    FixedRowHeight = 21
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'Tahoma'
    FixedFont.Style = [fsBold]
    FixedAsButtons = False
    FloatFormat = '%.2f'
    IntegralHeight = False
    WordWrap = True
    Lookup = False
    LookupCaseSensitive = False
    LookupHistory = False
    BackGround.Top = 0
    BackGround.Left = 0
    BackGround.Display = bdTile
    BackGround.Cells = bcNormal
    Filter = <>
    Version = '2.8.5.0'
    ColWidths = (
      64
      64
      64
      64)
  end
  object Button5: TButton
    Left = 1152
    Top = 280
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 33
    Visible = False
    OnClick = Button5Click
  end
  object Button10: TButton
    Left = 1248
    Top = 280
    Width = 75
    Height = 25
    Caption = 'Button10'
    TabOrder = 34
    Visible = False
    OnClick = Button10Click
  end
  object ListBox1: TListBox
    Left = 56
    Top = 552
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 35
    Visible = False
  end
  object Button11: TButton
    Left = 72
    Top = 664
    Width = 75
    Height = 25
    Caption = 'Button11'
    TabOrder = 36
    Visible = False
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 880
    Top = 368
    Width = 97
    Height = 33
    Caption = 'Vidéos'
    TabOrder = 37
    OnClick = Button8Click
  end
  object AdvStringGrid2: TAdvStringGrid
    Left = 820
    Top = 76
    Width = 681
    Height = 117
    Cursor = crDefault
    ColCount = 14
    DefaultColWidth = 21
    DefaultRowHeight = 21
    DefaultDrawing = False
    FixedCols = 1
    RowCount = 2
    FixedRows = 1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    GridLineWidth = 1
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goEditing]
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 38
    OnKeyDown = AdvStringGrid2KeyDown
    GridLineColor = clSilver
    ActiveCellShow = False
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    ActiveCellColor = clGray
    ActiveCellColorTo = clNone
    Bands.PrimaryColor = clInfoBk
    Bands.PrimaryLength = 1
    Bands.SecondaryColor = clWindow
    Bands.SecondaryLength = 1
    Bands.Print = False
    AutoNumAlign = False
    AutoSize = False
    VAlignment = vtaTop
    EnhTextSize = False
    EnhRowColMove = True
    SizeWithForm = False
    Multilinecells = False
    DragDropSettings.OleAcceptFiles = True
    DragDropSettings.OleAcceptText = True
    SortSettings.AutoColumnMerge = False
    SortSettings.Column = 0
    SortSettings.Show = False
    SortSettings.IndexShow = False
    SortSettings.IndexColor = clYellow
    SortSettings.Full = True
    SortSettings.SingleColumn = False
    SortSettings.IgnoreBlanks = False
    SortSettings.BlankPos = blFirst
    SortSettings.AutoFormat = True
    SortSettings.Direction = sdAscending
    SortSettings.InitSortDirection = sdAscending
    SortSettings.FixedCols = False
    SortSettings.NormalCellsOnly = False
    SortSettings.Row = 0
    SortSettings.UndoSort = False
    FloatingFooter.Color = clBtnFace
    FloatingFooter.Column = 0
    FloatingFooter.FooterStyle = fsFixedLastRow
    FloatingFooter.Visible = False
    ControlLook.Color = clBlack
    ControlLook.CommentColor = clRed
    ControlLook.CheckSize = 15
    ControlLook.RadioSize = 10
    ControlLook.ControlStyle = csWinXP
    ControlLook.DropDownAlwaysVisible = False
    ControlLook.ProgressMarginX = 2
    ControlLook.ProgressMarginY = 2
    EnableBlink = False
    EnableHTML = True
    EnableWheel = True
    Flat = False
    Look = glXP
    HintColor = clInfoBk
    SelectionColor = 15387318
    SelectionTextColor = clBlack
    SelectionRectangle = False
    SelectionResizer = False
    SelectionRTFKeep = False
    HintShowCells = False
    HintShowLargeText = False
    HintShowSizing = False
    PrintSettings.FooterSize = 0
    PrintSettings.HeaderSize = 0
    PrintSettings.Time = ppNone
    PrintSettings.Date = ppNone
    PrintSettings.DateFormat = 'dd/mm/yyyy'
    PrintSettings.PageNr = ppNone
    PrintSettings.Title = ppNone
    PrintSettings.Font.Charset = DEFAULT_CHARSET
    PrintSettings.Font.Color = clWindowText
    PrintSettings.Font.Height = -11
    PrintSettings.Font.Name = 'MS Sans Serif'
    PrintSettings.Font.Style = []
    PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
    PrintSettings.FixedFont.Color = clWindowText
    PrintSettings.FixedFont.Height = -11
    PrintSettings.FixedFont.Name = 'MS Sans Serif'
    PrintSettings.FixedFont.Style = []
    PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
    PrintSettings.HeaderFont.Color = clWindowText
    PrintSettings.HeaderFont.Height = -11
    PrintSettings.HeaderFont.Name = 'MS Sans Serif'
    PrintSettings.HeaderFont.Style = []
    PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
    PrintSettings.FooterFont.Color = clWindowText
    PrintSettings.FooterFont.Height = -11
    PrintSettings.FooterFont.Name = 'MS Sans Serif'
    PrintSettings.FooterFont.Style = []
    PrintSettings.Borders = pbSingle
    PrintSettings.BorderStyle = psSolid
    PrintSettings.Centered = True
    PrintSettings.RepeatFixedRows = False
    PrintSettings.RepeatFixedCols = False
    PrintSettings.LeftSize = 0
    PrintSettings.RightSize = 0
    PrintSettings.ColumnSpacing = 0
    PrintSettings.RowSpacing = 0
    PrintSettings.TitleSpacing = 0
    PrintSettings.Orientation = poPortrait
    PrintSettings.PageNumberOffset = 0
    PrintSettings.MaxPagesOffset = 0
    PrintSettings.FixedWidth = 0
    PrintSettings.FixedHeight = 0
    PrintSettings.UseFixedHeight = False
    PrintSettings.UseFixedWidth = False
    PrintSettings.FitToPage = fpNever
    PrintSettings.PageNumSep = '/'
    PrintSettings.NoAutoSize = False
    PrintSettings.NoAutoSizeRow = False
    PrintSettings.PrintGraphics = False
    PrintSettings.UseDisplayFont = True
    HTMLSettings.Width = 100
    HTMLSettings.XHTML = False
    Navigation.AdvanceDirection = adLeftRight
    Navigation.InsertPosition = pInsertBefore
    Navigation.HomeEndKey = heFirstLastColumn
    Navigation.TabToNextAtEnd = False
    Navigation.TabAdvanceDirection = adLeftRight
    ColumnSize.Location = clRegistry
    CellNode.Color = clSilver
    CellNode.ExpandOne = False
    CellNode.NodeColor = clBlack
    CellNode.NodeIndent = 12
    CellNode.TreeColor = clSilver
    MaxEditLength = 0
    Grouping.HeaderColor = clNone
    Grouping.HeaderColorTo = clNone
    Grouping.HeaderTextColor = clNone
    Grouping.MergeHeader = False
    Grouping.MergeSummary = False
    Grouping.Summary = False
    Grouping.SummaryColor = clNone
    Grouping.SummaryColorTo = clNone
    Grouping.SummaryTextColor = clNone
    IntelliPan = ipVertical
    URLColor = clBlue
    URLShow = False
    URLFull = False
    URLEdit = False
    ScrollType = ssNormal
    ScrollColor = clNone
    ScrollWidth = 17
    ScrollSynch = False
    ScrollProportional = False
    ScrollHints = shNone
    OemConvert = False
    FixedFooters = 0
    FixedRightCols = 0
    FixedColWidth = 21
    FixedRowHeight = 21
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'Tahoma'
    FixedFont.Style = [fsBold]
    FixedAsButtons = False
    FloatFormat = '%.2f'
    IntegralHeight = False
    WordWrap = True
    ColumnHeaders.Strings = (
      'Options'
      'Composition Trier Grouper'
      ''
      'N-0'
      'N-1'
      'N-2'
      'N-3'
      ''
      'Envel'
      ''
      'Ligne'
      'Colonne'
      'Trait'
      'Espace'
      '')
    Lookup = False
    LookupCaseSensitive = False
    LookupHistory = False
    BackGround.Top = 0
    BackGround.Left = 0
    BackGround.Display = bdTile
    BackGround.Cells = bcNormal
    Filter = <>
    Version = '2.8.5.0'
    ColWidths = (
      21
      79
      5
      46
      40
      32
      38
      3
      53
      3
      43
      55
      43
      49)
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 264
  end
end
