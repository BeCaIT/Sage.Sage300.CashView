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
    public class ForecastEntryControllerInternal<T>
        : InternalControllerBase<IForecastEntryService<T>>
        where T : ForecastEntry, new()
    {
        #region Constructors
        public ForecastEntryControllerInternal(Context context)
            : base(context) { }
        #endregion Constructors

        internal ForecastEntryViewModel<T> Get(PageOptions<T> pageOptions)
        {
            //EnumerableResponse<T> enumerableResponse = Service.Get(pageNumber, pageSize, null, null);
            EnumerableResponse<T> enumerableResponse = Service.Get(pageOptions);

            return new ForecastEntryViewModel<T>
            {
                DataList = enumerableResponse.Items,
                TotalResultsCount = enumerableResponse.TotalResultsCount,
                UserMessage = new UserMessage(enumerableResponse),
                UserAccess = GetAccessRights()
            };
        }

        //internal ForecastEntryViewModel<T> Add(T model)
        //{
        //    T data = Service.Add(model);
        //    var userMessage = new UserMessage(data, CommonResx.AddSuccessMessage);

        //    return new ForecastEntryViewModel<T>
        //    {
        //        Data = data,
        //        UserMessage = userMessage
        //    };
        //}

        internal ForecastEntryViewModel<T> Add(T model, PageOptions<T> pageOptions)
        {
            T data = Service.Add(model);
            var userMessage = new UserMessage(data, CommonResx.AddSuccessMessage);

            pageOptions.PageNumber = 0;
            ForecastEntryViewModel<T> viewModel = Get(pageOptions);

            viewModel.Data = data;
            viewModel.UserMessage = userMessage;

            return viewModel;
        }

        internal ForecastEntryViewModel<T> Save(T model)
        {
            T data = Service.Save(model);
            var userMessage = new UserMessage(data, CommonResx.SaveSuccessMessage);

            return new ForecastEntryViewModel<T>
            {
                Data = data,
                UserMessage = userMessage
            };
        }

        internal ForecastEntryViewModel<T> Delete(T model)
        {
            T data = Service.Delete(m => m.DocumentNumber == model.DocumentNumber);
            var userMessage = new UserMessage(data, CommonResx.DeleteSuccessMessage);

            return new ForecastEntryViewModel<T>
            {
                Data = data,
                UserMessage = userMessage
            };
        }
    }
}