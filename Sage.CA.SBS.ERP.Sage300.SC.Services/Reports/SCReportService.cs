using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Services.Base;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Reports;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Services.Reports
{
    public class SCReportService<T>
        : BaseReportService<T, ISCReportEntity<T>>,
        ISCReportService<T>
        where T : SCReport, new()
    {
        #region Constructors
        public SCReportService(Context context)
            : base(context) { }
        #endregion Constructors
    }
}
