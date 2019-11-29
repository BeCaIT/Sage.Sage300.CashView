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
    public class PayeeSummaryControllerInternal<T>
        : InternalControllerBase<IPayeeSummaryService<T>>
        where T : PayeeSummary, new()
    {
        public PayeeSummaryControllerInternal(Context context)
            : base(context) { }

        internal PayeeSummaryViewModel<T> GetAR()
        {
            var model = new PayeeSummaryViewModel<T>();
            try
            {
                var dataItems = Service.GetAR(new PageOptions<T> { });
                model.DataList = dataItems.Items;
                model.TotalResultsCount = dataItems.TotalResultsCount;
            }
            catch (BusinessException businessException)
            {
                model.UserMessage = new UserMessage(businessException.Errors)
                {
                    IsSuccess = false
                };
            }

            return model;
        }

        internal PayeeSummaryViewModel<T> GetAP()
        {
            var model = new PayeeSummaryViewModel<T>();
            try
            {
                var dataItems = Service.GetAP(new PageOptions<T> { });
                model.DataList = dataItems.Items;
                model.TotalResultsCount = dataItems.TotalResultsCount;
            }
            catch (BusinessException businessException)
            {
                model.UserMessage = new UserMessage(businessException.Errors)
                {
                    IsSuccess = false
                };
            }

            return model;
        }

        internal PayeeSummaryViewModel<T> GetAR(T model, int pageNumber, int pageSize, Expression<Func<T, bool>> filters)
        {
            var pageOptions = new PageOptions<T>
            {
                PageNumber = pageNumber,
                PageSize = pageSize,
                Filter = filters
            };

            var viewModel = new PayeeSummaryViewModel<T>();
            try
            {
                var dataItems = Service.GetAR(model, pageOptions);
                viewModel.DataList = dataItems.Items;
                viewModel.TotalResultsCount = dataItems.TotalResultsCount;
            }
            catch (BusinessException businessException)
            {
                viewModel.UserMessage = new UserMessage(businessException.Errors)
                {
                    IsSuccess = false
                };
            }

            return viewModel;
        }

        internal PayeeSummaryViewModel<T> GetAP(T model, int pageNumber, int pageSize, Expression<Func<T, bool>> filters)
        {
            var pageOptions = new PageOptions<T>
            {
                PageNumber = pageNumber,
                PageSize = pageSize,
                Filter = filters
            };

            var viewModel = new PayeeSummaryViewModel<T>();
            try
            {
                var dataItems = Service.GetAP(model, pageOptions);
                viewModel.DataList = dataItems.Items;
                viewModel.TotalResultsCount = dataItems.TotalResultsCount;
            }
            catch (BusinessException businessException)
            {
                viewModel.UserMessage = new UserMessage(businessException.Errors)
                {
                    IsSuccess = false
                };
            }

            return viewModel;
        }
    }
}