using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public class Summary : SCInquiryModelBase
    {
        //public int SerialNumber { get; set; }
        
        [Display(Name = nameof(Important), ResourceType = typeof(SummaryResx))]
        public bool Important { get; set; }

        [Display(Name = nameof(Description), ResourceType = typeof(SummaryResx))]
        public string Description { get; set; }

        [Display(Name = nameof(AmountPeriod0), ResourceType = typeof(SummaryResx))]
        public decimal AmountPeriod0 { get; set; }

        [Display(Name = nameof(AmountPeriod1), ResourceType = typeof(SummaryResx))]
        public decimal AmountPeriod1 { get; set; }

        [Display(Name = nameof(AmountPeriod2), ResourceType = typeof(SummaryResx))]
        public decimal AmountPeriod2 { get; set; }

        [Display(Name = nameof(AmountPeriod3), ResourceType = typeof(SummaryResx))]
        public decimal AmountPeriod3 { get; set; }

        [Display(Name = nameof(AmountPeriod4), ResourceType = typeof(SummaryResx))]
        public decimal AmountPeriod4 { get; set; }

        [Display(Name = nameof(AmountPeriod5), ResourceType = typeof(SummaryResx))]
        public decimal AmountPeriod5 { get; set; }

        [Display(Name = nameof(AmountPeriod6), ResourceType = typeof(SummaryResx))]
        public decimal AmountPeriod6 { get; set; }

        [Display(Name = nameof(AmountTotal), ResourceType = typeof(SummaryResx))]
        public decimal AmountTotal { get; set; }
    }
}
