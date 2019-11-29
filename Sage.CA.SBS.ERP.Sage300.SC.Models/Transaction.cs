using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public class Transaction : ApplicationModelBase
    {
        public RecordType RecordType { get; set; }
        public string Source { get; set; }
        public string PayeeNumber { get; set; } 
        public string PayeeName { get; set; }
        public string DocumentNumber { get; set; }  
        public decimal PaymentNumber { get; set; }
        public DateTime DocumentDate { get; set; }  
        public DateTime DueDate { get; set; }
        public string Description { get; set; }
        public decimal AmountDue { get; set; }
        public decimal AmountPaid { get; set; }
        public string Contact { get; set; } 
        public string Currency { get; set; }
        public decimal CreditLimit { get; set; }
        public decimal HighestBalance { get; set; } 
        public decimal AverageDaysToPay { get; set; }
    }
}
