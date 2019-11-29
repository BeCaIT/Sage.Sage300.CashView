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
    public class PayeeSummaryController<T>
        : MultitenantControllerBase<PayeeSummaryViewModel<T>>
        where T : PayeeSummary, new()
    {
        public PayeeSummaryControllerInternal<T> ControllerInternal { get; set; }

        #region Constructors
        public PayeeSummaryController(IUnityContainer container)
            : base(container) { }
        #endregion Constructors

        #region Initialize
        protected override void Initialize(RequestContext requestContext)
        {
            base.Initialize(requestContext);

            ControllerInternal = new PayeeSummaryControllerInternal<T>(Context);
        }
        #endregion Initialize

        public virtual ActionResult Index()
        {
            throw new NotImplementedException();
        }

        public virtual ActionResult AR()
        {
            PayeeSummaryViewModel<T> viewModel;

            try
            {
                viewModel = ControllerInternal.GetAR();
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

            return View(nameof(Index), viewModel);
        }

        public virtual ActionResult AP()
        {
            PayeeSummaryViewModel<T> viewModel;

            try
            {
                viewModel = ControllerInternal.GetAP();
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

            return View(nameof(Index), viewModel);
        }
    }
}