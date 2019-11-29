using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Repository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository
{
    public interface IDataEntity<T>
        : IBusinessRepository<T>,
        ISecurity
        where T : Models.Data, new()
    {
    }
}
