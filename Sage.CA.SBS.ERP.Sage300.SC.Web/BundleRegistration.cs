/* Copyright (c) 2019 Sage Software Asia Pte Ltd.  All rights reserved. */

using System.Web.Optimization;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web
{
    /// <summary>
    /// Class for bundle registration
    /// </summary>
    internal static class BundleRegistration
    {
        /// <summary>
        /// Register bundles
        /// </summary>
        /// <param name="bundles"></param> 
        internal static void RegisterBundles(BundleCollection bundles)
        {
            //
            //// Options
            bundles.Add(new ScriptBundle("~/bundles/SCOptions").Include(
                "~/Areas/SC/Scripts/Options/Sage.CA.SBS.ERP.Sage300.SC.OptionsBehaviour.js",
                "~/Areas/SC/Scripts/Options/Sage.CA.SBS.ERP.Sage300.SC.OptionsKoExtn.js",
                "~/Areas/SC/Scripts/Options/Sage.CA.SBS.ERP.Sage300.SC.OptionsRepository.js",
                "~/Areas/Core/Scripts/Process/Sage.CA.SBS.Sage300.Common.Process.js"));

            //
            //// Dashboard
            bundles.Add(new ScriptBundle("~/bundles/SCDashboard").Include(
                "~/Areas/SC/Scripts/Dashboard/Sage.CA.SBS.ERP.Sage300.SC.DashboardBehaviour.js",
                "~/Areas/SC/Scripts/Dashboard/Sage.CA.SBS.ERP.Sage300.SC.DashboardKoExtn.js",
                "~/Areas/SC/Scripts/Dashboard/Sage.CA.SBS.ERP.Sage300.SC.DashboardRepository.js",
                "~/Areas/SC/Scripts/Reports/Sage.CA.SBS.ERP.Sage300.SC.ReportsBehavior.js",
                "~/Areas/SC/Scripts/Reports/Sage.CA.SBS.ERP.Sage300.SC.ReportsRepository.js",
                "~/Areas/SC/Scripts/Common/Sage.CA.SBS.ERP.Sage300.SC.Common.js"));

            //
            //// Summary
            bundles.Add(new ScriptBundle("~/bundles/SCSummary").Include(
                "~/Areas/SC/Scripts/Summary/Sage.CA.SBS.ERP.Sage300.SC.SummaryBehaviour.js",
                "~/Areas/SC/Scripts/Summary/Sage.CA.SBS.ERP.Sage300.SC.SummaryKoExtn.js",
                "~/Areas/SC/Scripts/Summary/Sage.CA.SBS.ERP.Sage300.SC.SummaryRepository.js",
                "~/Areas/SC/Scripts/Reports/Sage.CA.SBS.ERP.Sage300.SC.ReportsBehavior.js",
                "~/Areas/SC/Scripts/Reports/Sage.CA.SBS.ERP.Sage300.SC.ReportsRepository.js",
                "~/Areas/SC/Scripts/Common/Sage.CA.SBS.ERP.Sage300.SC.Common.js"));

            //
            //// Payee Summary
            bundles.Add(new ScriptBundle("~/bundles/SCPayeeSummary").Include(
                "~/Areas/SC/Scripts/PayeeSummary/Sage.CA.SBS.ERP.Sage300.SC.PayeeSummaryBehaviour.js",
                "~/Areas/SC/Scripts/PayeeSummary/Sage.CA.SBS.ERP.Sage300.SC.PayeeSummaryKoExtn.js",
                "~/Areas/SC/Scripts/PayeeSummary/Sage.CA.SBS.ERP.Sage300.SC.PayeeSummaryRepository.js",
                "~/Areas/SC/Scripts/Reports/Sage.CA.SBS.ERP.Sage300.SC.ReportsBehavior.js",
                "~/Areas/SC/Scripts/Reports/Sage.CA.SBS.ERP.Sage300.SC.ReportsRepository.js",
                "~/Areas/SC/Scripts/Common/Sage.CA.SBS.ERP.Sage300.SC.Common.js"));

            //
            //// Loan
            bundles.Add(new ScriptBundle("~/bundles/SCLoan").Include(
                "~/Areas/SC/Scripts/Loan/Sage.CA.SBS.ERP.Sage300.SC.LoanBehaviour.js",
                "~/Areas/SC/Scripts/Loan/Sage.CA.SBS.ERP.Sage300.SC.LoanKoExtn.js",
                "~/Areas/SC/Scripts/Loan/Sage.CA.SBS.ERP.Sage300.SC.LoanRepository.js",
                "~/Areas/Core/Scripts/Process/Sage.CA.SBS.Sage300.Common.Process.js"));
        }
    }
}