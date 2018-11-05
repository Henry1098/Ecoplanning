object Champs: TChamps
  Left = 366
  Top = 229
  Width = 397
  Height = 421
  Caption = 'Champs'
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
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 240
    Width = 97
    Height = 13
    Caption = 'Valeur du Champ'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 216
    Top = 240
    Width = 59
    Height = 13
    Caption = 'à Valeur 2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 16
    Top = 8
    Width = 124
    Height = 13
    Caption = 'Critères (*) et Champs'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 216
    Top = 8
    Width = 54
    Height = 13
    Caption = 'Condition'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 24
    Top = 296
    Width = 37
    Height = 13
    Caption = 'Action'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbChamps: TListBox
    Left = 16
    Top = 24
    Width = 185
    Height = 209
    ItemHeight = 13
    TabOrder = 0
  end
  object lbRelation: TListBox
    Left = 216
    Top = 24
    Width = 145
    Height = 161
    ItemHeight = 13
    Items.Strings = (
      'Egal à'
      'Différent de'
      'Inférieur à'
      'Inférieur ou égal à'
      'Supérieur à'
      'Supérieur ou égal à'
      'Compris entre'
      'Non Compris entre'
      'Contient'
      'Ne Contient Pas'
      'Contient Masque'
      'Ne Contient Pas Masque')
    TabOrder = 1
    OnClick = lbRelationClick
  end
  object eDe: TEdit
    Left = 24
    Top = 256
    Width = 153
    Height = 21
    TabOrder = 2
  end
  object eA: TEdit
    Left = 216
    Top = 256
    Width = 145
    Height = 21
    TabOrder = 3
  end
  object lbAction: TListBox
    Left = 24
    Top = 312
    Width = 153
    Height = 57
    ItemHeight = 13
    Items.Strings = (
      'Ajouter'
      'Supprimer'
      'Ajouter Sauf'
      'Supprimer Sauf')
    TabOrder = 4
  end
  object btExec: TButton
    Left = 248
    Top = 288
    Width = 75
    Height = 25
    Caption = 'Exécuter'
    TabOrder = 5
    OnClick = btExecClick
  end
  object btCancel: TButton
    Left = 248
    Top = 320
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 6
    OnClick = btCancelClick
  end
  object btHelp: TButton
    Left = 248
    Top = 352
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 7
    OnClick = btHelpClick
  end
end
