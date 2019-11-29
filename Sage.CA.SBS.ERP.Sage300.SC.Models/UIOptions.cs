using Sage.CA.SBS.ERP.Sage300.Common.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public class UIOptions : ModelBase
    {
        public string Period0Name { get; set; }
        public string Period1Name { get; set; }
        public string Period2Name { get; set; }
        public string Period3Name { get; set; }
        public string Period4Name { get; set; }
        public string Period5Name { get; set; }
        public string Period6Name { get; set; }
        public string FormatString { get; set; }
        public bool ThresholdBreached { get; set; }
        public bool HasForecastEntryRight { get; set; }
        public bool HasLoanAccess { get; set; }
        public bool HasLoanRecords { get; set; }
        public bool HasNewLoanRecord { get; set; }
        public string OfferImage { get; set; }
    }
}
