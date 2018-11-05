object Form2: TForm2
  Left = 126
  Top = 0
  Width = 1063
  Height = 724
  Caption = 'Form2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 224
    Top = 32
    Width = 529
    Height = 81
  end
  object Label73: TLabel
    Left = 408
    Top = 16
    Width = 56
    Height = 13
    Caption = 'DÈsignation'
  end
  object Label72: TLabel
    Left = 640
    Top = 16
    Width = 87
    Height = 13
    Caption = 'Nombre de t‚ches'
  end
  object Label8: TLabel
    Left = 16
    Top = 8
    Width = 199
    Height = 13
    Caption = 'Affectation des critËres aux t‚ches'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label31: TLabel
    Left = 64
    Top = 40
    Width = 38
    Height = 13
    Caption = 'CritËre'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label32: TLabel
    Left = 88
    Top = 56
    Width = 85
    Height = 13
    Caption = 'Sous-CritËre Niv-1'
  end
  object Label33: TLabel
    Left = 104
    Top = 72
    Width = 85
    Height = 13
    Caption = 'Sous-CritËre Niv-2'
  end
  object Label34: TLabel
    Left = 128
    Top = 88
    Width = 85
    Height = 13
    Caption = 'Sous-CritËre Niv-3'
  end
  object asCrit: TAdvStringGrid
    Left = 16
    Top = 120
    Width = 969
    Height = 481
    Cursor = crDefault
    ColCount = 21
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
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
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
    OnClickCell = asCritClickCell
    OnCanEditCell = asCritCanEditCell
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
      ''
      'N∞'
      'DÈsignation'
      'Crit 1'
      'DÈsignation 1'
      'Crit 2'
      'DÈsignation 2'
      'Crit 3'
      'DÈsignation 3'
      'Crit 4'
      'DÈsignation 4'
      'Crit 5'
      'DÈsignation 5'
      'Crit6'
      'DÈs 6'
      'Crit7'
      'DÈs 7'
      'Crit8'
      'DÈs 8')
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
      34
      147
      45
      135
      45
      135
      45
      135
      45
      135
      5
      4
      3
      4
      4
      4
      4
      4
      29
      34)
  end
  object btEraseCrit: TButton
    Left = 24
    Top = 608
    Width = 185
    Height = 25
    Caption = 'Tous les CritËres de T‚ches ÅEBlanc'
    TabOrder = 1
  end
  object btCrit1: TButton
    Left = 224
    Top = 608
    Width = 177
    Height = 25
    Caption = 'Suppr. Crit. 1  T‚ches CochÈes'
    TabOrder = 2
  end
  object btCrit2: TButton
    Left = 424
    Top = 608
    Width = 153
    Height = 25
    Caption = 'Supp. Crit 2 T‚ches CochÈes'
    TabOrder = 3
  end
  object btCrit3: TButton
    Left = 600
    Top = 608
    Width = 169
    Height = 25
    Caption = 'Suppr. Crit 3 T‚ches CochÈes'
    TabOrder = 4
  end
  object btCrit4: TButton
    Left = 784
    Top = 608
    Width = 169
    Height = 25
    Caption = 'Suppr. Crit 4 T‚ches CochÈes'
    TabOrder = 5
  end
  object btSaveAffect: TButton
    Left = 832
    Top = 16
    Width = 105
    Height = 25
    Caption = 'Sauvegarder'
    TabOrder = 6
  end
  object btAccCrit: TButton
    Left = 832
    Top = 48
    Width = 105
    Height = 25
    Caption = 'AccËs CritËres'
    TabOrder = 7
    OnClick = btAccCritClick
  end
  object btAideCrit: TButton
    Left = 832
    Top = 80
    Width = 105
    Height = 25
    Caption = 'Aide'
    TabOrder = 8
  end
end
