/* Copyright (c) 2019 Sage Software Asia Pte Ltd.  All rights reserved. */

using Microsoft.Practices.Unity;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Bootstrap;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Repository;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Utilities;
using Sage.CA.SBS.ERP.Sage300.SC.Services.Reports;
using System.ComponentModel.Composition;

namespace Sage.CA.SBS.ERP.Sage300.SC.Services
{
    /// <summary>
    /// SC Bootstrapper Class
    /// </summary>
    [Export(typeof(IBootstrapperTask))]
    [BootstrapMetadataExport("SC", new[] { BootstrapAppliesTo.Web, BootstrapAppliesTo.Worker, BootstrapAppliesTo.WebApi }, 10)]
    public class SCBootstrapper : IBootstrapperTask
    {
        /// <summary>
        /// Bootstrap activity execution
        /// </summary>
        /// <param name="container">The Unity container</param>
        public void Execute(IUnityContainer container)
        {
            RegisterService(container);
            RegisterRepositories(container);
        }

        /// <summary>
        /// Register services 
        /// </summary>
        /// <param name="container">The Unity container</param>
        private void RegisterService(IUnityContainer container)
        {
            //
            //// Options
            UnityUtil.RegisterType<
                Interfaces.Services.IOptionsService<Models.Options>, 
                OptionsEntityService<Models.Options>>
                (container);

            //
            //// Account
            UnityUtil.RegisterType<
                Interfaces.Services.IAccountService<Models.Account>,
                AccountEntityService<Models.Account>>
                (container);

            //
            //// Dashboard
            UnityUtil.RegisterType<
                Interfaces.Services.IDashboardService<Models.Dashboard>, 
                DashboardEntityService<Models.Dashboard>>
                (container);

            //
            //// Summary
            UnityUtil.RegisterType<
                Interfaces.Services.ISummaryService<Models.Summary>, 
                SummaryEntityService<Models.Summary>>
                (container);

            //
            //// Forecast Entry
            UnityUtil.RegisterType <
                Interfaces.Services.IForecastEntryService<Models.ForecastEntry>,
                ForecastEntryEntityService<Models.ForecastEntry>>
                (container);

            //
            //// Payee Summary
            UnityUtil.RegisterType<
                Interfaces.Services.IPayeeSummaryService<Models.PayeeSummary>, 
                PayeeSummaryEntityService<Models.PayeeSummary>>
                (container);

            //
            //// Forecast Entry
            UnityUtil.RegisterType<
                Interfaces.Services.IForecastEntryService<Models.ForecastEntry>,
                ForecastEntryEntityService<Models.ForecastEntry>>
                (container);

            //
            //// Loan
            UnityUtil.RegisterType<
                Interfaces.Services.ILoanService<Models.Loan>, 
                LoanEntityService<Models.Loan>>
                (container);

            //
            //// Report: Dashboard Report
            UnityUtil.RegisterType<
                Interfaces.Services.Reports.ISCReportService<Models.Reports.SCReport>,
                SCReportService<Models.Reports.SCReport>>
                (container);
        }

        /// <summary>
        /// Register repositories 
        /// </summary>
        /// <param name="container">The Unity container</param>
        private void RegisterRepositories(IUnityContainer container)
        {
            //
            //// Options Service
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IOptionsEntity<Models.Options>),
                typeof(BusinessRepository.OptionsRepository<Models.Options>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IOptionsEntity<Models.Options>),
                typeof(BusinessRepository.OptionsRepository<Models.Options>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));

            //
            //// Account Service
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IAccountEntity<Models.Account>),
                typeof(BusinessRepository.AccountRepository<Models.Account>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IAccountEntity<Models.Account>),
                typeof(BusinessRepository.AccountRepository<Models.Account>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));

            //
            //// Account Service
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IAccountEntity<Models.Account>),
                typeof(BusinessRepository.AccountRepository<Models.Account>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IAccountEntity<Models.Account>),
                typeof(BusinessRepository.AccountRepository<Models.Account>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));

            //
            //// Dashboard Services
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IDashboardEntity<Models.Dashboard>),
                typeof(BusinessRepository.DashboardRepository<Models.Dashboard>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IDashboardEntity<Models.Dashboard>),
                typeof(BusinessRepository.DashboardRepository<Models.Dashboard>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));

            //
            //// Summary Services
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.ISummaryEntity<Models.Summary>),
                typeof(BusinessRepository.SummaryRepository<Models.Summary>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.ISummaryEntity<Models.Summary>),
                typeof(BusinessRepository.SummaryRepository<Models.Summary>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));

            //
            //// Forecast Entry
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IForecastEntryEntity<Models.ForecastEntry>),
                typeof(BusinessRepository.ForecastEntryRepository<Models.ForecastEntry>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IForecastEntryEntity<Models.ForecastEntry>),
                typeof(BusinessRepository.ForecastEntryRepository<Models.ForecastEntry>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));

            //
            //// Payee Summary Services
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IPayeeSummaryEntity<Models.PayeeSummary>),
                typeof(BusinessRepository.PayeeSummaryRepository<Models.PayeeSummary>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IPayeeSummaryEntity<Models.PayeeSummary>),
                typeof(BusinessRepository.PayeeSummaryRepository<Models.PayeeSummary>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));

            //
            //// Forecast Entry
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IForecastEntryEntity<Models.ForecastEntry>),
                typeof(BusinessRepository.ForecastEntryRepository<Models.ForecastEntry>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.IForecastEntryEntity<Models.ForecastEntry>),
                typeof(BusinessRepository.ForecastEntryRepository<Models.ForecastEntry>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));

            //
            //// Loan
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.ILoanEntity<Models.Loan>),
                typeof(BusinessRepository.LoanRepository<Models.Loan>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.ILoanEntity<Models.Loan>),
                typeof(BusinessRepository.LoanRepository<Models.Loan>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));

            //
            //// Report: Dashboard Report
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.Reports.ISCReportEntity<Models.Reports.SCReport>),
                typeof(BusinessRepository.Reports.SCReportRepository<Models.Reports.SCReport>),
                UnityInjectionType.Default,
                new InjectionConstructor(typeof(Context)));
            UnityUtil.RegisterType(
                container,
                typeof(Interfaces.BusinessRepository.Reports.ISCReportEntity<Models.Reports.SCReport>),
                typeof(BusinessRepository.Reports.SCReportRepository<Models.Reports.SCReport>),
                UnityInjectionType.Session,
                new InjectionConstructor(typeof(Context), typeof(IBusinessEntitySession)));
        }
    }
}
