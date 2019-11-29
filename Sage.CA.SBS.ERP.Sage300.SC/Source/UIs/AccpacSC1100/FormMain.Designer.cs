namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100
{
    partial class FormMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.themeManager = new Telerik.WinControls.RadThemeManager();
            this.pvMain = new Telerik.WinControls.UI.RadPageView();
            this.pvMain_infoCenter = new Telerik.WinControls.UI.RadPageViewPage();
            this.btnDismiss = new Telerik.WinControls.UI.RadButton();
            this.radWaitingBar1 = new Telerik.WinControls.UI.RadWaitingBar();
            this.fadingRingWaitingBarIndicatorElement1 = new Telerik.WinControls.UI.FadingRingWaitingBarIndicatorElement();
            this.pageInfoCenter = new Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages.SCPageInfoCenter();
            this.bsApplicationData = new System.Windows.Forms.BindingSource(this.components);
            this.pvMain_dashboard = new Telerik.WinControls.UI.RadPageViewPage();
            this.pageDashBoard = new Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages.SCPageDashboard();
            this.pvMain_cashFlowSummary = new Telerik.WinControls.UI.RadPageViewPage();
            this.pageCashFlowSummary = new Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages.SCPageCashFlowSummary();
            this.pvMain_arSummary = new Telerik.WinControls.UI.RadPageViewPage();
            this.btnPrintAR = new Telerik.WinControls.UI.RadDropDownButton();
            this.btnPrintAR_Top10Customers = new Telerik.WinControls.UI.RadMenuItem();
            this.btnPrintAR_AgedReceivables = new Telerik.WinControls.UI.RadMenuItem();
            this.pageARSummary = new Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages.SCPayeeSummary();
            this.pvMain_apSummary = new Telerik.WinControls.UI.RadPageViewPage();
            this.btnPrintAP = new Telerik.WinControls.UI.RadDropDownButton();
            this.btnPrintAP_Top10Vendor = new Telerik.WinControls.UI.RadMenuItem();
            this.btnPrintAP_AgedCashRequirements = new Telerik.WinControls.UI.RadMenuItem();
            this.pageAPSummary = new Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages.SCPayeeSummary();
            this.pvMain_loan = new Telerik.WinControls.UI.RadPageViewPage();
            this.pageLoan = new Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages.SCPageLoanNative();
            ((System.ComponentModel.ISupportInitialize)(this.pvMain)).BeginInit();
            this.pvMain.SuspendLayout();
            this.pvMain_infoCenter.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.btnDismiss)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.radWaitingBar1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bsApplicationData)).BeginInit();
            this.pvMain_dashboard.SuspendLayout();
            this.pvMain_cashFlowSummary.SuspendLayout();
            this.pvMain_arSummary.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.btnPrintAR)).BeginInit();
            this.pvMain_apSummary.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.btnPrintAP)).BeginInit();
            this.pvMain_loan.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this)).BeginInit();
            this.SuspendLayout();
            // 
            // pvMain
            // 
            this.pvMain.Controls.Add(this.pvMain_infoCenter);
            this.pvMain.Controls.Add(this.pvMain_dashboard);
            this.pvMain.Controls.Add(this.pvMain_cashFlowSummary);
            this.pvMain.Controls.Add(this.pvMain_arSummary);
            this.pvMain.Controls.Add(this.pvMain_apSummary);
            this.pvMain.Controls.Add(this.pvMain_loan);
            this.pvMain.DefaultPage = this.pvMain_dashboard;
            resources.ApplyResources(this.pvMain, "pvMain");
            this.pvMain.Name = "pvMain";
            this.pvMain.SelectedPage = this.pvMain_dashboard;
            this.pvMain.ViewMode = Telerik.WinControls.UI.PageViewMode.NavigationView;
            ((Telerik.WinControls.UI.RadPageViewNavigationViewElement)(this.pvMain.GetChildAt(0))).ExpandedPaneWidth = 150;
            // 
            // pvMain_infoCenter
            // 
            this.pvMain_infoCenter.Controls.Add(this.btnDismiss);
            this.pvMain_infoCenter.Controls.Add(this.radWaitingBar1);
            this.pvMain_infoCenter.Controls.Add(this.pageInfoCenter);
            this.pvMain_infoCenter.Image = global::Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Properties.Resources.AlertNotice;
            this.pvMain_infoCenter.ItemSize = new System.Drawing.SizeF(38F, 38F);
            resources.ApplyResources(this.pvMain_infoCenter, "pvMain_infoCenter");
            this.pvMain_infoCenter.Name = "pvMain_infoCenter";
            // 
            // btnDismiss
            // 
            resources.ApplyResources(this.btnDismiss, "btnDismiss");
            this.btnDismiss.Name = "btnDismiss";
            this.btnDismiss.Click += new System.EventHandler(this.BtnDismiss_Click);
            // 
            // radWaitingBar1
            // 
            this.radWaitingBar1.AssociatedControl = this.pvMain_infoCenter;
            resources.ApplyResources(this.radWaitingBar1, "radWaitingBar1");
            this.radWaitingBar1.Name = "radWaitingBar1";
            this.radWaitingBar1.WaitingIndicators.Add(this.fadingRingWaitingBarIndicatorElement1);
            this.radWaitingBar1.WaitingStep = 8;
            this.radWaitingBar1.WaitingStyle = Telerik.WinControls.Enumerations.WaitingBarStyles.FadingRing;
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).WaitingStep = 8;
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).TextWrap = ((bool)(resources.GetObject("radWaitingBar1.WaitingBarElement.TextWrap")));
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).TextOrientation = ((System.Windows.Forms.Orientation)(resources.GetObject("radWaitingBar1.WaitingBarElement.TextOrientation")));
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).FlipText = ((bool)(resources.GetObject("radWaitingBar1.WaitingBarElement.FlipText")));
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).Text = resources.GetString("radWaitingBar1.WaitingBarElement.Text");
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).Padding = ((System.Windows.Forms.Padding)(resources.GetObject("radWaitingBar1.WaitingBarElement.Padding")));
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).Margin = ((System.Windows.Forms.Padding)(resources.GetObject("radWaitingBar1.WaitingBarElement.Margin")));
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).Alignment = ((System.Drawing.ContentAlignment)(resources.GetObject("radWaitingBar1.WaitingBarElement.Alignment")));
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).RightToLeft = ((bool)(resources.GetObject("radWaitingBar1.WaitingBarElement.RightToLeft")));
            ((Telerik.WinControls.UI.RadWaitingBarElement)(this.radWaitingBar1.GetChildAt(0))).AngleTransform = ((float)(resources.GetObject("radWaitingBar1.WaitingBarElement.AngleTransform")));
            ((Telerik.WinControls.UI.WaitingBarContentElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0))).WaitingStyle = Telerik.WinControls.Enumerations.WaitingBarStyles.FadingRing;
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).Dash = false;
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).TextWrap = ((bool)(resources.GetObject("radWaitingBar1.WaitingBarElement.SeparatorElement.TextWrap")));
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).TextOrientation = ((System.Windows.Forms.Orientation)(resources.GetObject("radWaitingBar1.WaitingBarElement.SeparatorElement.TextOrientation")));
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).FlipText = ((bool)(resources.GetObject("radWaitingBar1.WaitingBarElement.SeparatorElement.FlipText")));
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).Text = resources.GetString("radWaitingBar1.WaitingBarElement.SeparatorElement.Text");
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).Padding = ((System.Windows.Forms.Padding)(resources.GetObject("radWaitingBar1.WaitingBarElement.SeparatorElement.Padding")));
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).Margin = ((System.Windows.Forms.Padding)(resources.GetObject("radWaitingBar1.WaitingBarElement.SeparatorElement.Margin")));
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).Alignment = ((System.Drawing.ContentAlignment)(resources.GetObject("radWaitingBar1.WaitingBarElement.SeparatorElement.Alignment")));
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).RightToLeft = ((bool)(resources.GetObject("radWaitingBar1.WaitingBarElement.SeparatorElement.RightToLeft")));
            ((Telerik.WinControls.UI.WaitingBarSeparatorElement)(this.radWaitingBar1.GetChildAt(0).GetChildAt(0).GetChildAt(0))).AngleTransform = ((float)(resources.GetObject("radWaitingBar1.WaitingBarElement.SeparatorElement.AngleTransform")));
            // 
            // fadingRingWaitingBarIndicatorElement1
            // 
            resources.ApplyResources(this.fadingRingWaitingBarIndicatorElement1, "fadingRingWaitingBarIndicatorElement1");
            this.fadingRingWaitingBarIndicatorElement1.Name = "fadingRingWaitingBarIndicatorElement1";
            // 
            // pageInfoCenter
            // 
            this.pageInfoCenter.DataSource = this.bsApplicationData;
            resources.ApplyResources(this.pageInfoCenter, "pageInfoCenter");
            this.pageInfoCenter.Name = "pageInfoCenter";
            this.pageInfoCenter.Dismiss += new System.EventHandler(this.PageInfoCenter_Dismiss);
            this.pageInfoCenter.Click += new System.EventHandler(this.PageInfoCenter_Click);
            // 
            // bsApplicationData
            // 
            this.bsApplicationData.DataSource = typeof(Sage.CA.SBS.ERP.Sage300.SC.Data.ApplicationData);
            // 
            // pvMain_dashboard
            // 
            this.pvMain_dashboard.Controls.Add(this.pageDashBoard);
            this.pvMain_dashboard.Image = global::Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Properties.Resources.DASHBOARD;
            this.pvMain_dashboard.ItemSize = new System.Drawing.SizeF(38F, 38F);
            resources.ApplyResources(this.pvMain_dashboard, "pvMain_dashboard");
            this.pvMain_dashboard.Name = "pvMain_dashboard";
            // 
            // pageDashBoard
            // 
            this.pageDashBoard.DataBindings.Add(new System.Windows.Forms.Binding("FormatString", this.bsApplicationData, "FormatString", true, System.Windows.Forms.DataSourceUpdateMode.Never));
            this.pageDashBoard.DataSource = this.bsApplicationData;
            resources.ApplyResources(this.pageDashBoard, "pageDashBoard");
            this.pageDashBoard.FormatString = "n";
            this.pageDashBoard.Name = "pageDashBoard";
            // 
            // pvMain_cashFlowSummary
            // 
            this.pvMain_cashFlowSummary.Controls.Add(this.pageCashFlowSummary);
            this.pvMain_cashFlowSummary.Image = global::Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Properties.Resources.SUMMARY;
            this.pvMain_cashFlowSummary.ItemSize = new System.Drawing.SizeF(38F, 38F);
            resources.ApplyResources(this.pvMain_cashFlowSummary, "pvMain_cashFlowSummary");
            this.pvMain_cashFlowSummary.Name = "pvMain_cashFlowSummary";
            // 
            // pageCashFlowSummary
            // 
            this.pageCashFlowSummary.DataBindings.Add(new System.Windows.Forms.Binding("FormatString", this.bsApplicationData, "FormatString", true, System.Windows.Forms.DataSourceUpdateMode.Never));
            this.pageCashFlowSummary.DataMember = "CashFlowSummary";
            this.pageCashFlowSummary.DataSource = this.bsApplicationData;
            resources.ApplyResources(this.pageCashFlowSummary, "pageCashFlowSummary");
            this.pageCashFlowSummary.FormatString = "n";
            this.pageCashFlowSummary.Name = "pageCashFlowSummary";
            // 
            // pvMain_arSummary
            // 
            this.pvMain_arSummary.Controls.Add(this.btnPrintAR);
            this.pvMain_arSummary.Controls.Add(this.pageARSummary);
            this.pvMain_arSummary.Image = global::Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Properties.Resources.AR;
            this.pvMain_arSummary.ItemSize = new System.Drawing.SizeF(38F, 38F);
            resources.ApplyResources(this.pvMain_arSummary, "pvMain_arSummary");
            this.pvMain_arSummary.Name = "pvMain_arSummary";
            // 
            // btnPrintAR
            // 
            resources.ApplyResources(this.btnPrintAR, "btnPrintAR");
            this.btnPrintAR.Items.AddRange(new Telerik.WinControls.RadItem[] {
            this.btnPrintAR_Top10Customers,
            this.btnPrintAR_AgedReceivables});
            this.btnPrintAR.Name = "btnPrintAR";
            // 
            // btnPrintAR_Top10Customers
            // 
            resources.ApplyResources(this.btnPrintAR_Top10Customers, "btnPrintAR_Top10Customers");
            this.btnPrintAR_Top10Customers.Name = "btnPrintAR_Top10Customers";
            this.btnPrintAR_Top10Customers.UseCompatibleTextRendering = false;
            this.btnPrintAR_Top10Customers.Click += new System.EventHandler(this.BtnPrintAR_Top10Customers_Click);
            // 
            // btnPrintAR_AgedReceivables
            // 
            resources.ApplyResources(this.btnPrintAR_AgedReceivables, "btnPrintAR_AgedReceivables");
            this.btnPrintAR_AgedReceivables.Name = "btnPrintAR_AgedReceivables";
            this.btnPrintAR_AgedReceivables.UseCompatibleTextRendering = false;
            this.btnPrintAR_AgedReceivables.Click += new System.EventHandler(this.BtnPrintAR_AgedReceivables_Click);
            // 
            // pageARSummary
            // 
            this.pageARSummary.DataBindings.Add(new System.Windows.Forms.Binding("FormatString", this.bsApplicationData, "FormatString", true, System.Windows.Forms.DataSourceUpdateMode.Never));
            this.pageARSummary.DataMember = "ARSummary";
            this.pageARSummary.DataSource = this.bsApplicationData;
            resources.ApplyResources(this.pageARSummary, "pageARSummary");
            this.pageARSummary.FormatString = "n";
            this.pageARSummary.Name = "pageARSummary";
            this.pageARSummary.PayeeHeaderText = "Customer #";
            // 
            // pvMain_apSummary
            // 
            this.pvMain_apSummary.Controls.Add(this.btnPrintAP);
            this.pvMain_apSummary.Controls.Add(this.pageAPSummary);
            this.pvMain_apSummary.Image = global::Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Properties.Resources.AP;
            this.pvMain_apSummary.ItemSize = new System.Drawing.SizeF(38F, 38F);
            resources.ApplyResources(this.pvMain_apSummary, "pvMain_apSummary");
            this.pvMain_apSummary.Name = "pvMain_apSummary";
            // 
            // btnPrintAP
            // 
            resources.ApplyResources(this.btnPrintAP, "btnPrintAP");
            this.btnPrintAP.Items.AddRange(new Telerik.WinControls.RadItem[] {
            this.btnPrintAP_Top10Vendor,
            this.btnPrintAP_AgedCashRequirements});
            this.btnPrintAP.Name = "btnPrintAP";
            // 
            // btnPrintAP_Top10Vendor
            // 
            resources.ApplyResources(this.btnPrintAP_Top10Vendor, "btnPrintAP_Top10Vendor");
            this.btnPrintAP_Top10Vendor.Name = "btnPrintAP_Top10Vendor";
            this.btnPrintAP_Top10Vendor.Click += new System.EventHandler(this.BtnPrintAP_Top10Vendor_Click);
            // 
            // btnPrintAP_AgedCashRequirements
            // 
            resources.ApplyResources(this.btnPrintAP_AgedCashRequirements, "btnPrintAP_AgedCashRequirements");
            this.btnPrintAP_AgedCashRequirements.Name = "btnPrintAP_AgedCashRequirements";
            this.btnPrintAP_AgedCashRequirements.Click += new System.EventHandler(this.BtnPrintAP_AgedCashRequirements_Click);
            // 
            // pageAPSummary
            // 
            this.pageAPSummary.DataBindings.Add(new System.Windows.Forms.Binding("FormatString", this.bsApplicationData, "FormatString", true, System.Windows.Forms.DataSourceUpdateMode.Never));
            this.pageAPSummary.DataMember = "APSummary";
            this.pageAPSummary.DataSource = this.bsApplicationData;
            resources.ApplyResources(this.pageAPSummary, "pageAPSummary");
            this.pageAPSummary.FormatString = "n";
            this.pageAPSummary.Name = "pageAPSummary";
            this.pageAPSummary.PayeeHeaderText = "Vendor #";
            // 
            // pvMain_loan
            // 
            this.pvMain_loan.Controls.Add(this.pageLoan);
            this.pvMain_loan.Image = global::Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Properties.Resources.LOAN;
            this.pvMain_loan.ItemSize = new System.Drawing.SizeF(38F, 38F);
            resources.ApplyResources(this.pvMain_loan, "pvMain_loan");
            this.pvMain_loan.Name = "pvMain_loan";
            // 
            // pageLoan
            // 
            resources.ApplyResources(this.pageLoan, "pageLoan");
            this.pageLoan.Name = "pageLoan";
            // 
            // FormMain
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.pvMain);
            this.Name = "FormMain";
            // 
            // 
            // 
            this.RootElement.ApplyShapeToControl = true;
            this.Load += new System.EventHandler(this.FormMain_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pvMain)).EndInit();
            this.pvMain.ResumeLayout(false);
            this.pvMain_infoCenter.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.btnDismiss)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.radWaitingBar1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bsApplicationData)).EndInit();
            this.pvMain_dashboard.ResumeLayout(false);
            this.pvMain_cashFlowSummary.ResumeLayout(false);
            this.pvMain_arSummary.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.btnPrintAR)).EndInit();
            this.pvMain_apSummary.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.btnPrintAP)).EndInit();
            this.pvMain_loan.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private Telerik.WinControls.RadThemeManager themeManager;
        private Telerik.WinControls.UI.RadPageView pvMain;
        private Telerik.WinControls.UI.RadPageViewPage pvMain_infoCenter;
        private Telerik.WinControls.UI.RadPageViewPage pvMain_cashFlowSummary;
        private Telerik.WinControls.UI.RadPageViewPage pvMain_arSummary;
        private Telerik.WinControls.UI.RadPageViewPage pvMain_apSummary;
        private Telerik.WinControls.UI.RadPageViewPage pvMain_loan;
        private Telerik.WinControls.UI.RadWaitingBar radWaitingBar1;
        private Telerik.WinControls.UI.FadingRingWaitingBarIndicatorElement fadingRingWaitingBarIndicatorElement1;
        private Telerik.WinControls.UI.RadPageViewPage pvMain_dashboard;
        private System.Windows.Forms.BindingSource bsApplicationData;
        private Pages.SCPageCashFlowSummary pageCashFlowSummary;
        private Pages.SCPageDashboard pageDashBoard;
        private Pages.SCPageInfoCenter pageInfoCenter;
        private Pages.SCPayeeSummary pageARSummary;
        private Pages.SCPayeeSummary pageAPSummary;
        private Telerik.WinControls.UI.RadButton btnDismiss;
        private Pages.SCPageLoanNative pageLoan;
        private Telerik.WinControls.UI.RadDropDownButton btnPrintAP;
        private Telerik.WinControls.UI.RadMenuItem btnPrintAP_Top10Vendor;
        private Telerik.WinControls.UI.RadMenuItem btnPrintAP_AgedCashRequirements;
        private Telerik.WinControls.UI.RadDropDownButton btnPrintAR;
        private Telerik.WinControls.UI.RadMenuItem btnPrintAR_Top10Customers;
        private Telerik.WinControls.UI.RadMenuItem btnPrintAR_AgedReceivables;
    }
}