using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Utilities;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Reports;
using Sage.CA.SBS.ERP.Sage300.Core.Cache;
using Sage.CA.SBS.ERP.Sage300.SC.Data;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Reports;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers.Reports
{
    public class SCReportMapper<T>
        : IReportMapper<T>
        where T : SCReport, new()
    {
        #region Private variables
        private Context _context;
        #endregion Private variables

        #region Constructors
        public SCReportMapper(Context context)
            => _context = context;
        #endregion Constructors

        //private static string _cacheKey = "SCData";

        #region IReportMapper
        public Report Map(T model)
        {
            ApplicationData applicationData = null;// CacheHelper.Get<ApplicationData>(_cacheKey);
            using (IDashboardEntity<Dashboard> dashboardEntity = Helper.Resolve<IDashboardEntity<Dashboard>>(_context))
                applicationData = (dashboardEntity as DashboardRepository<Dashboard>).ApplicationData;

            var report = new Report
            {
                Context = _context,
                ProgramId = "SC1100",
                MenuId = "SC1100",
                Name = model.Name
            };

            //
            //// Set Parameters
            switch (model.Name)
            {
                case "SCSUM01":
                    report.Parameters.Add(new Parameter
                    {
                        Id = "FSCYEAR",
                        Value = applicationData.CurrentYear,
                    });
                    report.Parameters.Add(new Parameter
                    {
                        Id = "FSCPERD",
                        Value = applicationData.CurrentPeriod.ToString(),
                    });
                    report.Parameters.Add(new Parameter
                    {
                        Id = "FSCSTART",
                        Value = applicationData.CurrentYearStartDate.ToString("yyyyMMdd"),
                    });
                    break;

                case "SCSUM03":
                case "SCCABK":
                    report.Parameters.Add(new Parameter
                    {
                        Id = "FSCYEAR",
                        Value = applicationData.CurrentYear,
                    });
                    report.Parameters.Add(new Parameter
                    {
                        Id = "FSCPERD",
                        Value = applicationData.CurrentPeriod.ToString(),
                    });
                    break;

                default:
                    break;
            }

            return report;
        }

        #endregion IReportMapper
    }
}
