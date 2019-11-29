using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Resources;
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
    public partial class Loan : ModelBase
    {
        [Key]
        [Display(Name = nameof(LoanNumber), ResourceType = typeof(LoanResx))]
        public string LoanNumber { get; set; }

        [Display(Name = nameof(Status), ResourceType = typeof(LoanResx))]
        public LoanStatus Status { get; set; }

        [Display(Name = nameof(Reference), ResourceType = typeof(LoanResx))]
        public string Reference { get; set; }

        [Display(Name = nameof(DateOffered), ResourceType = typeof(LoanResx))]
        public DateTime DateOffered { get; set; }

        [Display(Name = nameof(DateSubmitted), ResourceType = typeof(LoanResx))]
        public DateTime DateSubmitted { get; set; }

        [Display(Name = nameof(UserSubmitted), ResourceType = typeof(LoanResx))]
        public string UserSubmitted { get; set; }

        [Display(Name = nameof(EmailSubmitted), ResourceType = typeof(LoanResx))]
        public string EmailSubmitted { get; set; }

        [Display(Name = nameof(AmountOffer), ResourceType = typeof(LoanResx))]
        public decimal AmountOffer { get; set; }

        [Display(Name = nameof(AmountRequest), ResourceType = typeof(LoanResx))]
        [Required(ErrorMessageResourceName = "Required", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public decimal AmountRequest { get; set; }

        [Display(Name = nameof(Contact), ResourceType = typeof(LoanResx))]
        [Required(ErrorMessageResourceName = "Required", ErrorMessageResourceType = typeof(AnnotationsResx))]
        [StringLength(60, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Contact { get; set; }

        [Display(Name = nameof(JobTitle), ResourceType = typeof(LoanResx))]
        public JobTitle JobTitle { get; set; }

        [Display(Name = nameof(Email), ResourceType = typeof(LoanResx))]
        [Required(ErrorMessageResourceName = "Required", ErrorMessageResourceType = typeof(AnnotationsResx))]
        [StringLength(50, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Email { get; set; }

        [Display(Name = nameof(Phone), ResourceType = typeof(LoanResx))]
        [Required(ErrorMessageResourceName = "Required", ErrorMessageResourceType = typeof(AnnotationsResx))]
        [StringLength(30, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Phone { get; set; }

        [Display(Name = nameof(Mobile), ResourceType = typeof(LoanResx))]
        [StringLength(30, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Mobile { get; set; }

        [Display(Name = nameof(Message), ResourceType = typeof(LoanResx))]
        [StringLength(255, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Message { get; set; }

        [Display(Name = nameof(CompanyName), ResourceType = typeof(LoanResx))]
        [Required(ErrorMessageResourceName = "Required", ErrorMessageResourceType = typeof(AnnotationsResx))]
        [StringLength(60, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string CompanyName { get; set; }

        [Display(Name = nameof(Address1), ResourceType = typeof(LoanResx))]
        [StringLength(60, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Address1 { get; set; }

        [Display(Name = nameof(Address2), ResourceType = typeof(LoanResx))]
        [StringLength(60, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Address2 { get; set; }

        [Display(Name = nameof(Address3), ResourceType = typeof(LoanResx))]
        [StringLength(60, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Address3 { get; set; }

        [Display(Name = nameof(Address4), ResourceType = typeof(LoanResx))]
        [StringLength(60, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Address4 { get; set; }

        [Display(Name = nameof(City), ResourceType = typeof(LoanResx))]
        [StringLength(30, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string City { get; set; }

        [Display(Name = nameof(State), ResourceType = typeof(LoanResx))]
        [StringLength(30, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string State { get; set; }

        [Display(Name = nameof(Country), ResourceType = typeof(LoanResx))]
        [StringLength(30, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string Country { get; set; }

        [Display(Name = nameof(PostalCode), ResourceType = typeof(LoanResx))]
        [StringLength(20, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string PostalCode { get; set; }

        [Display(Name = nameof(EmailCC), ResourceType = typeof(LoanResx))]
        [StringLength(50, ErrorMessageResourceName = "MaxLength", ErrorMessageResourceType = typeof(AnnotationsResx))]
        public string EmailCC { get; set; }

        [Display(Name = nameof(BRN), ResourceType = typeof(LoanResx))]
        public string BRN { get; set; }

        [Display(Name = nameof(Currency), ResourceType = typeof(LoanResx))]
        public string Currency { get; set; }

        [Display(Name = nameof(EmailSubject), ResourceType = typeof(LoanResx))]
        public string EmailSubject { get; set; }

        [Display(Name = nameof(EmailFrom), ResourceType = typeof(LoanResx))]
        public string EmailFrom { get; set; }

        [Display(Name = nameof(EmailTo), ResourceType = typeof(LoanResx))]
        public string EmailTo { get; set; }

        public string TermsAndConditions { get; set; }
    }
}