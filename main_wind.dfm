object mainWnd: TmainWnd
  Left = 394
  Top = 150
  Width = 831
  Height = 545
  Caption = 'wave 1D'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object mainChart: TChart
    Left = 0
    Top = 0
    Width = 609
    Height = 505
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.Maximum = 200
    BottomAxis.Title.Caption = 'x'
    BottomAxis.Title.Font.Charset = DEFAULT_CHARSET
    BottomAxis.Title.Font.Color = clBlack
    BottomAxis.Title.Font.Height = -16
    BottomAxis.Title.Font.Name = 'Arial'
    BottomAxis.Title.Font.Style = [fsBold]
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 1
    LeftAxis.Minimum = -1
    LeftAxis.Title.Angle = 0
    LeftAxis.Title.Caption = 'U'
    LeftAxis.Title.Font.Charset = DEFAULT_CHARSET
    LeftAxis.Title.Font.Color = clBlack
    LeftAxis.Title.Font.Height = -16
    LeftAxis.Title.Font.Name = 'Arial'
    LeftAxis.Title.Font.Style = [fsBold]
    Legend.Visible = False
    RightAxis.Visible = False
    TopAxis.Visible = False
    View3D = False
    TabOrder = 0
    object developer: TStaticText
      Left = 8
      Top = 480
      Width = 154
      Height = 20
      Caption = 'Created by NOTaGrape'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clPurple
      Font.Height = -15
      Font.Name = 'Small Fonts'
      Font.Pitch = fpFixed
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnMouseUp = developerMouseUp
    end
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Style = smsValue
      Marks.Visible = False
      SeriesColor = 16711808
      Title = 'mainSerie'
      Pointer.HorizSize = 2
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.VertSize = 2
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object radioGroupMethods: TRadioGroup
    Left = 616
    Top = 0
    Width = 193
    Height = 81
    Caption = 'Methods'
    Items.Strings = (
      'Explicit Method'
      'Implicit Method')
    TabOrder = 1
    OnClick = radioGroupMethodsClick
  end
  object groupValueSet: TGroupBox
    Left = 616
    Top = 88
    Width = 193
    Height = 169
    BiDiMode = bdLeftToRight
    Caption = 'Values'
    ParentBiDiMode = False
    TabOrder = 2
    object lEditU1: TLabeledEdit
      Left = 32
      Top = 16
      Width = 140
      Height = 21
      EditLabel.Width = 17
      EditLabel.Height = 13
      EditLabel.Caption = 'U1 '
      LabelPosition = lpLeft
      LabelSpacing = 3
      TabOrder = 0
      Text = '0'
    end
    object lEditU2: TLabeledEdit
      Left = 32
      Top = 40
      Width = 140
      Height = 21
      EditLabel.Width = 17
      EditLabel.Height = 13
      EditLabel.Caption = 'U2 '
      LabelPosition = lpLeft
      LabelSpacing = 3
      TabOrder = 1
      Text = '0'
    end
    object lEditDx: TLabeledEdit
      Left = 32
      Top = 64
      Width = 140
      Height = 21
      EditLabel.Width = 14
      EditLabel.Height = 13
      EditLabel.Caption = 'dx '
      LabelPosition = lpLeft
      LabelSpacing = 3
      TabOrder = 2
      Text = '0,1'
    end
    object lEditDt: TLabeledEdit
      Left = 32
      Top = 88
      Width = 140
      Height = 21
      EditLabel.Width = 12
      EditLabel.Height = 13
      EditLabel.Caption = 'dt '
      LabelPosition = lpLeft
      LabelSpacing = 3
      TabOrder = 3
      Text = '0,005'
    end
    object lEditA: TLabeledEdit
      Left = 32
      Top = 112
      Width = 140
      Height = 21
      EditLabel.Width = 9
      EditLabel.Height = 13
      EditLabel.Caption = 'a '
      LabelPosition = lpLeft
      LabelSpacing = 3
      TabOrder = 4
      Text = '1'
    end
    object radioBtnBW: TCheckBox
      Left = 40
      Top = 136
      Width = 113
      Height = 25
      Caption = 'Enable basic wave'
      TabOrder = 5
    end
  end
  object grouEvents: TGroupBox
    Left = 616
    Top = 264
    Width = 193
    Height = 97
    Caption = 'Events'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object labelIterationClock: TLabel
      Left = 2
      Top = 15
      Width = 189
      Height = 80
      Align = alClient
      Alignment = taCenter
      Caption = 'labelIterationClock'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'a_LCDNovaObl'
      Font.Style = []
      ParentFont = False
      Layout = tlCenter
    end
  end
  object buttonReset: TButton
    Left = 616
    Top = 368
    Width = 193
    Height = 41
    Caption = 'Reset'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = buttonResetClick
  end
  object buttonStop: TButton
    Left = 616
    Top = 464
    Width = 193
    Height = 41
    Caption = 'Stop'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = buttonStopClick
  end
  object buttonStart: TButton
    Left = 616
    Top = 416
    Width = 193
    Height = 41
    Caption = 'Start'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = buttonStartClick
  end
end
