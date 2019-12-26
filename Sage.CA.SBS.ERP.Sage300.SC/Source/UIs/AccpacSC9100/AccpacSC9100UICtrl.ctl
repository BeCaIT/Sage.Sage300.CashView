VERSION 5.00
Object = "{BDC217C8-ED16-11CD-956C-0000C04E4C0A}#1.1#0"; "TABCTL32.OCX"
Object = "{5F7FA996-AD93-11D3-8ED1-000094847112}#1.0#0"; "a4wDataSource.dll"
Object = "{D07665A1-D89F-11D2-9BD2-00104B71EB3F}#1.0#0"; "a4wFldEdtCtrl.dll"
Object = "{A46D8382-C397-11D3-9FF2-00C04F815D63}#1.0#0"; "AccpacListCtrl.dll"
Object = "{B700FC75-C559-11D4-94E1-00C04F815D63}#1.0#0"; "AccpacGridCtrl.dll"
Begin VB.UserControl AccpacSC9100UICtrl 
   ClientHeight    =   8205
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   8340
   KeyPreview      =   -1  'True
   ScaleHeight     =   8205
   ScaleWidth      =   8340
   ToolboxBitmap   =   "AccpacSC9100UICtrl.ctx":0000
   Begin TabDlg.SSTab sstabOptions 
      Height          =   7440
      Left            =   150
      TabIndex        =   0
      TabStop         =   0   'False
      Top             =   150
      Width           =   8040
      _ExtentX        =   14182
      _ExtentY        =   13123
      _Version        =   393216
      Style           =   1
      Tabs            =   4
      Tab             =   3
      TabsPerRow      =   4
      TabHeight       =   520
      TabCaption(0)   =   "@Company@"
      TabPicture(0)   =   "AccpacSC9100UICtrl.ctx":0312
      Tab(0).ControlEnabled=   0   'False
      Tab(0).Control(0)=   "fecSCOPT_BRN"
      Tab(0).Control(1)=   "fraCompany"
      Tab(0).Control(2)=   "fecSCOPT_BRYear"
      Tab(0).Control(3)=   "fecSCOPT_Country"
      Tab(0).Control(4)=   "fecSCOPT_EntityType"
      Tab(0).Control(5)=   "fecSCOPT_Industry"
      Tab(0).Control(6)=   "fecSCOPT_Contact"
      Tab(0).Control(7)=   "fecSCOPT_JobTitle"
      Tab(0).Control(8)=   "fecSCOPT_Phone"
      Tab(0).Control(9)=   "fecSCOPT_Mobile"
      Tab(0).Control(10)=   "fecSCOPT_Email"
      Tab(0).ControlCount=   11
      TabCaption(1)   =   "@Processing@"
      TabPicture(1)   =   "AccpacSC9100UICtrl.ctx":032E
      Tab(1).ControlEnabled=   0   'False
      Tab(1).Control(0)=   "lblProcess_ForecastPeriods"
      Tab(1).Control(1)=   "lblProcess_DocumentNumbers"
      Tab(1).Control(2)=   "grdSCOPT_DocumentNumbers"
      Tab(1).Control(2).Enabled=   0   'False
      Tab(1).Control(3)=   "fraProcessing_Statistics"
      Tab(1).Control(4)=   "fraProcessing_Settings"
      Tab(1).Control(5)=   "grdSCOPT_ForecastPeriods"
      Tab(1).Control(5).Enabled=   0   'False
      Tab(1).ControlCount=   6
      TabCaption(2)   =   "@Cash/Bank Accounts@"
      TabPicture(2)   =   "AccpacSC9100UICtrl.ctx":034A
      Tab(2).ControlEnabled=   0   'False
      Tab(2).Control(0)=   "vlsSCACCT_Accounts"
      Tab(2).ControlCount=   1
      TabCaption(3)   =   "@Emails Alert@"
      TabPicture(3)   =   "AccpacSC9100UICtrl.ctx":0366
      Tab(3).ControlEnabled=   -1  'True
      Tab(3).Control(0)=   "lblEmail_Consent"
      Tab(3).Control(0).Enabled=   0   'False
      Tab(3).Control(1)=   "fecSCOPT_EmailOffer"
      Tab(3).Control(1).Enabled=   0   'False
      Tab(3).Control(2)=   "fecSCOPT_EmailSnoozeUntil"
      Tab(3).Control(2).Enabled=   0   'False
      Tab(3).Control(3)=   "fecSCOPT_EmailAlert"
      Tab(3).Control(3).Enabled=   0   'False
      Tab(3).Control(4)=   "fraEmail_Settings"
      Tab(3).Control(4).Enabled=   0   'False
      Tab(3).Control(5)=   "fraEmail_Testing"
      Tab(3).Control(5).Enabled=   0   'False
      Tab(3).Control(6)=   "fraEmail_Advisory"
      Tab(3).Control(6).Enabled=   0   'False
      Tab(3).ControlCount=   7
      Begin VB.Frame fraEmail_Advisory 
         Caption         =   "@Advisory@"
         Height          =   1365
         Left            =   150
         TabIndex        =   45
         Top             =   4350
         Width           =   7740
         Begin VB.Label lblEmail_Advisory 
            Caption         =   "@AdvisoryText@"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   700
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   990
            Left            =   150
            TabIndex        =   46
            Top             =   300
            Width           =   7440
         End
      End
      Begin VB.Frame fraEmail_Testing 
         Caption         =   "@SendTestEmail@"
         Height          =   765
         Left            =   150
         TabIndex        =   42
         Top             =   3525
         Width           =   7740
         Begin VB.CommandButton btnEmail_SendTest 
            Caption         =   "Send"
            Height          =   315
            Left            =   6525
            TabIndex        =   44
            Top             =   300
            Width           =   1065
         End
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailToTest 
            Height          =   315
            Left            =   150
            TabIndex        =   43
            Top             =   300
            Width           =   6240
            _cx             =   11007
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   0
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   0   'False
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "EMAILTEST"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
      End
      Begin VB.Frame fraEmail_Settings 
         Caption         =   "@Settings@"
         Height          =   2640
         Left            =   150
         TabIndex        =   34
         Top             =   825
         Width           =   7740
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailServer 
            Height          =   315
            Left            =   150
            TabIndex        =   35
            Top             =   300
            Width           =   7440
            _cx             =   13123
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   0
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   0   'False
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "EMAILHOST"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailPort 
            Height          =   315
            Left            =   150
            TabIndex        =   36
            Top             =   675
            Width           =   3540
            _cx             =   6244
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   4
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   0   'False
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "EMAILPORT"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailSSL 
            Height          =   315
            Left            =   3825
            TabIndex        =   37
            Top             =   675
            Width           =   3540
            _cx             =   6244
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   0
            BackStyle       =   1
            ControlType     =   2
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   0   'False
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "EMAILSSL"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   0
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   "EMAILSSL"
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailUserName 
            Height          =   315
            Left            =   150
            TabIndex        =   38
            Top             =   1050
            Width           =   7440
            _cx             =   13123
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   0
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   0   'False
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "EMAILUSER"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailFrom 
            Height          =   315
            Left            =   150
            TabIndex        =   40
            Top             =   1800
            Width           =   7440
            _cx             =   13123
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   0
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   0   'False
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "EMAILADDR"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailTo 
            Height          =   315
            Left            =   150
            TabIndex        =   41
            Top             =   2175
            Width           =   7440
            _cx             =   13123
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   0
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   0   'False
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "EMAILTO"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailPassword 
            Height          =   315
            Left            =   150
            TabIndex        =   39
            Top             =   1425
            Width           =   7440
            _cx             =   13123
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   0
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   0   'False
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "EMAILPSWDS"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
      End
      Begin AccpacFldListCtl.AccpacViewList vlsSCACCT_Accounts 
         Height          =   6765
         Left            =   -74850
         TabIndex        =   31
         Top             =   450
         Width           =   7740
         ShowGridLines   =   1
         DataSourceClone =   0
         Enabled         =   -1  'True
         RevisionList    =   0   'False
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         BeginProperty HeadFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         _cx             =   13652
         _cy             =   11933
         BackColor       =   -2147483633
         ForeColor       =   -2147483630
         BorderWidth     =   1
         DataSourceName  =   "dsSCACCT"
         AllowDelete     =   0   'False
         AllowInsert     =   0   'False
         ReadOnly        =   0   'False
         UpdateOnKillFocus=   -1  'True
         SavePreferences =   -1  'True
         UseFldDescAsCaption=   -1  'True
         CustomRowColor  =   0   'False
         Ctrl_Version    =   4
         Column0         =   "0,INCLUDE,-1,,2,75,1,0,1,NONE,-1,NONE,"
         FinderFld0      =   ""
         CustomColorFld0 =   "0"
         Column1         =   "1,ACCTFMTTD,-1,,0,150,0,0,0,NONE,-1,NONE,"
         FinderFld1      =   ""
         CustomColorFld1 =   "0"
         Column2         =   "2,ACCTDESC,-1,,0,250,0,0,0,NONE,-1,NONE,"
         FinderFld2      =   ""
         CustomColorFld2 =   "0"
      End
      Begin AccpacFldGridCtl.AccpacGrid grdSCOPT_ForecastPeriods 
         Height          =   2190
         Left            =   -74850
         TabIndex        =   28
         Top             =   2025
         Width           =   3015
         _cx             =   5318
         _cy             =   3863
         Appearance      =   0
         BackColor       =   -2147483633
         Enabled         =   -1  'True
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   -2147483630
         Object.TabStop         =   0   'False
         ColumnCount     =   2
         RowsCount       =   7
         MaxHeight       =   -1
         CustomColor     =   0   'False
         Ctrl_Version    =   1
         Column0         =   "0,FROM,-1,@From@,1,100,0,0,"
         Column1         =   "1,TO,-1,@To@,1,100,1,0,"
      End
      Begin VB.Frame fraProcessing_Settings 
         Caption         =   "@Settings@"
         Height          =   1140
         Left            =   -74850
         TabIndex        =   21
         Top             =   450
         Width           =   3840
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_FunctionalCurrency 
            Height          =   315
            Left            =   150
            TabIndex        =   22
            TabStop         =   0   'False
            Top             =   300
            Width           =   3540
            _cx             =   6244
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   0
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   -1  'True
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "HOMECUR"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   -1
            LoadModernizedIcon=   0
         End
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_CashBankThreshold 
            Height          =   315
            Left            =   150
            TabIndex        =   23
            Top             =   675
            Width           =   3540
            _cx             =   6244
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   4
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   0   'False
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "CBALTHRHD"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   -1  'True
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            RequiredField   =   -1
            LoadModernizedIcon=   0
         End
      End
      Begin VB.Frame fraProcessing_Statistics 
         Caption         =   "@Statistics@"
         Height          =   1140
         Left            =   -70950
         TabIndex        =   24
         Top             =   450
         Width           =   3840
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_LastProcessDate 
            Height          =   315
            Left            =   150
            TabIndex        =   25
            TabStop         =   0   'False
            Top             =   300
            Width           =   3540
            _cx             =   6244
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   5
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   -1  'True
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "LPROCDATE"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            CalendarTabAway =   0
            AllowNull       =   -1
            CreditCardExpireDate=   0
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
         Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_LastProcessTime 
            Height          =   315
            Left            =   150
            TabIndex        =   26
            TabStop         =   0   'False
            Top             =   675
            Width           =   3540
            _cx             =   6244
            _cy             =   556
            Valid           =   -1  'True
            Appearance      =   0
            BorderStyle     =   1
            BackStyle       =   1
            ControlType     =   5
            Enabled         =   -1  'True
            Mask            =   ""
            NavigationBtns  =   0   'False
            NewBtn          =   0   'False
            CustomButtonCount=   0
            ReadOnly        =   -1  'True
            TileVertically  =   -1  'True
            Version         =   5
            MultiLine       =   0   'False
            AutoRefresh     =   -1  'True
            AutoUpdate      =   -1  'True
            VerifyOnSave    =   -1  'True
            FireOnInvalidValue=   -1  'True
            ViewFinderBtn   =   0   'False
            DataSourceName  =   "dsSCOPT"
            FieldName       =   "LPROCTIME"
            CurrencyField   =   ""
            RightLabelResID =   0
            RightLabelLength=   0
            RightLabelAppID =   ""
            FieldDescriptionAsRightLabel=   -1  'True
            LeftLabelResID  =   0
            LeftLabelLength =   80
            LeftLabelAppID  =   ""
            FieldDescriptionAsLeftLabel=   -1  'True
            Text            =   ""
            TextResID       =   0
            TextAppID       =   ""
            FieldDescriptionAsText=   -1  'True
            CaptionType     =   2
            UseSysDefForNumber=   0   'False
            NumberGroupingSymbol=   "Default"
            NumberDecimalSymbol=   "Default"
            CurrencySymbol  =   ""
            NumberDecimalsBefore=   -1
            NumberDecimalsAfter=   -1
            NumberNegativeFormat=   5
            NumberDigitsInGroup=   3
            HomeCurrency    =   0   'False
            NumberDomain    =   0
            ForeColor       =   0
            BackColor       =   -2147483633
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            InvalidValueForeground=   255
            CalendarTabAway =   0
            AllowNull       =   -1
            CreditCardExpireDate=   0
            RequiredField   =   0
            LoadModernizedIcon=   0
         End
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_BRN 
         Height          =   315
         Left            =   -74850
         TabIndex        =   14
         Top             =   4275
         Width           =   3765
         _cx             =   6641
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   0
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "BRN"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin VB.Frame fraCompany 
         Height          =   3015
         Left            =   -74850
         TabIndex        =   1
         Top             =   375
         Width           =   7740
         Begin VB.Label lblComp_Country 
            Caption         =   "@Country@"
            Height          =   315
            Left            =   150
            TabIndex        =   10
            Top             =   2625
            Width           =   7440
         End
         Begin VB.Label lblComp_Postal 
            Caption         =   "@Postal@"
            Height          =   315
            Left            =   150
            TabIndex        =   9
            Top             =   2325
            Width           =   7440
         End
         Begin VB.Label lblComp_State 
            Caption         =   "@State@"
            Height          =   315
            Left            =   150
            TabIndex        =   8
            Top             =   2025
            Width           =   7440
         End
         Begin VB.Label lblComp_City 
            Caption         =   "@City@"
            Height          =   315
            Left            =   150
            TabIndex        =   7
            Top             =   1725
            Width           =   7440
         End
         Begin VB.Label lblComp_Address4 
            Caption         =   "@Address4@"
            Height          =   315
            Left            =   150
            TabIndex        =   6
            Top             =   1425
            Width           =   7440
         End
         Begin VB.Label lblComp_Address3 
            Caption         =   "@Address3@"
            Height          =   315
            Left            =   150
            TabIndex        =   5
            Top             =   1125
            Width           =   7440
         End
         Begin VB.Label lblComp_Address2 
            Caption         =   "@Address2@"
            Height          =   315
            Left            =   150
            TabIndex        =   4
            Top             =   825
            Width           =   7440
         End
         Begin VB.Label lblComp_Address1 
            Caption         =   "@Address1@"
            Height          =   315
            Left            =   150
            TabIndex        =   3
            Top             =   525
            Width           =   7440
         End
         Begin VB.Label lblComp_Name 
            Caption         =   "@CompanyName@"
            Height          =   315
            Left            =   150
            TabIndex        =   2
            Top             =   225
            Width           =   7440
         End
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_BRYear 
         Height          =   315
         Left            =   -70875
         TabIndex        =   15
         Top             =   4275
         Width           =   3765
         _cx             =   6641
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   0
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "BRYEAR"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_Country 
         Height          =   315
         Left            =   -74850
         TabIndex        =   11
         Top             =   3525
         Width           =   3765
         _cx             =   6641
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   1
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "COUNTRY"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EntityType 
         Height          =   315
         Left            =   -70875
         TabIndex        =   12
         Top             =   3525
         Width           =   3765
         _cx             =   6641
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   1
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "ENTITYTYPE"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_Industry 
         Height          =   315
         Left            =   -74850
         TabIndex        =   13
         Top             =   3900
         Width           =   7740
         _cx             =   13652
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   1
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "INDUSTRY"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_Contact 
         Height          =   315
         Left            =   -74850
         TabIndex        =   16
         Top             =   4650
         Width           =   7740
         _cx             =   13652
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   0
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "CONTACT"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_JobTitle 
         Height          =   315
         Left            =   -74850
         TabIndex        =   17
         Top             =   5025
         Width           =   7740
         _cx             =   13652
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   1
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "JOBTITLE"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_Phone 
         Height          =   315
         Left            =   -74850
         TabIndex        =   19
         Top             =   5775
         Width           =   3765
         _cx             =   6641
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   0
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "PHONE"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_Mobile 
         Height          =   315
         Left            =   -70875
         TabIndex        =   20
         Top             =   5775
         Width           =   3765
         _cx             =   6641
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   0
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "MOBILE"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   0
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailAlert 
         Height          =   315
         Left            =   150
         TabIndex        =   32
         Top             =   450
         Width           =   3540
         _cx             =   6244
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   0
         BackStyle       =   1
         ControlType     =   2
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "EMAILALERT"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   0
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   "EMAILALERT"
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_Email 
         Height          =   315
         Left            =   -74850
         TabIndex        =   18
         Top             =   5400
         Width           =   7740
         _cx             =   13652
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   0
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "EMAIL"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin AccpacFldGridCtl.AccpacGrid grdSCOPT_DocumentNumbers 
         Height          =   690
         Left            =   -74850
         TabIndex        =   30
         Top             =   4650
         Width           =   6015
         _cx             =   10610
         _cy             =   1217
         Appearance      =   0
         BackColor       =   -2147483633
         Enabled         =   -1  'True
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   -2147483630
         Object.TabStop         =   0   'False
         ColumnCount     =   4
         RowsCount       =   1
         MaxHeight       =   -1
         CustomColor     =   0   'False
         Ctrl_Version    =   9
         Column0         =   "0,DOCTYPE,-1,@DocumentType@,0,150,0,0,"
         Column1         =   "1,CFELENGTH,-1,@Length@,1,75,1,0,"
         Column2         =   "2,CFEPREFIX,-1,@Prefix@,0,75,1,0,"
         Column3         =   "3,CFENEXTNBR,-1,@NextNumber@,1,100,1,0,"
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailSnoozeUntil 
         Height          =   315
         Left            =   4695
         TabIndex        =   33
         Top             =   480
         Width           =   3165
         _cx             =   5583
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   1
         BackStyle       =   1
         ControlType     =   0
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "EMAILSNUTL"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   -1  'True
         LeftLabelResID  =   0
         LeftLabelLength =   80
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   -1  'True
         Text            =   ""
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   -1  'True
         CaptionType     =   2
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   0
         LoadModernizedIcon=   0
      End
      Begin AccpacFldEditCtl.AccpacFieldEditControl fecSCOPT_EmailOffer 
         Height          =   315
         Left            =   150
         TabIndex        =   51
         Top             =   5775
         Width           =   240
         _cx             =   423
         _cy             =   556
         Valid           =   -1  'True
         Appearance      =   0
         BorderStyle     =   0
         BackStyle       =   1
         ControlType     =   2
         Enabled         =   -1  'True
         Mask            =   ""
         NavigationBtns  =   0   'False
         NewBtn          =   0   'False
         CustomButtonCount=   0
         ReadOnly        =   0   'False
         TileVertically  =   -1  'True
         Version         =   5
         MultiLine       =   0   'False
         AutoRefresh     =   -1  'True
         AutoUpdate      =   -1  'True
         VerifyOnSave    =   -1  'True
         FireOnInvalidValue=   -1  'True
         ViewFinderBtn   =   0   'False
         DataSourceName  =   "dsSCOPT"
         FieldName       =   "EMAILOFFER"
         CurrencyField   =   ""
         RightLabelResID =   0
         RightLabelLength=   0
         RightLabelAppID =   ""
         FieldDescriptionAsRightLabel=   0   'False
         LeftLabelResID  =   0
         LeftLabelLength =   0
         LeftLabelAppID  =   ""
         FieldDescriptionAsLeftLabel=   0   'False
         Text            =   "EMAILOFFER"
         TextResID       =   0
         TextAppID       =   ""
         FieldDescriptionAsText=   0   'False
         CaptionType     =   3
         UseSysDefForNumber=   0   'False
         NumberGroupingSymbol=   "Default"
         NumberDecimalSymbol=   "Default"
         CurrencySymbol  =   ""
         NumberDecimalsBefore=   -1
         NumberDecimalsAfter=   -1
         NumberNegativeFormat=   5
         NumberDigitsInGroup=   3
         HomeCurrency    =   0   'False
         NumberDomain    =   0
         ForeColor       =   0
         BackColor       =   -2147483633
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         InvalidValueForeground=   255
         RequiredField   =   -1
         LoadModernizedIcon=   0
      End
      Begin VB.Label lblEmail_Consent 
         Caption         =   "@AdvisoryText@"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1590
         Left            =   450
         TabIndex        =   52
         Top             =   5775
         Width           =   7440
      End
      Begin VB.Label lblProcess_DocumentNumbers 
         Caption         =   "@Document Numbers@"
         Height          =   315
         Left            =   -74850
         TabIndex        =   29
         Top             =   4350
         Width           =   3765
      End
      Begin VB.Label lblProcess_ForecastPeriods 
         Caption         =   "@Forecast Periods@"
         Height          =   315
         Left            =   -74850
         TabIndex        =   27
         Top             =   1725
         Width           =   3765
      End
   End
   Begin VB.CommandButton APP_Save_Button 
      Caption         =   "&Save"
      Height          =   315
      Left            =   150
      TabIndex        =   49
      Top             =   7725
      Width           =   1065
   End
   Begin VB.CommandButton APP_Close_Button 
      Caption         =   "&Close"
      Height          =   315
      Left            =   7125
      TabIndex        =   50
      Top             =   7725
      Width           =   1065
   End
   Begin AccpacDataSrcCtl.AccpacDataSource dsSCACCT 
      Height          =   315
      Left            =   1800
      TabIndex        =   48
      TabStop         =   0   'False
      Top             =   7725
      Width           =   315
      _cx             =   556
      _cy             =   556
      _DefaultCmp     =   0   'False
      ViewID          =   "SC0010"
      ParentName      =   ""
      DesignUID       =   "ADMIN"
      DesignPWD       =   "ADMIN"
      DesignOrgID     =   "SAMLTD"
      DBLinkType      =   1
      DBLinkFlag      =   0
      Order           =   0
      ComposeViewIDs  =   ""
      UseRecNum       =   0   'False
      UseOpenViewInstance=   0   'False
      InstanceReadonly=   0   'False
      InstanceUnrevisioned=   0   'False
      InstanceUnvalidated=   0   'False
      InstanceNonheritable=   0   'False
      InstancePrefetch=   0
      UniqueIndex     =   0   'False
   End
   Begin AccpacDataSrcCtl.AccpacDataSource dsSCOPT 
      Height          =   315
      Left            =   1350
      TabIndex        =   47
      TabStop         =   0   'False
      Top             =   7725
      Width           =   315
      _cx             =   556
      _cy             =   556
      _DefaultCmp     =   0   'False
      ViewID          =   "SC0001"
      ParentName      =   ""
      DesignUID       =   "ADMIN"
      DesignPWD       =   "ADMIN"
      DesignOrgID     =   "SAMLTD"
      DBLinkType      =   1
      DBLinkFlag      =   0
      Order           =   0
      ComposeViewIDs  =   ""
      UseRecNum       =   0   'False
      UseOpenViewInstance=   0   'False
      InstanceReadonly=   0   'False
      InstanceUnrevisioned=   0   'False
      InstanceUnvalidated=   0   'False
      InstanceNonheritable=   0   'False
      InstancePrefetch=   0
      UniqueIndex     =   0   'False
   End
   Begin VB.Menu mnuFile 
      Caption         =   "&File"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuFile_Print 
         Caption         =   "&Print..."
      End
      Begin VB.Menu mnuFile_PrintSetup 
         Caption         =   "P&rint Setup..."
      End
      Begin VB.Menu mnuFile_s1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFile_Customize 
         Caption         =   "C&ustomize..."
      End
      Begin VB.Menu mnuFile_s2 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFile_Close 
         Caption         =   "&Close"
      End
   End
   Begin VB.Menu mnuHelp 
      Caption         =   "&Help"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuHelp_Contents 
         Caption         =   "&Contents"
      End
      Begin VB.Menu mnuHelp_UsingHelp 
         Caption         =   "Using &Help"
      End
      Begin VB.Menu mnuHelp_s1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuHelp_About 
         Caption         =   "&About..."
      End
   End
   Begin VB.Menu popmnuTopLevel 
      Caption         =   "(Popup)"
      Begin VB.Menu popmnuFile 
         Caption         =   "&File"
         Begin VB.Menu popmnuFile_Print 
            Caption         =   "&Print..."
         End
         Begin VB.Menu popmnuFile_PrintSetup 
            Caption         =   "P&rint Setup..."
         End
         Begin VB.Menu popmnuFile_s1 
            Caption         =   "-"
         End
         Begin VB.Menu popmnuFile_Customize 
            Caption         =   "C&ustomize..."
         End
         Begin VB.Menu popmnuFile_s2 
            Caption         =   "-"
         End
         Begin VB.Menu popmnuFile_Close 
            Caption         =   "&Close"
         End
      End
      Begin VB.Menu popmnuS1 
         Caption         =   "-"
      End
      Begin VB.Menu popmnuHelp 
         Caption         =   "&Help"
         Begin VB.Menu popmnuHelp_Contents 
            Caption         =   "&Contents"
         End
         Begin VB.Menu popmnuHelp_UsingHelp 
            Caption         =   "Using &Help"
         End
         Begin VB.Menu popmnuHelp_s1 
            Caption         =   "-"
         End
         Begin VB.Menu popmnuHelp_About 
            Caption         =   "&About..."
         End
      End
   End
End
Attribute VB_Name = "AccpacSC9100UICtrl"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
'
' Template 6.3A Revision: Release
'
' ACCPAC UI Control Class Module: AccpacSC9100UICtrl
'   (S/C Options)
'
' Description: <BRIEFLY DESCRIBE WHAT YOUR UI DOES>
'
' ObjectKey: <IF YOUR UI USES THE ObjectKey (PASSED
'             IN BY CALLER UI'S), BRIEFLY DESCRIBE
'             ITS STRUCTURE/USE.>
'
' ReturnValue: <IF YOUR UI SETS A RETURN VALUE (FOR
'               THE CALLER UI TO RETRIEVE AFTER
'               CALLING YOUR UI MODALLY), BRIEFLY
'               DESCRIBE ITS STRUCTURE.>
'
' NOTE: In the UserControl's visual designer, select
'       the UserControl itself.  Select its
'       "ToolboxBitmap" property and press this
'       property's "..." button.  The resulting
'       "Load Bitmap" dialog box lets you navigate
'       to and choose the appropriate BITMAP (.bmp
'       file) to represent your ACCPAC UI Control in
'       the OLE Object Viewer.  This bitmap should
'       look the same as the "About" box's icon.
'
' Standard Public Methods: - CloseUIApp
'                          - FireAfterCtlClick (HIDDEN)
'                          - FireBeforeCtlClick (HIDDEN)
'                          - FireCloseSplashScreen (HIDDEN)
'                          - FireOnLaunchObject (HIDDEN)
'                          - FireOnLaunchURL (HIDDEN)
'                          - FireOnPopupClosed (HIDDEN)
'                          - FireOnPopupOpened (HIDDEN)
'                          - QueryCloseUIApp
'                          - ShowMenus
' Control-Specific Public Methods: <LIST EXTRA METHODS HERE>
'
' Standard Properties: - BackColor (Saved)
'                      - BackStyle (Saved)
'                      - BorderStyle (Saved)
'                      - CompanyID (Read-only)
'                      - Enabled
'                      - Font (Saved)
'                      - ForeColor (Saved)
'                      - hWnd (Read-only)
'                      - MaskColor (Saved)
'                      - MaskPicture (Saved)
'                      - MinimumHeight (Read-only)
'                      - MinimumWidth (Read-only)
'                      - ObjectHandle (HIDDEN)
'                      - ObjectKey
'                      - Picture (Saved)
'                      - Resizable (Read-only)
'                      - ReturnValue (Read-only)
'                      - RightToLeft
'                      - ServerName (HIDDEN)
'                      - SessionID (HIDDEN)
'                      - TwipsPerPixelX (Read-only)
'                      - TwipsPerPixelY (Read-only)
'                      - UIAppControls (Read-only)
'                      - UIAppIsOpen (Read-only)
'                      - UIDBLinks (Read-only)
'                      - UIDSControls (Read-only)
'                      - UIIcon (Read-only)
'                      - UIName (Read-only)
'                      - UISession (Read-only)
' Control-Specific Properties: <LIST EXTRA PROPERTIES HERE>
'
' Standard Events: - AfterCtlClick
'                  - BeforeCtlClick
'                  - BeforeUIAppClosed
'                  - BeforeUIAppOpened (HIDDEN)
'                  - CloseSplashScreen (HIDDEN)
'                  - OnLaunchObject
'                  - OnLaunchURL
'                  - OnPopupClosed
'                  - OnPopupOpened
'                  - OnUIAppClosed
'                  - OnUIAppOpened
'                  - OnUIForceSize
' Control-Specific Events: <LIST EXTRA EVENTS HERE>
'
' NOTE: Replace the YYYY below with the latest year
'       in which your UI was developed.
'
' Copyright (c) 1999-YYYY Sage Software, Inc.  All rights reserved.
'

' ERROR HANDLING DONE FOR WHOLE FILE!

Option Compare Text
Option Explicit
Implements IObjectSafety


'---------------------------------------------------
' Enumerations
'---------------------------------------------------

Public Enum BackStyleChoice
    Transparent = 0
    Opaque = 1
End Enum

Public Enum BorderStyleChoice
    None = 0
    FixedSingle = 1
End Enum


'---------------------------------------------------
' Variables
'---------------------------------------------------

' Private dynamic control members
Private WithEvents ACCPACUICLOSED_frame As Frame  ' "UIClosed"-part
Attribute ACCPACUICLOSED_frame.VB_VarHelpID = -1
Private WithEvents ACCPACUICLOSED_lblMsg As Label  ' "UIClosed"-part
Attribute ACCPACUICLOSED_lblMsg.VB_VarHelpID = -1
' <PLACE OTHER PRIVATE DYNAMIC CONTROL MEMBERS HERE.>

' Tab Manager (for Q192208 SHIFT+TAB fix)
Private mTabManager As clsTabManager

' Special UI state private member flags
Private bResizeInfoAvailable As Boolean
Private bRunMode As Boolean
Private bUIAppIsOpen As Boolean
Private bAcceptUserClose As Boolean

' Localization resource retrieval private members
Private mIResTmpl As IResources
Private mIResApp As IResources
Private mIResUI As IResources
Private mstrLang As String
Private mstrMissingDLL As String  ' for error reporting

' Collections (private members)
Private mUIDBLinks As ACCPACDBLinks
Private mUIDSControls As ACCPACDSControls
Private mAppControls As ACCPACControls
Private mUIClosedControls As ACCPACControls  ' NOT exposed
Private mCustomCtls As ACCPACCustCtls  ' NOT exposed
' <PLACE OTHER COLLECTION PRIVATE MEMBERS HERE.  IF
'  A COLLECTION IS TO BE EXPOSED, REMEMBER TO
'  IMPLEMENT A "Property Get" FOR IT.>

' AccpacCOMAPI private members
Private mSessMgr As AccpacSessionMgr
Private mSession As AccpacSession
Private mDBLinkCmpRW As AccpacDBLink
' <PLACE OTHER AccpacCOMAPI PRIVATE MEMBERS HERE.>
' EXAMPLE: Private mDBLinkCmpRO As AccpacDBLink

' Default SAVED property value members: set in
' UC_Initialize and its callout (so if we want to
' change the default's VALUE, we only need to go to
' one place), accessed in ReadProperties AND
' WriteProperties, objects set to Nothing in
' UC_Terminate and its callout
Private mDefaultBackColor As OLE_COLOR
Private mDefaultBackStyle As BackStyleChoice
Private mDefaultBorderStyle As BorderStyleChoice
Private mDefaultFont As StdFont  ' value is Nothing
Private mDefaultForeColor As OLE_COLOR
Private mDefaultMaskColor As OLE_COLOR
Private mDefaultMaskPicture As StdPicture  ' value is Nothing
Private mDefaultPicture As StdPicture  ' value is Nothing
' <PLACE OTHER SAVED PROPERTIES' DEFAULT VALUE
'  PRIVATE MEMBERS HERE.>

' Font private member
Private WithEvents mFont As StdFont
Attribute mFont.VB_VarHelpID = -1

' "Customize" Box state-related private member
Private mstrCustLastProfileID As String

' Company ID private member
Private mstrCompanyID As String

' User access rights-related private members
Private bUserIsAdmin As Boolean
' <PLACE OTHER USER ACCESS RIGHTS-RELATED PRIVATE
'  MEMBERS HERE.>
Private bInquiryRight As Boolean
Private bSetupRight As Boolean

' Resource-related private picture members
Private micoABPic As IPictureDisp
' <PLACE OTHER RESOURCE-RELATED PRIVATE PICTURE
'  MEMBERS HERE.>

' Resource-related private string members
Private mstrACCPACUIName As String
Private mstrACCPACErrMBCap As String
Private mstrACCPACWarnMBCap As String
Private mstrAUINameIdent As String
Private mstrReopenTipsTxt As String
Private mstrUIInitFailTxt As String
Private mstrUIInitFailMBMsg As String
Private mstrAccessDeniedMsg As String
Private mstrActDSFailMsg As String
Private mstrCheckRightsFailMsg As String
Private mstrInitDBFailMsg As String
Private mstrInitIRIFailMsg As String
Private mstrLocUsePrevResMsg As String
Private mstrCannotOpenUIMsg As String
Private mstrNoHelpFileMsg As String
Private mstrNoUsingHelpMsg As String
Private mstrDelRecordMsg As String
Private mstrSaveRecordMsg As String
' <PLACE OTHER RESOURCE-RELATED PRIVATE STRING
'  MEMBERS HERE.>
Private mstrTestEmailSentSuccessed As String

' Lookup cookie private members
' <PLACE ANY LOOKUP COOKIE PRIVATE MEMBERS HERE.>

' Miscellaneous private members
Private itemResizeMainForm() As ITEM_RESIZE_INFO
Private msMinWidth As Single
Private msMinHeight As Single
Private mlSessionID As Long
Private mstrObjectHandle As String
Private mstrObjectKey As String
Private mstrReturnValue As String
Private mstrServerName As String
' <PLACE OTHER MISCELLANEOUS PRIVATE MEMBERS HERE.>


'---------------------------------------------------
' Event Declarations (For RAISED Events)
'---------------------------------------------------

Public Event AfterCtlClick(ByVal strFormName As String, _
                           ByVal strCtlName As String)
Attribute AfterCtlClick.VB_Description = "Raised by some controls on this ACCPAC UI (strFormName = """") or on its popup form AFTER default handling of the ""Click"" event (of strCtlName)."
Public Event BeforeCtlClick(ByVal strFormName As String, _
                            ByVal strCtlName As String, _
                            ByRef pStatus As AccpacCOMAPI.tagEventStatus)
Attribute BeforeCtlClick.VB_Description = "Raised by some controls on this ACCPAC UI (strFormName = """") or on its popup form BEFORE default handling of the ""Click"" event (of strCtlName).  The pStatus flag can be set to cancel the operation (unless it's STATUS_CANTDENY)."
Public Event BeforeUIAppClosed()
Attribute BeforeUIAppClosed.VB_Description = "Occurs right BEFORE this ACCPAC UI Control's application part closes.  Closing cannot be cancelled."
Public Event BeforeUIAppOpened()
Attribute BeforeUIAppOpened.VB_Description = "NOTE: DON'T HANDLE THIS EVENT UNLESS YOU ABSOLUTELY NEED TO.\r\nOccurs ONLY while this ACCPAC UI Control is handling its ""Show"" event, RIGHT BEFORE the ""Show"" event handler calls the application-part opening sequence."
Attribute BeforeUIAppOpened.VB_MemberFlags = "40"
Public Event CloseSplashScreen()
Attribute CloseSplashScreen.VB_Description = "NOTE: DON'T HANDLE THIS EVENT UNLESS YOU ABSOLUTELY NEED TO.\r\nRaised when the ACCPAC UI Control wants its container to close any open splash screens."
Attribute CloseSplashScreen.VB_MemberFlags = "40"
Public Event OnLaunchObject(ByVal strTargetClass As String, _
                            ByVal strCodebase As String, _
                            ByVal strObjectHandle As String)
Attribute OnLaunchObject.VB_Description = "Raised by this ACCPAC UI Control in order to get its container to open another ACCPAC UI Control."
Public Event OnLaunchURL(ByVal strURL As String)
Attribute OnLaunchURL.VB_Description = "Raised by this ACCPAC UI control in order to get its container to display the page specified by the URL."
Public Event OnPopupClosed(ByVal strPopupName As String)
Attribute OnPopupClosed.VB_Description = "Raised by a popup form (whose class name is strPopupName) when it is closed."
Public Event OnPopupOpened(ByVal strPopupName As String, _
                           ByRef PopupDSs As ACCPACDSControls, _
                           ByRef PopupCtls As ACCPACControls, _
                           ByRef strPopupCaption As String, _
                           ByRef icoPopup As StdPicture)
Attribute OnPopupOpened.VB_Description = "Raised by a popup form (whose class name is strPopupName) when it is opened (set up), but right before it is shown."
Public Event OnUIAppClosed()
Attribute OnUIAppClosed.VB_Description = "Occurs right AFTER this ACCPAC UI Control's application part has been closed.\r\nNOTE: This event may be raised WITHOUT ""OnUIAppOpened"" having been raised previously."
Public Event OnUIAppOpened()
Attribute OnUIAppOpened.VB_Description = "Occurs right AFTER the user has successfully opened this ACCPAC UI Control's application part."
Public Event OnUIForceSize(ByVal sNewWidth As Single, _
                           ByVal sNewHeight As Single, _
                           ByVal sTwipsPerPixelX As Single, _
                           ByVal sTwipsPerPixelY As Single)
Attribute OnUIForceSize.VB_Description = "Occurs AFTER this ACCPAC UI Control forces its own size to change to something different than what the container intended.  The container should resize itself accordingly."
' <PLACE OTHER EVENT DECLARATIONS HERE.>


'---------------------------------------------------
' Miscellaneous Event Handlers
'---------------------------------------------------

Private Sub APP_Close_Button_Click()
On Error Resume Next
    Debug.Print "APP_Close_Button_Click"
    
    DoEvents  ' MSDN Q74905 fix for order of events with accelerators vs. mouse
    
    ' Only close the UI's application part if we're
    ' actually ready to do so.  (We won't be ready
    ' to do so if there are unsaved changes and the
    ' user decides to cancel the action.)
    If QueryCloseUIApp = True Then
        ' Clear any errors from QueryCloseUIApp.
        Err.Clear
        
        ' Close the UI's application part (this will
        ' also display the "UIClosed" part after the
        ' session is closed).
        CloseUIApp
        If Err.Number <> 0 Then
            ' This is a programming error (as
            ' CloseUIApp should handle ALL of its
            ' errors), so just print a debug message
            ' and force a breakpoint to help
            ' diagnosis.
            Debug.Print "CloseUIApp should NOT be " _
                & "returning any errors to be" & _
                vbCrLf & "  handled in " & _
                "APP_Close_Button_Click!!!"
            Debug.Assert False  ' press F5 or F8 to continue
            Err.Clear
        End If  ' Err.Number <> 0
    End If  ' QueryCloseUIApp = True
    
    Err.Clear
End Sub

Private Sub APP_Save_Button_Click()
On Error Resume Next
    Debug.Print "APP_Save_Button_Click"
    
    DoEvents  ' MSDN Q74905 fix for order of events with accelerators vs. mouse
    SaveRecord  ' does the run mode/open checks
    Err.Clear
End Sub

Private Sub mFont_FontChanged(ByVal propertyName As String)
On Error Resume Next
    Debug.Print "mFont_FontChanged"
    
    Set UserControl.Font = mFont
    Refresh
    Err.Clear
End Sub


'---------------------------------------------------
' "Regular" Menu Event Handlers
'---------------------------------------------------

Private Sub mnuFile_Close_Click()
On Error Resume Next
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        APP_Close_Button_Click
    End If
    
    Err.Clear
End Sub

Private Sub mnuFile_Customize_Click()
On Error Resume Next
    If (bRunMode = True) _
      And (bUIAppIsOpen = True) _
      And (bUserIsAdmin = True) _
      Then
        CustomizeBox
    End If
    
    Err.Clear
End Sub

Private Sub mnuFile_PrintSetup_Click()
On Error GoTo mnuFilePrintSetupClickHandler
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        If mSession.IsRemote = False Then
            Dim ps As AccpacPrintSetup
            Dim bChanged As Boolean
            Dim pStatus As AccpacCOMAPI.tagEventStatus
            
            ' Allow macros to cancel the operation.
            pStatus = STATUS_OK
            RaiseEvent BeforeCtlClick("", _
                "mnuFile_PrintSetup", pStatus)
            If pStatus = STATUS_CANCEL Then
                Exit Sub
            End If
            
            ' It's a local server, so open up the
            ' "Print Setup" box.
            Set ps = mSession.GetPrintSetup( _
                       RptMenuID, ACCPACProgramName)
            
            ' Save changes made to the print setup.
            bChanged = ps.Query(UserControl.hwnd)
            If bChanged = True Then
                ps.Save
            End If
            
            Set ps = Nothing  ' no longer used
            
            ' Let macros add "after" functionality.
            RaiseEvent AfterCtlClick("", "mnuFile_PrintSetup")
        Else
            ' This is a programming error (as this
            ' menu item should be DISABLED by
            ' uncommented code in InitAppCtlsCallout
            ' if it's a remote server), so print a
            ' debug message and force a breakpoint
            ' to help diagnosis.
            Debug.Print "The ""Print Setup"" menu " _
                & "item should be DISABLED if the " _
                & vbCrLf & "  server is remote.  You " _
                & "need to UNCOMMENT the ""Report " _
                & vbCrLf & "  UI only"" section in " _
                & "the InitAppCtlsCallout sub."
            Debug.Assert False  ' press F5 or F8 to continue
        End If  ' mSession.IsRemote = False
    End If  ' (bRunMode = True) And (bUIAppIsOpen = True)
Exit Sub

mnuFilePrintSetupClickHandler:
    ' Just show the session errors (or VB error if
    ' there aren't any) and quit this operation.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True  ' clears error
End Sub

Private Sub mnuHelp_About_Click()
On Error Resume Next
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        Dim ab As AccpacAbout
        Dim bShown As Boolean
        
        ' Show the "About" box (or a "resources
        ' missing" message, though we WON'T be able
        ' to tell which resource DLL is missing).
        Set ab = New AccpacAbout
        bShown = ab.ShowAboutBox(mIResTmpl, _
                                 mIResApp, mIResUI, _
                                 mstrACCPACUIName)
        If bShown = False Then
            ' NOTE: UI PROGRAMMERS MUST USE
            '       mstrACCPACErrMBCap INSTEAD OF
            '       ACCPACErrMBCap.
            MsgBox ABNoLocResourcesMsg, _
                ACCPACErrMBStyle, ACCPACErrMBCap, _
                App.HelpFile, HCIDNoLocResources
        End If
        
        Set ab = Nothing  ' no longer used
    End If
    
    Err.Clear
End Sub

Private Sub mnuHelp_Contents_Click()
On Error Resume Next
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        Dim strHelpFile As String
        strHelpFile = App.HelpFile
        
        If (strHelpFile = "") Or (strHelpFile = vbNullString) Then
            ' Inform the user that there's no help
            ' file.  Use a message box that ONLY has
            ' an "OK" button (i.e. NO "Help" button,
            ' NO help files/contexts, and NO icons).
            MsgBox mstrNoHelpFileMsg, vbOKOnly, _
                mstrACCPACUIName  ' NO help information
        Else
            ' Log help event with the system when the help menu is selected
            LogAdvisorHelpEvent mSession, "mnuHelp_Contents", 0


            Dim hlpHWND As Long
            
            ' Go to the table of contents.
            hlpHWND = HtmlHelp(0, strHelpFile, _
                HH_DISPLAY_TOC, ByVal 0&)
            If hlpHWND = 0& Then
                ' Inform the user that there's no
                ' help file.
                MsgBox mstrNoHelpFileMsg, vbOKOnly, _
                    mstrACCPACUIName  ' NO help information
            End If  ' hlpHWND = 0&
        End If  ' (strHelpFile = "") Or (strHelpFile = vbNullString)
    End If  ' (bRunMode = True) And (bUIAppIsOpen = True)
    
    Err.Clear
End Sub

Private Sub mnuHelp_UsingHelp_Click()
On Error Resume Next
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        Dim strHelpFile As String
        strHelpFile = App.HelpFile
        
        If (strHelpFile = "") Or (strHelpFile = vbNullString) Then
            ' Inform the user that there's no help
            ' file.  Use a message box that ONLY has
            ' an "OK" button (i.e. NO "Help" button,
            ' NO help files/contexts, and NO icons).
            MsgBox mstrNoHelpFileMsg, vbOKOnly, _
                mstrACCPACUIName  ' NO help information
        Else
            ' Log help event with the system when the help menu is selected
            LogAdvisorHelpEvent mSession, "mnuHelp_UsingHelp", HCIDUsingHelp


            Dim hlpHWND As Long
            
            ' Go to the "Using Help" topic.
            hlpHWND = HtmlHelp(0, strHelpFile, _
               HH_HELP_CONTEXT, ByVal HCIDUsingHelp)
            If hlpHWND = 0& Then
                ' Inform the user that we can't find
                ' help for "Using Help".
                MsgBox mstrNoUsingHelpMsg, vbOKOnly, _
                    mstrACCPACUIName  ' NO help information
            End If  ' hlpHWND = 0&
        End If  ' (strHelpFile = "") Or (strHelpFile = vbNullString)
    End If  ' (bRunMode = True) And (bUIAppIsOpen = True)
    
    Err.Clear
End Sub


'---------------------------------------------------
' Popup Menu Event Handlers
'---------------------------------------------------
'
' Each popup menu item's event handler calls the
' associated "regular" menu item's event handler.
' Since these "regular" menu item event handlers
' clear errors upon entry and exit from them,
' there's no need to do "On Error..." here.
'

Private Sub popmnuFile_Close_Click()
    mnuFile_Close_Click
End Sub

Private Sub popmnuFile_Customize_Click()
    mnuFile_Customize_Click
End Sub

Private Sub popmnuFile_Print_Click()
    mnuFile_Print_Click
End Sub

Private Sub popmnuFile_PrintSetup_Click()
    mnuFile_PrintSetup_Click
End Sub

Private Sub popmnuHelp_About_Click()
    mnuHelp_About_Click
End Sub

Private Sub popmnuHelp_Contents_Click()
    mnuHelp_Contents_Click
End Sub

Private Sub popmnuHelp_UsingHelp_Click()
    mnuHelp_UsingHelp_Click
End Sub

'---------------------------------------------------
' ACCPAC UI Control Event Handlers
'---------------------------------------------------
'
' These are event handlers for controlling the
' lifetime of the whole ACCPAC UI UserControl.
'

Private Sub UserControl_EnterFocus()
On Error Resume Next
    ' This is part of the Q192208 SHIFT+TAB fix.
    mTabManager.ProcessEnterFocus
    Err.Clear
End Sub

Private Sub UserControl_ExitFocus()
On Error Resume Next
    ' This is part of the Q192208 SHIFT+TAB fix.
    mTabManager.ProcessExitFocus
    Err.Clear
End Sub

Private Sub UserControl_Hide()
On Error Resume Next
    Debug.Print "Hide"
    
    ' Close the UI's application part (if it isn't
    ' already closed).
    ' NOTE: It's TOO LATE to do QueryCloseUIApp, as
    '       the user has no chance to cancel the
    '       close operation (without causing memory
    '       and resource leaks).
    CloseUIApp
    If Err.Number <> 0 Then
        ' This is a programming error (as CloseUIApp
        ' should handle ALL of its errors), so just
        ' print a debug message and force a
        ' breakpoint to help diagnosis.  DON'T exit
        ' the sub, since we STILL need to (and can)
        ' do ClearCollections when CloseUIApp fails.
        Debug.Print "CloseUIApp should NOT be " & _
            "returning any errors to be" & vbCrLf & _
            "  handled in UC_Hide!!!"
        Debug.Assert False  ' press F5 or F8 to continue
        Err.Clear
    End If
    
    ' Try to clear the item resize information (even
    ' if it wasn't completely available) so that
    ' memory gets freed.  ClearItemResizeInfo will
    ' (ALWAYS) set bResizeInfoAvailable to False!!!
    ClearItemResizeInfo
    Err.Clear  ' ignore errors from ClearItemResizeInfo
    
    ' Destroy the collections (to free up memory).
    ClearCollections
    If Err.Number <> 0 Then
        ' This is a programming error (as
        ' ClearCollections should handle ALL of its
        ' errors), so just print a debug message and
        ' force a breakpoint to help diagnosis.
        ' DON'T exit the sub, since we STILL need to
        ' (and can) destroy the font object when
        ' ClearCollections fails.
        Debug.Print "ClearCollections should NOT be" _
            & " returning any errors to be" & vbCrLf _
            & "  handled in UC_Hide!!!"
        Debug.Assert False  ' press F5 or F8 to continue
        Err.Clear
    End If
    
    ' NOTE: Don't set dynamically created controls
    '       to Nothing and don't remove them from
    '       the Controls collection until
    '       UserControl_Terminate.
    
    ' Destroy the font object member.
    Set mFont = Nothing
    
    ' Destroy the localization resource object
    ' members.
    Set mIResUI = Nothing
    Set mIResApp = Nothing
    Set mIResTmpl = Nothing
    
    ' Destroy the picture members.
    SetDefaultPics
    
    ' Destroy the tab manager (this is part of the
    ' Q192208 SHIFT+TAB fix).
    Set mTabManager = Nothing
    
    Err.Clear
End Sub

' NO NEED FOR ERROR HANDLING!
Private Sub UserControl_Initialize()
    Debug.Print "Initialize"
    
    With UserControl
        ' Make sure we catch keypresses (for popup
        ' menu support) before passing them on to
        ' the constituent controls.
        .KeyPreview = True
        
        ' Set the scale mode to twips (this is
        ' needed in order for the dynamic controls
        ' to be created and resized correctly), THEN
        ' set the minimum width and height (now in
        ' twips) to the UI's "original" dimensions.
        .ScaleMode = vbTwips
        msMinWidth = .ScaleWidth  ' "original" width
        msMinHeight = .ScaleHeight  ' "original" height
    End With  ' UserControl
    
    ' Initialize the tab manager (this is part of
    ' the Q192208 SHIFT+TAB fix).
    Set mTabManager = Nothing
    
    ' Initialize the special UI state member flags.
    bResizeInfoAvailable = False
    bRunMode = True  ' assume run mode for now
    bUIAppIsOpen = False
    bAcceptUserClose = False
    
    ' Initialize the localization resource retrieval
    ' members.
    Set mIResTmpl = Nothing
    Set mIResApp = Nothing
    Set mIResUI = Nothing
    mstrLang = ""
    mstrMissingDLL = ""  ' for error reporting
    
    ' Create dynamic controls that AREN'T placed on
    ' the UI at **UI** design time (such as the
    ' "UIClosed"-part controls).
    CreateDynamicControls
    
    ' Set the (empty) help file, then default
    ' "resources" (mostly empty) for the UI, then
    ' HelpContextIDs for constituent controls.
    SetHelpFile
    SetDefaultResources  ' calls SetDefaultPics
    SetHelpIDs
    
    ' Set field edit control neighbor relationships.
    SetNeighbors
    
    ' Set the collection members to Nothing.
    Set mUIDBLinks = Nothing
    Set mUIDSControls = Nothing
    Set mAppControls = Nothing
    Set mUIClosedControls = Nothing
    Set mCustomCtls = Nothing
    
    ' Set the AccpacCOMAPI members to Nothing.
    Set mSessMgr = Nothing
    Set mSession = Nothing
    Set mDBLinkCmpRW = Nothing
    
    ' Make sure that all data sources are inactive.
    DeactivateDataSources
    
    ' Set the saved properties' default value
    ' members.
    mDefaultBackColor = vbButtonFace  ' light gray ("button face")
    mDefaultBackStyle = Opaque
    mDefaultBorderStyle = None
    Set mDefaultFont = Nothing
    mDefaultForeColor = vbButtonText  ' black
    mDefaultMaskColor = vbButtonText  ' black
    Set mDefaultMaskPicture = Nothing
    Set mDefaultPicture = Nothing
    
    ' Initialize the font member.
    Set mFont = New StdFont
    Set UserControl.Font = mFont
    
    ' Initialize the "Customize" Box state-related
    ' member.
    mstrCustLastProfileID = ""
    
    ' Initialize the company ID member.
    mstrCompanyID = ""
    
    ' Initialize (reset) the user access rights-
    ' related private members to default values.
    ResetAccessRights
    
    ' Initialize the captions of the looked-up
    ' controls and the corresponding lookup cookies.
    ClearLookupInfo
    
    ' Set miscellaneous members to default values.
    mstrObjectHandle = ""
    mstrObjectKey = ""
    mstrReturnValue = ""
    mstrServerName = ""
    mlSessionID = 0
    
    ' Do the "modifiable by UI programmers" part of
    ' the UserControl's initialization.
    InitializeUCCallout
End Sub

' NO NEED FOR ERROR HANDLING!  (THE CALLS TO
' InitAmbientProperties AND InitExtenderProperties
' HANDLE "No Ambient/Extender Available" CASES.)
Private Sub UserControl_InitProperties()
    Debug.Print "InitProperties"
    
    ' Initialize private members that base their
    ' values on Ambient/Extender object properties.
    InitAmbientProperties
    InitExtenderProperties
End Sub

' Popup menu support (from keyboard's "popup" key)
Private Sub UserControl_KeyUp(KeyCode As Integer, _
                              Shift As Integer)
On Error Resume Next
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        If KeyCode = ACCPACPopupMenuKeyCode Then
            UserControl.PopupMenu popmnuTopLevel, _
                            vbPopupMenuLeftAlign _
                            + vbPopupMenuRightButton
        End If  ' KeyCode = ACCPACPopupMenuKeyCode
    End If  ' (bRunMode = True) And (bUIAppIsOpen = True)
    
    Err.Clear
End Sub

' Popup menu support (from mouse's right button)
Private Sub UserControl_MouseDown(Button As Integer, _
                                  Shift As Integer, _
                                  X As Single, _
                                  Y As Single)
On Error Resume Next
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        If Button = vbRightButton Then
            UserControl.PopupMenu popmnuTopLevel, _
                            vbPopupMenuLeftAlign _
                            + vbPopupMenuRightButton
        End If  ' Button = vbRightButton
    End If  ' (bRunMode = True) And (bUIAppIsOpen = True)
    
    Err.Clear
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
On Error GoTo ReadPropertiesHandler
    Debug.Print "ReadProperties"
    
    ' Read in properties saved at design-time.
    If (Not (PropBag Is Nothing)) Then
        With PropBag
            BackColor = .ReadProperty("BackColor", mDefaultBackColor)
            BackStyle = .ReadProperty("BackStyle", mDefaultBackStyle)
            BorderStyle = .ReadProperty("BorderStyle", mDefaultBorderStyle)
            Set Font = .ReadProperty("Font", mDefaultFont)
            ForeColor = .ReadProperty("ForeColor", mDefaultForeColor)
            MaskColor = .ReadProperty("MaskColor", mDefaultMaskColor)
            Set MaskPicture = .ReadProperty("MaskPicture", mDefaultMaskPicture)
            Set Picture = .ReadProperty("Picture", mDefaultPicture)
            ' <READ IN ANY OTHER PROPERTIES THAT YOU
            '  SAVED IN WriteProperties.>
            
            ObjectHandle = .ReadProperty("ObjectHandle", "")
            ServerName = .ReadProperty("ServerName", "")
            SessionID = .ReadProperty("SessionID", 0)
            ' <READ IN ANY OTHER "NON-SAVED"
            '  PROPERTIES THAT YOU WANT TO READ IN
            '  FROM THE CONTAINER.>
        End With  ' PropBag
    End If
    
    ' Initialize private members that base their
    ' values on Ambient/Extender object properties.
    InitAmbientProperties
    InitExtenderProperties
    
    Debug.Print "Finished ReadProperties"
Exit Sub

ReadPropertiesHandler:
    ' This is a programming error, so print a debug
    ' message and force a breakpoint to help
    ' diagnosis.  Then, keep on going through this
    ' sub since it's NOT a fatal error if we miss
    ' initializing some of the UserControl's visual
    ' properties.  Since we're in an error handler,
    ' we need to call "Resume Next".
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' clears error
End Sub

' This happens AFTER InitProperties/ReadProperties
' IF the ACCPAC UI Control instance was placed
' (inside the container) at its ORIGINAL SIZE.  This
' happens BEFORE InitProperties/ReadProperties, but
' AFTER Initialize, IF the ACCPAC UI Control was
' placed (inside the container) at a DIFFERENT SIZE.
Private Sub UserControl_Resize()
On Error Resume Next
    Debug.Print "Resize"
    
    ' Set the scale mode to twips (just to be sure).
    UserControl.ScaleMode = vbTwips
    
    ' If the UI's application part is open (and it's
    ' run mode), update the active control's value
    ' to the data source (as it doesn't lose focus).
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        SaveActiveCtlValue
    End If
        
    If (ScaleWidth < msMinWidth) Or (ScaleHeight < msMinHeight) Then
        Dim sNewWidth As Single
        Dim sNewHeight As Single
        
        If ScaleWidth < msMinWidth Then
            sNewWidth = msMinWidth
        Else
            sNewWidth = ScaleWidth
        End If
        
        If ScaleHeight < msMinHeight Then
            sNewHeight = msMinHeight
        Else
            sNewHeight = ScaleHeight
        End If
        
        ' FORCE the UI back to the minimum width
        ' and/or height.
        Size sNewWidth, sNewHeight
        
        ' Resize the constituent controls if the
        ' resize information is available.
        If bResizeInfoAvailable = True Then
            SizeItems 0, sNewWidth, 0, sNewHeight, _
                    itemResizeMainForm
        End If
        
        ' Inform the container of the new UI size.
        With Screen
            RaiseEvent OnUIForceSize(sNewWidth, _
                    sNewHeight, .TwipsPerPixelX, _
                    .TwipsPerPixelY)
        End With  ' Screen
    Else
        ' Resize the constituent controls if the
        ' resize information is available.
        If bResizeInfoAvailable = True Then
            SizeItems 0, ScaleWidth, 0, ScaleHeight, _
                    itemResizeMainForm
        End If  ' bResizeInfoAvailable = True
    End If  ' (ScaleWidth < minWidth) Or (ScaleHeight < minHeight)
    
    ' Resize the "UIClosed" frame, THEN the message
    ' label properly (so if the "UIClosed" part has
    ' to be shown, it's properly resized).  (Offsets
    ' from left/right/top/bottom are included.)
    With ACCPACUICLOSED_frame
        .Width = UserControl.ScaleWidth _
                - (2 * ACCPACUICLOSEDFrameOffset)
        ACCPACUICLOSED_lblMsg.Move _
            ACCPACUICLOSEDLabelHorOffset, _
            ACCPACUICLOSEDLabelVerOffset, _
            .Width - (2 * _
                      ACCPACUICLOSEDLabelHorOffset), _
            .Height - (2 * _
                       ACCPACUICLOSEDLabelVerOffset)
    End With  ' ACCPACUICLOSED_frame
    
    ' <ADD ANY OTHER SPECIAL RESIZING CODE HERE.
    '  (i.e. EXTRA RESIZING CODE NOT COVERED BY THE
    '  "STANDARD" LAYOUT MANAGER'S WORK AND BY
    '  FILLING OUT THE itemResizeMainForm() ARRAY).>
    
    Err.Clear
End Sub

' This happens AFTER InitProperties/ReadProperties
' and Resize.
Private Sub UserControl_Show()
On Error Resume Next
    Debug.Print "Show"
    
    ' This sub needs to be called so that the (VB)
    ' container's "Activate" event can be raised
    ' (this is where it might initialize layout
    ' values for resizing the controls in the form).
    RefreshTopMenus
    
    ' Create the new tab manager if needed (this is
    ' part of the Q192208 SHIFT+TAB fix).
    If mTabManager Is Nothing Then
       Set mTabManager = New clsTabManager
       mTabManager.ClassConstruct UserControl.Controls
    End If
    
    ' Initialize the font member if it isn't already
    ' initialized (i.e. "UC_Hide" happened, then
    ' "UC_Show", but WITHOUT "UC_Initialize").
    If mFont Is Nothing Then
        Set mFont = New StdFont
        Set UserControl.Font = mFont
    End If
    
    ' Ignore any errors up to this point.
    Err.Clear
    
    ' If we're in RUN MODE, localize the UI (based
    ' on the last language used, if any).
    ' NOTE: This sets mIResTmpl, mIResApp, mIResUI,
    '       and mstrLang!!!
    If bRunMode = True Then
        LocalizeUI
        If Err.Number <> 0 Then
            ' Tell the user that localization failed
            ' (NO HELP for this) and show the UI in
            ' its "can't go any further" state.
            ' This sub raises OnUIAppClosed!!!
            DisplayLocalizeFailure
            
            ' GET OUT of this sub (we can't go on).
            Err.Clear
            Exit Sub
        End If  ' Err.Number <> 0
    End If  ' bRunMode = True
    
    ' Ignore any errors from testing bRunMode.
    Err.Clear
    
    ' IF WE GOT TO HERE AND WE'RE IN **RUN MODE**,
    ' WE MANAGED TO LOCALIZE THE UI.
    
    ' Initialize the collections.
    InitCollections
    If Err.Number <> 0 Then
        ' NOTE: We DON'T have to reverse any
        '       localizations (if it's run mode).
        
        ' Inform the user that UI initialization
        ' failed and show the UI in its "can't go
        ' any further" state.  This sub raises
        ' OnUIAppClosed!!!
        DisplayInitCollectionsFailure
        
        ' GET OUT of this sub (we can't go on).
        Err.Clear
        Exit Sub
    End If
    
    ' IF WE GOT TO HERE, WE MANAGED TO INITIALIZE
    ' THE COLLECTIONS.
    
    ' Initialize the item resize information, as it
    ' shouldn't be available yet.
    If bResizeInfoAvailable = False Then
        ' This sets bResizeInfoAvailable to True!!!
        InitItemResizeInfo
    Else
        ' This is a programming error (as the item
        ' resize information flag shouldn't be True
        ' until InitItemResizeInfo is called), so
        ' print a debug message and force a
        ' breakpoint to help diagnosis.
        Debug.Print "We should NOT have " & _
            """bResizeInfoAvailable = True"" in " & _
            "UC_Show" & vbCrLf & "  BEFORE the " & _
            "InitItemResizeInfo call."
        Debug.Assert False  ' press F5 or F8 to continue
    End If  ' bResizeInfoAvailable = False
    
    ' Raise the (hidden) "before application-part
    ' opening sequence" event and ignore any errors.
    RaiseEvent BeforeUIAppOpened
    Err.Clear
    
    ' Open the UI's application part.
    OpenUIApp
    If Err.Number <> 0 Then
        ' This is a programming error (as OpenUIApp
        ' should handle ALL of its errors), so print
        ' a debug message and force a breakpoint to
        ' help diagnosis.
        Debug.Print "OpenUIApp should NOT be " & _
            "returning any errors to be" & vbCrLf & _
            "  handled in UC_Show!!!"
        Debug.Assert False  ' press F5 or F8 to continue
        Err.Clear
    End If
End Sub

Private Sub UserControl_Terminate()
On Error Resume Next  ' clears any previous errors
    Debug.Print "Terminate"
    
    ' Make sure the font member is Nothing.
    Set mFont = Nothing
    
    ' Make sure the default property object members
    ' are Nothing.
    Set mDefaultPicture = Nothing
    Set mDefaultMaskPicture = Nothing
    Set mDefaultFont = Nothing
    
    ' Make sure all the data sources are inactive.
    DeactivateDataSources
    
    ' Make sure the collection members are Nothing.
    Set mCustomCtls = Nothing
    Set mUIClosedControls = Nothing
    Set mAppControls = Nothing
    Set mUIDSControls = Nothing
    Set mUIDBLinks = Nothing
    
    ' Make sure the localization resource object
    ' members are Nothing.
    Set mIResUI = Nothing
    Set mIResApp = Nothing
    Set mIResTmpl = Nothing
    
    ' Make sure all picture members are Nothing.
    SetDefaultPics
    
    ' Destroy dynamic controls that were created at
    ' UI run time in CreateDynamicControls (such as
    ' the "UIClosed"-part controls).
    DestroyDynamicControls
    
    ' Make sure the tab manager is Nothing (this is
    ' part of the Q192208 SHIFT+TAB fix).
    Set mTabManager = Nothing
    
    ' Do the "modifiable by UI programmers" part of
    ' the UserControl's termination.
    TerminateUCCallout
    
    Err.Clear
    
    Debug.Print "Finished terminate"
End Sub

' NO NEED FOR ERROR HANDLING!  (WriteProperties ONLY
' HAPPENS AT DESIGN TIME.)
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    Debug.Print "WriteProperties"
    
    ' Write out properties to be saved (design-time)
    If (Not (PropBag Is Nothing)) Then
        With PropBag
            .WriteProperty "BackColor", UserControl.BackColor, mDefaultBackColor
            .WriteProperty "BackStyle", UserControl.BackStyle, mDefaultBackStyle
            .WriteProperty "BorderStyle", UserControl.BorderStyle, mDefaultBorderStyle
            .WriteProperty "Font", UserControl.Font, mDefaultFont
            .WriteProperty "ForeColor", UserControl.ForeColor, mDefaultForeColor
            .WriteProperty "MaskColor", UserControl.MaskColor, mDefaultMaskColor
            .WriteProperty "MaskPicture", UserControl.MaskPicture, mDefaultMaskPicture
            .WriteProperty "Picture", UserControl.Picture, mDefaultPicture
            ' <WRITE OUT ANY OTHER "SAVED"
            '  PROPERTIES.  ALL "SAVED" PROPERTIES
            '  MUST BE READ IN BY ReadProperties.>
        End With  ' PropBag
    End If
End Sub

Private Sub UserControl_KeyDown(KeyCode As Integer, Shift As Integer)
On Error Resume Next
    ' Log help event with the system when F1 is pressed
    If KeyCode = vbKeyF1 Then
        If Not ActiveControl Is Nothing Then
            LogAdvisorHelpEvent mSession, ActiveControl.Name, ActiveControl.HelpContextID
        End If
    End If
    Err.Clear
   ' <ADD ANY OTHER SPECIAL KEYDOWN CODE HERE.>
End Sub



'---------------------------------------------------
' IObjectSafety Implementation
'---------------------------------------------------
'
' This is the IObjectSafety implementation from MSDN
' article Q182598.  It marks the ACCPAC UI Control
' as safe for scripting and initialization.
' NO NEED FOR ERROR HANDLING!
'

Private Sub IObjectSafety_GetInterfaceSafetyOptions( _
                        ByVal riid As Long, _
                        pdwSupportedOptions As Long, _
                        pdwEnabledOptions As Long)
    Dim Rc      As Long
    Dim rClsId  As udtGUID
    Dim IID     As String
    Dim bIID()  As Byte
    
    pdwSupportedOptions = INTERFACESAFE_FOR_UNTRUSTED_CALLER Or _
                          INTERFACESAFE_FOR_UNTRUSTED_DATA
    
    If (riid <> 0) Then
        CopyMemory rClsId, ByVal riid, Len(rClsId)
        
        bIID = String$(MAX_GUIDLEN, 0)
        Rc = StringFromGUID2(rClsId, _
                       VarPtr(bIID(0)), MAX_GUIDLEN)
        Rc = InStr(1, bIID, vbNullChar) - 1
        IID = Left$(UCase(bIID), Rc)
        
        Select Case IID
            Case IID_IDispatch
                pdwEnabledOptions = IIf(m_fSafeForScripting, _
                    INTERFACESAFE_FOR_UNTRUSTED_CALLER, _
                    0)
                Exit Sub
            Case IID_IPersistStorage, _
                 IID_IPersistStream, _
                 IID_IPersistPropertyBag
                pdwEnabledOptions = IIf(m_fSafeForInitializing, _
                    INTERFACESAFE_FOR_UNTRUSTED_DATA, _
                    0)
                Exit Sub
            Case Else
                Err.Raise E_NOINTERFACE
                Exit Sub
        End Select
    End If
End Sub

Private Sub IObjectSafety_SetInterfaceSafetyOptions( _
                    ByVal riid As Long, _
                    ByVal dwOptionsSetMask As Long, _
                    ByVal dwEnabledOptions As Long)
    Dim Rc          As Long
    Dim rClsId      As udtGUID
    Dim IID         As String
    Dim bIID()      As Byte
    
    If (riid <> 0) Then
        CopyMemory rClsId, ByVal riid, Len(rClsId)
        
        bIID = String$(MAX_GUIDLEN, 0)
        Rc = StringFromGUID2(rClsId, _
                       VarPtr(bIID(0)), MAX_GUIDLEN)
        Rc = InStr(1, bIID, vbNullChar) - 1
        IID = Left$(UCase(bIID), Rc)
        
        Select Case IID
            Case IID_IDispatch
                If ((dwEnabledOptions And _
                     dwOptionsSetMask) <> _
                    INTERFACESAFE_FOR_UNTRUSTED_CALLER) _
                  Then
                    Err.Raise E_FAIL
                    Exit Sub
                Else
                    If Not m_fSafeForScripting Then
                        Err.Raise E_FAIL
                    End If
                    Exit Sub
                End If
            Case IID_IPersistStorage, _
                 IID_IPersistStream, _
                 IID_IPersistPropertyBag
                If ((dwEnabledOptions And _
                     dwOptionsSetMask) <> _
                    INTERFACESAFE_FOR_UNTRUSTED_DATA) _
                  Then
                    Err.Raise E_FAIL
                    Exit Sub
                Else
                    If Not m_fSafeForInitializing Then
                        Err.Raise E_FAIL
                    End If
                    Exit Sub
                End If
            Case Else
                Err.Raise E_NOINTERFACE
                Exit Sub
        End Select
    End If
End Sub


'---------------------------------------------------
' General UI Initialization/Termination Helpers
'---------------------------------------------------

' This sub is used to create dynamic controls (i.e.
' controls that AREN'T already placed on the UI at
' **UI** design time).  This includes the frame and
' label that make up the "UIClosed" part.
' NO NEED FOR ERROR HANDLING!
' (LET VB GPF IF THERE'S A PROBLEM: IT'S PROBABLY
'  CAUSED BY A PROGRAMMING OR MEMORY ERROR.  THIS IS
'  WHY WE'RE NOT GOING TO CHECK IF THE CONTROL IS
'  NOTHING AFTER WE DO "Set <ctl> = Controls.Add".)
Private Sub CreateDynamicControls()
    Debug.Print "CreateDynamicControls"
    
    ' Make sure we are working in units of twips.
    UserControl.ScaleMode = vbTwips
    
    ' NOTE: Don't show any of these dynamic controls
    '       at first, just in case InitCollections
    '       fails.  Also, captions and
    '       HelpContextIDs will be set later.
    
    ' ***** "UIClosed"-Part Dynamic Controls *****
    
    ' Create the frame.  (Its width includes left
    ' AND right offsets.)
    Set ACCPACUICLOSED_frame = Controls.Add( _
                   "VB.Frame", "ACCPACUICLOSED_frame")
    With ACCPACUICLOSED_frame
        ' NOTE: "Visible" is FALSE by default.
        .Enabled = False  ' disable it at first
        .Move ACCPACUICLOSEDFrameOffset, _
            ACCPACUICLOSEDFrameOffset, _
            UserControl.ScaleWidth - (2 * _
                ACCPACUICLOSEDFrameOffset), _
            ACCPACUICLOSEDFrameHeight
    End With  ' ACCPACUICLOSED_frame
    
    ' Create the label for the "closed" message.
    ' (Its width includes left AND right offsets.)
    Set ACCPACUICLOSED_lblMsg = Controls.Add( _
            "VB.Label", "ACCPACUICLOSED_lblMsg", _
            ACCPACUICLOSED_frame)
    With ACCPACUICLOSED_lblMsg
        ' NOTE: "Visible" is FALSE by default.
        .Enabled = False  ' disable it at first
        .Move ACCPACUICLOSEDLabelHorOffset, _
            ACCPACUICLOSEDLabelVerOffset, _
            ACCPACUICLOSED_frame.Width - (2 * _
                ACCPACUICLOSEDLabelHorOffset), _
            ACCPACUICLOSED_frame.Height - (2 * _
                ACCPACUICLOSEDLabelVerOffset)
    End With  ' ACCPACUICLOSED_lblMsg
    
    ' ***** Other Dynamic Controls *****
    
    ' <CREATE ANY OTHER DYNAMIC CONTROL IN A MANNER
    '  SIMILAR TO WHAT'S DONE IN THE "UIClosed"-PART
    '  SECTION.  THE CONTROL NEEDS A "WithEvents"
    '  PRIVATE MEMBER (IN THE "Declarations"
    '  SECTION) SO THAT YOU CAN HANDLE ITS EVENTS.>
End Sub

' This sub is called from InitProperties and
' ReadProperties as part of the template code.  IT
' SHOULD NOT BE CALLED FROM ANYWHERE ELSE.
' The only error to handle is "No Amb. Available".
Private Sub InitAmbientProperties()
On Error GoTo InitAmbientPropertiesHandler
    Debug.Print "InitAmbientProperties"
    
    ' Set the private members that GET their values
    ' based on the Ambient object's properties.
    ' NOTE: DON'T do a "With Ambient" block (so the
    '       error handler WON'T need "structural"
    '       change).
    bRunMode = Ambient.UserMode  ' T = run, F = design
    ' <SET ANY OTHER PRIVATE MEMBERS THAT DEPEND ON
    '  THE Ambient OBJECT'S PROPERTIES.  REMEMBER TO
    '  SET THEIR DEFAULT VALUES INSIDE THIS SUB'S
    '  ERROR HANDLER AND IN "InitializeUCCallout".>
Exit Sub

InitAmbientPropertiesHandler:
    With Err
        If .Number = 398 Then
            ' The Ambient object isn't available, so
            ' set private members to default values.
            bRunMode = True  ' assume it's run time
            ' <SET DEFAULTS FOR ANY OTHER Ambient-
            '  DEPENDENT PRIVATE MEMBERS THAT WERE
            '  SET IN THE MAIN PART OF THIS SUB.>
            
            .Clear  ' we've now handled the "error"
        Else
            ' RE-RAISE any other errors.
            .Raise .Number, .Source, .Description, _
                .HelpFile, .HelpContext
        End If
    End With  ' Err
End Sub

' This sub is called from InitProperties and
' ReadProperties as part of the template code.  IT
' SHOULD NOT BE CALLED FROM ANYWHERE ELSE.
' NOTE: VB Documentation suggests NOT TO SET
'       Extender properties, but you can GET them.
' The only error to handle is "No Ext. Available".
Private Sub InitExtenderProperties()
' Ignore errors while hiding/disabling controls and
' setting the program name of ACCPAC data sources.
On Error Resume Next
    Debug.Print "InitExtenderProperties"
    
    Dim ctl As Control
    For Each ctl In Controls
        If (Not (ctl Is Nothing)) Then
            With ctl
                ' Hide/disable the control for now.
                .Visible = False
                .Enabled = False
                
                ' IF it's runtime, set the program
                ' name of all ACCPAC data sources.
                ' (bRunMode is ALREADY set properly
                ' as InitAmbientProperties happens
                ' BEFORE this sub.)
                If (TypeOf ctl Is AccpacDataSource) _
                  And (bRunMode = True) _
                  Then
                    .ProgramName = ACCPACProgramName
                End If
            End With  ' ctl
        End If
    Next ctl
    
' Switching error traps automatically clears Err.
On Error GoTo InitExtenderPropertiesHandler
    ' <SET ANY PRIVATE MEMBERS THAT DEPEND ON THE
    '  Extender OBJECT'S PROPERTIES.  REMEMBER TO
    '  SET THEIR DEFAULT VALUES INSIDE THIS SUB'S
    '  ERROR HANDLER AND IN "InitializeUCCallout".>
    ' NOTE: DON'T do a "With Extender" block (so the
    '       error handler WON'T need "structural"
    '       change).
Exit Sub

InitExtenderPropertiesHandler:
    With Err
        If .Number = 398 Then
            ' <SINCE THE Extender OBJECT ISN'T
            '  AVAILABLE, SET DEFAULTS FOR ANY
            '  Extender-DEPENDENT PRIVATE MEMBERS
            '  THAT WERE SET IN THE MAIN PART OF
            '  THIS SUB.>
            
            
            .Clear  ' we've now handled the "error"
        Else
            ' RE-RAISE any other errors.
            .Raise .Number, .Source, .Description, _
                .HelpFile, .HelpContext
        End If
    End With  ' Err
End Sub

' This sub is called (by UC_Show or OpenUIApp) if
' LocalizeUI propagates its errors to its caller.
' (Ignore any errors that occur within this sub
' itself.)
Private Sub DisplayLocalizeFailure()
On Error Resume Next
    Debug.Print "DisplayLocalizeFailure"
    
    Dim strDLLName As String
    
    ' Create the complete DLL name (with extension).
    strDLLName = mstrMissingDLL & ".dll"
    
    ' Hide and disable all of the controls first.
    ' NOTE: The wrapped control collections may not
    '       have been created yet!
    Dim ctl As Control
    For Each ctl In Controls
        If (Not (ctl Is Nothing)) Then
            With ctl
                .Visible = False
                .Enabled = False
            End With  ' ctl
        End If
    Next ctl
    
    ' Pop up a message box to make sure the user
    ' realizes that there's no localized resources.
    ' (This message is in ENGLISH and has NO HELP).
    ' NOTE: UI PROGRAMMERS MUST USE
    '       mstrACCPACErrMBCap INSTEAD OF
    '       ACCPACErrMBCap.
    RaiseEvent CloseSplashScreen
    MsgBox AUINoLocResourcesMsg & " " & strDLLName, _
        ACCPACErrMBStyle - vbMsgBoxHelpButton, _
        ACCPACErrMBCap
    
    ' Display the "UIClosed" part with the "can't go
    ' any further" message (in ENGLISH), which tells
    ' the user to exit.
    ' NOTE: The wrapped control collections may not
    '       have been created yet!
    If (Not (ACCPACUICLOSED_frame Is Nothing)) _
      And (Not (ACCPACUICLOSED_lblMsg Is Nothing)) _
      Then
        With ACCPACUICLOSED_frame
            .Enabled = True
            .Visible = True
        End With  ' ACCPACUICLOSED_frame
        
        With ACCPACUICLOSED_lblMsg
            ' NOTE: UI PROGRAMMERS SHOULDN'T USE THE
            '       LocUIFailTxt AND ReopenTipsTxt
            '       CONSTANTS.
            .Caption = LocUIFailTxt & " " & _
                strDLLName & vbCrLf & vbCrLf & _
                ReopenTipsTxt
            .Enabled = True
            .Visible = True
        End With  ' ACCPACUICLOSED_lblMsg
    End If
    
    ' Notify others that the UI's application part
    ' is now closed (and clear errors).
    RaiseOnUIAppClosed
    Err.Clear
End Sub

' This sub is called (by UC_Show) if InitCollections
' propagates its errors to UC_Show.  (Ignore any
' errors that occur within this sub itself.)
' NOTE: Localized strings need defaults so that
'       error messages can be shown in design mode.
Private Sub DisplayInitCollectionsFailure()
On Error Resume Next
    Debug.Print "DisplayInitCollectionsFailure"
    
    ' Hide and disable all of the controls first.
    ' NOTE: The wrapped control collections probably
    '       don't exist!
    Dim ctl As Control
    For Each ctl In Controls
        If (Not (ctl Is Nothing)) Then
            With ctl
                .Visible = False
                .Enabled = False
            End With  ' ctl
        End If
    Next ctl
    
    ' Pop up a message box to make sure the user
    ' realizes that UI initialization failed (there
    ' will be NO HELP).
    RaiseEvent CloseSplashScreen
    MsgBox mstrUIInitFailMBMsg, ACCPACErrMBStyle _
        - vbMsgBoxHelpButton, mstrACCPACErrMBCap
    
    ' Display the "UIClosed" part with the "can't go
    ' any further" message, which tells the user to
    ' exit.
    ' NOTE: The wrapped control collections probably
    '       don't exist!
    If (Not (ACCPACUICLOSED_frame Is Nothing)) _
      And (Not (ACCPACUICLOSED_lblMsg Is Nothing)) _
      Then
        With ACCPACUICLOSED_frame
            .Enabled = True
            .Visible = True
        End With  ' ACCPACUICLOSED_frame
        
        With ACCPACUICLOSED_lblMsg
            .Caption = mstrUIInitFailTxt & vbCrLf & _
                vbCrLf & mstrReopenTipsTxt
            .Enabled = True
            .Visible = True
        End With  ' ACCPACUICLOSED_lblMsg
    End If
    
    ' Notify others that the UI's application part
    ' is now closed (and clear errors).
    RaiseOnUIAppClosed
    Err.Clear
End Sub

' NOTE: This sub is called EVEN if item resize
'       information wasn't properly initialized.
Private Sub ClearItemResizeInfo()
On Error GoTo ClearItemResizeInfoHandler
    Debug.Print "ClearItemResizeInfo"
    
    ' Clear each itemResizeMainForm item.
    Dim i As Long
    For i = LBound(itemResizeMainForm) To UBound(itemResizeMainForm)
        With itemResizeMainForm(i)
            Set .controlID = Nothing
            .offsetFromBottom = 0
            .offsetFromRight = 0
            .resizeFlags = MOVE_NONE
        End With  ' itemResizeMainForm(i)
    Next i
    
    ' Erase the array (to free memory).
    Erase itemResizeMainForm
    
    ' Assume that item resize information was
    ' cleared anyways (as we won't need it anymore).
    bResizeInfoAvailable = False
Exit Sub

ClearItemResizeInfoHandler:
    ' Print a debug message for the programmer to
    ' help with diagnosis, then keep on going.
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next  ' clears error
End Sub

' This sub destroys dynamically created controls
' (from CreateDynamicControls).  This includes
' destroying the frame and label that make up the
' "UIClosed" part.
Private Sub DestroyDynamicControls()
On Error Resume Next
    Debug.Print "DestroyDynamicControls"
    
    With Controls
        ' Remove the "UIClosed" part controls from
        ' the Controls collection.
        ' NOTE: Since the label is contained in the
        '       frame, remove the LABEL first.
        .Remove "ACCPACUICLOSED_lblMsg"
        .Remove "ACCPACUICLOSED_frame"
        
        ' <REMOVE OTHER DYNAMIC CONTROLS FROM THE
        '  CONTROLS COLLECTION IN A SIMILAR MANNER.
        '  THE KEY INTO THE COLLECTION IS THE STRING
        '  PASSED AS THE SECOND ARGUMENT TO THE
        '  Controls.Add METHOD USED TO CREATE THE
        '  CONTROL IN CreateDynamicControls.  IF A
        '  DYNAMIC CONTROL CONTAINS OTHER DYNAMIC
        '  CONTROLS, THE CONTAINED CONTROLS MUST BE
        '  REMOVED FIRST.>
    End With  ' Controls
    
    ' Set the "UIClosed" part control members to
    ' Nothing.
    Set ACCPACUICLOSED_frame = Nothing
    Set ACCPACUICLOSED_lblMsg = Nothing
    
    ' <SET OTHER DYNAMIC CONTROL MEMBERS TO NOTHING
    '  IN A SIMILAR MANNER.>
    
    
    Err.Clear
End Sub


'---------------------------------------------------
' Subs for Initializing and Clearing Collections
'---------------------------------------------------
'
' These subs are responsible for creating ALL of the
' new collection objects, populating the collection
' of data source controls (UIDSControls), the
' collection of application-part controls
' (UIAppControls), the collection of "UIClosed"-part
' controls (mUIClosedControls), and the collection
' of customizable application-part controls
' (mCustomCtls), clearing these collections, making
' sure other collections are cleared, and finally
' destroying ALL of the collections.
'

' NOTE: Errors are RE-RAISED (to get to UC_Show).
Private Sub InitCollections()
On Error GoTo InitCollectionsHandler
    Debug.Print "InitCollections"
    
    ' Make the new private collections.
    Set mUIDBLinks = New ACCPACDBLinks
    Set mUIDSControls = New ACCPACDSControls
    Set mAppControls = New ACCPACControls
    Set mUIClosedControls = New ACCPACControls
    Set mCustomCtls = New ACCPACCustCtls
    ' <SET ANY OTHER PRIVATE COLLECTION MEMBERS AS
    '  NEW OBJECTS OF THE APPROPRIATE TYPES.>
    
    ' We DON'T need to add DB links to mUIDBLinks.
    ' Adding is done in InitDBLinks (called from
    ' AppOpenSeqRollback).  Removing is done in
    ' CloseDBLinks (called from AppCloseSequence).
    
    ' Add data source controls to mUIDSControls, add
    ' application-part controls to mAppControls and
    ' to mCustomCtls if customizable, and add
    ' "UIClosed"-part controls to mUIClosedControls.
    ' (Errors in "Add" need to be re-raised in order
    ' to get to this sub's handler.)
    ' NOTE: "Invisible at runtime" controls are NOT
    '       part of the application part or the
    '       "UIClosed" part.
    Dim ctl As Control
    For Each ctl In Controls
        If (Not (ctl Is Nothing)) Then
            Dim ctlName As String
            
            ' Save the control's name in a variable
            ' (for efficiency).
            ctlName = ctl.Name
            
            If (TypeOf ctl Is AccpacDataSource) Then
                ' Add to data source control
                ' collection
                mUIDSControls.Add ctl
                With Err
                    If .Number <> 0 Then
                        .Raise .Number, .Source, _
                            .Description, .HelpFile, _
                            .HelpContext
                    End If
                End With  ' Err
            ElseIf (ctlName = "ACCPACUICLOSED_frame") _
              Or (ctlName = "ACCPACUICLOSED_lblMsg") _
              Then
                ' Add to "UIClosed"-part collection
                mUIClosedControls.Add ctl
                With Err
                    If .Number <> 0 Then
                        .Raise .Number, .Source, _
                            .Description, .HelpFile, _
                            .HelpContext
                    End If
                End With  ' Err
            ' <ADD CHECKS TO THE "ELSEIF" CONDITION
            '  BELOW FOR "INVISIBLE AT RUNTIME"
            '  CONTROL TYPES.  (THESE AREN'T IN THE
            '  APPLICATION OR "UIClosed" PARTS.)>
            ElseIf (Not (TypeOf ctl Is CommonDialog)) _
              And (Not (TypeOf ctl Is AccpacFieldGroup)) _
              And (Not (TypeOf ctl Is Timer)) _
              Then
                Dim aCtl As ACCPACControl
                
                ' Add to application-part collection
                Set aCtl = mAppControls.Add(ctl)
                With Err
                    If .Number <> 0 Then
                        .Raise .Number, .Source, _
                            .Description, .HelpFile, _
                            .HelpContext
                    End If
                End With  ' Err
                
                ' Customizable controls are the
                ' application-part controls that are
                ' NOT the "Close" button, menus,
                ' lines, scroll bars, tabbed pages,
                ' and other "odd" controls.
                ' <ADD CHECKS TO THE "IF" CONDITION
                '  FOR TYPES OF CONTROLS AND/OR
                '  NAMES OF INDIVIDUAL CONTROLS THAT
                '  YOU **DON'T** WANT TO CUSTOMIZE.>
                If (Not (TypeOf ctl Is Menu)) _
                  And (Not (ctlName = "APP_Close_Button")) _
                  And (Not (TypeOf ctl Is SSTab)) _
                  And (Not (TypeOf ctl Is Line)) _
                  And (Not (TypeOf ctl Is HScrollBar)) _
                  And (Not (TypeOf ctl Is ImageList)) _
                  And (Not (TypeOf ctl Is OLE)) _
                  And (Not (TypeOf ctl Is Shape)) _
                  And (Not (TypeOf ctl Is TabStrip)) _
                  And (Not (TypeOf ctl Is VScrollBar)) _
                  Then
                    ' Add the corresponding
                    ' ACCPACControl to mCustomCtls
                    mCustomCtls.Add aCtl
                    With Err
                        If .Number <> 0 Then
                            .Raise .Number, .Source, _
                                .Description, _
                                .HelpFile, _
                                .HelpContext
                        End If
                    End With  ' Err
                End If
                
                Set aCtl = Nothing
            End If  ' ctl Is AccpacDataSource /
                    ' ElseIf ctl Is in "UIClosed" part /
                    ' ElseIf ctl ISN'T another "invisible at runtime" control
        End If  ' Not (ctl Is Nothing)
    Next ctl
    
    ' Print the counts out (for the UI programmer).
    ' NOTE: We MUST still check if the collections
    '       are Nothing (as function calls within
    '       Debug.Print strings aren't stripped from
    '       the compiled product).
    If mUIDSControls Is Nothing Then
        Debug.Print "Inside InitCollections: mUIDSControls is Nothing"
    Else
        Debug.Print "Total number of data source controls = " _
            & CStr(mUIDSControls.Count)
    End If
    
    If mUIClosedControls Is Nothing Then
        Debug.Print "Inside InitCollections: mUIClosedControls is Nothing"
    Else
        Debug.Print "Total number of ""UIClosed""-part controls = " _
            & CStr(mUIClosedControls.Count)
    End If
    
    If mAppControls Is Nothing Then
        Debug.Print "Inside InitCollections: mAppControls is Nothing"
    Else
        Debug.Print "Total number of application-part controls = " _
            & CStr(mAppControls.Count)
    End If
    
    If mCustomCtls Is Nothing Then
        Debug.Print "Inside InitCollections: mCustomCtls is Nothing"
    Else
        Debug.Print "Total number of customizable controls = " _
            & CStr(mCustomCtls.Count)
    End If
    
    ' <ADD ITEMS TO OTHER PRIVATE COLLECTION MEMBERS
    '  HERE OR IN ANOTHER FUNCTION.>
    
    ' NOTE: DON'T clear errors, as they should be
    '       PROPAGATED to UC_Show.
Exit Sub

InitCollectionsHandler:
    ' Just print a debug message and PROPAGATE THE
    ' ERROR to UC_Show (which then calls
    ' DisplayInitCollectionsFailure, where the user
    ' is shown a meaningful error message and
    ' "OnUIAppClosed" is raised).  Since the control
    ' must then be destroyed, UC_Hide will happen.
    ' It calls ClearCollections to clear collections
    ' that exist (and ignore "Nothing" collections).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, False  ' PROPAGATES the error
End Sub

Private Sub ClearCollections()
On Error GoTo ClearCollectionsHandler
    Debug.Print "ClearCollections"
    
    Dim i As Long
    
    ' Removal algorithm: Remove the front control
    ' (the one with index = 1) from the collection
    ' until there are none left.  After the front
    ' control is removed, what was the next control
    ' (used to be index = 2) becomes the new front
    ' control (i.e. its index becomes 1).
    
    ' Remove customizable application-part controls
    ' from mCustomCtls (if it still exists).
    If mCustomCtls Is Nothing Then
        Debug.Print "Inside ClearCollections: mCustomCtls is Nothing"
    Else
        With mCustomCtls
            Debug.Print "mCustomCtls.Count = " & CStr(.Count)
            For i = 1 To .Count
                .Remove 1
            Next i
            Debug.Print "Final mCustomCtls.Count = " & CStr(.Count)
        End With  ' mCustomCtls
    End If
    
    ' Remove application-part controls from
    ' mAppControls (if it still exists).
    If mAppControls Is Nothing Then
        Debug.Print "Inside ClearCollections: mAppControls is Nothing"
    Else
        With mAppControls
            Debug.Print "mAppControls.Count = " & CStr(.Count)
            For i = 1 To .Count
                .Remove 1
            Next i
            Debug.Print "Final mAppControls.Count = " & CStr(.Count)
        End With  ' mAppControls
    End If
    
    ' Remove "UIClosed"-part controls from
    ' mUIClosedControls (if it still exists).
    If mUIClosedControls Is Nothing Then
        Debug.Print "Inside ClearCollections: mUIClosedControls is Nothing"
    Else
        With mUIClosedControls
            Debug.Print "mUIClosedControls.Count = " & CStr(.Count)
            For i = 1 To .Count
                .Remove 1
            Next i
            Debug.Print "Final mUIClosedControls.Count = " & CStr(.Count)
        End With  ' mUIClosedControls
    End If
    
    ' Remove data source controls from mUIDSControls
    ' (if it still exists).
    If mUIDSControls Is Nothing Then
        Debug.Print "Inside ClearCollections: mUIDSControls is Nothing"
    Else
        With mUIDSControls
            Debug.Print "mUIDSControls.Count = " & CStr(.Count)
            For i = 1 To .Count
                .Remove 1
            Next i
            Debug.Print "Final mUIDSControls.Count = " & CStr(.Count)
        End With  ' mUIDSControls
    End If
    
    ' JUST IN CASE: Remove any remaining DB links
    ' from mUIDBLinks (if it still exists).  There
    ' shouldn't be any DB links left to remove here,
    ' as they are supposed to be removed in
    ' CloseDBLinks (called from AppCloseSequence).
    If mUIDBLinks Is Nothing Then
        Debug.Print "Inside ClearCollections: mUIDBLinks is Nothing"
    Else
        With mUIDBLinks
            Debug.Print "mUIDBLinks.Count = " & CStr(.Count)
            For i = 1 To .Count
                .Remove 1
            Next i
            Debug.Print "Final mUIDBLinks.Count = " & CStr(.Count)
        End With  ' mUIDBLinks
    End If
    
    ' <REMOVE ITEMS FROM OTHER PRIVATE COLLECTION
    '  MEMBERS HERE OR IN ANOTHER FUNCTION.  EVEN IF
    '  THE ITEMS ARE REMOVED IN ANOTHER FUNCTION,
    '  IT'S STILL A GOOD IDEA TO LOOP THROUGH THE
    '  COLLECTIONS AGAIN HERE TO REMOVE ANYTHING
    '  THAT SOMEHOW DIDN'T GET REMOVED EARLIER.>
    
    ' Now, destroy the collection members.
    Set mUIClosedControls = Nothing
    Set mCustomCtls = Nothing
    Set mAppControls = Nothing
    Set mUIDSControls = Nothing
    Set mUIDBLinks = Nothing
    ' <SET ANY OTHER PRIVATE COLLECTION MEMBERS TO
    '  NOTHING.>

    ' We STILL need to clear any errors (as some
    ' don't cause a jump to this sub's handler).
    Err.Clear
Exit Sub

ClearCollectionsHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message.  (With "Resume
    ' Next", we are guaranteed to attempt the "set
    ' all collections to Nothing" part.)
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next  ' clears error
End Sub


'---------------------------------------------------
' ACCPAC UI Application-Part Opening Functions
'---------------------------------------------------

Private Sub OpenUIApp()
On Error GoTo OpenUIAppHandler
    Debug.Print "OpenUIApp"
    
    If bRunMode = False Then
        ' We're in design mode, so we don't try to
        ' open a session.  When we call EnableApp
        ' (it doesn't matter which boolean argument
        ' we put in), ONLY the application part is
        ' enabled/shown.
        EnableApp True
    ElseIf bUIAppIsOpen = False Then
        ' NOTE: We have "pre-signon" localized
        '       resources already!
        
        ' We're in run mode and the UI's application
        ' part isn't (supposed to be) open.  Thus,
        ' DON'T enable/show ANY controls yet.
        ShowAppControls False
        ShowUIClosedControls False
        
        ' Try to open a session. OpenSession will
        ' set the bUIAppIsOpen flag!!!  (OpenSession
        ' handles its own errors.)
        OpenSession
        
        ' Once we've attempted to open a session,
        ' proceed based on whether or not we were
        ' successful in doing so.
        If bUIAppIsOpen = False Then
            ' We couldn't open a session, so we
            ' can't open the UI (application part).
            ' NOTE: This just has an "OK" button and
            '       NO HELP.
            RaiseEvent CloseSplashScreen
            MsgBox mstrCannotOpenUIMsg, vbOKOnly, _
                mstrACCPACUIName
            
            ' Clear the company ID and destroy the
            ' session and session manager objects.
            mstrCompanyID = ""
            Set mSession = Nothing
            Set mSessMgr = Nothing
            
            ' Enable/show the "UIClosed" part ONLY,
            ' and notify others that the UI's
            ' application part is closed.
            EnableApp False
            RaiseOnUIAppClosed
        Else
            ' We opened a session successfully, so
            ' we can now set the company ID.
            mstrCompanyID = mSession.CompanyID
            
            ' Do the FIRST application-part opening
            ' sequence callout ("modifiable by
            ' UI programmers" part) in "OpenUIApp".
            ' Calls placed in "AppOpenSeqStart"
            ' happen BEFORE the we localize the UI
            ' again.  Errors are handled INSIDE the
            ' sub (the "standard" way).
            AppOpenSeqStart
            
            ' Save the localization objects in
            ' variables just in case the next
            ' localization fails, so we can go back
            ' to these objects.
            Dim IResTmplPrev As IResources
            Dim IResAppPrev As IResources
            Dim IResUIPrev As IResources
            Dim strLangPrev As String
            
            Set IResTmplPrev = mIResTmpl
            Set IResAppPrev = mIResApp
            Set IResUIPrev = mIResUI
            strLangPrev = mstrLang
            
' An error from the LocalizeUI call within this "On
' Error Resume Next" trap may be "fatal" for the UI,
' so a "can't go on" screen will be displayed.
On Error Resume Next
            ' Localize the UI again (as the language
            ' may have changed).  This sets
            ' mIResTmpl, mIResApp, mIResUI, and
            ' mstrLang again!!!
            LocalizeUI
            If Err.Number <> 0 Then
                ' Try to use the previous localized
                ' resources.
                Set mIResTmpl = IResTmplPrev
                Set mIResApp = IResAppPrev
                Set mIResUI = IResUIPrev
                mstrLang = strLangPrev
                
                ' We no longer need the previous
                ' resource objects.
                Set IResTmplPrev = Nothing
                Set IResAppPrev = Nothing
                Set IResUIPrev = Nothing
                
                If (mIResTmpl Is Nothing) _
                  Or (mIResApp Is Nothing) _
                  Or (mIResUI Is Nothing) _
                  Then
                    ' Since we can't even go back to
                    ' the previous resource objects,
                    ' make sure ALL resource objects
                    ' are destroyed and the current
                    ' language member is cleared.
                    Set mIResTmpl = Nothing
                    Set mIResApp = Nothing
                    Set mIResUI = Nothing
                    mstrLang = ""
                    
                    ' Clear the company ID, close
                    ' the session, and destroy the
                    ' session manager.
                    mstrCompanyID = ""
                    
                    If (Not (mSession Is Nothing)) Then
                        mSession.Close
                        Set mSession = Nothing
                    End If
                    
                    Set mSessMgr = Nothing
                    
                    ' Indicate that the UI's
                    ' application part isn't open.
                    bUIAppIsOpen = False
                    
                    ' Inform the user that
                    ' localization failed (NO HELP
                    ' for this) and show the UI in
                    ' its "can't go on" state.  This
                    ' sub raises OnUIAppClosed!!!
                    DisplayLocalizeFailure
                    
                    ' GET OUT of this sub.
                    Err.Clear
                    Exit Sub
                Else
                    ' We can use the previous
                    ' resource objects, so roll back
                    ' to the previous help file and
                    ' localized resources.
                    SetHelpFile
                    SetLocalizedResources
                    
                    ' INFORM the user of the
                    ' rollback (and clear errors).
                    RaiseEvent CloseSplashScreen
                    MsgBox mstrLocUsePrevResMsg & _
                        " " & mstrMissingDLL & _
                        ".dll", ACCPACWarnMBStyle, _
                        mstrACCPACWarnMBCap, _
                        App.HelpFile, _
                        HCIDLocUsePrevRes
                    Err.Clear
                End If  ' (mIResTmpl Is Nothing) Or (mIResApp Is Nothing) Or (mIResUI Is Nothing)
            End If  ' Err.Number <> 0
            
            ' Make sure that the previous
            ' localization objects are destroyed.
            Set IResTmplPrev = Nothing
            Set IResAppPrev = Nothing
            Set IResUIPrev = Nothing
            
            ' Clear any errors from previous steps.
            Err.Clear
            
            ' IF WE GOT TO HERE, WE GOT LOCALIZED
            ' RESOURCES (OR REUSED THE PREVIOUS
            ' LANGUAGE'S RESOURCES).
            
            ' Redo the UI's layout based on the
            ' language settings.  This may set
            ' msMinHeight and msMinWidth!!!
            DoLangLayout
            
            ' Resize the UI based on previously
            ' saved dimensions.
            If ACCPACUIResizable = True Then
                CustomResizeUI
            End If
            
            ' Set the UI's font (if needed for that
            ' language).  For the UI, this font
            ' change filters automatically to the
            ' appropriate constituent controls.
            ' NOTE: According to KB article Q206907,
            '       the font should be changed AFTER
            '       resizing.
            ApplyNewFont mIResTmpl, Me, False
            
            ' Do the callout for the MAIN PART of
            ' the opening sequence, in which UI
            ' programmers can INSERT calls.
            Dim bRollback As Boolean
            
            bRollback = AppOpenSeqRollback
            If bRollback = True Then
                ' We did a rollback, so GET OUT of
                ' this sub.
                Err.Clear
                Exit Sub
            End If
            
            ' IF WE GOT TO HERE, WE'VE DONE THE MAIN
            ' PART OF THE OPENING SEQUENCE.
            
' If any errors occur after this point, we can still
' keep on going, so switch back to the sub's (main)
' error trap.  This will automatically clear Err.
On Error GoTo OpenUIAppHandler
            ' Enable/show the UI's application part
            ' ONLY.
            EnableApp True
            
            ' Do the callout for the END of the
            ' opening sequence.  Errors are handled
            ' INSIDE the sub (the "standard" way).
            AppOpenSeqEnd
            
            ' Notify others that the UI's
            ' application part is now open.
            bAcceptUserClose = True
            RaiseEvent OnUIAppOpened
        End If  ' bUIAppIsOpen = False (AFTER OpenSession attempt)
    Else
        ' This is a programming error, so print a
        ' debug message and force a breakpoint to
        ' help diagnosis.
        Debug.Print "OpenUIApp should NOT be called" _
            & " when BOTH ""bRunMode = True"" AND" & _
            vbCrLf & "  ""bUIAppIsOpen = True"" " & _
            "(i.e. the application part is already" _
            & vbCrLf & "  open)."
        Debug.Assert False  ' press F5 or F8 to continue
    End If  ' bRunMode = False / ElseIf bUIAppIsOpen = False (BEFORE OpenSession attempt)
    
    ' JUST IN CASE we're somehow still inside the
    ' "On Error Resume Next" trap, clear the error.
    Err.Clear
Exit Sub

OpenUIAppHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message (unless there's
    ' no "common" resource object, in which case we
    ' print a VB ERROR ONLY debug message instead).
    If mIResTmpl Is Nothing Then
        StdACCPACErrorHandler Me, Nothing, Nothing, _
            False, True
    Else
        StdACCPACErrorHandler Me, mSession, _
            mIResTmpl, True, True
    End If
    Resume Next  ' clears error
End Sub

' This sub should ONLY be called when in run mode
' (and it should be called by subs like OpenUIApp,
' which take bUIAppIsOpen and then tell the user if
' the session can't be opened).
Private Sub OpenSession()
On Error GoTo OpenSessionHandler
    Debug.Print "OpenSession"
    
    ' If we're NOT in run mode, it's a programmer
    ' error, so print a debug message and force a
    ' breakpoint to help diagnosis.  Then, GET OUT
    ' (and indicate that we failed to open a session
    ' by indicating that the UI's application part
    ' is NOT open).
    If bRunMode = False Then
        Debug.Print "OpenSession should NOT be " & _
            "called when ""bRunMode = False""" & _
            vbCrLf & "  (i.e. when in design mode)."
        Debug.Assert False  ' press F5 or F8 to continue
        
        bUIAppIsOpen = False
        Exit Sub
    End If
    
    ' IF WE GOT TO HERE, WE'RE IN RUN MODE.
    
    ' Only create and initialize the session manager
    ' if it doesn't already exist.
    ' NOTE: If mSessMgr is Nothing after the
    '       "CreateObject" call, "Init" will raise
    '       an error and jump to this sub's handler.
    If mSessMgr Is Nothing Then
        Set mSessMgr = _
            CreateObject("Accpac.SessionMgr")
        
        With mSessMgr
            ' Set the session manager's properties.
            .AppID = ACCPACAppID
            .AppVersion = ACCPACAppVersion
            .ProgramName = ACCPACProgramName
            .ServerName = mstrServerName
        End With  ' mSessMgr
    End If
    
    ' Only create the session if it doesn't already
    ' exist (this sets mSession!!!).
    If mSession Is Nothing Then
        mSessMgr.CreateSession mstrObjectHandle, _
            mlSessionID, mSession
    End If
    
    ' Indicate whether or not we NOW have an open
    ' session (i.e. application part).
    If mSession Is Nothing Then
        bUIAppIsOpen = False  ' user couldn't sign on
    Else
        bUIAppIsOpen = mSession.IsOpened
    End If
Exit Sub

OpenSessionHandler:
    ' Print a debug message instead of displaying
    ' the error, as it isn't useful to the user.
    ' ("bUIAppIsOpen = False" will cause OpenUIApp
    ' to display "Could not open the UI" anyway.)
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        False, True  ' clears error
    
    ' Clear the company ID, destroy the session and
    ' session manager (we don't need them after a
    ' failed attempt to open the session).
    mstrCompanyID = ""
    Set mSession = Nothing
    Set mSessMgr = Nothing
    
    ' Indicate that the session (i.e. application
    ' part) ISN'T open.
    bUIAppIsOpen = False
End Sub

' This sub retrieves and applies the language-
' specific layout (if it exists) of this UI.  It may
' set msMinHeight and msMinWidth!!!
Private Sub DoLangLayout()
On Error Resume Next
    Debug.Print "DoLangLayout"
    
    Dim lUISizeID As Long
    Dim lCtlLayoutID As Long
    Dim bFoundIDs As Boolean
    Dim bUISizeChanged As Boolean
    Dim bCtlLayoutChanged As Boolean
    
    ' Get the resource IDs for the UI's language-
    ' specific size changes and the constituent
    ' controls' language-specific layout changes.
    bFoundIDs = GetLangLayoutIDs(UserControl.Name, _
        mIResUI, lUISizeID, lCtlLayoutID)
    If bFoundIDs = False Then
        ' There are no IDs for language-specific
        ' layout changes, so GET OUT of the sub (and
        ' clear errors).
        Err.Clear
        Exit Sub
    End If
    
    ' IF WE GOT TO HERE, WE'VE SET THE RESOURCE IDS
    ' FOR THE LAYOUT CHANGES.
    
    ' Layout changes are applied in this order:
    '
    ' 1. Get the new minimum ScaleHeight/ScaleWidth.
    ' 2. Apply constituent control layout changes.
    ' 3. Re-initialize the item resize info (IRI),
    '    but based on the NEW minimum ScaleHeight
    '    and ScaleWidth (msMinHeight/msMinWidth).
    '    Since the UI can't be resized yet, its
    '    actual ScaleHeight/ScaleWidth haven't
    '    changed.  If resize was done earlier, the
    '    IRI would have OLD right/bottom offsets, so
    '    constituent controls would be resized
    '    incorrectly AND those OLD offsets would
    '    remain in the "re-initialized" IRI.
    ' 4. Resize the UI itself.  This triggers a
    '    constituent control "resize", but they will
    '    preserve their layouts.
    ' 5. Tell the container to resize itself (and/or
    '    the area it gives the UI).
    
    ' NOTE: GetNewFormSize sets msMinHeight and
    '       msMinWidth (or leaves them as is, if
    '       nothing has changed)!!!
    bUISizeChanged = GetNewFormSize(mIResUI, _
        lUISizeID, msMinHeight, msMinWidth)
    bCtlLayoutChanged = ApplyNewCtlLayout(mIResUI, _
        Controls, lCtlLayoutID)
    
    If (bCtlLayoutChanged = True) _
      And (bResizeInfoAvailable = True) _
      Then
        InitItemSizeInfo 0, msMinWidth, 0, _
            msMinHeight, itemResizeMainForm
    End If
    
    If bUISizeChanged = True Then
        Size msMinWidth, msMinHeight  ' changes ScaleHeight/ScaleWidth
        RaiseEvent OnUIForceSize(msMinWidth, _
            msMinHeight, Screen.TwipsPerPixelX, _
            Screen.TwipsPerPixelY)
    End If
    
    Err.Clear
End Sub

' This sub resizes the UI based on previously saved
' dimensions stored in ACCPAC properties (if any).
' NOTE: This is called AFTER any language-specific
'       UI size changes have been applied.
Private Sub CustomResizeUI()
On Error Resume Next
    Debug.Print "CustomResizeUI"
    
    Dim sNewHeight As Single
    Dim sNewWidth As Single
    Dim bNeedResize As Boolean
    
    bNeedResize = False  ' until told otherwise
    
    With mSession.GetAccpacProperty
        Dim vPropHeight As Variant
        Dim vPropWidth As Variant
        Dim ecRes As ACCPACErrorCode
        
        ' Identify the UI.
        .menuID = ACCPACProgramName
        .objectID = ACCPACProgramName
        
        ' See if the height needs resizing.
        .keyword = UIHEIGHT_KEY
        ecRes = .PropGet(vPropHeight, PROP_AS_STRING)
        If ecRes = EC_Success Then
            sNewHeight = CSng(vPropHeight)
            
            If sNewHeight > ScaleHeight Then
                bNeedResize = True  ' we're sure
            Else
                ' The saved property isn't valid,
                ' so clear it and use ScaleHeight.
                .PropClear
                sNewHeight = ScaleHeight
            End If  ' sNewHeight > ScaleHeight
        Else
            sNewHeight = ScaleHeight
        End If  ' ecRes = EC_Success (Height)
        
        ' See if the width needs resizing.
        .keyword = UIWIDTH_KEY
        ecRes = .PropGet(vPropWidth, PROP_AS_STRING)
        If ecRes = EC_Success Then
            sNewWidth = CSng(vPropWidth)
            
            If sNewWidth > ScaleWidth Then
                bNeedResize = True  ' we're sure
            Else
                ' The saved property isn't valid,
                ' so clear it and use ScaleWidth.
                .PropClear
                sNewWidth = ScaleWidth
            End If  ' sNewWidth > ScaleWidth
        Else
            sNewWidth = ScaleWidth
        End If  ' ecRes = EC_Success (Width)
    End With  ' mSession.GetAccpacProperty
    
    If bNeedResize = True Then
        ' Since the previously saved size differs
        ' from the default size, resize the UI and
        ' notify the container of the new size.
        Size sNewWidth, sNewHeight
        RaiseEvent OnUIForceSize(sNewWidth, _
            sNewHeight, Screen.TwipsPerPixelX, _
            Screen.TwipsPerPixelY)
    End If
    
    Err.Clear
End Sub

' NOTE: Errors are RE-RAISED (to get to
'       "AppOpenSeqRollback").
Private Sub InitDBLinks()
On Error GoTo InitDBLinksHandler
    Debug.Print "InitDBLinks"
    
    If mUIDBLinks Is Nothing Then
        Debug.Print "Inside InitDBLinks: mUIDBLinks is Nothing"
    Else
        ' Open each DB link and add it to the
        ' collection (errors in "Add" need to be re-
        ' raised in order to get to the handler).
        Set mDBLinkCmpRW = mSession.OpenDBLink(DBLINK_COMPANY, DBLINK_FLG_READWRITE)
        If mDBLinkCmpRW Is Nothing Then
            Debug.Print "Inside InitDBLinks: mDBLinkCmpRW is Nothing"
        Else
            mUIDBLinks.Add mDBLinkCmpRW, "mDBLinkCmpRW"
            With Err
                If .Number <> 0 Then
                    .Raise .Number, .Source, _
                        .Description, .HelpFile, _
                        .HelpContext
                End If
            End With  ' Err
        End If
        
        ' <SET EACH ADDITIONAL DB LINK IN A SIMILAR
        '  MANNER AS ABOVE: OPEN IT USING
        '  mSession.OpenDBLink, THEN ADD IT TO THE
        '  mUIDBLinks COLLECTION USING
        '  mUIDBLinks.Add <dbLinkVar>, _
        '      "<dbLinkVar>".  THEN, RE-RAISE THE
        '  ERROR TO GET TO THE HANDLER IF Err <> 0
        '  (i.e. THERE WAS AN ERROR IN "ADD").>
    End If  ' mUIDBLinks Is Nothing
    
    ' We STILL need to clear any errors (as some
    ' don't cause a jump to this sub's handler).
    Err.Clear
Exit Sub

InitDBLinksHandler:
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    
    ' Save the error information in variables (in
    ' case this information somehow changes).
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
    ' Destroy each DB link.
    Set mDBLinkCmpRW = Nothing
    ' <SET EACH ADDITIONAL DB LINK TO NOTHING.>
    
    ' RE-RAISE the error to get to
    ' AppOpenSeqRollback's ("On Error Resume Next")
    ' handler, which will finish clearing objects
    ' and reversing the state back to showing the
    ' "UIClosed" part.
    Err.Raise lErrNum, strErrSource, strErrDesc, _
        strErrHelpFile, lErrHelpContext
End Sub

' Errors prior to the callout are ignored, but ANY
' ERRORS NOT HANDLED INTERNALLY BY THE CALLOUT are
' RE-RAISED to get to the "Rollback" section of
' AppOpenSeqRollback.  If you want the callout to
' return success/failure, "InitAppControls" will
' have to be changed into a function that returns
' the callout's return value.  Then, you'll need to
' change the "Rollback" section of
' "AppOpenSeqRollback" to report the problem and
' close the UI upon a failure in "InitAppControls".
' NOTE: Errors from the CALLOUT are RE-RAISED (to
'       get to AppOpenSeqRollback).
Private Sub InitAppControls()
On Error Resume Next
    Debug.Print "InitAppControls"
    
    ' Reset the macro and UI enable/show "request
    ' flags" by forcing them to request that all of
    ' the application-part controls be shown.
    ' NOTE: Customization enable/show "request
    '       flags" are reset in the call (later in
    '       this sub) to ApplySavedCustomizations.
    If (Not (mAppControls Is Nothing)) Then
        Dim aCtl As ACCPACControl
        For Each aCtl In mAppControls
            If (Not (aCtl Is Nothing)) Then
                With aCtl
                    .MacroEnabledFlag = True
                    .UIEnabledFlag = True
                    .MacroVisibleFlag = True
                    .UIVisibleFlag = True
                End With  ' aCtl
            End If
        Next aCtl
    End If
    
    ' Ignore any errors trying to enable/show
    ' ACCPACControls.
    Err.Clear
    
    ' Apply any customizations that are saved in the
    ' customization views. (This sub CLEARS its own
    ' errors.)
    ApplySavedCustomizations
    
    ' Do the "modifiable by UI programmers" part of
    ' "InitAppControls".
    ' NOTE: Errors raised by "InitAppCtlsCallout"
    '       AREN'T CLEARED, so we END UP IN
    '       AppOpenSeqRollback's "Rollback" section.
    InitAppCtlsCallout
End Sub


'---------------------------------------------------
' ACCPAC UI Application-Part Closing Functions
'---------------------------------------------------

' This function indicates to the caller whether or
' not the application part should be closed (i.e.
' the caller should then call CloseUIApp) at this
' point.  If there are unsaved changes, the user is
' prompted (an error during the "save" attempt for
' the "Yes" choice results in "Cancel").  If the
' choice is "Cancel", this function returns False.
' Otherwise, it will return True, indicating that
' the caller can close the UI's application part
' (and almost always shut itself down).
' NOTE: It's OK to call CloseUIApp when the UI's
'       application part is closed.  In that case,
'       CloseUIApp just sets bUIAppIsOpen to False.
'       If QueryCloseUIApp had returned False when
'       the application part was already closed, the
'       caller wouldn't have been able to tell the
'       difference between that case, where exiting
'       should go ahead, and the case where the user
'       doesn't want to close it (i.e. the "Cancel"
'       case), where exiting should be aborted.
Public Function QueryCloseUIApp() As Boolean
Attribute QueryCloseUIApp.VB_Description = "Indicates whether or not the caller should proceed with closing this ACCPAC UI Control's application part (by calling CloseUIApp) and then destroying this ACCPAC UI Control as part of the exit sequence."
On Error Resume Next
    Debug.Print "QueryCloseUIApp"
    
    If (bAcceptUserClose = True) And (UserControl.MousePointer <> vbHourglass) Then
        ' Let CheckSaveRecord do the real work.
        QueryCloseUIApp = CheckSaveRecord
    Else
        ' Prevent the user-triggered close, as we're
        ' not fully opened yet.
        QueryCloseUIApp = False
    End If
    
    Err.Clear
End Function

' NO ERROR HANDLING!  Errors go back to the caller.
Private Sub RaiseOnUIAppClosed()
    ' BEFORE raising the event, change the flag so
    ' that QueryCloseUIApp won't force the close to
    ' be cancelled (unless CheckSaveRecord fails).
    bAcceptUserClose = True
    RaiseEvent OnUIAppClosed
End Sub

Public Sub CloseUIApp()
Attribute CloseUIApp.VB_Description = "Closes the application part of this ACCPAC UI Control.  The 'OnUIAppClosed' event is raised.  If the container doesn't destroy this ACCPAC UI Control, users will see the ""UIClosed"" part."
On Error GoTo CloseUIAppHandler
    Debug.Print "CloseUIApp"
    
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        ' Allow for macros' "pre-closing" cleanup.
        ' NOTE: It's too late to cancel closing.
        RaiseEvent BeforeUIAppClosed
        
        ' Do the "modifiable by UI programmers" part
        ' of the application-part closing sequence
        ' in "CloseUIApp".
        AppCloseSequence
        
        ' Save the UI's size (if it is not minimized
        ' or maximized).
        If ACCPACUIResizable = True Then
            SaveUISize
        End If
        
        ' Clear the company ID, close the session,
        ' and destroy the session manager.
        mstrCompanyID = ""
        
        If (Not (mSession Is Nothing)) Then
            mSession.Close
            Set mSession = Nothing
        End If
        
        Set mSessMgr = Nothing
        
        ' The UI's application part is no longer
        ' open (i.e. no open session anymore).
        bUIAppIsOpen = False
        
        ' We DON'T need to redo localizations as we
        ' keep using the previous opened session's
        ' language when the application part isn't
        ' opened.  However, the HELP FILE still has
        ' to be reset as the session's closed.
        SetHelpFile
        
        ' Enable/show the "UIClosed" part ONLY, then
        ' notify others that the UI's application
        ' part is now closed.
        EnableApp False
        RaiseOnUIAppClosed
    Else
        ' Make sure to indicate that the UI's
        ' application part is closed.
        bUIAppIsOpen = False
    End If
Exit Sub

CloseUIAppHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True
    Resume Next  ' clears error
End Sub

Private Sub ClearAppControls()
On Error GoTo ClearAppControlsHandler
    Debug.Print "ClearAppControls"
    
    ' Clear the captions of looked-up controls and
    ' the corresponding lookup cookies.
    ClearLookupInfo
    
    ' Clear the values (and AccpacCOMAPI references)
    ' of field edit controls and view list controls.
    ' NOTE: Use the Controls collection (as "Clear"
    '       isn't exposed by ACCPACControls).
    Dim ctl As Control
    For Each ctl In Controls
        If (Not (ctl Is Nothing)) Then
            If (TypeOf ctl Is AccpacFieldEditControl) _
              Or (TypeOf ctl Is AccpacViewList) _
              Then
                ctl.Clear
            End If  ' TypeOf ctl Is (Field Edit or View List)
        End If  ' Not (ctl Is Nothing)
    Next ctl
    
    ' Do the "modifiable by UI programmers" part of
    ' "ClearAppControls".
    ClearAppCtlsCallout
Exit Sub

ClearAppControlsHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True
    Resume Next  ' clears error
End Sub

Private Sub CloseDBLinks()
On Error GoTo CloseDBLinksHandler
    Debug.Print "CloseDBLinks"
    
    ' Remove DB links from mUIDBLinks (collection).
    If mUIDBLinks Is Nothing Then
        Debug.Print "Inside CloseDBLinks: mUIDBLinks is Nothing"
    Else
        With mUIDBLinks
            Debug.Print "mUIDBLinks.Count = " & CStr(.Count)
            Dim i As Long
            For i = 1 To .Count
                .Remove 1
            Next i
            Debug.Print "Final mUIDBLinks.Count = " & CStr(.Count)
        End With  ' mUIDBLinks
    End If
    
    ' Close DB links (and set members to Nothing).
    If (Not (mDBLinkCmpRW Is Nothing)) Then
        mDBLinkCmpRW.Close
        Set mDBLinkCmpRW = Nothing
    End If
    
    ' <CLOSE OTHER DB LINKS AND SET THEM TO NOTHING.>
    
    ' We STILL need to clear any errors (as some
    ' don't cause a jump to this sub's handler).
    Err.Clear
Exit Sub

CloseDBLinksHandler:
    ' Print a debug message for the programmer to
    ' help with diagnosis, then keep on going (so
    ' we'll attempt to set ALL DB links to Nothing).
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        False, True
    Resume Next  ' clears error
End Sub

' This sub saves the UI's height and width into
' ACCPAC Properties if the UI isn't minimized or
' maximized.  If the height and/or width is the same
' as the default height and/or width, the ACCPAC
' Property is cleared (for space efficiency and for
' a faster startup next time the UI is run).
Private Sub SaveUISize()
On Error Resume Next
    Dim lParentHwnd As Long
    Dim bMaximized As Boolean
    Dim bMinimized As Boolean
    
    ' Find the top-level parent window (doesn't
    ' include owner, i.e. caller, windows).
    lParentHwnd = GetAncestor(UserControl.hwnd, _
                              GA_ROOT)
    If Err.Number = 0 Then
        bMaximized = CBool(IsZoomed(lParentHwnd))
        bMinimized = CBool(IsIconic(lParentHwnd))
    Else
        ' The parent doesn't have an Hwnd, so assume
        ' it is not maximized or minimized.
        bMaximized = False
        bMinimized = False
        Err.Clear  ' this error is now handled
    End If
    
    If (bMaximized = True) Or (bMinimized = True) Then
        ' GET OUT!  DON'T save the size, but DON'T
        ' clear the previous saved size either!
        Err.Clear
        Exit Sub
    End If
    
    ' IF WE GOT TO HERE, WE NEED TO DEAL WITH THE
    ' ACCPAC PROPERTIES.
    
    With mSession.GetAccpacProperty
        .menuID = ACCPACProgramName
        .objectID = ACCPACProgramName
        
        ' See if we need to save/clear the height.
        .keyword = UIHEIGHT_KEY
        If ScaleHeight <= msMinHeight Then
            .PropClear
        Else
            Dim strUIHeight As String
            
            strUIHeight = CStr(ScaleHeight)
            .PropPut CVar(strUIHeight), Len(strUIHeight)
        End If
        
        ' See if we need to clear/save the width.
        .keyword = UIWIDTH_KEY
        If ScaleWidth <= msMinWidth Then
            .PropClear
        Else
            Dim strUIWidth As String
            
            strUIWidth = CStr(ScaleWidth)
            .PropPut CVar(strUIWidth), Len(strUIWidth)
        End If
    End With  ' mSession.GetAccpacProperty
    
    Err.Clear
End Sub


'---------------------------------------------------
' Constituent Control Display/Behavior Functions
'---------------------------------------------------
'
' These functions control whether or not the
' constituent controls are displayed and how they
' behave.  Basically, they help to display only the
' application part's controls (and hide the
' "UIClosed"-part controls) when the UI's
' application part is open, and do the opposite when
' it's closed.
'

Private Sub EnableApp(ByVal bEnableApp As Boolean)
On Error GoTo EnableAppHandler
    ' Tracing code
    If bRunMode = True Then
        If bEnableApp = True Then
            Debug.Print "EnableApp: TRUE"
        Else
            Debug.Print "EnableApp: FALSE"
        End If  ' bEnableApp = True
    Else
        Debug.Print "EnableApp: DESIGN MODE"
    End If  ' bRunMode = True
    ' End tracing code
    
    If bRunMode = True Then
        ' In run mode, we enable/show the "UIClosed"
        ' part OR the application part, NEVER both.
        If bEnableApp = True Then  ' (App is enabled)
            ' Enable/show the application part.
            ShowAppControls True
            
            ' Hide/disable the "UIClosed" part.
            ShowUIClosedControls False
            
            ' NOTE: It's the CLIENT'S (CONTAINER'S)
            '       responsibility to set the focus
            '       to this UI at the appropriate
            '       moment (i.e. in response to the
            '       "OnUIAppOpened" event), so focus
            '       will be set to the LAST control
            '       in this UI's tab order.
        Else  ' (App is disabled)
            ' Enable/show the "UIClosed" part.
            ShowUIClosedControls True
            
            ' Hide/disable the application part.
            ShowAppControls False
        End If  ' bEnableApp = True
    Else
        ' In design mode, ONLY the application part
        ' is enabled and shown.
        ShowAppControls True
        ShowUIClosedControls False
    End If  ' bRunMode = True
    
    ' Force the container to refresh the top-level
    ' menus.
    RefreshTopMenus
Exit Sub

EnableAppHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message (unless there's
    ' no "common" resource object, in which case we
    ' print a debug message instead).
    ' NOTE: There's NO session errors here.
    If mIResTmpl Is Nothing Then
        StdACCPACErrorHandler Me, Nothing, Nothing, _
            False, True
    Else
        StdACCPACErrorHandler Me, Nothing, _
            mIResTmpl, True, True
    End If
    Resume Next  ' clears error
End Sub

Private Sub ShowUIClosedControls(ByVal bShow As Boolean)
On Error GoTo ShowUIClosedControlsHandler
    ' Go through the "UIClosed"-part controls.
    ' NOTE: "Invisible at runtime" controls are
    '       NEITHER part of mAppControls NOR part of
    '       mUIClosedControls.
    If (Not (mUIClosedControls Is Nothing)) Then
        Dim aCtl As ACCPACControl
        For Each aCtl In mUIClosedControls
            If (Not (aCtl Is Nothing)) Then
                ShowTheControl aCtl, bShow
            End If
        Next aCtl
    End If
    
    ' We STILL need to clear any errors (as some
    ' don't cause a jump to this sub's handler).
    Err.Clear
Exit Sub

ShowUIClosedControlsHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message (unless there's
    ' no "common" resource object, in which case we
    ' print a debug message instead).
    ' NOTE: ShowTheControl handles its own errors,
    '       so any errors here are from the looping.
    '       Thus, there's NO session errors here.
    If mIResTmpl Is Nothing Then
        StdACCPACErrorHandler Me, Nothing, Nothing, _
            False, True
    Else
        StdACCPACErrorHandler Me, Nothing, _
            mIResTmpl, True, True
    End If
    Resume Next  ' clears error
End Sub

Private Sub ShowAppControls(ByVal bShow As Boolean)
On Error GoTo ShowAppControlsHandler
    ' Go through the application-part controls.
    ' NOTE: "Invisible at runtime" controls are
    '       NEITHER part of mAppControls NOR part of
    '       mUIClosedControls.
    If (Not (mAppControls Is Nothing)) Then
        Dim aCtl As ACCPACControl
        For Each aCtl In mAppControls
            If (Not (aCtl Is Nothing)) Then
                ShowTheControl aCtl, bShow
            End If
        Next aCtl
    End If
    
    ' We STILL need to clear any errors (as some
    ' don't cause a jump to this sub's handler).
    Err.Clear
Exit Sub

ShowAppControlsHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message (unless there's
    ' no "common" resource object, in which case we
    ' print a debug message instead).
    ' NOTE: ShowTheControl handles its own errors,
    '       so any errors here are from the looping.
    '       Thus, there's NO session errors here.
    If mIResTmpl Is Nothing Then
        StdACCPACErrorHandler Me, Nothing, Nothing, _
            False, True
    Else
        StdACCPACErrorHandler Me, Nothing, _
            mIResTmpl, True, True
    End If
    Resume Next  ' clears error
End Sub

' NOTE: "Invisible at runtime" controls are NEITHER
'       part of mAppControls NOR part of
'       mUIClosedControls (so ShowTheControl, which
'       is only called from ShowUIClosedControls and
'       ShowAppControls, WON'T get called for these
'       controls).
' NOTE: It's OK if the "Enabled" and/or "Visible"
'       properties don't exist and/or can't be set
'       on a given control, so we don't need to re-
'       raise the error after the TmplEnabledFlag
'       and TmplVisibleFlag calls.
Private Sub ShowTheControl(aCtl As ACCPACControl, _
                           ByVal bShow As Boolean)
On Error GoTo ShowTheControlHandler
    If (Not (aCtl Is Nothing)) Then
        With aCtl
            Dim aCtlName As String
            
            ' Save the control's name in a variable
            ' (for efficiency).  Check for errors.
            ' (We NEED TO DO THIS CHECK because an
            ' error in (aCtl).Name won't force a
            ' jump to this sub's error handler.  The
            ' error's number, source, and
            ' description are set, BUT we need to
            ' re-raise it to get to our handler.)
            aCtlName = .Name
            With Err
                If .Number <> 0 Then
                    .Raise .Number, .Source, _
                        .Description, .HelpFile, _
                        .HelpContext
                End If
            End With  ' Err
            
            ' IN THE NEXT PART: It's OK if one of
            ' the "Visible" and/or "Enabled" can't
            ' be set (using ".TmplAAA"), so by not
            ' doing "If Err.Number <> 0", we are in
            ' fact choosing not to propagate or
            ' handle that type of error in this sub.
            ' NOTE: Menu items' handlers STILL need
            '       to check if the application part
            '       is open because of an MS BUG
            '       that lets you use accelerator
            '       keys even if the item is
            '       disabled/hidden.
            
            If (aCtlName = "mnuFile_Customize") _
              Or (aCtlName = "mnuFile_s2") _
              Or (aCtlName = "popmnuFile_Customize") _
              Or (aCtlName = "popmnuFile_s2") _
              Then
                ' Only enable/show the "Customize"
                ' (File) menu item and its separator
                ' if we want it to be shown AND we
                ' know that the user is an
                ' administrator.
                If (bShow = True) And (bUserIsAdmin = True) Then
                    .TmplEnabledFlag = True
                    .TmplVisibleFlag = True
                Else
                    .TmplVisibleFlag = False
                    .TmplEnabledFlag = False
                End If  ' (bShow = True) And (bUserIsAdmin = True)
            Else
                ' It's a "normal" control.
                If bShow = True Then
                    .TmplEnabledFlag = True
                    .TmplVisibleFlag = True
                Else
                    .TmplVisibleFlag = False
                    .TmplEnabledFlag = False
                End If  ' bShow = True
            End If  ' It's the "customize" menu item
        End With  ' aCtl
    End If
    
    ' We STILL need to clear any errors (as some
    ' don't cause a jump to this sub's handler).
    Err.Clear
Exit Sub

ShowTheControlHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message (unless there's
    ' no "common" resource object, in which case we
    ' print a debug message instead).
    ' NOTE: There's NO session errors here.
    If mIResTmpl Is Nothing Then
        StdACCPACErrorHandler Me, Nothing, Nothing, _
            False, True
    Else
        StdACCPACErrorHandler Me, Nothing, _
            mIResTmpl, True, True
    End If
    Resume Next  ' clears error
End Sub


'---------------------------------------------------
' Special Menu Behavior Functions
'---------------------------------------------------

' This sub can be called by containers that DON'T
' negotiate menus with the UserControl (i.e. web
' pages).  When called, it will show the WHOLE POPUP
' MENU at the TOP LEFT CORNER of the UI's AREA.
Public Sub ShowMenus()
Attribute ShowMenus.VB_Description = "Displays this ACCPAC UI Control's popup menu (which contains the other menus) at the TOP LEFT corner of this ACCPAC UI Control's area.\r\n(This is mainly for containers that don't negotiate menu displays with controls they host.)"
On Error Resume Next
    Debug.Print "ShowMenus"
    
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        UserControl.PopupMenu popmnuTopLevel, , 0, 0
    End If
    
    Err.Clear
End Sub

' This sub should be called when a TOP-LEVEL menu
' changes its STATE (i.e. enabled or visible state)
' and/or its CAPTION.  This is the fix for the
' UserControl menu refresh problem.  It's taken from
' MSDN article Q196902.
Private Sub RefreshTopMenus()
On Error Resume Next
    Debug.Print "RefreshTopMenus"
    
    With UserControl
        .Enabled = False
        .Enabled = True
        .SetFocus
    End With  ' UserControl
    
    Err.Clear

    DoEvents
    
    Err.Clear
End Sub


'---------------------------------------------------
' Resource and Help-Related Functions
'---------------------------------------------------

' This sub creates the localized resource objects
' and sets the localized resources.  If needed, its
' error handler calls InstallLangDLLs.
' NOTE: The caller is responsible for checking
'       whether or not we're in run mode.  ALSO, we
'       assume that this sub is called sometime
'       BEFORE "EnableApp" is called (so that top-
'       level menus are refreshed properly).
' NOTE: Localized resource object creation errors
'       are RE-RAISED (to get to UC_Show/OpenUIApp).
'       (Because of this, we can't just return the
'       missing DLL's name if an error occurs.)
Private Sub LocalizeUI()
On Error Resume Next  ' Ignore errors getting the language
    Debug.Print "LocalizeUI"
    
    Dim strLang As String
    strLang = ""  ' default new "Language" choice
    
    ' (TRY TO) Find out what language to use.
    ' (Language code strings are MADE UPPERCASE.)
    If bUIAppIsOpen = True Then
        ' We're signed on, so the session tells us
        ' what language to use.  (At this point, if
        ' there is no user language, we SHOULD later
        ' try to go back to the previous language.)
        strLang = UCase(mSession.UserLanguage)
    Else
        ' We're not signed on, so try to find the
        ' last language used by looking in the
        ' registry.
        Dim lResult As Long
        Dim lKeyHandle As Long
        
        ' Try to open the key (if it doesn't work,
        ' that's OK).
        lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _
                        ACCPAC_KEYS_PATH, ByVal 0&, _
                        KEY_QUERY_VALUE, lKeyHandle)
        
        If lResult = ERROR_SUCCESS Then
            Dim strVal As String
            Dim lValLen As Long
            Dim lValType As Long
            
            ' Now that we opened the key, try to
            ' read its value (if it doesn't work,
            ' that's OK, so ignore the return code).
            strVal = String(STRING_BUFFER_SIZE, " ")
            lValLen = Len(strVal)
            
            RegQueryValueEx lKeyHandle, _
                ACCPAC_LANG_KEY, ByVal 0&, lValType, _
                ByVal strVal, lValLen
            
            ' We need to trim off the extra "null"
            ' character as well as the padded
            ' characters in the buffer.
            If (lValType = REG_SZ) And (lValLen >= 1) Then
                strLang = UCase(Left(strVal, _
                                     lValLen - 1))
            End If
            ' ELSE: Later, we'll just use English.
            
            ' We also need to close the key.
            RegCloseKey lKeyHandle
        End If
        ' ELSE: Later, we'll just use English.
        
        ' Since we're not signed on yet, it's OK to
        ' just use English (WITHOUT WARNING THE
        ' USER) if we can't get the registry value.
        If (strLang = "") Or (strLang = vbNullString) Then
            strLang = "ENG"
        End If  ' (strLang = "") Or (strLang = vbNullString)
    End If  ' bUIAppIsOpen = True
    
    ' If this is the same language that we're
    ' already using (and the resource objects
    ' exist), we just need to set the help file
    ' again and GET OUT of this sub.
    If (strLang = mstrLang) _
      And (strLang <> "") _
      And (strLang <> vbNullString) _
      And (Not (mIResTmpl Is Nothing)) _
      And (Not (mIResApp Is Nothing)) _
      And (Not (mIResUI Is Nothing)) _
      Then
        SetHelpFile  ' help file only set when signed on
        Err.Clear
        Exit Sub
    End If
    
    ' IF WE GOT TO HERE, WE'RE USING A DIFFERENT
    ' LANGUAGE, SO WE NEED TO CREATE THE RESOURCE
    ' OBJECTS AND CHANGE THE RESOURCES.
    
' Errors in this trap (for object creation) are
' propagated.  (Opening the trap clears Err.)
On Error GoTo LocalizeUIHandler
    ' (TRY TO) Install the language DLLs (if needed)
    ' and retrieve the localized resource objects.
    InstallLangDLLs strLang
    
' We can ignore errors from this point on.
On Error Resume Next
    ' Update the current language member and clear
    ' the "missing DLL" member (no DLLs missing).
    mstrLang = strLang
    mstrMissingDLL = ""
    
    ' Set the help file and resources to the
    ' localized versions.
    SetHelpFile
    SetLocalizedResources
    
    Err.Clear
Exit Sub

LocalizeUIHandler:
    If strLang = "ENG" Then
        ' We can't fall back any further, so
        ' RE-RAISE the error.
        With Err
            .Raise .Number, .Source, .Description, _
                .HelpFile, .HelpContext
        End With  ' Err
    Else
        ' Try to fall back ("silently") to English
        ' resources.
        strLang = "ENG"
        Resume
    End If
End Sub

' This sub tries to install the appropriate language
' DLLs if we couldn't open them on the first attempt
' in LocalizeUI.
Private Sub InstallLangDLLs(ByVal strLang As String)
On Error Resume Next  ' ignore errors trying to determine "use vbp" mode
    Debug.Print "InstallLangDLLs(" & strLang & ")"
    
    Dim strResType As String
    Dim sessMgrLang As AccpacSessionMgr
    
    ' Set "Missing DLL" error information to the UI-
    ' specific DLL.
    ' NOTE: If the session manager can't be created
    '       (highly unlikely), the user will see a
    '       (misleading) message saying that the UI-
    '       specific DLL is missing (even if it's
    '       there). It is better than a (no name)
    '       "'.DLL' is missing" message.
    mstrMissingDLL = App.EXEName & strLang
    strResType = RESOURCES_UI
    
On Error GoTo InstallLangDLLsHandler
    If mSessMgr Is Nothing Then
        ' It's before we sign on, so create a temp
        ' session manager and set its properties.
        Set sessMgrLang = New AccpacSessionMgr
        With sessMgrLang
            .AppID = ACCPACAppID
            .AppVersion = ACCPACAppVersion
            .ProgramName = ACCPACProgramName
            .ServerName = mstrServerName
        End With  ' sessMgrLang
    Else
        ' Use the existing session manager (to get
        ' correct resource/version information).
        Set sessMgrLang = mSessMgr
    End If
    
    With sessMgrLang
        ' Install the DLLs BUT ignore errors for
        ' this ONE call (so we can later pinpoint
        ' the missing DLL).  (Switching back to the
        ' "InstallLangDLLsHandler" handler will
        ' clear errors.)
On Error Resume Next
        .InstallLanguageDependencies strLang
On Error GoTo InstallLangDLLsHandler
        
        ' Get the UI-specific resource object.
        Set mIResUI = .PgmResource2(App.Path, _
                                    mstrMissingDLL)
        If mIResUI Is Nothing Then
            ' In case the session manager hadn't
            ' raised an error, raise one here.
            Err.Raise 5
        End If
        
        ' Set "Missing DLL" error information to the
        ' ("app") module-wide DLL, and get its
        ' resource object.
        mstrMissingDLL = ACCPACAppID & _
            ACCPACAppVersion & strLang & "Client"
        strResType = RESOURCES_APP
        
        Set mIResApp = .AppResource2(App.Path, _
                                     mstrMissingDLL)
        If mIResApp Is Nothing Then
            ' In case the session manager hadn't
            ' raised an error, raise one here.
            Err.Raise 5
        End If
        
        ' Set "Missing DLL" error information to the
        ' "template" (common-to-all) DLL, and get
        ' its resource object.
        mstrMissingDLL = ACCPACTmplResApp & strLang
        strResType = RESOURCES_COMMON
        
        Set mIResTmpl = .CommonResource2
        If mIResTmpl Is Nothing Then
            ' In case the session manager hadn't
            ' raised an error, raise one here.
            Err.Raise 5
        End If
    End With  ' sessMgrLang
    
    Set sessMgrLang = Nothing  ' no longer needed
Exit Sub

InstallLangDLLsHandler:
    With Err
        If strLang = "ENG" Then
            ' Since we couldn't get English resource
            ' objects, we can't fall back anymore.
            ' Print a debug message and force a
            ' breakpoint to help with diagnosis.
            ' (Err's state is STILL PRESERVED.)
            Debug.Print "ERROR: Failed to get the " _
                & "localized resource object for" & _
                vbCrLf & "  " & strResType & _
                " resources: " & mstrMissingDLL & _
                ".dll" & vbCrLf & "  " & _
                "Err.Number = " & CStr(.Number) & _
                vbCrLf & "  Err.Source = " & _
                .Source & vbCrLf & "  " & _
                "Err.Description = " & .Description
            Debug.Assert False  ' press F5 or F8 to continue
        End If
        
        ' Destroy ALL resource objects and clear
        ' the current language member.  Also make
        ' sure the session manager is destroyed.
        ' (Err's state is STILL PRESERVED.)
        Set sessMgrLang = Nothing  ' just to be sure
        Set mIResTmpl = Nothing
        Set mIResApp = Nothing
        Set mIResUI = Nothing
        mstrLang = ""
        
        ' RE-RAISE the error.
        .Raise .Number, .Source, .Description, _
            .HelpFile, .HelpContext
    End With  ' Err
End Sub

' This sub sets localized resources for the UI.  It
' is called **AFTER** "CreateDynamicControls" (and
' after "SetDefaultResources").
Private Sub SetLocalizedResources()
On Error GoTo SetLocalizedResourcesHandler
    Debug.Print "SetLocalizedResources"
    
    If (mIResTmpl Is Nothing) _
      Or (mIResApp Is Nothing) _
      Or (mIResUI Is Nothing) _
      Then
        ' Make sure that ALL resource objects are
        ' destroyed and the current language is
        ' cleared (anyways).
        Set mIResTmpl = Nothing
        Set mIResApp = Nothing
        Set mIResUI = Nothing
        mstrLang = ""
        
        ' We don't have any resource objects, so
        ' inform the user (in ENGLISH with NO HELP).
        ' NOTE: UI PROGRAMMERS MUST USE
        '       mstrACCPACErrMBCap INSTEAD OF
        '       ACCPACErrMBCap.
        RaiseEvent CloseSplashScreen
        MsgBox AUINoLocResourcesMsg, _
            ACCPACErrMBStyle - vbMsgBoxHelpButton, _
            ACCPACErrMBCap
    Else
        ' Grab the UI-specific resources FIRST (as
        ' well as a few "common" resources).
        ' NOTE: Some of the strings created from the
        '       templated "common" resources depend
        '       on UI-specific resources.
        With mIResUI
            ' UI's associated icon (same resource
            ' used by "About" box)
            Set micoABPic = _
                .GetResPicture(IDI_ABPicIcon, _
                               vbResIcon)
            
            ' UI name string
            mstrACCPACUIName = _
                .GetResString(IDS_ACCPACUIName)
            
            ' "Enhanced" UI name string (part of it
            ' comes from the "common" resources, the
            ' rest is the UI name above)
            mstrAUINameIdent = _
                mIResTmpl.GetResString(IDS_AUILStrNameIdent) _
                & mstrACCPACUIName & _
                mIResTmpl.GetResString(IDS_AUIRStrNameIdent)
        End With  ' mIResUI
        
        ' THEN, grab more "common" resources.
        ' NOTE: Some of the strings created from the
        '       templated "common" resources depend
        '       on UI-specific resources.
        With mIResTmpl
            ' Message box caption members
            mstrACCPACErrMBCap = _
                .GetResString(IDS_ACCPACErrMBCap)
            mstrACCPACWarnMBCap = _
                .GetResString(IDS_ACCPACWarnMBCap)
            
            ' "UIClosed"-part message string members
            mstrReopenTipsTxt = _
                .GetResString(IDS_ReopenTipsTxt)
            mstrUIInitFailTxt = _
                .GetResString(IDS_UIInitFailTxt)
            mstrUIInitFailMBMsg = _
                mstrAUINameIdent & vbCrLf & vbCrLf & _
                mstrUIInitFailTxt
            
            ' Other message string members (some
            ' depend on other strings above)
            mstrAccessDeniedMsg = _
                mstrAUINameIdent & vbCrLf & vbCrLf & _
                .GetResString(IDS_AccessDeniedTxt)
            mstrActDSFailMsg = _
                mstrAUINameIdent & vbCrLf & vbCrLf & _
                .GetResString(IDS_ActDSFailTxt)
            mstrCheckRightsFailMsg = _
                mstrAUINameIdent & vbCrLf & vbCrLf & _
                .GetResString(IDS_CheckRightsFailTxt)
            mstrInitDBFailMsg = _
                mstrAUINameIdent & vbCrLf & vbCrLf & _
                .GetResString(IDS_InitDBFailTxt)
            mstrInitIRIFailMsg = _
                mstrAUINameIdent & vbCrLf & vbCrLf & _
                .GetResString(IDS_InitIRIFailTxt)
            mstrLocUsePrevResMsg = _
                mstrAUINameIdent & vbCrLf & vbCrLf & _
                .GetResString(IDS_LocUsePrevResTxt)
            mstrCannotOpenUIMsg = _
                .GetResString(IDS_CannotOpenUIMsg)
            mstrNoHelpFileMsg = _
                .GetResString(IDS_NoHelpFileMsg)
            mstrNoUsingHelpMsg = _
                .GetResString(IDS_NoUsingHelpMsg)
            mstrDelRecordMsg = _
                .GetResString(IDS_DelRecWithTypeMsg)
            mstrSaveRecordMsg = _
                .GetResString(IDS_SaveRecWithTypeMsg)
            
            ' Standard "File" (regular) menu item
            ' captions
            mnuFile.Caption = _
                .GetResString(IDS_AUIMnuFileCap)
            mnuFile_Customize.Caption = _
                .GetResString(IDS_AUIMnuFileCustomizeCap)
            mnuFile_Close.Caption = _
                .GetResString(IDS_AUIMnuFileCloseCap)
            
            ' Standard "Help" (regular) menu item
            ' captions
            mnuHelp.Caption = _
                .GetResString(IDS_AUIMnuHelpCap)
            mnuHelp_Contents.Caption = _
                .GetResString(IDS_AUIMnuHelpContentsCap)
            mnuHelp_UsingHelp.Caption = _
                .GetResString(IDS_AUIMnuHelpUsingHelpCap)
            mnuHelp_About.Caption = _
                .GetResString(IDS_AUIMnuHelpAboutCap)
            
            ' Popup menu top-level "item" caption
            ' (hidden)
            popmnuTopLevel.Caption = _
                .GetResString(IDS_AUIPopmnuTopLevelCap)
            
            ' Standard "File" popup menu item
            ' captions
            popmnuFile.Caption = _
                .GetResString(IDS_AUIPopmnuFileCap)
            popmnuFile_Customize.Caption = _
                .GetResString(IDS_AUIPopmnuFileCustomizeCap)
            popmnuFile_Close.Caption = _
                .GetResString(IDS_AUIPopmnuFileCloseCap)
            
            ' Standard "Help" popup menu item
            ' captions
            popmnuHelp.Caption = _
                .GetResString(IDS_AUIPopmnuHelpCap)
            popmnuHelp_Contents.Caption = _
                .GetResString(IDS_AUIPopmnuHelpContentsCap)
            popmnuHelp_UsingHelp.Caption = _
                .GetResString(IDS_AUIPopmnuHelpUsingHelpCap)
            popmnuHelp_About.Caption = _
                .GetResString(IDS_AUIPopmnuHelpAboutCap)
            
            ' Standard constituent control captions
            ' (some depend on other strings above)
            ACCPACUICLOSED_frame.Caption = _
                mstrACCPACUIName
            ACCPACUICLOSED_lblMsg.Caption = _
                .GetResString(IDS_UIClosedTxt) & _
                vbCrLf & vbCrLf & mstrReopenTipsTxt
            APP_Close_Button.Caption = _
                .GetResString(IDS_AUIAppCloseButtonCap)
        End With  ' mIResTmpl
        
        ' Do the "modifiable by UI programmers" part
        ' of "SetLocalizedResources".  (Some of the
        ' resources may come from mIResApp.)
        LocalResCallout
    End If
Exit Sub

SetLocalizedResourcesHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message for the programmer to
    ' help diagnosis (and clearing the error).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next
End Sub

' This sub sets default resources for the UI.  It's
' called **AFTER** "CreateDynamicControls".
' NOTE: UI PROGRAMMERS SHOULD **NEVER** USE THE
'       DEFAULT CONSTANTS IN THEIR CODE.  USE THE
'       MEMBER STRING INSTEAD.  (For example, use
'       mstrACCPACErrMBCap, NOT ACCPACErrMBCap.)
Private Sub SetDefaultResources()
On Error GoTo SetDefaultResourcesHandler
    Debug.Print "SetDefaultResources"
    
    ' ========== UI-Specific/Module-Wide ==========
    ' ================= Resources =================
    
    ' Picture resources (ALL default to Nothing)
    SetDefaultPics
    
    ' UI name string (this HAS a default)
    mstrACCPACUIName = ACCPACUIName
    
    ' ========== "Common" Resources ==========
    
    ' Message box caption members (need defaults)
    mstrACCPACErrMBCap = ACCPACErrMBCap
    mstrACCPACWarnMBCap = ACCPACWarnMBCap
    
    ' "Enhanced" UI name string (needs default)
    mstrAUINameIdent = AUINameIdentStr
    
    ' "UIClosed"-part message string members (need
    ' defaults)
    mstrReopenTipsTxt = ReopenTipsTxt
    mstrUIInitFailTxt = UIInitFailTxt
    mstrUIInitFailMBMsg = UIInitFailMBMsg
    
    ' Other message string members
    mstrAccessDeniedMsg = ""
    mstrActDSFailMsg = ""
    mstrCheckRightsFailMsg = ""
    mstrInitDBFailMsg = ""
    mstrInitIRIFailMsg = ""
    mstrLocUsePrevResMsg = ""
    mstrCannotOpenUIMsg = ""
    mstrNoHelpFileMsg = ""
    mstrNoUsingHelpMsg = ""
    mstrDelRecordMsg = ""
    mstrSaveRecordMsg = ""
    
    ' Standard "File" (regular) menu item captions
    mnuFile.Caption = ""
    mnuFile_Customize.Caption = ""
    mnuFile_Close.Caption = ""
    
    ' Standard "Help" (regular) menu item captions
    mnuHelp.Caption = ""
    mnuHelp_Contents.Caption = ""
    mnuHelp_UsingHelp.Caption = ""
    mnuHelp_About.Caption = ""
    
    ' Popup menu top-level "item" caption (hidden)
    popmnuTopLevel.Caption = ""
    
    ' Standard "File" popup menu item captions
    popmnuFile.Caption = ""
    popmnuFile_Customize.Caption = ""
    popmnuFile_Close.Caption = ""
    
    ' Standard "Help" popup menu item captions
    popmnuHelp.Caption = ""
    popmnuHelp_Contents.Caption = ""
    popmnuHelp_UsingHelp.Caption = ""
    popmnuHelp_About.Caption = ""
    
    ' Standard constituent control captions
    ACCPACUICLOSED_frame.Caption = ACCPACUIName
    ACCPACUICLOSED_lblMsg.Caption = ""
    APP_Close_Button.Caption = ""
    
    ' Do the "modifiable by UI programmers" part of
    ' "SetDefaultResources".
    DefaultResCallout
Exit Sub

SetDefaultResourcesHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message for the programmer to
    ' help diagnosis (and clearing the error).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next
End Sub

' This sub sets the UI's help file.
' NOTE: If the help file isn't set correctly, VB
'       (and code in the "Help" menu item handlers)
'       will take care of the situation (by handling
'       it at runtime WITHOUT raising an error).
Private Sub SetHelpFile()
On Error Resume Next
    Debug.Print "SetHelpFile"
    
    If (mIResTmpl Is Nothing) _
      Or (mIResApp Is Nothing) _
      Or (mIResUI Is Nothing) _
      Then
        ' Make sure that ALL resource objects are
        ' destroyed and the current language member
        ' is cleared.
        Set mIResTmpl = Nothing
        Set mIResApp = Nothing
        Set mIResUI = Nothing
        mstrLang = ""
    End If
    
    ' Set the real help file if the UI's application
    ' part is opened.  (Set it to "" otherwise.)
    If bUIAppIsOpen = True Then
        ' NOTE: Use mstrLang (NOT the session's
        '       language), since we may have gone to
        '       using the PREVIOUS language.
        App.HelpFile = mSession.HelpPath & _
            ACCPACAppID & ACCPACAppVersion & _
            mstrLang & ".chm"
        
        If mstrLang <> "ENG" Then
            Dim iFileNum As Integer
            
            ' Test if the non-English help file
            ' exists (don't use FileSystemObject,
            ' as it depends on the scrrun.dll
            ' version on each build machine).
            iFileNum = FreeFile
            Err.Clear  ' ignore previous errors
            
            Open App.HelpFile For Input Access Read _
                As iFileNum
            If Err.Number = 0 Then
                Close iFileNum  ' the file exists
            Else
                ' Fall back to the English help file
                ' (which may or may not exist).
                App.HelpFile = mSession.HelpPath & _
                    ACCPACAppID & ACCPACAppVersion & _
                    "ENG.chm"
                Err.Clear
            End If  ' Err.Number = 0
        End If  ' mstrLang <> "ENG"
    Else
        App.HelpFile = ""
    End If  ' bUIAppIsOpen = True
    
    Err.Clear
End Sub

' This sub sets the HelpContextIDs for constituent
' controls.  It should be called sometime **AFTER**
' "CreateDynamicControls" is called!!!
' NOTE: HelpContextIDs STAY THE SAME for all
'       languages!!!  Also, none of the "UIClosed"-
'       part controls have help for them.
Private Sub SetHelpIDs()
On Error GoTo SetHelpIDsHandler
    Debug.Print "SetHelpIDs"
    
    ' Standard "File" (regular) menu items
    mnuFile.HelpContextID = HCIDAUIMnuFile
    mnuFile_Customize.HelpContextID = HCIDAUIMnuFileCustomize
    mnuFile_Close.HelpContextID = HCIDAUIMnuFileClose
    
    ' Standard "Help" (regular) menu items
    mnuHelp.HelpContextID = HCIDAUIMnuHelp
    mnuHelp_Contents.HelpContextID = HCIDAUIMnuHelpContents
    mnuHelp_UsingHelp.HelpContextID = HCIDAUIMnuHelpUsingHelp
    mnuHelp_About.HelpContextID = HCIDAUIMnuHelpAbout
    
    ' Popup menu top-level "item" (hidden)
    popmnuTopLevel.HelpContextID = HCIDAUIPopmnuTopLevel
    
    ' Standard "File" popup menu items
    popmnuFile.HelpContextID = HCIDAUIMnuFile
    popmnuFile_Customize.HelpContextID = HCIDAUIMnuFileCustomize
    popmnuFile_Close.HelpContextID = HCIDAUIMnuFileClose
    
    ' Standard "Help" popup menu items
    popmnuHelp.HelpContextID = HCIDAUIMnuHelp
    popmnuHelp_Contents.HelpContextID = HCIDAUIMnuHelpContents
    popmnuHelp_UsingHelp.HelpContextID = HCIDAUIMnuHelpUsingHelp
    popmnuHelp_About.HelpContextID = HCIDAUIMnuHelpAbout
    
    ' Standard constituent controls
    APP_Close_Button.HelpContextID = HCIDAUIAppCloseButton
    
    ' Do the "modifiable by UI programmers" part of
    ' "SetHelpIDs".
    HelpIDsCallout
Exit Sub

SetHelpIDsHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message for the programmer to
    ' help diagnosis (and clearing the error).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next
End Sub


'---------------------------------------------------
' Report Printing
'---------------------------------------------------
'
' This section ONLY exists for REPORT UI'S.
'

' This sub is called by REPORT UI'S to print
' (generate) the actual report.
Private Sub PrintReport()
On Error GoTo PrintReportHandler
    Debug.Print "PrintReport"
    
    Dim rpt As AccpacReport
    Dim PSCtl As AccpacProcessServerCtrl
    
    ' Change the mouse pointer to indicate a
    ' possible wait.
    UserControl.MousePointer = vbHourglass
    
    Set rpt = mSession.ReportSelect(RptName, _
                    RptMenuID, ACCPACProgramName)
    
    With rpt
        Dim bContinue As Boolean
        Dim bConfirm As Boolean
        
        ' We may need to involve the process server.
        If .RequiresProcessServerSettings = True Then
            Set PSCtl = New AccpacProcessServerCtrl
            With PSCtl
                .InitForReport mSession, rpt, RptName
                bContinue = .ConfirmReport(UserControl.hwnd)
            End With  ' PSCtl
            ' NOTE: DON'T set PSCtl to Nothing here,
            '       as we want to see its status box
            '       until the report is printed.
        Else
            bContinue = True
        End If
        
        If bContinue = True Then
            ' Set up the parameters for the report.
            SetRptParams rpt
            
            ' Ask the user to confirm before proceeding.
            bConfirm = .Confirm(True, UserControl.hwnd)
            If bConfirm = True Then
                Dim bWebRpt As Boolean
                
                ' Print the report (or indicate that
                ' it's to be previewed on the web).
                bWebRpt = .PrintReport
                
                ' Process Server may have a message
                ' for the user (on the error stack).
                StdACCPACErrorHandler Me, mSession, _
                       mIResTmpl, False, True  ' clears error
                
                If bWebRpt = True Then
                    Dim prRpt As AccpacPrintReport
                    
                    ' Preview it on the web.
                    Set prRpt = New AccpacPrintReport
                    prRpt.ReportViewer mSession, _
                                      .WebReportURL
                    Set prRpt = Nothing  ' no longer used
                End If  ' bWebRpt = True
                
                ' <IF NEEDED: DO ANY POST-PRINTING
                '  PROCESSING (i.e. CLEARING PRINTED
                '  RECORDS) HERE.>
            End If  ' bConfirm = True
        End If  ' bContinue = True
    End With  ' rpt
    Set rpt = Nothing  ' no longer used
    Set PSCtl = Nothing  ' STATUS BOX no longer needed
    
    ' Change the mouse pointer back to the normal
    ' one.
    UserControl.MousePointer = vbDefault
Exit Sub

PrintReportHandler:
    ' Make sure the mouse pointer is the normal one.
    UserControl.MousePointer = vbDefault
    
    ' Just show the session errors (or VB error if
    ' there aren't any) and quit this operation.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True  ' clears error
End Sub


'---------------------------------------------------
' Customizations
'---------------------------------------------------

' If the user is an administrator, this sub shows
' the "Customize" dialog box, then re-applies the
' administrator's customizations.
Private Sub CustomizeBox()
On Error Resume Next
    Debug.Print "CustomizeBox"
    
    ' DO the run mode, "is the UI open?", and "is
    ' the user an administrator?" checks ANYWAYS.
    If (bRunMode = True) _
      And (bUIAppIsOpen = True) _
      And (bUserIsAdmin = True) _
      Then
        Dim ctlActive As Control
        
        ' Save the active control (one with focus).
        ' NOTE: It WON'T be "File->Customize".
        Set ctlActive = UserControl.ActiveControl
        
        ' Load and set up the "Customize" box.
        Load ACCPACUICustomizeBox
        If (Not (ACCPACUICustomizeBox Is Nothing)) Then
            Dim bSetup As Boolean
            
            bSetup = ACCPACUICustomizeBox.SetupForm( _
                mCustomCtls, mSession, Me, _
                mIResTmpl, mstrCustLastProfileID)
            If bSetup = True Then
                ' Pop up the "Customize" box, then
                ' save the last profile ID after it
                ' closes (to be used next time).
                ACCPACUICustomizeBox.Show vbModal, Me
                mstrCustLastProfileID = _
                    ACCPACUICustomizeBox.WorkingProfileID
                
                ' Apply the admin's customizations
                ' again (as other customizations may
                ' have been temporarily applied).
                ApplySavedCustomizations
            End If  ' bSetup = True
        End If  ' Not (ACCPACUICustomizeBox Is Nothing)
        
        ' Free up the "Customize" box's resources
        ' (this works even if it's already Nothing).
        Unload ACCPACUICustomizeBox
        Set ACCPACUICustomizeBox = Nothing
        
        ' To prevent the tab stop from disappearing,
        ' set the focus back to the active control
        ' (unless it's now hidden, in which case we
        ' try to set focus on the "Close" button,
        ' which is a NON-CUSTOMIZABLE control).
        ' NOTE: ASSUME that the ACTIVE CONTROL
        '       ALWAYS EXISTS.
        With ctlActive
            If (.Enabled = True) And (.Visible = True) Then
                ' Set focus on the active control.
                .SetFocus
            Else
                ' Attempt the "Close" button.
                With APP_Close_Button
                    If (.Enabled = True) And (.Visible = True) Then
                        .SetFocus
                    End If
                End With  ' APP_Close_Button
            End If
        End With  ' ctlActive
    End If
    
    Err.Clear
End Sub

' This sub applies the customizations that are saved
' in the customization views.  (Saved customizations
' are applied to ALL users, whether or not they are
' administrators.  It's just that administrators get
' to use the "Customize" box to change these saved
' customizations.)
Private Sub ApplySavedCustomizations()
On Error Resume Next
    Debug.Print "ApplySavedCustomizations"
    
    If (Not (mCustomCtls Is Nothing)) And (Not (mSession Is Nothing)) Then
        ' BEFORE applying any customizations,
        ' reverse PREVIOUS customizations (or those
        ' applied temporarily while the "Customize"
        ' box was open) by showing all customizable
        ' controls.
        Dim cCtl As ACCPACCustCtl
        For Each cCtl In mCustomCtls
            If (Not (cCtl Is Nothing)) Then
                With cCtl
                    .EnabledFlag = True
                    .VisibleFlag = True
                End With  ' cCtl
            End If
        Next cCtl
        
        ' Ignore any errors that may have occurred
        ' while trying to enable/show controls.
        Err.Clear
        
        ' Get the user's customizations.
        Dim strArrHidnCtls() As String
        strArrHidnCtls = _
            mDBLinkCmpRW.GetUserCustomizations(ACCPACUIKey)
        
        ' If there's an error in trying to get the
        ' user's customizations, display (and clear)
        ' it, then GET OUT of this sub.
        If Err.Number <> 0 Then
            StdACCPACErrorHandler Me, mSession, _
                mIResTmpl, True, True  ' clears error
            Exit Sub
        End If
        
        ' IF WE GOT TO HERE, WE GOT THE USER'S
        ' CUSTOMIZATIONS SUCCESSFULLY.
        
        ' Get the hidden controls array's bounds.
        Dim lHCtlsLBound As Long
        Dim lHCtlsUBound As Long
        
        lHCtlsLBound = LBound(strArrHidnCtls)
        lHCtlsUBound = UBound(strArrHidnCtls)
        
        ' If there's an error trying to get these
        ' bounds, we have no controls that need to
        ' be hidden, so clear the error and GET OUT.
        If Err.Number <> 0 Then
            Err.Clear
            Exit Sub
        End If
        
        ' IF WE GOT TO HERE, WE HAVE A LIST OF
        ' CONTROLS THAT NEED TO BE HIDDEN.
        
' Switching error traps automatically clears Err.
On Error GoTo ApplySavedCustomizationsHandler
        ' Hide/disable each of the controls named in
        ' the hidden controls array.
        Dim i As Long
        For i = lHCtlsLBound To lHCtlsUBound
            Dim cHidnCtl As ACCPACCustCtl
            Set cHidnCtl = mCustomCtls(strArrHidnCtls(i))
            If (Not (cHidnCtl Is Nothing)) Then
                With cHidnCtl
                    .VisibleFlag = False
                    .EnabledFlag = False
                End With  ' cHidnCtl
            End If
        Next i
    End If
    
    ' We STILL need to clear any errors because we
    ' may still be in the "On Error Resume Next"
    ' handler and because some errors don't cause a
    ' jump to this sub's handler.
    Err.Clear
Exit Sub

ApplySavedCustomizationsHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True
    Resume Next  ' clears error
End Sub


'---------------------------------------------------
' HIDDEN Public Functions/Subs For Raising Events
'---------------------------------------------------
'
' These HIDDEN public functions/subs are used so
' that other files (form/class/standard modules) in
' this project can pass requests to raise events
' back to the UI's UserControl.  The events that
' can be raised are AfterCtlClick, BeforeCtlClick,
' CloseSplashScreen, OnLaunchObject, OnLaunchURL,
' OnPopupClosed, and OnPopupOpened.
'

Public Sub FireAfterCtlClick(ByVal strFormName As String, _
                             ByVal strCtlName As String)
Attribute FireAfterCtlClick.VB_Description = "DON'T USE THIS METHOD.\r\n(Exception: Other files within the ACCPAC UI Control's project.)"
Attribute FireAfterCtlClick.VB_MemberFlags = "40"
On Error Resume Next
    Debug.Print "FireAfterCtlClick"
    
    RaiseEvent AfterCtlClick(strFormName, strCtlName)
    Err.Clear
End Sub

Public Sub FireBeforeCtlClick(ByVal strFormName As String, _
                              ByVal strCtlName As String, _
                              ByRef pStatus As AccpacCOMAPI.tagEventStatus)
Attribute FireBeforeCtlClick.VB_Description = "DON'T USE THIS METHOD.\r\n(Exception: Other files within the ACCPAC UI Control's project.)"
Attribute FireBeforeCtlClick.VB_MemberFlags = "40"
On Error Resume Next
    Debug.Print "FireBeforeCtlClick"
    
    RaiseEvent BeforeCtlClick(strFormName, _
                              strCtlName, pStatus)
    Err.Clear
End Sub

Public Sub FireCloseSplashScreen()
Attribute FireCloseSplashScreen.VB_Description = "DON'T USE THIS METHOD.\r\n(Exception: Other files within the ACCPAC UI Control's project.)"
Attribute FireCloseSplashScreen.VB_MemberFlags = "40"
On Error Resume Next
    Debug.Print "FireCloseSplashScreen"
    
    RaiseEvent CloseSplashScreen
    Err.Clear
End Sub

Public Sub FireOnLaunchObject(ByVal strTargetClass As String, _
                              ByVal strCodebase As String, _
                              ByVal strObjectHandle As String)
Attribute FireOnLaunchObject.VB_Description = "DON'T USE THIS METHOD.\r\n(Exception: Other files within the ACCPAC UI Control's project.)"
Attribute FireOnLaunchObject.VB_MemberFlags = "40"
On Error Resume Next
    Debug.Print "FireOnLaunchObject"
    
    RaiseEvent OnLaunchObject(strTargetClass, _
                              strCodebase, _
                              strObjectHandle)
    Err.Clear
End Sub

Public Sub FireOnLaunchURL(ByVal strURL As String)
Attribute FireOnLaunchURL.VB_Description = "DON'T USE THIS METHOD.\r\n(Exception: Other files within the ACCPAC UI Control's project.)"
Attribute FireOnLaunchURL.VB_MemberFlags = "40"
On Error Resume Next
    Debug.Print "FireOnLaunchURL"
    
    RaiseEvent OnLaunchURL(strURL)
    Err.Clear
End Sub

Public Sub FireOnPopupClosed(ByVal strPopupName As String)
Attribute FireOnPopupClosed.VB_Description = "DON'T USE THIS METHOD.\r\n(Exception: Other files within the ACCPAC UI Control's project.)"
Attribute FireOnPopupClosed.VB_MemberFlags = "40"
On Error Resume Next
    Debug.Print "FireOnPopupClosed"
    
    RaiseEvent OnPopupClosed(strPopupName)
    Err.Clear
End Sub

Public Sub FireOnPopupOpened(ByVal strPopupName As String, _
                             ByRef PopupDSs As ACCPACDSControls, _
                             ByRef PopupCtls As ACCPACControls, _
                             ByRef strPopupCaption As String, _
                             ByRef icoPopup As StdPicture)
Attribute FireOnPopupOpened.VB_Description = "DON'T USE THIS METHOD.\r\n(Exception: Other files within the ACCPAC UI Control's project.)"
Attribute FireOnPopupOpened.VB_MemberFlags = "40"
On Error Resume Next
    Debug.Print "FireOnPopupOpened"
    
    RaiseEvent OnPopupOpened(strPopupName, PopupDSs, _
               PopupCtls, strPopupCaption, icoPopup)
    Err.Clear
End Sub


'---------------------------------------------------
' Standard Properties for an ACCPAC UI Control
'---------------------------------------------------

' Saved
Public Property Get BackColor() As OLE_COLOR
Attribute BackColor.VB_Description = "Returns/sets the background color used to display text and graphics in this ACCPAC UI Control."
Attribute BackColor.VB_ProcData.VB_Invoke_Property = ";Appearance"
Attribute BackColor.VB_UserMemId = -501
On Error GoTo GetBackColorHandler
    Debug.Print "(Get) BackColor"
    
    BackColor = UserControl.BackColor
Exit Property

GetBackColorHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "BackColor", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
' NOTE: ANYTHING on an SSTab is GRAY (to match TAB
'       color).  (The SSTab's BackColor is JUST for
'       the little strip to the right of the tabs.)
'       The BackColor of anything on a Frame matches
'       the Frame's BackColor.
Public Property Let BackColor(ByVal color As OLE_COLOR)
On Error GoTo LetBackColorHandler
    Dim ctl As Control  ' also used in error handler
    
    Debug.Print "(Let) BackColor"
    
    UserControl.BackColor = color
    
    For Each ctl In Controls
        If (Not (ctl Is Nothing)) Then
            If (TypeOf ctl Is AccpacFieldEditControl) _
              Or (TypeOf ctl Is Label) _
              Or (TypeOf ctl Is Frame) _
              Or (TypeOf ctl Is AccpacFrame) _
              Or (TypeOf ctl Is PictureBox) _
              Or (TypeOf ctl Is SSTab) _
              Or (TypeOf ctl Is CheckBox) _
              Or (TypeOf ctl Is OptionButton) _
              Or (TypeOf ctl Is PeriodPicker) _
              Or (TypeOf ctl Is AccpacGoButton.GoButton) _
              Then
                With ctl
                    Dim objContainer As Object
                    Set objContainer = .Container
                    
                    If objContainer Is Nothing Then
                        .BackColor = color
                    ElseIf (TypeOf objContainer Is SSTab) Then
                        .BackColor = vbButtonFace  ' SSTab's TAB color
                    ElseIf ((TypeOf objContainer Is Frame) _
                      Or (TypeOf objContainer Is AccpacFrame) _
                      Or (TypeOf objContainer Is PictureBox)) _
                      Then
                        .BackColor = objContainer.BackColor
                    Else
                        .BackColor = color
                    End If
                End With  ' ctl
            End If  ' TypeOf ctl Is one whose BackColor should match UserControl's
        End If  ' Not (ctl Is Nothing)
    Next ctl
    
    PropertyChanged "BackColor"
Exit Property

LetBackColorHandler:
    Dim errExtraInfo As String
    
    ' Include variable information in debug message.
    errExtraInfo = "ctl = "
    If ctl Is Nothing Then
        errExtraInfo = errExtraInfo & "(None)"
    Else
        errExtraInfo = errExtraInfo & ctl.Name
    End If
    
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "BackColor = &H" & _
        Hex(color), ptPropertyLet, errExtraInfo
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Get BackStyle() As BackStyleChoice
Attribute BackStyle.VB_Description = "Indicates/sets whether the background of this ACCPAC UI Control is transparent (0) or opaque (1)."
Attribute BackStyle.VB_ProcData.VB_Invoke_Property = ";Appearance"
Attribute BackStyle.VB_UserMemId = -502
On Error GoTo GetBackStyleHandler
    Debug.Print "(Get) BackStyle"
    
    BackStyle = UserControl.BackStyle
Exit Property

GetBackStyleHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "BackStyle", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Let BackStyle(ByVal bckStyle As BackStyleChoice)
On Error GoTo LetBackStyleHandler
    Dim ctl As Control  ' also used in error handler
    
    Debug.Print "(Let) BackStyle"
    
    UserControl.BackStyle = bckStyle
    
    ' NOTE: SSTabs and Frames DON'T have BackStyles,
    '       so there's no need to check for the
    '       container's BackStyle.
    For Each ctl In Controls
        If (Not (ctl Is Nothing)) Then
            If (TypeOf ctl Is AccpacFieldEditControl) _
              Or (TypeOf ctl Is Label) _
              Then
                ctl.BackStyle = bckStyle
            End If  ' TypeOf ctl Is one whose BackStyle should match UserControl's
        End If  ' Not (ctl Is Nothing)
    Next ctl
    
    PropertyChanged "BackStyle"
Exit Property

LetBackStyleHandler:
    Dim errExtraInfo As String
    
    ' Include variable information in debug message.
    errExtraInfo = "ctl = "
    If ctl Is Nothing Then
        errExtraInfo = errExtraInfo & "(None)"
    Else
        errExtraInfo = errExtraInfo & ctl.Name
    End If
    
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "BackStyle = " & _
        CStr(bckStyle), ptPropertyLet, errExtraInfo
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Get BorderStyle() As BorderStyleChoice
Attribute BorderStyle.VB_Description = "Indicates/sets whether this ACCPAC UI Control has no border (0) or a fixed single border (1)."
Attribute BorderStyle.VB_ProcData.VB_Invoke_Property = ";Appearance"
Attribute BorderStyle.VB_UserMemId = -504
On Error GoTo GetBorderStyleHandler
    Debug.Print "(Get) BorderStyle"
    
    BorderStyle = UserControl.BorderStyle
Exit Property

GetBorderStyleHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "BorderStyle", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Let BorderStyle(ByVal bordStyle As BorderStyleChoice)
On Error GoTo LetBorderStyleHandler
    Debug.Print "(Let) BorderStyle"
    
    UserControl.BorderStyle = bordStyle
    PropertyChanged "BorderStyle"
Exit Property

LetBorderStyleHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "BorderStyle = " & _
        CStr(bordStyle), ptPropertyLet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get CompanyID() As String
Attribute CompanyID.VB_Description = "Returns the company ID of the current session associated with this ACCPAC UI Control.  (If there's no session, returns """".)"
On Error GoTo GetCompanyIDHandler
    Debug.Print "(Get) CompanyID"
    
    CompanyID = mstrCompanyID
Exit Property

GetCompanyIDHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "CompanyID", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

Public Property Get Enabled() As Boolean
Attribute Enabled.VB_Description = "Returns/sets a value that determines whether or not this ACCPAC UI Control can respond to user-generated events."
Attribute Enabled.VB_ProcData.VB_Invoke_Property = ";Behavior"
Attribute Enabled.VB_UserMemId = -514
On Error GoTo GetEnabledHandler
    Enabled = UserControl.Enabled
Exit Property

GetEnabledHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "Enabled", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

Public Property Let Enabled(ByVal bNewEnabled As Boolean)
On Error GoTo LetEnabledHandler
    UserControl.Enabled = bNewEnabled
    PropertyChanged "Enabled"
Exit Property

LetEnabledHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "Enabled = " & _
        CStr(bNewEnabled), ptPropertyLet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Get Font() As StdFont
Attribute Font.VB_Description = "Returns/sets the Font object associated with this ACCPAC UI Control."
Attribute Font.VB_ProcData.VB_Invoke_Property = "StandardFont;Font"
Attribute Font.VB_UserMemId = -512
On Error GoTo GetFontHandler
    Debug.Print "(Get) Font"
    
    Set Font = mFont
Exit Property

GetFontHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "Font", ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
' NOTE: mFont should NEVER be Nothing (NOR should it
'       EVER be set to Nothing) UNTIL UC_Hide, as
'       UserControl.Font should NEVER be Nothing.
Public Property Set Font(ByVal fnt As StdFont)
On Error GoTo SetFontHandler
    Dim ctl As Control  ' also used in error handler
    
    Debug.Print "(Set) Font"
    
    If (Not (mFont Is Nothing)) And (Not (fnt Is Nothing)) Then
        With mFont
            ' NOTE: Bold is implicitly set by the
            '       weight.
            .Charset = fnt.Charset
            .Italic = fnt.Italic
            .Name = fnt.Name
            .Size = fnt.Size
            .Strikethrough = fnt.Strikethrough
            .Underline = fnt.Underline
            .Weight = fnt.Weight
        End With  ' mFont
        
        For Each ctl In Controls
            If (Not (ctl Is Nothing)) Then
                If (Not (TypeOf ctl Is Menu)) _
                  And (Not (TypeOf ctl Is AccpacDataSource)) _
                  And (Not (TypeOf ctl Is CommonDialog)) _
                  And (Not (TypeOf ctl Is AccpacFieldGroup)) _
                  And (Not (TypeOf ctl Is Line)) _
                  And (Not (TypeOf ctl Is HScrollBar)) _
                  And (Not (TypeOf ctl Is Image)) _
                  And (Not (TypeOf ctl Is ImageList)) _
                  And (Not (TypeOf ctl Is OLE)) _
                  And (Not (TypeOf ctl Is ProgressBar)) _
                  And (Not (TypeOf ctl Is Shape)) _
                  And (Not (TypeOf ctl Is Slider)) _
                  And (Not (TypeOf ctl Is Timer)) _
                  And (Not (TypeOf ctl Is Toolbar)) _
                  And (Not (TypeOf ctl Is UpDown)) _
                  And (Not (TypeOf ctl Is VScrollBar)) _
                  Then
                    ' Change the font (and the
                    ' headfont of viewlists).
                    If (TypeOf ctl Is AccpacViewList) Then
                        Set ctl.HeadFont = mFont
                    End If
                    
                    Set ctl.Font = mFont
                End If  ' Not (TypeOf ctl Is one that doesn't have Font)
            End If  ' Not (ctl Is Nothing)
        Next ctl
        
        PropertyChanged "Font"
    End If
    ' ELSE: This property didn't change, as mFont
    '       and/or fnt is Nothing.
Exit Property

SetFontHandler:
    Dim errExtraInfo As String
    
    ' Include variable information in debug message.
    errExtraInfo = "ctl = "
    If ctl Is Nothing Then
        errExtraInfo = errExtraInfo & "(None)"
    Else
        errExtraInfo = errExtraInfo & ctl.Name
    End If
    
    ' Print a debug message, then keep on going.
    ' NOTE: DON'T set a breakpoint, as some
    '       controls that may be used on UIs in
    '       the future won't have "Font".
    UIPropACCPACErrorHandler "Font = (StdFont " & _
        "Object)", ptPropertySet, errExtraInfo
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Get ForeColor() As OLE_COLOR
Attribute ForeColor.VB_Description = "Returns/sets the foreground color used to display text and graphics in this ACCPAC UI Control."
Attribute ForeColor.VB_ProcData.VB_Invoke_Property = ";Appearance"
Attribute ForeColor.VB_UserMemId = -513
On Error GoTo GetForeColorHandler
    Debug.Print "(Get) ForeColor"
    
    ForeColor = UserControl.ForeColor
Exit Property

GetForeColorHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "ForeColor", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Let ForeColor(ByVal color As OLE_COLOR)
On Error GoTo LetForeColorHandler
    Dim ctl As Control  ' also used in error handler
    
    Debug.Print "(Let) ForeColor"
    
    UserControl.ForeColor = color
    
    ' SSTab ForeColor should ALWAYS be black (thus,
    ' controls on SSTabs should MATCH this).
    For Each ctl In Controls
        If (Not (ctl Is Nothing)) Then
            If (TypeOf ctl Is SSTab) Then
                ctl.ForeColor = vbButtonText  ' black (text)
            ElseIf (TypeOf ctl Is AccpacFieldEditControl) _
              Or (TypeOf ctl Is Label) _
              Or (TypeOf ctl Is Frame) _
              Or (TypeOf ctl Is AccpacFrame) _
              Or (TypeOf ctl Is PictureBox) _
              Or (TypeOf ctl Is CheckBox) _
              Or (TypeOf ctl Is OptionButton) _
              Or (TypeOf ctl Is PeriodPicker) _
              Then
                With ctl
                    Dim objContainer As Object
                    Set objContainer = .Container
                    
                    If objContainer Is Nothing Then
                        .ForeColor = color
                    ElseIf (TypeOf objContainer Is SSTab) Then
                        .ForeColor = vbButtonText  ' black (SSTab text)
                    ElseIf ((TypeOf objContainer Is Frame) _
                      Or (TypeOf objContainer Is AccpacFrame) _
                      Or (TypeOf objContainer Is PictureBox)) _
                      Then
                        .ForeColor = objContainer.ForeColor
                    Else
                        .ForeColor = color
                    End If
                End With  ' ctl
            End If  ' TypeOf ctl Is SSTab / ElseIf TypeOf ctl Is one whose ForeColor should match UserControl's
        End If  ' Not (ctl Is Nothing)
    Next ctl
    
    PropertyChanged "ForeColor"
Exit Property

LetForeColorHandler:
    Dim errExtraInfo As String
    
    ' Include variable information in debug message.
    errExtraInfo = "ctl = "
    If ctl Is Nothing Then
        errExtraInfo = errExtraInfo & "(None)"
    Else
        errExtraInfo = errExtraInfo & ctl.Name
    End If
    
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "ForeColor = &H" & _
        Hex(color), ptPropertyLet, errExtraInfo
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get hwnd() As Long
Attribute hwnd.VB_Description = "Returns a handle (from Microsoft Windows) to an ACCPAC UI Control's window."
Attribute hwnd.VB_UserMemId = -515
On Error GoTo GethWndHandler
    Debug.Print "(Get) hWnd"
    
    hwnd = UserControl.hwnd
Exit Property

GethWndHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "hWnd", ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Get MaskColor() As OLE_COLOR
Attribute MaskColor.VB_Description = "Returns/sets the color that specifies transparent areas in the MaskPicture associated with this ACCPAC UI Control."
Attribute MaskColor.VB_ProcData.VB_Invoke_Property = ";Appearance"
On Error GoTo GetMaskColorHandler
    Debug.Print "(Get) MaskColor"
    
    MaskColor = UserControl.MaskColor
Exit Property

GetMaskColorHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "MaskColor", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Let MaskColor(ByVal color As OLE_COLOR)
On Error GoTo LetMaskColorHandler
    Debug.Print "(Let) MaskColor"
    
    UserControl.MaskColor = color
    PropertyChanged "MaskColor"
Exit Property

LetMaskColorHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "MaskColor = &H" & _
        Hex(color), ptPropertyLet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Get MaskPicture() As StdPicture
Attribute MaskPicture.VB_Description = "Returns/sets the picture that specifies the clickable/drawable area of this ACCPAC UI Control when its BackStyle is 0 (transparent)."
Attribute MaskPicture.VB_ProcData.VB_Invoke_Property = "StandardPicture;Appearance"
On Error GoTo GetMaskPictureHandler
    Debug.Print "(Get) MaskPicture"
    
    Set MaskPicture = UserControl.MaskPicture
Exit Property

GetMaskPictureHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "MaskPicture", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Set MaskPicture(ByVal newPicture As StdPicture)
On Error GoTo SetMaskPictureHandler
    Debug.Print "(Set) MaskPicture"
    
    Set UserControl.MaskPicture = newPicture
    PropertyChanged "MaskPicture"
Exit Property

SetMaskPictureHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "MaskPicture = " & _
        "(StdPicture Object)", ptPropertySet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get MinimumHeight() As Single
Attribute MinimumHeight.VB_Description = "Returns the minimum height for this ACCPAC UI Control."
On Error GoTo GetMinimumHeightHandler
    Debug.Print "(Get) MinimumHeight"
    
    MinimumHeight = msMinHeight
Exit Property

GetMinimumHeightHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "MinimumHeight", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get MinimumWidth() As Single
Attribute MinimumWidth.VB_Description = "Returns the minimum width for this ACCPAC UI Control."
On Error GoTo GetMinimumWidthHandler
    Debug.Print "(Get) MinimumWidth"
    
    MinimumWidth = msMinWidth
Exit Property

GetMinimumWidthHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "MinimumWidth", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' HIDDEN (Property/Object Browsers)
Public Property Get ObjectHandle() As String
Attribute ObjectHandle.VB_Description = "NOTE: DON'T ACCESS THIS PROPERTY UNLESS YOU ABSOLUTELY NEED TO.\r\nReturns/sets this ACCPAC UI Control's object handle."
Attribute ObjectHandle.VB_MemberFlags = "40"
On Error GoTo GetObjectHandleHandler
    Debug.Print "(Get) ObjectHandle"
    
    ObjectHandle = mstrObjectHandle
Exit Property

GetObjectHandleHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "ObjectHandle", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' HIDDEN (Property/Object Browsers)
' (Since it's hidden from the property browser, we
' don't need "PropertyChanged" on "Let".)
Public Property Let ObjectHandle(ByVal strObjHandle As String)
On Error GoTo LetObjectHandleHandler
    Debug.Print "(Let) ObjectHandle"
    
    mstrObjectHandle = strObjHandle
Exit Property

LetObjectHandleHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "ObjectHandle = " & _
        strObjHandle, ptPropertyLet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

Public Property Get ObjectKey() As String
Attribute ObjectKey.VB_Description = "Returns/sets this ACCPAC UI Control's key.  (The key's use and meaning are UI-specific.)"
Attribute ObjectKey.VB_MemberFlags = "400"
On Error GoTo GetObjectKeyHandler
    Debug.Print "(Get) ObjectKey"
    
    ObjectKey = mstrObjectKey
Exit Property

GetObjectKeyHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "ObjectKey", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

Public Property Let ObjectKey(ByVal strObjKey As String)
On Error GoTo LetObjectKeyHandler
    Debug.Print "(Let) ObjectKey"
    
    mstrObjectKey = strObjKey
Exit Property

LetObjectKeyHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "ObjectKey = " & _
        strObjKey, ptPropertyLet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Get Picture() As StdPicture
Attribute Picture.VB_Description = "Returns/sets the graphic that is displayed in this ACCPAC UI Control."
Attribute Picture.VB_ProcData.VB_Invoke_Property = "StandardPicture;Appearance"
On Error GoTo GetPictureHandler
    Debug.Print "(Get) Picture"
    
    Set Picture = UserControl.Picture
Exit Property

GetPictureHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "Picture", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Saved
Public Property Set Picture(ByVal newPicture As StdPicture)
On Error GoTo SetPictureHandler
    Debug.Print "(Set) Picture"
    
    Set UserControl.Picture = newPicture
    PropertyChanged "Picture"
Exit Property

SetPictureHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "Picture = (StdPicture" _
        & " Object)", ptPropertySet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get Resizable() As Boolean
Attribute Resizable.VB_Description = "Indicates whether or not this ACCPAC UI Control can (or should) be resized by its container."
On Error GoTo GetResizableHandler
    Debug.Print "(Get) Resizable"
    
    Resizable = ACCPACUIResizable
Exit Property

GetResizableHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "Resizable", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get ReturnValue() As String
Attribute ReturnValue.VB_Description = "Returns this ACCPAC UI Control's ReturnValue, which is retrieved by the container (and passed to the caller UI) when this ACCPAC UI Control is closed.  (The ReturnValue's use and meaning are UI-specific.)"
On Error GoTo ReturnValueHandler
    Debug.Print "(Get) ReturnValue"
    
    ReturnValue = mstrReturnValue
Exit Property

ReturnValueHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "ReturnValue", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' NOTE: This property is for bidirectional systems,
'       so ignore any failures instead of forcing a
'       breakpoint.
Public Property Get RightToLeft() As Boolean
Attribute RightToLeft.VB_Description = "Returns/sets whether or not text is displayed from right to left (for bidirectional systems) on this ACCPAC UI Control."
Attribute RightToLeft.VB_ProcData.VB_Invoke_Property = ";Behavior"
On Error Resume Next
    Debug.Print "(Get) RightToLeft"
    
    RightToLeft = UserControl.RightToLeft
    Err.Clear
End Property

' NOTE: This property is for bidirectional systems,
'       so ignore any failures instead of forcing a
'       breakpoint.
Public Property Let RightToLeft(ByVal bNewRToL As Boolean)
On Error Resume Next
    Debug.Print "(Let) RightToLeft"
    
    Dim ctl As Control
    
    UserControl.RightToLeft = bNewRToL
    
    For Each ctl In Controls
        If (Not (ctl Is Nothing)) Then
            ctl.RightToLeft = bNewRToL  ' ignore errors when control doesn't implement RightToLeft
        End If  ' Not (ctl Is Nothing)
    Next ctl
    
    PropertyChanged "RightToLeft"
    Err.Clear
End Property

' HIDDEN (Property/Object Browsers)
Public Property Get ServerName() As String
Attribute ServerName.VB_Description = "NOTE: DON'T ACCESS THIS PROPERTY UNLESS YOU ABSOLUTELY NEED TO.\r\nReturns/sets the name of the server on which to create the ACCPAC session associated with this ACCPAC UI Control."
Attribute ServerName.VB_MemberFlags = "40"
On Error GoTo GetServerNameHandler
    Debug.Print "(Get) ServerName"
    
    ServerName = mstrServerName
Exit Property

GetServerNameHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "ServerName", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' HIDDEN (Property/Object Browsers)
' (Since it's hidden from the property browser, we
' don't need "PropertyChanged" on "Let".)
Public Property Let ServerName(ByVal strSvrName As String)
On Error GoTo LetServerNameHandler
    Debug.Print "(Let) ServerName"
    
    mstrServerName = strSvrName
Exit Property

LetServerNameHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "ServerName = " & _
        strSvrName, ptPropertyLet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' HIDDEN (Property/Object Browsers)
Public Property Get SessionID() As Long
Attribute SessionID.VB_Description = "NOTE: DON'T ACCESS THIS PROPERTY UNLESS YOU ABSOLUTELY NEED TO.\r\nReturns/sets the session ID used (or to be used) by this ACCPAC UI Control."
Attribute SessionID.VB_MemberFlags = "40"
On Error GoTo GetSessionIDHandler
    Debug.Print "(Get) SessionID"
    
    SessionID = mlSessionID
Exit Property

GetSessionIDHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "SessionID", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' HIDDEN (Property/Object Browsers)
' (Since it's hidden from the property browser, we
' don't need "PropertyChanged" on "Let".)
Public Property Let SessionID(ByVal lNewSessID As Long)
On Error GoTo LetSessionIDHandler
    Debug.Print "(Let) SessionID"
    
    mlSessionID = lNewSessID
Exit Property

LetSessionIDHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "SessionID = " & _
        CStr(lNewSessID), ptPropertyLet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get TwipsPerPixelX() As Single
Attribute TwipsPerPixelX.VB_Description = "Returns the number of twips per pixel for the X (horizontal) direction for this ACCPAC UI Control."
On Error GoTo GetTwipsPerPixelXHandler
    Debug.Print "(Get) TwipsPerPixelX"
    
    TwipsPerPixelX = Screen.TwipsPerPixelX
Exit Property

GetTwipsPerPixelXHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "TwipsPerPixelX", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get TwipsPerPixelY() As Single
Attribute TwipsPerPixelY.VB_Description = "Returns the number of twips per pixel for the Y (vertical) direction for this ACCPAC UI Control."
On Error GoTo GetTwipsPerPixelYHandler
    Debug.Print "(Get) TwipsPerPixelY"
    
    TwipsPerPixelY = Screen.TwipsPerPixelY
Exit Property

GetTwipsPerPixelYHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "TwipsPerPixelY", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get UIAppControls() As ACCPACControls
Attribute UIAppControls.VB_Description = "Returns the collection of constituent controls in the application part of this ACCPAC UI Control."
On Error GoTo GetUIAppControlsHandler
    Debug.Print "(Get) UIAppControls"
    
    Set UIAppControls = mAppControls
Exit Property

GetUIAppControlsHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "UIAppControls", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get UIAppIsOpen() As Boolean
Attribute UIAppIsOpen.VB_Description = "Indicates whether or not this ACCPAC UI Control's application part is currently open."
On Error GoTo GetUIAppIsOpenHandler
    Debug.Print "(Get) UIAppIsOpen"
    
    UIAppIsOpen = bUIAppIsOpen
Exit Property

GetUIAppIsOpenHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "UIAppIsOpen", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get UIDBLinks() As ACCPACDBLinks
Attribute UIDBLinks.VB_Description = "Returns the collection of this ACCPAC UI Control's currently open ACCPAC database links.  (This EXCLUDES any database links that are implicitly opened by an ACCPAC data source.)"
On Error GoTo GetUIDBLinksHandler
    Debug.Print "(Get) UIDBLinks"
    
    Set UIDBLinks = mUIDBLinks
Exit Property

GetUIDBLinksHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "UIDBLinks", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get UIDSControls() As ACCPACDSControls
Attribute UIDSControls.VB_Description = "Returns the collection of ACCPAC data source controls in this ACCPAC UI Control."
On Error GoTo GetUIDSControlsHandler
    Debug.Print "(Get) UIDSControls"
    
    Set UIDSControls = mUIDSControls
Exit Property

GetUIDSControlsHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "UIDSControls", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get UIIcon() As IPictureDisp
Attribute UIIcon.VB_Description = "Returns this ACCPAC UI Control's associated (""About"" box) icon."
On Error GoTo GetUIIconHandler
    Debug.Print "(Get) UIIcon"
    
    Set UIIcon = micoABPic
Exit Property

GetUIIconHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "UIIcon", ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get UIName() As String
Attribute UIName.VB_Description = "Returns this ACCPAC UI Control's display name.\r\n(i.e. ""Currency Rate Types"")"
On Error GoTo GetUINameHandler
    Debug.Print "(Get) UIName"
    
    UIName = mstrACCPACUIName
Exit Property

GetUINameHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "UIName", ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property

' Read-only
Public Property Get UISession() As AccpacSession
Attribute UISession.VB_Description = "Returns the current ACCPAC session associated with this ACCPAC UI Control."
On Error GoTo GetUISessionHandler
    Debug.Print "(Get) UISession"
    
    Set UISession = mSession
Exit Property

GetUISessionHandler:
    ' Print a debug message, then force a breakpoint
    ' to help diagnosis.  Then, keep on going.
    UIPropACCPACErrorHandler "UISession", _
        ptPropertyGet
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' also (re-)clears error
End Property


'---------------------------------------------------
' Commonly Modified Methods: Initialization/Opening
'---------------------------------------------------

' This sub handles the end of "UC_Initialize", where
' the UI programmer may have to add code.
' NO NEED FOR ERROR HANDLING!
Private Sub InitializeUCCallout()
    Debug.Print "InitializeUCCallout"
    
    ' <SET ANY OTHER PRIVATE COLLECTION MEMBERS TO
    '  NOTHING.>
    ' EXAMPLE: Set mMyCollection = Nothing
    
    
    ' <SET OTHER AccpacCOMAPI MEMBERS TO NOTHING.>
    ' EXAMPLE: Set mDBLinkCmpRO = Nothing
    
    
    ' <SET ANY OTHER SAVED PROPERTIES' DEFAULT VALUE
    '  MEMBERS HERE.>
    ' EXAMPLE: mDefaultMyProperty = 0
    
    
    ' <INITIALIZE OTHER MISCELLANEOUS PRIVATE
    '  MEMBERS TO DEFAULT VALUES.>
    ' EXAMPLE: mlMyStatus = 5
End Sub

' This sub is used to set the neighbor relationships
' between field edit controls.  It's called by
' "UI_Initialize" **AFTER** "CreateDynamicControls"
' is called.
Private Sub SetNeighbors()
On Error GoTo SetNeighborsHandler
    Debug.Print "SetNeighbors"
    
    ' <SET UP ANY NEIGHBOR RELATIONSHIPS BETWEEN
    '  FIELD EDIT CONTROLS.  THESE RELATIONSHIPS ARE
    '  USED WHEN THE VIEWFINDER RETURNS MULTIPLE
    '  FIELDS FOR A CHOSEN RECORD.  THE FIRST VALUE
    '  RETURNED WILL BE SET TO THE "MAIN" CONTROL
    '  THAT THE NEIGHBORS WERE ADDED TO, AND THE
    '  NEXT VALUES WILL BE SET TO THE NEIGHBORS,
    '  **IN THE ORDER THEY WERE ADDED AS NEIGHBORS**
    '  TO THE "MAIN" CONTROL.>
    ' EXAMPLE:
    '   ' When the ViewFinder returns several fields
    '   ' for a selected record, the first will be
    '   ' set to fecBKACCT_1 (the "main" control),
    '   ' the second will be set to fecBKACCT_2, and
    '   ' the third will be set to fecBKACCT_3.
    '   With fecBKACCT_1
    '       .AddNeighborFieldEditControl fecBKACCT_2
    '       .AddNeighborFieldEditControl fecBKACCT_3
    '   End With  ' fecBKACCT_1
Exit Sub

SetNeighborsHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message for the programmer
    ' and forcing a breakpoint to help diagnosis
    ' (and then clearing the error).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next
End Sub

Private Sub InitItemResizeInfo()
On Error GoTo InitItemResizeInfoHandler
    ' Initialize the error handling flag.
    Dim bErrOccurred As Boolean
    bErrOccurred = False  ' no error yet
    
    Debug.Print "InitItemResizeInfo"
    
    Dim lResizeInfoItems As Long
    
    ' If item resize information is available
    ' ALREADY, it's a programming error, so print a
    ' debug message and force a breakpoint to help
    ' diagnosis.  Then, GET OUT (as we don't need
    ' any further initialization).
    If bResizeInfoAvailable = True Then
        Debug.Print "InitItemResizeInfo should NOT " _
            & "be called when " & _
            """bResizeInfoAvailable = True""" & _
            vbCrLf & "  (i.e. when item resize " & _
            "information is already available)."
        Debug.Assert False  ' press F5 or F8 to continue
        Exit Sub
    End If
    
    ' IF WE GOT TO HERE, WE KNOW THAT ITEM RESIZE
    ' INFORMATION ISN'T AVAILABLE YET (SO IT NEEDS
    ' TO BE INITIALIZED).
    
    ' Size the array appropriately (LBound = 0!!!).
    lResizeInfoItems = 1  ' <CHANGE THIS TO NUMBER OF ITEMS IN ARRAY>
    ReDim itemResizeMainForm(0 To (lResizeInfoItems - 1)) As ITEM_RESIZE_INFO
    
    ' Initialize the array elements.
    With itemResizeMainForm(0)
        Set .controlID = APP_Close_Button
        .resizeFlags = MOVE_RIGHT + MOVE_BOTTOM _
                       + MOVE_LEFT + MOVE_TOP
    End With  ' itemResizeMainForm(0)
    ' <ADD ANY OTHER ITEMS, SUCH AS THE "SAVE"
    '  AND "DELETE" BUTTONS, TO THIS ARRAY IN A
    '  SIMILAR MANNER AS ABOVE.  REMEMBER TO CHANGE
    '  THE lResizeInfoItems MEMBER'S VALUE TO HOLD
    '  THE ACTUAL NUMBER OF ITEMS IN THIS ARRAY.
    '  THE LARGEST INDEX USED IN THE ARRAY WILL BE
    '  lResizeInfoItems - 1.>
    
    ' Complete the initialization.
    InitItemSizeInfo 0, ScaleWidth, 0, ScaleHeight, _
            itemResizeMainForm
    
    If bErrOccurred = True Then
        ' We got AT LEAST ONE error within this sub,
        ' so indicate that item resize information
        ' isn't available (at least not completely).
        bResizeInfoAvailable = False
        
        ' Show the user a meaningful WARNING message
        ' IF it's RUN MODE and the UI is resizable.
        If (bRunMode = True) And (ACCPACUIResizable = True) Then
            RaiseEvent CloseSplashScreen
            MsgBox mstrInitIRIFailMsg, _
                ACCPACWarnMBStyle, _
                mstrACCPACWarnMBCap, App.HelpFile, _
                HCIDAUIInitIRIFail
        End If  ' (bRunMode = True) And (ACCPACUIResizable = True)
    Else
        ' There were no errors within this sub, so
        ' item resize information was initialized
        ' properly.  Thus, we can indicate that item
        ' resize information is now available.
        bResizeInfoAvailable = True
    End If  ' bErrOccurred = True
Exit Sub

InitItemResizeInfoHandler:
    ' Indicate that an error has occurred.
    bErrOccurred = True
    
    ' Print a debug message for the programmer to
    ' help with diagnosis, then keep on going.
    ' (Even if there's multiple errors, ONE warning
    ' message will be shown to the user at the end
    ' of the sub.  HOWEVER, each error is printed
    ' out for the programmer's benefit.)
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next  ' clears error
End Sub

' This sub is the FIRST callout from "OpenUIApp".
' It's the place for UI programmers to add calls to
' the START of the application-part opening sequence
' (before the POST-signon "LocalizeUI" call), with
' STANDARD ERROR HANDLING (show error, resume next)
' AND NO ROLLING BACK OF THESE CALLS.
' NOTE: Controls are NOT visible yet and errors are
'       shown in the PRE-SIGNON LANGUAGE (resource
'       objects are GUARANTEED to exist).
Private Sub AppOpenSeqStart()
On Error GoTo AppOpenSeqStartHandler
    Debug.Print "AppOpenSeqStart"
    
    ' <IF YOUR UI HAS A NOTEBOOK, SET ITS INITIAL
    '  ACTIVE TAB (THE PAGE SHOWN FIRST).  REMEMBER
    '  TO CALL ITS "CLICK" HANDLER IN AppOpenSeqEnd.>
    ' EXAMPLE: BKACCT_SSTabNotebook.Tab = 0
    sstabOptions.Tab = 0
    
    
    ' <IF YOUR UI MAKES USE OF THE OBJECTKEY, CHECK
    '  TO SEE IF A MACRO HAS ALREADY SET IT.  IF IT
    '  HASN'T, THEN GET IT FROM THE SESSION (WHICH
    '  HAS PASSED IT FROM THE CALLER UI).>
    ' NOTE: Use mstrObjectKey rather than ObjectKey
    '       to access the object key.
    ' EXAMPLE:
    '   If (mstrObjectKey = "") Or (mstrObjectKey = vbNullString) Then
    '       mstrObjectKey = mSession.GetObjectKey
    '   End If
    
    
    ' <ADD YOUR OTHER CODE HERE.  SEE THE COMMENTS
    '   RIGHT ABOVE THIS SUB FOR MORE INFORMATION.>
Exit Sub

AppOpenSeqStartHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message in the PRE-SIGNON
    ' LANGUAGE (mIResTmpl EXISTS).
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True
    Resume Next  ' clears error
End Sub

' This function is the ROLLBACK (and second) callout
' from "OpenUIApp".  WE HAVE LOCALZED RESOURCE
' OBJECTS AT THIS POINT.  Template AND UI-PROGRAMMER
' INSERTED calls here form the MAIN PART of the
' application-part opening sequence.  UNHANDLED
' errors from these calls can be sent to the
' "Rollback" error "handler", where we ROLL BACK
' TO THE UI'S "UIClosed" PART.  (We can't make the
' "Rollback" error "handler" a real "On Error"
' handler since we ignore errors raised within the
' "handler".)  This function returns TRUE if we HAD
' TO ROLL BACK (and False otherwise), so the flag is
' a ROLLBACK (failure) flag, NOT a "success" flag.
' NOTE: Controls are NOT visible yet.
Private Function AppOpenSeqRollback() As Boolean
On Error Resume Next
    Debug.Print "AppOpenSeqRollback"
    
    Dim bInitDBLinks As Boolean
    Dim bActivateDS As Boolean
    Dim bCheckARights As Boolean
    Dim bInitAppCtrls As Boolean
    ' <ADD A BOOLEAN FLAG FOR EACH PROCEDURE CALL IN
    '  THE "ROLLBACK" SECTION.>
    
    ' Initialize the values of the rollback flags to
    ' False (not done yet).
    bInitDBLinks = False
    bActivateDS = False
    bCheckARights = False
    bInitAppCtrls = False
    ' <SET OTHER ROLLBACK FLAGS TO FALSE.>
    
    ' <STARTING HERE, YOU MAY INSERT MORE OPENING
    '  SEQUENCE CALLS AT THE APPROPRIATE PLACES.
    '  YOU CAN INCLUDE CALLS THAT:
    '  - JUMP TO THE ROLLBACK "HANDLER" UPON FAILURE
    '  - SHOW THE ERROR AND MOVE ON UPON FAILURE
    '  - WON'T FAIL (OR WHOSE ERRORS ARE IGNORED)
    '  YOU'LL NEED AN INITIALIZED ROLLBACK FLAG FOR
    '  **EACH** CALL SO THAT THE ROLLBACK "HANDLER"
    '  KNOWS WHAT TO UNDO.  NOTE THAT THE OPENING
    '  AND CLOSING SEQUENCES SHOULD BE APPROXIMATELY
    '  THE "REVERSE" OF EACH OTHER.>
    ' NOTE: A call may go to the rollback "handler"
    '       if it fails, but it doesn't mean that
    '       the call itself needs undoing.  Also,
    '       a call that won't fail may need to be
    '       undone if subsequent calls fail.
    ' EXAMPLE: (JUMP TO ROLLBACK ON ERROR)
    '   (see the "InitDBLinks" call)
    ' EXAMPLE: (JUMP TO ROLLBACK ON FAILURE)
    '   ' bProcRollback is the Rollback flag here
    '   bProcRollback = ProcRollback
    '   Err.Clear
    '   If bProcRollback = False Then
    '       Goto RollBack  ' GETS OUT of function
    '   End If
    ' EXAMPLE: (SHOW ERROR AND MOVE ON)
    '   ProcShowErr
    '   If Err.Number <> 0 Then
    '       StdACCPACErrorHandler Me, mSession, _
    '           mIResTmpl, True, True  ' clears error
    '   End If
    '   bProcShowErr = True
    ' EXAMPLE: (WON'T FAIL/IGNORE ERRORS)
    '   ProcIgnoreErrs
    '   bProcIgnoreErrs = True
    '   Err.Clear
    
    ' Initialize the DB links.
    InitDBLinks
    If Err.Number = 0 Then
        bInitDBLinks = True
    Else
        GoTo RollBack  ' GETS OUT of function
    End If
    
    ' IF WE GOT TO HERE, WE INITIALIZED DB LINKS.
    
    ' Activate the ACCPAC data sources.
    ActivateDataSources
    If Err.Number = 0 Then
        bActivateDS = True
    Else
        GoTo RollBack  ' GETS OUT of function
    End If
    
    ' IF WE GOT TO HERE, WE ACTIVATED DATA SOURCES.
    
    ' Check the user's access rights.
    Dim bAccessGranted As Boolean
    bAccessGranted = CheckAccessRights
    If (Err.Number = 0) And (bAccessGranted = True) Then
        bCheckARights = True
    Else
        GoTo RollBack  ' GETS OUT of function
    End If
    
    ' IF WE GOT TO HERE, ACCESS WAS GRANTED.
    
    ' Initialize application-part controls' contents
    ' and state (which may depend on access rights).
    InitAppControls  ' also applies customizations
    If Err.Number = 0 Then
        bInitAppCtrls = True
    Else
        GoTo RollBack  ' GETS OUT of function
    End If
    
    ' IF WE GOT TO HERE, WE INITIALIZED APPLICATION-
    ' PART CONTROLS' CONTENTS AND STATE.
    
    ' Indicate that we DIDN'T have to roll back.
    ' (Clear any errors too, as this is an "On Error
    ' Resume Next" trap.)
    AppOpenSeqRollback = False
    Err.Clear
Exit Function

RollBack:
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    
    ' Save error information in variables for use
    ' during the actual rollbacks.  (Err itself will
    ' be cleared before they start.)
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
    ' Show any session errors and print a debug
    ' message for the programmer to help diagnosis
    ' (and clear all errors).
    ' NOTE: We do the RaiseEvent call here as
    '       StdACCPACErrorHandler only raises it if
    '       a message or error box is shown.  This
    '       event doesn't need to be raised before
    '       any MsgBox calls between here and "End
    '       Function".
    RaiseEvent CloseSplashScreen
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        False, True ' clears error
    
  ' Do the actual rollbacks, ignoring errors that
  ' may occur during the rollback sequence.
  On Error Resume Next
    ' <UNDO **ONLY** "REVERSIBLE" CHANGES IN THE
    '  REVERSE ORDER OF THE ORIGINAL CALLS.  USE THE
    '  ROLLBACK FLAGS TO SEE HOW FAR YOU GOT BEFORE
    '  THE ERROR OCCURRED.  THE EXAMPLE BELOW (AND
    '  TEMPLATE CODE) SHOWS HOW TO UNDO A CALL IF
    '  THE ERROR OCCURRED DURING/AFTER THAT CALL.>
    ' NOTE: Even if a call goes to "rollback" upon
    '       failure, it may not need undoing.  (For
    '       example, an external flag check may fail
    '       but it doesn't need undoing.)
    ' NOTE: In the example below, the "ElseIf" part
    '       would be omitted if a failure in
    '       InitSomething didn't cause a jump to the
    '       rollback "handler".
    ' EXAMPLE:
    '   If bInitSomething = True Then
    '       ' We got past InitSomething, so undo it.
    '       ClearSomething
    '   ElseIf bInitPreviousThing = True Then
    '       ' We failed during InitSomething, so we
    '       ' might need to inform the user and do
    '       ' a partial rollback of InitSomething.
    '   End If  ' bInitSomething = True / ElseIf bInitPreviousThing = True
    
    If bInitAppCtrls = True Then
        ' Clear references from controls that hold
        ' them.
        ClearAppControls
    ' <BELOW: IF NEEDED, CHANGE bCheckARights TO THE
    '  LAST BOOLEAN SET TO TRUE BEFORE THE CALL TO
    '  InitAppControls.>
    ElseIf bCheckARights = True Then
        ' We failed during InitAppControls, so ...
        ' <IF NEEDED, INFORM THE USER OF WHAT FAILED
        '  AND TAKE ROLLBACK ACTION TO REVERSE THE
        '  PARTIALLY DONE InitAppControls.>
    End If
    
    If bCheckARights = True Then
        ' Reset access rights to defaults.
        ResetAccessRights
    ' <BELOW: IF NEEDED, CHANGE bActivateDS TO THE
    '  LAST BOOLEAN SET TO TRUE BEFORE THE CALL TO
    '  CheckAccessRights.>
    ElseIf bActivateDS = True Then
        ' We failed during CheckAccessRights, so
        ' inform the user that the application part
        ' is closing.  Use the appropriate message.
        If lErrNum = 0 Then
            ' Access was denied.
            MsgBox mstrAccessDeniedMsg, _
                ACCPACErrMBStyle, _
                mstrACCPACErrMBCap, App.HelpFile, _
                HCIDAUIAccessDenied
        Else
            ' An error means access rights weren't
            ' determined.
            MsgBox mstrCheckRightsFailMsg, _
                ACCPACErrMBStyle, _
                mstrACCPACErrMBCap, App.HelpFile, _
                HCIDAUICheckRightsFail
        End If
        
        ' Reset access rights to defaults.
        ResetAccessRights
    End If
    
    If bActivateDS = True Then
        ' Clear lookup information and deactivate
        ' the data sources.
        ClearLookupInfo
        DeactivateDataSources
    ' <BELOW: IF NEEDED, CHANGE bInitDBLinks TO THE
    '  LAST BOOLEAN SET TO TRUE BEFORE THE CALL TO
    '  ActivateDataSources.>
    ElseIf bInitDBLinks = True Then
        ' We failed during ActivateDataSources, so
        ' inform the user that the application part
        ' is closing due to faulty data source
        ' activation.  Note that ActivateDataSources
        ' has an error handler that cleared lookup
        ' information and deactivated data sources.
        MsgBox mstrActDSFailMsg, ACCPACErrMBStyle, _
            mstrACCPACErrMBCap, App.HelpFile, _
            HCIDAUIActDSFail
    End If
    
    If bInitDBLinks = True Then
        ' Close the DB links (and clear mUIDBLinks).
        CloseDBLinks
    ' <BELOW: IF THERE'S A "ROLLBACK" CALL BEFORE
    '  InitDBLinks, CHANGE THE "ELSE" TO AN "ELSEIF"
    '  TO CHECK IF THE BOOLEAN SET FOR THE CALL
    '  BEFORE InitDBLinks IS SET TO TRUE.>
    Else
        ' We failed during InitDBLinks, so inform
        ' the user that the application part is
        ' closing because DB links couldn't be
        ' initialized.
        MsgBox mstrInitDBFailMsg, ACCPACErrMBStyle, _
            mstrACCPACErrMBCap, App.HelpFile, _
            HCIDAUIInitDBFail
        
        ' The InitDBLinks handler already set all DB
        ' links to Nothing.  We just need to clear
        ' the collection of DB links.
        If (Not (mUIDBLinks Is Nothing)) Then
            With mUIDBLinks
                Debug.Print "mUIDBLinks.Count = " & CStr(.Count)
                Dim i As Long
                For i = 1 To .Count
                    .Remove 1
                Next i
                Debug.Print "Final mUIDBLinks.Count = " & CStr(.Count)
            End With  ' mUIDBLinks
        End If  ' Not (mUIDBLinks Is Nothing)
    End If  ' bInitDBLinks = True
    
    ' Make sure the company ID is cleared, close the
    ' session (if it exists), and destroy the
    ' session manager.
    mstrCompanyID = ""
    
    If (Not (mSession Is Nothing)) Then
        mSession.Close
        Set mSession = Nothing
    End If
    
    Set mSessMgr = Nothing
    
    ' We need to indicate that the UI's application
    ' part isn't open now.
    bUIAppIsOpen = False
    
    ' Localizations DON'T need to be reversed, but
    ' the HELP FILE has to be reset as the session
    ' is now closed.
    SetHelpFile
    
    ' SHOW THE "UIClosed" PART (as we may be showing
    ' nothing at this point), notify others that the
    ' UI's application part is closed, and INDICATE
    ' THAT WE HAD TO ROLL BACK (and clear errors).
    EnableApp False
    RaiseOnUIAppClosed
    AppOpenSeqRollback = True  ' ROLLBACK happened
    Err.Clear
End Function

' NOTE: Errors are RE-RAISED (to get to
'       "AppOpenSeqRollback").
Private Sub ActivateDataSources()
On Error GoTo ActivateDataSourcesHandler
    Debug.Print "ActivateDataSources"
    
    ' <IF YOU WANT AUTOMATIC MACRO RECORDING FOR A
    '  VIEW OBJECT, CALL mSession.macroRecordObject
    '  WITH UserContro.hWnd AND THE OBJECT NAME
    '  (WHICH IS FOUND IN THE APP-WIDE .INI FILE).>
    ' EXAMPLE: mSession.macroRecordObject _
    '                   UserControl.hWnd, "BKACCT"
    
    
    ' <BELOW: FOR EACH DATA SOURCE, IF IT ISN'T
    '  ACTIVATED YET (i.e. Active IS FALSE), ATTACH
    '  THE APPROPRIATE DB LINK TO IT, THEN SET ITS
    '  Active TO TRUE.  IF NECESSARY, REGISTER
    '  LOOKUPS, SET FIELD-RELATED MEMBER VARIABLES,
    '  AND SET THE InstantViewUpdate PROPERTY OF ANY
    '  OF ITS FIELDS **AFTER** Active IS SET TO
    '  TRUE.  HAVE A MEMBER VARIABLE TO HOLD EACH
    '  LOOKUP COOKIE RETURNED BY RegisterLookup AND
    '  USED LATER ON IN GetLookupValue.>
    ' NOTE: If there's no explicitly opened DB link,
    '       attach mSession to the data source (and
    '       make sure that the DBLinkType and
    '       DBLinkFlag are set), then activate the
    '       data source.
    ' EXAMPLE:
    '   With dsBKACCT
    '       If .Active = False Then
    '           .DBLinkCompany = mDBLinkCmpRW
    '           .Active = True
    '       End If
    '
    '       ' IF we need to register a lookup, set a
    '       ' field-related member, or change the
    '       ' InstantViewUpdate of a field, do this
    '       ' AFTER knowing that .Active is True.
    '       With .Fields("BANK")
    '           mlBANKSize = CLng(.Size)
    '           .InstantViewUpdate = True
    '       End With  ' .Fields("BANK")
    '
    '       mlLookupCookie = .RegisterLookup(3, _
    '         "BK0002", 1, DBLINK_COMPANY, 4, 8)
    '   End With  ' dsBKACCT
    With dsSCOPT
        If .Active = False Then
            .DBLinkCompany = mDBLinkCmpRW
            .Active = True
            .Read
        End If
    End With  ' dsSCOPT
    
    With dsSCACCT
        If .Active = False Then
            .DBLinkCompany = mDBLinkCmpRW
            .Active = True
            .Process
        End If
    End With  ' dsSCACCT
    
    ' Attach DB links and activate the data sources
    ' if they aren't activated yet.  (If necessary,
    ' register lookups and change a field's
    ' InstantViewUpdate property AFTER activating
    ' the corresponding data source.)
Exit Sub

ActivateDataSourcesHandler:
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    
    ' Save the error information in variables (as
    ' DeactivateDataSources will clear Err).
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
    ' Make sure lookup information is cleared and
    ' all data sources are deactivated (those subs
    ' handle their own errors).
    ClearLookupInfo
    DeactivateDataSources
    
    ' RE-RAISE the error to get to
    ' AppOpenSeqRollback's ("On Error Resume Next")
    ' handler, which will finish clearing objects
    ' and reversing the state back to showing the
    ' "UIClosed" part.
    Err.Raise lErrNum, strErrSource, strErrDesc, _
        strErrHelpFile, lErrHelpContext
End Sub

' This function returns True if the user is allowed
' to access the UI and False otherwise (including
' the case where an error occurred).
' NOTE: Errors are RE-RAISED (to get to
'       "AppOpenSeqRollback").
Private Function CheckAccessRights() As Boolean
On Error GoTo CheckAccessRightsHandler
    Debug.Print "CheckAccessRights"
    
    ' <INSTRUCTIONS: YOU NEED MEMBER FLAGS FOR EACH
    '  RIGHT THAT HAS TO BE ACCESSED ELSEWHERE (i.e.
    '  InitAppCtlsCallout).  THESE MEMBERS' VALUES
    '  ARE DETERMINED HERE AND ARE RESET TO "NO"
    '  VALUES IN ResetAccessRights.>
    
    ' <BELOW: IF NEEDED, CHANGE mDBLinkCmpRW TO THE
    '  APPROPRIATE DB LINK VARIABLE.>
    With mDBLinkCmpRW
        ' Do the "administrator" rights check.
        bUserIsAdmin = .SecCheck(RSC_ADMIN)
        If bUserIsAdmin = True Then
            ' <BELOW: SET ALL OTHER RIGHTS FLAGS TO
            '  "YES" VALUES.>
            
            ' Administrators have all rights.
            
            CheckAccessRights = True  ' access granted
        Else
            ' <CHECK OTHER USER ACCESS RIGHTS IN A
            '  SIMILAR MANNER TO THE "Admin" CHECK.
            '  GO FROM HIGHER TO LOWER PRIVILEGES,
            '  USING .SecCheck (OR DATA SOURCES'
            '  Security/SystemAccess) TO SET THE
            '  FLAGS.  IF THE USER IS ALLOWED TO
            '  ACCESS THE UI, SET CheckAccessRights
            '  TO True.  OTHERWISE, IT'S False.>
            ' EXAMPLE:
            '   mbMaintain = .SecCheck(BK_RSC_MAINTAIN)
            '   If mbMaintain = True Then
            '       ' The user has inquiry rights, but
            '       ' we don't need a flag for that.
            '
            '       CheckAccessRights = True  ' access granted
            '   Else
            '       CheckAccessRights = .SecCheck(BK_RSC_INQUIRE)
            '   End If  ' mbMaintain = True
            bInquiryRight = .SecCheck(SC_RSC_SCINQUIRY)
            bSetupRight = .SecCheck(SC_RSC_SCSETUP)
            
            CheckAccessRights = bSetupRight Or bInquiryRight
        End If  ' bUserIsAdmin = True
    End With  ' mDBLinkCmpRW
Exit Function

CheckAccessRightsHandler:
    ' Indicate that the access is NOT granted AND
    ' RE-RAISE the error to get to
    ' AppOpenSeqRollback's ("On Error Resume Next")
    ' handler, which will reset access rights and
    ' undo the rest of the opening sequence (to get
    ' back to the "UIClosed" part).
    CheckAccessRights = False
    With Err
        .Raise .Number, .Source, .Description, _
            .HelpFile, .HelpContext
    End With  ' Err
End Function

' This sub handles the end of "InitAppControls",
' where the UI programmer has to add/modify code.
' Right now, errors are handled within the sub, but
' you can make another handler to re-raise errors.
' You can also make this sub a function that returns
' success/failure.  Then, you change the part of
' "InitAppControls" that calls this callout, as well
' as the "Rollback" section of "AppOpenSeqRollback"
' so you report the problem and close the UI if
' something here failed.
' NOTE: Controls are NOT visible/enabled yet, so you
'       CAN'T do "SetFocus" calls.
Private Sub InitAppCtlsCallout()
On Error GoTo InitAppCtlsCalloutHandler
    Debug.Print "InitAppCtlsCallout"
    
    ' <BELOW: IF THIS IS A REPORT UI, MAKE SURE THE
    '  FOLLOWING "REPORT UI ONLY" SECTION IS
    '  **UNCOMMENTED**.  OTHERWISE, MAKE SURE THE
    '  FOLLOWING "REPORT UI ONLY" SECTION IS
    '  **COMMENTED OUT**.  IF THE SERVER IS REMOTE,
    '  THIS SECTION DISABLES THE "Print Setup" MENU
    '  ITEMS AS WE CAN'T SET UP PRINTERS REMOTELY.>
    
    ' <--BEGIN "REPORT UI ONLY" SECTION-->
    If mSession.IsRemote = True Then
        mAppControls("mnuFile_PrintSetup").UIEnabledFlag = False
        mAppControls("popmnuFile_PrintSetup").UIEnabledFlag = False
    End If
    ' <--END "REPORT UI ONLY" SECTION-->
    
    ' <IF ANY FIELD EDIT CONTROL HAS A CUSTOM BUTTON
    '  WHOSE BITMAP YOU WANT TO CHANGE FROM THE
    '  DEFAULT "UP ARROW" TO SOMETHING ELSE, SET ITS
    '  BITMAP HERE.  SINCE THE FIELD EDIT CONTROL
    '  USES A **COPY** OF THE BITMAP, YOU CAN USE A
    '  LOCAL VARIABLE TO STORE THE BITMAP AND SET IT
    '  TO SEVERAL CUSTOM BUTTONS' BITMAPS.>
    ' EXAMPLE:
    '   Dim picCust As IPictureDisp
    '   Set picCust = mIResUI.GetResPicture( _
    '                   IDB_PicCust, vbResBitmap)
    '   fecBKACCT_A.SetCustomButtonPic picCust, 2
    '   fecBKACCT_B.SetCustomButtonPic picCust, 0
    '   Set picCust = Nothing  ' no longer used
    
    
    ' <IF YOU WANT A CONTROL TO START OUT AS
    '  DISABLED AND/OR INVISIBLE, SET ITS
    '  UIEnabledFlag AND/OR UIVisibleFlag TO FALSE
    '  HERE (USING THE mAppControls COLLECTION,
    '  **NOT** THE DIRECT CONTROL).  ALSO SET OTHER
    '  INITIAL DISPLAY STATES BY SETTING THE
    '  CONTROL'S PROPERTIES DIRECTLY (**NOT** USING
    '  mAppControls).>
    ' NOTES ON CHANGING ENABLED/VISIBLE STATE:
    '     You MUST use mAppControl's UIEnabledFlag
    '   and UIVisibleFlag properties instead of
    '   directly setting the control's "Enabled" and
    '   "Visible" properties.  This is done so that
    '   the control is ONLY enabled/shown when ALL
    '   parties want it to be enabled/shown.  These
    '   parties are the "Customize" box, macro code
    '   (and automation controllers), other template
    '   code (i.e. in EnableApp), and code that's
    '   specific to your UI (i.e. code you add).
    '   These other parties use similar properties
    '   (i.e. CustVisibleFlag, MacroVisibleFlag,
    '   TmplVisibleFlag).  DO NOT use those other
    '   parties' properties here!!!  ONLY use the
    '   ones starting with "UI"!!!
    '     For example, UIVisibleFlag sets (or gets)
    '   the UI's "want visible" flag, then (if it's
    '   a "set") checks everyone else's flag before
    '   deciding whether to set the underlying
    '   control's "Visible" to True or False.  (The
    '   ACCPACControl class' read-only "Visible"
    '   property tells whether or not the underlying
    '   control is ACTUALLY visible.)  This way, one
    '   party won't undo another party's "hide".
    ' NOTE: If a field edit control has "ReadOnly =
    '       True", it's automatically disabled.
    '       (i.e. We DON'T have to do
    '       UIEnabledFlag = False.)
    ' NOTE: DO NOT CHANGE A CONTROL'S HEIGHT, LEFT,
    '       TOP, or WIDTH (or X1, X2, Y1, Y2).  The
    '       control's layout is localized, so you
    '       don't want to overwrite the localized
    '       layout (which is done at runtime).
    ' EXAMPLE: mAppControls(fecBKACCT_A.Name).UIEnabledFlag = False  ' use COLLECTION
    '          mAppControls(txtMyTextBox.Name).UIVisibleFlag = False  ' use COLLECTION
    '          txtMyTextBox.Locked = True  ' use control DIRECTLY
    If Not bUserIsAdmin Then
        If bSetupRight = False Then
            mAppControls(APP_Save_Button.Name).UIEnabledFlag = False
            mAppControls(APP_Save_Button.Name).UIVisibleFlag = False
        End If
    End If
    
    
    ' <IF NEEDED: FILL "DATA-DEPENDENT" CONTROLS
    '  WITH INITIAL DATA.>
    ' EXAMPLE: txtMyTextBox.Text = "Initial text here"
    Dim company As AccpacCompany
    Set company = mDBLinkCmpRW.GetCompany
    With company
        lblComp_Name.Caption = .Name
        lblComp_Address1.Caption = .Address1
        lblComp_Address2.Caption = .Address2
        lblComp_Address3.Caption = .Address3
        lblComp_Address4.Caption = .Address4
        lblComp_City.Caption = .City
        lblComp_State.Caption = .State
        lblComp_Postal.Caption = .PostCode
        lblComp_Country.Caption = .Country
    End With
    Set company = Nothing
    
    'lblSCOPT_EmailPassword.Caption = dsSCOPT.Fields("EMAILPSWD").Description
        
    ' <REFRESH ACCPAC VIEW LIST CONTROLS' DATA.>
    ' EXAMPLE: vlsBKFORM.RefreshData
    vlsSCACCT_Accounts.SetColumnName vlsSCACCT_Accounts.ColumnIndexByField("INCLUDE"), dsSCACCT.Fields("INCLUDE").Description
    vlsSCACCT_Accounts.RefreshData
    
    
    ' <CONNECT THE SESSION TO ACCPAC GRID CONTROLS.>
    ' EXAMPLE: grdBKTFRH.SetAccpacSession mSession
    With grdSCOPT_ForecastPeriods
        .SetAccpacSession mSession
        
        .SetCellData 0, 1, dsSCOPT.Fields("FCPERIOD1S").Value
        .SetCellData 1, 1, dsSCOPT.Fields("FCPERIOD1E").Value
        .SetCellData 0, 2, dsSCOPT.Fields("FCPERIOD2S").Value
        .SetCellData 1, 2, dsSCOPT.Fields("FCPERIOD2E").Value
        .SetCellData 0, 3, dsSCOPT.Fields("FCPERIOD3S").Value
        .SetCellData 1, 3, dsSCOPT.Fields("FCPERIOD3E").Value
        .SetCellData 0, 4, dsSCOPT.Fields("FCPERIOD4S").Value
        .SetCellData 1, 4, dsSCOPT.Fields("FCPERIOD4E").Value
        .SetCellData 0, 5, dsSCOPT.Fields("FCPERIOD5S").Value
        .SetCellData 1, 5, dsSCOPT.Fields("FCPERIOD5E").Value
        .SetCellData 1, 6, dsSCOPT.Fields("FCPERIOD5E").Value
    End With
    
    With grdSCOPT_DocumentNumbers
        .SetAccpacSession mSession
        
        .SetCellData 1, 0, dsSCOPT.Fields("CFELENGTH").Value
        .SetCellData 2, 0, dsSCOPT.Fields("CFEPREFIX").Value
        .SetCellData 3, 0, dsSCOPT.Fields("CFENEXTNBR").Value
    End With
    
    
    ' We STILL need to clear any errors (as some
    ' don't cause a jump to this sub's handler).
    Err.Clear
Exit Sub

InitAppCtlsCalloutHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True
    Resume Next  ' clears error
End Sub

' This sub is the LAST callout from "OpenUIApp".
' It's the place for UI programmers to add calls to
' the END of the application-part opening sequence
' (AFTER EnableApp, so the APPLICATION-PART CONTROLS
' are SHOWN and ENABLED), with STANDARD ERROR
' HANDLING (show error, resume next).
' NOTE: If you **REALLY** need to SET FOCUS at the
'       "beginning", make the "SetFocus" calls here.
Private Sub AppOpenSeqEnd()
On Error GoTo AppOpenSeqEndHandler
    Debug.Print "AppOpenSeqEnd"
    
    ' <IF YOUR UI HAS A NOTEBOOK, CALL ITS "CLICK"
    '  HANDLER WITH "-1" AS ARGUMENT (THIS IS PART
    '  OF THE TABBING SEQUENCE BUG FIX DESCRIBED IN
    '  MSDN ARTICLE Q154885).>
    ' EXAMPLE: BKACCT_SSTabNotebook_Click -1
    sstabOptions_Click -1
    
    
    ' <ADD YOUR OTHER CODE HERE.  SEE THE COMMENTS
    '   RIGHT ABOVE THIS SUB FOR MORE INFORMATION.>
Exit Sub

AppOpenSeqEndHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True
    Resume Next  ' clears error
End Sub


'---------------------------------------------------
' Commonly Modified Methods: Termination/Closing
'---------------------------------------------------

' Since the active control's value may not have been
' saved (updated) to the data source (as it hasn't
' lost focus yet), force the save (update).  This
' sub is a callout from "QueryCloseUIApp" and
' "UC_Resize" (when it's RUNTIME and the UI's
' application part is OPEN).
Private Sub SaveActiveCtlValue()
On Error Resume Next
    Debug.Print "SaveActiveCtlValue"
    
    Dim ctlActive As Control
    
    ' If the active control (the one with focus) is
    ' view-aware and hasn't updated its value to its
    ' data source yet, force the update now (so we
    ' know ALL unsaved changes in QueryCloseUIApp).
    Set ctlActive = UserControl.ActiveControl
    
    If (Not (ctlActive Is Nothing)) Then
        If (TypeOf ctlActive Is AccpacFieldEditControl) Then
            ctlActive.SaveValueToField
        ElseIf (TypeOf ctlActive Is AccpacViewList) Then
            ctlActive.SaveRecord
        ElseIf (TypeOf ctlActive Is OptFieldControl) Then
            ctlActive.SaveRecord
        ElseIf (TypeOf ctlActive Is PeriodPicker) Then
            ctlActive.Update
        ' <IF YOU HAVE OTHER "VIEW-AWARE" CONTROLS,
        '  ADD OTHER "ELSEIF" CONDITIONS TO SEE IF
        '  ONE OF THEM COULD BE THE ACTIVE CONTROL.
        '  IF SO, IT HAS TO PASS TO THE DATA SOURCE
        '  ITS CURRENT VALUE.>
        End If
        
        Set ctlActive = Nothing  ' no longer used
    End If
    
    Err.Clear
End Sub

' <--"SAVE BUTTON" VERSION -->
' IF YOU REMOVE THE "SAVE" (AND/OR "POST") BUTTON,
' REPLACE THIS VERSION OF UnsavedChangesExist WITH
' UCExistNOSave.txt.
Private Function UnsavedChangesExist() As Boolean
On Error GoTo UnsavedChangesExistHandler
    Debug.Print "UnsavedChangesExist"
    
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        If (APP_Save_Button.Enabled = False) Or (APP_Save_Button.Visible = False) Then
            UnsavedChangesExist = False
        ' <CHANGE THE "False" PART OF THE "ElseIf"
        '  CONDITION TO CHECK TO THAT **ALL** DATA
        '  SOURCES ARE ACTIVE.  USE "AND" TO JOIN
        '  THE "Active" CHECKS.>
        ' NOTE: DON'T use the collection of data
        '       sources, as this function's caller
        '       (QueryCloseUIApp) can be called AT
        '       ANY TIME since it's public.
        ' EXAMPLE: (CHANGED "ELSEIF" CONDITION)
        '   ElseIf (dsBATCH.Active = True) _
        '     And (dsHEADER.Active = True) _
        '     And (dsDETAIL.Active = True) _
        '     Then
        ElseIf (dsSCOPT.Active = True) _
            And (dsSCACCT.Active = True) Then
            ' <CHANGE THE "False" PART OF THE "If
            '  False Then" CONDITION TO CHECK FOR
            '  **ANY** "DIRTY" DATA SOURCES.  IF A
            '  DETAIL DATA SOURCE HAS A REVISION
            '  LIST, CHECK FOR UNPOSTED REVISIONS
            '  INSTEAD.  USE "OR" TO JOIN THE
            '  "Dirty"/"UnpostedRevisions" CHECKS.>
            ' NOTE: DON'T use the collection of data
            '       sources, as this function's
            '       caller (QueryCloseUIApp) can be
            '       called AT ANY TIME.
            ' EXAMPLE: (CHANGED "IF" CONDITION)
            '   If (dsBATCH.Dirty = True) _
            '     Or (dsHEADER.Dirty = True) _
            '     Or (dsDETAIL.UnpostedRevisions = True) _
            '     Then
            If (dsSCOPT.Dirty = True) _
                Or (dsSCACCT.UnpostedRevisions = True) Then
                UnsavedChangesExist = True
            Else
                UnsavedChangesExist = False
            End If  ' at least one data source has changes
        Else
            UnsavedChangesExist = False
        End If  ' APP_Save_Button is enabled and visible / ElseIf all data sources are active
    Else
        UnsavedChangesExist = False
    End If  ' (bRunMode = True) And (bUIAppIsOpen = True)
Exit Function

UnsavedChangesExistHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True
    Resume Next  ' clears error
End Function

' This callout from "CloseUIApp" handles the section
' of the application-part closing sequence where UI
' programmers can insert their own calls.
' INSTRUCTIONS:
'   ADD ANY ADDITIONAL CLOSING SEQUENCE PROCEDURE
'   CALL(S) AT THE APPROPRIATE PLACE(S) INSIDE THIS
'   SUB.  NOTE THAT THE CLOSING AND OPENING
'   SEQUENCES SHOULD BE APPROXIMATELY THE "REVERSE"
'   OF EACH OTHER.
Private Sub AppCloseSequence()
On Error GoTo AppCloseSequenceHandler
    Debug.Print "AppCloseSequence"
    
    ' Reset the "Customize" Box state-related member
    ' (which MAY have been set inside CustomizeBox).
    mstrCustLastProfileID = ""
    
    ' Clear any controls that still hold references
    ' to objects such as views or view fields.
    ClearAppControls
    
    ' Reset user access rights (to defaults),
    ' deactivate the data sources (this will free
    ' object references), and close any explicitly
    ' opened DB links.
    ResetAccessRights
    DeactivateDataSources
    CloseDBLinks
Exit Sub

AppCloseSequenceHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True
    Resume Next  ' clears error
End Sub

' This sub handles the part of "ClearAppControls"
' where the UI programmer may have to add code.
Private Sub ClearAppCtlsCallout()
On Error GoTo ClearAppCtlsCalloutHandler
    Debug.Print "ClearAppCtlsCallout"
    
    ' <CLEAR ANY CONTROLS THAT **AREN'T** VIEW-AWARE
    '  BUT THAT NEED CLEARING IN ORDER FOR PROPER
    '  OBJECT CLEANUP (i.e. REFERENCE COUNTS = 0) TO
    '  HAPPEN.>
Exit Sub

ClearAppCtlsCalloutHandler:
    ' If we have a problem, just keep on going after
    ' displaying the error message.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True
    Resume Next  ' clears error
End Sub

Private Sub ClearLookupInfo()
On Error GoTo ClearLookupInfoHandler
    Debug.Print "ClearLookupInfo"
    
    ' <CLEAR THE CAPTIONS OF LOOKED-UP CONTROLS.>
    ' EXAMPLE: lblLookupDesc.Caption = ""
    
    
    ' <RESET EACH LOOKUP COOKIE MEMBER TO THE
    '  DEFAULT VALUE OF 0 ("NO LOOKUP").>
    ' EXAMPLE: mlLookupCookie = 0
Exit Sub

ClearLookupInfoHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message for the programmer to
    ' help diagnosis (and clearing the error).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next
End Sub

Private Sub ResetAccessRights()
On Error GoTo ResetAccessRightsHandler
    Debug.Print "ResetAccessRights"
    
    ' Set user access rights-related members to
    ' their default values.
    bUserIsAdmin = False
    ' <SET OTHER USER ACCESS RIGHTS-RELATED PRIVATE
    '  MEMBERS TO THEIR DEFAULT VALUES.>
    bSetupRight = False
    bInquiryRight = False
Exit Sub

ResetAccessRightsHandler:
    ' Print a debug message for the programmer to
    ' help with diagnosis, then keep on going.
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next  ' clears error
End Sub

Private Sub DeactivateDataSources()
On Error GoTo DeactivateDataSourcesHandler
    Debug.Print "DeactivateDataSources"
    
    ' <BELOW: FOR EACH DATA SOURCE, MAKE SURE IT'S
    '  DEACTIVATED BY SETTING ITS Active TO FALSE.>
    ' NOTE: DO NOT use "Close" (which is just a view
    '       call)!
    ' EXAMPLE: dsBKACCT.Active = False
    dsSCACCT.Active = False
    dsSCOPT.Active = False
    
    ' Make sure the data sources are deactivated.
    
    
    ' <IF YOU HAVE ANY OTHER MEMBER VARIABLES THAT
    '  WERE SET BASED ON AN ACTIVATED DATA SOURCE'S
    '  VALUES (i.e. FIELD-RELATED VALUES), BUT WERE
    '  NOT RESET YET, RESET THEM TO DEFAULT VALUES.>
    ' EXAMPLE: mlBANKSize = -1
Exit Sub

DeactivateDataSourcesHandler:
    ' Print a debug message AND FORCE A BREAKPOINT
    ' to help with diagnosis, then keep on going.
    ' NOTE: If there's no "common" resource object,
    '       we make sure to print a VB ERROR ONLY.
    If mIResTmpl Is Nothing Then
        StdACCPACErrorHandler Me, Nothing, Nothing, _
            False, True
    Else
        StdACCPACErrorHandler Me, mSession, _
            mIResTmpl, False, True
    End If
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' clears error
End Sub

' This sub handles the end of "UC_Terminate", where
' the UI programmer may have to add code.
Private Sub TerminateUCCallout()
On Error Resume Next  ' clears any previous errors
    Debug.Print "TerminateUCCallout"
    
    ' <SET OTHER SAVED PROPERTIES' DEFAULT VALUE
    '  PRIVATE **OBJECT** MEMBERS TO NOTHING.>
    ' EXAMPLE: Set mMyObjProp = Nothing
    
    
    ' <BELOW: SET OTHER AccpacCOMAPI MEMBERS TO
    '  NOTHING.  START WITH THOSE MEMBERS THAT ARE
    '  DEEPEST DOWN IN THE OBJECT MODEL TREE.  FOR
    '  EXAMPLE, SET ANY VIEWS, THEN DB LINKS TO
    '  NOTHING.  mSessMgr SHOULD BE THE LAST THING
    '  SET TO NOTHING.>
    ' EXAMPLE: Set mDBLinkCmpRO = Nothing
    '          ...
    ' (LATER:) Set mSession = Nothing  <TEMPLATE>
    '          Set mSessMgr = Nothing  <TEMPLATE>
    
    ' Make sure the AccpacCOMAPI members are Nothing.
    Set mDBLinkCmpRW = Nothing
    Set mSession = Nothing
    Set mSessMgr = Nothing
    
    ' <SET ANY OTHER PRIVATE COLLECTION MEMBERS TO
    '  NOTHING.>
    ' EXAMPLE: Set mMyCollection = Nothing
    
    
    ' <SET OTHER PRIVATE OBJECT MEMBERS TO NOTHING.>
    ' EXAMPLE: Set mMyObject = Nothing
    
    
    Err.Clear
End Sub


'---------------------------------------------------
' Commonly Modified Methods: Resources/Help
'---------------------------------------------------

' This sub does the end of "SetLocalizedResources",
' where the UI programmer may have to add code.
Private Sub LocalResCallout()
On Error GoTo LocalResCalloutHandler
    Debug.Print "LocalResCallout"
    
    ' <BELOW: FOR ANY OTHER LOCALIZED RESOURCES THAT
    '  NEED TO BE PLACED IN MEMBER VARIABLES OR INTO
    '  CONTROLS' CAPTIONS, GRAB THEM FROM THE UI-
    '  SPECIFIC RESOURCE FILE (IN THE "With mIResUI"
    '  BLOCK) OR THE MODULE-WIDE RESOURCE FILE (IN
    '  THE "With mIResApp" BLOCK), DEPENDING ON
    '  WHERE THOSE RESOURCES ARE.>
    ' NOTE: For captions that are connected to field
    '       descriptions or resource IDs at design
    '       time, DON'T ADD ANY CODE HERE.
    ' NOTE: Most pictures don't need to be in member
    '       variables since they're used ONLY in the
    '       method where they're needed.
    ' EXAMPLES:
    '   Set mbmpMyBitmap = .GetResPicture( _
    '                 IDI_MyBitmap, vbResBitmap)
    '   mstrMyMsg = .GetResString(IDS_MyMsg)
    '   lblStatic.Caption = .GetResString( _
    '                           IDS_LblStaticCap)
    
    ' Grab other localized resources from the UI-
    ' specific resource file.
    With mIResUI
        ' <ADD YOUR CODE HERE.>
        sstabOptions.TabCaption(0) = .GetResString(SC9100ID.IDS_TAB_COMPANY)
        sstabOptions.TabCaption(1) = .GetResString(SC9100ID.IDS_TAB_PROCESSING)
        sstabOptions.TabCaption(2) = .GetResString(SC9100ID.IDS_TAB_ACCOUNTS)
        sstabOptions.TabCaption(3) = .GetResString(SC9100ID.IDS_TAB_EMAIL)
        '
        fraProcessing_Settings.Caption = .GetResString(SC9100ID.IDS_PROCESSING_FRAME_SETTINGS)
        fraProcessing_Statistics.Caption = .GetResString(SC9100ID.IDS_PROCESSING_FRAME_STATISTICS)
        lblProcess_ForecastPeriods.Caption = .GetResString(SC9100ID.IDS_PROCESSING_LABEL_PERIODS)
        grdSCOPT_ForecastPeriods.SetColumnCaption 0, .GetResString(SC9100ID.IDS_PROCESSING_PERIOD_FROM)
        grdSCOPT_ForecastPeriods.SetColumnCaption 1, .GetResString(SC9100ID.IDS_PROCESSING_PERIOD_TO)
        grdSCOPT_ForecastPeriods.SetCellData 0, 0, .GetResString(SC9100ID.IDS_PROCESSING_PERIOD_CURRENT)
        grdSCOPT_ForecastPeriods.SetCellData 0, 6, .GetResString(SC9100ID.IDS_PROCESSING_PERIOD_OVER)
        '
        lblProcess_DocumentNumbers.Caption = .GetResString(SC9100ID.IDS_PROCESSING_LABEL_DOCNUMBERS)
        grdSCOPT_DocumentNumbers.SetColumnCaption 0, .GetResString(SC9100ID.IDS_PROCESSING_DOCNUM_TYPE)
        grdSCOPT_DocumentNumbers.SetColumnCaption 1, .GetResString(SC9100ID.IDS_PROCESSING_DOCNUM_LENGTH)
        grdSCOPT_DocumentNumbers.SetColumnCaption 2, .GetResString(SC9100ID.IDS_PROCESSING_DOCNUM_PREFIX)
        grdSCOPT_DocumentNumbers.SetColumnCaption 3, .GetResString(SC9100ID.IDS_PROCESSING_DOCNUM_NEXTNBR)
        grdSCOPT_DocumentNumbers.SetCellData 0, 0, .GetResString(SC9100ID.IDS_PROCESSING_DOCNUM_FORECAST)
        '
        fraEmail_Settings.Caption = .GetResString(SC9100ID.IDS_EMAIL_FRAME_SETTINGS)
        fraEmail_Testing.Caption = .GetResString(SC9100ID.IDS_EMAIL_FRAME_SENDTEST)
        fraEmail_Advisory.Caption = .GetResString(SC9100ID.IDS_EMAIL_FRAME_ADVISORY)
        lblEmail_Advisory.Caption = .GetResString(SC9100ID.IDS_EMAIL_LABEL_ADVISORY)
        btnEmail_SendTest.Caption = .GetResString(SC9100ID.IDS_EMAIL_BUTTON_SENDTEST)
        '
        lblEmail_Consent.Caption = .GetResString(SC9100ID.IDS_EMAIL_CONSENT)
    End With  ' mIResUI
    
    ' Grab other localized resources from the
    ' module-wide resource file.
    With mIResApp
        ' <ADD YOUR CODE HERE.>
    End With  ' mIResApp
    
    ' Grab some localized resources from the
    ' "common-to-all" resource file.
    With mIResTmpl
        ' <BELOW: COMMENT OUT THE LINES RELATING TO
        '  THE PAIRS OF MENU ITEMS (STANDARD AND
        '  ASSOCIATED POPUP) THAT **AREN'T** IN YOUR
        '  UI.  IF THIS IS A REPORT UI, THE
        '  "File_Import" AND "File_Export" LINES ARE
        '  ALMOST ALWAYS COMMENTED OUT.  IF THIS IS
        '  **NOT** A REPORT UI, MAKE SURE THAT THE
        '  "File_PrintSetup" LINES ARE COMMENTED OUT
        '  BUT ALSO CHECK WHETHER OR NOT YOU NEED TO
        '  KEEP "File_Import" AND "File_Export".
        '  "File_Print" IS **RARELY** COMMENTED OUT
        '  (AND NEVER FOR REPORT UI'S).>
    
        ' Menu items from the template
        mnuFile_Print.Caption = _
            .GetResString(IDS_AUIMnuFilePrintCap)
        popmnuFile_Print.Caption = _
            .GetResString(IDS_AUIPopmnuFilePrintCap)
        mnuFile_PrintSetup.Caption = _
            .GetResString(IDS_AUIMnuFilePrintSetupCap)
        popmnuFile_PrintSetup.Caption = _
            .GetResString(IDS_AUIPopmnuFilePrintSetupCap)
'        mnuFile_Import.Caption = _
'            .GetResString(IDS_AUIMnuFileImportCap)
'        popmnuFile_Import.Caption = _
'            .GetResString(IDS_AUIPopmnuFileImportCap)
'        mnuFile_Export.Caption = _
'            .GetResString(IDS_AUIMnuFileExportCap)
'        popmnuFile_Export.Caption = _
'            .GetResString(IDS_AUIPopmnuFileExportCap)
        
        ' <BELOW: COMMENT OUT THE
        '  "APP_Delete_Button" LINES IF YOUR UI HAS
        '  **NO** "Delete" BUTTON.  COMMENT OUT THE
        '  "APP_Save_Button" LINES IF YOUR UI HAS
        '  **NO** "Save" BUTTON.  COMMENT OUT THE
        '  "APP_Print_Button" LINES IF YOUR UI HAS
        '  **NO** "Print" BUTTON.>
        
        ' Constituent controls from the template
'        APP_Delete_Button.Caption = _
'            .GetResString(IDS_AUIAppDeleteButtonCap)
        APP_Save_Button.Caption = _
            .GetResString(IDS_AUIAppSaveButtonCap)
'        APP_Print_Button.Caption = _
'            .GetResString(IDS_AUIAppPrintButtonCap)
    End With  ' mIResTmpl
Exit Sub

LocalResCalloutHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message for the programmer to
    ' help diagnosis (and clearing the error).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next
End Sub

' This sub sets ALL picture resources for the UI to
' Nothing (the default).  It is called by
' SetDefaultResources as well as UC_Hide and
' UC_Terminate (to clear object references).  (Make
' sure it doesn't happen until **AFTER** the call to
' "CreateDynamicControls".)
Private Sub SetDefaultPics()
On Error GoTo SetDefaultPicsHandler
    Debug.Print "SetDefaultPics"
    
    ' UI's associated icon
    Set micoABPic = Nothing
    
    ' <SET ANY OTHER LOCALIZED PICTURE MEMBER
    '  VARIABLES TO NOTHING.>
Exit Sub

SetDefaultPicsHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message for the programmer to
    ' help diagnosis (and clearing the error).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next
End Sub

' This sub handles the end of "SetDefaultResources",
' where the UI programmer may have to add code.
Private Sub DefaultResCallout()
On Error GoTo DefaultResCalloutHandler
    Debug.Print "DefaultResCallout"
    
    ' <BELOW: FOR MEMBER VARIABLES AND CAPTIONS THAT
    '  HOLD LOCALIZED **STRINGS** (SET IN
    '  "LocalResCallout"), SET THEM TO "" (OR TO
    '  DEFAULT ENGLISH STRINGS IF NEEDED) IN THIS
    '  SUB.  IN KEEPING WITH THE ORGANIZATION OF
    '  "LocalResCallout", PUT THE STRINGS UNDER THE
    '  UI-SPECIFIC OR MODULE-WIDE SECTIONS.>
    ' NOTE: For field edit control captions (and
    '       others that are connected to field
    '       descriptions or resource IDs at design
    '       time), DON'T ADD ANY CODE HERE.
    ' EXAMPLES:
    '   mstrMyMsg = ""
    '   lblStatic.Caption = ""
    sstabOptions.TabCaption(0) = ""
    sstabOptions.TabCaption(1) = ""
    sstabOptions.TabCaption(2) = ""
    sstabOptions.TabCaption(3) = ""
    
    lblComp_Name.Caption = ""
    lblComp_Address1.Caption = ""
    lblComp_Address2.Caption = ""
    lblComp_Address3.Caption = ""
    lblComp_Address4.Caption = ""
    lblComp_City.Caption = ""
    lblComp_State.Caption = ""
    lblComp_Postal.Caption = ""
    lblComp_Country.Caption = ""
    
    fraProcessing_Settings.Caption = ""
    fraProcessing_Statistics.Caption = ""
    lblProcess_ForecastPeriods.Caption = ""
    grdSCOPT_ForecastPeriods.SetColumnCaption 0, ""
    grdSCOPT_ForecastPeriods.SetColumnCaption 1, ""
    '
    lblProcess_DocumentNumbers.Caption = ""
    grdSCOPT_DocumentNumbers.SetColumnCaption 0, ""
    grdSCOPT_DocumentNumbers.SetColumnCaption 1, ""
    grdSCOPT_DocumentNumbers.SetColumnCaption 2, ""
    grdSCOPT_DocumentNumbers.SetColumnCaption 3, ""
    grdSCOPT_DocumentNumbers.SetCellData 0, 0, ""
    
    fraEmail_Settings.Caption = ""
    fraEmail_Testing.Caption = ""
    fraEmail_Advisory.Caption = ""
    lblEmail_Advisory.Caption = ""
    btnEmail_SendTest.Caption = ""
    
    ' ========== UI-Specific Resources ==========
    
    ' <ADD DEFAULTS FOR MEMBERS/CAPTIONS SET IN THE
    '  "With mIResUI" BLOCK OF "LocalResCallout".>
    
    
    ' ========== Module-Wide Resources ==========
    
    ' <ADD DEFAULTS FOR MEMBERS/CAPTIONS SET IN THE
    '  "With mIResApp" BLOCK OF "LocalResCallout".>
    
    
    ' ========== "Common" Resources ==========
    
    ' <BELOW: COMMENT OUT THE LINES RELATING TO THE
    '  PAIRS OF MENU ITEMS (STANDARD AND ASSOCIATED
    '  POPUP) THAT **AREN'T** IN YOUR UI.  IF THIS
    '  IS A REPORT UI, THE "File_Import" AND
    '  "File_Export" LINES ARE ALMOST ALWAYS
    '  COMMENTED OUT.  IF THIS IS **NOT** A REPORT
    '  UI, MAKE SURE THE "File_PrintSetup" LINES ARE
    '  COMMENTED OUT, BUT ALSO CHECK WHETHER OR NOT
    '  YOU NEED TO KEEP "File_Import" AND
    '  "File_Export".  "File_Print" IS **RARELY**
    '  COMMENTED OUT (AND NEVER FOR REPORT UI'S).>
    
    ' Menu items provided by the template
    mnuFile_Print.Caption = ""
    popmnuFile_Print.Caption = ""
    mnuFile_PrintSetup.Caption = ""
    popmnuFile_PrintSetup.Caption = ""
'    mnuFile_Import.Caption = ""
'    popmnuFile_Import.Caption = ""
'    mnuFile_Export.Caption = ""
'    popmnuFile_Export.Caption = ""
    
    ' <BELOW: COMMENT OUT THE "APP_Delete_Button"
    '  LINE IF YOUR UI HAS **NO** "Delete" BUTTON.
    '  COMMENT OUT THE "APP_Save_Button" LINE IF
    '  YOUR UI HAS **NO** "Save" BUTTON.  COMMENT
    '  OUT THE "APP_Print_Button" LINE IF YOUR UI
    '  HAS **NO** "Print" BUTTON.>
    
    ' Constituent controls provided by the template
'    APP_Delete_Button.Caption = ""
    APP_Save_Button.Caption = ""
'    APP_Print_Button.Caption = ""
Exit Sub

DefaultResCalloutHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message for the programmer to
    ' help diagnosis (and clearing the error).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next
End Sub

' This sub handles the end of "SetHelpIDs", where
' the UI programmer may have to add code.
' NOTE: HelpContextIDs STAY THE SAME for all
'       languages!!!
Private Sub HelpIDsCallout()
On Error GoTo HelpIDsCalloutHandler
    Debug.Print "HelpIDsCallout"
    
    ' ***** Menu Items *****
    
    ' <BELOW: COMMENT OUT THE LINES RELATING TO THE
    '  PAIRS OF MENU ITEMS (STANDARD AND ASSOCIATED
    '  POPUP) THAT **AREN'T** IN YOUR UI.  IF THIS
    '  IS A REPORT UI, THE "File_Import" AND
    '  "File_Export" LINES ARE ALMOST ALWAYS
    '  COMMENTED OUT.  IF THIS IS **NOT** A REPORT
    '  UI, MAKE SURE THE "File_PrintSetup" LINES ARE
    '  COMMENTED OUT, BUT ALSO CHECK WHETHER OR NOT
    '  YOU NEED TO KEEP "File_Import" AND
    '  "File_Export".  "File_Print" IS **RARELY**
    '  COMMENTED OUT (AND NEVER FOR REPORT UI'S).>
    
    ' Menu items provided by the template
    mnuFile_Print.HelpContextID = HCIDAUIMnuFilePrint
    popmnuFile_Print.HelpContextID = HCIDAUIMnuFilePrint
    mnuFile_PrintSetup.HelpContextID = HCIDAUIMnuFilePrintSetup
    popmnuFile_PrintSetup.HelpContextID = HCIDAUIMnuFilePrintSetup
'    mnuFile_Import.HelpContextID = HCIDAUIMnuFileImport
'    popmnuFile_Import.HelpContextID = HCIDAUIMnuFileImport
'    mnuFile_Export.HelpContextID = HCIDAUIMnuFileExport
'    popmnuFile_Export.HelpContextID = HCIDAUIMnuFileExport
    
    ' <SET THE HelpContextIDs FOR ANY OTHER (UI-
    '  SPECIFIC) MENU ITEMS.>
    
    
    ' ***** Other Constituent Controls *****
    
    ' <BELOW: COMMENT OUT THE "APP_Delete_Button"
    '  LINE IF YOUR UI HAS **NO** "Delete" BUTTON.
    '  COMMENT OUT THE "APP_Save_Button" LINE IF
    '  YOUR UI HAS **NO** "Save" BUTTON.  COMMENT
    '  OUT THE "APP_Print_Button" LINE IF YOUR UI
    '  HAS **NO** "Print" BUTTON.>
    
    ' Constituent controls provided by the template
'    APP_Delete_Button.HelpContextID = HCIDAUIAppDeleteButton
    APP_Save_Button.HelpContextID = HCIDAUIAppSaveButton
'    APP_Print_Button.HelpContextID = HCIDAUIAppPrintButton
    
    ' <SET ALL HelpContextIDs FOR ALL OTHER (UI-
    '  SPECIFIC) CONSTITUENT CONTROLS.>
Exit Sub

HelpIDsCalloutHandler:
    ' If we have a problem, just keep on going after
    ' printing a debug message for the programmer to
    ' help diagnosis (and clearing the error).
    ' NOTE: There's NO session errors here and NO
    '       need for resources as nothing is shown.
    StdACCPACErrorHandler Me, Nothing, Nothing, _
        False, True
    Resume Next
End Sub


'---------------------------------------------------
' Commonly Modified Methods: Other Behavior
'---------------------------------------------------

' This function saves the record.  It returns True
' if the record was actually saved, and False
' otherwise (i.e. if there had been an error).  This
' makes it easier for callers to see if the "Save"
' actually happened.
Private Function SaveRecord() As Boolean
On Error GoTo SaveRecordHandler
    Debug.Print "SaveRecord"
    
    Dim mousePtr As VBRUN.MousePointerConstants
    mousePtr = vbDefault  ' in case of error determining original mouse pointer
    
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        ' Temporarily change the mouse pointer to
        ' the hourglass (saving may take a while).
        mousePtr = UserControl.MousePointer
        UserControl.MousePointer = vbHourglass
        
        ' <IF YOU **HAVE** A "Save" BUTTON, DO AN
        '  UPDATE (RECORD ALREADY EXISTS) OR INSERT
        '  (NEW RECORD) ON EACH DATA SOURCE THAT
        '  NEEDS TO HAVE THIS DONE (USUALLY IT'S
        '  JUST THE PARENT IN THE HIERARCHY).>
        ' NOTE: "Update/Insert" checks for "dirty".
        ' NOTE: If you have a "Post" button, this is
        '       a good place for the actual posting.
        ' EXAMPLE: (IF THERE'S A "SAVE" BUTTON)
        If (APP_Save_Button.Enabled = True) And (APP_Save_Button.Visible = True) Then
            
            dsSCOPT.Verify
            
            With dsSCOPT
                If .Exists = True Then
                    .Update  ' do the update
                Else
                    .Insert  ' insert a new record
                End If
            End With  ' dsSCOPT
            
            dsSCACCT.Post
                                   
            '
            ' Verify Exchange Rate
            dsSCOPT.Fields.FieldByName("PROCESSCMD").PutWithoutVerification 0
            dsSCOPT.Process
                       
            ' Display warnings/messages that
            ' may come from the "Save".
            StdACCPACErrorHandler Me, mSession, _
                mIResTmpl, False, True
        End If  ' (APP_Save_Button.Enabled = True) And (APP_Save_Button.Visible = True)
        
        ' Change the mouse pointer back.
        UserControl.MousePointer = mousePtr
    End If  ' (bRunMode = True) And (bUIAppIsOpen = True)
    
    ' Indicate a successful "Save" (i.e. no errors
    ' going through this function, whether or not
    ' we actually saved anything).
    SaveRecord = True
Exit Function

SaveRecordHandler:
    ' Change the mouse pointer back.
    UserControl.MousePointer = mousePtr
    
    ' Just show the session errors (or VB error if
    ' there aren't any), indicate "failure" of the
    ' "Save", and quit this operation.
    ' NOTE: If a data source "Update/Insert" fails,
    '       don't try the next data sources'
    '       "Update/Insert"s, as this would make
    '       things inconsistent.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True  ' clears error
    SaveRecord = False
End Function

' If the record isn't saved, this function lets the
' user choose "Yes", "No" or "Cancel" to saving it.
' If the choice is "Yes", ONE save attempt is made
' (if it fails, it's the same as "Cancel").  THIS
' FUNCTION'S RETURN VALUE INDICATES WHETHER OR NOT
' TO CONTINUE (True) OR CANCEL (False).
' NOTE: UnsavedChangesExist ALWAYS returns False if
'       we don't have (or can't access) "Save".
Private Function CheckSaveRecord() As Boolean
On Error GoTo CheckSaveRecordHandler
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        ' Since the active control hasn't lost focus
        ' yet, save its value to its data source if
        ' it's view-aware.
        SaveActiveCtlValue
    End If
    
    ' NOTE: If it's design time OR if the UI's
    '       application part is already closed,
    '       UnsavedChangesExist will return FALSE
    '       (obviously, as there are no changes).
    If UnsavedChangesExist = True Then
        Dim res As VbMsgBoxResult
                
        ' Prompt the user to save.
        res = MsgBox( _
            MessageReplace(mstrSaveRecordMsg, _
             Array(dsSCOPT.Description, "")), _
            vbYesNoCancel + vbMsgBoxHelpButton + _
            vbQuestion, mIResTmpl.GetResString(IDS_ACCPACConfMBCap, False), _
            App.HelpFile, HCIDAUISaveRecord)
        ' <REPLACE THE "<RECORD TYPE>" STRING WITH A
        '  A RESOURCE STRING INDICATING THE TYPE OF
        '  RECORD (i.e. Bank) BEING SAVED.  REPLACE
        '  THE "<KEY VALUE>" STRING WITH THE ACTUAL
        '  KEY FIELD'S VALUE.  IF AN ALTERNATE
        '  ADD/SAVE MESSAGE IS USED, THE ARRAY MAY
        '  HAVE DIFFERENT ELEMENTS.>
        ' EXAMPLE:
        '   "<RECORD TYPE>" replaced by:
        '      ' The string below would be "Bank"
        '      mIResUI.GetResString(IDS_BankRecType)
        '   "<KEY VALUE>" replaced by:
        '      CStr(dsBKACCT.Fields("BANK").Value)
        
        If res = vbCancel Then
            CheckSaveRecord = False  ' DON'T continue
        ElseIf res = vbYes Then
            ' Try to save the record ONCE.  The
            ' return value tells us whether to
            ' continue ("True") or not ("False",
            ' meaning the "Save" failed.)
            CheckSaveRecord = SaveRecord
        Else
            CheckSaveRecord = True  ' CONTINUE anyway
        End If  ' res = vbCancel / ElseIf res = vbYes
    Else
        ' There's no unsaved changes, so indicate to
        ' the caller that it's OK to CONTINUE.
        CheckSaveRecord = True
    End If  ' UnsavedChangesExist = True (BEFORE save)
Exit Function

CheckSaveRecordHandler:
    ' Just show the session errors (or VB error if
    ' there aren't any), indicate to the caller NOT
    ' to continue with the operation.
    StdACCPACErrorHandler Me, mSession, mIResTmpl, _
        True, True  ' clears error
    CheckSaveRecord = False
End Function

Private Sub mnuFile_Print_Click()
On Error Resume Next
    If (bRunMode = True) And (bUIAppIsOpen = True) Then
        ' Prompt to save the record first.
        If CheckSaveRecord = False Then
            ' The user cancelled the operation, so
            ' clear errors and GET OUT of the sub.
            Err.Clear
            Exit Sub
        End If
        
        Dim pStatus As AccpacCOMAPI.tagEventStatus
        
        ' Allow macros to cancel the operation.
        pStatus = STATUS_OK
        RaiseEvent BeforeCtlClick("", _
            "mnuFile_Print", pStatus)
        If pStatus = STATUS_CANCEL Then
            Exit Sub
        End If
        
        ' IF WE GOT TO HERE, WE CAN PROCEED.
        
        ' <BELOW: IF THIS IS A REPORT UI, MAKE SURE
        '  THE "PrintReport" CALL IS **UNCOMMENTED**
        '  WHILE THE "LaunchRptUI" CALL IS
        '  **COMMENTED OUT**.  IF THIS IS **NOT** A
        '  REPORT UI, MAKE SURE THE "PrintReport"
        '  CALL IS **COMMENTED OUT** WHILE THE
        '  "LaunchRptUI" CALL IS **UNCOMMENTED**.>
        
        ' Print/generate the report OR launch the
        ' associated report UI.
        PrintReport  ' REPORT UI'S ONLY
'        LaunchRptUI  ' NON-REPORT UI'S ONLY
        
        ' Let macros add "after" functionality.
        RaiseEvent AfterCtlClick("", "mnuFile_Print")
    End If
    
    Err.Clear
End Sub

' This function returns the name of the report to
' generate.  It's used by REPORT UI'S ONLY.
Private Function RptName() As String
On Error Resume Next
    RptName = "SCOPT"
    ' <CHANGE THE "<REPORT NAME>" RETURN STRING TO
    '  THE NAME (WITHOUT THE ".rpt" PART) OF THE
    '  REPORT TO GENERATE.>
    
    Err.Clear
End Function

' This function returns the report's menu ID.  It's
' used by REPORT UI'S ONLY.
Private Function RptMenuID() As String
On Error Resume Next
    RptMenuID = "SC9100"
    ' <CHANGE THE "<MENU ID>" RETURN STRING TO THE
    '  REPORT'S MENU ID.  THAT ID IS OFTEN THE ROTO
    '  ID (ACCPACProgramName) OF THE UI WHOSE
    '  "File->Print" MENU ITEM LAUNCHES THIS UI.>
    
    Err.Clear
End Function

' This sub is called by REPORT UI'S set up the
' report's paramaters.  It's a callout from
' "PrintReport".
' NOTE: BY HAVING NO ERROR HANDLER, errors are
'       RE-RAISED (to get to "PrintReport", which
'       quits the operation upon getting an error).
' NO ERROR HANDLING NEEDED!
Private Sub SetRptParams(ByRef rpt As AccpacReport)
    Debug.Print "SetRptParams"
    
    With rpt
        ' <SET UP EACH REPORT PARAMETER (EXCEPT
        '  "PATH" AND "EXT" ONES) USING THE
        '  <rpt>.SetParam METHOD.>
        ' EXAMPLE: (BK1420 REPORT)
        '   .SetParam "FROMTYPE", CStr(fecBKTT_From.Value)
        '   .SetParam "TOTYPE", CStr(fecBKTT_To.Value)
    End With  ' rpt
End Sub


'---------------------------------------------------
' UI-Specific Methods and Properties
'---------------------------------------------------

' <PLACE OTHER FUNCTIONS, SUBS, AND PROPERTIES IN
'  THIS SECTION.>
Private Sub dsSCOPT_OnRecordChanged(ByVal eReason As AccpacCOMAPI.tagEventReason, ByVal pField As AccpacDataSrcCtl.IAccpacDSField, ByVal pMultipleFields As AccpacDataSrcCtl.IAccpacDSFields)
    If eReason = RSN_READ Then
        SetFieldsPerCountry
    ElseIf eReason = RSN_FIELDCHANGE Then
        If pField.Name = "COUNTRY" Then
            pField.FlushValue True
            SetFieldsPerCountry
            dsSCOPT.Fields("BRYEAR").RefreshValue
        End If
        If pField.Name = "BRN" Then
            pField.FlushValue True
            dsSCOPT.Fields("BRYEAR").RefreshValue
        End If
        If pField.Name = "EMAILTEST" Or pField.Name = "PROCESSCMD" Then
            pField.FlushValue False
        End If
    End If
End Sub

Private Sub grdSCOPT_ForecastPeriods_OnBeforeStartEdit(ByVal Col As Integer, ByVal Row As Integer, Editable As Boolean)
    If Row = 0 Or Row = 6 Then _
        Editable = False
End Sub

Private Sub grdSCOPT_ForecastPeriods_OnStartEdit(ByVal FldName As String, ByVal Col As Integer, ByVal Row As Integer, pFieldEditCtrl As Object)
    Select Case Row
        Case 1
            pFieldEditCtrl.AccpacField = dsSCOPT.Fields("FCPERIOD1E")
        Case 2
            pFieldEditCtrl.AccpacField = dsSCOPT.Fields("FCPERIOD2E")
        Case 3
            pFieldEditCtrl.AccpacField = dsSCOPT.Fields("FCPERIOD3E")
        Case 4
            pFieldEditCtrl.AccpacField = dsSCOPT.Fields("FCPERIOD4E")
        Case 5
            pFieldEditCtrl.AccpacField = dsSCOPT.Fields("FCPERIOD5E")
    End Select
    
    pFieldEditCtrl.NumberDomain = POSITIVE_ONLY
End Sub

Private Sub grdSCOPT_ForecastPeriods_OnEndEdit(ByVal FieldName As String, ByVal Col As Integer, ByVal Row As Integer, ByVal FieldEditCtrl As Object, ByVal bValueSaved As Boolean)
    If Row < 5 Then
        grdSCOPT_ForecastPeriods.SetCellData 0, Row + 1, FieldEditCtrl.Value + 1
    Else
        grdSCOPT_ForecastPeriods.SetCellData 1, Row + 1, FieldEditCtrl.Value
    End If
End Sub

Private Sub grdSCOPT_DocumentNumbers_OnStartEdit(ByVal FldName As String, ByVal Col As Integer, ByVal Row As Integer, pFieldEditCtrl As Object)
    pFieldEditCtrl.AccpacField = dsSCOPT.Fields(FldName)
    pFieldEditCtrl.NumberDomain = POSITIVE_ONLY
End Sub

Private Sub SetFieldsPerCountry()
    Select Case dsSCOPT.Fields("COUNTRY").Value
        Case SCOPT.COUNTRY_SG:
            fecSCOPT_EntityType.AccpacField = dsSCOPT.Fields("ENTTYPESG")
            fecSCOPT_Industry.AccpacField = dsSCOPT.Fields("INDUSTRYSG")
        Case SCOPT.COUNTRY_MY:
            fecSCOPT_EntityType.AccpacField = dsSCOPT.Fields("ENTTYPEMY")
            fecSCOPT_Industry.AccpacField = dsSCOPT.Fields("INDUSTRYMY")
        Case SCOPT.COUNTRY_HK:
            fecSCOPT_EntityType.AccpacField = dsSCOPT.Fields("ENTTYPEHK")
            fecSCOPT_Industry.AccpacField = dsSCOPT.Fields("INDUSTRYHK")
        Case SCOPT.COUNTRY_AU:
            fecSCOPT_EntityType.AccpacField = dsSCOPT.Fields("ENTTYPEAU")
            fecSCOPT_Industry.AccpacField = dsSCOPT.Fields("INDUSTRYAU")
        Case SCOPT.COUNTRY_NZ:
            fecSCOPT_EntityType.AccpacField = dsSCOPT.Fields("ENTTYPENZ")
            fecSCOPT_Industry.AccpacField = dsSCOPT.Fields("INDUSTRYNZ")
        Case Else:
            fecSCOPT_EntityType.AccpacField = dsSCOPT.Fields("ENTITYTYPE")
            fecSCOPT_Industry.AccpacField = dsSCOPT.Fields("INDUSTRY")
    End Select
End Sub

Private Sub vlsSCACCT_Accounts_OnSetCustomItemData(ByVal bstrColName As String, ByVal bstrFieldName As String, pvBookMark As Variant, bstrData As String, pAccpacDSFields As Object)
    If bstrFieldName = "INCLUDE" Then
        bstrData = dsSCACCT.Fields("INCLUDE").PresentationStrings.FieldString
    End If
End Sub

Private Sub vlsSCACCT_Accounts_OnLBDblClick(ByVal iItem As Long, ByVal iIndex As Long, pvBookMark As Variant)
    dsSCACCT.GoToBookMark pvBookMark
        
    If iIndex = vlsSCACCT_Accounts.ColumnIndexByField("INCLUDE") Then
        If dsSCACCT.Fields("INCLUDE").Value = 0 Then
            dsSCACCT.Fields("INCLUDE").Value = 1
        Else
            dsSCACCT.Fields("INCLUDE").Value = 0
        End If
        dsSCACCT.Update
    End If
End Sub

Private Sub vlsSCACCT_Accounts_KeyDown(ByVal KeyCode As Long, ByVal iIndex As Integer, ByVal iItem As Integer, ByVal FieldName As String, ByVal Shift As Boolean, ByVal Ctrl As Boolean, ByVal Alt As Boolean, pvBookMark As Variant)
    If KeyCode = vbKeySpace And FieldName = "INCLUDE" Then
        vlsSCACCT_Accounts_OnLBDblClick iItem, iIndex, pvBookMark
    End If
End Sub

Private Sub btnEmail_SendTest_Click()
On Error GoTo btnEmail_SendTest_Click_Handler
    
    Dim mousePtr As VBRUN.MousePointerConstants
    mousePtr = vbDefault  ' in case of error determining original mouse pointer
    
    mousePtr = UserControl.MousePointer
    UserControl.MousePointer = vbHourglass
    
    DoEvents
    
    dsSCOPT.Fields.FieldByName("PROCESSCMD").PutWithoutVerification 1
    dsSCOPT.Process
        
    MsgBox mSession.RscGetString(ACCPACAppID, 399), _
        ACCPACStdMBStyle + vbInformation, mIResTmpl.GetResString(IDS_ACCPACInfoMBCap, False), _
        App.HelpFile, HCIDNoLocResources
        
btnEmail_SendTest_Click_Handler:
    UserControl.MousePointer = mousePtr
    
'    If Err.Number <> 0 Then
'        MsgBox mSession.RscGetString(ACCPACAppID, 400), _
'            ACCPACErrMBStyle, ACCPACErrMBCap, _
'            App.HelpFile, HCIDNoLocResources
'
'        Err.Clear
'    End If

    StdACCPACErrorHandler Me, mSession, _
    mIResTmpl, False, True
End Sub

Private Sub fecSCOPT_EmailPassword_OnSetFocus()
    WINAPI.SetPasswordField fecSCOPT_EmailPassword
End Sub

Private Sub sstabOptions_Click(PreviousTab As Integer)
On Error Resume Next
    Dim o As ACCPACControl
    For Each o In UIAppControls
        If o.Left < -40000 Then
            o.MacroVisibleFlag = False
        Else
            o.MacroVisibleFlag = True
        End If
    Next
    
    Err.Clear
End Sub

