using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers
{
    public class AccountMapper<T>
        : ModelMapper<T>
        where T : Account, new()
    {
        public AccountMapper(Context context)
            : base(context)
        {
        }

        public override T Map(IBusinessEntity entity)
        {
            T model = base.Map(entity);

            model.AccountNumber = entity.GetValue<string>(Account.Fields.AccountNumber);
            //model.Include = entity.GetValue<bool>(Account.Fields.Include) ? Models.Enums.YesNo.Yes : Models.Enums.YesNo.No;
            model.Include = entity.GetValue<short>(Account.Fields.Include) == 1;
            model.AccountExists = entity.GetValue<bool>(Account.Fields.AccountExists);
            model.AccountNumberFormatted = entity.GetValue<string>(Account.Fields.AccountNumberFormatted);
            model.AccountDescription = entity.GetValue<string>(Account.Fields.AccountDescription);
            model.AmountBalance = entity.GetValue<decimal>(Account.Fields.AmountBalance);
            model.ProcessCommand = entity.GetValue<int>(Account.Fields.ProcessCommand);

            return model;
        }

        public override void Map(T model, IBusinessEntity entity)
        {
            if (model == null)
                return;

            entity.SetValue(Account.Fields.AccountNumber, model.AccountNumber);
            //entity.SetValue(Account.Fields.Include, model.Include == Models.Enums.YesNo.Yes);
            entity.SetValue(Account.Fields.Include, model.Include ? 1 : 0);
            entity.SetValue(Account.Fields.AccountExists, model.AccountExists);
            entity.SetValue(Account.Fields.AccountNumberFormatted, model.AccountNumberFormatted);
            entity.SetValue(Account.Fields.AccountDescription, model.AccountDescription);
            entity.SetValue(Account.Fields.AmountBalance, model.AmountBalance);
            entity.SetValue(Account.Fields.ProcessCommand, model.ProcessCommand);
        }

        public override void MapKey(T model, IBusinessEntity entity)
        {
            entity.SetValue(Account.Fields.AccountNumber, model.AccountNumber);
        }
    }
}
