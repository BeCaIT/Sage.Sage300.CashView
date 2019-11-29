using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Core.Logging;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository
{
    internal class ProcessorRepository : BaseRepository
    {
        internal ProcessorRepository(Context context)
            : base(context) { }

        internal bool Process()
        {
            try
            {
                string repoName = GetType().Namespace + "," + GetType().Name;
                IBusinessEntity be = (BusinessEntity)OpenEntity("CS0030");
                Session.RemoveViewFromCache("CS0030", repoName, IsReadOnly);
                be.Destroy();
            }
            catch (Exception ex)
            {
                Logger.Error("error while processing SC", ex);
            }

            return HasLoanRecords();
        }

        internal bool HasLoanRecords()
        {
            try
            {
                using (BusinessEntity loan = (BusinessEntity)Session.OpenView(Models.Loan.EntityName, Session, GetType().Name, Context, true))
                    return loan.FilterCount(string.Empty, 0) > 0;
            }
            catch (Exception ex)
            {
                Logger.Error("error retrieving Loan records", ex);
            }

            return false;
        }
    }
}
