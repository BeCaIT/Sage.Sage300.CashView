using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Design;
using Telerik.WinControls.UI;
using Telerik.Charting;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages
{
    [ToolboxItem(true)]
    [ComplexBindingProperties("DataSource", "DataMember")]
    public partial class SCPayeeSummary : UserControl
    {
        [Browsable(true)]
        [Category("Data")]
        [DefaultValue(null)]
        [RefreshProperties(RefreshProperties.Repaint)]
        [AttributeProvider(typeof(IListSource))]
        public object DataSource
        {
            get => grdPayeeSummary.DataSource;
            set
            {
                string dataMember = grdPayeeSummary.DataMember;
                grdPayeeSummary.DataSource = value;
                ////
                //// Fix radGridView losing datamember
                ////
                grdPayeeSummary.DataMember = dataMember;
            }
        }

        [Browsable(true)]
        [Category("Data")]
        [DefaultValue("")]
        [Editor("System.Windows.Forms.Design.DataMemberListEditor, System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", typeof(UITypeEditor))]
        public string DataMember
        {
            get => grdPayeeSummary.DataMember;
            set => grdPayeeSummary.DataMember = value;
        }

        private string _formatString = "n";
        public string FormatString
        {
            get => _formatString;
            set
            {
                if (value == null)
                    return;

                _formatString = value;

                string internalFormatString 
                    = "{0:" 
                    + (_formatString.EndsWith(";\"\"") ? _formatString : _formatString + ";\"\"")
                    + "}";

                //
                //// Format Grid
                grdPayeeSummary.Columns["HighestBalance"].FormatString = internalFormatString;
                grdPayeeSummary.Columns["OutstandingBalance"].FormatString = internalFormatString;

                //// Format Charts
                chtPayeeSummary.Axes[1].LabelFormat = internalFormatString;
                foreach (var series in chtPayeeSummary.Series)
                    series.LabelFormat = internalFormatString;
            }
        }

        public string PayeeHeaderText
        {
            get => grdPayeeSummary.Columns["PayeeNumber"].HeaderText;
            set => grdPayeeSummary.Columns["PayeeNumber"].HeaderText = value;
        }

        public SCPayeeSummary()
        {
            InitializeComponent();
        }

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            //
            //// Work-around for radChartView losing datasource
            chtPayeeSummary.DataSource = grdPayeeSummary.DataSource;
            foreach (var series in chtPayeeSummary.Series)
            {
                series.DataSource = grdPayeeSummary.DataSource;
                series.DataMember = grdPayeeSummary.DataMember;
            }

            //
            ////
            chtPayeeSummary.View.Margin = new Padding(20);
        }

        private void ChtPayeeSummary_LabelFormatting(object sender, ChartViewLabelFormattingEventArgs e)
        {
            e.LabelElement.BackColor = Color.Transparent;
            e.LabelElement.BorderWidth = 0;

            //
            //// Work-around to display label on the right
            DataPoint dataPoint = (e.LabelElement.Parent as DataPointElement).DataPoint;
            if (dataPoint is CategoricalDataPoint)
            {
                BarLabelElement labelElement = (e.LabelElement as BarLabelElement);
                RadRect labelLayoutSlot = labelElement.GetLayoutSlot(); 
                labelElement.PositionOffset = new PointF(
                    (float)dataPoint.LayoutSlot.Width / 2 + (float)labelLayoutSlot.Width / 2, 
                    (float)dataPoint.LayoutSlot.Height / 2 + (float)labelLayoutSlot.Height / 2 + 6f);
            }
        }
    }
}
