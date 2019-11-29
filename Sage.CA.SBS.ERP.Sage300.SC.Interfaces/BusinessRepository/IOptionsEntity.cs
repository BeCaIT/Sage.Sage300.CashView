using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Repository;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Repository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository
{
    public interface IOptionsEntity<T>
        : IBusinessRepository<T>,
        ISecurity
        where T : Options, new()
    {
        T SendTestEmail(T model);
        T UpdateCalculatedFields(T model);

        EnumerableResponse<Account> GetAccounts(int pageNumber, int pageSize);
    }
}
