using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Web.Controllers.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Models.Reports;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers.Reports
{
    public class ReportsControllerInternal<T, TViewModel, TService>
        : ReportControllerInternal<T, TViewModel, TService>
        where T : SCReport, new()
        where TViewModel : SCReportViewModel<T>, new()
        where TService : ISCReportService<T>
    {
        #region Constructors
        public ReportsControllerInternal(Context context)
            : base(context) { }
        #endregion Constructors
    }
}