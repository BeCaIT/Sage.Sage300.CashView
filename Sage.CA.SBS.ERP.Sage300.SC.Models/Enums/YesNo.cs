using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models.Enums
{
    public enum YesNo
    {
        [EnumValue(nameof(No), typeof(SCCommonResx))]
        No = 0,

        [EnumValue(nameof(Yes), typeof(SCCommonResx))]
        Yes = 1,
    }
}