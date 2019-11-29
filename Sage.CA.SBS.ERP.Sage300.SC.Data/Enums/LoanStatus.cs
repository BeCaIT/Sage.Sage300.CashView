using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Data
{
    public enum LoanStatus
    {
        New = 0,
        Submitted = 1,
        Canceled = 2,
        Rejected = 3,
        Approved = 4,
        Closed = 5
    }
}
