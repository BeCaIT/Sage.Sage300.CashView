using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class Account
    {
        public const string EntityName = "SC0010";

        public class Fields
        {
            public const string AccountNumber = "ACCTID";
            public const string Include = "INCLUDE";
            public const string AccountExists = "ACCTEXISTS";
            public const string AccountNumberFormatted = "ACCTFMTTD";
            public const string AccountDescription = "ACCTDESC";
            public const string AmountBalance = "AMTBALHC";
            public const string ProcessCommand = "PROCESSCMD";
        }

        public class Index
        {
            public const int AccountNumber = 1;
            public const int Include = 2;
            public const int AccountExists = 10;
            public const int AccountNumberFormatted = 11;
            public const int AccountDescription = 12;
            public const int AmountBalance = 13;
            public const int ProcessCommand = 14;
        }
    }
}
