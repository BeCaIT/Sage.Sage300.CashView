using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository
{
    static class IBusinessEntitySessionExtensions
    {
        static PropertyInfo piSession = typeof(BusinessEntitySession).GetProperty("Session", BindingFlags.Instance | BindingFlags.NonPublic);

        internal static dynamic SafeGetSession(this IBusinessEntitySession session)
            => piSession.GetValue(session, null);
    }
}
