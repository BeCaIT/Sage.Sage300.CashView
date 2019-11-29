using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Data
{
    public class Loan : BaseDataModel
    {
        private string _loanNumber;
        public string LoanNumber
        {
            get => _loanNumber;
            set => SetProperty(ref _loanNumber, value);
        }

        private LoanStatus _status;
        public LoanStatus Status
        {
            get => _status;
            set => SetProperty(ref _status, value);
        }

        private string _reference;
        public string Reference
        {
            get => _reference;
            set => SetProperty(ref _reference, value);
        }

        private DateTime _dateOffered;
        public DateTime DateOffered
        {
            get => _dateOffered;
            set => SetProperty(ref _dateOffered, value);
        }

        private DateTime? _dateSubmitted;
        public DateTime? DateSubmitted
        {
            get => _dateSubmitted;
            set => SetProperty(ref _dateSubmitted, value);

        }

        private string _userSubmitted;
        public string UserSubmitted
        {
            get => _userSubmitted;
            set => SetProperty(ref _userSubmitted, value);
        }

        private decimal _amountOffered;
        public decimal AmountOffered
        {
            get => _amountOffered;
            set => SetProperty(ref _amountOffered, value);
        }

        private decimal _amountRequested;
        public decimal AmountRequested
        {
            get => _amountRequested;
            set => SetProperty(ref _amountRequested, value);
        }

        private string _contact;
        public string Contact
        {
            get => _contact;
            set => SetProperty(ref _contact, value);
        }

        private short _jobTitle;
        public short JobTitle
        {
            get => _jobTitle;
            set => SetProperty(ref _jobTitle, value);
        }

        private string _email;
        public string Email
        {
            get => _email;
            set => SetProperty(ref _email, value);
        }

        private string _phone;
        public string Phone
        {
            get => _phone;
            set => SetProperty(ref _phone, value);
        }

        private string _mobile;
        public string Mobile
        {
            get => _mobile;
            set => SetProperty(ref _mobile, value);
        }

        private string _message;
        public string Message
        {
            get => _message;
            set => SetProperty(ref _message, value);
        }

        private string _companyName;
        public string CompanyName
        {
            get => _companyName;
            set => SetProperty(ref _companyName, value);
        }

        private string _brn;
        public string BRN
        {
            get => _brn;
            set => SetProperty(ref _brn, value);
        }

        private string _address1;
        public string Address1
        {
            get => _address1;
            set => SetProperty(ref _address1, value);
        }

        private string _address2;
        public string Address2
        {
            get => _address2;
            set => SetProperty(ref _address2, value);
        }

        private string _address3;
        public string Address3
        {
            get => _address3;
            set => SetProperty(ref _address3, value);
        }

        private string _address4;
        public string Address4
        {
            get => _address4;
            set => SetProperty(ref _address4, value);
        }

        private string _city;
        public string City
        {
            get => _city;
            set => SetProperty(ref _city, value);
        }

        private string _state;
        public string State
        {
            get => _state;
            set => SetProperty(ref _state, value);
        }

        private string _country;
        public string Country
        {
            get => _country;
            set => SetProperty(ref _country, value);
        }

        private string _postal;
        public string Postal
        {
            get => _postal;
            set => SetProperty(ref _postal, value);
        }

        private string _emailSubject = "Standard Chartered loan submission request";
        public string EmailSubject
        {
            get => _emailSubject;
            set => SetProperty(ref _emailSubject, value);
        }

        private string _emailCC;
        public string EmailCC
        {
            get => _emailCC;
            set => SetProperty(ref _emailCC, value);
        }

        private string _emailFrom;
        public string EmailFrom
        {
            get => _emailFrom;
            set => SetProperty(ref _emailFrom, value);
        }

        private string _emailTo;
        public string EmailTo
        {
            get => _emailTo;
            set => SetProperty(ref _emailTo, value);
        }

        #region Extended Properties
        public bool Editable
            => Status == LoanStatus.New;

        public bool StatusEditable
            => Status == LoanStatus.Submitted;
        #endregion
    }
}
