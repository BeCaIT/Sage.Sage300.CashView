using Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.PopUps;
using Sage.CA.SBS.ERP.Sage300.SC.Data;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Telerik.WinControls;
using Telerik.WinControls.UI;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100
{
    public partial class FormMain : Telerik.WinControls.UI.RadForm
    {
        public FormMain()
        {
            InitializeComponent();

            //
            //// Default collapsed
            pvMain_loan.Item.Visibility = ElementVisibility.Collapsed;

            //
            //// Set Title
            Text = Sage300Application.Current.Session.CompanyID + " - " + Text;

            //
            //// Register ROTO
            RegisterWindow(Sage300Application.Current.ObjectHandle, Handle.ToInt32());
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

            if (Sage300Application.Current != null)
                UnregisterWindow(Sage300Application.Current.ObjectHandle);

            base.Dispose(disposing);
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            LoadData();
        }

        private async void LoadData()
        {
            radWaitingBar1.StartWaiting();

            pvMain.SelectedPage = pvMain_infoCenter;
            await Task.Run(() => Sage300Application.Current.LoadData());

            radWaitingBar1.StopWaiting();

            bsApplicationData.DataSource = ApplicationData.Current;

            //
            //// Check show Info Center page
            //if (!ApplicationData.Current.ShowNotifications)
            //{
                pvMain_infoCenter.Item.Visibility = ElementVisibility.Collapsed;
                pvMain.SelectedPage = pvMain_dashboard;
            //}

            //
            //// Check show Loan page
            if (!ApplicationData.Current.HasLoanRecords || !ApplicationData.Current.HasLoanInquiryRight)
                pvMain_loan.Item.Visibility = ElementVisibility.Collapsed;
            else
                pvMain_loan.Item.Visibility = ElementVisibility.Visible;

            //
            //// PopUps
            // Threshold
            if (ApplicationData.Current.ThresholdBreached)
                using (PopupAlert popupAlert = new PopupAlert())
                    popupAlert.ShowDialog();
            // Loan
            if (ApplicationData.Current.HasNewLoanRecord)
                using (PopupLoan popupLoan = new PopupLoan()
                {
                    DataSource = ApplicationData.Current
                })
                    if (popupLoan.ShowDialog() == DialogResult.OK)
                        pvMain.SelectedPage = pvMain_loan;
        }

        private void BtnDismiss_Click(object sender, EventArgs e)
        {
            pvMain.SelectedPage = pvMain_dashboard;
        }

        private void BtnPrintAR_Top10Customers_Click(object sender, EventArgs e)
        {
            Sage300Application.Current.PrintReport("SCARTOP", Handle.ToInt32(), null);
        }

        private void BtnPrintAR_AgedReceivables_Click(object sender, EventArgs e)
        {
            Sage300Application.Current.PrintReport("SCARAGED", Handle.ToInt32(), null);
        }

        private void BtnPrintAP_AgedCashRequirements_Click(object sender, EventArgs e)
        {
            Sage300Application.Current.PrintReport("SCAPCASH", Handle.ToInt32(), null);
        }

        private void BtnPrintAP_Top10Vendor_Click(object sender, EventArgs e)
        {
            Sage300Application.Current.PrintReport("SCAPTOP", Handle.ToInt32(), null);
        }

        private void PageInfoCenter_Click(object sender, EventArgs e)
        {
            if (pvMain_loan.Item.Visibility == ElementVisibility.Visible)
                pvMain.SelectedPage = pvMain_loan;
        }

        private void PageInfoCenter_Dismiss(object sender, EventArgs e)
        {
            pvMain.SelectedPage = pvMain_dashboard;
        }


        #region Roto Helpers
        [DllImport("a4wroto.dll")]
        private static extern void rotoSetObjectWindow(int objectHandle, int hWnd);

        public void RegisterWindow(int objectHandle, int hWnd)
        {
            rotoSetObjectWindow(objectHandle, hWnd);
        }

        public void UnregisterWindow(int objectHandle)
        {
            rotoSetObjectWindow(objectHandle, 0);
        }
        #endregion Roto Helpers
    }
}
