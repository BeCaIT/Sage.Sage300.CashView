using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Attributes;
using Sage.CA.SBS.ERP.Sage300.Common.Resources;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class ForecastEntry : ModelBase
    {
        public RecordType RecordType { get; set; }
        public string Source { get; set; }
        public string CustomerVendor { get; set; }
        [Key]
        public string DocumentNumber { get; set; }
        public decimal PaymentNumber { get; set; }

        [ValidateDateFormat(ErrorMessageResourceName = "DateFormat", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public DateTime EffectiveDate { get; set; }

        [StringLength(60, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Description { get; set; }

        private decimal _amountDue;
        public decimal AmountDue
        {
            get => _amountDue;
            set
            {
                _amountDue = value;
                if (_amountDue > 0)
                    _inflow = _amountDue;
                else
                    _outflow = -_amountDue;
            }
        }
        public decimal AmountPaid { get; set; }
        private decimal _inflow;
        public decimal Inflow
        {
            get => _inflow;
            set => _inflow = _amountDue = value;
        }
        private decimal _outflow;
        public decimal Outflow
        {
            get => _outflow;
            set
            {
                _outflow = value;
                _amountDue = -_outflow;
            }
        }
    }
}
