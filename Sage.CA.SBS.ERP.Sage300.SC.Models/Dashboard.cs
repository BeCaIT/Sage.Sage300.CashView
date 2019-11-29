using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Reports;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class Dashboard : SCInquiryModelBase
    {
        public decimal QuickRatio { get; set; }
        public decimal QuickRatioBreak { get; set; }
        public decimal CurrentRatio { get; set; }
        public decimal CurrentRatioBreak { get; set; }
        public decimal NetAR { get; set; }
        public decimal NetAP { get; set; }
        public decimal NetOperations
            => NetAR + NetAP;
        public decimal DSO { get; set; }
        public decimal DSOMaximum { get; set; }
        public decimal DSOMedian { get; set; }
        public decimal DPO { get; set; }
        public decimal DPOMaximum { get; set; }
        public decimal DPOMedian { get; set; }
        public decimal CCC { get; set; }
        public decimal CCCMaximum { get; set; }
        public decimal CCCMedian { get; set; }
        public decimal ARC { get; set; }
        public IEnumerable<ChartData> CashFlowChartNetIn { get; set; } = new List<ChartData>().AsEnumerable();
        public IEnumerable<ChartData> CashFlowChartNetOut { get; set; } = new List<ChartData>().AsEnumerable();
        public IEnumerable<ChartData> CashFlowChartEndingBalance { get; set; } = new List<ChartData>().AsEnumerable();
    }
}