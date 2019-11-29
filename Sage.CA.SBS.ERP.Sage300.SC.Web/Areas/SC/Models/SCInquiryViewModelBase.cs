using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.SC.Resources;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Models
{
    public abstract class SCInquiryViewModelBase<T>
        : ViewModelBase<T>
        where T : ModelBase, new()
    {
        public string ThresholdMessage { get; } = SCCommonResx.ThresholdBreached;
    }
}