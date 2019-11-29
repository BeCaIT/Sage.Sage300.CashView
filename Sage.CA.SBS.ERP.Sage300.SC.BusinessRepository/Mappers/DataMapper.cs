using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers
{
    public class DataMapper<T>
        : ModelMapper<T>
        where T : Models.Data, new()
    {
        public DataMapper(Context context)
            : base(context)
        {
        }

        public override T Map(IBusinessEntity entity)
        {
            T model = base.Map(entity);

            return model;
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
