// Copyright © 2019 Sage Software Asia Pte Ltd

#region Namespace

using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms.Enums;

#endregion

namespace Sage.CA.SBS.ERP.Sage300.SC.Models.Enums
{
    /// <summary>
    /// Enum for JobTitle
    /// </summary>
    public enum JobTitle
    {
        [EnumValue(nameof(Unspecified), typeof(JobTitleResx))]
        Unspecified = 0,

        [EnumValue(nameof(JT01), typeof(JobTitleResx))]
        JT01 = 1,

        [EnumValue(nameof(JT02), typeof(JobTitleResx))]
        JT02 = 2,

        [EnumValue(nameof(JT03), typeof(JobTitleResx))]
        JT03 = 3,

        [EnumValue(nameof(JT04), typeof(JobTitleResx))]
        JT04 = 4,

        [EnumValue(nameof(JT05), typeof(JobTitleResx))]
        JT05 = 5,

        [EnumValue(nameof(JT15), typeof(JobTitleResx))]
        JT15 = 15
    }
}