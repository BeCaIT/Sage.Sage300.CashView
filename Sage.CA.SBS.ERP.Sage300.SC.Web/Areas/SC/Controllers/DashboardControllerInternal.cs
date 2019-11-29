using Sage.CA.SBS.ERP.Sage300.Common.Exceptions;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers
{
    public class DashboardControllerInternal<T>
        : InternalControllerBase<IDashboardService<T>>
        where T : Dashboard, new()
    {
        public DashboardControllerInternal(Context context)
            : base(context) { }

        internal DashboardViewModel<T> Get()
        {
            DashboardViewModel<T> viewModel = new DashboardViewModel<T>();

            try
            {
                viewModel.Data = Service.Get();
                viewModel.UserMessage = new UserMessage(viewModel.Data);
            }
            catch (BusinessException businessException)
            {
                viewModel.UserMessage = new UserMessage(businessException.Errors);
                viewModel.UserMessage.IsSuccess = false;
            }

            return viewModel;
        }
    }
}