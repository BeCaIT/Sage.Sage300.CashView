using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Services.Base;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Services
{
    public class ForecastEntryEntityService<T>
        : FlatService<T, IForecastEntryEntity<T>>,
        IForecastEntryService<T>
        where T : ForecastEntry, new()
    {
        #region Constructors
        public ForecastEntryEntityService(Context context)
            : base(context) { }
        #endregion Constructors

        public T Create()
        {
            using (IForecastEntryEntity<T> repo = Resolve<IForecastEntryEntity<T>>())
                return repo.Create();
        }
    }
}
