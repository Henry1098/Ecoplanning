object Num_Tache_Succ: TNum_Tache_Succ
  Left = 563
  Top = 245
  Width = 306
  Height = 280
  Caption = 'Sucesseurs'
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
    Left = 32
    Top = 48
    Width = 90
    Height = 13
    Caption = 'Num�ro Sucesseur'
  end
  object Label2: TLabel
    Left = 40
    Top = 200
    Width = 46
    Height = 13
    Caption = 'D�calage'
  end
  object Label3: TLabel
    Left = 32
    Top = 24
    Width = 76
    Height = 13
    Caption = 'Tache d'#39'origine '
  end
  object Label4: TLabel
    Left = 120
    Top = 24
    Width = 8
    Height = 13
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 32
    Top = 64
    Width = 65
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 200
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 200
    Top = 16
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 4
    OnClick = Button2Click
  end
  object GroupBox1: TGroupBox
    Left = 32
    Top = 88
    Width = 153
    Height = 89
    Caption = 'Type de Lien'
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 16
      Top = 16
      Width = 113
      Height = 17
      Caption = 'FD (Fin-Debut)'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 40
      Width = 113
      Height = 17
      Caption = 'FF (Fin-Fin)'
      TabOrder = 0
    end
    object RadioButton4: TRadioButton
      Left = 16
      Top = 64
      Width = 113
      Height = 17
      Caption = 'DD (D�but-D�but)'
      TabOrder = 2
    end
  end
  object Edit2: TEdit
    Left = 104
    Top = 192
    Width = 41
    Height = 21
    TabOrder = 2
    Text = '0'
  end
  object UpDown1: TUpDown
    Left = 144
    Top = 192
    Width = 17
    Height = 25
    Min = 0
    Position = 0
    TabOrder = 3
    Wrap = False
    OnClick = UpDown1Click
  end
  object Button3: TButton
    Left = 200
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 6
    OnClick = Button3Click
  end
end