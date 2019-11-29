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
using Sage.CA.SBS.ERP.Sage300.SC.Data;
using Telerik.WinControls;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages
{
    [ToolboxItem(true)]
    [ComplexBindingProperties("DataSource", "DataMember")]
    public partial class SCPageDashboard : UserControl
    {
        [Browsable(true)]
        [Category("Data")]
        [DefaultValue(null)]
        [RefreshProperties(RefreshProperties.Repaint)]
        [AttributeProvider(typeof(IListSource))]
        public object DataSource
        {
            get => bsDashboard.DataSource;
            set => bsDashboard.DataSource = value;
        }

        [Browsable(true)]
        [Category("Data")]
        [DefaultValue("")]
        [Editor("System.Windows.Forms.Design.DataMemberListEditor, System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", typeof(UITypeEditor))]
        public string DataMember
        {
            get => bsDashboard.DataMember;
            set => bsDashboard.DataMember = value;
        }

        private string _formatString = "n";
        public string FormatString
        {
            get => _formatString;
            set
            {
                _formatString = value;

                string internalFormatString = "{0:" + _formatString + "}";

                //
                //// Format Gauges (those that are not support databining)
                rgDSO_labelValue.LabelFormat
                    = rgDPO_labelValue.LabelFormat
                    = rgCCC_labelValue.LabelFormat
                    = _formatString;

                //
                //// Format Charts
                foreach (var axis in chtCashFlow.Axes)
                    axis.LabelFormat = internalFormatString;
                foreach (var series in chtCashFlow.Series)
                    series.LabelFormat = internalFormatString;
            }
        }

        public SCPageDashboard()
        {
            InitializeComponent();
        }

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            //
            //// Work-around for radChartView properties not serialized in desinger
            chtCashFlow.ChartElement.LegendPosition = LegendPosition.Bottom;

            //
            //// Work-around for radChartView losing datasource
            chtCashFlow.DataSource = bsDashboard.DataSource;

            //
            ////
            chtCashFlow.View.Margin = new Padding(20);

            //
            //// Setup Annotation
            chtCashFlow.Annotations.Add(
                new CartesianGridLineAnnotation
                {
                    Axis = chtCashFlow.Axes[1] as CartesianAxis,
                    Value = ApplicationData.Current.Threshold
                });

            btnRefresh.Visible = ApplicationData.Current.HasProcessRight;
        }

        private void BtnPrint_Click(object sender, EventArgs e)
        {
            Dictionary<string, string> parameters = new Dictionary<string, string>();
            parameters.Add("FSCYEAR", ApplicationData.Current.CurrentYear);
            parameters.Add("FSCPERD", ApplicationData.Current.CurrentPeriod.ToString());
            parameters.Add("FSCSTART", ApplicationData.Current.CurrentYearStartDate.ToString("yyyyMMdd"));

            Sage300Application.Current.PrintReport("SCSUM01", Handle.ToInt32(), parameters);
        }

        private void ChtCashFlow_LabelFormatting(object sender, ChartViewLabelFormattingEventArgs e)
        {            
            e.LabelElement.BackColor = Color.Transparent;
            e.LabelElement.ForeColor = e.Series.ForeColor;
        }

        private void BtnRefresh_Click(object sender, EventArgs e)
        {
            Sage300Application.Current.ReProcessData();
        }

        private void BsDashboard_CurrentChanged(object sender, EventArgs e)
        {
            (chtCashFlow.Annotations[0] as CartesianGridLineAnnotation).Value = ApplicationData.Current.Threshold;

            //
            //// Color gauges
            var applicationData = (bsDashboard.Current as ApplicationData);
            if (applicationData.DSO > applicationData.DSOMedian)
                rgDSO_value.BackColor = rgDSO_value.BackColor2 = Color.Red;
            if (applicationData.DPO > applicationData.DPOMedian)
                rgDPO_value.BackColor = rgDPO_value.BackColor2 = Color.Red;
            if (applicationData.CCC > applicationData.CCCMedian)
                rgCCC_value.BackColor = rgCCC_value.BackColor2 = Color.Red;
        }

        private void BsDashboard_BindingComplete(object sender, BindingCompleteEventArgs e)
        {
        }
    }
}
