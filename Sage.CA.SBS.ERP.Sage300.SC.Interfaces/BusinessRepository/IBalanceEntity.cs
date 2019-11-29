﻿using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Repository;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository
{
    public interface IBalanceEntity<T>
        : IInquiryRepository<T>,
        ISecurity
        where T : Balance, new()
    {
    }
}
