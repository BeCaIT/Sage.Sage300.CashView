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
    public class PayeeSummaryRepository<T> :
        SCInquiryRepository<T>,
        IPayeeSummaryEntity<T>
        where T : PayeeSummary, new()
    {
        #region Constructors
        public PayeeSummaryRepository(Context context)
            : base(context, new PayeeSummaryMapper<T>(context), null) { }

        public PayeeSummaryRepository(Context context, IBusinessEntitySession session)
            : base(context, new PayeeSummaryMapper<T>(context), null, session) { }
        #endregion Constructors

        #region Methods
        protected override IBusinessEntity CreateBusinessEntities()
        {
            throw new NotImplementedException();
        }

        public virtual EnumerableResponse<T> GetAR(PageOptions<T> pageOptions)
        {
            EnumerableResponse<T> result = new EnumerableResponse<T>();

            result.Items = ApplicationData.ARSummary.Select(a =>
            new T
            {
                Ranking = a.Ranking,
                PayeeNumber = a.PayeeNumber,
                Name = a.Name,
                CurrencyCode = a.CurrencyCode,
                CreditLimit = a.CreditLimit,
                CreditLimitString = a.CreditLimitString,
                HighestBalance = a.HighestBalance,
                OutstandingBalance = a.OutstandingBalance,
                //
                UIOptions = UIOptions
            });
            result.TotalResultsCount = 11;

            return result;
        }

        public virtual EnumerableResponse<T> GetAP(PageOptions<T> pageOptions)
        {
            EnumerableResponse<T> result = new EnumerableResponse<T>();

            result.Items = ApplicationData.APSummary.Select(a =>
            new T
            {
                Ranking = a.Ranking,
                PayeeNumber = a.PayeeNumber,
                Name = a.Name,
                CurrencyCode = a.CurrencyCode,
                CreditLimit = a.CreditLimit,
                CreditLimitString = a.CreditLimitString,
                HighestBalance = a.HighestBalance,
                OutstandingBalance = a.OutstandingBalance,
                //
                UIOptions = UIOptions
            });
            result.TotalResultsCount = 11;

            return result;
        }
        #endregion
    }
}