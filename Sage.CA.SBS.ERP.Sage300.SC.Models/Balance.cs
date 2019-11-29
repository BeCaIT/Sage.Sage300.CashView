using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.GL.Models.Enums;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class Balance : ModelBase
    {
        public RecordType RecordType { get; set; }
        public GroupCategory GroupCategory { get; set; }
        public string FiscalYear { get; set; }
        public decimal BeginingBalance { get; set; }
        public decimal NetPeriod1 { get; set; }
        public decimal NetPeriod2 { get; set; }
        public decimal NetPeriod3 { get; set; }
        public decimal NetPeriod4 { get; set; }
        public decimal NetPeriod5 { get; set; }
        public decimal NetPeriod6 { get; set; }
        public decimal NetPeriod7 { get; set; }
        public decimal NetPeriod8 { get; set; }
        public decimal NetPeriod9 { get; set; }
        public decimal NetPeriod10 { get; set; }
        public decimal NetPeriod11 { get; set; }
        public decimal NetPeriod12 { get; set; }
        public decimal NetPeriod13 { get; set; }
        public decimal NetPeriod14 { get; set; }
        public decimal NetPeriod15 { get; set; }
        public decimal BalancePeriod1 { get; set; }
        public decimal BalancePeriod2 { get; set; }
        public decimal BalancePeriod3 { get; set; }
        public decimal BalancePeriod4 { get; set; }
        public decimal BalancePeriod5 { get; set; }
        public decimal BalancePeriod6 { get; set; }
        public decimal BalancePeriod7 { get; set; }
        public decimal BalancePeriod8 { get; set; }
        public decimal BalancePeriod9 { get; set; }
        public decimal BalancePeriod10 { get; set; }
        public decimal BalancePeriod11 { get; set; }
        public decimal BalancePeriod12 { get; set; }
        public decimal BalancePeriod13 { get; set; }
        public decimal BalancePeriod14 { get; set; }
        public decimal BalancePeriod15 { get; set; }
        public decimal NetYear { get; set; }
        public decimal NetYearToDate { get; set; }
        public decimal BalanceYearToDate { get; set; }
    }
}
