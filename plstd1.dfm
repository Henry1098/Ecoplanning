object plStandard: TplStandard
  Left = 134
  Top = 180
  Width = 1039
  Height = 788
  Caption = ' Ecoplanning 5.0'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 18
    Top = 8
    Width = 999
    Height = 705
    ActivePage = pl1
    MultiLine = True
    TabOrder = 0
    OnChange = PageControl1Change
    object pl1: TTabSheet
      Caption = 'Saisie Prévisionnelle'
      object Label1: TLabel
        Left = 24
        Top = 0
        Width = 76
        Height = 13
        Caption = 'nbre Tâches:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 24
        Top = 276
        Width = 84
        Height = 13
        Caption = 'Prédécesseurs'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 504
        Top = 276
        Width = 73
        Height = 13
        Caption = 'Successeurs'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label10: TLabel
        Left = 24
        Top = 16
        Width = 98
        Height = 13
        Caption = 'Tâche en cours :'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label11: TLabel
        Left = 128
        Top = 16
        Width = 8
        Height = 13
        Caption = '1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label13: TLabel
        Left = 176
        Top = 16
        Width = 125
        Height = 13
        Caption = 'nbre Tâches Cochées'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label14: TLabel
        Left = 176
        Top = 0
        Width = 113
        Height = 13
        Caption = 'nbreTâches Filtrées'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label15: TLabel
        Left = 120
        Top = 0
        Width = 38
        Height = 13
        Caption = 'Label15'
      end
      object Label16: TLabel
        Left = 304
        Top = 16
        Width = 38
        Height = 13
        Caption = 'Label16'
      end
      object Label17: TLabel
        Left = 304
        Top = 0
        Width = 38
        Height = 13
        Caption = 'Label17'
      end
      object Label6: TLabel
        Left = 360
        Top = 0
        Width = 92
        Height = 13
        Caption = 'Date Deb Projet'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label7: TLabel
        Left = 472
        Top = 0
        Width = 28
        Height = 13
        Caption = '--/--/--'
      end
      object immGantt: TImage
        Left = 120
        Top = 400
        Width = 841
        Height = 257
      end
      object Label26: TLabel
        Left = 8
        Top = 416
        Width = 97
        Height = 13
        Caption = 'Ordonnancement'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label43: TLabel
        Left = 360
        Top = 16
        Width = 104
        Height = 13
        Caption = 'Date de Fin Projet'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label44: TLabel
        Left = 472
        Top = 16
        Width = 28
        Height = 13
        Caption = '--/--/--'
      end
      object Label19: TLabel
        Left = 8
        Top = 432
        Width = 37
        Height = 13
        Caption = 'Tâche'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label81: TLabel
        Left = 272
        Top = 276
        Width = 125
        Height = 13
        Caption = 'Nombre de Prédécesseurs'
      end
      object Label82: TLabel
        Left = 712
        Top = 276
        Width = 116
        Height = 13
        Caption = 'Nombre de Successeurs'
      end
      object lnbPred: TLabel
        Left = 408
        Top = 276
        Width = 6
        Height = 13
        Caption = '0'
      end
      object lnbSucc: TLabel
        Left = 840
        Top = 276
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label102: TLabel
        Left = 8
        Top = 448
        Width = 50
        Height = 13
        Caption = 'en cours'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lTEC: TLabel
        Left = 56
        Top = 432
        Width = 3
        Height = 13
      end
      object AdvStringGrid1: TAdvStringGrid
        Left = 24
        Top = 32
        Width = 945
        Height = 241
        Cursor = crDefault
        ColCount = 20
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
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing, goTabs]
        ParentFont = False
        PopupMenu = PopupList
        ScrollBars = ssBoth
        TabOrder = 0
        OnContextPopup = AdvStringGrid1ContextPopup
        OnKeyDown = AdvStringGrid1KeyDown
        OnMouseUp = AdvStringGrid1MouseUp
        OnSelectCell = AdvStringGrid1SelectCell
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
        OnGetAlignment = AdvStringGrid1GetAlignment
        OnGetFormat = AdvStringGrid1GetFormat
        OnClickCell = AdvStringGrid1ClickCell
        OnCanEditCell = AdvStringGrid1CanEditCell
        OnCellValidate = AdvStringGrid1CellValidate
        DragDropSettings.OleAcceptFiles = True
        DragDropSettings.OleAcceptText = True
        SortSettings.AutoColumnMerge = False
        SortSettings.Column = 0
        SortSettings.Show = True
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
        SelectionColor = clSilver
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
          39
          136
          43
          53
          53
          53
          53
          43
          42
          37
          43
          21
          21
          21
          21
          21
          21
          21
          21)
      end
      object AdvStringGrid2: TAdvStringGrid
        Left = 24
        Top = 296
        Width = 465
        Height = 97
        Cursor = crDefault
        ColCount = 8
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
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 1
        OnKeyDown = AdvStringGrid2KeyDown
        OnSelectCell = AdvStringGrid2SelectCell
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
        OnClickCell = AdvStringGrid2ClickCell
        OnCanEditCell = AdvStringGrid2CanEditCell
        OnCellValidate = AdvStringGrid2CellValidate
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
          33
          135
          41
          64
          40
          40
          48)
      end
      object AdvStringGrid3: TAdvStringGrid
        Left = 504
        Top = 296
        Width = 465
        Height = 97
        Cursor = crDefault
        ColCount = 9
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
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 2
        OnKeyDown = AdvStringGrid3KeyDown
        OnSelectCell = AdvStringGrid3SelectCell
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
        OnClickCell = AdvStringGrid3ClickCell
        OnCanEditCell = AdvStringGrid3CanEditCell
        OnCellValidate = AdvStringGrid3CellValidate
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
          33
          119
          42
          40
          42
          42
          45
          58)
      end
      object ScrollBar5: TScrollBar
        Left = 16
        Top = 624
        Width = 49
        Height = 17
        PageSize = 0
        TabOrder = 3
        Visible = False
        OnScroll = ScrollBar5Scroll
      end
      object ScrollBar6: TScrollBar
        Left = 968
        Top = 400
        Width = 17
        Height = 257
        Kind = sbVertical
        PageSize = 0
        TabOrder = 4
        Visible = False
        OnScroll = ScrollBar6Scroll
      end
      object btSauver: TButton
        Left = 616
        Top = 4
        Width = 75
        Height = 25
        Caption = 'Sauvegarder'
        TabOrder = 5
        OnClick = btSauverClick
      end
      object btSauverComme: TButton
        Left = 704
        Top = 4
        Width = 121
        Height = 25
        Caption = 'Sauvegarder Comme'
        TabOrder = 6
        OnClick = btSauverCommeClick
      end
      object btAideS: TButton
        Left = 840
        Top = 4
        Width = 75
        Height = 25
        Caption = 'Aide Saisie'
        TabOrder = 7
        OnClick = btAideSClick
      end
      object cbEchelle: TComboBox
        Left = 16
        Top = 520
        Width = 89
        Height = 73
        Style = csSimple
        ItemHeight = 13
        TabOrder = 8
        Text = 'Jours/Semaines'
        Visible = False
        OnChange = cbEchelleChange
        Items.Strings = (
          'Jours/Semaines'
          'Semaines/Mois'
          'Mois/Années')
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Gantt Prévisionnel'
      ImageIndex = 1
      OnContextPopup = AdvStringGrid1ContextPopup
      OnShow = TabSheet1Show
      object imGantt: TImage
        Left = 192
        Top = 48
        Width = 777
        Height = 593
        OnMouseDown = imGanttMouseDown
        OnMouseMove = imGanttMouseMove
      end
      object Label2: TLabel
        Left = 8
        Top = 16
        Width = 105
        Height = 13
        Caption = 'Gantt Prévisionnel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object imP0p: TImage
        Left = 8
        Top = 48
        Width = 169
        Height = 217
        Stretch = True
        OnMouseDown = imP0pMouseDown
      end
      object Label45: TLabel
        Left = 232
        Top = 16
        Width = 138
        Height = 13
        Caption = 'nbre de tâches total du projet'
      end
      object Label46: TLabel
        Left = 400
        Top = 16
        Width = 38
        Height = 13
        Caption = 'Label46'
      end
      object Label47: TLabel
        Left = 464
        Top = 16
        Width = 141
        Height = 13
        Caption = 'Nombre de tâches visualisées'
      end
      object Label48: TLabel
        Left = 624
        Top = 16
        Width = 38
        Height = 13
        Caption = 'Label48'
      end
      object Label69: TLabel
        Left = 26
        Top = 417
        Width = 32
        Height = 13
        Caption = 'Zoom'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label70: TLabel
        Left = 0
        Top = 440
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label71: TLabel
        Left = 160
        Top = 448
        Width = 12
        Height = 13
        Caption = '10'
        OnClick = Label71Click
      end
      object btAideGantt: TButton
        Left = 720
        Top = 8
        Width = 75
        Height = 25
        Caption = 'Aide Gantt'
        TabOrder = 0
      end
      object ZoomP0: TTrackBar
        Left = 16
        Top = 440
        Width = 137
        Height = 30
        Orientation = trHorizontal
        Frequency = 1
        Position = 5
        SelEnd = 0
        SelStart = 0
        TabOrder = 1
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = ZoomP0Change
      end
      object Button1: TButton
        Left = 16
        Top = 272
        Width = 153
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 2
        Visible = False
        OnClick = btPrAvancClick
      end
      object ComboBox1: TComboBox
        Left = 16
        Top = 616
        Width = 145
        Height = 49
        Style = csSimple
        ItemHeight = 13
        TabOrder = 3
        Text = 'Jours/Semaines'
        Visible = False
        Items.Strings = (
          'Jours/Semaines'
          'Semaines/Mois'
          'Mois/Années')
      end
      object btImpGantt: TButton
        Left = 16
        Top = 480
        Width = 153
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 4
        OnClick = btImpGanttClick
      end
      object btEchelle: TButton
        Left = 16
        Top = 520
        Width = 153
        Height = 25
        Caption = 'Hauteur entre Tâches'
        TabOrder = 5
        OnClick = btEchelleClick
      end
      object Button13: TButton
        Left = 16
        Top = 560
        Width = 153
        Height = 25
        Caption = 'Préparation Planning'
        TabOrder = 6
        Visible = False
        OnClick = Button13Click
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Affectation Critères'
      ImageIndex = 5
      OnHide = TabSheet5Hide
      OnShow = TabSheet5Show
      object Label8: TLabel
        Left = 16
        Top = 8
        Width = 199
        Height = 13
        Caption = 'Affectation des critères aux tâches'
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
        Caption = 'Critère'
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
        Caption = 'Sous-Critère Niv-1'
      end
      object Label33: TLabel
        Left = 104
        Top = 72
        Width = 85
        Height = 13
        Caption = 'Sous-Critère Niv-2'
      end
      object Label34: TLabel
        Left = 128
        Top = 88
        Width = 85
        Height = 13
        Caption = 'Sous-Critère Niv-3'
      end
      object lC1: TLabel
        Left = 272
        Top = 40
        Width = 3
        Height = 13
      end
      object lC2: TLabel
        Left = 272
        Top = 56
        Width = 3
        Height = 13
      end
      object lC3: TLabel
        Left = 272
        Top = 72
        Width = 3
        Height = 13
      end
      object lC4: TLabel
        Left = 272
        Top = 88
        Width = 3
        Height = 13
      end
      object lD1: TLabel
        Left = 384
        Top = 40
        Width = 3
        Height = 13
      end
      object lD2: TLabel
        Left = 384
        Top = 56
        Width = 3
        Height = 13
      end
      object lD3: TLabel
        Left = 384
        Top = 72
        Width = 3
        Height = 13
      end
      object lD4: TLabel
        Left = 384
        Top = 88
        Width = 3
        Height = 13
      end
      object lT2: TLabel
        Left = 672
        Top = 56
        Width = 3
        Height = 13
      end
      object lT3: TLabel
        Left = 672
        Top = 72
        Width = 3
        Height = 13
      end
      object lT4: TLabel
        Left = 672
        Top = 88
        Width = 3
        Height = 13
      end
      object Label72: TLabel
        Left = 640
        Top = 16
        Width = 87
        Height = 13
        Caption = 'Nombre de tâches'
      end
      object lT1: TLabel
        Left = 672
        Top = 40
        Width = 3
        Height = 13
      end
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
        Caption = 'Désignation'
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
        OnContextPopup = asCritContextPopup
        OnMouseUp = asCritMouseUp
        OnSelectCell = asCritSelectCell
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
          'N°'
          'Désignation'
          'Crit 1'
          'Désignation 1'
          'Crit 2'
          'Désignation 2'
          'Crit 3'
          'Désignation 3'
          'Crit 4'
          'Désignation 4'
          'Crit 5'
          'Désignation 5'
          'Crit6'
          'Dés 6'
          'Crit7'
          'Dés 7'
          'Crit8'
          'Dés 8')
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
          162
          70
          4
          63
          4
          72
          4
          55
          4
          63
          4
          56
          4
          58
          4
          58
          4
          29
          34)
      end
      object btSaveAffect: TButton
        Left = 832
        Top = 16
        Width = 105
        Height = 25
        Caption = 'Sauvegarder'
        TabOrder = 1
        OnClick = btSaveAffectClick
      end
      object btAccCrit: TButton
        Left = 832
        Top = 48
        Width = 105
        Height = 25
        Caption = 'Accès Critères'
        TabOrder = 2
        OnClick = btAccCritClick
      end
      object btAideCrit: TButton
        Left = 832
        Top = 80
        Width = 105
        Height = 25
        Caption = 'Aide'
        TabOrder = 3
      end
    end
    object TabSheet8: TTabSheet
      Caption = 'Planning en Cours'
      ImageIndex = 8
      OnShow = TabSheet8Show
      object imP1Screen: TImage
        Left = 240
        Top = 56
        Width = 745
        Height = 561
        OnMouseDown = imP1ScreenMouseDown
      end
      object imP1p: TImage
        Left = 24
        Top = 48
        Width = 185
        Height = 241
        Stretch = True
        OnMouseDown = imP1pMouseDown
      end
      object imP1l: TImage
        Left = 8
        Top = 312
        Width = 225
        Height = 161
        Stretch = True
        OnMouseDown = imP1lMouseDown
      end
      object Label36: TLabel
        Left = 30
        Top = 504
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label37: TLabel
        Left = 200
        Top = 512
        Width = 12
        Height = 13
        Caption = '10'
      end
      object Label40: TLabel
        Left = 24
        Top = 32
        Width = 42
        Height = 13
        Caption = 'Portrait'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label41: TLabel
        Left = 8
        Top = 296
        Width = 49
        Height = 13
        Caption = 'Paysage'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label42: TLabel
        Left = 50
        Top = 481
        Width = 32
        Height = 13
        Caption = 'Zoom'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label63: TLabel
        Left = 24
        Top = 8
        Width = 118
        Height = 13
        Caption = 'Elaboration Planning'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label64: TLabel
        Left = 288
        Top = 8
        Width = 118
        Height = 13
        Caption = 'Nombre Total de Tâches'
      end
      object Label65: TLabel
        Left = 416
        Top = 8
        Width = 38
        Height = 13
        Caption = 'Label65'
      end
      object Label66: TLabel
        Left = 504
        Top = 8
        Width = 149
        Height = 13
        Caption = 'Nombre de Tâches  Visualisées'
      end
      object Label67: TLabel
        Left = 664
        Top = 8
        Width = 38
        Height = 13
        Caption = 'Label67'
      end
      object lxy: TLabel
        Left = 16
        Top = 312
        Width = 3
        Height = 13
      end
      object Label103: TLabel
        Left = 288
        Top = 32
        Width = 152
        Height = 13
        Caption = 'Planning / Tri / Filtre / Colonnes'
      end
      object LP1TFC: TLabel
        Left = 464
        Top = 32
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object btPrP1: TButton
        Left = 32
        Top = 544
        Width = 81
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 0
        OnClick = btPrP1Click
      end
      object ZoomP1: TTrackBar
        Left = 40
        Top = 496
        Width = 153
        Height = 30
        Orientation = trHorizontal
        Frequency = 1
        Position = 5
        SelEnd = 0
        SelStart = 0
        TabOrder = 1
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = ZoomP1Change
      end
      object btRetPlanning1: TButton
        Left = 56
        Top = 584
        Width = 129
        Height = 25
        Caption = 'Préparation Planning'
        TabOrder = 2
        OnClick = btRetPlanning1Click
      end
      object btP1PDF: TButton
        Left = 128
        Top = 544
        Width = 89
        Height = 25
        Caption = 'Fichier PDF'
        TabOrder = 3
        OnClick = btP1PDFClick
      end
      object Button10: TButton
        Left = 832
        Top = 4
        Width = 75
        Height = 25
        Caption = 'Aide'
        TabOrder = 4
      end
      object btMemor1: TButton
        Left = 56
        Top = 624
        Width = 129
        Height = 25
        Caption = 'Mémoriser Planning'
        TabOrder = 5
        OnClick = btMemor1Click
      end
    end
    object TabSheet10: TTabSheet
      Caption = 'Planning 2'
      ImageIndex = 10
      OnShow = TabSheet10Show
      object Label88: TLabel
        Left = 24
        Top = 8
        Width = 118
        Height = 13
        Caption = 'Elaboration Planning'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label89: TLabel
        Left = 24
        Top = 32
        Width = 42
        Height = 13
        Caption = 'Portrait'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label91: TLabel
        Left = 24
        Top = 504
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label92: TLabel
        Left = 184
        Top = 504
        Width = 12
        Height = 13
        Caption = '10'
      end
      object imP2Screen: TImage
        Left = 240
        Top = 56
        Width = 745
        Height = 585
        OnMouseDown = imP2ScreenMouseDown
      end
      object imP2p: TImage
        Left = 24
        Top = 48
        Width = 185
        Height = 241
        Stretch = True
        OnMouseDown = imP2pMouseDown
      end
      object imP2l: TImage
        Left = 8
        Top = 312
        Width = 225
        Height = 161
        Stretch = True
        OnMouseDown = imP2lMouseDown
      end
      object Label93: TLabel
        Left = 8
        Top = 296
        Width = 49
        Height = 13
        Caption = 'Paysage'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label90: TLabel
        Left = 50
        Top = 481
        Width = 32
        Height = 13
        Caption = 'Zoom'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Labelxxx: TLabel
        Left = 288
        Top = 32
        Width = 152
        Height = 13
        Caption = 'Planning / Tri / Filtre / Colonnes'
      end
      object LP2FTC: TLabel
        Left = 464
        Top = 32
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label110: TLabel
        Left = 288
        Top = 8
        Width = 118
        Height = 13
        Caption = 'Nombre Total de Tâches'
      end
      object Label111: TLabel
        Left = 416
        Top = 8
        Width = 3
        Height = 13
      end
      object Label112: TLabel
        Left = 504
        Top = 8
        Width = 146
        Height = 13
        Caption = 'Nombre de Tâches Visualisées'
      end
      object Label113: TLabel
        Left = 664
        Top = 8
        Width = 3
        Height = 13
      end
      object ZoomP2: TTrackBar
        Left = 32
        Top = 496
        Width = 153
        Height = 30
        Orientation = trHorizontal
        Frequency = 1
        Position = 5
        SelEnd = 0
        SelStart = 0
        TabOrder = 0
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = ZoomP2Change
      end
      object btPL2Help: TButton
        Left = 832
        Top = 4
        Width = 75
        Height = 25
        Caption = 'Aide'
        TabOrder = 1
      end
      object btPrP2: TButton
        Left = 16
        Top = 544
        Width = 81
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 2
        OnClick = btPrP2Click
      end
      object btP2PDF: TButton
        Left = 112
        Top = 544
        Width = 97
        Height = 25
        Caption = 'Fichier PDF'
        TabOrder = 3
        OnClick = btP2PDFClick
      end
      object btRetPlanning2: TButton
        Left = 48
        Top = 576
        Width = 129
        Height = 25
        Caption = 'Préparation Planning'
        TabOrder = 4
        OnClick = btRetPlanning2Click
      end
      object btmemor2: TButton
        Left = 48
        Top = 616
        Width = 129
        Height = 25
        Caption = 'Mémoriser Planning'
        TabOrder = 5
        OnClick = btmemor2Click
      end
    end
    object TabSheet12: TTabSheet
      Caption = 'Planning 3'
      ImageIndex = 12
      OnShow = TabSheet12Show
      object Label94: TLabel
        Left = 24
        Top = 8
        Width = 118
        Height = 13
        Caption = 'Elaboration Planning'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object imP3p: TImage
        Left = 24
        Top = 48
        Width = 185
        Height = 241
        Stretch = True
        OnMouseDown = imP3pMouseDown
      end
      object Label95: TLabel
        Left = 24
        Top = 32
        Width = 42
        Height = 13
        Caption = 'Portrait'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label96: TLabel
        Left = 8
        Top = 296
        Width = 49
        Height = 13
        Caption = 'Paysage'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object imP3l: TImage
        Left = 8
        Top = 312
        Width = 225
        Height = 161
        Stretch = True
        OnMouseDown = imP3lMouseDown
      end
      object imP3Screen: TImage
        Left = 240
        Top = 56
        Width = 745
        Height = 585
        OnMouseDown = imP3ScreenMouseDown
      end
      object Label97: TLabel
        Left = 50
        Top = 481
        Width = 32
        Height = 13
        Caption = 'Zoom'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label98: TLabel
        Left = 24
        Top = 504
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label99: TLabel
        Left = 192
        Top = 504
        Width = 12
        Height = 13
        Caption = '10'
      end
      object Label68: TLabel
        Left = 288
        Top = 32
        Width = 144
        Height = 13
        Caption = 'Planning / Tri / Filtre Colonnes'
      end
      object LP3FTC: TLabel
        Left = 464
        Top = 32
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label114: TLabel
        Left = 288
        Top = 16
        Width = 118
        Height = 13
        Caption = 'Nombre Total de Tâches'
      end
      object Label115: TLabel
        Left = 448
        Top = 16
        Width = 44
        Height = 13
        Caption = 'Label115'
      end
      object Label116: TLabel
        Left = 520
        Top = 16
        Width = 146
        Height = 13
        Caption = 'Nombre de Tâches Visualisées'
      end
      object Label117: TLabel
        Left = 696
        Top = 16
        Width = 44
        Height = 13
        Caption = 'Label117'
      end
      object btPL3Help: TButton
        Left = 832
        Top = 4
        Width = 75
        Height = 25
        Caption = 'Aide'
        TabOrder = 0
      end
      object ZoomP3: TTrackBar
        Left = 32
        Top = 496
        Width = 153
        Height = 30
        Orientation = trHorizontal
        Frequency = 1
        Position = 5
        SelEnd = 0
        SelStart = 0
        TabOrder = 1
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = ZoomP3Change
      end
      object btPrP3: TButton
        Left = 24
        Top = 536
        Width = 81
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 2
        OnClick = btPrP3Click
      end
      object btP3PDF: TButton
        Left = 120
        Top = 536
        Width = 97
        Height = 25
        Caption = 'Fichier PDF'
        TabOrder = 3
        OnClick = btP3PDFClick
      end
      object btRetPlanning3: TButton
        Left = 48
        Top = 576
        Width = 129
        Height = 25
        Caption = 'Préparation Planning'
        TabOrder = 4
        OnClick = btRetPlanning3Click
      end
      object btMemor3: TButton
        Left = 48
        Top = 616
        Width = 129
        Height = 25
        Caption = 'Mémorisation Planning'
        TabOrder = 5
        OnClick = btMemor3Click
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Rapport en Cours'
      ImageIndex = 5
      OnShow = TabSheet4Show
      object imR1Screen: TImage
        Left = 240
        Top = 56
        Width = 745
        Height = 585
        OnMouseDown = imR1ScreenMouseDown
      end
      object imR1p: TImage
        Left = 24
        Top = 48
        Width = 185
        Height = 241
        Stretch = True
        OnMouseDown = imR1pMouseDown
      end
      object Label23: TLabel
        Left = 24
        Top = 488
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label25: TLabel
        Left = 200
        Top = 488
        Width = 12
        Height = 13
        Caption = '10'
      end
      object Label38: TLabel
        Left = 24
        Top = 32
        Width = 42
        Height = 13
        Caption = 'Portrait'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label35: TLabel
        Left = 50
        Top = 457
        Width = 32
        Height = 13
        Caption = 'Zoom'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label58: TLabel
        Left = 24
        Top = 8
        Width = 109
        Height = 13
        Caption = 'Elaboration rapport'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label59: TLabel
        Left = 288
        Top = 8
        Width = 110
        Height = 13
        Caption = 'Nombre de tâches total'
      end
      object Label60: TLabel
        Left = 504
        Top = 8
        Width = 141
        Height = 13
        Caption = 'Nombre de tâches visualisées'
      end
      object Label61: TLabel
        Left = 416
        Top = 8
        Width = 38
        Height = 13
        Caption = 'Label61'
      end
      object Label62: TLabel
        Left = 664
        Top = 8
        Width = 38
        Height = 13
        Caption = 'Label62'
      end
      object Label75: TLabel
        Left = 16
        Top = 304
        Width = 69
        Height = 13
        Caption = 'Page en cours'
      end
      object Label76: TLabel
        Left = 96
        Top = 304
        Width = 8
        Height = 13
        Caption = '1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label104: TLabel
        Left = 288
        Top = 32
        Width = 149
        Height = 13
        Caption = 'Rapport / Tri / Filtre / Colonnes'
      end
      object LR1FTC: TLabel
        Left = 464
        Top = 32
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object btPrR1: TButton
        Left = 24
        Top = 536
        Width = 81
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 0
        OnClick = btPrR1Click
      end
      object ZoomR1: TTrackBar
        Left = 40
        Top = 480
        Width = 153
        Height = 30
        Orientation = trHorizontal
        Frequency = 1
        Position = 5
        SelEnd = 0
        SelStart = 0
        TabOrder = 1
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = ZoomR1Change
      end
      object btAideRapport1: TButton
        Left = 784
        Top = 2
        Width = 75
        Height = 25
        Caption = 'Aide Rapport'
        TabOrder = 2
      end
      object btPrepR1: TButton
        Left = 56
        Top = 576
        Width = 121
        Height = 25
        Caption = 'Préparation Rapport'
        TabOrder = 3
        OnClick = btPrepR1Click
      end
      object b1Prev: TBitBtn
        Left = 128
        Top = 296
        Width = 41
        Height = 33
        TabOrder = 4
        OnClick = b1PrevClick
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8888888880008888888888888868888880008888888888888668888880008888
          8888888866688888800088888888888666688888800088888888886666688888
          8000888888888666666888888000888888886666666888888000888888866666
          6668888880008888886666666668888880008888866666666668888880008888
          8866666666688888800088888886666666688888800088888888666666688888
          8000888888888666666888888000888888888866666888888000888888888886
          6668888880008888888888886668888880008888888888888668888880008888
          88888888886888888000888888888888888888888000}
      end
      object b1Next: TBitBtn
        Left = 168
        Top = 296
        Width = 41
        Height = 33
        TabOrder = 5
        OnClick = b1NextClick
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8888888880008888886888888888888880008888886688888888888880008888
          8866688888888888800088888866668888888888800088888866666888888888
          8000888888666666888888888000888888666666688888888000888888666666
          6688888880008888886666666668888880008888886666666666888880008888
          8866666666688888800088888866666666888888800088888866666668888888
          8000888888666666888888888000888888666668888888888000888888666688
          8888888880008888886668888888888880008888886688888888888880008888
          88688888888888888000888888888888888888888000}
      end
      object btPDFR1: TButton
        Left = 120
        Top = 536
        Width = 97
        Height = 25
        Caption = 'Fichier PDF'
        TabOrder = 6
      end
      object btMemor4: TButton
        Left = 56
        Top = 616
        Width = 121
        Height = 25
        Caption = 'Mémoriser Rapport'
        TabOrder = 7
        OnClick = btMemor4Click
      end
      object btMiseenPage1: TButton
        Left = 40
        Top = 384
        Width = 153
        Height = 25
        Caption = 'Mise En Page Rapport'
        TabOrder = 8
        OnClick = btMiseenPage1Click
      end
    end
    object TabSheet11: TTabSheet
      Caption = 'Rapport 2'
      ImageIndex = 12
      OnShow = TabSheet11Show
      object imR2Screen: TImage
        Left = 240
        Top = 56
        Width = 745
        Height = 585
        OnMouseDown = imR2ScreenMouseDown
      end
      object imR2p: TImage
        Left = 24
        Top = 48
        Width = 185
        Height = 241
        Stretch = True
        OnMouseDown = imR2pMouseDown
      end
      object Label18: TLabel
        Left = 24
        Top = 8
        Width = 114
        Height = 13
        Caption = 'Elaboration Rapport'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label39: TLabel
        Left = 24
        Top = 32
        Width = 42
        Height = 13
        Caption = 'Portrait'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label83: TLabel
        Left = 16
        Top = 304
        Width = 70
        Height = 13
        Caption = 'Page en Cours'
      end
      object Label84: TLabel
        Left = 96
        Top = 304
        Width = 8
        Height = 13
        Caption = '1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label85: TLabel
        Left = 50
        Top = 465
        Width = 32
        Height = 13
        Caption = 'Zoom'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label86: TLabel
        Left = 24
        Top = 488
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label87: TLabel
        Left = 200
        Top = 488
        Width = 12
        Height = 13
        Caption = '10'
      end
      object Label105: TLabel
        Left = 288
        Top = 32
        Width = 149
        Height = 13
        Caption = 'Rapport / Tri / Filtre / Colonnes'
      end
      object LR2FTC: TLabel
        Left = 464
        Top = 32
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label106: TLabel
        Left = 288
        Top = 8
        Width = 118
        Height = 13
        Caption = 'Nombre Total de Tâches'
      end
      object Label107: TLabel
        Left = 448
        Top = 8
        Width = 3
        Height = 13
      end
      object Label108: TLabel
        Left = 504
        Top = 8
        Width = 146
        Height = 13
        Caption = 'Nombre de Tâches Visualisées'
      end
      object Label109: TLabel
        Left = 664
        Top = 8
        Width = 3
        Height = 13
      end
      object b2Prev: TBitBtn
        Left = 128
        Top = 296
        Width = 41
        Height = 33
        TabOrder = 0
        OnClick = b2PrevClick
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8888888880008888888888888868888880008888888888888668888880008888
          8888888866688888800088888888888666688888800088888888886666688888
          8000888888888666666888888000888888886666666888888000888888866666
          6668888880008888886666666668888880008888866666666668888880008888
          8866666666688888800088888886666666688888800088888888666666688888
          8000888888888666666888888000888888888866666888888000888888888886
          6668888880008888888888886668888880008888888888888668888880008888
          88888888886888888000888888888888888888888000}
      end
      object b2Next: TBitBtn
        Left = 168
        Top = 296
        Width = 41
        Height = 33
        TabOrder = 1
        OnClick = b2NextClick
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8888888880008888886888888888888880008888886688888888888880008888
          8866688888888888800088888866668888888888800088888866666888888888
          8000888888666666888888888000888888666666688888888000888888666666
          6688888880008888886666666668888880008888886666666666888880008888
          8866666666688888800088888866666666888888800088888866666668888888
          8000888888666666888888888000888888666668888888888000888888666688
          8888888880008888886668888888888880008888886688888888888880008888
          88688888888888888000888888888888888888888000}
      end
      object ZoomR2: TTrackBar
        Left = 40
        Top = 480
        Width = 150
        Height = 33
        Orientation = trHorizontal
        Frequency = 1
        Position = 5
        SelEnd = 0
        SelStart = 0
        TabOrder = 2
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = ZoomR2Change
      end
      object btPrR2: TButton
        Left = 32
        Top = 520
        Width = 81
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 3
        OnClick = btPrR2Click
      end
      object btPDFR2: TButton
        Left = 136
        Top = 520
        Width = 81
        Height = 25
        Caption = 'Fichier PDF'
        TabOrder = 4
      end
      object btPrepR2: TButton
        Left = 64
        Top = 560
        Width = 121
        Height = 25
        Caption = 'Préparation Rapport'
        TabOrder = 5
        OnClick = btPrepR2Click
      end
      object btMemor5: TButton
        Left = 64
        Top = 600
        Width = 121
        Height = 25
        Caption = 'Mémoriser rapport'
        TabOrder = 6
        OnClick = btMemor5Click
      end
      object btMiseEnPage2: TButton
        Left = 48
        Top = 384
        Width = 137
        Height = 25
        Caption = 'Mise En Page Rapport'
        TabOrder = 7
        OnClick = btMiseEnPage2Click
      end
    end
    object TabSheet9: TTabSheet
      Caption = 'Couts et Echéancier'
      ImageIndex = 9
      object Label77: TLabel
        Left = 24
        Top = 80
        Width = 159
        Height = 13
        Caption = 'Saisie des Coût des Tâches'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label78: TLabel
        Left = 24
        Top = 312
        Width = 125
        Height = 13
        Caption = 'Echéancier des Coûts'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label79: TLabel
        Left = 24
        Top = 24
        Width = 114
        Height = 13
        Caption = 'Nombre de tâches Total'
      end
      object Label80: TLabel
        Left = 24
        Top = 48
        Width = 161
        Height = 13
        Caption = 'Nombre de Tâches Sélectionnées'
      end
      object avc: TAdvStringGrid
        Left = 24
        Top = 104
        Width = 889
        Height = 177
        Cursor = crDefault
        ColCount = 12
        DefaultColWidth = 26
        DefaultRowHeight = 21
        DefaultDrawing = False
        FixedCols = 1
        RowCount = 5
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
        OnCanEditCell = avcCanEditCell
        OnCellValidate = avcCellValidate
        DragDropSettings.OleAcceptFiles = True
        DragDropSettings.OleAcceptText = True
        SortSettings.AutoColumnMerge = False
        SortSettings.Column = 0
        SortSettings.Show = True
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
        FixedColWidth = 26
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
          'N°'
          'Désignation'
          'Durée'
          'Déb + Tôt'
          'Fin + Tôt'
          'Cout +'
          'Cout --'
          'Critère 1'
          'Critère 2'
          'Critère 3')
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
          26
          26
          152
          31
          54
          56
          73
          72
          54
          51
          51
          10)
      end
      object ave: TAdvStringGrid
        Left = 24
        Top = 344
        Width = 601
        Height = 209
        Cursor = crDefault
        ColCount = 5
        DefaultColWidth = 26
        DefaultRowHeight = 21
        DefaultDrawing = False
        FixedCols = 1
        RowCount = 5
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
        TabOrder = 1
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
        OnGetAlignment = aveGetAlignment
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
        FixedColWidth = 26
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
          'Début'
          'Fin'
          'Montant Prév.'
          'Prév. Cumulé')
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
          26
          57
          59
          80
          91)
      end
      object RadioGroup1: TRadioGroup
        Left = 728
        Top = 344
        Width = 129
        Height = 105
        Caption = 'Echelle'
        TabOrder = 2
      end
      object RadioButton1: TRadioButton
        Left = 752
        Top = 368
        Width = 81
        Height = 17
        Caption = 'Jour'
        TabOrder = 3
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 752
        Top = 392
        Width = 89
        Height = 17
        Caption = 'Semaine'
        TabOrder = 4
        OnClick = RadioButton2Click
      end
      object RadioButton3: TRadioButton
        Left = 752
        Top = 416
        Width = 73
        Height = 17
        Caption = 'Mois'
        TabOrder = 5
        OnClick = RadioButton3Click
      end
      object Button4: TButton
        Left = 760
        Top = 464
        Width = 75
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 6
      end
      object Button5: TButton
        Left = 760
        Top = 504
        Width = 75
        Height = 25
        Caption = 'Export'
        TabOrder = 7
      end
      object Button7: TButton
        Left = 288
        Top = 32
        Width = 129
        Height = 25
        Caption = 'Sauvegarder Couts'
        TabOrder = 8
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 464
        Top = 32
        Width = 97
        Height = 25
        Caption = 'Filtrer Taches'
        TabOrder = 9
        OnClick = Button8Click
      end
      object Button9: TButton
        Left = 608
        Top = 32
        Width = 97
        Height = 25
        Caption = 'Aller Rapports'
        TabOrder = 10
      end
      object RadioGroup2: TRadioGroup
        Left = 168
        Top = 296
        Width = 185
        Height = 41
        TabOrder = 11
      end
      object cbPos: TRadioButton
        Left = 184
        Top = 312
        Width = 73
        Height = 17
        Caption = 'Positif'
        Checked = True
        TabOrder = 12
        TabStop = True
        OnClick = cbPosClick
      end
      object cbNeg: TRadioButton
        Left = 272
        Top = 312
        Width = 73
        Height = 17
        Caption = 'Négatif'
        TabOrder = 13
        OnClick = cbNegClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Actualisation'
      ImageIndex = 2
      TabVisible = False
      object Label5: TLabel
        Left = 136
        Top = 16
        Width = 88
        Height = 13
        Caption = 'Date Selectionnée'
      end
      object Label12: TLabel
        Left = 240
        Top = 16
        Width = 49
        Height = 13
        Caption = '----------  '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object fname: TLabel
        Left = 441
        Top = 16
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label21: TLabel
        Left = 488
        Top = 16
        Width = 135
        Height = 13
        Caption = 'Nombre Tâches concernées'
      end
      object Label22: TLabel
        Left = 632
        Top = 16
        Width = 8
        Height = 13
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label9: TLabel
        Left = 8
        Top = 266
        Width = 152
        Height = 13
        Caption = 'Saisie Actualisation Tache'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label20: TLabel
        Left = 8
        Top = 328
        Width = 84
        Height = 13
        Caption = 'Prédécesseurs'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lAlert: TLabel
        Left = 413
        Top = 296
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lTA: TLabel
        Left = 169
        Top = 296
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lAlertPred: TLabel
        Left = 411
        Top = 376
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object immAct: TImage
        Left = 16
        Top = 424
        Width = 945
        Height = 193
      end
      object Label49: TLabel
        Left = 488
        Top = 0
        Width = 131
        Height = 13
        Caption = 'Nombre de tâches du projet'
      end
      object Label50: TLabel
        Left = 632
        Top = 0
        Width = 6
        Height = 13
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label56: TLabel
        Left = 680
        Top = 0
        Width = 104
        Height = 13
        Caption = 'Date fin prévisionnelle'
      end
      object Label57: TLabel
        Left = 680
        Top = 16
        Width = 65
        Height = 13
        Caption = 'Date fin réelle'
      end
      object asAvanc: TAdvStringGrid
        Left = 8
        Top = 32
        Width = 985
        Height = 225
        Cursor = crDefault
        ColCount = 20
        DefaultColWidth = 21
        DefaultRowHeight = 16
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
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        OnContextPopup = asAvancContextPopup
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
        OnGetCellColor = asAvancGetCellColor
        OnClickCell = asAvancClickCell
        OnCanEditCell = asAvancCanEditCell
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
        FixedRowHeight = 16
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
          21
          28
          117
          41
          67
          63
          60
          56
          67
          80
          74
          88
          65
          59
          21
          21
          21
          21
          21
          21)
      end
      object AdvStringGrid4: TAdvStringGrid
        Left = 8
        Top = 283
        Width = 985
        Height = 38
        Cursor = crDefault
        ColCount = 13
        DefaultRowHeight = 16
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
        TabOrder = 1
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
        OnCanEditCell = AdvStringGrid4CanEditCell
        OnCellValidate = AdvStringGrid4CellValidate
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
        FixedColWidth = 30
        FixedRowHeight = 16
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
          30
          64
          113
          75
          113
          89
          64
          64
          63
          64
          64
          64
          64)
      end
      object AdvStringGrid5: TAdvStringGrid
        Left = 8
        Top = 344
        Width = 985
        Height = 73
        Cursor = crDefault
        ColCount = 16
        DefaultRowHeight = 16
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
        TabOrder = 2
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
        OnCanEditCell = AdvStringGrid5CanEditCell
        OnCellValidate = AdvStringGrid5CellValidate
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
        FixedRowHeight = 16
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
          21
          64
          120
          52
          43
          38
          43
          40
          64
          64
          64
          64
          64
          64
          64
          64)
      end
      object btDatAct: TButton
        Left = 8
        Top = 4
        Width = 105
        Height = 25
        Caption = 'Date Actualisation'
        TabOrder = 3
        OnClick = btDatActClick
      end
      object btSavAct: TButton
        Left = 312
        Top = 4
        Width = 113
        Height = 25
        Caption = 'Sauver Actualisation'
        TabOrder = 4
        OnClick = btSavActClick
      end
      object ScrollBar7: TScrollBar
        Left = 960
        Top = 424
        Width = 17
        Height = 193
        Kind = sbVertical
        PageSize = 0
        TabOrder = 5
      end
      object ScrollBar8: TScrollBar
        Left = 16
        Top = 616
        Width = 945
        Height = 17
        PageSize = 0
        TabOrder = 6
      end
      object Button3: TButton
        Left = 840
        Top = 288
        Width = 99
        Height = 25
        Caption = 'Clear Dateavanc'
        TabOrder = 7
        OnClick = Button3Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Gantt Suivi'
      ImageIndex = 3
      TabVisible = False
      object imAvanc: TImage
        Left = 240
        Top = 40
        Width = 745
        Height = 657
      end
      object imPort: TImage
        Left = 24
        Top = 48
        Width = 185
        Height = 265
        Stretch = True
        OnMouseDown = imPortMouseDown
      end
      object imLand: TImage
        Left = 8
        Top = 336
        Width = 225
        Height = 137
        Stretch = True
        OnMouseDown = imLandMouseDown
      end
      object Label27: TLabel
        Left = 24
        Top = 32
        Width = 42
        Height = 13
        Caption = 'Portrait'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label28: TLabel
        Left = 8
        Top = 320
        Width = 49
        Height = 13
        Caption = 'Paysage'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label24: TLabel
        Left = 26
        Top = 481
        Width = 32
        Height = 13
        Caption = 'Zoom'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label29: TLabel
        Left = 48
        Top = 536
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label30: TLabel
        Left = 168
        Top = 536
        Width = 12
        Height = 13
        Caption = '10'
      end
      object Label51: TLabel
        Left = 24
        Top = 8
        Width = 64
        Height = 13
        Caption = 'Gantt Suivi'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label52: TLabel
        Left = 232
        Top = 16
        Width = 138
        Height = 13
        Caption = 'nbre de tâches total du projet'
      end
      object Label53: TLabel
        Left = 400
        Top = 16
        Width = 38
        Height = 13
        Caption = 'Label46'
      end
      object Label54: TLabel
        Left = 464
        Top = 16
        Width = 141
        Height = 13
        Caption = 'Nombre de tâches visualisées'
      end
      object Label55: TLabel
        Left = 624
        Top = 16
        Width = 38
        Height = 13
        Caption = 'Label48'
      end
      object btPrAvanc: TButton
        Left = 40
        Top = 560
        Width = 153
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 0
        OnClick = btPrAvancClick
      end
      object Zoom: TTrackBar
        Left = 40
        Top = 504
        Width = 153
        Height = 30
        Orientation = trHorizontal
        Frequency = 1
        Position = 5
        SelEnd = 0
        SelStart = 0
        TabOrder = 1
        TickMarks = tmBottomRight
        TickStyle = tsAuto
      end
      object btAideSuivi: TButton
        Left = 752
        Top = 8
        Width = 75
        Height = 25
        Caption = 'Aide Suivi'
        TabOrder = 2
        OnClick = btAideSuiviClick
      end
      object cbEchG: TComboBox
        Left = 48
        Top = 608
        Width = 145
        Height = 73
        Style = csSimple
        ItemHeight = 13
        TabOrder = 3
        Text = 'Jours/Semaines'
        Items.Strings = (
          'Jours/Semaines'
          'Semaines/Mois'
          'Mois/Années')
      end
    end
    object TabSheet13: TTabSheet
      Caption = 'Ressources'
      ImageIndex = 13
      TabVisible = False
    end
    object TabSheet6: TTabSheet
      Caption = 'Renumérotation'
      ImageIndex = 6
      object Label74: TLabel
        Left = 16
        Top = 16
        Width = 224
        Height = 13
        Caption = 'Appliquer le Tri Souhaité avant de Renumeroter'
      end
      object asTri: TAdvStringGrid
        Left = 8
        Top = 48
        Width = 937
        Height = 530
        Cursor = crDefault
        ColCount = 82
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
        OnClickCell = asTriClickCell
        DragDropSettings.OleAcceptFiles = True
        DragDropSettings.OleAcceptText = True
        SortSettings.AutoSortForGrouping = False
        SortSettings.AutoColumnMerge = False
        SortSettings.Column = 71
        SortSettings.Show = True
        SortSettings.IndexShow = False
        SortSettings.IndexColor = clYellow
        SortSettings.Full = True
        SortSettings.SingleColumn = False
        SortSettings.IgnoreBlanks = False
        SortSettings.BlankPos = blFirst
        SortSettings.AutoFormat = False
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
          'N°'
          'Libellé'
          'Durée'
          'Début Pr'
          'Fin Pr'
          ''
          ''
          ''
          ''
          '10'
          ''
          ''
          ''
          ''
          '15'
          ''
          ''
          ''
          ''
          '20'
          ''
          ''
          ''
          ''
          '25'
          ''
          ''
          ''
          ''
          '30'
          ''
          ''
          ''
          ''
          '35'
          ''
          ''
          ''
          ''
          '40'
          'Crit 1'
          'Crit 2'
          'Crit 3'
          ''
          '45'
          ''
          ''
          ''
          ''
          '50'
          ''
          ''
          ''
          ''
          '55'
          ''
          ''
          ''
          ''
          '60')
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
          41
          157
          48
          59
          55
          47
          38
          38
          44
          31
          27
          26
          4
          5
          7
          6
          8
          7
          5
          4
          4
          3
          4
          3
          3
          5
          4
          6
          5
          4
          4
          4
          4
          4
          4
          4
          5
          6
          4
          3
          59
          58
          40
          4
          5
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21
          21)
      end
      object BitBtn3: TBitBtn
        Left = 952
        Top = 304
        Width = 33
        Height = 33
        TabOrder = 1
        OnClick = BitBtn3Click
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
      object BitBtn4: TBitBtn
        Left = 952
        Top = 344
        Width = 33
        Height = 33
        TabOrder = 2
        OnClick = BitBtn4Click
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
      object btRenum: TButton
        Left = 360
        Top = 16
        Width = 75
        Height = 25
        Caption = 'Renuméroter'
        TabOrder = 3
        OnClick = btRenumClick
      end
      object Button2: TButton
        Left = 272
        Top = 16
        Width = 83
        Height = 25
        Caption = 'Tri Préalable'
        TabOrder = 4
        OnClick = Button2Click
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'Virtuel'
      ImageIndex = 10
      object iTest: TImage
        Left = 16
        Top = 200
        Width = 953
        Height = 25
      end
      object sg: TAdvStringGrid
        Left = 8
        Top = 8
        Width = 969
        Height = 105
        Cursor = crDefault
        ColCount = 14
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
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSizing, goColSizing]
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
        ColumnHeaders.Strings = (
          ''
          'Crit1'
          'Crit2'
          'Crit3'
          'N°'
          'Libellé'
          'Dat1'
          'Dat2'
          'Color'
          'Val1'
          'Val2'
          'Val3'
          'Val4')
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
          75
          34
          32
          33
          99
          51
          50
          64
          40
          44
          41
          64
          64)
      end
      object asT: TAdvStringGrid
        Left = 16
        Top = 400
        Width = 969
        Height = 241
        Cursor = crDefault
        ColCount = 20
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
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 1
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
          'Typ'
          'X1'
          'Y1'
          'X2'
          'Y2'
          'Ref'
          'Back'
          'Fore'
          'Epai'
          'FontName'
          'Italic'
          'Bold'
          'Text'
          'Style'
          'X3'
          'Y3'
          'X4'
          'Y4'
          ''
          ''
          ''
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
          30
          32
          32
          28
          36
          37
          39
          46
          67
          49
          41
          118
          64
          54
          48
          49
          46
          21
          21)
      end
      object btReset: TButton
        Left = 56
        Top = 123
        Width = 81
        Height = 25
        Caption = 'Sans Taches'
        TabOrder = 2
        OnClick = btResetClick
      end
      object btTout: TButton
        Left = 152
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Toutes'
        TabOrder = 3
        OnClick = btToutClick
      end
      object btTri: TButton
        Left = 848
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Tri / Critères'
        TabOrder = 4
        OnClick = btTriClick
      end
      object btFiltre: TButton
        Left = 248
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Filtre'
        TabOrder = 5
      end
      object btPrep: TButton
        Left = 344
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Prepare Gr.'
        Enabled = False
        TabOrder = 6
        OnClick = btPrepClick
      end
      object btDrawR: TButton
        Left = 440
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Rapport'
        Enabled = False
        TabOrder = 7
      end
      object btDrawP: TButton
        Left = 536
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Planning'
        TabOrder = 8
      end
      object av: TAdvStringGrid
        Left = 16
        Top = 240
        Width = 961
        Height = 153
        Cursor = crDefault
        ColCount = 80
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
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 9
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
          '0'
          ''
          ''
          ''
          ''
          '5'
          ''
          ''
          ''
          ''
          '10'
          ''
          ''
          ''
          ''
          '15'
          ''
          ''
          ''
          ''
          '20'
          ''
          ''
          ''
          ''
          '25'
          ''
          ''
          ''
          ''
          '30'
          ''
          ''
          ''
          ''
          '35'
          ''
          ''
          ''
          ''
          '40'
          ''
          ''
          ''
          ''
          '45'
          ''
          ''
          ''
          ''
          '50'
          ''
          ''
          ''
          ''
          '55'
          ''
          ''
          ''
          ''
          '60')
        Lookup = False
        LookupCaseSensitive = False
        LookupHistory = False
        BackGround.Top = 0
        BackGround.Left = 0
        BackGround.Display = bdTile
        BackGround.Cells = bcNormal
        Filter = <>
        Version = '2.8.5.0'
      end
      object Button6: TButton
        Left = 56
        Top = 168
        Width = 75
        Height = 25
        Caption = 'Save AV'
        TabOrder = 10
        OnClick = Button6Click
      end
      object Button11: TButton
        Left = 152
        Top = 168
        Width = 105
        Height = 25
        Caption = 'Clear DDS DFS'
        TabOrder = 11
        OnClick = Button11Click
      end
      object Button12: TButton
        Left = 680
        Top = 128
        Width = 75
        Height = 25
        Caption = 'Button12'
        TabOrder = 12
        OnClick = Button12Click
      end
    end
  end
  object PopupList: TPopupMenu
    Left = 976
    Top = 192
    object CocherDcocherTacheencours1: TMenuItem
      Caption = 'Cocher <-> Décocher Tache en cours'
      OnClick = CocherDcocherTacheencours1Click
    end
    object CocherDcocherTches1: TMenuItem
      Caption = 'Cocher <-> Décocher Tâches'
      OnClick = CocherDcocherTches1Click
    end
    object CochertouteslesTaches1: TMenuItem
      Caption = 'Cocher toutes les Taches'
      OnClick = CochertouteslesTaches1Click
    end
    object DcochertouteslesTaches1: TMenuItem
      Caption = 'Décocher toutes les Taches'
      OnClick = DcochertouteslesTaches1Click
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object CopierlesTaches1: TMenuItem
      Caption = 'Copier les Taches Cochées '
      OnClick = CopierlesTaches1Click
    end
    object LierTachesCoches1: TMenuItem
      Caption = 'Lier Taches Cochées'
      OnClick = LierTachesCoches1Click
    end
    object DlierTchesCoches1: TMenuItem
      Caption = 'Délier Tâches Cochées'
      OnClick = DlierTchesCoches1Click
    end
    object SupprimerTchesCoches1: TMenuItem
      Caption = 'Supprimer Tâches Cochées'
      OnClick = SupprimerTchesCoches1Click
    end
    object TachesAmontssurtachesCoches1: TMenuItem
      Caption = 'Taches Amonts sur  Taches Cochées'
      OnClick = TachesAmontssurtachesCoches1Click
    end
    object AffecterunCalendrier1: TMenuItem
      Caption = 'Affecter un Calendrier'
      OnClick = AffecterunCalendrier1Click
    end
    object AffecterDonnesauxTachesCoches1: TMenuItem
      Caption = 'Affecter Données aux Taches Cochées'
      OnClick = AffecterDonnesauxTachesCoches1Click
    end
    object ComplterDsignationTachesCoches1: TMenuItem
      Caption = 'Compléter Désignation Taches Cochées'
      OnClick = ComplterDsignationTachesCoches1Click
    end
    object LierTacheavecPrdcesseurs1: TMenuItem
      Caption = 'Affecter un Prédécesseur aux Taches Cochées'
      OnClick = LierTacheavecPrdcesseurs1Click
    end
    object LiertacheavecSuccesseurs1: TMenuItem
      Caption = 'Affecter un Successeur aux Taches Cochées'
      OnClick = LiertacheavecSuccesseurs1Click
    end
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 976
    Top = 288
  end
  object PopupActiv: TPopupMenu
    Left = 976
    Top = 160
    object A1: TMenuItem
      Caption = 'Tout Cocher'
    end
    object ToutDcocher1: TMenuItem
      Caption = 'Tout Décocher'
    end
    object TachesCochesTermines1: TMenuItem
      Caption = 'Déclarer Taches Cochées Terminées'
    end
    object DclarerTachesCochesNonCommences1: TMenuItem
      Caption = 'Déclarer Taches Cochées Non Commencées'
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 976
    Top = 128
  end
  object PrintDialog1: TPrintDialog
    Left = 976
    Top = 104
  end
  object Timer2: TTimer
    Interval = 100
    OnTimer = Timer2Timer
    Left = 976
    Top = 256
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Options = [fdEffects, fdApplyButton]
    Left = 976
    Top = 72
  end
  object PopupCrit: TPopupMenu
    Left = 976
    Top = 224
    object AffecterCritre1: TMenuItem
      Caption = 'Affecter Critère'
    end
  end
  object PopPlann1: TPopupMenu
    Left = 974
    Top = 320
    object Action11: TMenuItem
      Caption = 'Action1'
    end
    object Action21: TMenuItem
      Caption = 'Action2'
    end
    object Action31: TMenuItem
      Caption = 'Action3'
    end
  end
end
