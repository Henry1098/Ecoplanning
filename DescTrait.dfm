object FDTrait: TFDTrait
  Left = 192
  Top = 140
  Width = 508
  Height = 248
  Caption = 'Descriptif Trait de Séparation'
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
    Left = 40
    Top = 32
    Width = 75
    Height = 13
    Caption = 'Couleur du Trait'
  end
  object Image1: TImage
    Left = 168
    Top = 24
    Width = 105
    Height = 41
    OnClick = Image1Click
  end
  object Label2: TLabel
    Left = 32
    Top = 96
    Width = 85
    Height = 13
    Caption = 'Epaisseur du Trait'
  end
  object Label3: TLabel
    Left = 32
    Top = 144
    Width = 23
    Height = 13
    Caption = 'Style'
  end
  object Label4: TLabel
    Left = 48
    Top = 48
    Width = 66
    Height = 13
    Caption = 'de Séparation'
  end
  object Edit1: TEdit
    Left = 168
    Top = 88
    Width = 41
    Height = 21
    TabOrder = 0
  end
  object ComboBox1: TComboBox
    Left = 160
    Top = 144
    Width = 81
    Height = 21
    ItemHeight = 13
    TabOrder = 1
    Text = '_____________'
    Items.Strings = (
      '__________________'
      '_  _  _  _  _  _'
      '_ . _ . _ . _ . _ .')
  end
  object Button1: TButton
    Left = 376
    Top = 24
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 376
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 376
    Top = 120
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 4
    OnClick = Button3Click
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 312
    Top = 24
  end
end
