using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Models.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers
{
    public class LoanMapper<T>
        : ModelMapper<T>
        where T : Loan, new()
    {
        #region Constructors
        public LoanMapper(Context context)
            : base(context) { }
        #endregion Constructors

        #region Mappings
        public override T Map(IBusinessEntity entity)
        {
            T model = base.Map(entity);

            model.LoanNumber = entity.GetValue<string>(Loan.Fields.LoanNumber);
            model.Status = entity.GetValue<LoanStatus>(Loan.Fields.Status);
            model.Reference = entity.GetValue<string>(Loan.Fields.Reference);
            model.DateOffered = entity.GetValue<DateTime>(Loan.Fields.DateOffered);
            model.DateSubmitted = entity.GetValue<DateTime>(Loan.Fields.DateSubmitted);
            model.AmountOffer = entity.GetValue<decimal>(Loan.Fields.AmountOffer);
            model.AmountRequest = entity.GetValue<decimal>(Loan.Fields.AmountRequest);
            model.Contact = entity.GetValue<string>(Loan.Fields.Contact);
            model.Email = entity.GetValue<string>(Loan.Fields.Email);
            model.Phone = entity.GetValue<string>(Loan.Fields.Phone);
            model.Mobile = entity.GetValue<string>(Loan.Fields.Mobile);
            model.Message = entity.GetValue<string>(Loan.Fields.Message);
            model.CompanyName = entity.GetValue<string>(Loan.Fields.CompanyName);
            model.Address1 = entity.GetValue<string>(Loan.Fields.Address1);
            model.Address2 = entity.GetValue<string>(Loan.Fields.Address2);
            model.Address3 = entity.GetValue<string>(Loan.Fields.Address3);
            model.Address4 = entity.GetValue<string>(Loan.Fields.Address4);
            model.City = entity.GetValue<string>(Loan.Fields.City);
            model.State = entity.GetValue<string>(Loan.Fields.State);
            model.Country = entity.GetValue<string>(Loan.Fields.Country);
            model.PostalCode = entity.GetValue<string>(Loan.Fields.PostalCode);
            model.EmailCC = entity.GetValue<string>(Loan.Fields.EmailCC);
            model.BRN = entity.GetValue<string>(Loan.Fields.BRN);
            model.Currency = entity.GetValue<string>(Loan.Fields.Currency);
            model.EmailSubject = entity.GetValue<string>(Loan.Fields.EmailSubject);
            model.EmailFrom = entity.GetValue<string>(Loan.Fields.EmailFrom);
            model.EmailTo = entity.GetValue<string>(Loan.Fields.EmailTo);

            return model;
        }

        public override void Map(T model, IBusinessEntity entity)
        {
            entity.SetValue(Loan.Fields.LoanNumber, model.LoanNumber);
            entity.SetValue(Loan.Fields.Reference, model.Reference);
            entity.SetValue(Loan.Fields.DateOffered, model.DateOffered);
            entity.SetValue(Loan.Fields.DateSubmitted, model.DateSubmitted);
            entity.SetValue(Loan.Fields.UserSubmitted, model.UserSubmitted);
            entity.SetValue(Loan.Fields.EmailSubmitted, model.EmailSubmitted);
            entity.SetValue(Loan.Fields.AmountOffer, model.AmountOffer);
            entity.SetValue(Loan.Fields.AmountRequest, model.AmountRequest);
            entity.SetValue(Loan.Fields.Contact, model.Contact);
            entity.SetValue(Loan.Fields.JobTitle, model.JobTitle);
            entity.SetValue(Loan.Fields.Email, model.Email);
            entity.SetValue(Loan.Fields.Phone, model.Phone);
            entity.SetValue(Loan.Fields.Mobile, model.Mobile);
            entity.SetValue(Loan.Fields.Message, model.Message);
            entity.SetValue(Loan.Fields.CompanyName, model.CompanyName);
            entity.SetValue(Loan.Fields.Address1, model.Address1);
            entity.SetValue(Loan.Fields.Address2, model.Address2);
            entity.SetValue(Loan.Fields.Address3, model.Address3);
            entity.SetValue(Loan.Fields.Address4, model.Address4);
            entity.SetValue(Loan.Fields.City, model.City);
            entity.SetValue(Loan.Fields.State, model.State);
            entity.SetValue(Loan.Fields.Country, model.Country);
            entity.SetValue(Loan.Fields.PostalCode, model.PostalCode);
            entity.SetValue(Loan.Fields.EmailCC, model.EmailCC);
            //
            //// Move status to last 
            entity.SetValue(Loan.Fields.Status, model.Status);
        }

        public override void MapKey(T model, IBusinessEntity entity)
        {
            entity.SetValue(Loan.Fields.LoanNumber, model.LoanNumber);
        }
        #endregion Mappings
    }
}
