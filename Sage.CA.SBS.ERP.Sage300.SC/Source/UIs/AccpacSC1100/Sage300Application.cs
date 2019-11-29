using AccpacCOMAPI;
using AccpacReportViewer;
using Sage.CA.SBS.ERP.Sage300.SC.Data;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100
{
    internal class Sage300Application : IDisposable
    {
        /// <summary>
        /// Singleton instance
        /// </summary>
        internal static Sage300Application Current { get; private set; }

        #region Properties
        private int _signOnId;
        public int SignOnId
            => _signOnId;

        private int _objectHandle = 0;
        public int ObjectHandle
            => _objectHandle;

        private AccpacSession _session;
        public AccpacSession Session
            => _session;

        private AccpacDBLink _dbLinkCmpRO;
        public AccpacDBLink DbLinkCmpRO
            => _dbLinkCmpRO
            ?? (_dbLinkCmpRO = Session.OpenDBLink(tagDBLinkTypeEnum.DBLINK_COMPANY, tagDBLinkFlagsEnum.DBLINK_FLG_READONLY));

        private AccpacDBLink _dbLinkCmpRW;
        public AccpacDBLink DbLinkCmpRW
            => _dbLinkCmpRW
            ?? (_dbLinkCmpRW = Session.OpenDBLink(tagDBLinkTypeEnum.DBLINK_COMPANY, tagDBLinkFlagsEnum.DBLINK_FLG_READWRITE));
        #endregion Properties

        internal Sage300Application(string objectHandle)
        {
            if (!Int32.TryParse(objectHandle, out _objectHandle))
                _objectHandle = 0;

            AccpacSessionManager.AccpacSessionMgr sessionManager = null;

            try
            {
                sessionManager = new AccpacSessionManager.AccpacSessionMgr
                {
                    AppID = "SC",
                    AppVersion = "63A",
                    ProgramName = "SC1100"
                };
                sessionManager.CreateSession(objectHandle, ref _signOnId, out _session);

                EnsureOptionDefined();

                Load_Permissions();

                if (!ApplicationData.Current.HasInquiryRight)
                    throw new ApplicationException("You do not have permission to use this feature");

                Current = this;
            }
            catch (Exception ex)
            {
                Session.Errors.Put(ex.Message, tagErrorPriority.ERRPRI_ERROR);

                ReportErrors();
            }
            finally
            {
                if (sessionManager != null)
                {
                    Marshal.ReleaseComObject(sessionManager);
                    sessionManager = null;
                }
            }
        }

        #region IDisposable Support
        private bool disposedValue = false; // To detect redundant calls

        protected virtual void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                if (disposing)
                {
                    // TODO: dispose managed state (managed objects).
                }

                // TODO: free unmanaged resources (unmanaged objects) and override a finalizer below.
                // TODO: set large fields to null.
                if (_dbLinkCmpRW != null)
                {
                    _dbLinkCmpRW.Close();
                    Marshal.ReleaseComObject(_dbLinkCmpRW);
                    _dbLinkCmpRW = null;
                }

                if (_dbLinkCmpRO != null)
                {
                    _dbLinkCmpRO.Close();
                    Marshal.ReleaseComObject(_dbLinkCmpRO);
                    _dbLinkCmpRO = null;
                }

                if (_session != null)
                {
                    _session.Close();
                    Marshal.ReleaseComObject(_session);
                    _session = null;
                }

                disposedValue = true;
            }
        }

        // TODO: override a finalizer only if Dispose(bool disposing) above has code to free unmanaged resources.
        ~Sage300Application()
        {
            // Do not change this code. Put cleanup code in Dispose(bool disposing) above.
            Dispose(false);
        }

        // This code added to correctly implement the disposable pattern.
        public void Dispose()
        {
            // Do not change this code. Put cleanup code in Dispose(bool disposing) above.
            Dispose(true);
            // TODO: uncomment the following line if the finalizer is overridden above.
            GC.SuppressFinalize(this);
        }
        #endregion

        #region Permissions
        private void Load_Permissions()
        {
            if (DbLinkCmpRO.SecCheck("**ADMIN**"))
            {
                ApplicationData.Current.HasInquiryRight = true;
                ApplicationData.Current.HasProcessRight = true;
                ApplicationData.Current.HasForecastEntryRight = true;
                ApplicationData.Current.HasLoanInquiryRight = true;
                ApplicationData.Current.HasLoanEntryRight = true;
            }
            else
            {
                ApplicationData.Current.HasInquiryRight = DbLinkCmpRO.SecCheck(ApplicationData.RIGHT_SCINQUIRY);
                ApplicationData.Current.HasProcessRight = DbLinkCmpRO.SecCheck(ApplicationData.RIGHT_SCPROCESS);
                ApplicationData.Current.HasForecastEntryRight = DbLinkCmpRO.SecCheck(ApplicationData.RIGHT_SCFCENTRY);
                ApplicationData.Current.HasLoanInquiryRight = DbLinkCmpRO.SecCheck(ApplicationData.RIGHT_SCLINQUIRY);
                ApplicationData.Current.HasLoanEntryRight = DbLinkCmpRO.SecCheck(ApplicationData.RIGHT_SCLENTRY);
            }
        }
        #endregion Permissions

        #region Data
        internal void ReProcessData()
        {
            AccpacView vSCPRO = null;

            try
            {
                DbLinkCmpRW.OpenView("SC0800", out vSCPRO);

                vSCPRO.Fields.FieldByName["PROCESSCMD"].PutWithoutVerification(1);
                vSCPRO.Process();
            }
            catch (COMException)
            {
                ReportErrors();
            }
            finally
            {
                if (vSCPRO != null)
                {
                    vSCPRO.Close();
                    Marshal.ReleaseComObject(vSCPRO);
                    vSCPRO = null;
                }
            }

            LoadData();
        }

        internal void LoadData()
        {
            try
            {
                //
                //// Load Settings
                LoadData_ApplicationSettings();

                //
                //// Load Options
                LoadData_Options();

                //
                //// Load Accounts
                LoadData_Accounts();

                //
                //// Load Balances
                LoadData_Balances();

                //
                //// Load Transactions
                LoadData_Transactions();

                //
                //// Load Loan Records
                //LoadData_Loans();

                //
                //// UI Settings
                LoadData_UISettings();

                //
                ////
                ApplicationData.Current.PopuplateData();
            }
            catch (COMException)
            {
                ReportErrors();
            }
        }

        private void LoadData_ApplicationSettings()
        {
            string buffer;
            decimal value;

            //
            //// Quick Ratio
            Session.GetIniFileKey(Session.AppID, "Dashboard", "QuickRatioBreak", out buffer);
            if (decimal.TryParse(buffer, out value))
                ApplicationData.Current.QuickRatioBreak = value;

            //
            //// Current Ratio
            Session.GetIniFileKey(Session.AppID, "Dashboard", "CurrentRatioBreak", out buffer);
            if (decimal.TryParse(buffer, out value))
                ApplicationData.Current.CurrentRatioBreak = value;

            //
            //// DSO Maximum
            Session.GetIniFileKey(Session.AppID, "Dashboard", "DSOMaximum", out buffer);
            if (decimal.TryParse(buffer, out value))
                ApplicationData.Current.DSOMaximum = value;

            //
            //// DSO Median
            Session.GetIniFileKey(Session.AppID, "Dashboard", "DSOMedian", out buffer);
            if (decimal.TryParse(buffer, out value))
                ApplicationData.Current.DSOMedian = value;

            //
            //// DPO Maximum
            Session.GetIniFileKey(Session.AppID, "Dashboard", "DPOMaximum", out buffer);
            if (decimal.TryParse(buffer, out value))
                ApplicationData.Current.DPOMaximum = value;

            //
            //// DPO Median
            Session.GetIniFileKey(Session.AppID, "Dashboard", "DPOMedian", out buffer);
            if (decimal.TryParse(buffer, out value))
                ApplicationData.Current.DPOMedian = value;
        }

        private void LoadData_Options()
        {
            AccpacView vSCOPT = null;

            try
            {
                DbLinkCmpRO.OpenView("SC0001", out vSCOPT);

                if (vSCOPT.Read())
                {
                    ApplicationData.Current.Country = (short)vSCOPT.Fields.FieldByName["COUNTRY"].get_Value();
                    // Threshold
                    ApplicationData.Current.Threshold = (decimal)vSCOPT.Fields.FieldByName["CBALTHRHD"].get_Value();

                    // Forecast Periods
                    ApplicationData.Current.Period1End = (short)vSCOPT.Fields.FieldByName["FCPERIOD1E"].get_Value();
                    ApplicationData.Current.Period2End = (short)vSCOPT.Fields.FieldByName["FCPERIOD2E"].get_Value();
                    ApplicationData.Current.Period3End = (short)vSCOPT.Fields.FieldByName["FCPERIOD3E"].get_Value();
                    ApplicationData.Current.Period4End = (short)vSCOPT.Fields.FieldByName["FCPERIOD4E"].get_Value();
                    ApplicationData.Current.Period5End = (short)vSCOPT.Fields.FieldByName["FCPERIOD5E"].get_Value();

                    // Current Year/Period
                    ApplicationData.Current.CurrentYear = (string)vSCOPT.Fields.FieldByName["CURYEAR"].get_Value();
                    ApplicationData.Current.CurrentPeriod = (short)vSCOPT.Fields.FieldByName["CURPERIOD"].get_Value();

                    DbLinkCmpRO.GetFiscalCalendar().GetYearDates(ApplicationData.Current.CurrentYear, out DateTime startDate, out DateTime endDate);
                    ApplicationData.Current.CurrentYearStartDate = startDate;
                }
            }
            catch (Exception ex)
            {
                Session.Errors.Put(ex.Message, tagErrorPriority.ERRPRI_ERROR);
                ReportErrors();
            }
            finally
            {
                if (vSCOPT != null)
                {
                    vSCOPT.Close();
                    Marshal.ReleaseComObject(vSCOPT);
                    vSCOPT = null;
                }
            }
        }

        private void LoadData_Accounts()
        {
            AccpacView vSCACCT = null;

            try
            {
                ApplicationData.Current.Accounts.Clear();

                DbLinkCmpRO.OpenView("SC0010", out vSCACCT);

                vSCACCT.Browse(string.Empty, true);
                while (vSCACCT.Fetch())
                    ApplicationData.Current.Accounts.Add(new Account
                    {
                        AccountNumber = (string)vSCACCT.Fields.FieldByName["ACCTFMTTD"].get_Value(),
                        Description = (string)vSCACCT.Fields.FieldByName["ACCTDESC"].get_Value(),
                        Include = ((short)vSCACCT.Fields.FieldByName["INCLUDE"].get_Value() == 1),
                        Balance = (decimal)vSCACCT.Fields.FieldByName["AMTBALHC"].get_Value(),
                    });
            }
            catch (Exception ex)
            {
                Session.Errors.Put(ex.Message, tagErrorPriority.ERRPRI_ERROR);
                ReportErrors();
            }
            finally
            {
                if (vSCACCT != null)
                {
                    vSCACCT.Close();
                    Marshal.ReleaseComObject(vSCACCT);
                    vSCACCT = null;
                }
            }
        }

        private void LoadData_Balances()
        {
            AccpacView vSCBAL = null;

            try
            {
                ApplicationData.Current.Balances.Clear();

                DbLinkCmpRO.OpenView("SC0100", out vSCBAL);

                vSCBAL.Browse(string.Format("FSCYEAR=\"{0}\"", ApplicationData.Current.CurrentYear), true);
                while (vSCBAL.Fetch())
                    ApplicationData.Current.Balances.Add(new Balance
                    {
                        RecordType = (RecordType)Enum.ToObject(typeof(RecordType), (short)vSCBAL.Fields.FieldByName["RECTYPE"].get_Value()),
                        GroupCode = (short)vSCBAL.Fields.FieldByName["GRPCOD"].get_Value(),
                        NetPeriod1 = (decimal)vSCBAL.Fields.FieldByName["NETPERD1"].get_Value(),
                        NetPeriod2 = (decimal)vSCBAL.Fields.FieldByName["NETPERD2"].get_Value(),
                        NetPeriod3 = (decimal)vSCBAL.Fields.FieldByName["NETPERD3"].get_Value(),
                        NetPeriod4 = (decimal)vSCBAL.Fields.FieldByName["NETPERD4"].get_Value(),
                        NetPeriod5 = (decimal)vSCBAL.Fields.FieldByName["NETPERD5"].get_Value(),
                        NetPeriod6 = (decimal)vSCBAL.Fields.FieldByName["NETPERD6"].get_Value(),
                        NetPeriod7 = (decimal)vSCBAL.Fields.FieldByName["NETPERD7"].get_Value(),
                        NetPeriod8 = (decimal)vSCBAL.Fields.FieldByName["NETPERD8"].get_Value(),
                        NetPeriod9 = (decimal)vSCBAL.Fields.FieldByName["NETPERD9"].get_Value(),
                        NetPeriod10 = (decimal)vSCBAL.Fields.FieldByName["NETPERD10"].get_Value(),
                        NetPeriod11 = (decimal)vSCBAL.Fields.FieldByName["NETPERD11"].get_Value(),
                        NetPeriod12 = (decimal)vSCBAL.Fields.FieldByName["NETPERD12"].get_Value(),
                        NetPeriod13 = (decimal)vSCBAL.Fields.FieldByName["NETPERD13"].get_Value(),
                        NetPeriod14 = (decimal)vSCBAL.Fields.FieldByName["NETPERD14"].get_Value(),
                        NetPeriod15 = (decimal)vSCBAL.Fields.FieldByName["NETPERD15"].get_Value(),
                        NetYear = (decimal)vSCBAL.Fields.FieldByName["NETYEAR"].get_Value(),
                        NetYearToDate = (decimal)vSCBAL.Fields.FieldByName["NETYTD"].get_Value(),
                        BalanceOpening = (decimal)vSCBAL.Fields.FieldByName["BALOPEN"].get_Value(),
                        BalancePeriod1 = (decimal)vSCBAL.Fields.FieldByName["BALPERD1"].get_Value(),
                        BalancePeriod2 = (decimal)vSCBAL.Fields.FieldByName["BALPERD2"].get_Value(),
                        BalancePeriod3 = (decimal)vSCBAL.Fields.FieldByName["BALPERD3"].get_Value(),
                        BalancePeriod4 = (decimal)vSCBAL.Fields.FieldByName["BALPERD4"].get_Value(),
                        BalancePeriod5 = (decimal)vSCBAL.Fields.FieldByName["BALPERD5"].get_Value(),
                        BalancePeriod6 = (decimal)vSCBAL.Fields.FieldByName["BALPERD6"].get_Value(),
                        BalancePeriod7 = (decimal)vSCBAL.Fields.FieldByName["BALPERD7"].get_Value(),
                        BalancePeriod8 = (decimal)vSCBAL.Fields.FieldByName["BALPERD8"].get_Value(),
                        BalancePeriod9 = (decimal)vSCBAL.Fields.FieldByName["BALPERD9"].get_Value(),
                        BalancePeriod10 = (decimal)vSCBAL.Fields.FieldByName["BALPERD10"].get_Value(),
                        BalancePeriod11 = (decimal)vSCBAL.Fields.FieldByName["BALPERD11"].get_Value(),
                        BalancePeriod12 = (decimal)vSCBAL.Fields.FieldByName["BALPERD12"].get_Value(),
                        BalancePeriod13 = (decimal)vSCBAL.Fields.FieldByName["BALPERD13"].get_Value(),
                        BalancePeriod14 = (decimal)vSCBAL.Fields.FieldByName["BALPERD14"].get_Value(),
                        BalancePeriod15 = (decimal)vSCBAL.Fields.FieldByName["BALPERD15"].get_Value(),
                        BalanceYearToDate = (decimal)vSCBAL.Fields.FieldByName["BALYTD"].get_Value(),
                    });
            }
            catch (Exception ex)
            {
                Session.Errors.Put(ex.Message, tagErrorPriority.ERRPRI_ERROR);
                ReportErrors();
            }
            finally
            {
                if (vSCBAL != null)
                {
                    vSCBAL.Close();
                    Marshal.ReleaseComObject(vSCBAL);
                    vSCBAL = null;
                }
            }
        }

        private void LoadData_Transactions()
        {
            AccpacView vSCTRAN = null;

            try
            {
                ApplicationData.Current.Transactions.Clear();

                DbLinkCmpRO.OpenView("CS0120", out vSCTRAN);

                vSCTRAN.Browse(
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
                vSCTRAN.InternalSet(256);
                while (vSCTRAN.Fetch())
                    ApplicationData.Current.Transactions.Add(new Transaction
                    {
                        RecordType = (RecordType)Enum.ToObject(typeof(RecordType), (short)vSCTRAN.Fields.FieldByName["RECTYPE"].get_Value()),
                        Source = (string)vSCTRAN.Fields.FieldByName["SOURCE"].get_Value(),
                        PayeeNumber = (string)vSCTRAN.Fields.FieldByName["CUSTVEND"].get_Value(),
                        PayeeName = (string)vSCTRAN.Fields.FieldByName["PAYEE"].get_Value(),
                        DocumentNumber = (string)vSCTRAN.Fields.FieldByName["DOCNUM"].get_Value(),
                        PaymentNumber = (decimal)vSCTRAN.Fields.FieldByName["PAYMENTNBR"].get_Value(),
                        DocumentDate = DateTime.ParseExact(Convert.ToString(vSCTRAN.Fields.FieldByName["DOCDATE"].get_Value()), "yyyyMMdd", CultureInfo.InvariantCulture),
                        DueDate = DateTime.ParseExact(Convert.ToString(vSCTRAN.Fields.FieldByName["DATEDUE"].get_Value()), "yyyyMMdd", CultureInfo.InvariantCulture),
                        Description = (string)vSCTRAN.Fields.FieldByName["DOCDESC"].get_Value(),
                        AmountDue = (decimal)vSCTRAN.Fields.FieldByName["AMTDUEHC"].get_Value(),
                        AmountPaid = (decimal)vSCTRAN.Fields.FieldByName["AMTPAIDHC"].get_Value(),
                        Contact = (string)vSCTRAN.Fields.FieldByName["CONTACT"].get_Value(),
                        Currency = (string)vSCTRAN.Fields.FieldByName["CURRENCY"].get_Value(),
                        CreditLimit = (decimal)vSCTRAN.Fields.FieldByName["CRLIMIT"].get_Value(),
                        HighestBalance = (decimal)vSCTRAN.Fields.FieldByName["BALHIGHEST"].get_Value(),
                        AverageDaysToPay = (decimal)vSCTRAN.Fields.FieldByName["DAYSTOPAY"].get_Value(),
                    });
            }
            catch (Exception ex)
            {
                Session.Errors.Put(ex.Message, tagErrorPriority.ERRPRI_ERROR);
                ReportErrors();
            }
            finally
            {
                if (vSCTRAN != null)
                {
                    vSCTRAN.Close();
                    Marshal.ReleaseComObject(vSCTRAN);
                    vSCTRAN = null;
                }
            }
        }

        private void LoadData_UISettings()
        {
            AccpacProperty propThresholdAlert = null;
            AccpacView vSCLOAN = null;

            try
            {
                //
                ////
                propThresholdAlert = Session.GetAccpacProperty();
                object snoozeUntil = "00000000";
                propThresholdAlert.objectID = propThresholdAlert.menuID = Session.ProgramName;                 
                propThresholdAlert.keyword = "SNOOZEALERT";
                propThresholdAlert.PropGet(ref snoozeUntil, tagPropertyType.PROP_AS_STRING);
                DateTime dtSnoozeAlertUntil = DateTime.MinValue;
                if (DateTime.TryParseExact((string)snoozeUntil, "yyyyMMdd", null, DateTimeStyles.None, out dtSnoozeAlertUntil))
                    ApplicationData.Current.ThresholdAlertSnooze = dtSnoozeAlertUntil;

                //
                //// New Loan Record
                DbLinkCmpRO.OpenView("SC0200", out vSCLOAN);
                // Has Loan Records
                ApplicationData.Current.HasLoanRecords = (vSCLOAN.FilterCount(string.Empty, 0) > 0);
                // Has New Loan Records
                ApplicationData.Current.HasNewLoanRecord = (vSCLOAN.FilterCount("(STATUS = 0)", 0) > 0);
            }
            catch (COMException)
            {
                ReportErrors();
            }
            finally
            {
                if (vSCLOAN != null)
                {
                    vSCLOAN.Close();
                    Marshal.ReleaseComObject(vSCLOAN);
                    vSCLOAN = null;
                }

                if (propThresholdAlert != null)
                {
                    Marshal.ReleaseComObject(propThresholdAlert);
                    propThresholdAlert = null;
                }
            }
        }
        #endregion Data

        #region Report
        internal void PrintReport(string reportName, int hWnd, Dictionary<string, string> parameters)
        {
            AccpacReport report = null;
            AccpacPrintReport printReport = null;

            try
            {
                //
                //// Load Report
                report = Session.ReportSelect(reportName, Session.ProgramName, Session.ProgramName);
                //
                //// Set Parameters
                if (parameters != null)
                    foreach (var parameter in parameters)
                        report.SetParam(parameter.Key, parameter.Value);
                //
                //// Print report: We ignore all logic of using Process server & Web Report as they are no-longer applicable
                if (report.Confirm(true, hWnd))
                {
                    if (report.PrintReport())
                    {
                        printReport = new AccpacPrintReport();
                        printReport.ReportViewer(Session, report.WebReportURL);
                    }
                }
            }
            catch (COMException)
            {
                ReportErrors();
            }
            finally
            {
                if (printReport != null)
                {
                    Marshal.ReleaseComObject(printReport);
                    printReport = null;
                }

                if (report != null)
                {
                    Marshal.ReleaseComObject(report);
                    report = null;
                }
            }
        }
        #endregion Report

        #region Helpers
        private void EnsureOptionDefined()
        {
            AccpacView vSCOPT = null;

            try
            {
                DbLinkCmpRO.OpenView("SC0001", out vSCOPT);
                if (!vSCOPT.Read())
                {
                    //Session.Errors.Put("Incorrect Procedure. Options are not defined. Please check with your system Administrator", tagErrorPriority.ERRPRI_ERROR);
                    //ReportErrors();

                    throw new ApplicationException("Incorrect Procedure. Options are not defined. Please check with your system Administrator");
                }
            }
            catch (COMException)
            {
                Session.Errors.Put("Incorrect Procedure. Options are not defined. Please check with your system Administrator", tagErrorPriority.ERRPRI_ERROR);
                ReportErrors();
            }
            finally
            {
                if (vSCOPT != null)
                {
                    vSCOPT.Close();
                    Marshal.ReleaseComObject(vSCOPT);
                    vSCOPT = null;
                }
            }
        }

        internal void ReportErrors(bool clearErrors = true)
        {
            if (Session?.Errors?.Count <= 0)
                return;

            AccpacErrorReport errorReport = null;

            try
            {
                errorReport = new AccpacErrorReport();
                errorReport.ShowError(Session);

                if (clearErrors)
                    Session.Errors.Clear();
            }
            catch { }
            finally
            {
                if (errorReport != null)
                {
                    Marshal.ReleaseComObject(errorReport);
                    errorReport = null;
                }
            }
        }
        #endregion Helpers
    }
}
