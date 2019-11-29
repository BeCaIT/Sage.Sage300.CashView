using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    public class SCIndicatorArrow : Control
    {
        public Color PositiveColor { get; set; } = Color.GreenYellow;
        public Color NegativeColor { get; set; } = Color.Red;

        public decimal BreakPoint { get; set; }
        public decimal Value { get; set; }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            PointF pointMidle = new PointF(e.ClipRectangle.Width / 2, e.ClipRectangle.Height / 2);
            float delta = ((e.ClipRectangle.Width < e.ClipRectangle.Height)
                        ? e.ClipRectangle.Width
                        : e.ClipRectangle.Height)
                        * 0.45f;

            PointF point1;
            PointF point2;
            PointF point3;

            SolidBrush brush;

            if (Value >= BreakPoint)
            {
                point1 = new PointF(pointMidle.X, pointMidle.Y - delta);
                point2 = new PointF(pointMidle.X + delta, pointMidle.Y + delta);
                point3 = new PointF(pointMidle.X - delta, pointMidle.Y + delta);
                brush = new SolidBrush(PositiveColor);
            }
            else
            {
                point1 = new PointF(pointMidle.X, pointMidle.Y + delta);
                point2 = new PointF(pointMidle.X + delta, pointMidle.Y - delta);
                point3 = new PointF(pointMidle.X - delta, pointMidle.Y - delta);
                brush = new SolidBrush(NegativeColor);
            }

            e.Graphics.FillPolygon(brush, new PointF[] { point1, point2, point3 });

            brush.Dispose();
        }

        private void InitializeComponent()
        {
            this.SuspendLayout();
            this.ResumeLayout(false);

        }
    }
}
