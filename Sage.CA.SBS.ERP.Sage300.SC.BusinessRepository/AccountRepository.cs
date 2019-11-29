using ACCPAC.Advantage;
using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Utilities;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Utilities;
using Sage.CA.SBS.ERP.Sage300.Core.Cache;
using Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository
{
    public class AccountRepository<T>
        : FlatRepository<T>,
        IAccountEntity<T>
        where T : Account, new()
    {
        #region Constructors
        public AccountRepository(Context context)
            : base(context, new AccountMapper<T>(context), null) { }

        public AccountRepository(Context context, IBusinessEntitySession session)
            : base(context, new AccountMapper<T>(context), null, session) { }
        #endregion Constructors

        private IBusinessEntity _businessEntity;

        protected override IBusinessEntity CreateBusinessEntities()
        {
            _businessEntity = OpenEntity(Account.EntityName);
            return _businessEntity;
        }

        protected override Expression<Func<T, bool>> GetUpdateExpression(T model)
            => (m => m.AccountNumber == model.AccountNumber);

        internal void Process()
        {
            IBusinessEntity businessEntity = CreateBusinessEntities();
            businessEntity.Process();
        }

        public override T Save(T model)
        {
            T result = base.Save(model);
            _businessEntity.Post();

            return result;
        }
    }
}
