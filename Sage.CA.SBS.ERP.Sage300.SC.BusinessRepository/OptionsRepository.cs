using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.Exceptions;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Enums;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Enums.ExportImport;
using Sage.CA.SBS.ERP.Sage300.Common.Models.ExportImport;
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
    public class OptionsRepository<T>
        : FlatRepository<T>,
        IOptionsEntity<T>
        where T : Options, new()
    {
        #region Constructors
        public OptionsRepository(Context context)
            : base(context, new OptionsMapper<T>(context), null) { }

        public OptionsRepository(Context context, IBusinessEntitySession session)
            : base(context, new OptionsMapper<T>(context), null, session) { }
        #endregion Constructors

        private IBusinessEntity _businessEntity;

        protected override IBusinessEntity CreateBusinessEntities()
        {
            _businessEntity = OpenEntity(Options.EntityName);
            return _businessEntity;
        }

        protected override Expression<Func<T, bool>> GetUpdateExpression(T model)
        {
            return null;
        }

        public override T GetById<TKey>(TKey key)
        {
            T result = base.FirstOrDefault();
            if (result == null)
            {
                var businessEntity = CreateBusinessEntities();
                businessEntity.GenerateRecord(false);
                result = Mapper.Map(businessEntity);
                result.IsNewLine = true;

                using (AccountRepository<Account> accountsRepo = (AccountRepository<Account>)Resolve<IAccountEntity<Account>>())
                    accountsRepo.Process();
            }

            return result;
        }            

        public override T Save(T model)
        {
            T result = null;

            var businessEntity = CreateBusinessEntities();
            Mapper.Map(model, businessEntity);
            businessEntity.Verify();

            using (IAccountEntity<Account> accountRepo = Resolve<IAccountEntity<Account>>())
                foreach (var account in model.Accounts.Items)
                    accountRepo.Save(account);

            if (model.IsNewLine)
                result = base.Add(model);
            else
                result = base.Save(model);

            return result;
        }

        public T SendTestEmail(T model)
        {
            IBusinessEntity businessEntity = CreateBusinessEntities();
            Mapper.Map(model, businessEntity);
            businessEntity.SetValue<short>(Options.Fields.ProcessCommand, 1);
            businessEntity.Process();

            return Mapper.Map(businessEntity);
        }

        public T UpdateCalculatedFields(T model)
        {
            IBusinessEntity businessEntity = CreateBusinessEntities();
            Mapper.Map(model, businessEntity);
            businessEntity.SetValue(Options.Fields.Country, model.Country, true);
            businessEntity.SetValue(Options.Fields.BRN, model.BRN, true);

            var newModel = Mapper.Map(businessEntity);
            newModel.IsNewLine = model.IsNewLine;
            newModel.ETag = model.ETag;

            if (newModel.Country == Models.Enums.Country.Singapore)
                newModel.BRYear = newModel.BRYearCalculated;

            return newModel;
        }

        public EnumerableResponse<Account> GetAccounts(int pageNumber, int pageSize)
        {
            EnumerableResponse<Account> accounts = null;
            using (IAccountEntity<Account> accountRepo = Resolve<IAccountEntity<Account>>())
                accounts = accountRepo.Get(pageNumber, pageSize);

            int index = pageNumber * pageSize;
            if (accounts != null && accounts.Items != null)
            {
                foreach (var account in accounts.Items)
                    account.SerialNumber = index++;
            }

            return accounts;
        }
    }
}
