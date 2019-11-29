﻿using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Service;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.ExportImport;
using Sage.CA.SBS.ERP.Sage300.Common.Services.Base;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Services
{
    public class SummaryEntityService<T>
        : InquiryService<T, ISummaryEntity<T>>,
        ISummaryService<T>
        where T : Summary, new()
    {
        public SummaryEntityService(Context context)
            : base(context) { }
    }
}
