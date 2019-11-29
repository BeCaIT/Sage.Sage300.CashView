﻿namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.PopUps
{
    partial class PopupAlert
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PopupAlert));
            this.pnlTitle = new Telerik.WinControls.UI.RadPanel();
            this.lblTitle = new Telerik.WinControls.UI.RadLabel();
            this.picIcon = new System.Windows.Forms.PictureBox();
            this.btnClose = new Telerik.WinControls.UI.RadButton();
            this.picOffer = new System.Windows.Forms.PictureBox();
            this.bsApplication = new System.Windows.Forms.BindingSource(this.components);
            this.lblThresholdAlert = new Telerik.WinControls.UI.RadLabel();
            ((System.ComponentModel.ISupportInitialize)(this.pnlTitle)).BeginInit();
            this.pnlTitle.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lblTitle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picIcon)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.btnClose)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picOffer)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bsApplication)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblThresholdAlert)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlTitle
            // 
            this.pnlTitle.BackColor = System.Drawing.Color.Black;
            this.pnlTitle.Controls.Add(this.lblTitle);
            this.pnlTitle.Controls.Add(this.picIcon);
            this.pnlTitle.Controls.Add(this.btnClose);
            resources.ApplyResources(this.pnlTitle, "pnlTitle");
            this.pnlTitle.Name = "pnlTitle";
            // 
            // lblTitle
            // 
            resources.ApplyResources(this.lblTitle, "lblTitle");
            this.lblTitle.ForeColor = System.Drawing.Color.White;
            this.lblTitle.Name = "lblTitle";
            // 
            // picIcon
            // 
            this.picIcon.Image = global::Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Properties.Resources.WarningSign;
            resources.ApplyResources(this.picIcon, "picIcon");
            this.picIcon.Name = "picIcon";
            this.picIcon.TabStop = false;
            // 
            // btnClose
            // 
            resources.ApplyResources(this.btnClose, "btnClose");
            this.btnClose.BackColor = System.Drawing.Color.Transparent;
            this.btnClose.ForeColor = System.Drawing.Color.White;
            this.btnClose.Name = "btnClose";
            this.btnClose.Click += new System.EventHandler(this.BtnClose_Click);
            // 
            // picOffer
            // 
            this.picOffer.DataBindings.Add(new System.Windows.Forms.Binding("Image", this.bsApplication, "OfferImage", true));
            resources.ApplyResources(this.picOffer, "picOffer");
            this.picOffer.Name = "picOffer";
            this.picOffer.TabStop = false;
            // 
            // bsApplication
            // 
            this.bsApplication.DataSource = typeof(Sage.CA.SBS.ERP.Sage300.SC.Data.ApplicationData);
            // 
            // lblThresholdAlert
            // 
            resources.ApplyResources(this.lblThresholdAlert, "lblThresholdAlert");
            this.lblThresholdAlert.Name = "lblThresholdAlert";
            // 
            // PopupAlert
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.lblThresholdAlert);
            this.Controls.Add(this.picOffer);
            this.Controls.Add(this.pnlTitle);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "PopupAlert";
            // 
            // 
            // 
            this.RootElement.ApplyShapeToControl = true;
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.Load += new System.EventHandler(this.PopupLoan_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pnlTitle)).EndInit();
            this.pnlTitle.ResumeLayout(false);
            this.pnlTitle.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lblTitle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picIcon)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.btnClose)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picOffer)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bsApplication)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.lblThresholdAlert)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Telerik.WinControls.UI.RadPanel pnlTitle;
        private Telerik.WinControls.UI.RadButton btnClose;
        private System.Windows.Forms.PictureBox picOffer;
        private System.Windows.Forms.BindingSource bsApplication;
        private System.Windows.Forms.PictureBox picIcon;
        private Telerik.WinControls.UI.RadLabel lblTitle;
        private Telerik.WinControls.UI.RadLabel lblThresholdAlert;
    }
}
