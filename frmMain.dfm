object MainFrm: TMainFrm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'MagicPoints v1.0'
  ClientHeight = 331
  ClientWidth = 260
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 96
    Top = 104
    Width = 94
    Height = 13
    Caption = 'magic points found!'
  end
  object lblMagiCalls: TLabel
    Left = 49
    Top = 104
    Width = 41
    Height = 13
    Alignment = taRightJustify
    AutoSize = False
    Caption = '0'
  end
  object lstPointsData: TListView
    Left = 8
    Top = 129
    Width = 244
    Height = 193
    Columns = <
      item
        Caption = 'Module'
        Width = 130
      end
      item
        Caption = 'Address'
        Width = 80
      end>
    GridLines = True
    ReadOnly = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 244
    Height = 89
    Caption = ' Compiler '
    TabOrder = 1
    object cmbCompiler: TComboBox
      Left = 16
      Top = 22
      Width = 209
      Height = 21
      DropDownCount = 15
      TabOrder = 0
      Text = 'Visual Basic 5'
      Items.Strings = (
        'Visual Basic 5'
        'Visual Basic 6'
        'Borland Delphi/C++'
        'Visual C++ 5/6 (MFC)'
        'Visual C++ 10 (MFC Dynamic Debug)'
        'Visual C++ 10 (MFC Dynamic Release)'
        'Visual C++ 10 (MFC Static Debug)'
        'Visual C++ 10 (MFC Static Release)'
        'Visual C++ 12 (MFC Dynamic Debug)'
        'Visual C++ 12 (MFC Dynamic Release)'
        'Visual C++ 12 (MFC Static Debug)'
        'Visual C++ 12 (MFC Static Release)'
        'Visual C++ 14 (MFC Dynamic Debug)'
        'Visual C++ 14 (MFC Dynamic Release)'
        'Visual C++ 14 (MFC Static Debug)'
        'Visual C++ 14 (MFC Static Release)'
        'Point H-MEMCPY (Generic)')
    end
    object btnLocate: TButton
      Left = 80
      Top = 49
      Width = 84
      Height = 25
      Caption = 'Locate'
      TabOrder = 1
      OnClick = btnLocateClick
    end
  end
end
