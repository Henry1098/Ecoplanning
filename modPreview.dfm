object Preview: TPreview
  Left = 155
  Top = 0
  Width = 1125
  Height = 676
  Caption = 'Aperçu'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 176
    Top = 8
    Width = 425
    Height = 425
    OnMouseDown = Image1MouseDown
  end
  object imP1p: TImage
    Left = 32
    Top = 56
    Width = 105
    Height = 145
    Stretch = True
    OnMouseDown = imP1pMouseDown
  end
  object imP1l: TImage
    Left = 8
    Top = 232
    Width = 161
    Height = 105
    Stretch = True
    OnMouseDown = imP1lMouseDown
  end
  object Label1: TLabel
    Left = 24
    Top = 424
    Width = 6
    Height = 13
    Caption = '1'
  end
  object Label2: TLabel
    Left = 152
    Top = 424
    Width = 12
    Height = 13
    Caption = '11'
  end
  object Label3: TLabel
    Left = 64
    Top = 368
    Width = 56
    Height = 13
    Caption = 'Zoom Local'
  end
  object Button1: TButton
    Left = 48
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Fermer'
    TabOrder = 0
    OnClick = Button1Click
  end
  object ZoomP1: TTrackBar
    Left = 16
    Top = 384
    Width = 150
    Height = 33
    Orientation = trHorizontal
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 1
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = ZoomP1Change
  end
  object Memo1: TMemo
    Left = 8
    Top = 480
    Width = 161
    Height = 273
    Color = clWindowFrame
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Cliquer dans le petit graphique'
      'du haut pour afficher le planning'
      'dans la partie droite  avec'
      'la valeur du zoom en cours'
      ''
      'Avec une valeur du zoom local'
      'à 1, la largeur de la page est'
      'totalement cadrée dans le'
      'graphique du planning. On'
      'accède au bas de la page, en'
      'cliquant dans la partie basse'
      'du graphique'
      ''
      'Dans le graphique du planning,'
      'cliquer en haut, en bas, à '
      'gauche, à droite, '
      'ou en diagonale pour'
      'vous déplacer dans le '
      'graphique')
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
end
