using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Design;
using Sage.CA.SBS.ERP.Sage300.SC.Data;
using Telerik.WinControls.UI;
using AccpacDataSrc;
using System.Runtime.InteropServices;
using System.Globalization;
using AccpacFldEdit;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages
{
    [ToolboxItem(true)]
    [ComplexBindingProperties("DataSource", "DataMember")]
    public partial class SCPageCashFlowSummary : UserControl
    {
        [Browsable(true)]
        [Category("Data")]
        [DefaultValue(null)]
        [RefreshProperties(RefreshProperties.Repaint)]
        [AttributeProvider(typeof(IListSource))]
        public object DataSource
        {
            get => grdCashFlowSummary.DataSource;
            set
            {
                string dataMember = grdCashFlowSummary.DataMember;
                grdCashFlowSummary.DataSource = value;
                //
                // Fix radGridView losing datamember
                //
                grdCashFlowSummary.DataMember = dataMember;
            }
        }

        [Browsable(true)]
        [Category("Data")]
        [DefaultValue("")]
        [Editor("System.Windows.Forms.Design.DataMemberListEditor, System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", typeof(UITypeEditor))]
        public string DataMember
        {
            get => grdCashFlowSummary.DataMember;
            set => grdCashFlowSummary.DataMember = value;
        }

        private string _formatString = "n";
        public string FormatString
        {
            get => _formatString;
            set
            {
                _formatString = value;

                string gridFormatString = "{0:" + _formatString + ";\"\"}";

                grdCashFlowSummary.Columns["AmountPeriod0"].FormatString = gridFormatString;
                grdCashFlowSummary.Columns["AmountPeriod1"].FormatString = gridFormatString;
                grdCashFlowSummary.Columns["AmountPeriod2"].FormatString = gridFormatString;
                grdCashFlowSummary.Columns["AmountPeriod3"].FormatString = gridFormatString;
                grdCashFlowSummary.Columns["AmountPeriod4"].FormatString = gridFormatString;
                grdCashFlowSummary.Columns["AmountPeriod5"].FormatString = gridFormatString;
                grdCashFlowSummary.Columns["AmountPeriod6"].FormatString = gridFormatString;
                grdCashFlowSummary.Columns["AmountTotal"].FormatString = gridFormatString;
            }
        }

        private AccpacDataSource _dsSCTRAN;
        private AccpacCustomField _cfInflow;
        private AccpacCustomField _cfOutflow;

        private AccpacFieldFormater _fldFormater;

        private string _homeCurrency;

        public SCPageCashFlowSummary()
        {
            InitializeComponent();

            _dsSCTRAN = new AccpacDataSource();
            _dsSCTRAN.OnRecordChanging += _dsSCTRAN_OnRecordChanging;
            _dsSCTRAN.OnRecordChanged += _dsSCTRAN_OnRecordChanged;
        }

        private void _dsSCTRAN_OnRecordChanging(AccpacCOMAPI.tagEventReason eReason, ref AccpacCOMAPI.tagEventStatus pStatus, AccpacDSField pField, AccpacDSFields pMultipleFields)
        {
            if (eReason == AccpacCOMAPI.tagEventReason.RSN_FIELDCHANGE
                && pField.Name == "DOCDATE")
                _dsSCTRAN.Fields["DATEDUE"].PutWithoutVerification(pField.UncommittedValue);
        }

        private void _dsSCTRAN_OnRecordChanged(AccpacCOMAPI.tagEventReason eReason, AccpacDSField pField, AccpacDSFields pMultipleFields)
        {
            Transaction transaction;
            switch (eReason)
            {
                case AccpacCOMAPI.tagEventReason.RSN_ADDNEW:
                    ApplicationData.Current.Transactions.Add(new Transaction
                    {
                        RecordType = RecordType.Posted,
                        Source = "SC",
                        DocumentNumber = (string)_dsSCTRAN.Fields.FieldByName["DOCNUM"].get_Value(),
                        PaymentNumber = (decimal)_dsSCTRAN.Fields.FieldByName["PAYMENTNBR"].get_Value(),
                        DocumentDate = (DateTime)_dsSCTRAN.Fields.FieldByName["DOCDATE"].get_Value(),
                        DueDate = (DateTime)_dsSCTRAN.Fields.FieldByName["DATEDUE"].get_Value(),
                        Description = (string)_dsSCTRAN.Fields.FieldByName["DOCDESC"].get_Value(),
                        AmountDue = (decimal)_dsSCTRAN.Fields.FieldByName["AMTDUEHC"].get_Value(),
                        AmountPaid = (decimal)_dsSCTRAN.Fields.FieldByName["AMTPAIDHC"].get_Value(),
                    });

                    ApplicationData.Current.PopuplateData();

                    break;

                case AccpacCOMAPI.tagEventReason.RSN_DELETE:
                    transaction = ApplicationData.Current.Transactions.Where(t =>
                    t.Source == "SC" &&
                    t.DocumentNumber == (string)_dsSCTRAN.Fields["DOCNUM"].get_Value())
                        .FirstOrDefault();
                    if (transaction != null)
                        ApplicationData.Current.Transactions.Remove(transaction);

                    ApplicationData.Current.PopuplateData();

                    break;

                case AccpacCOMAPI.tagEventReason.RSN_UPDATE:
                    transaction = ApplicationData.Current.Transactions.Where(t =>
                    t.Source == "SC" &&
                    t.DocumentNumber == (string)_dsSCTRAN.Fields["DOCNUM"].get_Value())
                        .FirstOrDefault();
                    if (transaction != null)
                    {
                        transaction.DocumentDate = (DateTime)_dsSCTRAN.Fields["DOCDATE"].get_Value();
                        transaction.DueDate = (DateTime)_dsSCTRAN.Fields["DATEDUE"].get_Value();
                        transaction.AmountDue = (decimal)_dsSCTRAN.Fields["AMTDUEHC"].get_Value();
                        transaction.AmountPaid = (decimal)_dsSCTRAN.Fields["AMTPAIDHC"].get_Value();
                    }

                    ApplicationData.Current.PopuplateData();

                    break;
            }
        }

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }

            DeactivateDataSources();
            if (_dsSCTRAN != null)
            {
                Marshal.ReleaseComObject(_dsSCTRAN);
                _dsSCTRAN = null;
            }

            base.Dispose(disposing);
        }

        private void SCPageCashFlowSummary_Load(object sender, EventArgs e)
        {
            _homeCurrency = Sage300Application.Current.DbLinkCmpRO.GetCompany().HomeCurrency;

            //
            //// Setup Column Names
            grdCashFlowSummary.Columns["AmountPeriod1"].HeaderText = ApplicationData.Current.Period1Name;
            grdCashFlowSummary.Columns["AmountPeriod2"].HeaderText = ApplicationData.Current.Period2Name;
            grdCashFlowSummary.Columns["AmountPeriod3"].HeaderText = ApplicationData.Current.Period3Name;
            grdCashFlowSummary.Columns["AmountPeriod4"].HeaderText = ApplicationData.Current.Period4Name;
            grdCashFlowSummary.Columns["AmountPeriod5"].HeaderText = ApplicationData.Current.Period5Name;
            grdCashFlowSummary.Columns["AmountPeriod6"].HeaderText = ApplicationData.Current.Period6Name;

            //
            //// Conditional Formating
            ConditionalFormattingObject cfoImportantRow = new ConditionalFormattingObject(
                "ImportantRow",
                ConditionTypes.Equal,
                "True",
                null,
                true);
            cfoImportantRow.RowFont = new Font(grdCashFlowSummary.Font, FontStyle.Bold);
            grdCashFlowSummary.Columns["Important"].ConditionalFormattingObjectList.Add(cfoImportantRow);

            //
            ////
            ActivateDataSources();
            InitializeControls();
        }

        #region Accpac Helpers
        private void ActivateDataSources()
        {
            if (!_dsSCTRAN.Active)
            {
                _dsSCTRAN.ViewID = "SC0110";
                _dsSCTRAN.DBLink = Sage300Application.Current.DbLinkCmpRW;
                _dsSCTRAN.Active = true;
                _dsSCTRAN.FilterSelect("SOURCE=\"SC\"", true, 0, AccpacCOMAPI.tagFilterOriginEnum.FILTERSELECT_FROMSTART);
            }
        }

        private void DeactivateDataSources()
        {
            _dsSCTRAN.Active = false;
        }

        private void InitializeControls()
        {

            //
            //// InFlow
            _cfInflow = new AccpacCustomField();
            _cfInflow.InitFromField(_dsSCTRAN.Fields["AMTDUEHC"]);

            //
            //// OutFlow
            _cfOutflow = new AccpacCustomField();
            _cfOutflow.InitFromField(_dsSCTRAN.Fields["AMTDUEHC"]);

            //
            //// Formatter
            _fldFormater = new AccpacFieldFormater();
            _fldFormater.Add(_cfInflow);
            _fldFormater.Add(_cfOutflow);
            _fldFormater.CurrencyCode[0] = _homeCurrency;
            _fldFormater.CurrencyCode[1] = _homeCurrency;

            //
            ////
            vlSCTRAN.AddColumn(0, "DOCNUM", _dsSCTRAN.View.Fields.FieldByName["DOCNUM"].Index, "Document Number", AccpacFldList.tagColumnAligment.ALIGMENT_LEFT, 175, false, false, false);
            //vlSCTRAN.AddColumn(1, "DOCDATE", _dsSCTRAN.View.Fields.FieldByName["DOCDATE"].Index, "Effective Date", AccpacFldList.tagColumnAligment.ALIGMENT_LEFT, 100, true, false, false);
            vlSCTRAN.AddColumn(1, "DATEDUE", _dsSCTRAN.View.Fields.FieldByName["DATEDUE"].Index, "Effective Date", AccpacFldList.tagColumnAligment.ALIGMENT_LEFT, 100, true, false, false);
            vlSCTRAN.AddColumn(2, "DOCDESC", _dsSCTRAN.View.Fields.FieldByName["DOCDESC"].Index, "Description", AccpacFldList.tagColumnAligment.ALIGMENT_LEFT, 250, true, false, false);
            vlSCTRAN.AddColumn(3, "AMTIN", _dsSCTRAN.View.Fields.FieldByName["AMTDUEHC"].Index, "Inflow", AccpacFldList.tagColumnAligment.ALIGMENT_RIGHT, 100, true, false, true);
            vlSCTRAN.AddColumn(4, "AMTOUT", _dsSCTRAN.View.Fields.FieldByName["AMTPAIDHC"].Index, "Outflow", AccpacFldList.tagColumnAligment.ALIGMENT_RIGHT, 100, true, false, true);
            vlSCTRAN.DataSource = _dsSCTRAN;
            vlSCTRAN.Refresh();
            vlSCTRAN.RefreshData();

            vlSCTRAN.ReadOnly = !ApplicationData.Current.HasForecastEntryRight;
        }
        #endregion Accpac Helpers

        #region Event Handlers
        private void BtnPrint_Summary_Click(object sender, EventArgs e)
        {
            Dictionary<string, string> parameters = new Dictionary<string, string>();
            parameters.Add("FSCYEAR", ApplicationData.Current.CurrentYear);
            parameters.Add("FSCPERD", ApplicationData.Current.CurrentPeriod.ToString());

            Sage300Application.Current.PrintReport("SCSUM03", Handle.ToInt32(), parameters);
        }

        private void BtnPrint_CashAndBank_Click(object sender, EventArgs e)
        {
            Dictionary<string, string> parameters = new Dictionary<string, string>();
            parameters.Add("FSCYEAR", ApplicationData.Current.CurrentYear);
            parameters.Add("FSCPERD", ApplicationData.Current.CurrentPeriod.ToString());

            Sage300Application.Current.PrintReport("SCCABK", Handle.ToInt32(), parameters);
        }

        private void BtnPrint_CashFlowEntries_Click(object sender, EventArgs e)
        {
            Sage300Application.Current.PrintReport("SCINOUT", Handle.ToInt32(), null);
        }
        #endregion Event Handlers
        
        private void VlSCTRAN_OnSetCustomItemData(object sender, AxAccpacFldList._IAccpacViewListEvents_OnSetCustomItemDataEvent e)
        {
            decimal amount = (decimal)_dsSCTRAN.Fields["AMTDUEHC"].get_Value();
            switch (e.bstrFieldName)
            {
                case "AMTIN": //Inflow
                    if (amount > 0)
                        _cfInflow.set_Value(amount);
                    else
                        _cfInflow.set_Value(0);

                    e.bstrData = _fldFormater.DisplayValue[0];

                    break;

                case "AMTOUT": //Outflow
                    if (amount < 0)
                        _cfOutflow.set_Value(-amount);
                    else
                        _cfOutflow.set_Value(0);

                    e.bstrData = _fldFormater.DisplayValue[1];

                    break;
            }
        }

        private void VlSCTRAN_OnStartEditCustomData(object sender, AxAccpacFldList._IAccpacViewListEvents_OnStartEditCustomDataEvent e)
        {
            decimal amount = (decimal)_dsSCTRAN.Fields["AMTDUEHC"].get_Value();
            switch (e.bstrFieldName)
            {
                case "AMTIN":
                    if (amount > 0)
                        _cfInflow.set_Value(amount);
                    else
                        _cfInflow.set_Value(0);

                    (e.pFEditCtrl as AccpacFieldEditControl).AccpacField = _cfInflow;
                    (e.pFEditCtrl as AccpacFieldEditControl).NumberDomain = tagNumberDomainType.NON_NEGATIVE;
                    (e.pFEditCtrl as AccpacFieldEditControl).CurrencyCode = _homeCurrency;

                    break;

                case "AMTOUT":
                    if (amount < 0)
                        _cfOutflow.set_Value(-amount);
                    else
                        _cfOutflow.set_Value(0);

                    (e.pFEditCtrl as AccpacFieldEditControl).AccpacField = _cfOutflow;
                    (e.pFEditCtrl as AccpacFieldEditControl).NumberDomain = tagNumberDomainType.NON_NEGATIVE;
                    (e.pFEditCtrl as AccpacFieldEditControl).CurrencyCode = _homeCurrency;

                    break;
            }
        }

        private void VlSCTRAN_OnEndEdit(object sender, AxAccpacFldList._IAccpacViewListEvents_OnEndEditEvent e)
        {
            decimal amount = 0;
            if (e.pFEditCtrl != null && (e.pFEditCtrl as AccpacFieldEditControl).Dirty)
            {
                switch (e.bstrFieldName)
                {
                    case "AMTIN":
                        amount = (decimal)e.vInl;
                        _dsSCTRAN.Fields["AMTDUEHC"].set_Value(amount);
                        e.pbHandled = true;
                        break;

                    case "AMTOUT":
                        amount = -(decimal)e.vInl;
                        _dsSCTRAN.Fields["AMTDUEHC"].set_Value(amount);
                        e.pbHandled = true;
                        break;
                }
            }
        }

        private void VlSCTRAN_SizeChanged(object sender, EventArgs e)
        {
            vlSCTRAN.Refresh();
        }
    }
}
