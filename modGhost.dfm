object Ghost: TGhost
  Left = 343
  Top = 254
  Width = 659
  Height = 373
  Caption = 'Ghost'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 56
    Width = 44
    Height = 13
    Caption = 'PopupTL'
  end
  object Label2: TLabel
    Left = 448
    Top = 56
    Width = 30
    Height = 13
    Caption = 'PStyle'
  end
  object Label3: TLabel
    Left = 384
    Top = 56
    Width = 38
    Height = 13
    Caption = 'PEpaiss'
  end
  object Label4: TLabel
    Left = 296
    Top = 56
    Width = 33
    Height = 13
    Caption = 'PLigne'
  end
  object Label5: TLabel
    Left = 200
    Top = 56
    Width = 45
    Height = 13
    Caption = 'PopupST'
  end
  object Label6: TLabel
    Left = 104
    Top = 56
    Width = 45
    Height = 13
    Caption = 'PopupTC'
  end
  object PopupTL: TPopupMenu
    Left = 16
    Top = 16
    object TitreenLigne1: TMenuItem
      Caption = 'Titre en Ligne'
      Checked = True
      OnClick = TitreenLigne1Click
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object Libell1: TMenuItem
      Caption = 'Libellé ...'
      OnClick = Libell1Click
    end
    object PoliceTexte1: TMenuItem
      Caption = 'Police et Couleur Texte'
      OnClick = PoliceTexte1Click
    end
    object HauteurTitreenLigne1: TMenuItem
      Caption = 'Hauteur Titre en Ligne'
      OnClick = HauteurTitreenLigne1Click
    end
    object LigneSparatriceHaute1: TMenuItem
      Caption = 'Ligne Séparatrice Haute'
      OnClick = LigneSparatriceHaute1Click
    end
    object LigneSparatriceBasse1: TMenuItem
      Caption = 'Ligne Séparatrice Basse'
      OnClick = LigneSparatriceBasse1Click
    end
    object CouleurFond1: TMenuItem
      Caption = 'Couleur Fond'
      OnClick = CouleurFond1Click
    end
    object JustificationTexte1: TMenuItem
      Caption = 'Justification Texte'
      OnClick = JustificationTexte1Click
    end
    object RetraitHorizontalTitre1: TMenuItem
      Caption = 'Retrait Horizontal Titre'
      OnClick = RetraitHorizontalTitre1Click
    end
  end
  object PopupTC: TPopupMenu
    Left = 112
    Top = 16
    object TitreenColonne1: TMenuItem
      Caption = 'Titre en Colonne'
      Checked = True
      OnClick = TitreenColonne1Click
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Libell2: TMenuItem
      Caption = 'Libellé'
      OnClick = Libell2Click
    end
    object PoliceetCouleurTexte1: TMenuItem
      Caption = 'Police et Couleur Texte'
      OnClick = PoliceetCouleurTexte1Click
    end
    object HauteurTitreenLigne2: TMenuItem
      Caption = 'Hauteur Titre en Ligne'
      OnClick = HauteurTitreenLigne2Click
    end
    object LigneSparatriceHaute2: TMenuItem
      Caption = 'Ligne Séparatrice Haute'
      OnClick = LigneSparatriceHaute2Click
    end
    object LigneSparatriceBasse2: TMenuItem
      Caption = 'Ligne Séparatrice Basse'
      OnClick = LigneSparatriceBasse2Click
    end
    object CouleurFond2: TMenuItem
      Caption = 'Couleur Fond'
      OnClick = CouleurFond2Click
    end
    object JustificationTexte2: TMenuItem
      Caption = 'Justification Texte'
      OnClick = JustificationTexte2Click
    end
    object RetraitHorizontalTitre2: TMenuItem
      Caption = 'Retrait Horizontal Titre'
      OnClick = RetraitHorizontalTitre2Click
    end
  end
  object PopupST: TPopupMenu
    Left = 200
    Top = 16
    object SansTitre1: TMenuItem
      Caption = 'Sans Titre'
      Checked = True
    end
    object LigneSparatrice1: TMenuItem
      Caption = 'Ligne Séparatrice'
      OnClick = LigneSparatrice1Click
    end
  end
  object PLigne: TPopupMenu
    Left = 296
    Top = 16
    object Ligne1: TMenuItem
      Caption = 'Ligne'
      Checked = True
    end
    object CouleurLigne1: TMenuItem
      Caption = 'Couleur Ligne ...'
      OnClick = CouleurLigne1Click
    end
    object StyleLigne1: TMenuItem
      Caption = 'Style Ligne ...'
      OnClick = StyleLigne1Click
    end
    object EpaisseurLigne1: TMenuItem
      Caption = 'Epaisseur Ligne'
      OnClick = EpaisseurLigne1Click
    end
  end
  object PEpaiss: TPopupMenu
    Left = 384
    Top = 16
    object EpaisseurLigne2: TMenuItem
      Caption = 'Epaisseur Ligne'
      Enabled = False
    end
    object N4: TMenuItem
      Caption = '-'
    end
    object N00mm1: TMenuItem
      Caption = '0,0 mm'
      OnClick = N00mm1Click
    end
    object N010mm1: TMenuItem
      Caption = '0,10 mm'
      OnClick = N010mm1Click
    end
    object N020mm1: TMenuItem
      Caption = '0,20 mm'
      OnClick = N020mm1Click
    end
    object N050mm1: TMenuItem
      Caption = '0,50 mm'
      OnClick = N050mm1Click
    end
    object N080mm1: TMenuItem
      Caption = '0,80 mm'
      OnClick = N080mm1Click
    end
    object N100mm1: TMenuItem
      Caption = '1,00 mm'
      OnClick = N100mm1Click
    end
    object N150mm1: TMenuItem
      Caption = '1,50 mm'
      OnClick = N150mm1Click
    end
    object N200mm1: TMenuItem
      Caption = '2,00 mm'
      OnClick = N200mm1Click
    end
    object N250mm1: TMenuItem
      Caption = '2,50 mm'
      OnClick = N250mm1Click
    end
  end
  object PStyle: TPopupMenu
    Left = 448
    Top = 16
    object StyleLigne2: TMenuItem
      Caption = 'Style Ligne'
      Enabled = False
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object N5: TMenuItem
      Caption = '_____________________'
      OnClick = N5Click
    end
    object N6: TMenuItem
      Caption = '_  _  _  _  _  _  _  _  _  _  _'
      OnClick = N6Click
    end
    object N7: TMenuItem
      Caption = '. . . . . . . . . . . . . . . . . .'
      OnClick = N7Click
    end
    object N8: TMenuItem
      Caption = '_ . _ . _ . _ . _ . _ . _ . _'
      OnClick = N8Click
    end
    object N9: TMenuItem
      Caption = '_ . . _ . . _ . . _ . . _ . . _'
      OnClick = N9Click
    end
  end
  object TFontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 16
    Top = 96
  end
  object CD: TColorDialog
    Ctl3D = True
    Left = 72
    Top = 96
  end
  object PopupCol: TPopupMenu
    Left = 136
    Top = 96
    object PoliceetCouleurTexte2: TMenuItem
      Caption = 'Police et Couleur Texte'
      OnClick = PoliceetCouleurTexte2Click
    end
    object Hauteur1: TMenuItem
      Caption = 'Hauteur'
    end
    object CouleurdeFond1: TMenuItem
      Caption = 'Couleur de Fond'
    end
    object Justification1: TMenuItem
      Caption = 'Justification'
    end
  end
end
