namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    partial class SCNetGauge
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SCNetGauge));
            this.tlNetGauge = new Telerik.WinControls.UI.DoubleBufferedTableLayoutPanel();
            this.lblInLabel = new Telerik.WinControls.UI.RadLabel();
            this.lblInValue = new Telerik.WinControls.UI.RadLabel();
            this.lblOutLabel = new Telerik.WinControls.UI.RadLabel();
            this.lblOutValue = new Telerik.WinControls.UI.RadLabel();
            this.lblNetLabel = new Telerik.WinControls.UI.RadLabel();
            this.lblNetValue = new Telerik.WinControls.UI.RadLabel();
            this.tlNetGauge.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lblInLabel)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblInValue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblOutLabel)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblOutValue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblNetLabel)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblNetValue)).BeginInit();
            this.SuspendLayout();
            // 
            // tlNetGauge
            // 
            resources.ApplyResources(this.tlNetGauge, "tlNetGauge");
            this.tlNetGauge.Controls.Add(this.lblInLabel, 0, 1);
            this.tlNetGauge.Controls.Add(this.lblInValue, 1, 1);
            this.tlNetGauge.Controls.Add(this.lblOutLabel, 0, 2);
            this.tlNetGauge.Controls.Add(this.lblOutValue, 1, 2);
            this.tlNetGauge.Controls.Add(this.lblNetLabel, 0, 3);
            this.tlNetGauge.Controls.Add(this.lblNetValue, 1, 3);
            this.tlNetGauge.Name = "tlNetGauge";
            // 
            // lblInLabel
            // 
            resources.ApplyResources(this.lblInLabel, "lblInLabel");
            this.lblInLabel.Name = "lblInLabel";
            // 
            // lblInValue
            // 
            resources.ApplyResources(this.lblInValue, "lblInValue");
            this.lblInValue.Name = "lblInValue";
            // 
            // lblOutLabel
            // 
            resources.ApplyResources(this.lblOutLabel, "lblOutLabel");
            this.lblOutLabel.Name = "lblOutLabel";
            // 
            // lblOutValue
            // 
            resources.ApplyResources(this.lblOutValue, "lblOutValue");
            this.lblOutValue.Name = "lblOutValue";
            // 
            // lblNetLabel
            // 
            resources.ApplyResources(this.lblNetLabel, "lblNetLabel");
            this.lblNetLabel.Name = "lblNetLabel";
            // 
            // lblNetValue
            // 
            resources.ApplyResources(this.lblNetValue, "lblNetValue");
            this.lblNetValue.Name = "lblNetValue";
            // 
            // SCNetGauge
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.tlNetGauge);
            this.Name = "SCNetGauge";
            this.tlNetGauge.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.lblInLabel)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblInValue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblOutLabel)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblOutValue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblNetLabel)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblNetValue)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private Telerik.WinControls.UI.DoubleBufferedTableLayoutPanel tlNetGauge;
        private Telerik.WinControls.UI.RadLabel lblInLabel;
        private Telerik.WinControls.UI.RadLabel lblInValue;
        private Telerik.WinControls.UI.RadLabel lblOutLabel;
        private Telerik.WinControls.UI.RadLabel lblOutValue;
        private Telerik.WinControls.UI.RadLabel lblNetLabel;
        private Telerik.WinControls.UI.RadLabel lblNetValue;
    }
}
