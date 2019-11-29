using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models.Enums
{
    public enum Country
    {
        [EnumValue(nameof(Others), typeof(CountryResx))]
        Others = 0,

        [EnumValue(nameof(Singapore), typeof(CountryResx))]
        Singapore = 702,

        [EnumValue(nameof(Malaysia), typeof(CountryResx))]
        Malaysia = 458,
    }
}
