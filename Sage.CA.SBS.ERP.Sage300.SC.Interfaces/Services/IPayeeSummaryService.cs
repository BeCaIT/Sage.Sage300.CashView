using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Service;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services
{
    public interface IPayeeSummaryService<T> :
        IInquiryService<T>,
        ISecurityService
        where T : PayeeSummary, new()
    {
        EnumerableResponse<T> GetAR(PageOptions<T> pageOptions);
        EnumerableResponse<T> GetAP(PageOptions<T> pageOptions);

        EnumerableResponse<T> GetAR(T model, PageOptions<T> pageOptions);
        EnumerableResponse<T> GetAP(T model, PageOptions<T> pageOptions);
    }
}
