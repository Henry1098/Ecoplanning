object FDEspace: TFDEspace
  Left = 212
  Top = 328
  Width = 506
  Height = 201
  Caption = 'Descriptif Espace de Séparation'
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
    Left = 32
    Top = 32
    Width = 75
    Height = 13
    Caption = 'Couleur Espace'
  end
  object Image1: TImage
    Left = 152
    Top = 24
    Width = 113
    Height = 41
    OnClick = Image1Click
  end
  object Label2: TLabel
    Left = 32
    Top = 96
    Width = 103
    Height = 13
    Caption = 'Epaisseur Séparation '
  end
  object Edit1: TEdit
    Left = 152
    Top = 96
    Width = 41
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 384
    Top = 16
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 384
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Annuler'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 384
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Aide'
    TabOrder = 3
    OnClick = Button3Click
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 296
    Top = 24
  end
end
