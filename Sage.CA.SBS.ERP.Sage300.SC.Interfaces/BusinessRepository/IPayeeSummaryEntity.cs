using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Repository;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository
{
    public interface IPayeeSummaryEntity<T>
        : ISCInquiryRepository<T>
        where T : PayeeSummary, new()
    {
        EnumerableResponse<T> GetAR(PageOptions<T> pageOptions);
        EnumerableResponse<T> GetAP(PageOptions<T> pageOptions);
    }
}
