using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Services.Base;
using Sage.CA.SBS.ERP.Sage300.CS.Interfaces.Services;
using Sage.CA.SBS.ERP.Sage300.CS.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Services
{
    public class OptionsEntityService<T>
        : FlatService<T, IOptionsEntity<T>>,
        IOptionsService<T>
        where T : Options, new()
    {
        #region Constructors
        public OptionsEntityService(Context context)
            : base(context) { }

        public override T GetById<TKey>(TKey key)
        {
            T model = base.GetById<string>(null);
            if (model != null)
                model.CompanyProfile = ResolveService<ICompanyProfileService<CompanyProfile>>()
                    .FirstOrDefault(null, null);

            return model;
        }

        public T SendTestEmail(T model)
        {
            using (IOptionsEntity<T> optionRepo = Resolve<IOptionsEntity<T>>())
                return optionRepo.SendTestEmail(model);
        }

        public T UpdateCalculatedFields(T model)
        {
            using (IOptionsEntity<T> optionRepo = Resolve<IOptionsEntity<T>>())
                return optionRepo.UpdateCalculatedFields(model);
        }
        #endregion ConstructorS

        public EnumerableResponse<Account> GetAccounts(int pageNumber, int pageSize)
        {
            using (IOptionsEntity<T> optionRepo = Resolve<IOptionsEntity<T>>())
                return optionRepo.GetAccounts(pageNumber, pageSize);
        }
    }
}
