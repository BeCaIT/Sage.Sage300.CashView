using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models.Enums
{
    public enum LoanStatus
    {
        [EnumValue(nameof(New), typeof(LoanStatusResx))]
        New = 0,

        [EnumValue(nameof(Submitted), typeof(LoanStatusResx))]
        Submitted = 1,

        [EnumValue(nameof(Cancelled), typeof(LoanStatusResx))]
        Cancelled = 2,

        [EnumValue(nameof(Rejected), typeof(LoanStatusResx))]
        Rejected = 3,

        [EnumValue(nameof(Approved), typeof(LoanStatusResx))]
        Approved = 4
    }
}
