using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class ForecastEntry
    {
        public const string EntityName = "SC0110";

        #region Fields
        public class Fields
        {
            public const string RecordType = "RECTYPE";
            public const string Source = "SOURCE";
            public const string CustomerVendor = "CUSTVEND";
            public const string DocumentNumber = "DOCNUM";
            public const string PaymentNumber = "PAYMENTNBR";
            public const string EffectiveDate = "DATEDUE";
            public const string Description = "DOCDESC";
            public const string AmountDue = "AMTDUEHC";
            public const string AmountPaid = "AMTPAIDHC";
        }
        #endregion Fields

        #region Index
        public class Index
        {
            public const int RecordType = 1;
            public const int Source = 2;
            public const int CustomerVendor = 3;
            public const int DocumentNumber = 4;
            public const int PaymentNumber = 5;
            public const int EffectiveDate = 9;
            public const int Description = 8;
            public const int AmountDue = 10;
            public const int AmountPaid = 11;
        }
        #endregion Index
    }
}
