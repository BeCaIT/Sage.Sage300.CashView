namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    partial class SCIndicatorGauge
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SCIndicatorGauge));
            this.tlIndicatorGauge = new Telerik.WinControls.UI.DoubleBufferedTableLayoutPanel();
            this.lblIndicator = new Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls.SCAutoSizeLabel();
            this.arrIndicator = new Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls.SCIndicatorArrow();
            this.tlIndicatorGauge.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lblIndicator)).BeginInit();
            this.SuspendLayout();
            // 
            // tlIndicatorGauge
            // 
            resources.ApplyResources(this.tlIndicatorGauge, "tlIndicatorGauge");
            this.tlIndicatorGauge.Controls.Add(this.lblIndicator, 0, 0);
            this.tlIndicatorGauge.Controls.Add(this.arrIndicator, 1, 0);
            this.tlIndicatorGauge.Name = "tlIndicatorGauge";
            // 
            // lblIndicator
            // 
            resources.ApplyResources(this.lblIndicator, "lblIndicator");
            this.lblIndicator.Name = "lblIndicator";
            // 
            // arrIndicator
            // 
            this.arrIndicator.BreakPoint = new decimal(new int[] {
            0,
            0,
            0,
            0});
            resources.ApplyResources(this.arrIndicator, "arrIndicator");
            this.arrIndicator.Name = "arrIndicator";
            this.arrIndicator.NegativeColor = System.Drawing.Color.Red;
            this.arrIndicator.PositiveColor = System.Drawing.Color.GreenYellow;
            this.arrIndicator.Value = new decimal(new int[] {
            0,
            0,
            0,
            0});
            // 
            // SCIndicatorGauge
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.tlIndicatorGauge);
            this.Name = "SCIndicatorGauge";
            this.tlIndicatorGauge.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.lblIndicator)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private Telerik.WinControls.UI.DoubleBufferedTableLayoutPanel tlIndicatorGauge;
        private SCAutoSizeLabel lblIndicator;
        private SCIndicatorArrow arrIndicator;
    }
}
