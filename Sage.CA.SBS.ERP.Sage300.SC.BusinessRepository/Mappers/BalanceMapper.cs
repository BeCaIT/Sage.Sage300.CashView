using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.GL.Models.Enums;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers
{
    public class BalanceMapper<T>
        : ModelMapper<T>
        where T : Balance, new()
    {
        public BalanceMapper(Context context)
            : base(context) { }

        public override T Map(IBusinessEntity entity)
        {
            T model = base.Map(entity);

            model.RecordType = entity.GetValue<RecordType>(Balance.Fields.RecordType);
            model.GroupCategory = entity.GetValue<GroupCategory>(Balance.Fields.GroupCategory);
            model.FiscalYear = entity.GetValue<string>(Balance.Fields.FiscalYear);
            model.BeginingBalance = entity.GetValue<decimal>(Balance.Fields.BeginingBalance);
            model.NetPeriod1 = entity.GetValue<decimal>(Balance.Fields.NetPeriod1);
            model.NetPeriod2 = entity.GetValue<decimal>(Balance.Fields.NetPeriod2);
            model.NetPeriod3 = entity.GetValue<decimal>(Balance.Fields.NetPeriod3);
            model.NetPeriod4 = entity.GetValue<decimal>(Balance.Fields.NetPeriod4);
            model.NetPeriod5 = entity.GetValue<decimal>(Balance.Fields.NetPeriod5);
            model.NetPeriod6 = entity.GetValue<decimal>(Balance.Fields.NetPeriod6);
            model.NetPeriod7 = entity.GetValue<decimal>(Balance.Fields.NetPeriod7);
            model.NetPeriod8 = entity.GetValue<decimal>(Balance.Fields.NetPeriod8);
            model.NetPeriod9 = entity.GetValue<decimal>(Balance.Fields.NetPeriod9);
            model.NetPeriod10 = entity.GetValue<decimal>(Balance.Fields.NetPeriod10);
            model.NetPeriod11 = entity.GetValue<decimal>(Balance.Fields.NetPeriod11);
            model.NetPeriod12 = entity.GetValue<decimal>(Balance.Fields.NetPeriod12);
            model.NetPeriod13 = entity.GetValue<decimal>(Balance.Fields.NetPeriod13);
            model.NetPeriod14 = entity.GetValue<decimal>(Balance.Fields.NetPeriod14);
            model.NetPeriod15 = entity.GetValue<decimal>(Balance.Fields.NetPeriod15);
            model.BalancePeriod1 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod1);
            model.BalancePeriod2 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod2);
            model.BalancePeriod3 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod3);
            model.BalancePeriod4 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod4);
            model.BalancePeriod5 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod5);
            model.BalancePeriod6 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod6);
            model.BalancePeriod7 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod7);
            model.BalancePeriod8 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod8);
            model.BalancePeriod9 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod9);
            model.BalancePeriod10 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod10);
            model.BalancePeriod11 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod11);
            model.BalancePeriod12 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod12);
            model.BalancePeriod13 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod13);
            model.BalancePeriod14 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod14);
            model.BalancePeriod15 = entity.GetValue<decimal>(Balance.Fields.BalancePeriod15);
            model.NetYear = entity.GetValue<decimal>(Balance.Fields.NetYear);
            model.NetYearToDate = entity.GetValue<decimal>(Balance.Fields.NetYearToDate);
            model.BalanceYearToDate = entity.GetValue<decimal>(Balance.Fields.BalanceYearToDate);

            return model;
        }

        public override void Map(T model, IBusinessEntity entity)
        {
            throw new NotImplementedException();
        }

        public override void MapKey(T model, IBusinessEntity entity)
        {
            throw new NotImplementedException();
        }
    }
}
