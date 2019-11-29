using Microsoft.Practices.Unity;
using Sage.CA.SBS.ERP.Sage300.Common.Exceptions;
using Sage.CA.SBS.ERP.Sage300.Common.Resources;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers
{
    public class DashboardController<T>
        : MultitenantControllerBase<DashboardViewModel<T>>
        where T : Dashboard, new()
    {
        public DashboardControllerInternal<T> ControllerInternal { get; set; }

        #region Constructors
        public DashboardController(IUnityContainer container)
            : base(container) { }
        #endregion Constructors

        #region Initialize
        protected override void Initialize(RequestContext requestContext)
        {
            base.Initialize(requestContext);

            ControllerInternal = new DashboardControllerInternal<T>(Context);
        }
        #endregion Initialize

        public virtual ActionResult Index()
        {
            DashboardViewModel<T> viewModel = new DashboardViewModel<T>();

            try
            {
                //viewModel = new DashboardViewModel<T>();
                viewModel = ControllerInternal.Get();
            }
            catch (BusinessException businessException)
            {
                return View(JsonNet(BuildErrorModelBase(CommonResx.GetFailedMessage, businessException, string.Empty)));
            }

            return View(viewModel);
        }

        public virtual JsonNetResult GetThresholdAlert()
        {
            BusinessException ex = new BusinessException();
            //BusinessException ex = new BusinessException(
            //    "You have reached threshold", new List<Common.Models.EntityError>(new Common.Models.EntityError[] 
            //    {
            //        new Common.Models.EntityError(){ Priority = Common.Models.Priority.Warning, Message = "Threshold Breached" },
            //    }));

            //var result = BuildErrorOrWarningModelBase("Threshold breached", ex);
            var result = new ViewModelBase<Common.Models.ModelBase>();
            result.UserMessage.Info = new List<SCEntityError>(new SCEntityError[]
                {
                    //new Common.Models.EntityError() { Message = "<img style=\"width: 310\" alt=\"&amp;\" src=\"data:image/png;base64, " + GetOffer() + "\" />" },
                    new SCEntityError { ImageData = GetOffer() }
                });
            return JsonNet(result);
        }

        private string GetOffer()
        {
            using (var stream = new MemoryStream())
            {
                Properties.Resources.OfferSG.Save(stream, Properties.Resources.OfferSG.RawFormat);
                return Convert.ToBase64String(stream.ToArray());
            }
        }
    }
}