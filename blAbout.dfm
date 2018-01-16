object AboutBox: TAboutBox
  Left = 587
  Top = 339
  BorderStyle = bsDialog
  Caption = 'О программе '
  ClientHeight = 196
  ClientWidth = 336
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 321
    Height = 177
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    object ProductName: TLabel
      Left = 88
      Top = 16
      Width = 156
      Height = 20
      Caption = 'Текстовой редактор'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object Label1: TLabel
      Left = 24
      Top = 42
      Width = 275
      Height = 20
      Caption = 'Выполнил: студент гр. БИСЗУ 11-01'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object Label2: TLabel
      Left = 48
      Top = 71
      Width = 228
      Height = 20
      Caption = 'Пучинин Дмитрий Георгиевич'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object Label3: TLabel
      Left = 120
      Top = 103
      Width = 87
      Height = 13
      Caption = '2 курс 2 семестр'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object Label4: TLabel
      Left = 88
      Top = 119
      Width = 155
      Height = 13
      Caption = 'г. Красноярск 2012 - 2013 год.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
  end
  object OKButton: TButton
    Left = 135
    Top = 148
    Width = 75
    Height = 25
    Caption = 'Закрыть'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
end
