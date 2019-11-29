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
    public class OptionsMapper<T> :
        ModelMapper<T>
        where T : Options, new()
    {
        public OptionsMapper(Context context)
            : base(context) { }

        public override void Map(T model, IBusinessEntity entity)
        {
            if (model == null)
                return;

            //entity.SetValue(Options.Fields.Dummy, model.Dummy);
            entity.SetValue(Options.Fields.Contact, model.Contact);
            entity.SetValue(Options.Fields.JobTitle, model.JobTitle);
            entity.SetValue(Options.Fields.Email, model.Email);
            entity.SetValue(Options.Fields.Phone, model.Phone);
            entity.SetValue(Options.Fields.Mobile, model.Mobile);
            entity.SetValue(Options.Fields.Country, model.Country, true);
            //switch (model.Country)
            //{
            //    case Country.Singapore:
            //        entity.SetValue(Options.Fields.EntityType, model.EntityTypeSG);
            //        entity.SetValue(Options.Fields.Industry, model.IndustrySG);
            //        break;

            //    case Country.Malaysia:
            //        entity.SetValue(Options.Fields.EntityType, model.EntityTypeMY);
            //        entity.SetValue(Options.Fields.Industry, model.IndustryMY);
            //        break;

            //    default:
            //        entity.SetValue(Options.Fields.EntityType, model.EntityType);
            //        entity.SetValue(Options.Fields.Industry, model.Industry);
            //        break;
            //}
            //entity.SetValue(Options.Fields.Industry, model.Industry);
            //entity.SetValue(Options.Fields.EntityType, model.EntityType);
            entity.SetValue(Options.Fields.BRYear, model.BRYear);
            entity.SetValue(Options.Fields.Threshold, model.Threshold);
            entity.SetValue(Options.Fields.Period1End, model.Period1End);
            entity.SetValue(Options.Fields.Period2End, model.Period2End);
            entity.SetValue(Options.Fields.Period3End, model.Period3End);
            entity.SetValue(Options.Fields.Period4End, model.Period4End);
            entity.SetValue(Options.Fields.Period5End, model.Period5End);
            entity.SetValue(Options.Fields.IncludePendingGL, model.IncludePendingGL);
            entity.SetValue(Options.Fields.IncludePendingAR, model.IncludePendingAR);
            entity.SetValue(Options.Fields.IncludePendingAP, model.IncludePendingAP);
            //entity.SetValue(Options.Fields.LastProcessedDate, model.LastProcessedDate);
            //entity.SetValue(Options.Fields.LastProcessedTime, model.LastProcessedTime);
            entity.SetValue(Options.Fields.EmailAlert, model.EmailAlert == YesNo.Yes);
            entity.SetValue(Options.Fields.EmailOffer, model.EmailOffer);
            entity.SetValue(Options.Fields.EmailSnoozeUntil, model.EmailSnoozeUntil);
            entity.SetValue(Options.Fields.EmailHost, model.EmailHost);
            entity.SetValue(Options.Fields.EmailPort, model.EmailPort);
            entity.SetValue(Options.Fields.EmailSSL, model.EmailSSL == YesNo.Yes);
            entity.SetValue(Options.Fields.EmailUser, model.EmailUser);
            entity.SetValue(Options.Fields.EmailPassword, model.EmailPassword);
            entity.SetValue(Options.Fields.EmailAddress, model.EmailAddress);
            entity.SetValue(Options.Fields.EmailTo, model.EmailTo);
            entity.SetValue(Options.Fields.FELength, model.FELength);
            entity.SetValue(Options.Fields.FEPrefix, model.FEPrefix);
            entity.SetValue(Options.Fields.FENextNumber, model.FENextNumber);
            entity.SetValue(Options.Fields.BRN, model.BRN);
            //entity.SetValue(Options.Fields.BRYearCalculated, model.BRYearCalculated);
            //entity.SetValue(Options.Fields.FunctionalCurrency, model.FunctionalCurrency);
            switch (model.Country)
            {
                case Country.Singapore:
                    entity.SetValue(Options.Fields.IndustrySG, EnumUtility.EnumToString(model.IndustrySG));
                    entity.SetValue(Options.Fields.EntityTypeSG, model.EntityTypeSG, true);
                    break;

                case Country.Malaysia:
                    entity.SetValue(Options.Fields.IndustryMY, EnumUtility.EnumToString(model.IndustryMY));
                    entity.SetValue(Options.Fields.EntityTypeMY, model.EntityTypeMY, true);
                    break;

                default:
                    entity.SetValue(Options.Fields.Industry, EnumUtility.EnumToString(model.Industry));
                    entity.SetValue(Options.Fields.EntityType, model.EntityType, true);
                    break;
            }
            //entity.SetValue(Options.Fields.Period1Start, model.Period1Start);
            //entity.SetValue(Options.Fields.Period2Start, model.Period2Start);
            //entity.SetValue(Options.Fields.Period3Start, model.Period3Start);
            //entity.SetValue(Options.Fields.Period4Start, model.Period4Start);
            //entity.SetValue(Options.Fields.Period5Start, model.Period5Start);
            //entity.SetValue(Options.Fields.Period6Start, model.Period6Start);
            //entity.SetValue(Options.Fields.CurrentDate, model.CurrentDate);
            //entity.SetValue(Options.Fields.CurrentYear, model.CurrentYear);
            //entity.SetValue(Options.Fields.CurrentPeriod, model.CurrentPeriod);
            //entity.SetValue(Options.Fields.ReportingCurrency, model.ReportingCurrency);
            //entity.SetValue(Options.Fields.Rate, model.Rate);
            //entity.SetValue(Options.Fields.RateOperator, model.RateOperator);
            //entity.SetValue(Options.Fields.RateDate, model.RateDate);
            //entity.SetValue(Options.Fields.EmailPasswordString, model.EmailPasswordString);
            entity.SetValue(Options.Fields.EmailTest, model.EmailTest);
            //entity.SetValue(Options.Fields.FEDocumentDefault, model.FEDocumentDefault);
            //entity.SetValue(Options.Fields.FEDocumentNext, model.FEDocumentNext);
            entity.SetValue(Options.Fields.ProcessCommand, model.ProcessCommand);

            //entity.Verify();
        }

        public override T Map(IBusinessEntity entity)
        {
            var model = base.Map(entity);

            model.Dummy = entity.GetValue<string>(Options.Fields.Dummy);
            model.Contact = entity.GetValue<string>(Options.Fields.Contact);
            model.JobTitle = entity.GetValue<JobTitle>(Options.Fields.JobTitle);
            model.Email = entity.GetValue<string>(Options.Fields.Email);
            model.Phone = entity.GetValue<string>(Options.Fields.Phone);
            model.Mobile = entity.GetValue<string>(Options.Fields.Mobile);
            model.Country = entity.GetValue<Country>(Options.Fields.Country);
            switch (model.Country)
            {
                case Country.Singapore:
                    model.Industry = entity.GetValue<Industry>(Options.Fields.IndustrySG);
                    model.EntityType = entity.GetValue<EntityType>(Options.Fields.EntityTypeSG);
                    break;

                case Country.Malaysia:
                    model.Industry = entity.GetValue<Industry>(Options.Fields.IndustryMY);
                    model.EntityType = entity.GetValue<EntityType>(Options.Fields.EntityTypeMY);
                    break;

                default:
                    model.Industry = entity.GetValue<Industry>(Options.Fields.Industry);
                    model.EntityType = entity.GetValue<EntityType>(Options.Fields.EntityType);
                    break;
            }
            //model.Industry = entity.GetValue<Industry>(Options.Fields.Industry);
            //model.EntityType = entity.GetValue<EntityType>(Options.Fields.EntityType);
            model.BRYear = entity.GetValue<string>(Options.Fields.BRYear);
            model.Threshold = entity.GetValue<decimal>(Options.Fields.Threshold);
            model.Period1End = entity.GetValue<int>(Options.Fields.Period1End);
            model.Period2End = entity.GetValue<int>(Options.Fields.Period2End);
            model.Period3End = entity.GetValue<int>(Options.Fields.Period3End);
            model.Period4End = entity.GetValue<int>(Options.Fields.Period4End);
            model.Period5End = entity.GetValue<int>(Options.Fields.Period5End);
            model.IncludePendingGL = entity.GetValue<bool>(Options.Fields.IncludePendingGL);
            model.IncludePendingAR = entity.GetValue<bool>(Options.Fields.IncludePendingAR);
            model.IncludePendingAP = entity.GetValue<bool>(Options.Fields.IncludePendingAP);
            model.LastProcessedDate = entity.GetValue<DateTime>(Options.Fields.LastProcessedDate);
            model.LastProcessedTime = entity.GetValue<DateTime>(Options.Fields.LastProcessedTime).TimeOfDay;
            model.EmailAlert = entity.GetValue<bool>(Options.Fields.EmailAlert) ? YesNo.Yes : YesNo.No;
            model.EmailOffer = entity.GetValue<bool>(Options.Fields.EmailOffer);
            model.EmailSnoozeUntil = entity.GetValue<DateTime>(Options.Fields.EmailSnoozeUntil);
            model.EmailHost = entity.GetValue<string>(Options.Fields.EmailHost);
            model.EmailPort = entity.GetValue<int>(Options.Fields.EmailPort);
            model.EmailSSL = entity.GetValue<bool>(Options.Fields.EmailSSL) ? YesNo.Yes : YesNo.No;
            model.EmailUser = entity.GetValue<string>(Options.Fields.EmailUser);
            model.EmailPassword = entity.GetValue<byte[]>(Options.Fields.EmailPassword);
            model.EmailAddress = entity.GetValue<string>(Options.Fields.EmailAddress);
            model.EmailTo = entity.GetValue<string>(Options.Fields.EmailTo);
            model.FELength = entity.GetValue<int>(Options.Fields.FELength);
            model.FEPrefix = entity.GetValue<string>(Options.Fields.FEPrefix);
            model.FENextNumber = entity.GetValue<decimal>(Options.Fields.FENextNumber);
            model.BRN = entity.GetValue<string>(Options.Fields.BRN);
            model.BRYearCalculated = entity.GetValue<string>(Options.Fields.BRYearCalculated);
            model.FunctionalCurrency = entity.GetValue<string>(Options.Fields.FunctionalCurrency);
            model.IndustrySG = entity.GetValue<IndustrySG>(Options.Fields.IndustrySG);
            model.IndustryMY = entity.GetValue<IndustryMY>(Options.Fields.IndustryMY);
            model.EntityTypeSG = entity.GetValue<EntityTypeSG>(Options.Fields.EntityTypeSG);
            model.EntityTypeMY = entity.GetValue<EntityTypeMY>(Options.Fields.EntityTypeMY);
            model.Period1Start = entity.GetValue<int>(Options.Fields.Period1Start);
            model.Period2Start = entity.GetValue<int>(Options.Fields.Period2Start);
            model.Period3Start = entity.GetValue<int>(Options.Fields.Period3Start);
            model.Period4Start = entity.GetValue<int>(Options.Fields.Period4Start);
            model.Period5Start = entity.GetValue<int>(Options.Fields.Period5Start);
            model.Period6Start = entity.GetValue<int>(Options.Fields.Period6Start);
            model.CurrentDate = entity.GetValue<DateTime>(Options.Fields.CurrentDate);
            model.CurrentYear = entity.GetValue<string>(Options.Fields.CurrentYear);
            model.CurrentPeriod = entity.GetValue<int>(Options.Fields.CurrentPeriod);
            model.ReportingCurrency = entity.GetValue<string>(Options.Fields.ReportingCurrency);
            model.Rate = entity.GetValue<decimal>(Options.Fields.Rate);
            model.RateOperator = entity.GetValue<int>(Options.Fields.RateOperator);
            model.RateDate = entity.GetValue<DateTime>(Options.Fields.RateDate);
            model.EmailPasswordString = entity.GetValue<string>(Options.Fields.EmailPasswordString);
            model.EmailTest = entity.GetValue<string>(Options.Fields.EmailTest);
            model.FEDocumentDefault = entity.GetValue<string>(Options.Fields.FEDocumentDefault);
            model.FEDocumentNext = entity.GetValue<string>(Options.Fields.FEDocumentNext);
            model.ProcessCommand = entity.GetValue<int>(Options.Fields.ProcessCommand);

            return model;
        }

        public override void MapKey(T model, IBusinessEntity entity)
        {
            throw new NotImplementedException();
        }
    }
}
