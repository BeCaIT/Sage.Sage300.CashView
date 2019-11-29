using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Base;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Entity;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Mappers;
using Sage.CA.SBS.ERP.Sage300.SC.Data;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository
{
    public class DashboardRepository<T> :
        SCInquiryRepository<T>,
        IDashboardEntity<T>
        where T : Dashboard, new()
    {
        #region Constructors
        public DashboardRepository(Context context)
            : base(context, new DashboardMapper<T>(context), null) { }

        public DashboardRepository(Context context, IBusinessEntitySession session)
            : base(context, new DashboardMapper<T>(context), null, session) { }
        #endregion Constructors

        #region Methods
        protected override IBusinessEntity CreateBusinessEntities()
        {
            throw new NotImplementedException();
        }

        public override T Get()
        {
            //ApplicationData applicationData = InternalDataRepository.GetApplicationData(Context, Session);
            T model = new T
            {
                //
                //// Current Ratio
                CurrentRatio = ApplicationData.CurrentRatio,
                CurrentRatioBreak = ApplicationData.CurrentRatioBreak,
                //
                //// Quick Ratio
                QuickRatio = ApplicationData.QuickRatio,
                QuickRatioBreak = ApplicationData.QuickRatioBreak,
                //
                //// Net Operations
                NetAR = ApplicationData.NetAR.AmountTotal,
                NetAP = ApplicationData.NetAP.AmountTotal,
                //
                //// DSO
                DSO = ApplicationData.DSO,
                DSOMaximum = ApplicationData.DSOMaximum,
                DSOMedian = ApplicationData.DSOMedian,
                //
                //// DPO
                DPO = ApplicationData.DPO,
                DPOMaximum = ApplicationData.DPOMaximum,
                DPOMedian = ApplicationData.DPOMedian,
                //
                //// ARC
                ARC = ApplicationData.ARC,
                //
                //// CCC
                CCC = ApplicationData.CCC,
                CCCMaximum = ApplicationData.CCCMaximum,
                CCCMedian = ApplicationData.CCCMedian,
                //
                //// Cashflow Chart
                CashFlowChartNetIn = ApplicationData.CashFlowChartNetIn.Select(c => new Models.ChartData { Category = c.Category, Value = c.Value }),
                CashFlowChartNetOut = ApplicationData.CashFlowChartNetOut.Select(c => new Models.ChartData { Category = c.Category, Value = c.Value }),
                CashFlowChartEndingBalance = ApplicationData.CashFlowChartEndingBalance.Select(c => new Models.ChartData { Category = c.Category, Value = c.Value }),
                //
                //// UI Options
                UIOptions = UIOptions
            };

            return model;
        }
        #endregion
    }
}
