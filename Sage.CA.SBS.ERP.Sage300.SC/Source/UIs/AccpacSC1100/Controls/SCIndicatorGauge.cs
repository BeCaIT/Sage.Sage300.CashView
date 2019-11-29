using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Telerik.WinControls;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    public partial class SCIndicatorGauge : UserControl
    {
        private RadToolTip _toolTip = new RadToolTip();

        public string FormatString { get; set; } = "n";

        public decimal Value
        {
            get => arrIndicator.Value;
            set
            {
                arrIndicator.Value = value;
                lblIndicator.Text = value.ToString(FormatString);
            }
        }

        public decimal BreakPoint
        {
            get => arrIndicator.BreakPoint;
            set => arrIndicator.BreakPoint = value;
        }

        [Browsable(true)]
        public string ToolTip { get; set; }

        public SCIndicatorGauge()
        {
            InitializeComponent();

            lblIndicator.Font = new Font(lblIndicator.Font, FontStyle.Bold);
            lblIndicator.MouseHover += ShowToolTip;

            arrIndicator.MouseHover += ShowToolTip;
        }

        private void ShowToolTip(object sender, EventArgs e)
        {
            _toolTip.Show(ToolTip, (Control)sender);           
        }
    }
}