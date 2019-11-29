namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100
{
    partial class TermsAndConditionsForm
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
            this.btnOK = new Telerik.WinControls.UI.RadButton();
            this.pnlTermsAndConditions = new Telerik.WinControls.UI.RadPanel();
            this.wbTermsAndConditions = new System.Windows.Forms.WebBrowser();
            ((System.ComponentModel.ISupportInitialize)(this.btnOK)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pnlTermsAndConditions)).BeginInit();
            this.pnlTermsAndConditions.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this)).BeginInit();
            this.SuspendLayout();
            // 
            // btnOK
            // 
            this.btnOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnOK.Location = new System.Drawing.Point(511, 323);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(110, 24);
            this.btnOK.TabIndex = 1;
            this.btnOK.Text = "&OK";
            this.btnOK.Click += new System.EventHandler(this.BtnYes_Click);
            // 
            // pnlTermsAndConditions
            // 
            this.pnlTermsAndConditions.Controls.Add(this.wbTermsAndConditions);
            this.pnlTermsAndConditions.Location = new System.Drawing.Point(12, 12);
            this.pnlTermsAndConditions.Name = "pnlTermsAndConditions";
            this.pnlTermsAndConditions.Size = new System.Drawing.Size(609, 305);
            this.pnlTermsAndConditions.TabIndex = 4;
            // 
            // wbTermsAndConditions
            // 
            this.wbTermsAndConditions.AllowNavigation = false;
            this.wbTermsAndConditions.AllowWebBrowserDrop = false;
            this.wbTermsAndConditions.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.wbTermsAndConditions.Location = new System.Drawing.Point(3, 3);
            this.wbTermsAndConditions.MinimumSize = new System.Drawing.Size(20, 20);
            this.wbTermsAndConditions.Name = "wbTermsAndConditions";
            this.wbTermsAndConditions.Size = new System.Drawing.Size(603, 299);
            this.wbTermsAndConditions.TabIndex = 4;
            this.wbTermsAndConditions.WebBrowserShortcutsEnabled = false;
            // 
            // TermsAndConditionsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(633, 352);
            this.ControlBox = false;
            this.Controls.Add(this.pnlTermsAndConditions);
            this.Controls.Add(this.btnOK);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MinimizeBox = false;
            this.Name = "TermsAndConditionsForm";
            // 
            // 
            // 
            this.RootElement.ApplyShapeToControl = true;
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Terms and Conditions";
            this.Load += new System.EventHandler(this.TermsAndConditionsForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.btnOK)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pnlTermsAndConditions)).EndInit();
            this.pnlTermsAndConditions.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private Telerik.WinControls.UI.RadButton btnOK;
        private Telerik.WinControls.UI.RadPanel pnlTermsAndConditions;
        private System.Windows.Forms.WebBrowser wbTermsAndConditions;
    }
}
