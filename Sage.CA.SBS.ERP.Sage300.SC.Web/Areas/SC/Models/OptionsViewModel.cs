using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Models
{
    public class OptionsViewModel<T>
        : ViewModelBase<T>
        where T : Options, new()
    {
        public IEnumerable JobTitles
            => EnumUtility.GetItems<JobTitle>();

        public IEnumerable Countries
            => EnumUtility.GetItems<Country>();

        public IEnumerable EntityTypes
            => EnumUtility.GetItems<EntityType>();

        public IEnumerable EntityTypesSG
            => EnumUtility.GetItems<EntityTypeSG>();

        public IEnumerable EntityTypesMY
            => EnumUtility.GetItems<EntityTypeMY>();

        public IEnumerable Industries
            => EnumUtility.GetItems<Industry>();

        public IEnumerable IndustriesSG
            => EnumUtility.GetItems<IndustrySG>();

        public IEnumerable IndustriesMY
            => EnumUtility.GetItems<IndustryMY>();

        public IEnumerable YesNo
            => EnumUtility.GetItems<YesNo>();
    }
}