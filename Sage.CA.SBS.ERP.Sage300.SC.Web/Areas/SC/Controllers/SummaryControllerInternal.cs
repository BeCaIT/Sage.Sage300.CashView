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
    public class SummaryControllerInternal<T>
        : InternalControllerBase<ISummaryService<T>>
        where T : Summary, new()
    {
        public SummaryControllerInternal(Context context)
            : base(context) { }

        internal SummaryViewModel<T> Get()
        {
            var model = new SummaryViewModel<T>();

            try
            {
                var dataItems = Service.Get(new PageOptions<T> { });
                model.DataList = dataItems.Items;
                model.TotalResultsCount = dataItems.TotalResultsCount;
            }
            catch (BusinessException businessException)
            {
                model.UserMessage = new UserMessage(businessException.Errors);
                model.UserMessage.IsSuccess = false;
            }

            return model;
        }

        internal SummaryViewModel<T> Get(T model, int pageNumber, int pageSize, Expression<Func<T, bool>> filters)
        {
            var pageOptions = new PageOptions<T>
            {
                PageNumber = pageNumber,
                PageSize = pageSize,
                Filter = filters
            };

            var viewModel = new SummaryViewModel<T>();
            try
            {
                var dataItems = Service.Get(model, pageOptions);
                viewModel.DataList = dataItems.Items;
                viewModel.TotalResultsCount = dataItems.TotalResultsCount;
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