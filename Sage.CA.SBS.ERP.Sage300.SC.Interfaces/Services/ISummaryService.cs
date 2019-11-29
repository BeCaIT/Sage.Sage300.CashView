using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Service;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services
{
    public interface ISummaryService<T> :
        IInquiryService<T>,
        ISecurityService
        where T : Summary, new()
    {
    }
}
