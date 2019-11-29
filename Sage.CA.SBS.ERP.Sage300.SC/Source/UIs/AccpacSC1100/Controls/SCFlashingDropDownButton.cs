using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms;
using Telerik.WinControls.UI;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    public class SCFlashingDropDownButton : RadDropDownButton
    {
        private System.Timers.Timer _timer;

        public SCFlashingDropDownButton()
        {
            //
            //// Capture this event align the drop-down to the right
            DropDownOpening += SCFlashingDropDownButton_DropDownOpening;

            //
            //// Auto Font Size
            SizeChanged += SetFontSize;
            TextChanged += SetFontSize;

            //
            _timer = new System.Timers.Timer(500);
            _timer.Elapsed += Timer_Elapsed;
            _timer.Start();
        }

        #region IDisposable Support
        bool _disposed = false;

        protected override void Dispose(bool disposing)
        {
            if (_disposed)
                return;

            if (disposing)
                _timer.Dispose();

            _disposed = true;

            base.Dispose(disposing);
        }
        #endregion IDisposable Support

        private void Timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            try
            {
                if (ForeColor == Color.Red)
                    ForeColor = Color.Black;
                else
                    ForeColor = Color.Red;
            }
            catch { }
        }

        private void SCFlashingDropDownButton_DropDownOpening(object sender, EventArgs e)
        {
            //
            //// Right align drop-down box
            var args = e as RadPopupOpeningEventArgs;
            var popupSize = DropDownButtonElement.DropDownMenu.Size;
            var x = args.CustomLocation.X - (popupSize.Width - Width);
            args.CustomLocation = new Point(x, args.CustomLocation.Y);
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

        //private void InitializeComponent()
        //{
        //    ((System.ComponentModel.ISupportInitialize)(this)).BeginInit();
        //    this.SuspendLayout();
        //    ((System.ComponentModel.ISupportInitialize)(this)).EndInit();
        //    this.ResumeLayout(false);

        //}
    }
}
