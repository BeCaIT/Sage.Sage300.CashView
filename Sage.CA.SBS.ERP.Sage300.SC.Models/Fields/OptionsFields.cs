using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class Options
    {
        public const string EntityName = "SC0001";


        public class Fields
        {
            public const string Dummy = "DUMMY";
            public const string Contact = "CONTACT";
            public const string JobTitle = "JOBTITLE";
            public const string Email = "EMAIL";
            public const string Phone = "PHONE";
            public const string Mobile = "MOBILE";
            public const string Country = "COUNTRY";
            public const string Industry = "INDUSTRY";
            public const string EntityType = "ENTITYTYPE";
            public const string BRYear = "BRYEAR";
            public const string Threshold = "CBALTHRHD";
            public const string Period1End = "FCPERIOD1E";
            public const string Period2End = "FCPERIOD2E";
            public const string Period3End = "FCPERIOD3E";
            public const string Period4End = "FCPERIOD4E";
            public const string Period5End = "FCPERIOD5E";
            public const string IncludePendingGL = "PENDINGGL";
            public const string IncludePendingAR = "PENDINGAR";
            public const string IncludePendingAP = "PENDINGAP";
            public const string LastProcessedDate = "LPROCDATE";
            public const string LastProcessedTime = "LPROCTIME";
            public const string EmailAlert = "EMAILALERT";
            public const string EmailOffer = "EMAILOFFER";
            public const string EmailSnoozeUntil = "EMAILSNUTL";
            public const string EmailHost = "EMAILHOST";
            public const string EmailPort = "EMAILPORT";
            public const string EmailSSL = "EMAILSSL";
            public const string EmailUser = "EMAILUSER";
            public const string EmailPassword = "EMAILPSWD";
            public const string EmailAddress = "EMAILADDR";
            public const string EmailTo = "EMAILTO";
            public const string FELength = "CFELENGTH";
            public const string FEPrefix = "CFEPREFIX";
            public const string FENextNumber = "CFENEXTNBR";
            public const string BRN = "BRN";
            public const string BRYearCalculated = "BRYEARC";
            public const string FunctionalCurrency = "HOMECUR";
            public const string IndustrySG = "INDUSTRYSG";
            public const string IndustryMY = "INDUSTRYMY";
            public const string IndustryHK = "INDUSTRYHK";
            public const string IndustryAU = "INDUSTRYAU";
            public const string IndustryNZ = "INDUSTRYNZ";
            public const string EntityTypeSG = "ENTTYPESG";
            public const string EntityTypeMY = "ENTTYPEMY";
            public const string EntityTypeHK = "ENTTYPEHK";
            public const string EntityTypeAU = "ENTTYPEAU";
            public const string EntityTypeNZ = "ENTTYPENZ";
            public const string Period1Start = "FCPERIOD1S";
            public const string Period2Start = "FCPERIOD2S";
            public const string Period3Start = "FCPERIOD3S";
            public const string Period4Start = "FCPERIOD4S";
            public const string Period5Start = "FCPERIOD5S";
            public const string Period6Start = "FCPERIOD6S";
            public const string CurrentDate = "CURDATE";
            public const string CurrentYear = "CURYEAR";
            public const string CurrentPeriod = "CURPERIOD";
            public const string ReportingCurrency = "RPTCUR";
            public const string Rate = "RATE";
            public const string RateOperator = "RATEOPER";
            public const string RateDate = "RATEDATE";
            public const string EmailPasswordString = "EMAILPSWDS";
            public const string EmailTest = "EMAILTEST";
            public const string FEDocumentDefault = "CFEDOCNUMD";
            public const string FEDocumentNext = "CFEDOCNUMN";
            public const string ProcessCommand = "PROCESSCMD";
        }

        public class Indexes
        {
            public const int Dummy = 1;
            public const int Contact = 2;
            public const int JobTitle = 3;
            public const int Email = 4;
            public const int Phone = 5;
            public const int Mobile = 6;
            public const int Country = 7;
            public const int Industry = 8;
            public const int EntityType = 9;
            public const int BRYear = 10;
            public const int Threshold = 11;
            public const int Period1End = 12;
            public const int Period2End = 13;
            public const int Period3End = 14;
            public const int Period4End = 15;
            public const int Period5End = 16;
            public const int IncludePendingGL = 17;
            public const int IncludePendingAR = 18;
            public const int IncludePendingAP = 19;
            public const int LastProcessedDate = 20;
            public const int LastProcessedTime = 21;
            public const int EmailAlert = 22;
            public const int EmailOffer = 23;
            public const int EmailSnoozeUntil = 24;
            public const int EmailHost = 25;
            public const int EmailPort = 26;
            public const int EmailSLL = 27;
            public const int EmailUser = 28;
            public const int EmailPassword = 29;
            public const int EmailAddress = 30;
            public const int EmailTo = 31;
            public const int FELength = 32;
            public const int FEPrefix = 33;
            public const int FENextNumber = 34;
            public const int BRN = 50;
            public const int BRYearCalculated = 51;
            public const int FunctionalCurrency = 52;
            public const int IndustrySG = 53;
            public const int IndustryMY = 54;
            public const int IndustryHK = 55;
            public const int IndustryAU = 56;
            public const int IndustryNZ = 57;
            public const int EntityTypeSG = 58;
            public const int EntityTypeMY = 59;
            public const int EntityTypeHK = 60;
            public const int EntityTypeAU = 61;
            public const int EntityTypeNZ = 62;
            public const int Period1Start = 63;
            public const int Period2Start = 64;
            public const int Period3Start = 65;
            public const int Period4Start = 66;
            public const int Period5Start = 67;
            public const int Period6Start = 68;
            public const int CurrentDate = 69;
            public const int CurrentYear = 70;
            public const int CurrentPeriod = 71;
            public const int ReportingCurrency = 72;
            public const int Rate = 73;
            public const int RateOperator = 74;
            public const int RateDate = 75;
            public const int EmailPasswordString = 76;
            public const int EmailTest = 77;
            public const int FEDocumentDefault = 78;
            public const int FEDocumentNext = 79;
            public const int ProcessCommand = 80;
        }
    }
}
