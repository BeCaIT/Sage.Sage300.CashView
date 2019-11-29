using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Resources;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.Common.Web.Utilities;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers
{
    public class LoanControllerInternal<T>
        : InternalControllerBase<ILoanService<T>>
        where T : Loan, new()
    {
        #region Constructors
        public LoanControllerInternal(Context context)
            : base(context) { }
        #endregion Constructors

        internal LoanViewModel<T> Get()
            => new LoanViewModel<T>
            {
                UserAccess = GetAccessRights()
            };

        internal LoanViewModel<T> Get(int pageNumber, int pageSize)
        {
            EnumerableResponse<T> enumerableResponse = Service.Get(pageNumber, pageSize, null, new OrderBy
            {
                SortDirection = SortDirection.Descending
            });

            return new LoanViewModel<T>
            {
                DataList = enumerableResponse.Items,
                TotalResultsCount = enumerableResponse.TotalResultsCount,
                UserMessage = new UserMessage(enumerableResponse),
                UserAccess = GetAccessRights()
            };
        }

        #region Save
        internal LoanViewModel<T> Save(T model)
        {
            T data = Service.Save(model);
            var userMessage = new UserMessage(data, data.Status == SC.Models.Enums.LoanStatus.Submitted ? LoanResx.ResubmitSuccessMessage : CommonResx.SaveSuccessMessage);

            return new LoanViewModel<T>
            {
                Data = data,
                UserMessage = userMessage
            };
        }

        internal LoanViewModel<T> Submit(T model)
        {
            model.Status = SC.Models.Enums.LoanStatus.Submitted;
            T data = Service.Save(model);
            var userMessage = new UserMessage(data, LoanResx.SubmitSuccessMessage);

            return new LoanViewModel<T>
            {
                Data = data,
                UserMessage = userMessage
            };
        }

        internal LoanViewModel<T> Cancel(T model)
        {
            model.Status = SC.Models.Enums.LoanStatus.Cancelled;
            T data = Service.Save(model);
            var userMessage = new UserMessage(data, LoanResx.CancelSuccessMessage);

            return new LoanViewModel<T>
            {
                Data = data,
                UserMessage = userMessage
            };
        }

        internal LoanViewModel<T> Rejected(T model)
        {
            model.Status = SC.Models.Enums.LoanStatus.Rejected;
            return Save(model);
        }

        internal LoanViewModel<T> Approved(T model)
        {
            model.Status = SC.Models.Enums.LoanStatus.Approved;
            return Save(model);
        }
        #endregion Save
    }
}