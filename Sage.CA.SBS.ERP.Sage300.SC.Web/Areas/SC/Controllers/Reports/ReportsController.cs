using Microsoft.Practices.Unity;
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
    public class ReportsController<T>
        : ReportController<T, SCReportViewModel<T>, 
            ReportsControllerInternal<T, SCReportViewModel<T>, ISCReportService<T>>,
            ISCReportService<T>>
        where T : SCReport, new()
    {
        #region Constructors
        public ReportsController(IUnityContainer container)
            : base(container, 
                  context => new ReportsControllerInternal<T, SCReportViewModel<T>, ISCReportService<T>>(context),
                  "SCDashboardReport") { }
        #endregion Constructors
    }
}