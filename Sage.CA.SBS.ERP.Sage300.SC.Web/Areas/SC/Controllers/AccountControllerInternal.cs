using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Resources;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers
{
    public class AccountControllerInternal<T>
        : InternalControllerBase<IAccountService<T>>
        where T : Account, new()
    {
        #region Constructors
        public AccountControllerInternal(Context context)
            : base(context) { }
        #endregion Constructors

        internal AccountViewModel<T> Get(int pageNumber, int pageSize)
        {
            EnumerableResponse<T> enumerableResponse = Service.Get(pageNumber, pageSize, (t) => true, new OrderBy());

            return new AccountViewModel<T>
            {
                DataList = enumerableResponse.Items,
                TotalResultsCount = enumerableResponse.TotalResultsCount,
                UserMessage = new UserMessage(enumerableResponse),
                UserAccess = GetAccessRights()
            };
        }

        internal AccountViewModel<T> Save(T model)
        {
            T data = Service.Save(model);
            var userMessage = new UserMessage(data, CommonResx.SaveSuccessMessage);

            return new AccountViewModel<T>
            {
                Data = data,
                UserMessage = userMessage
            };
        }
    }
}