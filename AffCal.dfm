object AffectCal: TAffectCal
  Left = 816
  Top = 172
  Width = 451
  Height = 264
  Caption = 'Affecter Calendrier aux Tâches Cochées'
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
  object Label5: TLabel
    Left = 16
    Top = 8
    Width = 124
    Height = 13
    Caption = 'Sélectionner un Calendrier'
  end
  object Label1: TLabel
    Left = 16
    Top = 128
    Width = 66
    Height = 13
    Caption = 'Commentaires'
  end
  object ComboBox1: TComboBox
    Left = 16
    Top = 24
    Width = 145
    Height = 97
    Style = csSimple
    ItemHeight = 13
    TabOrder = 0
    OnChange = ComboBox1Change
  end
  object Memo1: TMemo
    Left = 16
    Top = 144
    Width = 409
    Height = 65
    Enabled = False
    TabOrder = 1
  end
  object Affect: TButton
    Left = 344
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Affecter'
    TabOrder = 2
    OnClick = AffectClick
  end
  object Annul: TButton
    Left = 344
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 3
    OnClick = AnnulClick
  end
  object Aide: TButton
    Left = 344
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 4
    OnClick = AideClick
  end
  object CheckBox1: TCheckBox
    Left = 176
    Top = 20
    Width = 153
    Height = 17
    Caption = 'Décocher après traitement'
    Checked = True
    State = cbChecked
    TabOrder = 5
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 384
  end
end
