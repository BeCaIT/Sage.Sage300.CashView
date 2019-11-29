using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers
{
    public class PayeeSummaryMapper<T> :
        ModelMapper<T>
        where T : PayeeSummary, new()
    {
        public PayeeSummaryMapper(Context context)
            : base(context)
        {
        }

        public override void Map(T model, IBusinessEntity entity)
        {
            throw new NotImplementedException();
        }

        public override void MapKey(T model, IBusinessEntity entity)
        {
            throw new NotImplementedException();
        }
    }
}
