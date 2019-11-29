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
using System.Web.Mvc;
using System.Web.Routing;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers
{
    public class LoanController<T>
        : MultitenantControllerBase<LoanViewModel<T>>
        where T : Loan, new()
    {
        protected LoanControllerInternal<T> ControllerInternal { get; set; }

        #region Constructors
        public LoanController(IUnityContainer container)
            : base(container, "SCLoan") { }
        #endregion Constructors

        #region Initialize
        protected override void Initialize(RequestContext requestContext)
        {
            base.Initialize(requestContext);
            ControllerInternal = new LoanControllerInternal<T>(Context);
        }
        #endregion Initialize

        public ActionResult Index()
            => View(ControllerInternal.Get());

        [HttpPost]
        public JsonNetResult Get(int pageNumber, int pageSize)
        {
            try
            {
                return JsonNet(ControllerInternal.Get(pageNumber, pageSize));
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.GetFailedMessage, businessException, LoanResx.Entity));
            }
        }

        [HttpPost]
        public JsonNetResult Save(T model)
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
        public JsonNetResult Submit(T model)
        {
            try
            {
                ViewModelBase<ModelBase> viewModel;

                return ValidateModelState(ModelState, out viewModel)
                    ? JsonNet(ControllerInternal.Submit(model))
                    : JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.SaveFailedMessage, businessException));
            }
        }

        [HttpPost]
        public JsonNetResult Cancel(T model)
        {
            try
            {
                ViewModelBase<ModelBase> viewModel;

                return ValidateModelState(ModelState, out viewModel)
                    ? JsonNet(ControllerInternal.Cancel(model))
                    : JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.SaveFailedMessage, businessException));
            }
        }

        [HttpPost]
        public JsonNetResult Rejected(T model)
        {
            try
            {
                ViewModelBase<ModelBase> viewModel;

                return ValidateModelState(ModelState, out viewModel)
                    ? JsonNet(ControllerInternal.Rejected(model))
                    : JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.SaveFailedMessage, businessException));
            }
        }

        [HttpPost]
        public JsonNetResult Approved(T model)
        {
            try
            {
                ViewModelBase<ModelBase> viewModel;

                return ValidateModelState(ModelState, out viewModel)
                    ? JsonNet(ControllerInternal.Approved(model))
                    : JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.SaveFailedMessage, businessException));
            }
        }
    }
}