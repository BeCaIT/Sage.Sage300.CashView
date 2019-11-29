using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Data
{
    public class Summary : BaseDataModel
    {
        private bool _important;
        public bool Important
        {
            get => _important;
            set => SetProperty(ref _important, value);
        }

        private string _description;
        public string Description
        {
            get => _description;
            set => SetProperty(ref _description, value);
        }

        private decimal _amountPeriod0;
        public decimal AmountPeriod0
        {
            get => _amountPeriod0;
            set => SetProperty(ref _amountPeriod0, value);
        }

        private decimal _amountPeriod1;
        public decimal AmountPeriod1
        {
            get => _amountPeriod1;
            set => SetProperty(ref _amountPeriod1, value);
        }

        private decimal _amountPeriod2;
        public decimal AmountPeriod2
        {
            get => _amountPeriod2;
            set => SetProperty(ref _amountPeriod2, value);
        }

        private decimal _amountPeriod3;
        public decimal AmountPeriod3
        {
            get => _amountPeriod3;
            set => SetProperty(ref _amountPeriod3, value);
        }

        private decimal _amountPeriod4;
        public decimal AmountPeriod4
        {
            get => _amountPeriod4;
            set => SetProperty(ref _amountPeriod4, value);
        }

        private decimal _amountPeriod5;
        public decimal AmountPeriod5
        {
            get => _amountPeriod5;
            set => SetProperty(ref _amountPeriod5, value);
        }

        private decimal _amountPeriod6;
        public decimal AmountPeriod6
        {
            get => _amountPeriod6;
            set => SetProperty(ref _amountPeriod6, value);
        }

        private decimal _amountTotal;
        public decimal AmountTotal
        {
            get => _amountTotal;
            set => SetProperty(ref _amountTotal, value);
        }
    }
}
