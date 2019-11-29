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
    public class LoanRepository<T>
        : FlatRepository<T>,
        ILoanEntity<T>
        where T : Loan, new()
    {
        #region Constructors
        public LoanRepository(Context context)
            : base(context, new LoanMapper<T>(context), ActiveFilter) { }

        public LoanRepository(Context context, IBusinessEntitySession session)
            : base(context, new LoanMapper<T>(context), ActiveFilter, session) { }
        #endregion Constructors

        protected override IBusinessEntity CreateBusinessEntities()
            => OpenEntity(Loan.EntityName);

        protected override Expression<Func<T, bool>> GetUpdateExpression(T model)
            => entity => entity.LoanNumber == model.LoanNumber;

        private static Expression<Func<T, bool>> ActiveFilter
            => null;

        public override EnumerableResponse<T> Get(int currentPageNumber, int pageSize, Expression<Func<T, bool>> filter = null, OrderBy orderBy = null)
        {
            EnumerableResponse<T> enumerableResponse = base.Get(currentPageNumber, pageSize, filter, orderBy);

            string termsAndConditions = string.Empty;

            using (var dashboardRepo = (DashboardRepository<Dashboard>)Resolve<IDashboardEntity<Dashboard>>())
                termsAndConditions = dashboardRepo.ApplicationData.TermsAndConditions;

            foreach (var item in enumerableResponse.Items)
                item.TermsAndConditions = termsAndConditions;

            return enumerableResponse;
        }
    }
}
