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
    public class PayeeSummary : SCInquiryModelBase
    {
        [Display(Name = nameof(Ranking), ResourceType = typeof(PayeeSummaryResx))]
        public string Ranking { get; set; }

        [Display(Name = nameof(PayeeNumber), ResourceType = typeof(PayeeSummaryResx))]
        public string PayeeNumber { get; set; }

        [Display(Name = nameof(Name), ResourceType = typeof(PayeeSummaryResx))]
        public string Name { get; set; }

        [Display(Name = nameof(CurrencyCode), ResourceType = typeof(PayeeSummaryResx))]
        public string CurrencyCode { get; set; }

        [Display(Name = nameof(CreditLimit), ResourceType = typeof(PayeeSummaryResx))]
        public decimal CreditLimit { get; set; }

        [Display(Name = nameof(CreditLimitString), ResourceType = typeof(PayeeSummaryResx))]
        public string CreditLimitString { get; set; }

        [Display(Name = nameof(HighestBalance), ResourceType = typeof(PayeeSummaryResx))]
        public decimal HighestBalance { get; set; }

        [Display(Name = nameof(OutstandingBalance), ResourceType = typeof(PayeeSummaryResx))]
        public decimal OutstandingBalance { get; set; }
    }
}
