using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Attributes;
using Sage.CA.SBS.ERP.Sage300.Common.Resources;
using Sage.CA.SBS.ERP.Sage300.CS.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models
{
    public partial class Options : ModelBase
    {
        public CompanyProfile CompanyProfile { get; set; }

        public IEnumerable<Account> AccountsDummy { get; set; } = new List<Account>();

        [Display(Name = nameof(Accounts), ResourceType = typeof(OptionsResx))]
        [IsMvcSpecific]
        public EnumerableResponse<Account> Accounts { get; set; } = new EnumerableResponse<Account>();

        [Key]
        [Display(Name = nameof(Dummy), ResourceType = typeof(OptionsResx))]
        public string Dummy { get; set; }

        [Display(Name = nameof(Contact), ResourceType = typeof(OptionsResx))]
        public string Contact { get; set; }

        [Display(Name = nameof(JobTitle), ResourceType = typeof(OptionsResx))]
        public JobTitle JobTitle { get; set; }

        [Display(Name = nameof(Email), ResourceType = typeof(OptionsResx))]
        public string Email { get; set; }

        [Display(Name = nameof(Phone), ResourceType = typeof(OptionsResx))]
        public string Phone { get; set; }

        [Display(Name = nameof(Mobile), ResourceType = typeof(OptionsResx))]
        public string Mobile { get; set; }

        [Display(Name = nameof(Country), ResourceType = typeof(OptionsResx))]
        public Country Country { get; set; }

        [Display(Name = nameof(Industry), ResourceType = typeof(OptionsResx))]
        public Industry Industry { get; set; }

        [Display(Name = nameof(EntityType), ResourceType = typeof(OptionsResx))]
        public EntityType EntityType { get; set; }

        [Display(Name = nameof(BRYear), ResourceType = typeof(OptionsResx))]
        public string BRYear { get; set; }

        [Display(Name = nameof(Threshold), ResourceType = typeof(OptionsResx))]
        public decimal Threshold { get; set; }

        [Display(Name = nameof(Period1End), ResourceType = typeof(OptionsResx))]
        public int Period1End { get; set; }

        [Display(Name = nameof(Period2End), ResourceType = typeof(OptionsResx))]
        public int Period2End { get; set; }

        [Display(Name = nameof(Period3End), ResourceType = typeof(OptionsResx))]
        public int Period3End { get; set; }

        [Display(Name = nameof(Period4End), ResourceType = typeof(OptionsResx))]
        public int Period4End { get; set; }

        [Display(Name = nameof(Period5End), ResourceType = typeof(OptionsResx))]
        public int Period5End { get; set; }

        [Display(Name = nameof(IncludePendingGL), ResourceType = typeof(OptionsResx))]
        public bool IncludePendingGL { get; set; }

        [Display(Name = nameof(IncludePendingAR), ResourceType = typeof(OptionsResx))]
        public bool IncludePendingAR { get; set; }

        [Display(Name = nameof(IncludePendingAP), ResourceType = typeof(OptionsResx))]
        public bool IncludePendingAP { get; set; }

        [Display(Name = nameof(LastProcessedDate), ResourceType = typeof(OptionsResx))]
        public DateTime LastProcessedDate { get; set; }

        [Display(Name = nameof(LastProcessedTime), ResourceType = typeof(OptionsResx))]
        public TimeSpan LastProcessedTime { get; set; }

        [Display(Name = nameof(EmailAlert), ResourceType = typeof(OptionsResx))]
        public YesNo EmailAlert { get; set; }

        [Display(Name = nameof(EmailOffer), ResourceType = typeof(OptionsResx))]
        public bool EmailOffer { get; set; }

        [ValidateDateFormat(ErrorMessageResourceName = "DateFormat", ErrorMessageResourceType = typeof(AnnotationsResx))]
        [Display(Name = nameof(EmailSnoozeUntil), ResourceType = typeof(OptionsResx))]
        public DateTime? EmailSnoozeUntil { get; set; }

        [Display(Name = nameof(EmailHost), ResourceType = typeof(OptionsResx))]
        public string EmailHost { get; set; }

        [Display(Name = nameof(EmailPort), ResourceType = typeof(OptionsResx))]
        public int EmailPort { get; set; }

        [Display(Name = nameof(EmailSSL), ResourceType = typeof(OptionsResx))]
        public YesNo EmailSSL { get; set; }

        [Display(Name = nameof(EmailUser), ResourceType = typeof(OptionsResx))]
        public string EmailUser { get; set; }

        [Display(Name = nameof(EmailPassword), ResourceType = typeof(OptionsResx))]
        public byte[] EmailPassword { get; set; }

        [Display(Name = nameof(EmailAddress), ResourceType = typeof(OptionsResx))]
        public string EmailAddress { get; set; }

        [Display(Name = nameof(EmailTo), ResourceType = typeof(OptionsResx))]
        public string EmailTo { get; set; }

        [Display(Name = nameof(FELength), ResourceType = typeof(OptionsResx))]
        public int FELength { get; set; }

        [Display(Name = nameof(FEPrefix), ResourceType = typeof(OptionsResx))]
        public string FEPrefix { get; set; }

        [Display(Name = nameof(FENextNumber), ResourceType = typeof(OptionsResx))]
        public decimal FENextNumber { get; set; }

        [Display(Name = nameof(BRN), ResourceType = typeof(OptionsResx))]
        public string BRN { get; set; }

        [Display(Name = nameof(BRYearCalculated), ResourceType = typeof(OptionsResx))]
        public string BRYearCalculated { get; set; }

        [Display(Name = nameof(FunctionalCurrency), ResourceType = typeof(OptionsResx))]
        public string FunctionalCurrency { get; set; }

        [Display(Name = nameof(IndustrySG), ResourceType = typeof(OptionsResx))]
        public IndustrySG IndustrySG { get; set; }

        [Display(Name = nameof(IndustryMY), ResourceType = typeof(OptionsResx))]
        public IndustryMY IndustryMY { get; set; }

        [Display(Name = nameof(EntityTypeSG), ResourceType = typeof(OptionsResx))]
        public EntityTypeSG EntityTypeSG { get; set; }

        [Display(Name = nameof(EntityTypeMY), ResourceType = typeof(OptionsResx))]
        public EntityTypeMY EntityTypeMY { get; set; }

        [Display(Name = nameof(Period1Start), ResourceType = typeof(OptionsResx))]
        public int Period1Start { get; set; }

        [Display(Name = nameof(Period2Start), ResourceType = typeof(OptionsResx))]
        public int Period2Start { get; set; }

        [Display(Name = nameof(Period3Start), ResourceType = typeof(OptionsResx))]
        public int Period3Start { get; set; }

        [Display(Name = nameof(Period4Start), ResourceType = typeof(OptionsResx))]
        public int Period4Start { get; set; }

        [Display(Name = nameof(Period5Start), ResourceType = typeof(OptionsResx))]
        public int Period5Start { get; set; }

        [Display(Name = nameof(Period6Start), ResourceType = typeof(OptionsResx))]
        public int Period6Start { get; set; }

        [Display(Name = nameof(CurrentDate), ResourceType = typeof(OptionsResx))]
        public DateTime CurrentDate { get; set; }

        [Display(Name = nameof(CurrentYear), ResourceType = typeof(OptionsResx))]
        public string CurrentYear { get; set; }

        [Display(Name = nameof(CurrentPeriod), ResourceType = typeof(OptionsResx))]
        public int CurrentPeriod { get; set; }

        [Display(Name = nameof(ReportingCurrency), ResourceType = typeof(OptionsResx))]
        public string ReportingCurrency { get; set; }

        [Display(Name = nameof(Rate), ResourceType = typeof(OptionsResx))]
        public decimal Rate { get; set; }

        [Display(Name = nameof(RateOperator), ResourceType = typeof(OptionsResx))]
        public int RateOperator { get; set; }

        [Display(Name = nameof(RateDate), ResourceType = typeof(OptionsResx))]
        public DateTime? RateDate { get; set; }

        [Display(Name = nameof(EmailPasswordString), ResourceType = typeof(OptionsResx))]
        public string EmailPasswordString { get; set; }
 
        [Display(Name = nameof(EmailTest), ResourceType = typeof(OptionsResx))]
        public string EmailTest { get; set; }

        [Display(Name = nameof(FEDocumentDefault), ResourceType = typeof(OptionsResx))]
        public string FEDocumentDefault { get; set; }

        [Display(Name = nameof(FEDocumentNext), ResourceType = typeof(OptionsResx))]
        public string FEDocumentNext { get; set; }

        [Display(Name = nameof(ProcessCommand), ResourceType = typeof(OptionsResx))]
        public int ProcessCommand { get; set; }
    }
}