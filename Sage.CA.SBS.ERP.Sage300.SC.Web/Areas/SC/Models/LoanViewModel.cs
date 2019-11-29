using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Models
{
    public class LoanViewModel<T>
        : ViewModelBase<T>
        where T : Loan, new()
    {
        public IEnumerable Statuses
            => EnumUtility.GetItems<LoanStatus>();

        public IEnumerable JobTitles
            => EnumUtility.GetItems<JobTitle>();
    }
}