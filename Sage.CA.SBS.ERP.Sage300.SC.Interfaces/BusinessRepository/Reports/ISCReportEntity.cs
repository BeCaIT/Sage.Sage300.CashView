using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Repository.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Reports;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository.Reports
{
    public interface ISCReportEntity<T>
        : IReportRepository<T>
        where T : SCReport, new()
    {
    }
}
