using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.Exceptions;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Core.Cache;
using Sage.CA.SBS.ERP.Sage300.SC.Data;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq.Expressions;
using System.Reflection;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository
{
    public abstract class SCInquiryRepository<T>
        : InquiryRepository<T>,
        ISCInquiryRepository<T>
        where T : SCInquiryModelBase, new()
    {
        #region Constructors
        public SCInquiryRepository(
            Context context,
            ModelMapper<T> mapper,
            Expression<Func<T, bool>> activeFilter)
            : base(context, mapper, activeFilter) { }

        public SCInquiryRepository(
            Context context,
            ModelMapper<T> mapper,
            Expression<Func<T, bool>> activeFilter,
            IBusinessEntitySession session)
            : base(context, mapper, activeFilter, session) { }
        #endregion Constructors

        #region Overrides
        protected override IBusinessEntity CreateBusinessEntities()
        {
            throw new NotImplementedException();
        }
        #endregion Overrides

        #region Data
        private static string _cacheKey = "SCData";
        private string CacheKey => $"{Context.SessionId}-{_cacheKey}";

        static MethodInfo miSetCache = typeof(CacheHelper).GetMethod("Set").MakeGenericMethod(typeof(ApplicationData));

        private ApplicationData _applicationData;
        internal ApplicationData ApplicationData
            => (_applicationData)
            ?? (_applicationData = GetApplicationData());

        protected void Refresh()
        {
            _applicationData = null;
            CacheHelper.Remove(CacheKey);
        }

        private ApplicationData GetApplicationData()
        {
            //ApplicationData applicationData = CacheHelper.Get<ApplicationData>(CacheKey);

            //if (applicationData == null)
            //{
            //    applicationData = LoadData();
            //    // Set Cache:
            //    // Have to use this reflection approach due to different API signature between 2016 & 2019
            //    switch (miSetCache.GetParameters().Length)
            //    {
            //        case 2:
            //            miSetCache.Invoke(null, new object[] { CacheKey, applicationData });
            //            break;

            //        default:
            //            miSetCache.Invoke(null, new object[] { CacheKey, applicationData, 0 });
            //            break;
            //    }
            //}

            //return applicationData;

            return LoadData();
        }

        private ApplicationData LoadData()
        {
            ApplicationData applicationData = ApplicationData.Current;

            //
            //// Options
            LoadData_Options(ref applicationData);

            //
            //// Permissions
            LoadData_Permissions(ref applicationData);

            //
            //// Application Settings
            LoadData_ApplicationSettings(ref applicationData);

            //
            //// UI Settings
            LoadData_UISettings(ref applicationData);

            //
            //// Accounts
            LoadData_Accounts(ref applicationData);

            //
            //// Balances
            LoadData_Balances(ref applicationData);

            //
            //// Transactions
            LoadData_Transactions(ref applicationData);

            //
            //// Popuplate Data
            applicationData.PopuplateData();

            return applicationData;
        }

        private void LoadData_Permissions(
            ref ApplicationData applicationData)
        {
            if (Session.IsAdmin)
            {
                applicationData.HasInquiryRight = true;
                applicationData.HasProcessRight = true;
                applicationData.HasForecastEntryRight = true;
                applicationData.HasLoanInquiryRight = true;
                applicationData.HasLoanEntryRight = true;
            }
            else
            {
                applicationData.HasInquiryRight = Session.SecurityCheck(ApplicationData.RIGHT_SCINQUIRY);
                applicationData.HasProcessRight = Session.SecurityCheck(ApplicationData.RIGHT_SCPROCESS);
                applicationData.HasForecastEntryRight = Session.SecurityCheck(ApplicationData.RIGHT_SCFCENTRY);
                applicationData.HasLoanInquiryRight = Session.SecurityCheck(ApplicationData.RIGHT_SCLINQUIRY);
                applicationData.HasLoanEntryRight = Session.SecurityCheck(ApplicationData.RIGHT_SCLENTRY);
            }
        }

        private void LoadData_ApplicationSettings(
            ref ApplicationData applicationData)
        {
            dynamic _session = Session.SafeGetSession();

            string buffer;
            decimal value;

            //
            //// Quick Ratio                        
            _session.GetIniFileKey("SC", "Dashboard", "QuickRatioBreak", out buffer);
            if (decimal.TryParse(buffer, out value))
                applicationData.QuickRatioBreak = value;

            //
            //// Current Ratio
            _session.GetIniFileKey("SC", "Dashboard", "CurrentRatioBreak", out buffer);
            if (decimal.TryParse(buffer, out value))
                applicationData.CurrentRatioBreak = value;
                //ApplicationData.Current.CurrentRatioBreak = value;

            //
            //// DSO Maximum
            _session.GetIniFileKey("SC", "Dashboard", "DSOMaximum", out buffer);
            if (decimal.TryParse(buffer, out value))
                applicationData.DSOMaximum = value;

            //
            //// DSO Median
            _session.GetIniFileKey("SC", "Dashboard", "DSOMedian", out buffer);
            if (decimal.TryParse(buffer, out value))
                applicationData.DSOMedian = value;

            //
            //// DPO Maximum
            _session.GetIniFileKey("SC", "Dashboard", "DPOMaximum", out buffer);
            if (decimal.TryParse(buffer, out value))
                applicationData.DPOMaximum = value;

            //
            //// DPO Median
            _session.GetIniFileKey("SC", "Dashboard", "DPOMedian", out buffer);
            if (decimal.TryParse(buffer, out value))
                applicationData.DPOMedian = value;
        }

        private void LoadData_UISettings(
            ref ApplicationData applicationData)
        {
            IBusinessEntity loan = Session.OpenView(Models.Loan.EntityName, Session, GetType().Name, Context, true);
            applicationData.HasLoanRecords = (loan.FilterCount(string.Empty, 0) > 0);
            applicationData.HasNewLoanRecord = (loan.FilterCount("(STATUS = 0)", 0) > 0);
        }

        private void LoadData_Options(
            ref ApplicationData applicationData)
        {
            //var options = Session.ParamGet(
            //    Options.EntityName,
            //    new int[]
            //    {
            //        Options.Indexes.Country,
            //        Options.Indexes.Threshold,
            //        Options.Indexes.Period1End,
            //        Options.Indexes.Period2End,
            //        Options.Indexes.Period3End,
            //        Options.Indexes.Period4End,
            //        Options.Indexes.Period5End,
            //        Options.Indexes.CurrentYear,
            //        Options.Indexes.CurrentPeriod,
            //    });

            //applicationData.Country = (short)options[0];
            //applicationData.Threshold = (decimal)options[1];
            ////
            //applicationData.Period1End = (short)options[2];
            //applicationData.Period2End = (short)options[3];
            //applicationData.Period3End = (short)options[4];
            //applicationData.Period4End = (short)options[5];
            //applicationData.Period5End = (short)options[6];
            ////
            //applicationData.CurrentYear = (string)options[7];
            //applicationData.CurrentPeriod = (short)options[8];
            //Session.GetPeriodInfo(Session.GetFiscalPeriod().Year, (short)1, out PeriodInfo periodInfo, "SC");
            //applicationData.CurrentYearStartDate = DateTime.FromOADate(periodInfo.BeginDate);
            IBusinessEntity options = Session.OpenView(Options.EntityName, Session, GetType().Name, Context, true);
            if (options.Read(false))
            {
                applicationData.Country = options.GetValue<short>(Options.Fields.Country);
                applicationData.Threshold = options.GetValue<decimal>(Options.Fields.Threshold);
                //
                applicationData.Period1End = options.GetValue<short>(Options.Fields.Period1End);
                applicationData.Period2End = options.GetValue<short>(Options.Fields.Period2End);
                applicationData.Period3End = options.GetValue<short>(Options.Fields.Period3End);
                applicationData.Period4End = options.GetValue<short>(Options.Fields.Period4End);
                applicationData.Period5End = options.GetValue<short>(Options.Fields.Period5End);
                //
                applicationData.CurrentYear = options.GetValue<string>(Options.Fields.CurrentYear);
                applicationData.CurrentPeriod = options.GetValue<short>(Options.Fields.CurrentPeriod);
                Session.GetPeriodInfo(Session.GetFiscalPeriod().Year, (short)1, out PeriodInfo periodInfo, "SC");
                applicationData.CurrentYearStartDate = DateTime.FromOADate(periodInfo.BeginDate);
            }
            else
            {
                throw new BusinessException(SCCommonResx.OptionsNotDefined, new List<EntityError>(new EntityError[] { new EntityError { Priority = Priority.Error, Message = SCCommonResx.OptionsNotDefined } }));
            }
            options.Dispose();
        }

        private void LoadData_Accounts(
            ref ApplicationData applicationData)
        {
            applicationData.Accounts.Clear();

            IBusinessEntity account = Session.OpenView(Models.Account.EntityName, Session, GetType().Name, Context, true);
            account.Browse(string.Empty, true);
            while (account.Fetch(false))
            {
                applicationData.Accounts.Add(new Data.Account
                {
                    AccountNumber = account.GetValue<string>(Models.Account.Fields.AccountNumber),
                    Description = account.GetValue<string>(Models.Account.Fields.AccountDescription),
                    Include = account.GetValue<short>(Models.Account.Fields.Include) == 1,
                    Balance = account.GetValue<decimal>(Models.Account.Fields.AmountBalance)
                });
            }
            account.Dispose();
        }

        private void LoadData_Balances(
            ref ApplicationData applicationData)
        {
            applicationData.Balances.Clear();

            var balance = Session.OpenView(Models.Balance.EntityName, Session, GetType().Name, Context, true);
            balance.Browse($"FSCYEAR=\"{applicationData.CurrentYear}\"", true);
            while (balance.Fetch(false))
            {
                applicationData.Balances.Add(new Data.Balance
                {
                    RecordType = (RecordType)Enum.ToObject(typeof(RecordType), balance.GetValue<short>(Models.Balance.Fields.RecordType)),
                    GroupCode = balance.GetValue<short>(Models.Balance.Fields.GroupCategory),
                    NetPeriod1 = balance.GetValue<decimal>("NETPERD1"),
                    NetPeriod2 = balance.GetValue<decimal>("NETPERD2"),
                    NetPeriod3 = balance.GetValue<decimal>("NETPERD3"),
                    NetPeriod4 = balance.GetValue<decimal>("NETPERD4"),
                    NetPeriod5 = balance.GetValue<decimal>("NETPERD5"),
                    NetPeriod6 = balance.GetValue<decimal>("NETPERD6"),
                    NetPeriod7 = balance.GetValue<decimal>("NETPERD7"),
                    NetPeriod8 = balance.GetValue<decimal>("NETPERD8"),
                    NetPeriod9 = balance.GetValue<decimal>("NETPERD9"),
                    NetPeriod10 = balance.GetValue<decimal>("NETPERD10"),
                    NetPeriod11 = balance.GetValue<decimal>("NETPERD11"),
                    NetPeriod12 = balance.GetValue<decimal>("NETPERD12"),
                    NetPeriod13 = balance.GetValue<decimal>("NETPERD13"),
                    NetPeriod14 = balance.GetValue<decimal>("NETPERD14"),
                    NetPeriod15 = balance.GetValue<decimal>("NETPERD15"),
                    NetYear = balance.GetValue<decimal>("NETYEAR"),
                    NetYearToDate = balance.GetValue<decimal>("NETYTD"),
                    BalanceOpening = balance.GetValue<decimal>("BALOPEN"),
                    BalancePeriod1 = balance.GetValue<decimal>("BALPERD1"),
                    BalancePeriod2 = balance.GetValue<decimal>("BALPERD2"),
                    BalancePeriod3 = balance.GetValue<decimal>("BALPERD3"),
                    BalancePeriod4 = balance.GetValue<decimal>("BALPERD4"),
                    BalancePeriod5 = balance.GetValue<decimal>("BALPERD5"),
                    BalancePeriod6 = balance.GetValue<decimal>("BALPERD6"),
                    BalancePeriod7 = balance.GetValue<decimal>("BALPERD7"),
                    BalancePeriod8 = balance.GetValue<decimal>("BALPERD8"),
                    BalancePeriod9 = balance.GetValue<decimal>("BALPERD9"),
                    BalancePeriod10 = balance.GetValue<decimal>("BALPERD10"),
                    BalancePeriod11 = balance.GetValue<decimal>("BALPERD11"),
                    BalancePeriod12 = balance.GetValue<decimal>("BALPERD12"),
                    BalancePeriod13 = balance.GetValue<decimal>("BALPERD13"),
                    BalancePeriod14 = balance.GetValue<decimal>("BALPERD14"),
                    BalancePeriod15 = balance.GetValue<decimal>("BALPERD15"),
                    BalanceYearToDate = balance.GetValue<decimal>("BALYTD"),
                });
            }
            balance.Dispose();
        }

        private void LoadData_Transactions(
            ref ApplicationData applicationData)
        {
            applicationData.Transactions.Clear();

            var transaction = Session.OpenView("CS0120", Session, GetType().Name, Context, true);
            transaction.Browse(
                "select\n" +
                "   SCTRAN.*\n" +
                "   ,coalesce(ARCUS.NAMECUST, APVEN.VENDNAME) PAYEE\n" +
                "   ,coalesce(ARCUS.NAMECTAC, APVEN.NAMECTAC) CONTACT\n" +
                "   ,coalesce(ARCUS.CODECURN, APVEN.CURNCODE) CURRENCY\n" +
                "   ,coalesce(ARCUS.AMTCRLIMT, APVEN.AMTCRLIMT) CRLIMIT\n" +
                "   ,coalesce(ARCUS.AMTBALHIH, APVEN.AMTBALHIH) BALHIGHEST\n" +
                "   ,coalesce(ARCUS.DAYSTOPAY, APVEN.DAYSTOPAY) DAYSTOPAY\n" +
                "from\n" +
                "   SCTRAN\n" +
                "   left join ARCUS on (SCTRAN.SOURCE = 'AR' and SCTRAN.CUSTVEND = ARCUS.IDCUST)\n" +
                "   left join APVEN on(SCTRAN.SOURCE = 'AP' and SCTRAN.CUSTVEND = APVEN.VENDORID)",
                true);
            transaction.RefreshMetaData();

            while (transaction.Fetch(false))
                applicationData.Transactions.Add(new Data.Transaction
                {
                    RecordType = (RecordType)Enum.ToObject(typeof(RecordType), transaction.GetValue<short>("RECTYPE")),
                    Source = transaction.GetValue<string>("SOURCE"),
                    PayeeNumber = transaction.GetValue<string>("CUSTVEND"),
                    PayeeName = transaction.GetValue<string>("PAYEE"),
                    DocumentNumber = transaction.GetValue<string>("DOCNUM"),
                    PaymentNumber = transaction.GetValue<decimal>("PAYMENTNBR"),
                    DocumentDate = DateTime.ParseExact(transaction.GetValue<decimal>("DOCDATE").ToString(), "yyyyMMdd", CultureInfo.InvariantCulture),
                    DueDate = DateTime.ParseExact(transaction.GetValue<decimal>("DATEDUE").ToString(), "yyyyMMdd", CultureInfo.InvariantCulture),
                    Description = transaction.GetValue<string>("DOCDESC"),
                    AmountDue = transaction.GetValue<decimal>("AMTDUEHC"),
                    AmountPaid = transaction.GetValue<decimal>("AMTPAIDHC"),
                    Contact = transaction.GetValue<string>("CONTACT"),
                    Currency = transaction.GetValue<string>("CURRENCY"),
                    CreditLimit = transaction.GetValue<decimal>("CRLIMIT"),
                    HighestBalance = transaction.GetValue<decimal>("BALHIGHEST"),
                    AverageDaysToPay = transaction.GetValue<decimal>("DAYSTOPAY"),
                });

            transaction.Dispose();
        }
        #endregion Data

        #region UIOptions
        private UIOptions _uiOptions;
        protected UIOptions UIOptions
            => _uiOptions
            ?? (_uiOptions = new UIOptions
            {
                FormatString = ApplicationData.FormatString,
                //
                HasForecastEntryRight = ApplicationData.HasForecastEntryRight,
                //
                HasLoanAccess = ApplicationData.HasLoanInquiryRight,
                HasLoanRecords = ApplicationData.HasLoanRecords,
                ThresholdBreached = ApplicationData.ThresholdBreached,
                HasNewLoanRecord = ApplicationData.HasNewLoanRecord,
                OfferImage = Convert.ToBase64String(ApplicationData.OfferImage),
                //
                Period0Name = ApplicationData.Period0Name,
                Period1Name = ApplicationData.Period1Name,
                Period2Name = ApplicationData.Period2Name,
                Period3Name = ApplicationData.Period3Name,
                Period4Name = ApplicationData.Period4Name,
                Period5Name = ApplicationData.Period5Name,
                Period6Name = ApplicationData.Period6Name,
                //
            });
        #endregion UIOptions
    }
}
