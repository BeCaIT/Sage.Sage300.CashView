using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Data
{
    public class Transaction : BaseDataModel
    {
        private RecordType _recordType;
        public RecordType RecordType
        {
            get => _recordType;
            set => SetProperty(ref _recordType, value);
        }

        private string _source;
        public string Source
        {
            get => _source;
            set => SetProperty(ref _source, value);
        }

        private string _payeeNumber;
        public string PayeeNumber
        {
            get => _payeeNumber;
            set => SetProperty(ref _payeeNumber, value);
        }

        private string _payeeName;
        public string PayeeName
        {
            get => _payeeName;
            set => SetProperty(ref _payeeName, value);
        }

        private string _documentNumber;
        public string DocumentNumber
        {
            get => _documentNumber;
            set => SetProperty(ref _documentNumber, value);
        }

        private decimal _paymentNumber;
        public decimal PaymentNumber
        {
            get => _paymentNumber;
            set => SetProperty(ref _paymentNumber, value);
        }

        private DateTime _documentDate;
        public DateTime DocumentDate
        {
            get => _documentDate;
            set => SetProperty(ref _documentDate, value);
        }

        private DateTime _dueDate;
        public DateTime DueDate
        {
            get => _dueDate;
            set => SetProperty(ref _dueDate, value, new string[] { nameof(DaysToPay) });
        }

        private string _description;
        public string Description
        {
            get => _description;
            set => SetProperty(ref _description, value);
        }

        private decimal _amountDue;
        public decimal AmountDue
        {
            get => _amountDue;
            set => SetProperty(ref _amountDue, value, 
                new string[] 
                {
                    nameof(AmountOutstanding),
                    nameof(AmountPeriod0),
                    nameof(AmountPeriod1),
                    nameof(AmountPeriod2),
                    nameof(AmountPeriod3),
                    nameof(AmountPeriod4),
                    nameof(AmountPeriod5),
                    nameof(AmountPeriod6),
                });
        }

        private decimal _amountPaid;
        public decimal AmountPaid
        {
            get => _amountPaid;
            set => SetProperty(ref _amountPaid, value,
                new string[]
                {
                    nameof(AmountOutstanding),
                    nameof(AmountPeriod0),
                    nameof(AmountPeriod1),
                    nameof(AmountPeriod2),
                    nameof(AmountPeriod3),
                    nameof(AmountPeriod4),
                    nameof(AmountPeriod5),
                    nameof(AmountPeriod6),
                });
        }

        public decimal AmountOutstanding
            => AmountDue + AmountPaid;

        public int DaysToPay
            => (DueDate - DateTime.Now.Date).Days;

        public decimal AmountPeriod0
            => (DaysToPay <= 0)
            ? AmountOutstanding
            : 0;

        public decimal AmountPeriod1
            => (DaysToPay > 0 
            && DaysToPay <= ApplicationData.Current.Period1End)
            ? AmountOutstanding
            : 0;

        public decimal AmountPeriod2
            => (DaysToPay > ApplicationData.Current.Period1End 
            && DaysToPay <= ApplicationData.Current.Period2End)
            ? AmountOutstanding
            : 0;

        public decimal AmountPeriod3
            => (DaysToPay > ApplicationData.Current.Period2End 
            && DaysToPay <= ApplicationData.Current.Period3End)
            ? AmountOutstanding
            : 0;

        public decimal AmountPeriod4
            => (DaysToPay > ApplicationData.Current.Period3End 
            && DaysToPay <= ApplicationData.Current.Period4End)
            ? AmountOutstanding
            : 0;

        public decimal AmountPeriod5
            => (DaysToPay > ApplicationData.Current.Period4End 
            && DaysToPay <= ApplicationData.Current.Period5End)
            ? AmountOutstanding
            : 0;

        public decimal AmountPeriod6
            => (DaysToPay > ApplicationData.Current.Period5End)
            ? AmountOutstanding
            : 0;

        #region Extra Properties
        private string _contact;
        public string Contact
        {
            get => _contact;
            set => SetProperty(ref _contact, value);
        }

        private string _currency;
        public string Currency
        {
            get => _currency;
            set => SetProperty(ref _currency, value);
        }

        private decimal _creditLimit;
        public decimal CreditLimit
        {
            get => _creditLimit;
            set => SetProperty(ref _creditLimit, value);
        }

        private decimal _highestBalance;
        public decimal HighestBalance
        {
            get => _highestBalance;
            set => SetProperty(ref _highestBalance, value);
        }

        private decimal _averageDaysToPay;
        public decimal AverageDaysToPay
        {
            get => _averageDaysToPay;
            set => SetProperty(ref _averageDaysToPay, value);
        }
        #endregion Extra Properties
    }
}