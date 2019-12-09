using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using Sage.CA.SBS.ERP.Sage300.SC.Data;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages
{
    public partial class SCPageLoanNative : UserControl
    {
        private AccpacDataSrc.AccpacDataSource _dataSource;

        public SCPageLoanNative()
        {
            InitializeComponent();

            _dataSource = new AccpacDataSrc.AccpacDataSource();
            _dataSource.OnKeyChanging += _dataSource_OnKeyChanging;
            _dataSource.OnKeyChanged += _dataSource_OnKeyChanged;
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

            if (_dataSource != null)
            {
                DeactivateDataSources();
                _dataSource.Active = false;
                Marshal.ReleaseComObject(_dataSource);
                _dataSource = null;
            }

            base.Dispose(disposing);
        }


        private void _dataSource_OnKeyChanging(AccpacCOMAPI.tagEventReason eReason, ref AccpacCOMAPI.tagEventStatus pStatus, AccpacDataSrc.AccpacDSField pField, AccpacDataSrc.AccpacDSFields pMultipleFields)
        {
            if (_dataSource.Dirty)
            {
                switch (MessageBox.Show("Do you want to save changes to Loan Request?", "Confirmation", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Information))
                {
                    case DialogResult.Yes:
                        if (!SaveChanges(false))
                            pStatus = AccpacCOMAPI.tagEventStatus.STATUS_CANCEL;
                        break;

                    case DialogResult.Cancel:
                        pStatus = AccpacCOMAPI.tagEventStatus.STATUS_CANCEL;
                        break;

                    default:
                        break;
                }
            }
        }

        private void _dataSource_OnKeyChanged(AccpacCOMAPI.tagEventReason eReason, AccpacDataSrc.AccpacDSField pField, AccpacDataSrc.AccpacDSFields pMultipleFields)
        {
            SetControlsState();
        }

        private void SCPageLoanNative_Load(object sender, EventArgs e)
        {
            ActivateDataSources();
            InitializeControls();
        }

        private void ActivateDataSources()
        {
            _dataSource.ViewID = "SC0200";
            if (!DesignMode)
            {
                _dataSource.DBLinkCompany = Sage300Application.Current.DbLinkCmpRW;
                _dataSource.Active = true;
                _dataSource.Browse(string.Empty, false);
                _dataSource.GoTop();
            }
            else
            {
                _dataSource.ForceDesignMode(true);
                _dataSource.Active = true;
            }
        }

        private void DeactivateDataSources()
        {
            _dataSource.Active = false;
        }

        private void InitializeControls()
        {
            //vlSCLOAN.DataSourceClone = 1;
            vlSCLOAN.DataSource = _dataSource;
            vlSCLOAN.AddColumn(0, "STATUS", _dataSource.View.Fields.FieldByName["STATUS"].Index, "", AccpacFldList.tagColumnAligment.ALIGMENT_LEFT, 150, false, false, false);
            vlSCLOAN.AddColumn(1, "REFERENCE", _dataSource.View.Fields.FieldByName["REFERENCE"].Index, "", AccpacFldList.tagColumnAligment.ALIGMENT_LEFT, 150, false, false, false);
            vlSCLOAN.AddColumn(2, "DTSUBMIT", _dataSource.View.Fields.FieldByName["DTSUBMIT"].Index, "", AccpacFldList.tagColumnAligment.ALIGMENT_RIGHT, 150, false, false, false);
            vlSCLOAN.AddColumn(3, "AMTOFFER", _dataSource.View.Fields.FieldByName["AMTOFFER"].Index, "", AccpacFldList.tagColumnAligment.ALIGMENT_RIGHT, 150, false, false, false);
            vlSCLOAN.AddColumn(4, "AMTREQUEST", _dataSource.View.Fields.FieldByName["AMTREQUEST"].Index, "", AccpacFldList.tagColumnAligment.ALIGMENT_RIGHT, 150, false, false, false);
            vlSCLOAN.Refresh();
            vlSCLOAN.DataSource = _dataSource;
            vlSCLOAN.RefreshData();
            //vlSCLOAN.ReadOnly = !ApplicationData.Current.HasLoanEntryRight;

            foreach (var ctl in grpLoanRequestDetails.Controls)
            {
                AxAccpacFldEdit.AxAccpacFieldEditControl fec = (ctl as AxAccpacFldEdit.AxAccpacFieldEditControl);
                if (fec != null)
                    fec.DataSource = _dataSource;
            }

            foreach (var ctl in grpContactDetails.Controls)
            {
                AxAccpacFldEdit.AxAccpacFieldEditControl fec = (ctl as AxAccpacFldEdit.AxAccpacFieldEditControl);
                if (fec != null)
                    fec.DataSource = _dataSource;
            }

            foreach (var ctl in grpEmailDetails.Controls)
            {
                AxAccpacFldEdit.AxAccpacFieldEditControl fec = (ctl as AxAccpacFldEdit.AxAccpacFieldEditControl);
                if (fec != null)
                    fec.DataSource = _dataSource;
            }

            if (!ApplicationData.Current.HasLoanEntryRight)
            {
                btnViewTC.Enabled = false;
                //
                chkAgreeTC.Enabled = false;
                //
                btnSave.Enabled = false;
                btnSave.Visible = false;
                //
                btnSubmit.Enabled = false;
                btnSubmit.Visible = false;
                //
                btnUpdate.Enabled = false;
                btnUpdate.Visible = false;
                //
                btnResubmit.Enabled = false;
                btnResubmit.Visible = false;
                //
                foreach (var ctl in grpLoanRequestDetails.Controls)
                {
                    AxAccpacFldEdit.AxAccpacFieldEditControl fec = (ctl as AxAccpacFldEdit.AxAccpacFieldEditControl);
                    if (fec != null)
                        fec.ReadOnly = true;
                }

                foreach (var ctl in grpContactDetails.Controls)
                {
                    AxAccpacFldEdit.AxAccpacFieldEditControl fec = (ctl as AxAccpacFldEdit.AxAccpacFieldEditControl);
                    if (fec != null)
                        fec.ReadOnly = true;
                }

                foreach (var ctl in grpEmailDetails.Controls)
                {
                    AxAccpacFldEdit.AxAccpacFieldEditControl fec = (ctl as AxAccpacFldEdit.AxAccpacFieldEditControl);
                    if (fec != null)
                        fec.ReadOnly = true;
                }
            }
        }

        private void BtnViewTC_Click(object sender, EventArgs e)
        {
            using (TermsAndConditionsForm formTC = new TermsAndConditionsForm())
            {
                bool result = (formTC.ShowDialog(this) == DialogResult.OK);

                if ((short)_dataSource.Fields["STATUS"].get_Value() == 0)
                    chkAgreeTC.Enabled = result;
            }
        }

        private void BtnSave_Click(object sender, EventArgs e)
        {
            SaveChanges();
        }

        private void BtnResubmit_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show(
                Properties.Resources.SCPageLoanNative_ConfirmReSubmit,
                Properties.Resources.SCPageLoanNative_ConfirmTitle,
                MessageBoxButtons.YesNo, MessageBoxIcon.Question)
                == DialogResult.Yes)
                SaveChanges();
        }

        private void BtnSubmit_Click(object sender, EventArgs e)
        {
            try
            {
                _dataSource.Verify();
                if (MessageBox.Show(
                    Properties.Resources.SCPageLoanNative_ConfirmSubmit,
                    Properties.Resources.SCPageLoanNative_ConfirmTitle,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Question)
                    == DialogResult.Yes)
                {
                    _dataSource.Fields["STATUS"].set_Value(1);
                    SaveChanges();
                }
            }
            catch (COMException)
            {
                Sage300Application.Current.ReportErrors();
            }
        }

        private void BtnUpdate_Approved_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show(
                Properties.Resources.SCPageLoanNative_ConfirmApproved,
                Properties.Resources.SCPageLoanNative_ConfirmTitle,
                MessageBoxButtons.YesNo, MessageBoxIcon.Question)
                == DialogResult.Yes)
            {
                _dataSource.Fields["STATUS"].set_Value(4);
                SaveChanges();
            }
        }

        private void BtnUpdate_Rejected_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show(
                Properties.Resources.SCPageLoanNative_ConfirmRejected,
                Properties.Resources.SCPageLoanNative_ConfirmTitle,
                MessageBoxButtons.YesNo, MessageBoxIcon.Question)
                == DialogResult.Yes)
            {
                _dataSource.Fields["STATUS"].set_Value(3);
                SaveChanges();
            }
        }

        private void BtnUpdate_Cancel_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show(
                Properties.Resources.SCPageLoanNative_ConfirmCancel,
                Properties.Resources.SCPageLoanNative_ConfirmTitle,
                MessageBoxButtons.YesNo, MessageBoxIcon.Question)
                == DialogResult.Yes)
            {
                _dataSource.Fields["STATUS"].set_Value(2);
                SaveChanges();
            }
        }

        private bool SaveChanges(bool read = true)
        {
            try
            {
                btnSave.Enabled = false;
                btnSubmit.Enabled = false;
                btnUpdate.Enabled = false;
                btnResubmit.Enabled = false;

                Cursor.Current = Cursors.WaitCursor;

                _dataSource.Update();

                return true;
            }
            catch (COMException)
            {
                Sage300Application.Current.ReportErrors();
            }
            finally
            {
                if (read)
                    _dataSource.Read();

                Cursor.Current = Cursors.Default;
            }

            return false;
        }

        private void ChkAgreeTC_CheckStateChanged(object sender, EventArgs e)
        {
            btnSubmit.Enabled = chkAgreeTC.Checked;
        }

        private void SetControlsState()
        {
            if (!ApplicationData.Current.HasLoanEntryRight)
            {
                btnViewTC.Enabled = false;
                //
                chkAgreeTC.Enabled = false;
                //
                btnSave.Enabled = false;
                btnSave.Visible = false;
                //
                btnSubmit.Enabled = false;
                btnSubmit.Visible = false;
                //
                btnUpdate.Enabled = false;
                btnUpdate.Visible = false;
                //
                btnResubmit.Enabled = false;
                btnResubmit.Visible = false;
            }
            else
            {
                switch ((short)_dataSource.Fields["STATUS"].get_Value())
                {
                    case 0: // New
                        //
                        btnViewTC.Enabled = true;
                        //
                        chkAgreeTC.Enabled = false;
                        chkAgreeTC.Checked = false;
                        //
                        btnSave.Enabled = true;
                        btnSave.Visible = true;
                        //
                        btnSubmit.Enabled = false;
                        btnSubmit.Visible = true;
                        //
                        btnUpdate.Enabled = false;
                        btnUpdate.Visible = false;
                        //
                        btnResubmit.Enabled = false;
                        btnResubmit.Visible = false;

                        break;

                    case 1: // Submitted
                        //
                        btnViewTC.Enabled = true;
                        //
                        chkAgreeTC.Enabled = false;
                        chkAgreeTC.Checked = true;
                        //
                        btnSave.Enabled = false;
                        btnSave.Visible = false;
                        //
                        btnSubmit.Enabled = false;
                        btnSubmit.Visible = false;
                        //
                        btnUpdate.Enabled = true;
                        btnUpdate.Visible = true;
                        //
                        btnResubmit.Enabled = true;
                        btnResubmit.Visible = true;

                        break;

                    default: // Approved/Rejected/Cancelled
                        //
                        btnViewTC.Enabled = true;
                        //
                        chkAgreeTC.Enabled = false;
                        chkAgreeTC.Checked = true;
                        //
                        btnSave.Enabled = false;
                        btnSave.Visible = false;
                        //
                        btnSubmit.Enabled = false;
                        btnSubmit.Visible = false;
                        //
                        btnUpdate.Enabled = false;
                        btnUpdate.Visible = false;
                        //
                        btnResubmit.Enabled = false;
                        btnResubmit.Visible = false;

                        break;
                }
            }
        }
    }
}