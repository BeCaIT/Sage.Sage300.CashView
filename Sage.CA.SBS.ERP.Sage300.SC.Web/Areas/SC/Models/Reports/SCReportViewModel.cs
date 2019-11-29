using Sage.CA.SBS.ERP.Sage300.Common.Web.Models.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Reports;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Models.Reports
{
    public class SCReportViewModel<T>
        : ReportViewModel<T>
        where T : SCReport, new()
    {
    }
}