using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Services.Base;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Services
{
    public class LoanEntityService<T>
        : FlatService<T, ILoanEntity<T>>,
        ILoanService<T>
        where T : Loan, new()
    {
        #region Constructors
        public LoanEntityService(Context context)
            : base(context) { }
        #endregion Constructors
    }
}
