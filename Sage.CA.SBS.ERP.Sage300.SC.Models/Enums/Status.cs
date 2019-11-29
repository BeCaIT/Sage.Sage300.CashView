// Copyright © 2019 Sage Software Asia Pte Ltd

#region Namespace

using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms;

#endregion

namespace Sage.CA.SBS.ERP.Sage300.SC.Models.Enums
{
    /// <summary>
    /// Enum for Status
    /// </summary>
    public enum Status
    {
        /// <summary>
        /// Gets or sets New
        /// </summary>
        [EnumValue("New", typeof(LoanResx))]
        New = 0,

        /// <summary>
        /// Gets or sets Submitted
        /// </summary>
        [EnumValue("Submitted", typeof(LoanResx))]
        Submitted = 1,

        /// <summary>
        /// Gets or sets Cancelled
        /// </summary>
        [EnumValue("Cancelled", typeof(LoanResx))]
        Cancelled = 2,

        /// <summary>
        /// Gets or sets Rejected
        /// </summary>
        [EnumValue("Rejected", typeof(LoanResx))]
        Rejected = 3,

        /// <summary>
        /// Gets or sets Approved
        /// </summary>
        [EnumValue("Approved", typeof(LoanResx))]
        Approved = 4

    }
}