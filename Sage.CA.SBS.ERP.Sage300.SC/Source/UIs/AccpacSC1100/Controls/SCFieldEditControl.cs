using AccpacDataSrc;
using AccpacFinder;
using AccpacFldEdit;
using stdole;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    public class SCFieldEditControl
        : Control,
        AccpacFieldEditControl,
        _IFieldEditControlEvents
    {
        private SCAxHost _axFieldEditControl;
        #region Constructors
        public SCFieldEditControl()
        {
            //_accpacFieldEditControl = new AccpacFieldEditControl();
            InitializeComponents();
        }

        private SCFieldEditControl(AccpacFieldEditControl accpacFieldEditControl)
        {
            _accpacFieldEditControl = accpacFieldEditControl;
        }

        private void InitializeComponents()
        {
            ComponentResourceManager resources = new ComponentResourceManager(typeof(SCFieldEditControl));
            _axFieldEditControl = new SCAxHost("A4wFldEdtCtrl.FieldEditControl");
            ((ISupportInitialize)_axFieldEditControl).BeginInit();
            SuspendLayout();

            _axFieldEditControl.OnAttachInterfaces += _axFieldEditControl_OnAttachInterfaces;

            Controls.Add(_axFieldEditControl);
            ((ISupportInitialize)_axFieldEditControl).EndInit();
            ResumeLayout();

        }

        private void _axFieldEditControl_OnAttachInterfaces(object ocx)
        {
            _axFieldEditControl.Location = new Point(0, 0);
            _axFieldEditControl.Dock = DockStyle.Fill;
            _axFieldEditControl.CreateControl();
            _accpacFieldEditControl = (AccpacFieldEditControl)ocx;

            _accpacFieldEditControl.OnChange += _accpacFieldEditControl_OnChange;
        }

        private void _accpacFieldEditControl_OnChange()
        {
            //SetBackgroundMode(2);
        }
        #endregion Constructors

        #region IDisposable
        private bool _disposed = false;

        protected override void Dispose(bool disposing)
        {
            if (_disposed)
                return;

            if (disposing)
            {

            }

            if (_accpacFieldEditControl != null)
            {
                Marshal.ReleaseComObject(_accpacFieldEditControl);
                _accpacFieldEditControl = null;
            }

            _disposed = true;

            base.Dispose(disposing);
        }
        #endregion IDisposable

        #region AccpacFieldEditControl
        private AccpacFieldEditControl _accpacFieldEditControl;

        public void let_AccpacField(IAccpacField pVal)
            => _accpacFieldEditControl.AccpacField = pVal;

        public void PutValueWithSetCursor(object newVal)
            => _accpacFieldEditControl.PutValueWithSetCursor(newVal);

        public void SetInternalStyle(int lStyle)
            => _accpacFieldEditControl.SetInternalStyle(lStyle);

        public void SaveValueToField()
            => _accpacFieldEditControl.SaveValueToField();

        public void Clear()
            => _accpacFieldEditControl.Clear();

        public void SetDSName(string newVal)
            => _accpacFieldEditControl.SetDSName(newVal);

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        public void AddNeighborFieldEditControl(AccpacFieldEditControl pVal)
            => _accpacFieldEditControl.AddNeighborFieldEditControl(pVal);

        public void AddNeighborFieldEditControl(SCFieldEditControl pVal)
            => _accpacFieldEditControl.AddNeighborFieldEditControl(pVal?._accpacFieldEditControl);

        public void SetFullSelectFlag(bool flag)
            => _accpacFieldEditControl.SetFullSelectFlag(flag);

        public void GetDisplayValue(out string pVal)
            => _accpacFieldEditControl.GetDisplayValue(out pVal);

        public void RefreshCurrencyValue()
            => _accpacFieldEditControl.RefreshCurrencyValue();

        public void SetCursorPosition(int nPos)
            => _accpacFieldEditControl.SetCursorPosition(nPos);

        public void SetCustomButtonPic(int idx, tagButtonBitmapType typeBitmap, string bstrTooltip)
            => _accpacFieldEditControl.SetCustomButtonPic(idx, typeBitmap, bstrTooltip);

        public void SetCustomButtonPic2(int idx, IPictureDisp bmpNormal, IPictureDisp bmpHot, IPictureDisp bmpDisabled, string bstrTooltip)
            => _accpacFieldEditControl.SetCustomButtonPic2(idx, bmpNormal, bmpHot, bmpDisabled, bstrTooltip);

        public void Finder()
            => _accpacFieldEditControl.Finder();

        public void InternalSet(string bstrName, string Val)
            => _accpacFieldEditControl.InternalSet(bstrName, Val);

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public object Value
        {
            get => _accpacFieldEditControl.Value;
            set => _accpacFieldEditControl.Value = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public short Appearance
        {
            get => _accpacFieldEditControl.Appearance;
            set => _accpacFieldEditControl.Appearance = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int BorderStyle
        {
            get => _accpacFieldEditControl.BorderStyle;
            set => _accpacFieldEditControl.BorderStyle = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool Valid
        {
            get => _accpacFieldEditControl.Valid;
            set => _accpacFieldEditControl.Valid = value;
        }

        [Browsable(false)]
        [DefaultValue(false)]
        public bool ReadOnly
        {
            get => _accpacFieldEditControl.ReadOnly;
            set => _accpacFieldEditControl.ReadOnly = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public IAccpacField AccpacField
        {
            get => _accpacFieldEditControl.AccpacField;
            set => _accpacFieldEditControl.AccpacField = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        uint IFieldEditControl.InvalidValueForeground
        {
            get => _accpacFieldEditControl.InvalidValueForeground;
            set => _accpacFieldEditControl.InvalidValueForeground = value;
        }

        public Color InvalidValueForeground
        {
            get => SCAxHost.GetColorFromOleColor(((IFieldEditControl)this).InvalidValueForeground);
            set => ((IFieldEditControl)this).InvalidValueForeground = SCAxHost.GetOleColorFromColor(value);
        }

        [Browsable(false)]
        [DefaultValue(tagFieldEditControlType.FIELD_EDIT_CONTROL_EDIT)]
        public tagFieldEditControlType ControlType
        {
            get => _accpacFieldEditControl.ControlType;
            set => _accpacFieldEditControl.ControlType = value;
        }


        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string DisplayValue
            => _accpacFieldEditControl.DisplayValue;

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool TileVertically
        {
            get => _accpacFieldEditControl.TileVertically;
            set => _accpacFieldEditControl.TileVertically = value;
        }

        [Browsable(false)]
        [DefaultValue(true)]
        public bool AllowNull
        {
            get => _accpacFieldEditControl.AllowNull;
            set => _accpacFieldEditControl.AllowNull = value;
        }

        [Browsable(false)]
        [DefaultValue(false)]
        public bool MultiLine
        {
            get => _accpacFieldEditControl.MultiLine;
            set => _accpacFieldEditControl.MultiLine = value;
        }

        [Browsable(false)]
        [DefaultValue(false)]
        public bool RequiredField
        {
            get => _accpacFieldEditControl.RequiredField;
            set => _accpacFieldEditControl.RequiredField = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string DataSourceName
        {
            get => _accpacFieldEditControl.DataSourceName;
            set => _accpacFieldEditControl.DataSourceName = value;
        }

        public string FieldName
        {
            get => _accpacFieldEditControl.FieldName;
            set => _accpacFieldEditControl.FieldName = value;
        }

        [Browsable(false)]
        public string CurrencyField
        {
            get => _accpacFieldEditControl.CurrencyField;
            set => _accpacFieldEditControl.CurrencyField = value;
        }

        [Browsable(false)]
        public string CurrencyCode
        {
            get => _accpacFieldEditControl.CurrencyCode;
            set => _accpacFieldEditControl.CurrencyCode = value;
        }

        [Browsable(false)]
        public string Mask
        {
            get => _accpacFieldEditControl.Mask;
            set => _accpacFieldEditControl.Mask = value;
        }

        [Browsable(false)]
        [DefaultValue(false)]
        public bool UseSysDefForNumber
        {
            get => _accpacFieldEditControl.UseSysDefForNumber;
            set => _accpacFieldEditControl.UseSysDefForNumber = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string NumberGroupingSymbol
        {
            get => _accpacFieldEditControl.NumberGroupingSymbol;
            set => _accpacFieldEditControl.NumberGroupingSymbol = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string NumberDecimalSymbol
        {
            get => _accpacFieldEditControl.NumberDecimalSymbol;
            set => _accpacFieldEditControl.NumberDecimalSymbol = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string CurrencySymbol
        {
            get => _accpacFieldEditControl.CurrencySymbol;
            set => _accpacFieldEditControl.CurrencySymbol = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int NumberDecimalsBefore
        {
            get => _accpacFieldEditControl.NumberDecimalsBefore;
            set => _accpacFieldEditControl.NumberDecimalsBefore = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int NumberDecimalsAfter
        {
            get => _accpacFieldEditControl.NumberDecimalsAfter;
            set => _accpacFieldEditControl.NumberDecimalsAfter = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int NumberDigitsInGroup
        {
            get => _accpacFieldEditControl.NumberDigitsInGroup;
            set => _accpacFieldEditControl.NumberDigitsInGroup = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public short NumberNegativeFormat
        {
            get => _accpacFieldEditControl.NumberNegativeFormat;
            set => _accpacFieldEditControl.NumberNegativeFormat = value;
        }

        [Browsable(false)]
        [DefaultValue(false)]
        public bool UseHomeCurrency
        {
            get => _accpacFieldEditControl.UseHomeCurrency;
            set => _accpacFieldEditControl.UseHomeCurrency = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public tagNumberDomainType NumberDomain
        {
            get => _accpacFieldEditControl.NumberDomain;
            set => _accpacFieldEditControl.NumberDomain = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public object ValueWithoutSaveToField
        {
            set => _accpacFieldEditControl.ValueWithoutSaveToField = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool get_EnableButton(tagButtonType btnType)
            => _accpacFieldEditControl.EnableButton[btnType];

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public void set_EnableButton(tagButtonType btnType, bool pVal)
            => _accpacFieldEditControl.EnableButton[btnType] = pVal;

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public tagFieldEditControlType DisplayControlType
            => _accpacFieldEditControl.DisplayControlType;

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int LastReturnCode
            => _accpacFieldEditControl.LastReturnCode;

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public short Version
        {
            get => _accpacFieldEditControl.Version;
            set => _accpacFieldEditControl.Version = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool CalendarTabAway
        {
            get => _accpacFieldEditControl.CalendarTabAway;
            set => _accpacFieldEditControl.CalendarTabAway = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool Dirty
            => _accpacFieldEditControl.Dirty;

        [Browsable(false)]
        [DefaultValue(true)]
        public bool AutoRefresh
        {
            get => _accpacFieldEditControl.AutoRefresh;
            set => _accpacFieldEditControl.AutoRefresh = value;
        }

        [Browsable(false)]
        [DefaultValue(true)]
        public bool AutoUpdate
        {
            get => _accpacFieldEditControl.AutoUpdate;
            set => _accpacFieldEditControl.AutoUpdate = value;
        }

        [Browsable(false)]
        [DefaultValue(true)]
        public bool VerifyOnSave
        {
            get => _accpacFieldEditControl.VerifyOnSave;
            set => _accpacFieldEditControl.VerifyOnSave = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool FireOnInvalidValue
        {
            get => _accpacFieldEditControl.FireOnInvalidValue;
            set => _accpacFieldEditControl.FireOnInvalidValue = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        uint IFieldEditControl.ForeColor
        {
            get => _accpacFieldEditControl.ForeColor;
            set => _accpacFieldEditControl.ForeColor = value;
        }

        public override Color ForeColor
        {
            get => SCAxHost.GetColorFromOleColor(((IFieldEditControl)this).ForeColor);
            set => ((IFieldEditControl)this).ForeColor = SCAxHost.GetOleColorFromColor(value);
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        uint IFieldEditControl.BackColor
        {
            get => _accpacFieldEditControl.BackColor;
            set => _accpacFieldEditControl.BackColor = value;
        }

        public override Color BackColor
        {
            get => SCAxHost.GetColorFromOleColor(((IFieldEditControl)this).BackColor);
            set => ((IFieldEditControl)this).BackColor = SCAxHost.GetOleColorFromColor(value);
        }

        //[Browsable(false)]
        [DefaultValue(1)]
        public int BackStyle
        {
            get => _accpacFieldEditControl.BackStyle;
            set => _accpacFieldEditControl.BackStyle = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        IFontDisp IFieldEditControl.Font
        {
            get => _accpacFieldEditControl.Font;
            set => _accpacFieldEditControl.Font = value;
        }

        public override System.Drawing.Font Font
        {
            get => SCAxHost.GetFontFromIFont(((IFieldEditControl)this).Font);
            set => ((IFieldEditControl)this).Font = (IFontDisp)SCAxHost.GetIFontFromFont(value);
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        AccpacDataSource IFieldEditControl.DataSource
        {
            get => _accpacFieldEditControl.DataSource;
            set 
            {
                _accpacFieldEditControl.DataSource = value;
                _accpacFieldEditControl.DataSource.OnActivate += DataSource_OnActivate;
            }
        }

        private void DataSource_OnActivate(bool bActive)
        {
            if (bActive
                && !string.IsNullOrEmpty(FieldName))
                _accpacFieldEditControl.AccpacField = DataSource.Fields[FieldName];
            else
                _accpacFieldEditControl.AccpacField = null;
        }

        private SCDataSource _dataSource;
        public SCDataSource DataSource
        {
            get => _dataSource;
            set
            {
                _dataSource = value;

                ((IFieldEditControl)this).DataSource = _dataSource?._accpacDataSource;
            }
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public object AccpacFieldGroup
        {
            get => _accpacFieldEditControl.AccpacFieldGroup;
            set => _accpacFieldEditControl.AccpacFieldGroup = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public ViewFinder ViewFinder
        {
            get => _accpacFieldEditControl.ViewFinder;
            set => _accpacFieldEditControl.ViewFinder = value;
        }


        //[Browsable(false)]
        //[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        //public AccpacFieldEditControl NeighborFieldEditControl
        //    => _accpacFieldEditControl.NeighborFieldEditControl;

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacFieldEditControl get_NeighborFieldEditControl(int idx)
            => _accpacFieldEditControl.NeighborFieldEditControl[idx];

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string DisplayName
        {
            get => _accpacFieldEditControl.DisplayName;
            set => _accpacFieldEditControl.DisplayName = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int HWND
            => _accpacFieldEditControl.HWND;

        [DefaultValue(false)]
        public bool NavigationButtons
        {
            get => _accpacFieldEditControl.NavigationButtons;
            set => _accpacFieldEditControl.NavigationButtons = value;
        }

        [DefaultValue(false)]
        public bool ViewFinderButton
        {
            get => _accpacFieldEditControl.ViewFinderButton;
            set => _accpacFieldEditControl.ViewFinderButton = value;
        }

        [DefaultValue(false)]
        public bool NewButton
        {
            get => _accpacFieldEditControl.NewButton;
            set => _accpacFieldEditControl.NewButton = value;
        }

        [DefaultValue(0)]
        public int CustomButtonCount
        {
            get => _accpacFieldEditControl.CustomButtonCount;
            set => _accpacFieldEditControl.CustomButtonCount = value;
        }

        [DefaultValue(true)]
        public bool FieldDescriptionAsRightLabel
        {
            get => _accpacFieldEditControl.FieldDescriptionAsRightLabel;
            set => _accpacFieldEditControl.FieldDescriptionAsRightLabel = value;
        }

        [DefaultValue(true)]
        public bool FieldDescriptionAsLeftLabel
        {
            get => _accpacFieldEditControl.FieldDescriptionAsLeftLabel;
            set => _accpacFieldEditControl.FieldDescriptionAsLeftLabel = value;
        }

        [DefaultValue(0)]
        public short LeftLabelLength
        {
            get => _accpacFieldEditControl.LeftLabelLength;
            set => _accpacFieldEditControl.LeftLabelLength = value;
        }

        [DefaultValue(0)]
        public short RightLabelLength
        {
            get => _accpacFieldEditControl.RightLabelLength;
            set => _accpacFieldEditControl.RightLabelLength = value;
        }

        [Browsable(false)]
        [DefaultValue("")]
        public string LeftLabelAppID
        {
            get => _accpacFieldEditControl.LeftLabelAppID;
            set => _accpacFieldEditControl.LeftLabelAppID = value;
        }

        [Browsable(false)]
        [DefaultValue(0)]
        public int LeftLabelResID
        {
            get => _accpacFieldEditControl.LeftLabelResID;
            set => _accpacFieldEditControl.LeftLabelResID = value;
        }

        [Browsable(false)]
        [DefaultValue("")]
        public string RightLabelAppID
        {
            get => _accpacFieldEditControl.RightLabelAppID;
            set => _accpacFieldEditControl.RightLabelAppID = value;
        }

        [Browsable(false)]
        [DefaultValue(0)]
        public int RightLabelResID
        {
            get => _accpacFieldEditControl.RightLabelResID;
            set => _accpacFieldEditControl.RightLabelResID = value;
        }

        [Browsable(false)]
        [DefaultValue("")]
        public string LeftLabel
        {
            get => _accpacFieldEditControl.LeftLabel;
            set => _accpacFieldEditControl.LeftLabel = value;
        }

        [Browsable(false)]
        [DefaultValue("")]
        public string RightLabel
        {
            get => _accpacFieldEditControl.RightLabel;
            set => _accpacFieldEditControl.RightLabel = value;
        }

        [Browsable(false)]
        [DefaultValue(tagFieldCaptionType.CAPTION_LEFT_LABEL)]
        public tagFieldCaptionType CaptionType
        {
            get => _accpacFieldEditControl.CaptionType;
            set => _accpacFieldEditControl.CaptionType = value;
        }

        [Browsable(false)]
        [DefaultValue("")]
        public string Caption
        {
            get => _accpacFieldEditControl.Caption;
            set => _accpacFieldEditControl.Caption = value;
        }

        [Browsable(false)]
        [DefaultValue("")]
        public string TextAppID
        {
            get => _accpacFieldEditControl.TextAppID;
            set => _accpacFieldEditControl.TextAppID = value;
        }

        [Browsable(false)]
        [DefaultValue(0)]
        public int TextResID
        {
            get => _accpacFieldEditControl.TextResID;
            set => _accpacFieldEditControl.TextResID = value;
        }

        [Browsable(false)]
        [DefaultValue(false)]
        public bool FieldDescriptionAsText
        {
            get => _accpacFieldEditControl.FieldDescriptionAsText;
            set => _accpacFieldEditControl.FieldDescriptionAsText = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool CreditCardExpireDate
        {
            get => _accpacFieldEditControl.CreditCardExpireDate;
            set => _accpacFieldEditControl.CreditCardExpireDate = value;
        }

        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool LoadModernizedIcon
        {
            get => _accpacFieldEditControl.LoadModernizedIcon;
            set => _accpacFieldEditControl.LoadModernizedIcon = value;
        }

        public event _IFieldEditControlEvents_OnKillFocusEventHandler OnKillFocus;
        public event _IFieldEditControlEvents_OnReturnKeyEventHandler OnReturnKey;
        public event _IFieldEditControlEvents_OnEscapeKeyEventHandler OnEscapeKey;
        public event _IFieldEditControlEvents_OnTabKeyEventHandler OnTabKey;
        public event _IFieldEditControlEvents_OnSetFocusEventHandler OnSetFocus;
        public event _IFieldEditControlEvents_OnInvalidValueEventHandler OnInvalidValue;
        public event _IFieldEditControlEvents_OnClickButtonEventHandler OnClickButton;
        public event _IFieldEditControlEvents_OnChangeEventHandler OnChange;
        public event _IFieldEditControlEvents_OnSizeingEventHandler OnSizeing;
        public event _IFieldEditControlEvents_OnStatusChangedEventHandler OnStatusChanged;
        public event _IFieldEditControlEvents_OnFunctionKeyEventHandler OnFunctionKey;
        public event _IFieldEditControlEvents_OnEndEditEventHandler OnEndEdit;
        public event _IFieldEditControlEvents_OnBeforeButtonClickEventHandler OnBeforeButtonClick;
        #endregion AccpacFieldEditControl

        #region _IFieldEditControlEvents
        void _IFieldEditControlEvents.OnKillFocus()
            => OnKillFocus?.Invoke();

        void _IFieldEditControlEvents.OnReturnKey()
            => OnReturnKey?.Invoke();

        void _IFieldEditControlEvents.OnEscapeKey()
            => OnEscapeKey?.Invoke();

        void _IFieldEditControlEvents.OnTabKey()
            => OnTabKey?.Invoke();

        void _IFieldEditControlEvents.OnSetFocus()
            => OnSetFocus?.Invoke();

        void _IFieldEditControlEvents.OnInvalidValue()
            => OnInvalidValue?.Invoke();

        void _IFieldEditControlEvents.OnClickButton(tagButtonType btnType, ref tagButtonEventStatus pStatus)
            => OnClickButton?.Invoke(btnType, ref pStatus);

        void _IFieldEditControlEvents.OnChange()
            => OnChange?.Invoke();

        void _IFieldEditControlEvents.OnSizeing()
            => OnSizeing?.Invoke();

        void _IFieldEditControlEvents.OnStatusChanged(tagStatusChangeReason reason)
            => OnStatusChanged?.Invoke(reason);

        void _IFieldEditControlEvents.OnFunctionKey(int Fkey)
            => OnFunctionKey?.Invoke(Fkey);

        void _IFieldEditControlEvents.OnEndEdit(object vInl, out object vOut, ref bool pbHandled)
        {
            vOut = vInl;
            OnEndEdit?.Invoke(vInl, out vOut, ref pbHandled);
        }

        void _IFieldEditControlEvents.OnBeforeButtonClick(ref bool pbForceClick)
            => OnBeforeButtonClick?.Invoke(ref pbForceClick);
        #endregion

        #region Label Mode / Color
        [DllImport("user32.dll")]
        static extern IntPtr GetTopWindow(IntPtr hWnd);
        [DllImport("user32.dll", SetLastError = true)]
        private static extern IntPtr GetWindow(IntPtr hWnd, uint uCmd);
        [DllImport("user32.dll")]
        static extern IntPtr GetWindowDC(IntPtr hWnd);
        [DllImport("user32.dll")]
        static extern bool ReleaseDC(IntPtr hWnd, IntPtr hDC);

        [DllImport("user32.dll", SetLastError = true, CharSet = CharSet.Ansi)]
        static extern int GetClassName(IntPtr hWnd, StringBuilder lpClassName, int nMaxCount);

        [DllImport("gdi32.dll")]
        static extern int SetBkMode(IntPtr hdc, int iBkMode);

        [DllImport("gdi32.dll")]
        static extern IntPtr CreateSolidBrush(uint crColor);

        [DllImport("gdi32.dll", EntryPoint = "DeleteObject")]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool DeleteObject([In] IntPtr hObject);

        [DllImport("user32", EntryPoint = "SetClassLong")]
        public static extern int SetClassLongA(IntPtr hwnd, int nIndex, IntPtr dwNewLong);

        const int GCLP_HBRBACKGROUND = -10;

        IntPtr hBrush = IntPtr.Zero;

        const int TRANSPARENT = 1;
        const int OPAQUE = 2;

        private string GetClassName(IntPtr hWnd)
        {
            int nRet;
            StringBuilder sb = new StringBuilder(256);
            nRet = GetClassName(hWnd, sb, sb.Capacity);

            if (nRet != 0)
                return sb.ToString();
            else
                return string.Empty;
        }

        private void SetLabelBackgroundMode(IntPtr hWnd, int bkMode)
        {
            if (hWnd == IntPtr.Zero)
                return;

            if (GetClassName(hWnd).StartsWith("Accpac"))
                SetLabelBackgroundMode(GetWindow(hWnd, 2), bkMode);
            else
            {
                hBrush = CreateSolidBrush(SCAxHost.GetOleColorFromColor(Color.White));
                SetClassLongA(hWnd, GCLP_HBRBACKGROUND, hBrush);
                SetLabelBackgroundMode(GetWindow(hWnd, 2), bkMode);
                //IntPtr hDC = GetWindowDC(hWnd);
                //if (hDC != IntPtr.Zero)
                //{
                //    System.Diagnostics.Debug.WriteLine("Doing it");

                //    SetBkMode(hWnd, bkMode);
                //    ReleaseDC(hWnd, hDC);
                //}
            }
        }

        private void SetBackgroundMode(int bkMode)
        {
            SetLabelBackgroundMode(GetTopWindow(new IntPtr(HWND)), bkMode);
        }

        private int _backMode = 2;
        [DefaultValue(2)]
        public int BackMode
        {
            get => _backMode;
            set
            {
                _backMode = value;
                //SetBackgroundMode(_backMode);
            }
        }
        #endregion Label Mode / Color
    }
}
