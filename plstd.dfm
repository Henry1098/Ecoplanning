object plStandard: TplStandard
  Left = 103
  Top = 207
  Width = 1382
  Height = 788
  Caption = 'x'
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
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1273
    Height = 730
    ActivePage = pl1
    Align = alLeft
    BiDiMode = bdLeftToRight
    MultiLine = True
    ParentBiDiMode = False
    TabOrder = 0
    OnChange = PageControl1Change
    object pl1: TTabSheet
      Caption = 'Ordonnancement t‚ches'
      object Label1: TLabel
        Left = 24
        Top = 0
        Width = 76
        Height = 13
        Caption = 'nbre T‚ches:'
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
        Caption = 'PrÈdÈcesseurs'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 704
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
        Caption = 'T‚che en cours :'
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
        Caption = 'nbre T‚ches CochÈes'
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
        Caption = 'nbreT‚ches FiltrÈes'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label15: TLabel
        Left = 120
        Top = 0
        Width = 12
        Height = 13
        Caption = '__'
      end
      object Label16: TLabel
        Left = 304
        Top = 16
        Width = 12
        Height = 13
        Caption = '__'
      end
      object Label17: TLabel
        Left = 304
        Top = 0
        Width = 15
        Height = 13
        Caption = '__'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
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
        Left = 144
        Top = 408
        Width = 1049
        Height = 225
        Stretch = True
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
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label44: TLabel
        Left = 472
        Top = 16
        Width = 37
        Height = 13
        Caption = '--/--/--'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label19: TLabel
        Left = 8
        Top = 432
        Width = 37
        Height = 13
        Caption = 'T‚che'
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
        Caption = 'Nombre de PrÈdÈcesseurs'
      end
      object Label82: TLabel
        Left = 864
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
        Left = 992
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
      object Label100: TLabel
        Left = 16
        Top = 664
        Width = 29
        Height = 13
        Caption = 'reste :'
      end
      object Label78: TLabel
        Left = 24
        Top = 488
        Width = 61
        Height = 13
        Caption = 'Visualisation '
      end
      object Label144: TLabel
        Left = 24
        Top = 504
        Width = 67
        Height = 13
        Caption = 'de l'#39'ensemble '
      end
      object Label161: TLabel
        Left = 1184
        Top = 40
        Width = 25
        Height = 13
        Caption = 'Zone'
      end
      object Label162: TLabel
        Left = 960
        Top = 184
        Width = 35
        Height = 13
        Caption = 'CritËres'
      end
      object AdvStringGrid1: TAdvStringGrid
        Left = 24
        Top = 32
        Width = 1121
        Height = 241
        Cursor = crDefault
        ColCount = 36
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        PopupMenu = PopupList
        ScrollBars = ssBoth
        TabOrder = 0
        OnContextPopup = AdvStringGrid1ContextPopup
        OnKeyDown = AdvStringGrid1KeyDown
        OnMouseUp = AdvStringGrid1MouseUp
        OnSelectCell = AdvStringGrid1SelectCell
        OnGetAlignment = AdvStringGrid1GetAlignment
        OnGetFormat = AdvStringGrid1GetFormat
        OnClickCell = AdvStringGrid1ClickCell
        OnCanEditCell = AdvStringGrid1CanEditCell
        OnCellValidate = AdvStringGrid1CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        MouseActions.RowSelect = True
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        ScrollSynch = True
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SelectionColor = clSilver
        SortSettings.Show = True
        Version = '3.5.1.1'
        ColWidths = (
          21
          39
          240
          43
          53
          53
          53
          53
          0
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
          21
          21
          21
          42
          42
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
      object AdvStringGrid2: TAdvStringGrid
        Left = 24
        Top = 296
        Width = 593
        Height = 97
        Cursor = crDefault
        ColCount = 8
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 1
        OnKeyDown = AdvStringGrid2KeyDown
        OnSelectCell = AdvStringGrid2SelectCell
        OnClickCell = AdvStringGrid2ClickCell
        OnCanEditCell = AdvStringGrid2CanEditCell
        OnCellValidate = AdvStringGrid2CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
        ColWidths = (
          21
          33
          135
          41
          256
          40
          40
          48)
      end
      object AdvStringGrid3: TAdvStringGrid
        Left = 680
        Top = 296
        Width = 513
        Height = 97
        Cursor = crDefault
        ColCount = 9
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 2
        OnKeyDown = AdvStringGrid3KeyDown
        OnSelectCell = AdvStringGrid3SelectCell
        OnClickCell = AdvStringGrid3ClickCell
        OnCanEditCell = AdvStringGrid3CanEditCell
        OnCellValidate = AdvStringGrid3CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SortSettings.Column = 7
        Version = '3.5.1.1'
        ColWidths = (
          21
          33
          220
          37
          60
          33
          36
          36
          127)
      end
      object SB1: TScrollBar
        Left = 120
        Top = 408
        Width = 17
        Height = 225
        Kind = sbVertical
        Max = 10
        PageSize = 0
        TabOrder = 3
        OnScroll = SB1Scroll
      end
      object btSauver: TButton
        Left = 800
        Top = 4
        Width = 75
        Height = 25
        Caption = 'Sauvegarder'
        TabOrder = 4
        OnClick = btSauverClick
      end
      object btSauverComme: TButton
        Left = 888
        Top = 4
        Width = 121
        Height = 25
        Caption = 'Sauvegarder Comme'
        TabOrder = 5
        OnClick = btSauverCommeClick
      end
      object btAideS: TButton
        Left = 1160
        Top = 4
        Width = 75
        Height = 25
        Caption = 'Aide Saisie'
        TabOrder = 6
        OnClick = btAideSClick
      end
      object btRenum: TButton
        Left = 1024
        Top = 4
        Width = 75
        Height = 25
        Caption = 'RenumÈroter'
        TabOrder = 7
        OnClick = btRenumClick
      end
      object BitBtn1: TBitBtn
        Left = 1172
        Top = 104
        Width = 27
        Height = 25
        TabOrder = 8
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
        Left = 1172
        Top = 136
        Width = 27
        Height = 25
        TabOrder = 9
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
      object btBcl: TButton
        Left = 1104
        Top = 276
        Width = 75
        Height = 17
        Caption = 'Test Bouclage'
        TabOrder = 10
        OnClick = btBclClick
      end
      object btImportLiens: TButton
        Left = 16
        Top = 592
        Width = 75
        Height = 25
        Caption = 'Import Liens'
        TabOrder = 11
        Visible = False
        OnClick = btImportLiensClick
      end
      object Button31: TButton
        Left = 8
        Top = 528
        Width = 105
        Height = 49
        Caption = 'T‚ches dÈja saisies'
        TabOrder = 12
        OnClick = Button31Click
      end
      object BitBtn5: TBitBtn
        Left = 1160
        Top = 56
        Width = 75
        Height = 25
        Caption = 'Agrandir/Red'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 13
        OnClick = BitBtn5Click
      end
      object BitBtn6: TBitBtn
        Left = 1152
        Top = 200
        Width = 105
        Height = 25
        Caption = 'Cout et Ressources'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 14
        OnClick = BitBtn6Click
      end
      object BitBtn7: TBitBtn
        Left = 1168
        Top = 232
        Width = 75
        Height = 25
        Caption = 'CritËres'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 15
        OnClick = BitBtn7Click
      end
      object BitBtn11: TBitBtn
        Left = 1160
        Top = 168
        Width = 97
        Height = 25
        Caption = 'Export Centralisation'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 16
        Visible = False
        OnClick = BitBtn11Click
      end
      object Button48: TButton
        Left = 1200
        Top = 328
        Width = 75
        Height = 25
        Caption = 'Button48'
        TabOrder = 17
        Visible = False
        OnClick = Button48Click
      end
      object Button413: TButton
        Left = 600
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Tache mËre'
        TabOrder = 18
        OnClick = Button413Click
      end
      object Button49: TButton
        Left = 1152
        Top = 80
        Width = 75
        Height = 25
        Caption = 'Button49'
        TabOrder = 19
        Visible = False
        OnClick = Button49Click
      end
      object Button50: TButton
        Left = 1192
        Top = 368
        Width = 75
        Height = 25
        Caption = 'Button50'
        TabOrder = 20
        Visible = False
      end
      object Button51: TButton
        Left = 1192
        Top = 440
        Width = 75
        Height = 25
        Caption = 'Button51'
        TabOrder = 21
        Visible = False
        OnClick = Button51Click
      end
      object Button53: TButton
        Left = 1200
        Top = 288
        Width = 75
        Height = 25
        Caption = 'Button53'
        TabOrder = 22
        Visible = False
        OnClick = Button53Click
      end
      object Button57: TButton
        Left = 696
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Button57'
        TabOrder = 23
        OnClick = Button57Click
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Affectation CritËres'
      ImageIndex = 5
      OnHide = TabSheet5Hide
      OnShow = TabSheet5Show
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
        Caption = 'Nombre de t‚ches'
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
        Caption = 'DÈsignation'
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
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        OnContextPopup = asCritContextPopup
        OnMouseUp = asCritMouseUp
        OnSelectCell = asCritSelectCell
        OnClickCell = asCritClickCell
        OnCanEditCell = asCritCanEditCell
        OnCellValidate = asCritCellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
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
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
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
      object btSaveAffect: TButton
        Left = 880
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
        Caption = 'AccËs CritËres'
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
        OnClick = btAideCritClick
      end
      object btEraseCrit: TButton
        Left = 24
        Top = 608
        Width = 185
        Height = 25
        Caption = 'Tous les CritËres de T‚ches ÅEBlanc'
        TabOrder = 4
        OnClick = btEraseCritClick
      end
      object btCrit1: TButton
        Left = 224
        Top = 608
        Width = 177
        Height = 25
        Caption = 'Suppr. Crit. 1  T‚ches CochÈes'
        TabOrder = 5
        OnClick = btCrit1Click
      end
      object btCrit2: TButton
        Left = 424
        Top = 608
        Width = 153
        Height = 25
        Caption = 'Supp. Crit 2 T‚ches CochÈes'
        TabOrder = 6
        OnClick = btCrit2Click
      end
      object btCrit3: TButton
        Left = 600
        Top = 608
        Width = 169
        Height = 25
        Caption = 'Suppr. Crit 3 T‚ches CochÈes'
        TabOrder = 7
        OnClick = btCrit3Click
      end
      object btCrit4: TButton
        Left = 784
        Top = 608
        Width = 169
        Height = 25
        Caption = 'Suppr. Crit 4 T‚ches CochÈes'
        TabOrder = 8
        OnClick = btCrit4Click
      end
      object BitBtn8: TBitBtn
        Left = 776
        Top = 16
        Width = 97
        Height = 25
        Caption = 'Revenir en arriËre'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 9
        OnClick = BitBtn8Click
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Gantt PrÈvision'
      ImageIndex = 1
      OnShow = TabSheet1Show
      object imGantt: TImage
        Left = 200
        Top = 48
        Width = 753
        Height = 569
        Stretch = True
        OnMouseDown = imGanttMouseDown
        OnMouseMove = imGanttMouseMove
      end
      object Label2: TLabel
        Left = 8
        Top = 16
        Width = 105
        Height = 13
        Caption = 'Gantt PrÈvisionnel'
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
        Left = 208
        Top = 16
        Width = 154
        Height = 13
        Caption = 'Nombre de t‚ches total du projet'
      end
      object Label46: TLabel
        Left = 376
        Top = 16
        Width = 12
        Height = 13
        Caption = '__'
      end
      object Label47: TLabel
        Left = 464
        Top = 16
        Width = 170
        Height = 13
        Caption = 'Nombre de t‚ches visualisÈes'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label48: TLabel
        Left = 640
        Top = 16
        Width = 15
        Height = 13
        Caption = '__'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label69: TLabel
        Left = 26
        Top = 401
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
        Left = 168
        Top = 440
        Width = 12
        Height = 13
        Caption = '10'
        OnDblClick = Label71DblClick
      end
      object Label141: TLabel
        Left = 280
        Top = 624
        Width = 41
        Height = 13
        Caption = 'Planning'
      end
      object Label142: TLabel
        Left = 336
        Top = 624
        Width = 44
        Height = 13
        Caption = 'Label142'
      end
      object btAideGantt: TButton
        Left = 720
        Top = 8
        Width = 75
        Height = 25
        Caption = 'Aide Gantt'
        TabOrder = 0
        OnClick = btAideGanttClick
      end
      object ZoomP0: TTrackBar
        Left = 16
        Top = 424
        Width = 145
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
      object ComboBox1: TComboBox
        Left = 120
        Top = 624
        Width = 145
        Height = 17
        Style = csSimple
        ItemHeight = 13
        TabOrder = 2
        Text = 'Jours/Semaines'
        Visible = False
        Items.Strings = (
          'Jours/Semaines'
          'Semaines/Mois'
          'Mois/AnnÈes')
      end
      object btImpGantt: TButton
        Left = 16
        Top = 520
        Width = 161
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 3
        OnClick = btImpGanttClick
      end
      object btEchelle: TButton
        Left = 16
        Top = 456
        Width = 153
        Height = 25
        Caption = 'Hauteur entre T‚ches'
        TabOrder = 4
        Visible = False
        OnClick = btEchelleClick
      end
      object Button13: TButton
        Left = 16
        Top = 488
        Width = 161
        Height = 25
        Caption = 'PrÈparation Planning'
        TabOrder = 5
        OnClick = Button13Click
      end
      object btPreview: TButton
        Left = 16
        Top = 288
        Width = 145
        Height = 25
        Caption = 'AperÁu Projet Plein Ecran'
        TabOrder = 6
        OnClick = btPreviewClick
      end
      object RadioGroup2: TRadioGroup
        Left = 8
        Top = 320
        Width = 177
        Height = 81
        Caption = 'Plannings Standards'
        TabOrder = 7
      end
      object rbGantt: TRadioButton
        Left = 16
        Top = 344
        Width = 137
        Height = 17
        Caption = 'Ordonnancement Gantt'
        TabOrder = 8
        OnClick = rbGanttClick
      end
      object rbCompr: TRadioButton
        Left = 16
        Top = 368
        Width = 161
        Height = 17
        Caption = 'Ordonnancement Compress'
        Checked = True
        TabOrder = 9
        TabStop = True
        OnClick = rbComprClick
      end
      object Button122: TButton
        Left = 808
        Top = 8
        Width = 75
        Height = 25
        Caption = 'CompressÈ'
        TabOrder = 10
        OnClick = Button122Click
      end
      object Button1: TButton
        Left = 1024
        Top = 264
        Width = 75
        Height = 25
        Caption = 'Button1'
        TabOrder = 11
        Visible = False
        OnClick = Button1Click
      end
    end
    object TabSheet8: TTabSheet
      Caption = 'Planning en Cours'
      ImageIndex = 8
      OnShow = TabSheet8Show
      object imP1Screen: TImage
        Left = 240
        Top = 56
        Width = 713
        Height = 569
        Stretch = True
        OnMouseDown = imP1ScreenMouseDown
      end
      object imP1p: TImage
        Left = 32
        Top = 48
        Width = 177
        Height = 225
        IncrementalDisplay = True
        Stretch = True
        OnMouseDown = imP1pMouseDown
      end
      object imP1l: TImage
        Left = 8
        Top = 320
        Width = 225
        Height = 153
        Stretch = True
        OnMouseDown = imP1lMouseDown
      end
      object Label36: TLabel
        Left = 30
        Top = 592
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label37: TLabel
        Left = 200
        Top = 592
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
        Top = 569
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
        Visible = False
      end
      object Label64: TLabel
        Left = 240
        Top = 8
        Width = 118
        Height = 13
        Caption = 'Nombre Total de T‚ches'
      end
      object Label65: TLabel
        Left = 376
        Top = 8
        Width = 12
        Height = 13
        Caption = '__'
      end
      object Label66: TLabel
        Left = 440
        Top = 8
        Width = 114
        Height = 13
        Caption = 'T‚ches  VisualisÈes'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label67: TLabel
        Left = 576
        Top = 8
        Width = 15
        Height = 13
        Caption = '__'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label107: TLabel
        Left = 240
        Top = 626
        Width = 105
        Height = 13
        Caption = 'Coefficient Ajustement'
        Visible = False
      end
      object Label116: TLabel
        Left = 96
        Top = 408
        Width = 77
        Height = 13
        Caption = 'Mode Portrait'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object Label103: TLabel
        Left = 240
        Top = 32
        Width = 97
        Height = 13
        Caption = 'Date dÈbut de projet'
      end
      object Label109: TLabel
        Left = 376
        Top = 32
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label114: TLabel
        Left = 440
        Top = 32
        Width = 96
        Height = 13
        Caption = 'Date de fin de projet'
      end
      object Label117: TLabel
        Left = 576
        Top = 32
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label136: TLabel
        Left = 1016
        Top = 626
        Width = 26
        Height = 13
        Caption = 'Ajust.'
        Visible = False
      end
      object btPrP1: TButton
        Left = 16
        Top = 624
        Width = 81
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 0
        OnClick = btPrP1Click
      end
      object ZoomP1: TTrackBar
        Left = 40
        Top = 584
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
        Top = 512
        Width = 113
        Height = 25
        Caption = 'PrÈparation Planning'
        TabOrder = 2
        OnClick = btRetPlanning1Click
      end
      object btP1PDF: TButton
        Left = 112
        Top = 624
        Width = 89
        Height = 25
        Caption = 'Fichier PDF'
        TabOrder = 3
        OnClick = btP1PDFClick
      end
      object Button10: TButton
        Left = 928
        Top = 12
        Width = 75
        Height = 25
        Caption = 'Aide'
        TabOrder = 4
        OnClick = Button10Click
      end
      object btMemor1: TButton
        Left = 56
        Top = 544
        Width = 105
        Height = 25
        Caption = 'MÈmoriser Planning'
        TabOrder = 5
        OnClick = btMemor1Click
      end
      object cbP1Form: TComboBox
        Left = 176
        Top = 8
        Width = 57
        Height = 21
        ItemHeight = 13
        TabOrder = 6
        Text = 'A4'
        Visible = False
        Items.Strings = (
          'A4'
          'A3'
          'A2'
          'A1'
          'A0')
      end
      object edAjust: TEdit
        Left = 992
        Top = 624
        Width = 25
        Height = 21
        TabOrder = 7
        Text = '1.0'
        Visible = False
      end
      object Button26: TButton
        Left = 752
        Top = 12
        Width = 153
        Height = 25
        Hint = 'RÈ-afficher le planning avec les nouvelles dates'
        Caption = 'Choisir une pÈriode du projet'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 8
        OnClick = Button26Click
      end
      object Button28: TButton
        Left = 40
        Top = 480
        Width = 153
        Height = 25
        Caption = 'AperÁu Projet Plein Ecran'
        TabOrder = 9
        OnClick = Button28Click
      end
      object BitBtn9: TBitBtn
        Left = 968
        Top = 504
        Width = 113
        Height = 25
        Caption = 'Description Corps'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 10
        OnClick = BitBtn9Click
      end
      object BitBtn10: TBitBtn
        Left = 968
        Top = 472
        Width = 113
        Height = 25
        Caption = 'Description Taches'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 11
        OnClick = BitBtn10Click
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
        Visible = False
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
        Top = 560
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label92: TLabel
        Left = 184
        Top = 560
        Width = 12
        Height = 13
        Caption = '10'
      end
      object imP2Screen: TImage
        Left = 240
        Top = 56
        Width = 713
        Height = 569
        Stretch = True
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
        Top = 537
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
        Left = 232
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
        Left = 232
        Top = 8
        Width = 118
        Height = 13
        Caption = 'Nombre Total de T‚ches'
      end
      object Label111: TLabel
        Left = 392
        Top = 8
        Width = 12
        Height = 13
        Caption = '__'
      end
      object Label112: TLabel
        Left = 504
        Top = 8
        Width = 175
        Height = 13
        Caption = 'Nombre de T‚ches VisualisÈes'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label113: TLabel
        Left = 696
        Top = 8
        Width = 15
        Height = 13
        Caption = '__'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label108: TLabel
        Left = 248
        Top = 628
        Width = 105
        Height = 13
        Caption = 'Coefficient Ajustement'
        Visible = False
      end
      object Label115: TLabel
        Left = 832
        Top = 632
        Width = 77
        Height = 13
        Caption = 'Mode Portrait'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ZoomP2: TTrackBar
        Left = 32
        Top = 552
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
        OnClick = btPL2HelpClick
      end
      object btPrP2: TButton
        Left = 16
        Top = 592
        Width = 81
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 2
        OnClick = btPrP2Click
      end
      object btP2PDF: TButton
        Left = 112
        Top = 592
        Width = 97
        Height = 25
        Caption = 'Fichier PDF'
        TabOrder = 3
        OnClick = btP2PDFClick
      end
      object btRetPlanning2: TButton
        Left = 112
        Top = 512
        Width = 113
        Height = 25
        Caption = 'PrÈparation Planning'
        TabOrder = 4
        OnClick = btRetPlanning2Click
      end
      object btmemor2: TButton
        Left = 0
        Top = 512
        Width = 105
        Height = 25
        Caption = 'MÈmoriser Planning'
        TabOrder = 5
        OnClick = btmemor2Click
      end
      object edAjust2: TEdit
        Left = 1008
        Top = 624
        Width = 25
        Height = 21
        TabOrder = 6
        Text = '1.0'
        Visible = False
      end
      object Button29: TButton
        Left = 56
        Top = 480
        Width = 137
        Height = 25
        Caption = 'AperÁu Projet Plein Ecran'
        TabOrder = 7
        OnClick = Button29Click
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Rapport en Cours'
      ImageIndex = 5
      TabVisible = False
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
        Caption = 'Nombre de t‚ches total'
      end
      object Label60: TLabel
        Left = 504
        Top = 8
        Width = 141
        Height = 13
        Caption = 'Nombre de t‚ches visualisÈes'
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
        Caption = 'PrÈparation Rapport'
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
        Caption = 'MÈmoriser Rapport'
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
    object TabSheet9: TTabSheet
      Caption = 'Echeancier Co˚ts et Ressources'
      ImageIndex = 9
      OnShow = TabSheet9Show
      object Label77: TLabel
        Left = 24
        Top = 104
        Width = 129
        Height = 13
        Caption = 'Saisie des Ressources'
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
        Caption = 'Nombre de t‚ches Total'
      end
      object Label80: TLabel
        Left = 24
        Top = 48
        Width = 161
        Height = 13
        Caption = 'Nombre de T‚ches SÈlectionnÈes'
      end
      object Label143: TLabel
        Left = 24
        Top = 392
        Width = 186
        Height = 13
        Caption = 'EchÈancier Co˚ts et Ressources'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object avc: TAdvStringGrid
        Left = 8
        Top = 120
        Width = 969
        Height = 249
        Cursor = crDefault
        ColCount = 14
        DefaultColWidth = 26
        DefaultRowHeight = 21
        RowCount = 5
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        OnGetFormat = avcGetFormat
        OnCanEditCell = avcCanEditCell
        OnCellValidate = avcCellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          ''
          'N∞'
          'DÈsignation'
          'DurÈe'
          'DÈb + TÙt'
          'Fin + TÙt'
          'Ress/Jour'
          'Ress/Total'
          'CritËre Ressources'
          'CritËre Phases'
          'CritËre Intervenant'
          'CritËre Tris'
          'Cout/Jour'
          'Cout/Total')
        Filter = <>
        FixedColWidth = 26
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SortSettings.Show = True
        Version = '3.5.1.1'
        ColWidths = (
          26
          26
          152
          31
          54
          56
          79
          80
          121
          128
          81
          126
          70
          86)
        RowHeights = (
          21
          21
          21
          21
          21)
      end
      object ave: TAdvStringGrid
        Left = 24
        Top = 416
        Width = 601
        Height = 209
        Cursor = crDefault
        ColCount = 7
        DefaultColWidth = 26
        DefaultRowHeight = 21
        RowCount = 5
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 1
        OnGetAlignment = aveGetAlignment
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          ''
          'DÈbut'
          'Fin'
          'PrÈv/Jour'
          'CumulÈ')
        Filter = <>
        FixedColWidth = 26
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
        ColWidths = (
          26
          57
          59
          80
          91
          75
          74)
      end
      object Button4: TButton
        Left = 696
        Top = 560
        Width = 113
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 2
        Visible = False
      end
      object Button5: TButton
        Left = 696
        Top = 592
        Width = 113
        Height = 25
        Caption = 'Export Format CSV'
        TabOrder = 3
        OnClick = Button5Click
      end
      object Button7: TButton
        Left = 544
        Top = 32
        Width = 153
        Height = 25
        Caption = 'Sauvegarder Ressources'
        TabOrder = 4
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 752
        Top = 32
        Width = 97
        Height = 25
        Caption = 'Filtrer Taches'
        TabOrder = 5
        OnClick = Button8Click
      end
      object Button9: TButton
        Left = 848
        Top = 80
        Width = 97
        Height = 25
        Caption = 'Aller Rapports'
        TabOrder = 6
        Visible = False
      end
      object Button14: TButton
        Left = 872
        Top = 32
        Width = 75
        Height = 25
        Caption = 'Aide'
        TabOrder = 7
        OnClick = Button14Click
      end
      object cbPos: TCheckBox
        Left = 312
        Top = 384
        Width = 105
        Height = 17
        Caption = 'Co˚t PrÈvisionnel'
        Checked = True
        State = cbChecked
        TabOrder = 8
        Visible = False
        OnClick = cbPosClick
      end
      object RadioGroup1: TRadioGroup
        Left = 688
        Top = 448
        Width = 137
        Height = 97
        Caption = 'Echelle'
        TabOrder = 9
      end
      object RadioButton1: TRadioButton
        Left = 712
        Top = 464
        Width = 65
        Height = 17
        Caption = 'Jour'
        TabOrder = 10
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 712
        Top = 488
        Width = 65
        Height = 17
        Caption = 'Semaine'
        TabOrder = 11
        OnClick = RadioButton2Click
        OnContextPopup = RadioButton2ContextPopup
      end
      object RadioButton3: TRadioButton
        Left = 712
        Top = 512
        Width = 73
        Height = 17
        Caption = 'Mois'
        TabOrder = 12
        OnClick = RadioButton3Click
        OnContextPopup = RadioButton3ContextPopup
      end
      object cbNeg: TCheckBox
        Left = 432
        Top = 384
        Width = 97
        Height = 17
        Caption = 'Co˚t RÈel'
        TabOrder = 13
        Visible = False
        OnClick = cbNegClick
      end
      object RadioGroup3: TRadioGroup
        Left = 280
        Top = 24
        Width = 185
        Height = 81
        Caption = 'Echeancier CÙuts et Ressources'
        TabOrder = 14
      end
      object rbCout: TRadioButton
        Left = 328
        Top = 48
        Width = 113
        Height = 17
        Caption = 'Co˚ts'
        Checked = True
        TabOrder = 15
        TabStop = True
        Visible = False
        OnClick = rbCoutClick
      end
      object rbRess: TRadioButton
        Left = 328
        Top = 72
        Width = 105
        Height = 17
        Caption = 'Ressources'
        TabOrder = 16
        Visible = False
        OnClick = rbRessClick
      end
      object ComboBox2: TComboBox
        Left = 304
        Top = 56
        Width = 145
        Height = 21
        ItemHeight = 13
        TabOrder = 17
        OnChange = ComboBox2Change
        Items.Strings = (
          'Cout Previsionnel'
          'Ressources Previsionnelles'
          'Cout Reel'
          'Ressources Reeles')
      end
      object Button56: TButton
        Left = 1032
        Top = 296
        Width = 153
        Height = 65
        Caption = 'Histogramme et Courbe en S'
        TabOrder = 18
        OnClick = Button56Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Affiner Actualisation'
      ImageIndex = 2
      object Label5: TLabel
        Left = 152
        Top = 16
        Width = 88
        Height = 13
        Caption = 'Date SelectionnÈe'
      end
      object Label12: TLabel
        Left = 256
        Top = 16
        Width = 45
        Height = 13
        Caption = '../../..  '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object fname: TLabel
        Left = 136
        Top = 0
        Width = 5
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object Label21: TLabel
        Left = 352
        Top = 16
        Width = 121
        Height = 13
        Caption = 'Nbre T‚ches concernÈes'
      end
      object Label22: TLabel
        Left = 496
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
        Top = 244
        Width = 257
        Height = 13
        Caption = 'Saisie de l'#39'Actualisation de laTache en cours'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label20: TLabel
        Left = 8
        Top = 296
        Width = 156
        Height = 13
        Caption = 'PrÈdÈcesseurs de la t‚che '
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
      object immGnt: TImage
        Left = 8
        Top = 392
        Width = 945
        Height = 249
      end
      object Label49: TLabel
        Left = 352
        Top = 0
        Width = 87
        Height = 13
        Caption = 'Nbre t‚ches projet'
      end
      object Label50: TLabel
        Left = 496
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
        Left = 544
        Top = 0
        Width = 104
        Height = 13
        Caption = 'Date fin prÈvisionnelle'
      end
      object Label57: TLabel
        Left = 544
        Top = 16
        Width = 65
        Height = 13
        Caption = 'Date fin rÈelle'
      end
      object Label129: TLabel
        Left = 288
        Top = 244
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
      object Label130: TLabel
        Left = 664
        Top = 0
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label131: TLabel
        Left = 664
        Top = 16
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object lRetard: TLabel
        Left = 328
        Top = 244
        Width = 22
        Height = 13
        Caption = '___'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object Label18: TLabel
        Left = 16
        Top = 372
        Width = 104
        Height = 13
        Caption = 'Gantt de la T‚che'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label83: TLabel
        Left = 128
        Top = 372
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
      object Label84: TLabel
        Left = 152
        Top = 372
        Width = 230
        Height = 13
        Caption = 'avec ses PrÈdÈcesseurs et Successeurs'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label133: TLabel
        Left = 288
        Top = 296
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
      object asAvanc: TAdvStringGrid
        Left = 8
        Top = 56
        Width = 985
        Height = 185
        Cursor = crDefault
        ColCount = 27
        DefaultColWidth = 21
        DefaultRowHeight = 16
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goRowSelect]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        OnContextPopup = asAvancContextPopup
        OnSelectCell = asAvancSelectCell
        OnGetCellColor = asAvancGetCellColor
        OnClickCell = asAvancClickCell
        OnCanEditCell = asAvancCanEditCell
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          '0'
          '1'
          '2'
          '3'
          '4'
          '5'
          '6'
          '7'
          '8'
          '9'
          '10'
          '11'
          '12'
          '13'
          '14'
          '15'
          '16'
          '17'
          '18'
          '19'
          '20'
          '21'
          '22'
          '23'
          '24'
          'Code Tache')
        Filter = <>
        FixedColWidth = 21
        FixedRowHeight = 16
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
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
          21
          21
          21
          21
          21
          21
          44
          21)
      end
      object AdvStringGrid4: TAdvStringGrid
        Left = 8
        Top = 259
        Width = 985
        Height = 36
        Cursor = crDefault
        ColCount = 14
        DefaultRowHeight = 16
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 1
        OnClickCell = AdvStringGrid4ClickCell
        OnCanEditCell = AdvStringGrid4CanEditCell
        OnCellValidate = AdvStringGrid4CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          '0'
          '1'
          '2'
          '3'
          '4'
          '5'
          '6'
          '7'
          '8'
          '9'
          '10'
          '11'
          'Code Tache')
        Filter = <>
        FixedColWidth = 30
        FixedRowHeight = 16
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
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
          80
          64)
      end
      object AdvStringGrid5: TAdvStringGrid
        Left = 8
        Top = 312
        Width = 985
        Height = 57
        Cursor = crDefault
        ColCount = 16
        DefaultRowHeight = 16
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 2
        OnCanEditCell = AdvStringGrid5CanEditCell
        OnCellValidate = AdvStringGrid5CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedColWidth = 21
        FixedRowHeight = 16
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
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
        Left = 720
        Top = 4
        Width = 129
        Height = 21
        Caption = 'Sauveg.  Actualisation'
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
        Visible = False
      end
      object Button20: TButton
        Left = 864
        Top = 4
        Width = 89
        Height = 21
        Caption = 'Aide'
        TabOrder = 6
        Visible = False
      end
      object Button25: TButton
        Left = 864
        Top = 32
        Width = 89
        Height = 21
        Caption = 'Visual. Gantt'
        TabOrder = 7
        Visible = False
        OnClick = Button25Click
      end
      object btRAZ: TButton
        Left = 720
        Top = 32
        Width = 129
        Height = 21
        Caption = 'Remise ÅEZÈro'
        TabOrder = 8
        Visible = False
        OnClick = btRAZClick
      end
      object Button33: TButton
        Left = 152
        Top = 32
        Width = 113
        Height = 17
        Caption = 'Choix PÈriode Projet'
        TabOrder = 9
        OnClick = Button33Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Gantt Suivi'
      ImageIndex = 3
      TabVisible = False
      OnShow = TabSheet3Show
      object imAvanc: TImage
        Left = 240
        Top = 48
        Width = 713
        Height = 569
      end
      object imPort: TImage
        Left = 24
        Top = 48
        Width = 185
        Height = 241
        Stretch = True
        OnMouseDown = imPortMouseDown
      end
      object imLand: TImage
        Left = 128
        Top = 624
        Width = 113
        Height = 25
        Stretch = True
        Visible = False
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
      object Label24: TLabel
        Left = 42
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
        Left = 24
        Top = 480
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label30: TLabel
        Left = 184
        Top = 480
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
        Left = 152
        Top = 6
        Width = 90
        Height = 13
        Caption = 'Nbre  t‚ches projet'
      end
      object Label53: TLabel
        Left = 152
        Top = 22
        Width = 38
        Height = 13
        Caption = 'Label46'
      end
      object Label54: TLabel
        Left = 264
        Top = 6
        Width = 117
        Height = 13
        Caption = 'Nbre t‚ches concernÈes'
      end
      object Label55: TLabel
        Left = 264
        Top = 22
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
      object LDatACTU: TLabel
        Left = 32
        Top = 304
        Width = 93
        Height = 13
        Caption = 'Date d'#39'actualisation'
      end
      object Label28: TLabel
        Left = 32
        Top = 344
        Width = 79
        Height = 13
        Caption = 'DÈbut Calendrier'
      end
      object Label39: TLabel
        Left = 32
        Top = 392
        Width = 64
        Height = 13
        Caption = 'Fin Calendrier'
      end
      object Label68: TLabel
        Left = 32
        Top = 320
        Width = 38
        Height = 13
        Caption = 'Label68'
      end
      object Label98: TLabel
        Left = 408
        Top = 6
        Width = 108
        Height = 13
        Caption = 'Date Fin PrÈvisionnelle'
      end
      object Label99: TLabel
        Left = 536
        Top = 6
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label105: TLabel
        Left = 408
        Top = 22
        Width = 73
        Height = 13
        Caption = 'Date Fin RÈelle'
      end
      object Label106: TLabel
        Left = 536
        Top = 22
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label137: TLabel
        Left = 8
        Top = 548
        Width = 91
        Height = 13
        Caption = 'Echelle Horizontale'
      end
      object Label138: TLabel
        Left = 8
        Top = 580
        Width = 79
        Height = 13
        Caption = 'Echelle Verticale'
      end
      object Label139: TLabel
        Left = 168
        Top = 548
        Width = 3
        Height = 13
      end
      object Label140: TLabel
        Left = 168
        Top = 580
        Width = 3
        Height = 13
      end
      object btPrAvanc: TButton
        Left = 8
        Top = 504
        Width = 97
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 0
        OnClick = btPrAvancClick
      end
      object Zoom: TTrackBar
        Left = 32
        Top = 464
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
        OnChange = ZoomChange
      end
      object btAideSuivi: TButton
        Left = 880
        Top = 8
        Width = 75
        Height = 21
        Caption = 'Aide Suivi'
        TabOrder = 2
        OnClick = btAideSuiviClick
      end
      object btPrintPDFAV: TButton
        Left = 120
        Top = 504
        Width = 97
        Height = 25
        Caption = 'Fichier PDF'
        TabOrder = 3
        OnClick = btPrintPDFAVClick
      end
      object Button18: TButton
        Left = 808
        Top = 8
        Width = 59
        Height = 21
        Caption = 'RafraÓchir Graphique'
        TabOrder = 4
        Visible = False
        OnClick = Button18Click
      end
      object cbLB: TCheckBox
        Left = 32
        Top = 440
        Width = 145
        Height = 17
        Caption = 'Lignes BrisÈes'
        Checked = True
        State = cbChecked
        TabOrder = 5
        Visible = False
        OnClick = cbLBClick
      end
      object Button23: TButton
        Left = 616
        Top = 8
        Width = 153
        Height = 21
        Caption = 'Revenir'
        TabOrder = 6
        OnClick = Button23Click
      end
      object cbAvantX: TComboBox
        Left = 32
        Top = 360
        Width = 145
        Height = 21
        ItemHeight = 13
        TabOrder = 7
        Text = '2 Semaines Avant'
        OnChange = cbAvantXChange
        Items.Strings = (
          'DÈbut PrÈvisionnel'
          'DÈbut Actualisation'
          '1 Semaine Avant'
          '2 Semaines Avant'
          '1 Mois Avant')
      end
      object cbApresX: TComboBox
        Left = 32
        Top = 408
        Width = 145
        Height = 21
        ItemHeight = 13
        TabOrder = 8
        Text = '1 Semaine AprËs'
        OnChange = cbApresXChange
        Items.Strings = (
          'Fin Actualisation'
          '1 Semaine AprËs'
          '2 Semaines AprËs'
          '1 Mois AprËs'
          '2 Mois AprËs')
      end
      object edHoriz: TEdit
        Left = 112
        Top = 544
        Width = 41
        Height = 21
        TabOrder = 9
        Text = '0'
      end
      object edVertic: TEdit
        Left = 112
        Top = 576
        Width = 41
        Height = 21
        TabOrder = 10
        Text = '0'
      end
      object Button27: TButton
        Left = 72
        Top = 608
        Width = 75
        Height = 25
        Caption = 'RÈ-afficher'
        TabOrder = 11
        OnClick = Button27Click
      end
    end
    object TabSheet13: TTabSheet
      Caption = 'Ressources'
      ImageIndex = 13
      TabVisible = False
    end
    object TabSheet11: TTabSheet
      Caption = 'Planning Suivi'
      ImageIndex = 13
      OnShow = TabSheet11Show
      object imP3Screen: TImage
        Left = 240
        Top = 56
        Width = 713
        Height = 569
      end
      object imP3p: TImage
        Left = 24
        Top = 48
        Width = 185
        Height = 241
        Stretch = True
        OnMouseDown = imP3pMouseDown
      end
      object Label85: TLabel
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
      object Label86: TLabel
        Left = 240
        Top = 8
        Width = 91
        Height = 13
        Caption = 'Nombre de T‚ches'
        Visible = False
      end
      object Label87: TLabel
        Left = 352
        Top = 8
        Width = 6
        Height = 13
        Caption = '0'
        Visible = False
      end
      object Label94: TLabel
        Left = 416
        Top = 8
        Width = 146
        Height = 13
        Caption = 'Nombre de T‚ches VisualisÈes'
        Visible = False
      end
      object Label97: TLabel
        Left = 576
        Top = 8
        Width = 6
        Height = 13
        Caption = '0'
        Visible = False
      end
      object Label95: TLabel
        Left = 240
        Top = 32
        Width = 100
        Height = 13
        Caption = 'Date DÈbut de Projet'
      end
      object Label96: TLabel
        Left = 416
        Top = 32
        Width = 85
        Height = 13
        Caption = 'Date Fin de Projet'
      end
      object Label134: TLabel
        Left = 352
        Top = 32
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label135: TLabel
        Left = 520
        Top = 32
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object ZoomP3: TTrackBar
        Left = 40
        Top = 472
        Width = 150
        Height = 45
        Orientation = trHorizontal
        Frequency = 1
        Position = 5
        SelEnd = 0
        SelStart = 0
        TabOrder = 0
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = ZoomP3Change
      end
      object btPrepAct: TButton
        Left = 48
        Top = 336
        Width = 137
        Height = 25
        Caption = 'PrÈparation Planning'
        TabOrder = 1
        OnClick = btPrepActClick
      end
      object btPrepAvanc: TButton
        Left = 48
        Top = 576
        Width = 137
        Height = 25
        Caption = 'Preparation Planning'
        TabOrder = 2
        Visible = False
        OnClick = btPrepAvancClick
      end
      object btLBRISEE: TButton
        Left = 32
        Top = 416
        Width = 161
        Height = 25
        Caption = 'Choix des Lignes BrisÈes'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = btLBRISEEClick
      end
      object Button21: TButton
        Left = 32
        Top = 536
        Width = 75
        Height = 25
        Caption = 'Imprimer'
        TabOrder = 4
        OnClick = Button21Click
      end
      object Button22: TButton
        Left = 120
        Top = 536
        Width = 75
        Height = 25
        Caption = 'Fichier PDF'
        TabOrder = 5
        OnClick = Button22Click
      end
      object btChoix: TButton
        Left = 712
        Top = 16
        Width = 161
        Height = 25
        Caption = 'Choix d'#39'une pÈriode du projet'
        TabOrder = 6
        OnClick = btChoixClick
      end
      object Button30: TButton
        Left = 48
        Top = 368
        Width = 137
        Height = 25
        Caption = 'AperÁu ProjetPlein Ecran'
        TabOrder = 7
        OnClick = Button30Click
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'RenumÈrotation'
      ImageIndex = 6
      TabVisible = False
      OnShow = TabSheet6Show
      object Label74: TLabel
        Left = 16
        Top = 16
        Width = 224
        Height = 13
        Caption = 'Appliquer le Tri SouhaitÈ avant de Renumeroter'
      end
      object asTri: TAdvStringGrid
        Left = 8
        Top = 48
        Width = 937
        Height = 530
        Cursor = crDefault
        ColCount = 85
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        OnGetFormat = asTriGetFormat
        OnClickCell = asTriClickCell
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          ''
          'N∞'
          'LibellÈ'
          'DurÈe'
          'DÈbut Pr'
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
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SortSettings.AutoSortForGrouping = False
        SortSettings.Column = 71
        SortSettings.Show = True
        SortSettings.AutoFormat = False
        Version = '3.5.1.1'
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
      object Button2: TButton
        Left = 272
        Top = 16
        Width = 83
        Height = 25
        Caption = 'Tri PrÈalable'
        TabOrder = 3
        OnClick = Button2Click
      end
      object Button15: TButton
        Left = 480
        Top = 16
        Width = 75
        Height = 25
        Caption = 'Fermer Onglet'
        TabOrder = 4
        OnClick = Button15Click
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
      object asT: TAdvStringGrid
        Left = 16
        Top = 544
        Width = 929
        Height = 65
        Cursor = crDefault
        ColCount = 20
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
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
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
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
        TabOrder = 1
        OnClick = btResetClick
      end
      object btTout: TButton
        Left = 152
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Toutes'
        TabOrder = 2
        OnClick = btToutClick
      end
      object btTri: TButton
        Left = 848
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Tri / CritËres'
        TabOrder = 3
        OnClick = btTriClick
      end
      object btFiltre: TButton
        Left = 248
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Filtre'
        TabOrder = 4
      end
      object btPrep: TButton
        Left = 344
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Prepare Gr.'
        Enabled = False
        TabOrder = 5
        OnClick = btPrepClick
      end
      object btDrawR: TButton
        Left = 440
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Rapport'
        Enabled = False
        TabOrder = 6
      end
      object btDrawP: TButton
        Left = 536
        Top = 123
        Width = 75
        Height = 25
        Caption = 'Planning'
        TabOrder = 7
      end
      object av: TAdvStringGrid
        Left = 16
        Top = 240
        Width = 929
        Height = 297
        Cursor = crDefault
        ColCount = 95
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 8
        OnGetFormat = avGetFormat
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
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
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SortSettings.AutoSortForGrouping = False
        SortSettings.Column = 80
        SortSettings.Show = True
        SortSettings.AutoFormat = False
        Version = '3.5.1.1'
      end
      object Button6: TButton
        Left = 56
        Top = 168
        Width = 75
        Height = 25
        Caption = 'Save AV'
        TabOrder = 9
        OnClick = Button6Click
      end
      object Button11: TButton
        Left = 152
        Top = 168
        Width = 105
        Height = 25
        Caption = 'Clear DDS DFS'
        TabOrder = 10
        OnClick = Button11Click
      end
      object Button12: TButton
        Left = 680
        Top = 128
        Width = 75
        Height = 25
        Caption = 'Button12'
        TabOrder = 11
        OnClick = Button12Click
      end
      object Button16: TButton
        Left = 344
        Top = 168
        Width = 75
        Height = 25
        Caption = 'Filesize'
        TabOrder = 12
        OnClick = Button16Click
      end
      object btFilesize: TButton
        Left = 456
        Top = 168
        Width = 75
        Height = 25
        Caption = 'btFilesize'
        TabOrder = 13
        OnClick = btFilesizeClick
      end
      object Button3: TButton
        Left = 568
        Top = 168
        Width = 75
        Height = 25
        Caption = 'Test Bouclage'
        TabOrder = 14
        OnClick = Button3Click
      end
      object Button17: TButton
        Left = 688
        Top = 168
        Width = 75
        Height = 25
        Caption = 'Save Excel'
        TabOrder = 15
        OnClick = Button17Click
      end
    end
    object TabSheet14: TTabSheet
      Caption = 'Actualisation Rapide'
      ImageIndex = 14
      OnShow = TabSheet14Show
      object Label101: TLabel
        Left = 112
        Top = 16
        Width = 86
        Height = 13
        Caption = 'Date Actualisation'
      end
      object Label118: TLabel
        Left = 208
        Top = 16
        Width = 37
        Height = 13
        Caption = '../../..'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label121: TLabel
        Left = 576
        Top = 16
        Width = 64
        Height = 13
        Caption = 'Fin Calendrier'
        Visible = False
      end
      object Label123: TLabel
        Left = 24
        Top = 40
        Width = 151
        Height = 13
        Caption = 'Nombre de T‚ches ConcernÈes'
      end
      object Label124: TLabel
        Left = 208
        Top = 40
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label125: TLabel
        Left = 256
        Top = 40
        Width = 121
        Height = 13
        Caption = 'Date de Fin PrÈvisonnelle'
      end
      object Label126: TLabel
        Left = 392
        Top = 40
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label127: TLabel
        Left = 448
        Top = 40
        Width = 88
        Height = 13
        Caption = 'Date de Fin RÈelle'
      end
      object Label128: TLabel
        Left = 560
        Top = 40
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object imAvGantt: TImage
        Left = 304
        Top = 160
        Width = 929
        Height = 438
      end
      object imAvCal: TImage
        Left = 304
        Top = 120
        Width = 929
        Height = 41
      end
      object Label120: TLabel
        Left = 216
        Top = 84
        Width = 77
        Height = 13
        Caption = 'Reste ‡ Faire'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label119: TLabel
        Left = 296
        Top = 16
        Width = 142
        Height = 13
        Caption = 'DÈbut Calendrier Actualisation'
        Visible = False
      end
      object Label122: TLabel
        Left = 24
        Top = 56
        Width = 130
        Height = 13
        Caption = 'Nombre de T‚che en cours'
      end
      object Label132: TLabel
        Left = 192
        Top = 56
        Width = 6
        Height = 13
        Caption = '0'
      end
      object btDate: TButton
        Left = 24
        Top = 8
        Width = 75
        Height = 25
        Caption = 'Date Actual.'
        TabOrder = 0
        OnClick = btDateClick
      end
      object btSaveActu: TButton
        Left = 1080
        Top = 8
        Width = 105
        Height = 25
        Caption = 'Sauvegarde Actu.'
        TabOrder = 1
        OnClick = btSaveActuClick
      end
      object avact: TAdvStringGrid
        Left = 16
        Top = 98
        Width = 273
        Height = 460
        Cursor = crDefault
        ColCount = 8
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 2
        OnClickCell = avactClickCell
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          ''
          'N∞'
          'DÈsignation'
          '0%'
          '100%')
        Filter = <>
        FixedColWidth = 25
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
        ColWidths = (
          25
          27
          156
          31
          43
          64
          64
          64)
      end
      object avas: TAdvStringGrid
        Left = 304
        Top = 64
        Width = 921
        Height = 49
        Cursor = crDefault
        ColCount = 12
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 3
        OnCanEditCell = avasCanEditCell
        OnCellValidate = avasCellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          ''
          'N∞'
          'DÈsignation'
          '%Rest.'
          'J Rest'
          'Du RÈel.'
          'DÈb+tot R'
          'Fin+tot R'
          'DÈb+Tot P'
          'Fin+Tot P'
          'Retard Tot.'
          'Retard Imp.')
        Filter = <>
        FixedColWidth = 25
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
        ColWidths = (
          25
          35
          120
          51
          43
          79
          77
          73
          72
          76
          90
          89)
      end
      object btDP: TButton
        Left = 816
        Top = 624
        Width = 121
        Height = 17
        Caption = 'Afficher Graphique'
        TabOrder = 4
        Visible = False
        OnClick = btDPClick
      end
      object cbApres: TComboBox
        Left = 648
        Top = 11
        Width = 113
        Height = 21
        ItemHeight = 13
        TabOrder = 5
        Text = '1 Semaine AprËs'
        OnChange = cbApresChange
        Items.Strings = (
          'Fin Actualisation'
          '1 Semaine AprËs'
          '2 Semaines AprËs'
          '1 Mois AprËs')
      end
      object btActRapid: TButton
        Left = 784
        Top = 8
        Width = 161
        Height = 25
        Caption = 'T‚ches en cours'
        TabOrder = 6
        OnClick = btActRapidClick
      end
      object Button19: TButton
        Left = 1192
        Top = 8
        Width = 57
        Height = 25
        Caption = 'Aide'
        TabOrder = 7
      end
      object cbAvant: TComboBox
        Left = 448
        Top = 11
        Width = 113
        Height = 21
        ItemHeight = 13
        TabOrder = 8
        Text = '2 Semaines Avant'
        OnChange = cbAvantChange
        Items.Strings = (
          'DÈbut PrÈvisionnel'
          'DÈbut Actualisation'
          '1 Semaine Avant'
          '2 Semaines Avant'
          '1 Mois Avant')
      end
      object Button24: TButton
        Left = 16
        Top = 72
        Width = 185
        Height = 25
        Caption = 'Visual. Gantt'
        TabOrder = 9
        Visible = False
        OnClick = Button24Click
      end
      object Button32: TButton
        Left = 952
        Top = 8
        Width = 121
        Height = 25
        Caption = 'Choix PÈriode du Projet'
        TabOrder = 10
        OnClick = Button32Click
      end
    end
    object TabSheet12: TTabSheet
      Caption = 'Actualisation Rapide'
      ImageIndex = 14
      TabVisible = False
      object Label145: TLabel
        Left = 152
        Top = 16
        Width = 88
        Height = 13
        Caption = 'Date SelectionnÈe'
      end
      object Label146: TLabel
        Left = 256
        Top = 16
        Width = 45
        Height = 13
        Caption = '../../..  '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label147: TLabel
        Left = 352
        Top = 0
        Width = 87
        Height = 13
        Caption = 'Nbre t‚ches projet'
      end
      object Label148: TLabel
        Left = 352
        Top = 16
        Width = 121
        Height = 13
        Caption = 'Nbre T‚ches concernÈes'
      end
      object Label149: TLabel
        Left = 496
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
      object Label150: TLabel
        Left = 496
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
      object Label151: TLabel
        Left = 544
        Top = 0
        Width = 104
        Height = 13
        Caption = 'Date fin prÈvisionnelle'
      end
      object Label152: TLabel
        Left = 544
        Top = 16
        Width = 65
        Height = 13
        Caption = 'Date fin rÈelle'
      end
      object Label153: TLabel
        Left = 664
        Top = 0
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label154: TLabel
        Left = 664
        Top = 16
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label155: TLabel
        Left = 8
        Top = 260
        Width = 257
        Height = 13
        Caption = 'Saisie de l'#39'Actualisation de laTache en cours'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label156: TLabel
        Left = 288
        Top = 260
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
      object Label157: TLabel
        Left = 328
        Top = 260
        Width = 22
        Height = 13
        Caption = '___'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object Label158: TLabel
        Left = 16
        Top = 372
        Width = 104
        Height = 13
        Caption = 'Gantt de la T‚che'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label159: TLabel
        Left = 128
        Top = 372
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
      object Label160: TLabel
        Left = 152
        Top = 372
        Width = 230
        Height = 13
        Caption = 'avec ses PrÈdÈcesseurs et Successeurs'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Image1: TImage
        Left = 8
        Top = 386
        Width = 945
        Height = 249
      end
      object Button35: TButton
        Left = 8
        Top = 4
        Width = 105
        Height = 25
        Caption = 'Date Actualisation'
        TabOrder = 0
        OnClick = Button35Click
      end
      object Button36: TButton
        Left = 720
        Top = 4
        Width = 129
        Height = 21
        Caption = 'Sauveg.  Actualisation'
        TabOrder = 1
        OnClick = Button36Click
      end
      object Button37: TButton
        Left = 720
        Top = 32
        Width = 129
        Height = 21
        Caption = 'Remise ÅEZÈro'
        TabOrder = 2
        Visible = False
        OnClick = Button37Click
      end
      object Button38: TButton
        Left = 864
        Top = 32
        Width = 89
        Height = 21
        Caption = 'Visual. Gantt'
        TabOrder = 3
        Visible = False
        OnClick = Button38Click
      end
      object Button39: TButton
        Left = 864
        Top = 4
        Width = 89
        Height = 21
        Caption = 'Aide'
        TabOrder = 4
        Visible = False
      end
      object AdvStringGrid6: TAdvStringGrid
        Left = 8
        Top = 56
        Width = 985
        Height = 193
        Cursor = crDefault
        ColCount = 15
        DefaultColWidth = 21
        DefaultRowHeight = 16
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goRowSelect]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 5
        OnContextPopup = AdvStringGrid6ContextPopup
        OnSelectCell = AdvStringGrid6SelectCell
        OnGetCellColor = AdvStringGrid6GetCellColor
        OnClickCell = AdvStringGrid6ClickCell
        OnCanEditCell = AdvStringGrid6CanEditCell
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          '0'
          '1'
          '2'
          '3'
          '4'
          '5'
          '6'
          '7'
          '8'
          '9'
          '10'
          '11'
          '17'
          '18'
          '19'
          '20')
        Filter = <>
        FixedColWidth = 21
        FixedRowHeight = 16
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
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
          21)
      end
      object AdvStringGrid7: TAdvStringGrid
        Left = 8
        Top = 280
        Width = 985
        Height = 63
        Cursor = crDefault
        ColCount = 15
        DefaultRowHeight = 16
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 6
        OnClickCell = AdvStringGrid7ClickCell
        OnCanEditCell = AdvStringGrid7CanEditCell
        OnCellValidate = AdvStringGrid7CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          '0'
          '1'
          '2'
          '3'
          '4'
          '5'
          '6'
          '7'
          '8'
          '9'
          '10'
          '11'
          'Code Tache')
        Filter = <>
        FixedColWidth = 30
        FixedRowHeight = 16
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
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
          80
          64
          64)
      end
      object ScrollBar1: TScrollBar
        Left = 960
        Top = 424
        Width = 17
        Height = 193
        Kind = sbVertical
        PageSize = 0
        TabOrder = 7
        Visible = False
      end
    end
    object TabSheet15: TTabSheet
      Caption = 'Tache mËre'
      ImageIndex = 15
      OnContextPopup = TabSheet15ContextPopup
      object Label178: TLabel
        Left = 96
        Top = 40
        Width = 6
        Height = 13
        Caption = '1'
        Visible = False
      end
      object Label179: TLabel
        Left = 864
        Top = 56
        Width = 44
        Height = 13
        Caption = 'Label179'
        Visible = False
      end
      object Label180: TLabel
        Left = 96
        Top = 24
        Width = 44
        Height = 13
        Caption = 'Label180'
        Visible = False
      end
      object Label181: TLabel
        Left = 88
        Top = 56
        Width = 44
        Height = 13
        Caption = 'Label181'
        Visible = False
      end
      object Label182: TLabel
        Left = 64
        Top = 24
        Width = 226
        Height = 13
        Caption = 'Combien des taches filles souhaitez-vous crÈer?'
      end
      object Label183: TLabel
        Left = 48
        Top = 288
        Width = 65
        Height = 13
        Caption = 'Predecesseur'
        Visible = False
      end
      object Label184: TLabel
        Left = 152
        Top = 288
        Width = 56
        Height = 13
        Caption = 'Successeur'
        Visible = False
      end
      object Label185: TLabel
        Left = 112
        Top = 56
        Width = 57
        Height = 13
        Caption = 'Tache mËre'
      end
      object Label187: TLabel
        Left = 416
        Top = 288
        Width = 52
        Height = 13
        Caption = 'Date de fin'
        Visible = False
      end
      object Label188: TLabel
        Left = 496
        Top = 288
        Width = 72
        Height = 13
        Caption = 'Nombre de suc'
        Visible = False
      end
      object Label189: TLabel
        Left = 600
        Top = 288
        Width = 76
        Height = 13
        Caption = 'Nombre de pred'
        Visible = False
      end
      object Image2: TImage
        Left = 48
        Top = 303
        Width = 1049
        Height = 225
        Stretch = True
      end
      object Label186: TLabel
        Left = 48
        Top = 56
        Width = 63
        Height = 13
        Caption = 'Tache mËre: '
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object AdvStringGrid8: TAdvStringGrid
        Left = 48
        Top = 80
        Width = 961
        Height = 185
        Cursor = crDefault
        ColCount = 8
        DefaultRowHeight = 21
        FixedCols = 0
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        OnKeyDown = AdvStringGrid8KeyDown
        OnClickCell = AdvStringGrid8ClickCell
        OnCanEditCell = AdvStringGrid8CanEditCell
        OnCellValidate = AdvStringGrid8CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          'Designation'
          'DurÈe'
          'Lien'
          'DÈcalage'
          'Code Ressource'
          'Coefficient'
          'Successeur'
          'Code Tache'
          '')
        Filter = <>
        FixedColWidth = 134
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
        ColWidths = (
          134
          83
          81
          64
          118
          84
          74
          104)
      end
      object Button41: TButton
        Left = 488
        Top = 24
        Width = 217
        Height = 25
        Caption = 'Valider et retourner a l'#39'ordonnacment'
        TabOrder = 1
        OnClick = Button41Click
      end
      object Button43: TButton
        Left = 720
        Top = 24
        Width = 75
        Height = 25
        Caption = 'Annuler'
        TabOrder = 2
        OnClick = Button43Click
      end
      object Edit2: TEdit
        Left = 296
        Top = 24
        Width = 57
        Height = 21
        TabOrder = 3
        Text = '0'
      end
      object Button54: TButton
        Left = 368
        Top = 24
        Width = 81
        Height = 25
        Caption = 'CrÈer'
        TabOrder = 4
        OnClick = Button54Click
      end
      object Button52: TButton
        Left = 1032
        Top = 112
        Width = 105
        Height = 49
        Caption = 'Validez les donnÈes'
        TabOrder = 5
        Visible = False
        OnClick = Button52Click
      end
      object Button55: TButton
        Left = 840
        Top = 24
        Width = 105
        Height = 25
        Caption = 'Charger Ressources'
        TabOrder = 6
        OnClick = Button55Click
      end
      object ListBox2: TListBox
        Left = 1032
        Top = 40
        Width = 209
        Height = 225
        ItemHeight = 13
        TabOrder = 7
        OnClick = ListBox2Click
      end
    end
    object TabSheet16: TTabSheet
      Caption = 'TabSheet16'
      ImageIndex = 16
      object Label163: TLabel
        Left = 112
        Top = 16
        Width = 86
        Height = 13
        Caption = 'Date Actualisation'
      end
      object Label164: TLabel
        Left = 208
        Top = 16
        Width = 37
        Height = 13
        Caption = '../../..'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label165: TLabel
        Left = 272
        Top = 16
        Width = 50
        Height = 13
        Caption = 'DÈbut Cal.'
        Visible = False
      end
      object Label166: TLabel
        Left = 456
        Top = 16
        Width = 32
        Height = 13
        Caption = 'Fin Cal'
        Visible = False
      end
      object Label167: TLabel
        Left = 448
        Top = 40
        Width = 88
        Height = 13
        Caption = 'Date de Fin RÈelle'
      end
      object Label168: TLabel
        Left = 560
        Top = 40
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label169: TLabel
        Left = 256
        Top = 40
        Width = 121
        Height = 13
        Caption = 'Date de Fin PrÈvisonnelle'
      end
      object Label170: TLabel
        Left = 392
        Top = 40
        Width = 28
        Height = 13
        Caption = '../../..'
      end
      object Label171: TLabel
        Left = 24
        Top = 40
        Width = 151
        Height = 13
        Caption = 'Nombre de T‚ches ConcernÈes'
      end
      object Label172: TLabel
        Left = 192
        Top = 40
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label173: TLabel
        Left = 24
        Top = 56
        Width = 130
        Height = 13
        Caption = 'Nombre de T‚che en cours'
      end
      object Label174: TLabel
        Left = 192
        Top = 56
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label175: TLabel
        Left = 216
        Top = 84
        Width = 77
        Height = 13
        Caption = 'Reste ‡ Faire'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Image5: TImage
        Left = 304
        Top = 160
        Width = 929
        Height = 438
      end
      object Image6: TImage
        Left = 304
        Top = 120
        Width = 929
        Height = 41
      end
      object ButtonDate: TButton
        Left = 24
        Top = 8
        Width = 75
        Height = 25
        Caption = 'Date Actual.'
        TabOrder = 0
      end
      object ComboBox3: TComboBox
        Left = 328
        Top = 11
        Width = 113
        Height = 21
        ItemHeight = 13
        TabOrder = 1
        Text = '2 Semaines Avant'
        Visible = False
        OnChange = cbAvantChange
        Items.Strings = (
          'DÈbut PrÈvisionnel'
          'DÈbut Actualisation'
          '1 Semaine Avant'
          '2 Semaines Avant'
          '1 Mois Avant')
      end
      object ComboBox4: TComboBox
        Left = 496
        Top = 11
        Width = 113
        Height = 21
        ItemHeight = 13
        TabOrder = 2
        Text = '1 Semaine AprËs'
        Visible = False
        OnChange = cbApresChange
        Items.Strings = (
          'Fin Actualisation'
          '1 Semaine AprËs'
          '2 Semaines AprËs'
          '1 Mois AprËs')
      end
      object ButtonTache: TButton
        Left = 632
        Top = 8
        Width = 185
        Height = 25
        Caption = 'T‚ches en cours'
        TabOrder = 3
        OnClick = ButtonTacheClick
      end
      object ButtonPeriode: TButton
        Left = 832
        Top = 8
        Width = 121
        Height = 25
        Caption = 'Choix PÈriode du Projet'
        TabOrder = 4
      end
      object ButtonSauve: TButton
        Left = 960
        Top = 8
        Width = 105
        Height = 25
        Caption = 'Sauvegarde Actu.'
        TabOrder = 5
      end
      object Button42: TButton
        Left = 1072
        Top = 8
        Width = 89
        Height = 25
        Caption = 'Aide'
        TabOrder = 6
      end
      object ButtonVis: TButton
        Left = 16
        Top = 72
        Width = 185
        Height = 25
        Caption = 'Visual. Gantt'
        TabOrder = 7
        Visible = False
        OnClick = Button24Click
      end
      object AdvStringGrid11: TAdvStringGrid
        Left = 304
        Top = 64
        Width = 921
        Height = 49
        Cursor = crDefault
        ColCount = 12
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 8
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          ''
          'N∞'
          'DÈsignation'
          '%Rest.'
          'J Rest'
          'Du RÈel.'
          'DÈb+tot R'
          'Fin+tot R'
          'DÈb+Tot P'
          'Fin+Tot P'
          'Retard Tot.'
          'Retard Imp.')
        Filter = <>
        FixedColWidth = 25
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
        ColWidths = (
          25
          35
          120
          51
          43
          79
          77
          73
          72
          76
          90
          89)
      end
      object AdvStringGrid12: TAdvStringGrid
        Left = 16
        Top = 98
        Width = 273
        Height = 460
        Cursor = crDefault
        ColCount = 8
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 9
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        ColumnHeaders.Strings = (
          ''
          'N∞'
          'DÈsignation'
          '0%'
          '100%')
        Filter = <>
        FixedColWidth = 25
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
        ColWidths = (
          25
          27
          156
          31
          43
          64
          64
          64)
      end
      object Button44: TButton
        Left = 816
        Top = 624
        Width = 121
        Height = 17
        Caption = 'Afficher Graphique'
        TabOrder = 10
        Visible = False
        OnClick = btDPClick
      end
    end
    object TabSheet17: TTabSheet
      Caption = 'TabSheet17'
      ImageIndex = 17
      object AdvStringGrid9: TAdvStringGrid
        Left = 16
        Top = 32
        Width = 1073
        Height = 241
        Cursor = crDefault
        ColCount = 31
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goEditing]
        ParentFont = False
        PopupMenu = PopupList
        ScrollBars = ssBoth
        TabOrder = 0
        OnContextPopup = AdvStringGrid1ContextPopup
        OnKeyDown = AdvStringGrid1KeyDown
        OnMouseUp = AdvStringGrid1MouseUp
        OnSelectCell = AdvStringGrid1SelectCell
        OnGetAlignment = AdvStringGrid1GetAlignment
        OnGetFormat = AdvStringGrid1GetFormat
        OnClickCell = AdvStringGrid1ClickCell
        OnCanEditCell = AdvStringGrid1CanEditCell
        OnCellValidate = AdvStringGrid1CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        MouseActions.RowSelect = True
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        ScrollSynch = True
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SelectionColor = clSilver
        SortSettings.Show = True
        Version = '3.5.1.1'
        ColWidths = (
          21
          39
          240
          43
          53
          53
          53
          53
          0
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
          21
          21
          21
          42
          42
          21
          21
          21
          21
          21
          21
          21)
      end
      object Button133: TButton
        Left = 1168
        Top = 136
        Width = 75
        Height = 25
        Caption = 'Button133'
        TabOrder = 1
        OnClick = Button133Click
      end
    end
    object TabSheet18: TTabSheet
      Caption = 'TabSheet18'
      ImageIndex = 18
      object AdvStringGrid10: TAdvStringGrid
        Left = 24
        Top = 32
        Width = 1121
        Height = 241
        Cursor = crDefault
        ColCount = 36
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        PopupMenu = PopupList
        ScrollBars = ssBoth
        TabOrder = 0
        OnContextPopup = AdvStringGrid1ContextPopup
        OnKeyDown = AdvStringGrid1KeyDown
        OnMouseUp = AdvStringGrid1MouseUp
        OnSelectCell = AdvStringGrid1SelectCell
        OnGetAlignment = AdvStringGrid1GetAlignment
        OnGetFormat = AdvStringGrid1GetFormat
        OnClickCell = AdvStringGrid1ClickCell
        OnCanEditCell = AdvStringGrid1CanEditCell
        OnCellValidate = AdvStringGrid1CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        MouseActions.RowSelect = True
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        ScrollSynch = True
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SelectionColor = clSilver
        SortSettings.Show = True
        Version = '3.5.1.1'
        ColWidths = (
          21
          39
          240
          43
          53
          53
          53
          53
          0
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
          21
          21
          21
          42
          42
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
    end
    object TabSheet19: TTabSheet
      Caption = 'TabSheet19'
      ImageIndex = 19
      object AdvStringGrid13: TAdvStringGrid
        Left = 24
        Top = 32
        Width = 1121
        Height = 241
        Cursor = crDefault
        ColCount = 36
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        PopupMenu = PopupList
        ScrollBars = ssBoth
        TabOrder = 0
        OnContextPopup = AdvStringGrid1ContextPopup
        OnKeyDown = AdvStringGrid1KeyDown
        OnMouseUp = AdvStringGrid1MouseUp
        OnSelectCell = AdvStringGrid1SelectCell
        OnGetAlignment = AdvStringGrid1GetAlignment
        OnGetFormat = AdvStringGrid1GetFormat
        OnClickCell = AdvStringGrid1ClickCell
        OnCanEditCell = AdvStringGrid1CanEditCell
        OnCellValidate = AdvStringGrid1CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        MouseActions.RowSelect = True
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        ScrollSynch = True
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SelectionColor = clSilver
        SortSettings.Show = True
        Version = '3.5.1.1'
        ColWidths = (
          21
          39
          240
          43
          53
          53
          53
          53
          0
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
          21
          21
          21
          42
          42
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
      object Button34: TButton
        Left = 120
        Top = 312
        Width = 177
        Height = 25
        Caption = 'Export Centralisation'
        TabOrder = 1
        OnClick = Button34Click
      end
      object Button40: TButton
        Left = 336
        Top = 312
        Width = 153
        Height = 25
        Caption = 'Import Centralisation'
        TabOrder = 2
        OnClick = Button40Click
      end
      object AdvStringGrid14: TAdvStringGrid
        Left = 656
        Top = 336
        Width = 473
        Height = 120
        Cursor = crDefault
        DefaultRowHeight = 21
        FixedCols = 0
        RowCount = 5
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected]
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 3
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        Version = '3.5.1.1'
      end
    end
    object TabSheet20: TTabSheet
      Caption = 'TabSheet20'
      ImageIndex = 20
      object Label176: TLabel
        Left = 56
        Top = 16
        Width = 253
        Height = 13
        Caption = 'Veuillez selectionner le fichier de centralisation voulue'
      end
      object Label177: TLabel
        Left = 632
        Top = 296
        Width = 58
        Height = 13
        Caption = 'Visualisation'
      end
      object ListBox1: TListBox
        Left = 32
        Top = 32
        Width = 289
        Height = 265
        ItemHeight = 13
        TabOrder = 0
        OnClick = ListBox1Click
      end
      object Edit1: TEdit
        Left = 392
        Top = 48
        Width = 193
        Height = 21
        TabOrder = 1
        Text = 'Edit1'
      end
      object Button45: TButton
        Left = 440
        Top = 152
        Width = 75
        Height = 25
        Caption = 'Valider'
        TabOrder = 2
        OnClick = Button45Click
      end
      object Button46: TButton
        Left = 440
        Top = 184
        Width = 75
        Height = 25
        Caption = 'Annuler'
        TabOrder = 3
        OnClick = Button46Click
      end
      object AdvStringGrid15: TAdvStringGrid
        Left = 40
        Top = 328
        Width = 1121
        Height = 241
        Cursor = crDefault
        ColCount = 19
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        PopupMenu = PopupList
        ScrollBars = ssBoth
        TabOrder = 4
        OnContextPopup = AdvStringGrid1ContextPopup
        OnKeyDown = AdvStringGrid1KeyDown
        OnMouseUp = AdvStringGrid1MouseUp
        OnSelectCell = AdvStringGrid1SelectCell
        OnGetAlignment = AdvStringGrid1GetAlignment
        OnGetFormat = AdvStringGrid1GetFormat
        OnClickCell = AdvStringGrid1ClickCell
        OnCanEditCell = AdvStringGrid1CanEditCell
        OnCellValidate = AdvStringGrid1CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        MouseActions.RowSelect = True
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        ScrollSynch = True
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SelectionColor = clSilver
        SortSettings.Show = True
        Version = '3.5.1.1'
        ColWidths = (
          21
          39
          240
          43
          53
          53
          53
          53
          0
          82
          47
          65
          62
          40
          49
          54
          50
          69
          41)
      end
      object Button47: TButton
        Left = 384
        Top = 120
        Width = 193
        Height = 25
        Caption = 'Visualiser les taches'
        TabOrder = 5
        OnClick = Button47Click
      end
    end
    object TabSheet21: TTabSheet
      Caption = 'TabSheet21'
      ImageIndex = 21
      object AdvStringGrid16: TAdvStringGrid
        Left = 24
        Top = 32
        Width = 1121
        Height = 241
        Cursor = crDefault
        ColCount = 36
        DefaultColWidth = 21
        DefaultRowHeight = 21
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing]
        ParentFont = False
        PopupMenu = PopupList
        ScrollBars = ssBoth
        TabOrder = 0
        OnContextPopup = AdvStringGrid1ContextPopup
        OnKeyDown = AdvStringGrid1KeyDown
        OnMouseUp = AdvStringGrid1MouseUp
        OnSelectCell = AdvStringGrid1SelectCell
        OnGetAlignment = AdvStringGrid1GetAlignment
        OnGetFormat = AdvStringGrid1GetFormat
        OnClickCell = AdvStringGrid1ClickCell
        OnCanEditCell = AdvStringGrid1CanEditCell
        OnCellValidate = AdvStringGrid1CellValidate
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        CellNode.TreeColor = clSilver
        Filter = <>
        FixedColWidth = 21
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        MouseActions.RowSelect = True
        PrintSettings.DateFormat = 'dd/mm/yyyy'
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
        PrintSettings.PageNumSep = '/'
        ScrollSynch = True
        SearchFooter.FindNextCaption = 'Find next'
        SearchFooter.FindPrevCaption = 'Find previous'
        SearchFooter.Font.Charset = DEFAULT_CHARSET
        SearchFooter.Font.Color = clWindowText
        SearchFooter.Font.Height = -11
        SearchFooter.Font.Name = 'MS Sans Serif'
        SearchFooter.Font.Style = []
        SearchFooter.HighLightCaption = 'Highlight'
        SearchFooter.HintClose = 'Close'
        SearchFooter.HintFindNext = 'Find next occurence'
        SearchFooter.HintFindPrev = 'Find previous occurence'
        SearchFooter.HintHighlight = 'Highlight occurences'
        SearchFooter.MatchCaseCaption = 'Match case'
        SelectionColor = clSilver
        SortSettings.Show = True
        Version = '3.5.1.1'
        ColWidths = (
          21
          39
          240
          43
          53
          53
          53
          53
          0
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
          21
          21
          21
          42
          42
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
      object Memo1: TMemo
        Left = 64
        Top = 352
        Width = 185
        Height = 89
        TabOrder = 1
      end
      object Memo2: TMemo
        Left = 352
        Top = 352
        Width = 185
        Height = 89
        TabOrder = 2
      end
      object Memo3: TMemo
        Left = 632
        Top = 352
        Width = 185
        Height = 89
        TabOrder = 3
      end
    end
    object TabSheet22: TTabSheet
      Caption = 'Histogramme et Courbe enS'
      ImageIndex = 22
      object Chart1: TChart
        Left = 16
        Top = 16
        Width = 753
        Height = 505
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        MarginBottom = 0
        MarginLeft = 0
        MarginRight = 0
        Title.Text.Strings = (
          'Histogramme')
        View3D = False
        TabOrder = 0
        object Series1: TBarSeries
          Marks.ArrowLength = 20
          Marks.Visible = True
          SeriesColor = clRed
          BarWidthPercent = 100
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
      object Chart2: TChart
        Left = 808
        Top = 56
        Width = 400
        Height = 377
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Text.Strings = (
          'Courbe en S')
        View3D = False
        TabOrder = 1
        object Series2: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 730
    Width = 1366
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object PopupList: TPopupMenu
    Left = 1000
    Top = 160
    object CocherDcocherTacheencours1: TMenuItem
      Caption = 'Cocher <-> DÈcocher Tache en cours'
      OnClick = CocherDcocherTacheencours1Click
    end
    object CocherDcocherTches1: TMenuItem
      Caption = 'Cocher <-> DÈcocher T‚ches'
      OnClick = CocherDcocherTches1Click
    end
    object CochertouteslesTaches1: TMenuItem
      Caption = 'Cocher toutes les Taches'
      OnClick = CochertouteslesTaches1Click
    end
    object DcochertouteslesTaches1: TMenuItem
      Caption = 'DÈcocher toutes les Taches'
      OnClick = DcochertouteslesTaches1Click
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object CopierlesTaches1: TMenuItem
      Caption = 'Copier les Taches CochÈes '
      OnClick = CopierlesTaches1Click
    end
    object LierTachesCoches1: TMenuItem
      Caption = 'Lier Taches CochÈes'
      OnClick = LierTachesCoches1Click
    end
    object DlierTchesCoches1: TMenuItem
      Caption = 'DÈlier T‚ches CochÈes'
      OnClick = DlierTchesCoches1Click
    end
    object SupprimerTchesCoches1: TMenuItem
      Caption = 'Supprimer T‚ches CochÈes'
      OnClick = SupprimerTchesCoches1Click
    end
    object TachesAmontssurtachesCoches1: TMenuItem
      Caption = 'Taches Amonts sur  Taches CochÈes'
      Visible = False
      OnClick = TachesAmontssurtachesCoches1Click
    end
    object AffecterunCalendrier1: TMenuItem
      Caption = 'Affecter un Calendrier'
      OnClick = AffecterunCalendrier1Click
    end
    object AffecterDonnesauxTachesCoches1: TMenuItem
      Caption = 'Affecter DonnÈes aux Taches CochÈes'
      OnClick = AffecterDonnesauxTachesCoches1Click
    end
    object ComplterDsignationTachesCoches1: TMenuItem
      Caption = 'ComplÈter DÈsignation Taches CochÈes'
      OnClick = ComplterDsignationTachesCoches1Click
    end
    object LierTacheavecPrdcesseurs1: TMenuItem
      Caption = 'Affecter un PrÈdÈcesseur aux Taches CochÈes'
      OnClick = LierTacheavecPrdcesseurs1Click
    end
    object LiertacheavecSuccesseurs1: TMenuItem
      Caption = 'Affecter un Successeur aux Taches CochÈes'
      OnClick = LiertacheavecSuccesseurs1Click
    end
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 1216
    Top = 448
  end
  object PopupActiv: TPopupMenu
    Left = 1000
    Top = 128
    object A1: TMenuItem
      Caption = 'Tout Cocher'
    end
    object ToutDcocher1: TMenuItem
      Caption = 'Tout DÈcocher'
    end
    object TachesCochesTermines1: TMenuItem
      Caption = 'DÈclarer Taches CochÈes TerminÈes'
    end
    object DclarerTachesCochesNonCommences1: TMenuItem
      Caption = 'DÈclarer Taches CochÈes Non CommencÈes'
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 1000
    Top = 96
  end
  object PrintDialog1: TPrintDialog
    Left = 1000
    Top = 56
  end
  object Timer2: TTimer
    Interval = 100
    OnTimer = Timer2Timer
    Left = 1000
    Top = 232
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
    Left = 1000
    Top = 16
  end
  object PopupCrit: TPopupMenu
    Left = 1000
    Top = 192
    object AffecterCritre1: TMenuItem
      Caption = 'Affecter CritËre'
      OnClick = AffecterCritre1Click
    end
    object CocherToutesLesTaches2: TMenuItem
      Caption = 'Cocher Toutes Les Taches'
      OnClick = CocherToutesLesTaches2Click
    end
    object DcocherToutesLestaches2: TMenuItem
      Caption = 'DÈcocher Toutes Les taches'
      OnClick = DcocherToutesLestaches2Click
    end
    object CocherDcocher1: TMenuItem
      Caption = 'Cocher <-> DÈcocher'
      OnClick = CocherDcocher1Click
    end
  end
  object PopPlann1: TPopupMenu
    Left = 1150
    Top = 392
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
  object OpenDialog1: TOpenDialog
    Left = 1176
    Top = 376
  end
  object Timer3: TTimer
    Interval = 500
    OnTimer = Timer3Timer
    Left = 1116
    Top = 336
  end
  object Timer4: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer4Timer
    Left = 1112
    Top = 64
  end
  object Timer5: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer5Timer
    Left = 1028
    Top = 40
  end
  object Timer6: TTimer
    Enabled = False
    Interval = 500
    Left = 1156
    Top = 152
  end
  object Timer7: TTimer
    Interval = 300
    OnTimer = Timer7Timer
    Left = 838
    Top = 58
  end
  object SaveDialog2: TSaveDialog
    Filter = 'Ecoplanning 6|*.ecoc'
    Left = 1092
    Top = 250
  end
  object OpenDialog2: TOpenDialog
    Left = 1164
    Top = 298
  end
  object Timer8: TTimer
    Enabled = False
    Interval = 400
    OnTimer = Timer8Timer
    Left = 1212
    Top = 306
  end
  object Timer9: TTimer
    OnTimer = Timer9Timer
    Left = 1252
    Top = 178
  end
  object Timer10: TTimer
    Interval = 500
    OnTimer = Timer10Timer
    Left = 1174
    Top = 92
  end
end
