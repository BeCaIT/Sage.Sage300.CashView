using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository
{
    public class BalanceRepository<T>
        : InquiryRepository<T>,
        IBalanceEntity<T>
        where T : Models.Balance, new()
    {
        #region Constructors
        public BalanceRepository(Context context)
            : base(context, new BalanceMapper<T>(context), null) { }

        public BalanceRepository(Context context, IBusinessEntitySession session)
            : base(context, new BalanceMapper<T>(context), null, session) { }
        #endregion Constructors

        protected override IBusinessEntity CreateBusinessEntities()
            => OpenEntity(Models.Balance.EntityName);
    }
}
