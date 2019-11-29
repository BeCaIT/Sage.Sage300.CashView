using Sage.CA.SBS.ERP.Sage300.SC.Data;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Telerik.WinControls;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100
{
    public partial class TermsAndConditionsForm : Telerik.WinControls.UI.RadForm
    {
        public TermsAndConditionsForm()
        {
            InitializeComponent();
        }

        private void BtnNo_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void BtnYes_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void TermsAndConditionsForm_Load(object sender, EventArgs e)
        {
            var text = $"<html><body style=\"background: #f0f0f0\">{ApplicationData.Current.TermsAndConditions}</body></html>";
            wbTermsAndConditions.DocumentText = text;
        }
    }
}
