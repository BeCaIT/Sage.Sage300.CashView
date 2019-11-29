/* Copyright (c) 2019 Sage Software Asia Pte Ltd.  All rights reserved. */

using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers;
using Microsoft.Practices.Unity;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Bootstrap;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Controller;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Repository;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Utilities;
using System.ComponentModel.Composition;
using System.Web.Mvc;

using Constants = Sage.CA.SBS.ERP.Sage300.SC.Web.Constants;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers.Reports;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Reports;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web
{
    /// <summary>
    /// SC Bootstrapper Class
    /// </summary>
    [Export(typeof(IBootstrapperTask))]
    [BootstrapMetadataExport("SC", new[] { BootstrapAppliesTo.Web }, 20)]
    public class SCWebBootstrapper : IBootstrapperTask
    {
        /// <summary>
        /// Bootstrap activity execution
        /// </summary>
        /// <param name="container">The Unity container</param>
        public void Execute(IUnityContainer container)
        {
            RegisterController(container);
            RegisterFinder(container);
            RegisterExportImportController(container);
        }

        /// <summary>
        /// Register controllers
        /// </summary>
        /// <param name="container">The Unity container</param>
        private void RegisterController(IUnityContainer container)
        {
            //
            //// Options
            UnityUtil.RegisterType<IController, OptionsController<Options>>(container, "SCOptions");

            //
            //// Account
            UnityUtil.RegisterType<IController, AccountController<Account>>(container, "SCAccount");

            //
            //// Dashboard
            UnityUtil.RegisterType<IController, DashboardController<Dashboard>>(container, "SCDashboard");

            //
            //// Summary
            UnityUtil.RegisterType<IController, SummaryController<Summary>>(container, "SCSummary");

            //
            //// Forecast Entry
            UnityUtil.RegisterType<IController, ForecastEntryController<ForecastEntry>>(container, "SCForecastEntry");

            //
            //// Payee Summary
            UnityUtil.RegisterType<IController, PayeeSummaryController<PayeeSummary>>(container, "SCPayeeSummary");

            //
            //// Loan
            UnityUtil.RegisterType<IController, LoanController<Loan>>(container, "SCLoan");

            //
            //// Report: Dashboard Report
            UnityUtil.RegisterType<IController, ReportsController<SCReport>>(container, "SCReports");
        }

        /// <summary>
        /// Register finders
        /// </summary>
        /// <param name="container">The Unity container</param>
        private void RegisterFinder(IUnityContainer container)
        {
            //
            //// Loan Gen: TO BE DELETED
			//UnityUtil.RegisterType<IFinder, FindLoanGenControllerInternal<LoanGen>>(container, "scloan", new InjectionConstructor(typeof(Context)));
        }

        /// <summary>
        /// Register import/export controllers
        /// </summary>
        /// <param name="container">The Unity container</param>
        private void RegisterExportImportController(IUnityContainer container)
        {
            //
            //// Loan Gen: TO BE DELETED
            //UnityUtil.RegisterType<IExportImportController, LoanGenControllerInternal<LoanGen>>(container, "scloan", new InjectionConstructor(typeof(Context)));
        }
    }
}
