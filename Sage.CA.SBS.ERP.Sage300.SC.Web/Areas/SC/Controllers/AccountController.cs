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
    public class AccountController<T>
        : MultitenantControllerBase<AccountViewModel<T>>
        where T : Account, new()
    {
        protected AccountControllerInternal<T> ControllerInternal { get; set; }

        #region Constructors
        public AccountController(IUnityContainer container)
            : base(container, "SCAccounts") { }
        #endregion Constructors

        #region Initialize
        protected override void Initialize(RequestContext requestContext)
        {
            base.Initialize(requestContext);
            ControllerInternal = new AccountControllerInternal<T>(Context);
        }
        #endregion Initialize

        [HttpPost]
        public JsonNetResult Get(int pageNumber, int pageSize)
        {
            try
            {
                return JsonNet(ControllerInternal.Get(pageNumber, pageSize));
            }
            catch (BusinessException businessException)
            {
                return JsonNet(BuildErrorModelBase(CommonResx.GetFailedMessage, businessException, AccountResx.Entity));
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
    }
}