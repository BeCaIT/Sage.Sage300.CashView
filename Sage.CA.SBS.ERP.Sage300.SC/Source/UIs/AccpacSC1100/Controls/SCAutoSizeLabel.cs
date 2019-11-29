using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Telerik.WinControls.UI;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    public class SCAutoSizeLabel : RadLabel
    {
        public SCAutoSizeLabel()
            : base()
        {
            SizeChanged += SetFontSize;
            TextChanged += SetFontSize;
        }

        private void SetFontSize(object sender, EventArgs e)
        {
            try
            {
                SizeF size = GetDpiScaledSize(TextRenderer.MeasureText(Text, Font));
                float hRatio = (Height / size.Height);
                float wRatio = (Width / size.Width);
                float ratio = (hRatio < wRatio) ? hRatio : wRatio;

                Font = new Font(Font.FontFamily, (Font.Size * ratio) * 0.80f, Font.Style);
            }
            catch { }
        }

        private void InitializeComponent()
        {
            ((System.ComponentModel.ISupportInitialize)(this)).BeginInit();
            this.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this)).EndInit();
            this.ResumeLayout(false);

        }
    }
}
