using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Service;
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
    public class PayeeSummaryEntityService<T>
        : InquiryService<T, IPayeeSummaryEntity<T>>,
        IPayeeSummaryService<T>
        where T : PayeeSummary, new()
    {
        public PayeeSummaryEntityService(Context context)
            : base(context) { }

        public EnumerableResponse<T> GetAR(T model, PageOptions<T> pageOptions)
        {
            using (IPayeeSummaryEntity<T> repository = Resolve<IPayeeSummaryEntity<T>>())
                return repository.GetAR(pageOptions);
        }

        public EnumerableResponse<T> GetAP(T model, PageOptions<T> pageOptions)
        {
            using (IPayeeSummaryEntity<T> repository = Resolve<IPayeeSummaryEntity<T>>())
                return repository.GetAP(pageOptions);
        }

        public EnumerableResponse<T> GetAR(PageOptions<T> pageOptions)
        {
            using (IPayeeSummaryEntity<T> repository = Resolve<IPayeeSummaryEntity<T>>())
                return repository.GetAR(pageOptions);
        }

        public EnumerableResponse<T> GetAP(PageOptions<T> pageOptions)
        {
            using (IPayeeSummaryEntity<T> repository = Resolve<IPayeeSummaryEntity<T>>())
                return repository.GetAP(pageOptions);
        }
    }
}
