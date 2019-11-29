using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Service;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services
{
    public interface IDataService<T>
        : IEntityService<T>,
        ISecurityService
        where T : Models.Data, new()
    {
    }
}
