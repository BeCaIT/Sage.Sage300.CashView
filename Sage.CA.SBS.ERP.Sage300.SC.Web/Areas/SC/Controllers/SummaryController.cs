using Microsoft.Practices.Unity;
using Sage.CA.SBS.ERP.Sage300.Common.Exceptions;
using Sage.CA.SBS.ERP.Sage300.Common.Resources;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers
{
    public class SummaryController<T>
        : MultitenantControllerBase<SummaryViewModel<T>>
        where T : Summary, new()
    {
        public SummaryControllerInternal<T> ControllerInternal { get; set; }

        #region Constructors
        public SummaryController(IUnityContainer container)
            : base(container) { }
        #endregion Constructors

        #region Initialize
        protected override void Initialize(RequestContext requestContext)
        {
            base.Initialize(requestContext);

            ControllerInternal = new SummaryControllerInternal<T>(Context);
        }
        #endregion Initialize

        public virtual ActionResult Index()
        {
            SummaryViewModel<T> viewModel;

            try
            {
                viewModel = ControllerInternal.Get();
                if (viewModel.DataList != null && viewModel.DataList.Count() > 0)
                {
                    viewModel.Data.UIOptions = viewModel.DataList.First().UIOptions;
                    foreach (var model in viewModel.DataList)
                        model.UIOptions = null;
                }
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.GetFailedMessage, businessException, string.Empty));
            }

            return View(viewModel);
        }

        //public virtual JsonNetResult Get(T model, int pageNumber, int pageSize, Expression<Func<T, bool>> filters)
        public virtual JsonNetResult Get(T model, int pageNumber, int pageSize, Expression<Func<T, bool>> filters)
        {
            SummaryViewModel<T> viewModel;

            try
            {
                viewModel = ControllerInternal.Get(model, pageNumber, pageSize, filters);
                if (viewModel.DataList != null && viewModel.DataList.Count() > 0)
                {
                    viewModel.Data.UIOptions = viewModel.DataList.First().UIOptions;
                    foreach (var detailModel in viewModel.DataList)
                        detailModel.UIOptions = null;
                }

                return JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                // TODO: Replace string.Empty with Resx string (i.e. CashflowProcessResx.SomeString)
                // TODO: Delete TODO statements when complete
                return JsonNet(BuildErrorModelBase(CommonResx.GetFailedMessage, businessException, string.Empty));
            }

        }
    }
}