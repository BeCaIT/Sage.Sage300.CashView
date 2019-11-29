using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class Account : ModelBase
    {
        public long SerialNumber { get; set; }

        [Key]
        [Display(Name = nameof(AccountNumber), ResourceType = typeof(AccountResx))]
        public string AccountNumber { get; set; }

        [Display(Name = nameof(Include), ResourceType = typeof(AccountResx))]
        public bool Include { get; set; }
        //public YesNo Include { get; set; }

        [Display(Name = nameof(AccountExists), ResourceType = typeof(AccountResx))]
        public bool AccountExists { get; set; }

        [Display(Name = nameof(AccountNumberFormatted), ResourceType = typeof(AccountResx))]
        public string AccountNumberFormatted { get; set; }

        [Display(Name = nameof(AccountDescription), ResourceType = typeof(AccountResx))]
        public string AccountDescription { get; set; }

        [Display(Name = nameof(AmountBalance), ResourceType = typeof(AccountResx))]
        public decimal AmountBalance { get; set; }

        [Display(Name = nameof(ProcessCommand), ResourceType = typeof(AccountResx))]
        public int ProcessCommand { get; set; }
    }
}
