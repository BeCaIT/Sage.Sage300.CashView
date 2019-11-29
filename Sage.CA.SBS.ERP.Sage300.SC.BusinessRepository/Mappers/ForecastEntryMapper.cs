using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers
{
    public class ForecastEntryMapper<T>
        : ModelMapper<T>
        where T : ForecastEntry, new()
    {
        #region Constructors
        public ForecastEntryMapper(Context context)
            : base(context) { }
        #endregion Constructors

        #region Mappings
        public override T Map(IBusinessEntity entity)
        {
            T model = base.Map(entity);

            model.RecordType = entity.GetValue<RecordType>(ForecastEntry.Fields.RecordType);
            model.Source = entity.GetValue<string>(ForecastEntry.Fields.Source);
            model.CustomerVendor = entity.GetValue<string>(ForecastEntry.Fields.CustomerVendor);
            model.DocumentNumber = entity.GetValue<string>(ForecastEntry.Fields.DocumentNumber);
            model.PaymentNumber = entity.GetValue<decimal>(ForecastEntry.Fields.PaymentNumber);
            model.EffectiveDate = entity.GetValue<DateTime>(ForecastEntry.Fields.EffectiveDate);
            model.Description = entity.GetValue<string>(ForecastEntry.Fields.Description);
            model.AmountDue = entity.GetValue<decimal>(ForecastEntry.Fields.AmountDue);

            return model;
        }

        public override void Map(T model, IBusinessEntity entity)
        {
            entity.SetValue(ForecastEntry.Fields.RecordType, RecordType.Posted);
            entity.SetValue(ForecastEntry.Fields.Source, model.Source);
            entity.SetValue(ForecastEntry.Fields.CustomerVendor, model.CustomerVendor);
            entity.SetValue(ForecastEntry.Fields.DocumentNumber, model.DocumentNumber);
            entity.SetValue(ForecastEntry.Fields.PaymentNumber, model.PaymentNumber);
            entity.SetValue(ForecastEntry.Fields.EffectiveDate, model.EffectiveDate);
            entity.SetValue(ForecastEntry.Fields.Description, model.Description);
            entity.SetValue(ForecastEntry.Fields.AmountDue, model.Inflow - model.Outflow);
        }

        public override void MapKey(T model, IBusinessEntity entity)
        {
            entity.SetValue(ForecastEntry.Fields.RecordType, RecordType.Posted);
            entity.SetValue(ForecastEntry.Fields.Source, model.Source);
            entity.SetValue(ForecastEntry.Fields.CustomerVendor, model.CustomerVendor);
            entity.SetValue(ForecastEntry.Fields.DocumentNumber, model.DocumentNumber);
            entity.SetValue(ForecastEntry.Fields.PaymentNumber, model.PaymentNumber);
        }
        #endregion Mappings
    }
}
