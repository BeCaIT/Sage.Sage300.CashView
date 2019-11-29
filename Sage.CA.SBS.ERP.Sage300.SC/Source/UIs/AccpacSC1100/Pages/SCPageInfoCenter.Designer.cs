namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages
{
    partial class SCPageInfoCenter
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

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
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SCPageInfoCenter));
            this.tlInfoCenter = new Telerik.WinControls.UI.DoubleBufferedTableLayoutPanel();
            this.picBIL = new System.Windows.Forms.PictureBox();
            this.bsInfoCenter = new System.Windows.Forms.BindingSource(this.components);
            this.btnThresholdBreachedAlert = new Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls.SCFlashingDropDownButton();
            this.mnuSnooze = new Telerik.WinControls.UI.RadMenuHeaderItem();
            this.mnuSnooze_07days = new Telerik.WinControls.UI.RadMenuItem();
            this.mnuSnooze_14days = new Telerik.WinControls.UI.RadMenuItem();
            this.mnuSnooze_30days = new Telerik.WinControls.UI.RadMenuItem();
            this.tlInfoCenter.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picBIL)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bsInfoCenter)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.btnThresholdBreachedAlert)).BeginInit();
            this.SuspendLayout();
            // 
            // tlInfoCenter
            // 
            resources.ApplyResources(this.tlInfoCenter, "tlInfoCenter");
            this.tlInfoCenter.Controls.Add(this.picBIL, 0, 1);
            this.tlInfoCenter.Controls.Add(this.btnThresholdBreachedAlert, 0, 0);
            this.tlInfoCenter.Name = "tlInfoCenter";
            // 
            // picBIL
            // 
            this.picBIL.DataBindings.Add(new System.Windows.Forms.Binding("Visible", this.bsInfoCenter, "HasNewLoanRecord", true, System.Windows.Forms.DataSourceUpdateMode.Never));
            this.picBIL.DataBindings.Add(new System.Windows.Forms.Binding("Image", this.bsInfoCenter, "OfferImage", true));
            resources.ApplyResources(this.picBIL, "picBIL");
            this.picBIL.Image = global::Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Properties.Resources._702;
            this.picBIL.Name = "picBIL";
            this.picBIL.TabStop = false;
            this.picBIL.Click += new System.EventHandler(this.PicBIL_Click);
            // 
            // bsInfoCenter
            // 
            this.bsInfoCenter.DataSource = typeof(Sage.CA.SBS.ERP.Sage300.SC.Data.ApplicationData);
            this.bsInfoCenter.BindingComplete += new System.Windows.Forms.BindingCompleteEventHandler(this.BsInfoCenter_BindingComplete);
            // 
            // btnThresholdBreachedAlert
            // 
            this.btnThresholdBreachedAlert.DataBindings.Add(new System.Windows.Forms.Binding("Visible", this.bsInfoCenter, "ShowThresholdAlert", true));
            resources.ApplyResources(this.btnThresholdBreachedAlert, "btnThresholdBreachedAlert");
            this.btnThresholdBreachedAlert.ForeColor = System.Drawing.Color.Red;
            this.btnThresholdBreachedAlert.Items.AddRange(new Telerik.WinControls.RadItem[] {
            this.mnuSnooze,
            this.mnuSnooze_07days,
            this.mnuSnooze_14days,
            this.mnuSnooze_30days});
            this.btnThresholdBreachedAlert.Name = "btnThresholdBreachedAlert";
            // 
            // mnuSnooze
            // 
            resources.ApplyResources(this.mnuSnooze, "mnuSnooze");
            this.mnuSnooze.Name = "mnuSnooze";
            // 
            // mnuSnooze_07days
            // 
            resources.ApplyResources(this.mnuSnooze_07days, "mnuSnooze_07days");
            this.mnuSnooze_07days.Name = "mnuSnooze_07days";
            this.mnuSnooze_07days.Click += new System.EventHandler(this.MnuSnooze_07days_Click);
            // 
            // mnuSnooze_14days
            // 
            resources.ApplyResources(this.mnuSnooze_14days, "mnuSnooze_14days");
            this.mnuSnooze_14days.Name = "mnuSnooze_14days";
            this.mnuSnooze_14days.Click += new System.EventHandler(this.MnuSnooze_14days_Click);
            // 
            // mnuSnooze_30days
            // 
            resources.ApplyResources(this.mnuSnooze_30days, "mnuSnooze_30days");
            this.mnuSnooze_30days.Name = "mnuSnooze_30days";
            this.mnuSnooze_30days.Click += new System.EventHandler(this.MnuSnooze_30days_Click);
            // 
            // SCPageInfoCenter
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.tlInfoCenter);
            this.Name = "SCPageInfoCenter";
            this.tlInfoCenter.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picBIL)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bsInfoCenter)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.btnThresholdBreachedAlert)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private Telerik.WinControls.UI.DoubleBufferedTableLayoutPanel tlInfoCenter;
        private Controls.SCFlashingDropDownButton btnThresholdBreachedAlert;
        private Telerik.WinControls.UI.RadMenuHeaderItem mnuSnooze;
        private Telerik.WinControls.UI.RadMenuItem mnuSnooze_07days;
        private Telerik.WinControls.UI.RadMenuItem mnuSnooze_14days;
        private Telerik.WinControls.UI.RadMenuItem mnuSnooze_30days;
        private System.Windows.Forms.BindingSource bsInfoCenter;
        private System.Windows.Forms.PictureBox picBIL;
    }
}
