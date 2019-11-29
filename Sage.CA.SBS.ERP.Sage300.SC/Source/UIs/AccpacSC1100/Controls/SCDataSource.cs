using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using AccpacCOMAPI;
using AccpacDataSrc;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    public class SCDataSource
        : Component,
        AccpacDataSource,
        _IAccpacDataSourceEvents
    {
        private SCAxHost _axAccpacDataSource;
        internal AccpacDataSource _accpacDataSource;
        private bool _designMode = false;
        private UserControl _ucDataSourceWrapper;

        #region Constructors
        public SCDataSource()
        {
            _designMode = (LicenseManager.UsageMode == LicenseUsageMode.Designtime);
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            ComponentResourceManager resources = new ComponentResourceManager(typeof(SCDataSource));
            _axAccpacDataSource = new SCAxHost("A4wDataSource.AccpacDataSource");
            ((ISupportInitialize)_axAccpacDataSource).BeginInit();
            _axAccpacDataSource.OnAttachInterfaces += _axAccpacDataSource_OnAttachInterfaces;
            _ucDataSourceWrapper = new UserControl();
            _ucDataSourceWrapper.Controls.Add(_axAccpacDataSource);
            ((ISupportInitialize)_axAccpacDataSource).EndInit();
        }

        private void _axAccpacDataSource_OnAttachInterfaces(object ocx)
        {
            _accpacDataSource = (AccpacDataSource)ocx;

            //_accpacDataSource.OnActivate += ((_IAccpacDataSourceEvents)this).OnActivate;
            //_accpacDataSource.OnActivate += _OnActivate;
            //_accpacDataSource.SetFireEvents(true);
            //_accpacDataSource.OnActivate += _accpacDataSource_OnActivate;

            ForceDesignMode(_designMode);
        }

        private void _accpacDataSource_OnActivate(bool bActive)
        {
            throw new NotImplementedException();
        }

        private SCDataSource(AccpacDataSource accpacDataSource, bool Activate)
        {
            _accpacDataSource = (AccpacDataSource)accpacDataSource.Clone();
            _accpacDataSource.Active = Activate;
        }
        #endregion Constructors

        #region IDisposable Support
        private bool _disposed = false;

        protected override void Dispose(bool disposing)
        {
            if (_disposed)
                return;

            if (disposing)
            {
                _ucDataSourceWrapper.Dispose();
            }

            _disposed = true;

            if (_accpacDataSource != null)
            {
                Marshal.ReleaseComObject(_accpacDataSource);
                _accpacDataSource = null;
            }

            base.Dispose(disposing);
        }
        #endregion IDisposable Support

        public object get_ComposeViewIDsArray()
            => _accpacDataSource.get_ComposeViewIDsArray();

        public void set_ComposeViewIDsArray(ref object pVal)
            => _accpacDataSource.set_ComposeViewIDsArray(ref pVal);

        public void SetFireEvents(bool FireEvents)
            => _accpacDataSource.SetFireEvents(FireEvents);

        public AccpacView GetComposedView(string bstrName)
            => _accpacDataSource.GetComposedView(bstrName);

        public int RegisterLookup(
            ref object SourceFieldIDOrArrayOfIDs,
            string TargetViewID, int TargetViewOrder,
            tagDBLinkTypeEnum TargetDBLinkType,
            ref object TargetFieldIDOrArrayOfIDs,
            int TargetLookupFieldID)
            => _accpacDataSource.RegisterLookup(
                ref SourceFieldIDOrArrayOfIDs,
                TargetViewID,
                TargetViewOrder,
                TargetDBLinkType,
                ref TargetFieldIDOrArrayOfIDs,
                TargetLookupFieldID);

        public object GetLookupValue(int Cookie)
            => _accpacDataSource.GetLookupValue(Cookie);

        public object Clone()
            => new SCDataSource(_accpacDataSource, false);

        public void ForceDesignMode(bool bDesignMode)
            => _accpacDataSource.ForceDesignMode(bDesignMode);

        public bool ReloadPropertyFilter()
            => _accpacDataSource.ReloadPropertyFilter();

        public void Update()
            => _accpacDataSource.Update();

        public void Cancel()
            => _accpacDataSource.Cancel();

        public void Init()
            => _accpacDataSource.Init();

        public void Insert()
            => _accpacDataSource.Insert();

        public void Verify()
            => _accpacDataSource.Verify();

        public void Delete()
            => _accpacDataSource.Delete();

        public void Post()
            => _accpacDataSource.Post();

        public void Close()
            => _accpacDataSource.Close();

        public void Process()
            => _accpacDataSource.Process();

        public void UnLock()
            => _accpacDataSource.UnLock();

        public bool Fetch()
            => _accpacDataSource.Fetch();

        public bool FetchLock()
            => _accpacDataSource.FetchLock();

        public bool Read()
            => _accpacDataSource.Read();

        public bool ReadLock()
            => _accpacDataSource.ReadLock();

        public void Browse(string Filter, bool Ascending)
            => _accpacDataSource.Browse(Filter, Ascending);

        public bool GoTop()
            => _accpacDataSource.GoTop();

        public bool GoBottom()
            => _accpacDataSource.GoBottom();

        public bool GoToBookMark(ref object pBookMark)
            => _accpacDataSource.GoToBookMark(ref pBookMark);

        public bool GoNext()
            => _accpacDataSource.GoNext();

        public bool GoPrev()
            => _accpacDataSource.GoPrev();

        public void Compose(ref object ViewOrArrayOfViews)
            => _accpacDataSource.Compose(ref ViewOrArrayOfViews);

        public object BlkGet(ref object FieldIDs)
            => _accpacDataSource.BlkGet(ref FieldIDs);

        public void BlkPut(ref object FieldIDs, ref object pValues, bool Verify)
            => _accpacDataSource.BlkPut(ref FieldIDs, ref pValues, Verify);

        public object BlkGetFields(ref object FieldIDs)
            => _accpacDataSource.BlkGetFields(ref FieldIDs);

        public void UnregisterLookup(int Cookie)
            => _accpacDataSource.UnregisterLookup(Cookie);

        public void InitPrimaryKeyFields(ref object Bookmark)
            => _accpacDataSource.InitPrimaryKeyFields(ref Bookmark);

        public bool GoToRecordNumber(int RecordNumber)
            => _accpacDataSource.GoToRecordNumber(RecordNumber);

        public void ResetRecordNumbers()
            => _accpacDataSource.ResetRecordNumbers();

        public void SetFireEventsWithoutNotification(bool FireEvents)
            => _accpacDataSource.SetFireEventsWithoutNotification(FireEvents);

        public void SetRequiredFields(ref Array FieldIdentifiers)
            => _accpacDataSource.SetRequiredFields(ref FieldIdentifiers);

        public object CloneEx(bool Activate)
            => new SCDataSource(_accpacDataSource, Activate);

        public void RecordClear()
            => _accpacDataSource.RecordClear();

        public void RecordGenerate(bool Insert)
            => _accpacDataSource.RecordGenerate(Insert);

        public void TableEmpty()
            => _accpacDataSource.TableEmpty();

        public void RevisionCancel(int level)
            => _accpacDataSource.RevisionCancel(level);

        public void RevisionPost(int level)
            => _accpacDataSource.RevisionPost(level);

        public bool RevisionExists(int level)
            => _accpacDataSource.RevisionExists(level);

        public bool RevisionUnposted(int level)
            => _accpacDataSource.RevisionUnposted(level);

        public void FilterDelete(string Filter, tagFilterStrictnessEnum strictness)
            => _accpacDataSource.FilterDelete(Filter, strictness);

        public void FilterSelect(string Filter, bool Ascending, int Order, tagFilterOriginEnum origin)
            => _accpacDataSource.FilterSelect(Filter, Ascending, Order, origin);

        public bool FilterFetch(bool @lock)
            => _accpacDataSource.FilterFetch(@lock);

        public int RegisterLookupInstance(
            ref object SourceFieldIDOrArrayOfIDs,
            string TargetViewID,
            int TargetViewOrder,
            tagDBLinkTypeEnum TargetDBLinkType,
            ref object TargetFieldIDOrArrayOfIDs,
            int TargetLookupFieldID,
            bool Readonly = false,
            bool Unvalidated = false,
            bool Unrevisioned = false,
            bool Nonheritable = false,
            int Prefetch = 0,
            bool RawPut = false,
            bool Noncascading = false,
            object extra = null)
            => _accpacDataSource.RegisterLookupInstance(
                ref SourceFieldIDOrArrayOfIDs,
                TargetViewID,
                TargetViewOrder,
                TargetDBLinkType,
                ref TargetFieldIDOrArrayOfIDs,
                TargetLookupFieldID,
                Readonly,
                Unvalidated,
                Unrevisioned,
                Nonheritable,
                Prefetch,
                RawPut,
                Noncascading,
                extra);

        public void SetOrder(int Order, bool Unique)
            => _accpacDataSource.SetOrder(Order, Unique);

        public void RecordCreate(tagViewRecordCreateEnum flags)
            => _accpacDataSource.RecordCreate(flags);

        public int FilterCount(string Filter, int flags)
            => _accpacDataSource.FilterCount(Filter, flags);

        public string ViewID
        {
            get => _accpacDataSource.ViewID;
            set => _accpacDataSource.ViewID = value;
        }

        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        [DefaultValue(false)]
        public bool Active
        {
            get => _accpacDataSource.Active;
            set => _accpacDataSource.Active = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string ParentName
        {
            get => _accpacDataSource.ParentName;
            set => _accpacDataSource.ParentName = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacDataSource ParentDataSource { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        public string DisplayName
            => _accpacDataSource.DisplayName;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacView View
            => _accpacDataSource.View;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacSession Session
        {
            get => _accpacDataSource.Session;
            set => _accpacDataSource.Session = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacDBLink DBLinkCompany
        {
            get => _accpacDataSource.DBLinkCompany;
            set => _accpacDataSource.DBLinkCompany = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacDBLink DBLinkSystem
        {
            get => _accpacDataSource.DBLinkSystem;
            set => _accpacDataSource.DBLinkSystem = value;
        }

        [DefaultValue("ADMIN")]
        public string DesignUID
        {
            get => _accpacDataSource.DesignUID;
            set => _accpacDataSource.DesignUID = value;
        }

        [DefaultValue("ADMIN")]
        public string DesignPWD
        {
            get => _accpacDataSource.DesignPWD;
            set => _accpacDataSource.DesignPWD = value;
        }

        [DefaultValue("SAMLTD")]
        public string DesignOrgID
        {
            get => _accpacDataSource.DesignOrgID;
            set => _accpacDataSource.DesignOrgID = value;
        }

        [DefaultValue(tagDBLinkTypeEnum.DBLINK_COMPANY)]
        public tagDBLinkTypeEnum DBLinkType
        {
            get => _accpacDataSource.DBLinkType;
            set => _accpacDataSource.DBLinkType = value;
        }

        [DefaultValue(tagDBLinkFlagsEnum.DBLINK_FLG_READWRITE)]
        public tagDBLinkFlagsEnum DBLinkFlag
        {
            get => _accpacDataSource.DBLinkFlag;
            set => _accpacDataSource.DBLinkFlag = value;
        }
        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string ComposeViewIDs
        {
            get => _accpacDataSource.ComposeViewIDs;
            set => _accpacDataSource.ComposeViewIDs = value;
        }

        public string BrowseFilter
            => _accpacDataSource.BrowseFilter;

        public bool BrowseAscending
            => _accpacDataSource.BrowseAscending;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string ProgramName
        {
            get => _accpacDataSource.ProgramName;
            set => _accpacDataSource.ProgramName = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string PropertyFilter
        {
            get => _accpacDataSource.PropertyFilter;
            set => _accpacDataSource.PropertyFilter = value;
        }

        [DefaultValue(true)]
        public bool FireOnRecordChanging
        {
            get => _accpacDataSource.FireOnRecordChanging;
            set => _accpacDataSource.FireOnRecordChanging = value;
        }

        [DefaultValue(true)]
        public bool FireOnRecordChanged
        {
            get => _accpacDataSource.FireOnRecordChanged;
            set => _accpacDataSource.FireOnRecordChanged = value;
        }

        [DefaultValue(true)]
        public bool FireOnKeyChanged
        {
            get => _accpacDataSource.FireOnKeyChanged;
            set => _accpacDataSource.FireOnKeyChanged = value;
        }

        [DefaultValue(true)]
        public bool FireOnKeyChanging
        {
            get => _accpacDataSource.FireOnKeyChanging;
            set => _accpacDataSource.FireOnKeyChanging = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacDSFields Fields
            => _accpacDataSource.Fields;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool Dirty
            => _accpacDataSource.Dirty;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool Exists
            => _accpacDataSource.Exists;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int Order
        {
            get => _accpacDataSource.Order;
            set => _accpacDataSource.Order = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public tagRotoViewTypeEnum Type
            => _accpacDataSource.Type;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public tagViewSecurityEnum Security
            => _accpacDataSource.Security;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacDSKeys Keys
            => _accpacDataSource.Keys;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public object RecordBookMark
            => _accpacDataSource.RecordBookMark;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string Description
            => _accpacDataSource.Description;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool UnpostedRevisions
            => _accpacDataSource.UnpostedRevisions;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public tagSystemAccessEnum SystemAccess
        {
            get => _accpacDataSource.SystemAccess;
            set => _accpacDataSource.SystemAccess = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public tagReferentialIntegrityEnum ReferentialIntegrity
        {
            get => _accpacDataSource.ReferentialIntegrity;
            set => _accpacDataSource.ReferentialIntegrity = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacViewCompositeNames CompositeNames
            => _accpacDataSource.CompositeNames;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public AccpacDBLink DBLink
        {
            get => _accpacDataSource.DBLink;
            set => _accpacDataSource.DBLink = value;    
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public tagViewReturnCode LastReturnCode
            => _accpacDataSource.LastReturnCode;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool AutoCompose
        {
            get => _accpacDataSource.AutoCompose;
            set => _accpacDataSource.AutoCompose = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool UseProcessServer
            => _accpacDataSource.UseProcessServer;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool UseRecordNumbering
        {
            get => _accpacDataSource.UseRecordNumbering;
            set => _accpacDataSource.UseRecordNumbering = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int RecordNumber
            => _accpacDataSource.RecordNumber;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public tagViewSecurityEnum InstanceSecurity
            => _accpacDataSource.InstanceSecurity;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string TemplateVersion
            => _accpacDataSource.TemplateVersion;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public DateTime TemplateDate
            => _accpacDataSource.TemplateDate;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool InstanceReadonly
        {
            get => _accpacDataSource.InstanceReadonly;
            set => _accpacDataSource.InstanceReadonly = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool InstanceUnrevisioned
        {
            get => _accpacDataSource.InstanceUnrevisioned;
            set => _accpacDataSource.InstanceUnrevisioned = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool InstanceUnvalidated
        {
            get => _accpacDataSource.InstanceUnvalidated;
            set => _accpacDataSource.InstanceUnvalidated = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool InstanceRawPut
        {
            get => _accpacDataSource.InstanceRawPut;
            set => _accpacDataSource.InstanceRawPut = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool InstanceNoncascading
        {
            get => _accpacDataSource.InstanceNoncascading;
            set => _accpacDataSource.InstanceNoncascading = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int InstancePrefetch
        {
            get => _accpacDataSource.InstancePrefetch;
            set => _accpacDataSource.InstancePrefetch = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool InstanceNonheritable
        {
            get => _accpacDataSource.InstanceNonheritable;
            set => _accpacDataSource.InstanceNonheritable = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool UseOpenViewInstance
        {
            get => _accpacDataSource.UseOpenViewInstance;
            set => _accpacDataSource.UseOpenViewInstance = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool InstanceNotify
        {
            get => _accpacDataSource.InstanceNotify;
            set => _accpacDataSource.InstanceNotify = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public object InstanceExtra
        {
            get => _accpacDataSource.InstanceExtra;
            set => _accpacDataSource.InstanceExtra = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool UniqueIndex
        {
            get => _accpacDataSource.UniqueIndex;
            set => _accpacDataSource.UniqueIndex = value;
        }

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public tagViewInstanceProtocolEnum InstanceProtocol
            => _accpacDataSource.InstanceProtocol;

        [Browsable(false)]
        [EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool CheckDuplicateKeys
        {
            get => _accpacDataSource.CheckDuplicateKeys;
            set => _accpacDataSource.CheckDuplicateKeys = value;
        }

        public event _IAccpacDataSourceEvents_OnRecordChangedEventHandler OnRecordChanged;
        public event _IAccpacDataSourceEvents_OnKeyChangedEventHandler OnKeyChanged;
        public event _IAccpacDataSourceEvents_OnRecordChangingEventHandler OnRecordChanging;
        public event _IAccpacDataSourceEvents_OnActivateEventHandler OnActivate;
        public event _IAccpacDataSourceEvents_OnKeyChangingEventHandler OnKeyChanging;
        public event _IAccpacDataSourceEvents_OnRecordChangedPreEventHandler OnRecordChangedPre;

        #region _IAccpacDataSourceEvents
        void _IAccpacDataSourceEvents.OnRecordChanged(tagEventReason eReason, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnRecordChanged?.Invoke(eReason, pField, pMultipleFields);

        void _IAccpacDataSourceEvents.OnKeyChanged(tagEventReason eReason, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnKeyChanged?.Invoke(eReason, pField, pMultipleFields);

        void _IAccpacDataSourceEvents.OnRecordChanging(tagEventReason eReason, ref tagEventStatus pStatus, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnRecordChanging?.Invoke(eReason, ref pStatus, pField, pMultipleFields);

        void _IAccpacDataSourceEvents.OnActivate(bool bActive)
            => OnActivate?.Invoke(bActive);

        void _IAccpacDataSourceEvents.OnKeyChanging(tagEventReason eReason, ref tagEventStatus pStatus, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnKeyChanging?.Invoke(eReason, ref pStatus, pField, pMultipleFields);

        void _IAccpacDataSourceEvents.OnRecordChangedPre(tagEventReason eReason, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnRecordChangedPre?.Invoke(eReason, pField, pMultipleFields);

        void _OnRecordChanged(tagEventReason eReason, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnRecordChanged?.Invoke(eReason, pField, pMultipleFields);

        void _OnKeyChanged(tagEventReason eReason, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnKeyChanged?.Invoke(eReason, pField, pMultipleFields);

        void _OnRecordChanging(tagEventReason eReason, ref tagEventStatus pStatus, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnRecordChanging?.Invoke(eReason, ref pStatus, pField, pMultipleFields);

        void _OnActivate(bool bActive)
            => OnActivate?.Invoke(bActive);

        void _OnKeyChanging(tagEventReason eReason, ref tagEventStatus pStatus, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnKeyChanging?.Invoke(eReason, ref pStatus, pField, pMultipleFields);

        void _OnRecordChangedPre(tagEventReason eReason, AccpacDSField pField, AccpacDSFields pMultipleFields)
            => OnRecordChangedPre?.Invoke(eReason, pField, pMultipleFields);
        #endregion
    }
}
