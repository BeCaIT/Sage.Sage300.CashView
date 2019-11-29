using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Data
{
    public class ApplicationData : BaseDataModel
    {
        public static ApplicationData Current { get; } = new ApplicationData();

        public void PopuplateData()
        {
            PopuplateSharedData();
            PopuplateDashboardData();
            PopuplateCashFlowSummaryData();
            PopuplateARSummaryData();
            PopuplateAPSummaryData();
        }

        #region Permissions
        public const string RIGHT_SCINQUIRY = "SCINQUIRY";
        private bool _hasInquiryRight;
        public bool HasInquiryRight
        {
            get => _hasInquiryRight;
            set => SetProperty(ref _hasInquiryRight, value);
        }

        public const string RIGHT_SCPROCESS = "SCPROCESS";
        private bool _hasProcessRight;
        public bool HasProcessRight
        {
            get => _hasProcessRight;
            set => SetProperty(ref _hasProcessRight, value);
        }

        public const string RIGHT_SCFCENTRY = "SCFCENTRY";
        private bool _hasForecastEntryRight;
        public bool HasForecastEntryRight
        {
            get => _hasForecastEntryRight;
            set => SetProperty(ref _hasForecastEntryRight, value);
        }

        public const string RIGHT_SCLINQUIRY = "SCLINQUIRY";
        private bool _hasLoanInquiryRight;
        public bool HasLoanInquiryRight
        {
            get => _hasLoanInquiryRight;
            set => SetProperty(ref _hasLoanInquiryRight, value);
        }

        public const string RIGHT_SCLENTRY = "SCLENTRY";
        private bool _hasLoanEntryRight;
        public bool HasLoanEntryRight
        {
            get => _hasLoanEntryRight;
            set => SetProperty(ref _hasLoanEntryRight, value);
        }
        #endregion Permissions

        #region Options
        #region Forecast Periods
        private short _period1End;
        public short Period1End
        {
            get => _period1End;
            set => SetProperty(ref _period1End, value, new string[] { nameof(Period1Name), nameof(Period2Name) });
        }

        private short _period2End;
        public short Period2End
        {
            get => _period2End;
            set => SetProperty(ref _period2End, value, new string[] { nameof(Period2Name), nameof(Period3Name) });
        }

        private short _period3End;
        public short Period3End
        {
            get => _period3End;
            set => SetProperty(ref _period3End, value, new string[] { nameof(Period3Name), nameof(Period4Name) });
        }

        private short _period4End;
        public short Period4End
        {
            get => _period4End;
            set => SetProperty(ref _period4End, value, new string[] { nameof(Period4Name), nameof(Period5Name) });
        }

        private short _period5End;
        public short Period5End
        {
            get => _period5End;
            set => SetProperty(ref _period5End, value, new string[] { nameof(Period5Name), nameof(Period6Name) });
        }

        private string _period0Name = "Current";
        public string Period0Name
        {
            get => _period0Name;
            set => SetProperty(ref _period0Name, value);
        }

        public string Period1Name
            => "1 - " + Period1End;

        public string Period2Name
            => (Period1End + 1) + " - " + Period2End;

        public string Period3Name
            => (Period2End + 1) + " - " + Period3End;

        public string Period4Name
            => (Period3End + 1) + " - " + Period4End;

        public string Period5Name
            => (Period4End + 1) + " - " + Period5End;

        public string Period6Name
            => "> " + Period5End;
        #endregion Forecast Periods

        private decimal _threshold;
        public decimal Threshold
        {
            get => _threshold;
            set => SetProperty(ref _threshold, value);
        }

        private string _currentYear;
        public string CurrentYear
        {
            get => _currentYear;
            set => SetProperty(ref _currentYear, value);
        }

        private short _currentPeriod;
        public short CurrentPeriod
        {
            get => _currentPeriod;
            set => SetProperty(ref _currentPeriod, value);
        }

        private DateTime _currentYearStartDate;
        public DateTime CurrentYearStartDate
        {
            get => _currentYearStartDate;
            set => SetProperty(ref _currentYearStartDate, value, new string[] { nameof(NumberOfDays) });
        }

        private int NumberOfDays
            => (DateTime.Now - CurrentYearStartDate).Days;

        private short _country;
        public short Country
        {
            get => _country;
            set => SetProperty(ref _country, value, new string[] { nameof(OfferImage) });
        }

        private string _formatString = "#,0.00;-#,0.00";
        public string FormatString
        {
            get => _formatString;
            set => SetProperty(ref _formatString, value);
        }
        #endregion Options

        #region Settings
        private bool _thresholdBreached;
        public bool ThresholdBreached
        {
            get => _thresholdBreached;
            set => SetProperty(ref _thresholdBreached, value, new string[] { nameof(ShowThresholdAlert), nameof(ShowNotifications) });
        }

        private DateTime _thresholdAlertSnooze = DateTime.MinValue;
        public DateTime ThresholdAlertSnooze
        {
            get => _thresholdAlertSnooze;
            set => SetProperty(ref _thresholdAlertSnooze, value, new string[] { nameof(ShowThresholdAlert), nameof(ShowNotifications) });
        }

        private bool _hasLoanRecords;
        public bool HasLoanRecords
        {
            get => _hasLoanRecords;
            set => SetProperty(ref _hasLoanRecords, value);
        }

        private bool _hasNewLoanRecord;
        public bool HasNewLoanRecord
        {
            get => _hasNewLoanRecord;
            set => SetProperty(ref _hasNewLoanRecord, value, new string[] { nameof(ShowNotifications) });
        }

        public bool ShowThresholdAlert
            => ThresholdBreached && (ThresholdAlertSnooze.Date <= DateTime.Now.Date);

        public bool ShowNotifications
            => ShowThresholdAlert || HasNewLoanRecord;

        private byte[] _offerImage;
        public byte[] OfferImage
            => _offerImage
            ?? (_offerImage = GetOfferImage());

        private byte[] GetOfferImage()
        {
            using (var memoryStream = new MemoryStream())
            {
                switch (Country)
                {
                    case 702:
                        Properties.Resources.Offer702.Save(memoryStream, Properties.Resources.Offer702.RawFormat);
                        break;
                }

                return memoryStream.ToArray();
            }
        }
        #endregion Settings

        #region Raw Data
        public List<Account> Accounts { get; } = new List<Account>();
        public List<Balance> Balances { get; } = new List<Balance>();
        public List<Transaction> Transactions { get; } = new List<Transaction>();
        #endregion Raw Data

        #region Shared Data
        private Summary _netAR;
        public Summary NetAR
        {
            get => _netAR;
            set => SetProperty(ref _netAR, value);
        }

        private Summary _netAP;
        public Summary NetAP
        {
            get => _netAP;
            set => SetProperty(ref _netAP, value);
        }

        private Summary _netInFlow;
        public Summary NetInFlow
        {
            get => _netInFlow;
            set => SetProperty(ref _netInFlow, value);
        }

        private Summary _netOutFlow;
        public Summary NetOutFlow
        {
            get => _netOutFlow;
            set => SetProperty(ref _netOutFlow, value);
        }

        private Summary _openingBalance;
        public Summary OpeningBalance
        {
            get => _openingBalance;
            set => SetProperty(ref _openingBalance, value);
        }

        private Summary _endingBalance;
        public Summary EndingBalance
        {
            get => _endingBalance;
            set => SetProperty(ref _endingBalance, value);
        }

        private void PopuplateSharedData()
        {
            //
            //// Net AR
            NetAR = Transactions
            .Where(t => t.Source == "AR")
            .GroupBy(t => t.Source)
            .Select(g => new Summary
            {
                Description = "Collections from Customers",
                AmountPeriod0 = g.Sum(t => t.AmountPeriod0),
                AmountPeriod1 = g.Sum(t => t.AmountPeriod1),
                AmountPeriod2 = g.Sum(t => t.AmountPeriod2),
                AmountPeriod3 = g.Sum(t => t.AmountPeriod3),
                AmountPeriod4 = g.Sum(t => t.AmountPeriod4),
                AmountPeriod5 = g.Sum(t => t.AmountPeriod5),
                AmountPeriod6 = g.Sum(t => t.AmountPeriod6),
                AmountTotal = g.Sum(t => t.AmountOutstanding),
            })
            .FirstOrDefault() ?? new Summary { Description = "Collections from Customers" };

            //
            //// Net AP
            NetAP = Transactions
            .Where(t => t.Source == "AP")
            .GroupBy(t => t.Source)
            .Select(g => new Summary
            {
                Description = "Payments to Suppliers",
                AmountPeriod0 = g.Sum(t => t.AmountPeriod0),
                AmountPeriod1 = g.Sum(t => t.AmountPeriod1),
                AmountPeriod2 = g.Sum(t => t.AmountPeriod2),
                AmountPeriod3 = g.Sum(t => t.AmountPeriod3),
                AmountPeriod4 = g.Sum(t => t.AmountPeriod4),
                AmountPeriod5 = g.Sum(t => t.AmountPeriod5),
                AmountPeriod6 = g.Sum(t => t.AmountPeriod6),
                AmountTotal = g.Sum(t => t.AmountOutstanding),
            })
            .FirstOrDefault() ?? new Summary { Description = "Payments to Suppliers" };

            //
            //// Net Inflow
            NetInFlow = Transactions
            .Where(t => t.Source == "SC" && t.AmountOutstanding > 0)
            .GroupBy(t => t.Source)
            .Select(g => new Summary
            {
                Description = "InFlow",
                AmountPeriod0 = g.Sum(t => t.AmountPeriod0),
                AmountPeriod1 = g.Sum(t => t.AmountPeriod1),
                AmountPeriod2 = g.Sum(t => t.AmountPeriod2),
                AmountPeriod3 = g.Sum(t => t.AmountPeriod3),
                AmountPeriod4 = g.Sum(t => t.AmountPeriod4),
                AmountPeriod5 = g.Sum(t => t.AmountPeriod5),
                AmountPeriod6 = g.Sum(t => t.AmountPeriod6),
                AmountTotal = g.Sum(t => t.AmountOutstanding),
            })
            .FirstOrDefault() ?? new Summary { Description = "InFlow" };

            //
            //// Net Outflow
            NetOutFlow = Transactions
            .Where(t => t.Source == "SC" && t.AmountOutstanding < 0)
            .GroupBy(t => t.Source)
            .Select(g => new Summary
            {
                Description = "OutFlow",
                AmountPeriod0 = g.Sum(t => t.AmountPeriod0),
                AmountPeriod1 = g.Sum(t => t.AmountPeriod1),
                AmountPeriod2 = g.Sum(t => t.AmountPeriod2),
                AmountPeriod3 = g.Sum(t => t.AmountPeriod3),
                AmountPeriod4 = g.Sum(t => t.AmountPeriod4),
                AmountPeriod5 = g.Sum(t => t.AmountPeriod5),
                AmountPeriod6 = g.Sum(t => t.AmountPeriod6),
                AmountTotal = g.Sum(t => t.AmountOutstanding),
            })
            .FirstOrDefault() ?? new Summary { Description = "OutFlow" };

            //
            //// Opening Balance
            decimal currentBalance = Accounts.Where(a => a.Include).Sum(a => a.Balance);
            OpeningBalance = new Summary
            {
                Important = true,
                Description = "Cash Opening Balance",
                AmountPeriod0 = currentBalance,
            };
            OpeningBalance.AmountPeriod1 = OpeningBalance.AmountPeriod0 + NetAR.AmountPeriod0 + NetAP.AmountPeriod0 + NetInFlow.AmountPeriod0 + NetOutFlow.AmountPeriod0;
            OpeningBalance.AmountPeriod2 = OpeningBalance.AmountPeriod1 + NetAR.AmountPeriod1 + NetAP.AmountPeriod1 + NetInFlow.AmountPeriod1 + NetOutFlow.AmountPeriod1;
            OpeningBalance.AmountPeriod3 = OpeningBalance.AmountPeriod2 + NetAR.AmountPeriod2 + NetAP.AmountPeriod2 + NetInFlow.AmountPeriod2 + NetOutFlow.AmountPeriod2;
            OpeningBalance.AmountPeriod4 = OpeningBalance.AmountPeriod3 + NetAR.AmountPeriod3 + NetAP.AmountPeriod3 + NetInFlow.AmountPeriod3 + NetOutFlow.AmountPeriod3;
            OpeningBalance.AmountPeriod5 = OpeningBalance.AmountPeriod4 + NetAR.AmountPeriod4 + NetAP.AmountPeriod4 + NetInFlow.AmountPeriod4 + NetOutFlow.AmountPeriod4;
            OpeningBalance.AmountPeriod6 = OpeningBalance.AmountPeriod5 + NetAR.AmountPeriod5 + NetAP.AmountPeriod5 + NetInFlow.AmountPeriod5 + NetOutFlow.AmountPeriod5;
            OpeningBalance.AmountTotal = currentBalance;

            //
            //// Ending Balance
            EndingBalance = new Summary
            {
                Important = true,
                Description = "Cash Ending Balance",
                AmountPeriod0 = OpeningBalance.AmountPeriod0 + NetAR.AmountPeriod0 + NetAP.AmountPeriod0 + NetInFlow.AmountPeriod0 + NetOutFlow.AmountPeriod0,
                AmountPeriod1 = OpeningBalance.AmountPeriod1 + NetAR.AmountPeriod1 + NetAP.AmountPeriod1 + NetInFlow.AmountPeriod1 + NetOutFlow.AmountPeriod1,
                AmountPeriod2 = OpeningBalance.AmountPeriod2 + NetAR.AmountPeriod2 + NetAP.AmountPeriod2 + NetInFlow.AmountPeriod2 + NetOutFlow.AmountPeriod2,
                AmountPeriod3 = OpeningBalance.AmountPeriod3 + NetAR.AmountPeriod3 + NetAP.AmountPeriod3 + NetInFlow.AmountPeriod3 + NetOutFlow.AmountPeriod3,
                AmountPeriod4 = OpeningBalance.AmountPeriod4 + NetAR.AmountPeriod4 + NetAP.AmountPeriod4 + NetInFlow.AmountPeriod4 + NetOutFlow.AmountPeriod4,
                AmountPeriod5 = OpeningBalance.AmountPeriod5 + NetAR.AmountPeriod5 + NetAP.AmountPeriod5 + NetInFlow.AmountPeriod5 + NetOutFlow.AmountPeriod5,
                AmountPeriod6 = OpeningBalance.AmountPeriod6 + NetAR.AmountPeriod6 + NetAP.AmountPeriod6 + NetInFlow.AmountPeriod6 + NetOutFlow.AmountPeriod6,
                AmountTotal = OpeningBalance.AmountPeriod6 + NetAR.AmountPeriod6 + NetAP.AmountPeriod6 + NetInFlow.AmountPeriod6 + NetOutFlow.AmountPeriod6,
            };

            //
            //// Threshold Breached
            ThresholdBreached = currentBalance < Threshold
                || EndingBalance.AmountPeriod0 < Threshold
                || EndingBalance.AmountPeriod1 < Threshold
                || EndingBalance.AmountPeriod2 < Threshold
                || EndingBalance.AmountPeriod3 < Threshold
                || EndingBalance.AmountPeriod4 < Threshold
                || EndingBalance.AmountPeriod5 < Threshold
                || EndingBalance.AmountPeriod6 < Threshold;
        }
        #endregion Shared Data

        #region Dashboard
        private decimal _quickRatioBreak = 1.0m;
        public decimal QuickRatioBreak
        {
            get => _quickRatioBreak;
            set => SetProperty(ref _quickRatioBreak, value);
        }

        private decimal _quickRatio;
        public decimal QuickRatio
        {
            get => _quickRatio;
            set => SetProperty(ref _quickRatio, value);
        }

        private decimal _currentRatioBreak = 1.1m;
        public decimal CurrentRatioBreak
        {
            get => _currentRatioBreak;
            set => SetProperty(ref _currentRatioBreak, value);
        }

        private decimal _currentRatio;
        public decimal CurrentRatio
        {
            get => _currentRatio;
            set => SetProperty(ref _currentRatio, value);
        }

        private decimal _dsoMaximum = 60;
        public decimal DSOMaximum
        {
            get => _dsoMaximum;
            set => SetProperty(ref _dsoMaximum, value);
        }

        private decimal _dsoMedian = 30;
        public decimal DSOMedian
        {
            get => _dsoMedian;
            set => SetProperty(ref _dsoMedian, value);
        }

        private decimal _dso;
        public decimal DSO
        {
            get => _dso;
            set => SetProperty(ref _dso, value, new string[] { nameof(CCC) });
        }

        private decimal _dpoMaximum = 60;
        public decimal DPOMaximum
        {
            get => _dpoMaximum;
            set => SetProperty(ref _dpoMaximum, value);
        }

        private decimal _dpoMedian = 30;
        public decimal DPOMedian
        {
            get => _dpoMedian;
            set => SetProperty(ref _dpoMedian, value);
        }

        private decimal _dpo;
        public decimal DPO
        {
            get => _dpo;
            set => SetProperty(ref _dpo, value, new string[] { nameof(CCC) });
        }

        private decimal _dioMaximum = 60;
        public decimal DIOMaximum
        {
            get => _dioMaximum;
            set => SetProperty(ref _dioMaximum, value);
        }

        private decimal _dioMedian = 30;
        public decimal DIOMedian
        {
            get => _dioMedian;
            set => SetProperty(ref _dioMedian, value);
        }

        private decimal _dio;
        public decimal DIO
        {
            get => _dio;
            set => SetProperty(ref _dio, value, new string[] { nameof(CCC) });
        }

        private decimal _cccMaximum = 60;
        public decimal CCCMaximum
        {
            get => _cccMaximum;
            set => SetProperty(ref _cccMaximum, value);
        }

        private decimal _cccMedian = 30;
        public decimal CCCMedian
        {
            get => _cccMedian;
            set => SetProperty(ref _cccMedian, value);
        }

        public decimal CCC => DSO + DIO - DPO;

        private decimal _arTotalAmountDue;
        public decimal ARTotalAmountDue
        {
            get => _arTotalAmountDue;
            set => SetProperty(ref _arTotalAmountDue, value);
        }

        private decimal _arTotalAmountPaid;
        public decimal ARTotalAmountPaid
        {
            get => _arTotalAmountPaid;
            set => SetProperty(ref _arTotalAmountPaid, value);
        }

        public decimal ARC
            => (ARTotalAmountDue == 0)
            ? 1m
            : ARTotalAmountPaid / ARTotalAmountDue;

        #region Cash Flow Chart
        public BindingList<ChartData> CashFlowChartNetIn { get; } = new BindingList<ChartData>();
        public BindingList<ChartData> CashFlowChartNetOut { get; } = new BindingList<ChartData>();
        public BindingList<ChartData> CashFlowChartEndingBalance { get; } = new BindingList<ChartData>();

        private void PopuplateCashFlowChartData()
        {
            //
            //// Net In
            CashFlowChartNetIn.Clear();
            CashFlowChartNetIn.Add(new ChartData { Category = Period0Name, Value = NetAR.AmountPeriod0 });
            CashFlowChartNetIn.Add(new ChartData { Category = Period1Name, Value = NetAR.AmountPeriod1 });
            CashFlowChartNetIn.Add(new ChartData { Category = Period2Name, Value = NetAR.AmountPeriod2 });
            CashFlowChartNetIn.Add(new ChartData { Category = Period3Name, Value = NetAR.AmountPeriod3 });
            CashFlowChartNetIn.Add(new ChartData { Category = Period4Name, Value = NetAR.AmountPeriod4 });
            CashFlowChartNetIn.Add(new ChartData { Category = Period5Name, Value = NetAR.AmountPeriod5 });
            CashFlowChartNetIn.Add(new ChartData { Category = Period6Name, Value = NetAR.AmountPeriod6 });

            //
            //// Net Out
            CashFlowChartNetOut.Clear();
            CashFlowChartNetOut.Add(new ChartData { Category = Period0Name, Value = -NetAP.AmountPeriod0 });
            CashFlowChartNetOut.Add(new ChartData { Category = Period1Name, Value = -NetAP.AmountPeriod1 });
            CashFlowChartNetOut.Add(new ChartData { Category = Period2Name, Value = -NetAP.AmountPeriod2 });
            CashFlowChartNetOut.Add(new ChartData { Category = Period3Name, Value = -NetAP.AmountPeriod3 });
            CashFlowChartNetOut.Add(new ChartData { Category = Period4Name, Value = -NetAP.AmountPeriod4 });
            CashFlowChartNetOut.Add(new ChartData { Category = Period5Name, Value = -NetAP.AmountPeriod5 });
            CashFlowChartNetOut.Add(new ChartData { Category = Period6Name, Value = -NetAP.AmountPeriod6 });

            //
            //// Ending Balance
            CashFlowChartEndingBalance.Clear();
            CashFlowChartEndingBalance.Add(new ChartData { Category = Period0Name, Value = EndingBalance.AmountPeriod0 });
            CashFlowChartEndingBalance.Add(new ChartData { Category = Period1Name, Value = EndingBalance.AmountPeriod1 });
            CashFlowChartEndingBalance.Add(new ChartData { Category = Period2Name, Value = EndingBalance.AmountPeriod2 });
            CashFlowChartEndingBalance.Add(new ChartData { Category = Period3Name, Value = EndingBalance.AmountPeriod3 });
            CashFlowChartEndingBalance.Add(new ChartData { Category = Period4Name, Value = EndingBalance.AmountPeriod4 });
            CashFlowChartEndingBalance.Add(new ChartData { Category = Period5Name, Value = EndingBalance.AmountPeriod5 });
            CashFlowChartEndingBalance.Add(new ChartData { Category = Period6Name, Value = EndingBalance.AmountPeriod6 });
        }
        #endregion Cash Flow Chart

        private void PopuplateDashboardData()
        {
            decimal currentLiabilities = Balances
                .Where(b => new[] { 80, 90 }.Contains(b.GroupCode))
                .Sum(b => b.BalanceYearToDate);

            //
            //// Quick Ratio
            QuickRatio = (currentLiabilities == 0)
                ? 0
                : Balances
                .Where(b => new[] { 10, 20, 40 }.Contains(b.GroupCode))
                .Sum(b => b.BalanceYearToDate)
                / -currentLiabilities;

            //
            //// Current Ratio
            CurrentRatio = (currentLiabilities == 0)
                ? 0
                : Balances
                .Where(b => new[] { 10, 20, 30, 40 }.Contains(b.GroupCode))
                .Sum(b => b.BalanceYearToDate)
                / -currentLiabilities;

            //
            //// DSO
            decimal revenue = Balances
                .Where(g => g.GroupCode == 140)
                .Sum(g => g.BalanceYearToDate);

            DSO = (revenue == 0)
                ? 0
                : (Balances
                .Where(g => g.GroupCode == 20)
                .Sum(g => (g.BalanceOpening + g.BalanceYearToDate) / 2)
                / -revenue)
                * NumberOfDays;

            //
            //// DPO
            decimal cogs = Balances
                .Where(g => g.GroupCode == 150)
                .Sum(g => g.BalanceYearToDate);

            DPO = (cogs == 0)
                ? 0
                : (Balances
                .Where(g => g.GroupCode == 80)
                .Sum(g => (g.BalanceOpening + g.BalanceYearToDate) / 2)
                / -cogs)
                * NumberOfDays;

            //
            //// DIO
            DIO = (cogs == 0)
                ? 0
                : (Balances
                .Where(g => g.GroupCode == 30)
                .Sum(g => (g.BalanceOpening + g.BalanceYearToDate) / 2)
                / cogs)
                * NumberOfDays;

            //
            //// ARC
            ARTotalAmountDue = Transactions
                .Where(t => t.Source == "AR")
                .Sum(t => t.AmountDue);

            ARTotalAmountPaid = Transactions
                .Where(t => t.Source == "AR")
                .Sum(t => -t.AmountPaid);

            //
            //// Chart
            PopuplateCashFlowChartData();
        }
        #endregion Dashboard

        #region Cash Flow Summary
        public BindingList<Summary> CashFlowSummary { get; } = new BindingList<Summary>();

        private void PopuplateCashFlowSummaryData()
        {
            CashFlowSummary.Clear();

            CashFlowSummary.Add(OpeningBalance);
            CashFlowSummary.Add(new Summary());
            CashFlowSummary.Add(new Summary
            {
                Important = true,
                Description = "Net from Operations"
            });
            CashFlowSummary.Add(NetAR);
            CashFlowSummary.Add(NetAP);
            CashFlowSummary.Add(new Summary
            {
                Important = true,
                Description = "Net from Operations",
                AmountPeriod0 = NetAR.AmountPeriod0 + NetAP.AmountPeriod0,
                AmountPeriod1 = NetAR.AmountPeriod1 + NetAP.AmountPeriod1,
                AmountPeriod2 = NetAR.AmountPeriod2 + NetAP.AmountPeriod2,
                AmountPeriod3 = NetAR.AmountPeriod3 + NetAP.AmountPeriod3,
                AmountPeriod4 = NetAR.AmountPeriod4 + NetAP.AmountPeriod4,
                AmountPeriod5 = NetAR.AmountPeriod5 + NetAP.AmountPeriod5,
                AmountPeriod6 = NetAR.AmountPeriod6 + NetAP.AmountPeriod6,
                AmountTotal = NetAR.AmountTotal + NetAP.AmountTotal,
            });
            CashFlowSummary.Add(new Summary());
            CashFlowSummary.Add(new Summary
            {
                Important = true,
                Description = "Other Activities"
            });
            CashFlowSummary.Add(NetInFlow);
            CashFlowSummary.Add(NetOutFlow);
            CashFlowSummary.Add(new Summary
            {
                Important = true,
                Description = "Other Activities",
                AmountPeriod0 = NetInFlow.AmountPeriod0 + NetOutFlow.AmountPeriod0,
                AmountPeriod1 = NetInFlow.AmountPeriod1 + NetOutFlow.AmountPeriod1,
                AmountPeriod2 = NetInFlow.AmountPeriod2 + NetOutFlow.AmountPeriod2,
                AmountPeriod3 = NetInFlow.AmountPeriod3 + NetOutFlow.AmountPeriod3,
                AmountPeriod4 = NetInFlow.AmountPeriod4 + NetOutFlow.AmountPeriod4,
                AmountPeriod5 = NetInFlow.AmountPeriod5 + NetOutFlow.AmountPeriod5,
                AmountPeriod6 = NetInFlow.AmountPeriod6 + NetOutFlow.AmountPeriod6,
                AmountTotal = NetInFlow.AmountTotal + NetOutFlow.AmountTotal,
            });
            CashFlowSummary.Add(new Summary());
            CashFlowSummary.Add(EndingBalance);
        }
        #endregion Cash Flow Summary

        #region A/R Summary
        public BindingList<PayeeSummary> ARSummary { get; } = new BindingList<PayeeSummary>();
        
        private void PopuplateARSummaryData()
        {
            ARSummary.Clear();

            var payeeSummaries = Transactions.Where(t => t.Source == "AR")
                .GroupBy(t => t.PayeeNumber)
                .Select(g => new PayeeSummary
                {
                    PayeeNumber = g.Key,
                    Name = g.Min(t => t.PayeeName),
                    CurrencyCode = g.Min(t => t.Currency),
                    CreditLimit = g.Min(t => t.CreditLimit),
                    HighestBalance = g.Min(t => t.HighestBalance),
                    OutstandingBalance = g.Sum(t => t.AmountOutstanding)
                })
                .OrderByDescending(ar => ar.OutstandingBalance)
                .Take(10);

            int i = 0;
            foreach (var payeeSummary in payeeSummaries)
            {
                payeeSummary.Ranking = (++i).ToString();
                ARSummary.Add(payeeSummary);
            }

            if (ARSummary.Count == 10)
                ARSummary.Add(Transactions.Where(t => t.Source == "AR" && !ARSummary.Any(ar => ar.PayeeNumber == t.PayeeNumber))
                    .GroupBy(t => 1)
                    .Select(g => new PayeeSummary
                    {
                        PayeeNumber = "Others",
                        OutstandingBalance = g.Sum(t => t.AmountOutstanding)
                    }).First());
        }
        #endregion A/R Summary

        #region A/P Summary
        public BindingList<PayeeSummary> APSummary { get; } = new BindingList<PayeeSummary>();

        private void PopuplateAPSummaryData()
        {
            APSummary.Clear();

            var payeeSummaries = Transactions.Where(t => t.Source == "AP")
                .GroupBy(t => t.PayeeNumber)
                .Select(g => new PayeeSummary
                {
                    PayeeNumber = g.Key,
                    Name = g.Min(t => t.PayeeName),
                    CurrencyCode = g.Min(t => t.Currency),
                    CreditLimit = g.Min(t => t.CreditLimit),
                    HighestBalance = g.Min(t => t.HighestBalance),
                    OutstandingBalance = g.Sum(t => -t.AmountOutstanding)
                })
                .OrderByDescending(ap => ap.OutstandingBalance)
                .Take(10);

            int i = 0;
            foreach (var payeeSummary in payeeSummaries)
            {
                payeeSummary.Ranking = (++i).ToString();
                APSummary.Add(payeeSummary);
            }

            if (APSummary.Count == 10)
                APSummary.Add(Transactions.Where(t => t.Source == "AP" && !APSummary.Any(ap => ap.PayeeNumber == t.PayeeNumber))
                    .GroupBy(t => 1)
                    .Select(g => new PayeeSummary
                    {
                        PayeeNumber = "Others",
                        OutstandingBalance = g.Sum(t => -t.AmountOutstanding)
                    }).First());
        }
        #endregion A/P Summary

        #region Loans
        private string _termsAndConditions;
        public string TermsAndConditions
            => (!string.IsNullOrEmpty(_termsAndConditions)
            ? _termsAndConditions
            : (_termsAndConditions = GetTermsAndConditions()));

        private string GetTermsAndConditions()
        {
            switch (Country)
            {
                case 702: // Singapore
                    return Properties.Resources.TermsAndConditionsSG;

                case 458:
                    return Properties.Resources.TermsAndConditionsMY;

                default:
                    return string.Empty;
            }
        }

        public BindingList<Loan> Loans { get; } = new BindingList<Loan>();
        #endregion Loans
    }
}