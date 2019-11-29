using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models.Enums
{
    public enum EntityType
    {
        [EnumValue(nameof(Unspecified), typeof(EntityTypeResx))]
        Unspecified = 0,
    }

    public enum EntityTypeSG
    {
        [EnumValue(nameof(Unspecified), typeof(EntityTypeSGResx))]
        Unspecified = 0,

        [EnumValue(nameof(BIZ), typeof(EntityTypeSGResx))]
        BIZ = 1,

        [EnumValue(nameof(COM), typeof(EntityTypeSGResx))]
        COM = 2,

        [EnumValue(nameof(LLP), typeof(EntityTypeSGResx))]
        LLP = 3,

        [EnumValue(nameof(LP), typeof(EntityTypeSGResx))]
        LP = 4,

        [EnumValue(nameof(PAF), typeof(EntityTypeSGResx))]
        PAF = 5,
    }


    public enum EntityTypeMY
    {
        [EnumValue(nameof(Unspecified), typeof(EntityTypeMYResx))]
        Unspecified = 0,

        [EnumValue(nameof(BIZ), typeof(EntityTypeMYResx))]
        BIZ = 1,

        [EnumValue(nameof(COM), typeof(EntityTypeMYResx))]
        COM = 2,

        [EnumValue(nameof(LLP), typeof(EntityTypeMYResx))]
        LLP = 3,

        [EnumValue(nameof(LP), typeof(EntityTypeMYResx))]
        LP = 4,

        [EnumValue(nameof(PAF), typeof(EntityTypeMYResx))]
        PAF = 5,
    }
}
