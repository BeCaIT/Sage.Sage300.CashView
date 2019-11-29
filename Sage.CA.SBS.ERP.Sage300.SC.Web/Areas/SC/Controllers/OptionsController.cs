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
    public class OptionsController<T>
        : MultitenantControllerBase<OptionsViewModel<T>>
        where T : Options, new()
    {
        public OptionsControllerInternal<T> ControllerInternal { get; private set; }

        #region Constructors
        public OptionsController(IUnityContainer container)
            : base(container, "SCOptions") { }
        #endregion Constructors

        #region Initialize
        protected override void Initialize(RequestContext requestContext)
        {
            base.Initialize(requestContext);
            ControllerInternal = new OptionsControllerInternal<T>(Context);
        }

        public virtual ActionResult Index()
        {
            OptionsViewModel<T> viewModel;

            try
            {
                viewModel = ControllerInternal.Get();
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.GetFailedMessage, businessException, OptionsResx.Entity));
            }

            return View(viewModel);
        }


        [HttpPost]
        public virtual JsonNetResult Get()
        {
            try
            {
                return JsonNet(ControllerInternal.Get());
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.GetFailedMessage, businessException, OptionsResx.Entity));
            }
        }

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
        public virtual JsonNetResult SendTestEmail(T model)
        {
            try
            {
                ViewModelBase<ModelBase> viewModel;

                return ValidateModelState(ModelState, out viewModel)
                    ? JsonNet(ControllerInternal.SendTestEmail(model))
                    : JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(OptionsResx.EmailTestFailed, businessException));
            }
        }

        [HttpPost]
        public virtual JsonNetResult UpdateCalculatedFields(T model)
        {
            try
            {
                ViewModelBase<ModelBase> viewModel;

                return ValidateModelState(ModelState, out viewModel)
                    ? JsonNet(ControllerInternal.UpdateCalculatedFields(model))
                    : JsonNet(viewModel);
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.SaveFailedMessage, businessException));
            }
        }
        #endregion

        #region Accounts
        [HttpPost]
        public virtual JsonNetResult GetAccounts(T model, int pageNumber, int pageSize)
        {
            try
            {
                return JsonNet(ControllerInternal.GetAccounts(model, pageNumber, pageSize));
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.GetFailedMessage, businessException, AccountResx.Entity));
            }
        }
        #endregion Accounts
    }
}