object Renum: TRenum
  Left = 394
  Top = 153
  Width = 539
  Height = 242
  Caption = 'Renum�rotation'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object btYes: TButton
    Left = 416
    Top = 16
    Width = 83
    Height = 25
    Caption = 'Renum�roter'
    TabOrder = 0
    OnClick = btYesClick
  end
  object Annuler: TButton
    Left = 416
    Top = 56
    Width = 83
    Height = 25
    Caption = 'Annuler'
    TabOrder = 1
    OnClick = AnnulerClick
  end
  object Memo1: TMemo
    Left = 24
    Top = 16
    Width = 369
    Height = 169
    Color = clGray
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Lines.Strings = (
      'Avant de renum�roter, il est recommand� de sauvegarder '
      'votre projet sous un autre nom, puisque les num�ros de t�ches'
      'seront modifi�s.'
      ''
      'Vous pouvez ensuite trier :'
      'par date de d�but au plot t�t en cliquant sur le haut de la '
      'colonne,'
      'ou en appliquant un tri pr�-d�fini avec l'#39'outil "trier-grouper"'
      ''
      'La renum�rotation s'#39'effectuera toujours selon l'#39'ordre des '
      't�ches affich�es dans l'#39'onglet de saisie pr�visionnelle.')
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
end
