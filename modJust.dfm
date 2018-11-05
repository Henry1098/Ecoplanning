object Just: TJust
  Left = 803
  Top = 257
  Width = 318
  Height = 235
  BorderIcons = [biSystemMenu]
  Caption = 'Justification'
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
  object GroupBox1: TGroupBox
    Left = 32
    Top = 24
    Width = 97
    Height = 153
    Caption = 'Horizontal'
    TabOrder = 0
    object RadioButton1: TRadioButton
      Left = 16
      Top = 32
      Width = 73
      Height = 17
      Caption = 'Gauche'
      TabOrder = 0
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 64
      Width = 57
      Height = 17
      Caption = 'Centré'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object RadioButton3: TRadioButton
      Left = 16
      Top = 96
      Width = 57
      Height = 17
      Caption = 'Droite'
      TabOrder = 2
    end
  end
  object btOK: TButton
    Left = 184
    Top = 32
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = btOKClick
  end
  object btAnnul: TButton
    Left = 184
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
    OnClick = btAnnulClick
  end
  object btAide: TButton
    Left = 184
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
    OnClick = btAideClick
  end
end
