using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Services.Base;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Services
{
    public class DataEntityService<T>
        : FlatService<T, IDataEntity<T>>,
        IDataService<T>
        where T : Models.Data, new()
    {
        public DataEntityService(Context context)
            : base(context)
        {

        }
    }
}
