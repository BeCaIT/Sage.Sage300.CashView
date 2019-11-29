using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Enums.ExportImport;
using Sage.CA.SBS.ERP.Sage300.Common.Models.ExportImport;
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
    public class ForecastEntryRepository<T>
        : FlatRepository<T>,
        IForecastEntryEntity<T>
        where T : ForecastEntry, new()
    {
        #region Constructors
        public ForecastEntryRepository(Context context)
            : base(context, new ForecastEntryMapper<T>(context), ActiveFilter) { }

        public ForecastEntryRepository(Context context, IBusinessEntitySession session)
            : base(context, new ForecastEntryMapper<T>(context), ActiveFilter, session) { }
        #endregion Constructors

        protected override IBusinessEntity CreateBusinessEntities()
            => OpenEntity(ForecastEntry.EntityName);

        protected override Expression<Func<T, bool>> GetUpdateExpression(T model)
            => (m =>
            m.RecordType == model.RecordType
            && m.Source == model.Source
            && m.CustomerVendor == model.CustomerVendor
            && m.DocumentNumber == model.DocumentNumber
            && m.PaymentNumber == model.PaymentNumber);

        private static Expression<Func<T, bool>> ActiveFilter
            => (m => m.Source == "SC");

        public override EnumerableResponse<T> Get(Expression<Func<T, bool>> filter = null, OrderBy orderBy = null)
        {
            var res = base.Get(filter, orderBy);
            return res;// base.Get(filter, orderBy);
        }

        public override EnumerableResponse<T> Get(int currentPageNumber, int pageSize, Expression<Func<T, bool>> filter = null, OrderBy orderBy = null)
        {
            var res = base.Get(currentPageNumber, pageSize, filter, orderBy);
            return res;// base.Get(currentPageNumber, pageSize, filter, orderBy);
        }

        public override EnumerableResponse<T> Get(PageOptions<T> pageOptions)
        {
            var res = base.Get(pageOptions);
            return res; //base.Get(pageOptions);
        }

        public virtual T Create()
        {
            IBusinessEntity businessEntity = CreateBusinessEntities();
            businessEntity.GenerateRecord(false);
            return Mapper.Map(businessEntity);
        }
    }
}
