using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
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
    public class SummaryRepository<T> :
        SCInquiryRepository<T>,
        ISummaryEntity<T>
        where T : Summary, new()
    {
        #region Constructors
        public SummaryRepository(Context context)
            : base(context, new SummaryMapper<T>(context), null) { }

        public SummaryRepository(Context context, IBusinessEntitySession session)
            : base(context, new SummaryMapper<T>(context), null, session) { }
        #endregion Constructors

        #region Methods
        protected override IBusinessEntity CreateBusinessEntities()
        {
            throw new NotImplementedException();
        }

        public override EnumerableResponse<T> Get(T model, PageOptions<T> pageOptions)
        {
            Refresh();
            return this.Get(pageOptions);
        }

        public override EnumerableResponse<T> Get(PageOptions<T> pageOptions)
        {
            EnumerableResponse<T> result = new EnumerableResponse<T>();

            //int i = 0;

            //result.Items = InternalDataRepository.GetApplicationData(Context, Session).CashFlowSummary.Select(c =>
            result.Items = ApplicationData.CashFlowSummary.Select(c =>
            new T
            {
                //SerialNumber = i++,
                Important = c.Important,
                Description = c.Description,
                AmountPeriod0 = c.AmountPeriod0,
                AmountPeriod1 = c.AmountPeriod1,
                AmountPeriod2 = c.AmountPeriod2,
                AmountPeriod3 = c.AmountPeriod3,
                AmountPeriod4 = c.AmountPeriod4,
                AmountPeriod5 = c.AmountPeriod5,
                AmountPeriod6 = c.AmountPeriod6,
                AmountTotal = c.AmountTotal,
                //
                UIOptions = UIOptions
            }).AsEnumerable();
            result.TotalResultsCount = 13;

            return result;
        }
        #endregion
    }
}
