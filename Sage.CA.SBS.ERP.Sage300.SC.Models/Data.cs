using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Reports;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public class Data : ModelBase
    {
        public IEnumerable<Summary> CashFlowSummary { get; set; } = new List<Summary>().AsEnumerable();
    }
}
