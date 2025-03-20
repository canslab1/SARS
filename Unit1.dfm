object SARS_Form: TSARS_Form
  Left = 157
  Top = 2
  Width = 828
  Height = 735
  Caption = 
    'Simulating SARS: Small-World Epidemiological Modeling and Public' +
    ' Health Policy Assessments, Version 2'
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Times New Roman'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 19
  object Label_Person: TLabel
    Left = 136
    Top = 544
    Width = 50
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = 'person'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
  end
  object Label_Day: TLabel
    Left = 448
    Top = 544
    Width = 20
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = 'day'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
  end
  object Label_Active: TLabel
    Left = 496
    Top = 544
    Width = 33
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = 'times'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
  end
  object Label_FileName: TLabel
    Left = 136
    Top = 648
    Width = 40
    Height = 25
    AutoSize = False
    Caption = 'File'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
  end
  object Label_PeopleState: TLabel
    Left = 8
    Top = 648
    Width = 40
    Height = 25
    AutoSize = False
    Caption = 'Attr.'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 676
    Width = 820
    Height = 25
    Panels = <
      item
        Width = 50
      end
      item
        Width = 50
      end
      item
        Width = 80
      end
      item
        Width = 80
      end
      item
        Width = 80
      end
      item
        Width = 80
      end
      item
        Width = 70
      end
      item
        Width = 70
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object PageControl2: TPageControl
    Left = 528
    Top = 8
    Width = 289
    Height = 665
    ActivePage = TabSheet_PolicySegment1
    Font.Charset = ANSI_CHARSET
    Font.Color = clMaroon
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    TabIndex = 5
    TabOrder = 1
    object TabSheet_SmallWorld: TTabSheet
      Caption = 'Small World'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 5
      ParentFont = False
      object Panel_SmallWorld: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 633
        Color = clMoneyGreen
        TabOrder = 0
        object Label_Count: TLabel
          Left = 184
          Top = 600
          Width = 40
          Height = 25
          Alignment = taCenter
          AutoSize = False
          Caption = 'times'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          Layout = tlCenter
        end
        object Button_SystemWorld: TButton
          Left = 8
          Top = 600
          Width = 130
          Height = 25
          Caption = 'Calculate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clMaroon
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = Button_SmallWorldClick
        end
        object Memo_System: TMemo
          Left = 8
          Top = 8
          Width = 265
          Height = 585
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object Edit_Count: TEdit
          Left = 144
          Top = 600
          Width = 40
          Height = 27
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = '100'
        end
      end
    end
    object TabSheet_System: TTabSheet
      Caption = 'Simulation System'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 3
      ParentFont = False
      object Panel_System: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 633
        Color = clMoneyGreen
        TabOrder = 0
        object CheckBox_OutputFile2: TCheckBox
          Left = 25
          Top = 40
          Width = 180
          Height = 20
          Caption = 'Output to Log File #2'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 0
          OnClick = CheckBox_ContactClick
        end
        object CheckBox_OutputFile3: TCheckBox
          Left = 25
          Top = 72
          Width = 180
          Height = 20
          Caption = 'Output to Log File #3'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 1
          OnClick = CheckBox_ContactClick
        end
        object CheckBox_OutputFile4: TCheckBox
          Left = 25
          Top = 104
          Width = 180
          Height = 20
          Caption = 'Output to Log File #4'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 2
          OnClick = CheckBox_ContactClick
        end
        object CheckBox_OutputFile1: TCheckBox
          Left = 25
          Top = 8
          Width = 180
          Height = 20
          Caption = 'Output to Log File #1'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 3
          OnClick = CheckBox_ContactClick
        end
        object CheckBox_InputAsWellAsRun: TCheckBox
          Left = 25
          Top = 136
          Width = 180
          Height = 20
          Caption = 'Import Case with Run'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 4
          OnClick = CheckBox_ContactClick
        end
      end
    end
    object TabSheet_Environment: TTabSheet
      Caption = 'Environment'
      Enabled = False
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 4
      ParentFont = False
      object Panel_Environment: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 633
        Color = clMoneyGreen
        TabOrder = 0
        object Label_WorldHeight: TLabel
          Left = 24
          Top = 8
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Height of CA'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_WorldWidth: TLabel
          Left = 24
          Top = 40
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Width of CA'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Edit_MaxWorldHeight: TEdit
          Left = 157
          Top = 8
          Width = 100
          Height = 20
          AutoSize = False
          Enabled = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '500'
        end
        object Edit_MaxWorldWidth: TEdit
          Left = 157
          Top = 40
          Width = 100
          Height = 20
          AutoSize = False
          Enabled = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '500'
        end
      end
    end
    object TabSheet_Population: TTabSheet
      Caption = 'Population'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      object Panel_Population: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 633
        Color = clMoneyGreen
        TabOrder = 0
        object Label_PopulationRateOldMan: TLabel
          Left = 24
          Top = 104
          Width = 120
          Height = 20
          AutoSize = False
          Caption = '60'#27506#20197#19978#20154#21475#29575
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
        end
        object Label_PopulationRateYoungMan: TLabel
          Left = 24
          Top = 136
          Width = 120
          Height = 20
          AutoSize = False
          Caption = '20'#27506#20197#19979#20154#21475#29575
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
        end
        object Label_MaxPopulation: TLabel
          Left = 24
          Top = 8
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Total'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_MaxAgent: TLabel
          Left = 24
          Top = 40
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Upper Limit of MI'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label1: TLabel
          Left = 24
          Top = 72
          Width = 120
          Height = 20
          AutoSize = False
          Caption = #27963#21205#27425#25976
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
        end
        object Edit_PopulationRateOldMan: TEdit
          Left = 157
          Top = 104
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '0.2'
        end
        object Edit_PopulationRateYoungMan: TEdit
          Left = 157
          Top = 136
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '0.3'
        end
        object Edit_MaxPopulation: TEdit
          Left = 157
          Top = 8
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = '100000'
        end
        object Edit_MaxAgent: TEdit
          Left = 157
          Top = 40
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = '5'
        end
        object RadioButton_Fixed: TRadioButton
          Left = 160
          Top = 72
          Width = 45
          Height = 20
          Caption = #22266#23450
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          TabStop = True
        end
        object RadioButton_Floating: TRadioButton
          Left = 216
          Top = 72
          Width = 45
          Height = 20
          Caption = #35722#21205
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
          TabOrder = 5
        end
        object Memo_Population: TMemo
          Left = 8
          Top = 168
          Width = 265
          Height = 457
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
        end
      end
    end
    object TabSheet_Disease: TTabSheet
      Caption = 'Epidemic Disease'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold, fsItalic]
      ImageIndex = 1
      ParentFont = False
      object Panel_Disease: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 633
        Color = clMoneyGreen
        TabOrder = 0
        object Label_AvgRecoveredPeriod: TLabel
          Left = 24
          Top = 72
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Restoration Period'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_AvgSymptomaticPeriod: TLabel
          Left = 24
          Top = 40
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Morbidity Period'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_ImmuneProb: TLabel
          Left = 24
          Top = 264
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Immune Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_TransmissionProb: TLabel
          Left = 24
          Top = 232
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Infection Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_MortalityPrimeMan: TLabel
          Left = 24
          Top = 168
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Prime Mortality'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_MortalityOldMan: TLabel
          Left = 24
          Top = 136
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Aged Mortality'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_AvgExposedPeriod: TLabel
          Left = 24
          Top = 8
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Incubation Period'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_MortalityYoungMan: TLabel
          Left = 24
          Top = 200
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Young Mortality'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_AvgInfectiousPeriod: TLabel
          Left = 24
          Top = 296
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Infection Period'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_DetectRate: TLabel
          Left = 24
          Top = 328
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Discovery Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_AvgAntiBodyPeriod: TLabel
          Left = 24
          Top = 104
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'Immune Period'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_SuperRate: TLabel
          Left = 24
          Top = 360
          Width = 120
          Height = 20
          AutoSize = False
          Caption = 'SSE Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Edit_MortalityOldMan: TEdit
          Left = 157
          Top = 136
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '0.52'
        end
        object Edit_MortalityPrimeMan: TEdit
          Left = 157
          Top = 168
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '0.17'
        end
        object Edit_TransmissionProb: TEdit
          Left = 157
          Top = 232
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = '0.05'
        end
        object Edit_ImmuneProb: TEdit
          Left = 157
          Top = 264
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = '0.02'
        end
        object Edit_AvgSymptomaticPeriod: TEdit
          Left = 157
          Top = 40
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          Text = '23'
        end
        object Edit_AvgRecoveredPeriod: TEdit
          Left = 157
          Top = 72
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          Text = '7'
        end
        object Edit_AvgExposedPeriod: TEdit
          Left = 157
          Top = 8
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          Text = '5'
        end
        object Edit_MortalityYoungMan: TEdit
          Left = 157
          Top = 200
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 7
          Text = '0.05'
        end
        object Edit_AvgInfectiousPeriod: TEdit
          Left = 157
          Top = 296
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          Text = '3'
        end
        object Edit_DetectRate: TEdit
          Left = 157
          Top = 328
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 9
          Text = '0.9'
        end
        object Edit_AvgAntibodyPeriod: TEdit
          Left = 157
          Top = 104
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 10
          Text = '60'
        end
        object Edit_SuperRate: TEdit
          Left = 157
          Top = 360
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 11
          Text = '0.0001'
        end
      end
    end
    object TabSheet_PolicySegment1: TTabSheet
      Caption = 'Public Health Policies'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 2
      ParentFont = False
      object Panel_Policies: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 633
        Color = clMoneyGreen
        TabOrder = 0
        object Label_HomePeriod: TLabel
          Left = 24
          Top = 360
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = #38548#38626#22825#25976
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
        end
        object Label_MaskAvailable: TLabel
          Left = 24
          Top = 72
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Participation Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_TempAvailable: TLabel
          Left = 24
          Top = 264
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Participation Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_Home: TLabel
          Left = 24
          Top = 424
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Participation Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_HospitalAvailable: TLabel
          Left = 24
          Top = 584
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Participation Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_HospitalEffect: TLabel
          Left = 24
          Top = 552
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Reduced Death'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_HomeLevel: TLabel
          Left = 24
          Top = 360
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Class'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_TempEffect: TLabel
          Left = 24
          Top = 232
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Detection Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_MaskEffect: TLabel
          Left = 24
          Top = 40
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Prevention Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_Vaccine: TLabel
          Left = 24
          Top = 392
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Quarantined Days'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label3: TLabel
          Left = 24
          Top = 328
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Trace History'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_MedicalPolicyEffect: TLabel
          Left = 24
          Top = 136
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Prevention Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_MedicalPolicyAvailable: TLabel
          Left = 24
          Top = 168
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Participation Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_Visit: TLabel
          Left = 24
          Top = 488
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Participation Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object CheckBox_Mask: TCheckBox
          Left = 25
          Top = 8
          Width = 250
          Height = 20
          Caption = 'Wearing Mask by General Public'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBox_MaskClick
        end
        object Edit_MaskEffect: TEdit
          Left = 157
          Top = 40
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '0.9'
          OnChange = Edit_MaskEffectChange
        end
        object Edit_TempEffect: TEdit
          Left = 157
          Top = 232
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = '0.9'
          OnChange = Edit_TempEffectChange
        end
        object CheckBox_Temp: TCheckBox
          Left = 25
          Top = 200
          Width = 230
          Height = 20
          Caption = 'Temperature Measuring'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = CheckBox_TempClick
        end
        object CheckBox_Home: TCheckBox
          Left = 25
          Top = 296
          Width = 230
          Height = 20
          Caption = 'Home Quarantine'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = CheckBox_HomeClick
        end
        object RadioButton_IsolatedLevelA: TRadioButton
          Left = 156
          Top = 360
          Width = 45
          Height = 20
          Caption = 'A'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          TabStop = True
          OnClick = RadioButton_IsolatedLevelAClick
        end
        object RadioButton_IsolatedLevelB: TRadioButton
          Left = 212
          Top = 360
          Width = 45
          Height = 20
          Caption = 'B'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          OnClick = RadioButton_IsolatedLevelBClick
        end
        object Edit_QuarantinedPeriod: TEdit
          Left = 157
          Top = 392
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 7
          Text = '10'
          OnChange = Edit_QuarantinedPeriodChange
        end
        object Edit_MaskAvailable: TEdit
          Left = 157
          Top = 72
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          Text = '0.9'
          OnChange = Edit_MaskAvailableChange
        end
        object Edit_TempAvailable: TEdit
          Left = 157
          Top = 264
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 9
          Text = '0.9'
          OnChange = Edit_TempAvailableChange
        end
        object Edit_HomeAvailable: TEdit
          Left = 157
          Top = 424
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 10
          Text = '0.81'
          OnChange = Edit_HomeAvailableChange
        end
        object CheckBox_Hospital: TCheckBox
          Left = 25
          Top = 520
          Width = 230
          Height = 20
          Caption = 'Start Medical System'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 11
          OnClick = CheckBox_HospitalClick
        end
        object Edit_HospitalAvailable: TEdit
          Left = 157
          Top = 584
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 12
          Text = '0.95'
          OnChange = Edit_HospitalAvailableChange
        end
        object Edit_HospitalEffect: TEdit
          Left = 157
          Top = 552
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 13
          Text = '0.5'
          OnChange = Edit_HospitalEffectChange
        end
        object CheckBox_TraceOn: TCheckBox
          Left = 156
          Top = 328
          Width = 45
          Height = 20
          BiDiMode = bdLeftToRight
          Caption = 'On'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBiDiMode = False
          ParentFont = False
          State = cbChecked
          TabOrder = 14
          OnClick = CheckBox_TraceOnClick
        end
        object CheckBox_TraceOff: TCheckBox
          Left = 212
          Top = 328
          Width = 45
          Height = 20
          Caption = 'Off'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 15
          OnClick = CheckBox_TraceOffClick
        end
        object CheckBox_MedicalPolicy: TCheckBox
          Left = 25
          Top = 104
          Width = 250
          Height = 20
          Caption = 'Wearing Mask by Healthcare Worker'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 16
          OnClick = CheckBox_MedicalPolicyClick
        end
        object Edit_MedicalPolicyEffect: TEdit
          Left = 157
          Top = 136
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 17
          Text = '0.9'
          OnChange = Edit_MedicalPolicyEffectChange
        end
        object Edit_MedicalPolicyAvailable: TEdit
          Left = 157
          Top = 168
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 18
          Text = '0.9'
          OnChange = Edit_MedicalPolicyAvailableChange
        end
        object CheckBox_Visit: TCheckBox
          Left = 25
          Top = 456
          Width = 230
          Height = 20
          Caption = 'Restrict Access to Hospitals'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 19
          OnClick = CheckBox_VisitClick
        end
        object Edit_VisitAvailable: TEdit
          Left = 157
          Top = 488
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 20
          Text = '0.9'
          OnChange = Edit_VisitAvailableChange
        end
      end
    end
    object TabSheet_PolicySegment2: TTabSheet
      Caption = 'Other Public Health Policies'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 6
      ParentFont = False
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 633
        Color = clMoneyGreen
        TabOrder = 0
        object Label_ContactAvailable: TLabel
          Left = 24
          Top = 40
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Participation Rate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object Label_VaccineEffect: TLabel
          Left = 24
          Top = 104
          Width = 116
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Period of Validity'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
        end
        object CheckBox_Contact: TCheckBox
          Left = 25
          Top = 8
          Width = 216
          Height = 20
          Caption = 'Reducing Public Contact'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBox_ContactClick
        end
        object Edit_ContactAvailable: TEdit
          Left = 157
          Top = 40
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '0.9'
          OnChange = Edit_ContactAvailableChange
        end
        object Button_Vaccine: TButton
          Left = 24
          Top = 72
          Width = 120
          Height = 20
          Caption = 'Inoculate'
          Font.Charset = ANSI_CHARSET
          Font.Color = clMaroon
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Button_VaccineClick
        end
        object Edit_VaccineAvailable: TEdit
          Left = 157
          Top = 72
          Width = 100
          Height = 20
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = '2000'
        end
        object CheckBox_VaccineForever: TCheckBox
          Left = 156
          Top = 104
          Width = 100
          Height = 20
          BiDiMode = bdLeftToRight
          Caption = 'Forever'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentBiDiMode = False
          ParentFont = False
          TabOrder = 4
          OnClick = CheckBox_VaccineForeverClick
        end
        object CheckBox_VaccinePeriod: TCheckBox
          Left = 156
          Top = 128
          Width = 100
          Height = 20
          Caption = 'Short-term'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          State = cbChecked
          TabOrder = 5
          OnClick = CheckBox_VaccinePeriodClick
        end
      end
    end
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 508
    Height = 532
    ActivePage = TabSheet_Zoom
    Font.Charset = ANSI_CHARSET
    Font.Color = clMaroon
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    TabIndex = 1
    TabOrder = 2
    object TabSheet_Lattice: TTabSheet
      Caption = 'MacroScopic'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      OnShow = TabSheet_LatticeShow
      object Lattice: TImage
        Left = 0
        Top = 0
        Width = 500
        Height = 500
        Cursor = crHandPoint
        OnMouseDown = LatticeMouseDown
        OnMouseMove = LatticeMouseMove
      end
    end
    object TabSheet_Zoom: TTabSheet
      Tag = 1
      Caption = 'MicroScopic'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 1
      ParentFont = False
      OnShow = TabSheet_ZoomShow
      object partialLattice: TImage
        Left = 0
        Top = 0
        Width = 500
        Height = 500
        Cursor = crHandPoint
        OnMouseMove = partialLatticeMouseMove
      end
      object Button_West: TButton
        Left = 424
        Top = 444
        Width = 25
        Height = 25
        Caption = '<'
        Enabled = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = Button_WestClick
      end
      object Button_North: TButton
        Left = 448
        Top = 420
        Width = 25
        Height = 25
        Caption = '^'
        Enabled = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = Button_NorthClick
      end
      object Button_Middle: TButton
        Left = 448
        Top = 444
        Width = 25
        Height = 25
        Caption = '0'
        Enabled = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = Button_MiddleClick
      end
      object Button_East: TButton
        Left = 472
        Top = 444
        Width = 25
        Height = 25
        Caption = '>'
        Enabled = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = Button_EastClick
      end
      object Button_South: TButton
        Left = 448
        Top = 468
        Width = 25
        Height = 25
        Caption = 'v'
        Enabled = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = Button_SouthClick
      end
    end
    object TabSheet_TotalCase: TTabSheet
      Tag = 2
      Caption = 'Accumulative Graph'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 2
      ParentFont = False
      OnShow = TabSheet_TotalCaseShow
      object TotalCase_Chart: TChart
        Left = 0
        Top = 0
        Width = 500
        Height = 500
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        BottomAxis.Title.Caption = 'day(s)'
        BottomAxis.Title.Font.Charset = ANSI_CHARSET
        BottomAxis.Title.Font.Color = clBlack
        BottomAxis.Title.Font.Height = -16
        BottomAxis.Title.Font.Name = 'Times New Roman'
        BottomAxis.Title.Font.Style = []
        LeftAxis.Title.Caption = 'person(s)'
        LeftAxis.Title.Font.Charset = ANSI_CHARSET
        LeftAxis.Title.Font.Color = clBlack
        LeftAxis.Title.Font.Height = -16
        LeftAxis.Title.Font.Name = 'Times New Roman'
        LeftAxis.Title.Font.Style = []
        Legend.Alignment = laBottom
        Legend.Color = clBlack
        Legend.Font.Charset = DEFAULT_CHARSET
        Legend.Font.Color = clWhite
        Legend.Font.Height = -11
        Legend.Font.Name = 'Arial'
        Legend.Font.Style = []
        Legend.Frame.Color = clWhite
        Legend.ShadowColor = clSilver
        View3D = False
        TabOrder = 0
        object Series_TotalExposedCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clYellow
          Title = 'Incubation'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psTriangle
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
        object Series_TotalInfectiveCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Infective'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
        object Series_TotalRecoveredCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clBlue
          Title = 'Recovered'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
        object Series_TotalImmuneCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clWhite
          Title = 'Immune'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
        object Series_TotalDiedCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clGray
          Title = 'Died'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
        object Series_TotalIsolatedCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clGreen
          Title = 'Isolated'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
    end
    object TabSheet_Case: TTabSheet
      Tag = 3
      Caption = 'Daily Graph'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 3
      ParentFont = False
      OnShow = TabSheet_CaseShow
      object Case_Chart: TChart
        Left = 0
        Top = 0
        Width = 500
        Height = 500
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clBlue
        Title.Font.Height = -16
        Title.Font.Name = 'Arial'
        Title.Font.Style = []
        Title.Text.Strings = (
          '')
        Title.Visible = False
        BottomAxis.Title.Caption = 'day(s)'
        BottomAxis.Title.Font.Charset = ANSI_CHARSET
        BottomAxis.Title.Font.Color = clBlack
        BottomAxis.Title.Font.Height = -16
        BottomAxis.Title.Font.Name = 'Times New Roman'
        BottomAxis.Title.Font.Style = []
        LeftAxis.Title.Caption = 'person(s)'
        LeftAxis.Title.Font.Charset = ANSI_CHARSET
        LeftAxis.Title.Font.Color = clBlack
        LeftAxis.Title.Font.Height = -16
        LeftAxis.Title.Font.Name = 'Times New Roman'
        LeftAxis.Title.Font.Style = []
        Legend.Alignment = laBottom
        Legend.Color = clBlack
        Legend.Font.Charset = DEFAULT_CHARSET
        Legend.Font.Color = clWhite
        Legend.Font.Height = -11
        Legend.Font.Name = 'Arial'
        Legend.Font.Style = []
        Legend.Frame.Color = clWhite
        Legend.ShadowColor = clSilver
        View3D = False
        TabOrder = 0
        object Series_ExposedCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clYellow
          Title = 'Incubation'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
        object Series_InfectiveCase: TBarSeries
          Marks.ArrowLength = 8
          Marks.Style = smsValue
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Infective'
          BarBrush.Color = clWhite
          BarPen.Visible = False
          BarWidthPercent = 75
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_RecoveredCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clBlue
          Title = 'Recovered'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
        object Series_ImmuneCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clWhite
          Title = 'Immune'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
        object Series_DiedCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clGray
          Title = 'Died'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
        object Series_IsolatedCase2: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clGreen
          Title = 'Isolated'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
    end
    object TabSheet_IsolatedCase: TTabSheet
      Caption = 'Notifiable Graph'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 4
      ParentFont = False
      OnShow = TabSheet_IsolatedCaseShow
      object IsolatedCase_Chart: TChart
        Left = 0
        Top = 0
        Width = 500
        Height = 500
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clBlue
        Title.Font.Height = -16
        Title.Font.Name = 'Arial'
        Title.Font.Style = []
        Title.Text.Strings = (
          '')
        Title.Visible = False
        BottomAxis.Title.Caption = 'day(s)'
        BottomAxis.Title.Font.Charset = ANSI_CHARSET
        BottomAxis.Title.Font.Color = clBlack
        BottomAxis.Title.Font.Height = -16
        BottomAxis.Title.Font.Name = 'Times New Roman'
        BottomAxis.Title.Font.Style = []
        LeftAxis.Title.Caption = 'person(s)'
        LeftAxis.Title.Font.Charset = ANSI_CHARSET
        LeftAxis.Title.Font.Color = clBlack
        LeftAxis.Title.Font.Height = -16
        LeftAxis.Title.Font.Name = 'Times New Roman'
        LeftAxis.Title.Font.Style = []
        Legend.Alignment = laBottom
        Legend.Color = clBlack
        Legend.Font.Charset = DEFAULT_CHARSET
        Legend.Font.Color = clWhite
        Legend.Font.Height = -11
        Legend.Font.Name = 'Arial'
        Legend.Font.Style = []
        Legend.Frame.Color = clWhite
        Legend.ShadowColor = clSilver
        View3D = False
        TabOrder = 0
        object Label_AverageCount: TLabel
          Left = 40
          Top = 436
          Width = 60
          Height = 25
          AutoSize = False
          Caption = 'Average'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          Layout = tlCenter
        end
        object Button_Clear: TButton
          Left = 8
          Top = 468
          Width = 90
          Height = 25
          Caption = 'Clear'
          Font.Charset = ANSI_CHARSET
          Font.Color = clMaroon
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = Button_ClearClick
        end
        object Edit_AverageCount: TEdit
          Left = 8
          Top = 436
          Width = 25
          Height = 27
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '0'
        end
        object Series_IsolatedCase: TBarSeries
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clGreen
          Title = 'Isolation'
          MultiBar = mbStacked
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_InfectiveCase2: TBarSeries
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Death'
          MultiBar = mbStacked
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_AverageCount: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clNavy
          Title = 'Average'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
    end
    object TabSheet_InfectedCase: TTabSheet
      Caption = 'Infective Graph'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 7
      ParentFont = False
      object InfectedCase_Chart: TChart
        Left = 0
        Top = 0
        Width = 500
        Height = 500
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clBlue
        Title.Font.Height = -16
        Title.Font.Name = 'Arial'
        Title.Font.Style = []
        Title.Text.Strings = (
          '')
        Title.Visible = False
        BottomAxis.Title.Caption = 'day(s)'
        BottomAxis.Title.Font.Charset = ANSI_CHARSET
        BottomAxis.Title.Font.Color = clBlack
        BottomAxis.Title.Font.Height = -16
        BottomAxis.Title.Font.Name = 'Times New Roman'
        BottomAxis.Title.Font.Style = []
        LeftAxis.Title.Caption = 'person(s)'
        LeftAxis.Title.Font.Charset = ANSI_CHARSET
        LeftAxis.Title.Font.Color = clBlack
        LeftAxis.Title.Font.Height = -16
        LeftAxis.Title.Font.Name = 'Times New Roman'
        LeftAxis.Title.Font.Style = []
        Legend.Alignment = laBottom
        Legend.Color = clBlack
        Legend.Font.Charset = DEFAULT_CHARSET
        Legend.Font.Color = clWhite
        Legend.Font.Height = -11
        Legend.Font.Name = 'Arial'
        Legend.Font.Style = []
        Legend.Frame.Color = clWhite
        Legend.ShadowColor = clSilver
        View3D = False
        TabOrder = 0
        object Label_InfectedByNormal: TLabel
          Left = 8
          Top = 424
          Width = 40
          Height = 25
          Alignment = taCenter
          AutoSize = False
          Caption = 'Normal'
          Font.Charset = ANSI_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          Layout = tlCenter
        end
        object Label_InfectedByHospital: TLabel
          Left = 48
          Top = 424
          Width = 40
          Height = 25
          Alignment = taCenter
          AutoSize = False
          Caption = 'Hospital'
          Font.Charset = ANSI_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          Layout = tlCenter
        end
        object Label_Infected: TLabel
          Left = 88
          Top = 424
          Width = 49
          Height = 25
          Alignment = taCenter
          AutoSize = False
          Caption = 'Infection'
          Font.Charset = ANSI_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          Layout = tlCenter
        end
        object Edit_InfectedByNormal: TEdit
          Left = 8
          Top = 448
          Width = 40
          Height = 24
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clRed
          Font.Height = -13
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object Edit_InfectedByHospital: TEdit
          Left = 48
          Top = 448
          Width = 40
          Height = 24
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clGreen
          Font.Height = -13
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object Edit_InfectedByNormalRate: TEdit
          Left = 8
          Top = 472
          Width = 40
          Height = 24
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clRed
          Font.Height = -13
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
        object Edit_InfectedByHospitalRate: TEdit
          Left = 48
          Top = 472
          Width = 40
          Height = 24
          AutoSize = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clGreen
          Font.Height = -13
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          ParentFont = False
          TabOrder = 3
        end
        object Series_InfectedByNormal: TBarSeries
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Normal'
          MultiBar = mbStacked
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series_InfectedByHospital: TBarSeries
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clGreen
          Title = 'Hospital'
          MultiBar = mbStacked
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
    end
    object TabSheet_TotalQuarantinedCase: TTabSheet
      Caption = 'Accumulative Quarantine'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 5
      ParentFont = False
      object TotalQuarantinedCase_Chart: TChart
        Left = 0
        Top = 0
        Width = 500
        Height = 500
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clBlue
        Title.Font.Height = -16
        Title.Font.Name = 'Arial'
        Title.Font.Style = []
        Title.Text.Strings = (
          '')
        Title.Visible = False
        BottomAxis.Title.Caption = 'day(s)'
        BottomAxis.Title.Font.Charset = ANSI_CHARSET
        BottomAxis.Title.Font.Color = clBlack
        BottomAxis.Title.Font.Height = -16
        BottomAxis.Title.Font.Name = 'Times New Roman'
        BottomAxis.Title.Font.Style = []
        LeftAxis.Title.Caption = 'person(s)'
        LeftAxis.Title.Font.Charset = ANSI_CHARSET
        LeftAxis.Title.Font.Color = clBlack
        LeftAxis.Title.Font.Height = -16
        LeftAxis.Title.Font.Name = 'Times New Roman'
        LeftAxis.Title.Font.Style = []
        Legend.Alignment = laBottom
        Legend.Color = clBlack
        Legend.Font.Charset = DEFAULT_CHARSET
        Legend.Font.Color = clWhite
        Legend.Font.Height = -11
        Legend.Font.Name = 'Arial'
        Legend.Font.Style = []
        Legend.Frame.Color = clWhite
        Legend.ShadowColor = clSilver
        Legend.Visible = False
        View3D = False
        TabOrder = 0
        object Series_TotalQuarantinedCase: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'QUARANTINED'
          LinePen.Width = 2
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
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
    end
    object TabSheet_QuarantinedCase: TTabSheet
      Caption = 'Daily Quarantine'
      Font.Charset = ANSI_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ImageIndex = 6
      ParentFont = False
      object QuarantinedCase_Chart: TChart
        Left = 0
        Top = 0
        Width = 500
        Height = 500
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clBlue
        Title.Font.Height = -16
        Title.Font.Name = 'Arial'
        Title.Font.Style = []
        Title.Text.Strings = (
          '')
        Title.Visible = False
        BottomAxis.Title.Caption = 'day(s)'
        BottomAxis.Title.Font.Charset = ANSI_CHARSET
        BottomAxis.Title.Font.Color = clBlack
        BottomAxis.Title.Font.Height = -16
        BottomAxis.Title.Font.Name = 'Times New Roman'
        BottomAxis.Title.Font.Style = []
        LeftAxis.Title.Caption = 'person(s)'
        LeftAxis.Title.Font.Charset = ANSI_CHARSET
        LeftAxis.Title.Font.Color = clBlack
        LeftAxis.Title.Font.Height = -16
        LeftAxis.Title.Font.Name = 'Times New Roman'
        LeftAxis.Title.Font.Style = []
        Legend.Alignment = laBottom
        Legend.Color = clBlack
        Legend.Font.Charset = DEFAULT_CHARSET
        Legend.Font.Color = clWhite
        Legend.Font.Height = -11
        Legend.Font.Name = 'Arial'
        Legend.Font.Style = []
        Legend.Frame.Color = clWhite
        Legend.ShadowColor = clSilver
        Legend.Visible = False
        View3D = False
        TabOrder = 0
        object Series_QuarantinedCase: TBarSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'QUARANTINED'
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
    end
  end
  object Button_Exit: TButton
    Left = 456
    Top = 648
    Width = 60
    Height = 25
    Caption = 'Exit'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button_ExitClick
  end
  object Button_Create: TButton
    Left = 328
    Top = 648
    Width = 60
    Height = 25
    Caption = 'Initial'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button_CreateClick
  end
  object Button_NewCase: TButton
    Left = 8
    Top = 544
    Width = 49
    Height = 25
    Caption = 'Import'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button_NewCaseClick
  end
  object Edit_NewCase: TEdit
    Left = 112
    Top = 544
    Width = 25
    Height = 25
    AutoSize = False
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    Text = '1'
  end
  object Button_Run: TButton
    Left = 344
    Top = 544
    Width = 33
    Height = 25
    Caption = 'Run'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button_RunClick
  end
  object Edit_Period: TEdit
    Left = 424
    Top = 544
    Width = 20
    Height = 25
    AutoSize = False
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    Text = '1'
  end
  object MemoStatus: TMemo
    Left = 8
    Top = 592
    Width = 508
    Height = 49
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    WordWrap = False
  end
  object ProgressBar: TProgressBar
    Left = 8
    Top = 576
    Width = 508
    Height = 9
    Min = 0
    Max = 50000
    Step = 1
    TabOrder = 10
  end
  object RadioButton_Exposed: TRadioButton
    Left = 192
    Top = 544
    Width = 80
    Height = 25
    Caption = 'Incubation'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
  end
  object RadioButton_Infective: TRadioButton
    Left = 272
    Top = 544
    Width = 73
    Height = 25
    Caption = 'Infected'
    Checked = True
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    TabStop = True
  end
  object Button_Termination: TButton
    Left = 392
    Top = 648
    Width = 60
    Height = 25
    Caption = 'Finish'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = Button_TerminationClick
  end
  object Edit_Gossip: TEdit
    Left = 472
    Top = 544
    Width = 20
    Height = 25
    AutoSize = False
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    Text = '1'
    OnChange = Edit_GossipChange
  end
  object Button_Print: TButton
    Left = 8
    Top = 648
    Width = 60
    Height = 25
    Caption = 'Print'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = Button_PrintClick
  end
  object Button_Save: TButton
    Left = 72
    Top = 648
    Width = 60
    Height = 25
    Caption = 'Save'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 16
    OnClick = Button_SaveClick
  end
  object Edit_FileName: TEdit
    Left = 176
    Top = 648
    Width = 140
    Height = 24
    AutoSize = False
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 17
    Text = 'Accumulation'
  end
  object Edit_PeopleState: TEdit
    Left = 48
    Top = 648
    Width = 340
    Height = 25
    AutoSize = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 18
  end
  object CheckBox_Super: TCheckBox
    Left = 64
    Top = 544
    Width = 41
    Height = 25
    Caption = 'SS'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 19
  end
  object Button_Stop: TButton
    Left = 384
    Top = 544
    Width = 33
    Height = 25
    Caption = 'Stop'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 20
    OnClick = Button_StopClick
  end
  object SimulationTimer: TTimer
    Enabled = False
    OnTimer = SimulationTimerTimer
    Left = 520
    Top = 56
  end
end
