object Regist: TRegist
  Left = 192
  Top = 122
  Width = 873
  Height = 301
  Caption = 'Registration Form'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 56
    Top = 32
    Width = 54
    Height = 13
    Caption = 'Code Client'
  end
  object Label2: TLabel
    Left = 40
    Top = 80
    Width = 167
    Height = 13
    Caption = 'transmettez ce code à Ecoplanning'
  end
  object Label3: TLabel
    Left = 40
    Top = 96
    Width = 329
    Height = 13
    Caption = 
      'En retour, vous recevrez une Clé Logicielle pour débrider votre ' +
      'logiciel'
  end
  object Label4: TLabel
    Left = 16
    Top = 152
    Width = 274
    Height = 13
    Caption = 'Si elle est connue, entrez votre clé logicielle (sinon quittez)'
  end
  object Label5: TLabel
    Left = 192
    Top = 224
    Width = 32
    Height = 13
    Caption = 'Label5'
    Visible = False
  end
  object Label6: TLabel
    Left = 408
    Top = 224
    Width = 32
    Height = 13
    Caption = 'Label6'
    Visible = False
  end
  object edLK: TEdit
    Left = 16
    Top = 184
    Width = 817
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 16
    Top = 216
    Width = 153
    Height = 25
    Caption = 'Enregistrer la clé'
    TabOrder = 1
    OnClick = Button1Click
  end
  object edMAC: TEdit
    Left = 152
    Top = 28
    Width = 129
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    Text = '00:00:00:00:00:00'
  end
  object Button2: TButton
    Left = 336
    Top = 26
    Width = 75
    Height = 25
    Caption = 'Quitter'
    TabOrder = 3
    OnClick = Button2Click
  end
end
