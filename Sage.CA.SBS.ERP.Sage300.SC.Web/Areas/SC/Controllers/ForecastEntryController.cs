using Microsoft.Practices.Unity;
using Sage.CA.SBS.ERP.Sage300.Common.Exceptions;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Resources;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Http;
using System.Web.Routing;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers
{
    public class ForecastEntryController<T>
        : MultitenantControllerBase<ForecastEntryViewModel<T>>
        where T : ForecastEntry, new()
    {
        private ForecastEntryControllerInternal<T> ControllerInternal { get; set; }

        #region Constructors
        public ForecastEntryController(IUnityContainer container)
            : base(container) { }
        #endregion Constructors

        #region Initialization
        protected override void Initialize(RequestContext requestContext)
        {
            base.Initialize(requestContext);
            ControllerInternal = new ForecastEntryControllerInternal<T>(Context);
        }
        #endregion Initialization

        [HttpPost]
        public virtual JsonNetResult Get(PageOptions<T> pageOptions)
        {
            try
            {
                pageOptions.OrderBy = new OrderBy
                {
                    PropertyName = "DocumentNumber",
                    SortDirection = SortDirection.Descending
                };

                return JsonNet(ControllerInternal.Get(pageOptions));
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.GetFailedMessage, businessException, ForecastEntryResx.Entity));
            }
        }

        [HttpPost]
        public virtual JsonNetResult Add(T model, PageOptions<T> pageOptions)
        {
            try
            {
                ViewModelBase<ModelBase> viewModel;

                pageOptions.OrderBy = new OrderBy
                {
                    PropertyName = "DocumentNumber",
                    SortDirection = SortDirection.Descending
                };

                return ValidateModelState(ModelState, out viewModel)
                    ? JsonNet(ControllerInternal.Add(model, pageOptions))
                    : JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.SaveFailedMessage, businessException));
            }
        }

        //[HttpPost]
        //public virtual JsonNetResult Add2(T model, int pageNumber, int pageSize)
        //{
        //    try
        //    {
        //        ViewModelBase<ModelBase> viewModel;

        //        return ValidateModelState(ModelState, out viewModel)
        //            ? JsonNet(ControllerInternal.Add(model, pageNumber, pageSize))
        //            : JsonNet(viewModel);
        //    }
        //    catch (BusinessException businessException)
        //    {
        //        return JsonNet(BuildErrorModelBase(CommonResx.SaveFailedMessage, businessException));
        //    }
        //}

        [HttpPost]
        public virtual JsonNetResult Save(T model)
        {
            try
            {
                ViewModelBase<ModelBase> viewModel;

                return ValidateModelState(ModelState, out viewModel)
                    ? JsonNet(ControllerInternal.Save(model))
                    : JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.SaveFailedMessage, businessException));
            }
        }

        [HttpPost]
        public virtual JsonNetResult Delete(T model)
        {
            try
            {
                ViewModelBase<ModelBase> viewModel;

                return ValidateModelState(ModelState, out viewModel)
                    ? JsonNet(ControllerInternal.Delete(model))
                    : JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.SaveFailedMessage, businessException));
            }
        }
    }
}