using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Data
{
    public class PayeeSummary : BaseDataModel
    {
        private string _ranking;
        public string Ranking
        {
            get => _ranking;
            set => SetProperty(ref _ranking, value);
        }

        private string _payeeNumber;
        public string PayeeNumber
        {
            get => _payeeNumber;
            set => SetProperty(ref _payeeNumber, value);
        }

        private string _name;
        public string Name
        {
            get => _name;
            set => SetProperty(ref _name, value);
        }

        private string _currencyCode;
        public string CurrencyCode
        {
            get => _currencyCode;
            set => SetProperty(ref _currencyCode, value, new string[] { nameof(CreditLimitString) });
        }

        private decimal _creditLimit;
        public decimal CreditLimit
        {
            get => _creditLimit;
            set => SetProperty(ref _creditLimit, value, new string[] { nameof(CreditLimitString) });
        }

        public string CreditLimitString
            => string.IsNullOrEmpty(_currencyCode)
            ? string.Empty
            : _currencyCode + " " + _creditLimit.ToString("n");

        private decimal _highestBalance;
        public decimal HighestBalance
        {
            get => _highestBalance;
            set => SetProperty(ref _highestBalance, value);
        }

        private decimal _outstandingBalance;
        public decimal OutstandingBalance
        {
            get => _outstandingBalance;
            set => SetProperty(ref _outstandingBalance, value);
        }
    }
}