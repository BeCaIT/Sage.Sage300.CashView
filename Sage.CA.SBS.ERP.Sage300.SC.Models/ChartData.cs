﻿using Sage.CA.SBS.ERP.Sage300.Common.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class ChartData : ModelBase
    {
        public string Category { get; set; }
        public decimal Value { get; set; }
    }
}
