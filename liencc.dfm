object LienCoche: TLienCoche
  Left = 493
  Top = 322
  BorderStyle = bsSingle
  Caption = 'Lier Taches Cochées'
  ClientHeight = 214
  ClientWidth = 233
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
  object Label1: TLabel
    Left = 144
    Top = 16
    Width = 49
    Height = 13
    Caption = 'Décalage '
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 16
    Width = 121
    Height = 153
    Caption = 'Type de Lien'
    TabOrder = 0
    object RadioButton1: TRadioButton
      Left = 16
      Top = 40
      Width = 81
      Height = 17
      Caption = 'Fin / Debut'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 72
      Width = 89
      Height = 17
      Caption = 'Fin / Fin'
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 16
      Top = 104
      Width = 97
      Height = 17
      Caption = 'Debut-Debut'
      TabOrder = 2
    end
  end
  object Edit1: TEdit
    Left = 144
    Top = 32
    Width = 33
    Height = 21
    TabOrder = 1
    Text = '0'
  end
  object Button1: TButton
    Left = 144
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Exécuter'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 144
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 144
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 4
    OnClick = Button3Click
  end
  object CheckBox1: TCheckBox
    Left = 32
    Top = 184
    Width = 161
    Height = 17
    Caption = 'Décocher après traitement'
    Checked = True
    State = cbChecked
    TabOrder = 5
  end
end
