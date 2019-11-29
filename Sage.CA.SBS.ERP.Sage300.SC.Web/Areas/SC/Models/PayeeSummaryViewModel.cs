using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Models
{
    public class PayeeSummaryViewModel<T>
        : SCInquiryViewModelBase<T>
        where T : PayeeSummary, new()
    {
    }
}