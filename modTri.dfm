object Tri: TTri
  Left = -30
  Top = 242
  Width = 1382
  Height = 740
  Caption = 'Trier Grouper Tâches'
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
    Left = 8
    Top = 48
    Width = 139
    Height = 13
    Caption = 'Liste des  Tris / Groupements'
  end
  object Label2: TLabel
    Left = 312
    Top = 104
    Width = 66
    Height = 13
    Caption = 'Commentaires'
  end
  object Label3: TLabel
    Left = 320
    Top = 48
    Width = 86
    Height = 13
    Caption = 'Titre Trier Grouper'
  end
  object Label7: TLabel
    Left = 56
    Top = 368
    Width = 148
    Height = 13
    Caption = 'Composition Trier Grouper'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 256
    Top = 136
    Width = 51
    Height = 13
    Caption = 'Préséance'
    Visible = False
  end
  object Label4: TLabel
    Left = 256
    Top = 368
    Width = 124
    Height = 13
    Caption = 'Choix Regroupements'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 464
    Top = 368
    Width = 172
    Height = 13
    Caption = 'Choix Présentation Séparation'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 453
    Top = 368
    Width = 4
    Height = 13
    Caption = '|'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label11: TLabel
    Left = 392
    Top = 368
    Width = 4
    Height = 13
    Caption = '|'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 408
    Top = 368
    Width = 43
    Height = 13
    Caption = 'Tâches'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label10: TLabel
    Left = 16
    Top = 16
    Width = 90
    Height = 13
    Caption = 'Trier / Grouper '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbTri: TListBox
    Left = 16
    Top = 64
    Width = 233
    Height = 241
    ItemHeight = 13
    TabOrder = 0
    OnClick = lbTriClick
  end
  object mTri: TMemo
    Left = 312
    Top = 120
    Width = 257
    Height = 185
    TabOrder = 1
  end
  object btLigne: TButton
    Left = 256
    Top = 328
    Width = 81
    Height = 25
    Caption = 'Ajouter Champ'
    TabOrder = 2
    OnClick = btLigneClick
  end
  object btSupprimer: TButton
    Left = 592
    Top = 128
    Width = 161
    Height = 25
    Caption = 'Supprimer un Tri'
    TabOrder = 3
    OnClick = btSupprimerClick
  end
  object btAppliquer: TButton
    Left = 592
    Top = 64
    Width = 161
    Height = 25
    Caption = 'Appliquer'
    TabOrder = 4
    OnClick = btAppliquerClick
  end
  object btOk: TButton
    Left = 584
    Top = 256
    Width = 57
    Height = 25
    Caption = 'OK'
    TabOrder = 5
    OnClick = btOkClick
  end
  object btAnnul: TButton
    Left = 648
    Top = 256
    Width = 57
    Height = 25
    Caption = 'Annuler'
    TabOrder = 6
    OnClick = btAnnulClick
  end
  object btAide: TButton
    Left = 712
    Top = 256
    Width = 49
    Height = 25
    Caption = 'Aide'
    TabOrder = 7
    OnClick = btAideClick
  end
  object eMemoire: TEdit
    Left = 320
    Top = 64
    Width = 249
    Height = 21
    TabOrder = 8
  end
  object btNew: TButton
    Left = 592
    Top = 96
    Width = 161
    Height = 25
    Caption = 'Nouveau Trier / Grouper'
    TabOrder = 9
    OnClick = btNewClick
  end
  object btMod: TButton
    Left = 352
    Top = 328
    Width = 89
    Height = 25
    Caption = 'Modifier Champ'
    TabOrder = 10
    OnClick = btModClick
  end
  object btDelete: TButton
    Left = 456
    Top = 328
    Width = 89
    Height = 25
    Caption = 'Effacer Champ'
    TabOrder = 11
    OnClick = btDeleteClick
  end
  object asFC: TAdvStringGrid
    Left = 16
    Top = 384
    Width = 681
    Height = 193
    Cursor = crDefault
    ColCount = 14
    DefaultColWidth = 21
    DefaultRowHeight = 21
    RowCount = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goEditing]
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 12
    OnContextPopup = asFCContextPopup
    OnClickCell = asFCClickCell
    ActiveCellFont.Charset = DEFAULT_CHARSET
    ActiveCellFont.Color = clWindowText
    ActiveCellFont.Height = -11
    ActiveCellFont.Name = 'Tahoma'
    ActiveCellFont.Style = [fsBold]
    CellNode.TreeColor = clSilver
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
      198
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
    object AdvStringGrid1: TAdvStringGrid
      Left = -4
      Top = -4
      Width = 681
      Height = 193
      Cursor = crDefault
      ColCount = 14
      DefaultColWidth = 21
      DefaultRowHeight = 21
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
      Visible = False
      OnContextPopup = asFCContextPopup
      OnClickCell = asFCClickCell
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      CellNode.TreeColor = clSilver
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
        207
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
  end
  object btHaut: TBitBtn
    Left = 704
    Top = 432
    Width = 25
    Height = 25
    TabOrder = 13
    OnClick = btHautClick
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
  object btBas: TBitBtn
    Left = 704
    Top = 464
    Width = 25
    Height = 25
    TabOrder = 14
    OnClick = btBasClick
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
  object btMemor: TButton
    Left = 592
    Top = 160
    Width = 161
    Height = 25
    Caption = 'Mémoriser un Tri'
    TabOrder = 15
    OnClick = btMemorClick
  end
  object BitBtn1: TBitBtn
    Left = 272
    Top = 160
    Width = 25
    Height = 25
    TabOrder = 16
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
    Left = 272
    Top = 192
    Width = 25
    Height = 25
    TabOrder = 17
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
  object Button1: TButton
    Left = 592
    Top = 224
    Width = 161
    Height = 25
    Caption = 'Affecter Tri au Rapport en Cours'
    TabOrder = 18
    Visible = False
    OnClick = Button1Click
  end
  object btAffPlann: TButton
    Left = 592
    Top = 192
    Width = 161
    Height = 25
    Caption = 'Affecter au Planning en Cours'
    TabOrder = 19
    OnClick = btAffPlannClick
  end
  object Memo1: TMemo
    Left = 592
    Top = 296
    Width = 161
    Height = 65
    Color = clInfoBk
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Pour enregistrer un Tri, il faut '
      'que la désignation'
      ' commence obligatoirement par '
      'une lettre !!!')
    ParentFont = False
    TabOrder = 20
  end
  object cb1: TCheckBox
    Left = 48
    Top = 336
    Width = 105
    Height = 17
    Caption = 'Tâches Détail'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    State = cbChecked
    TabOrder = 21
    OnClick = cb1Click
  end
  object Button2: TButton
    Left = 72
    Top = 312
    Width = 105
    Height = 17
    Caption = 'Trier la Liste'
    TabOrder = 22
    OnClick = Button2Click
  end
  object ListBox1: TListBox
    Left = 712
    Top = 384
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 23
    Visible = False
  end
  object AdvStringGrid2: TAdvStringGrid
    Left = 840
    Top = 96
    Width = 425
    Height = 120
    Cursor = crDefault
    ColCount = 10
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
    TabOrder = 24
    Visible = False
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
  object Button3: TButton
    Left = 592
    Top = 24
    Width = 161
    Height = 25
    Caption = 'Memoriser Tri Admin'
    TabOrder = 25
    Visible = False
    OnClick = Button3Click
  end
  object Timer1: TTimer
    Interval = 200
    OnTimer = Timer1Timer
    Left = 704
    Top = 8
  end
end
