using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class Loan
    {
        /// <summary>
        /// Entity Name
        /// </summary>
        public const string EntityName = "SC0200";

        #region Fields
        public class Fields
        {
            public const string LoanNumber = "LOANNUM";
            public const string Status = "STATUS";
            public const string Reference = "REFERENCE";
            public const string DateOffered = "DTOFFER";
            public const string DateSubmitted = "DTSUBMIT";
            public const string UserSubmitted = "USRSUBMIT";
            public const string EmailSubmitted = "EMLSUBMIT";
            public const string AmountOffer = "AMTOFFER";
            public const string AmountRequest = "AMTREQUEST";
            public const string Contact = "CONTACT";
            public const string JobTitle = "JOBTITLE";
            public const string Email = "EMAIL";
            public const string Phone = "PHONE";
            public const string Mobile = "MOBILE";
            public const string Message = "MESSAGE";
            public const string CompanyName = "COMPNAME";
            public const string Address1 = "ADDRESS1";
            public const string Address2 = "ADDRESS2";
            public const string Address3 = "ADDRESS3";
            public const string Address4 = "ADDRESS4";
            public const string City = "CITY";
            public const string State = "STATE";
            public const string Country = "COUNTRY";
            public const string PostalCode = "POSTAL";
            public const string EmailCC = "EMAILCC";
            public const string BRN = "BRN";
            public const string Currency = "RPTCUR";
            public const string EmailSubject = "EMAILSUBJ";
            public const string EmailFrom = "EMAILFROM";
            public const string EmailTo = "EMAILTO";
        }
        #endregion Fields

        #region Index
        public class Index
        {
            public const int LoanNumber = 1;
            public const int Status = 2;
            public const int Reference = 3;
            public const int DateOffered = 4;
            public const int DateSubmitted = 5;
            public const int UserSubmitted = 6;
            public const int EmailSubmitted = 7;
            public const int AmountOffer = 8;
            public const int AmountRequest = 9;
            public const int Contact = 10;
            public const int JobTitle = 11;
            public const int Email = 12;
            public const int Phone = 13;
            public const int Mobile = 14;
            public const int Message = 15;
            public const int CompanyName = 16;
            public const int Address1 = 17;
            public const int Address2 = 18;
            public const int Address3 = 19;
            public const int Address4 = 20;
            public const int City = 21;
            public const int State = 22;
            public const int Country = 23;
            public const int PostalCode = 24;
            public const int EmailCC = 25;
            public const int BRN = 35;
            public const int Currency = 36;
            public const int EmailSubject = 37;
            public const int EmailFrom = 38;
            public const int EmailTo = 39;
        }
        #endregion Index
    }
}