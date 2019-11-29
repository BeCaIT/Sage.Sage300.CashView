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
using Telerik.WinControls.UI;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    public partial class SCNetGauge : UserControl
    {
        public string FormatString { get; set; } = "n";

        private decimal _in;
        public decimal In
        {
            get => _in;
            set
            {
                _in = value;
                lblInValue.Text = _in.ToString(FormatString);
                lblNetValue.Text = (_in + _out).ToString(FormatString);
            }
        }

        private decimal _out;
        public decimal Out
        {
            get => _out;
            set
            {
                _out = value;
                lblOutValue.Text = _out.ToString(FormatString);
                lblNetValue.Text = (_in + _out).ToString(FormatString);
            }
        }

        public SCNetGauge()
        {
            InitializeComponent();

            //lblInLabel.TextChanged += SetFontSize;
            //lblInLabel.SizeChanged += SetFontSize;
            //lblOutLabel.TextChanged += SetFontSize;
            //lblOutLabel.SizeChanged += SetFontSize;
            //lblNetLabel.TextChanged += SetFontSize;
            //lblNetLabel.SizeChanged += SetFontSize;

            //lblInValue.TextChanged += SetFontSize;
            //lblInValue.SizeChanged += SetFontSize;
            //lblOutValue.TextChanged += SetFontSize;
            //lblOutValue.SizeChanged += SetFontSize;
            lblNetValue.TextChanged += SetFontSize;
            lblNetValue.SizeChanged += SetFontSize;
        }

        private static bool _settingSizes = false;
        private void SetFontSize(object sender, EventArgs e)
        {
            //if (_settingSizes)
            //    return;

            _settingSizes = true;

            try
            {
                float ratio = new float[]
                {
                    //GetRatio(lblInLabel),
                    //GetRatio(lblInValue),
                    //GetRatio(lblOutLabel),
                    //GetRatio(lblOutValue),
                    GetRatio(lblNetLabel),
                    GetRatio(lblNetValue),
                }.Min();

                SetFont(lblInLabel, ratio);
                SetFont(lblInValue, ratio);
                SetFont(lblOutLabel, ratio);
                SetFont(lblOutValue, ratio);
                SetFont(lblNetLabel, ratio);
                SetFont(lblNetValue, ratio);
            }
            catch { }

            _settingSizes = false;
        }

        private float GetRatio(RadLabel label)
        {
            SizeF size = RadControl.GetDpiScaledSize(TextRenderer.MeasureText(label.Text, label.Font));
            float hRatio = (label.Height / size.Height);
            float wRatio = (label.Width / size.Width);

            return (hRatio < wRatio) ? hRatio : wRatio;
        }

        private void SetFont(RadLabel label, float ratio)
        {
            label.Font = new Font(label.Font.FontFamily, label.Font.Size * ratio * 0.80f, label.Font.Style);
        }
    }
}