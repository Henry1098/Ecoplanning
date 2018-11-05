object Cadre: TCadre
  Left = 431
  Top = 353
  Width = 440
  Height = 312
  Caption = 'Description du Cadre'
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
    Top = 32
    Width = 85
    Height = 13
    Caption = 'Epaisseur du Trait'
  end
  object Label2: TLabel
    Left = 16
    Top = 48
    Width = 34
    Height = 13
    Caption = 'en mm.'
  end
  object Image1: TImage
    Left = 304
    Top = 152
    Width = 105
    Height = 105
  end
  object Button1: TButton
    Left = 24
    Top = 208
    Width = 121
    Height = 25
    Caption = 'Couleur du Cadre'
    TabOrder = 0
    OnClick = Button1Click
  end
  object cbEpaiss: TComboBox
    Left = 128
    Top = 24
    Width = 145
    Height = 137
    Style = csSimple
    ItemHeight = 13
    TabOrder = 1
    Text = '2.00'
    Items.Strings = (
      '0.10'
      '0.20'
      '0.50'
      '0.80'
      '1.00'
      '1.50'
      '2.00'
      '2.50')
  end
  object Button2: TButton
    Left = 328
    Top = 16
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 328
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 328
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 176
    Top = 208
    Width = 89
    Height = 21
    TabOrder = 5
    Text = '0'
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 8
  end
end
