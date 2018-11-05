object Copy: TCopy
  Left = 914
  Top = 201
  Width = 375
  Height = 269
  Caption = 'Copie des Tâches Cochées'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 48
    Width = 46
    Height = 13
    Caption = 'Décalage'
    Enabled = False
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 16
    Width = 129
    Height = 17
    Caption = 'Copier en Cascade'
    TabOrder = 0
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 176
    Top = 16
    Width = 177
    Height = 17
    Caption = 'Cocher les Anciennes Tâches'
    TabOrder = 1
  end
  object CheckBox3: TCheckBox
    Left = 176
    Top = 48
    Width = 169
    Height = 17
    Caption = 'Cocher les Nouvelles Tâches'
    Checked = True
    State = cbChecked
    TabOrder = 2
  end
  object Button1: TButton
    Left = 192
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Exécuter'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 192
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 192
    Top = 176
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 80
    Top = 48
    Width = 33
    Height = 21
    Enabled = False
    TabOrder = 6
    Text = '0'
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 88
    Width = 129
    Height = 121
    Caption = 'Type de Lien'
    Enabled = False
    TabOrder = 7
    object RadioButton1: TRadioButton
      Left = 16
      Top = 24
      Width = 89
      Height = 17
      Caption = 'Fin / Debut'
      Checked = True
      Enabled = False
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 56
      Width = 81
      Height = 17
      Caption = 'Fin / Fin'
      Enabled = False
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 16
      Top = 88
      Width = 89
      Height = 17
      Caption = 'Début /Début'
      Enabled = False
      TabOrder = 2
    end
  end
  object UpDown1: TUpDown
    Left = 120
    Top = 48
    Width = 17
    Height = 25
    Min = 0
    Position = 0
    TabOrder = 8
    Wrap = False
    OnClick = UpDown1Click
  end
end
