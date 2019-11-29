using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Reports;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Reports
{
    public class SCReportRepository<T>
        : BaseReportRepository<T>,
        ISCReportEntity<T>
        where T : SCReport, new()
    {
        #region Constructors
        public SCReportRepository(Context context)
            : base(context, new SCReportMapper<T>(context), SCReport.EntityName) { }

        public SCReportRepository(Context context, IBusinessEntitySession session)
            : base(context, new SCReportMapper<T>(context), session) { }
        #endregion Constructors

        #region BaseReportRepository Implementation
        protected override IBusinessEntity CreateBusinessEntities()
        {
            throw new NotImplementedException();
        }

        public override Guid Execute(T model)
        {
            return base.Execute(model);
        }

        public override T Get(bool applyUserPreferences = true)
        {
            return base.Get(applyUserPreferences);
        }
        #endregion BaseReportRepository Implementation
    }
}
