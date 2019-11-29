namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.PopUps
{
    partial class PopupLoan
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PopupLoan));
            this.pnlTitle = new Telerik.WinControls.UI.RadPanel();
            this.picIcon = new System.Windows.Forms.PictureBox();
            this.btnClose = new Telerik.WinControls.UI.RadButton();
            this.picOffer = new System.Windows.Forms.PictureBox();
            this.bsApplication = new System.Windows.Forms.BindingSource(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.pnlTitle)).BeginInit();
            this.pnlTitle.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picIcon)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.btnClose)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picOffer)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bsApplication)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlTitle
            // 
            this.pnlTitle.BackColor = System.Drawing.Color.Black;
            this.pnlTitle.Controls.Add(this.picIcon);
            this.pnlTitle.Controls.Add(this.btnClose);
            resources.ApplyResources(this.pnlTitle, "pnlTitle");
            this.pnlTitle.Name = "pnlTitle";
            // 
            // picIcon
            // 
            this.picIcon.Image = global::Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Properties.Resources.InfoSign;
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
            this.picOffer.Click += new System.EventHandler(this.PicOffer_Click);
            // 
            // bsApplication
            // 
            this.bsApplication.DataSource = typeof(Sage.CA.SBS.ERP.Sage300.SC.Data.ApplicationData);
            // 
            // PopupLoan
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.picOffer);
            this.Controls.Add(this.pnlTitle);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "PopupLoan";
            // 
            // 
            // 
            this.RootElement.ApplyShapeToControl = true;
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.Load += new System.EventHandler(this.PopupLoan_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pnlTitle)).EndInit();
            this.pnlTitle.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picIcon)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.btnClose)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picOffer)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bsApplication)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private Telerik.WinControls.UI.RadPanel pnlTitle;
        private Telerik.WinControls.UI.RadButton btnClose;
        private System.Windows.Forms.PictureBox picOffer;
        private System.Windows.Forms.BindingSource bsApplication;
        private System.Windows.Forms.PictureBox picIcon;
    }
}
