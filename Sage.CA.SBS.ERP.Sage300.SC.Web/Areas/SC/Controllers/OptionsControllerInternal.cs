using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Enums;
using Sage.CA.SBS.ERP.Sage300.Common.Resources;
using Sage.CA.SBS.ERP.Sage300.Common.Web;
using Sage.CA.SBS.ERP.Sage300.Common.Web.Utilities;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.Services;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms;
using Sage.CA.SBS.ERP.Sage300.SC.Web.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Web;

namespace Sage.CA.SBS.ERP.Sage300.SC.Web.Controllers
{
    public class OptionsControllerInternal<T>
        : InternalControllerBase<IOptionsService<T>>
        where T : Options, new()
    {
        #region Constructors
        public OptionsControllerInternal(Context context)
            : base(context)
        {
            _accountCacheKey = CreateSessionKey<T>("scAccountCache");
            _accountFilter = ((Account a) => a.SerialNumber);
        }
        #endregion Constructors

        #region Internal Methods
        internal OptionsViewModel<T> Get()
        {
            SessionHelper.Remove(_accountCacheKey);

            var data = Service.GetById<string>(null);
            var userMessage = new UserMessage(data);

            return GetViewModel(data, userMessage);
        }

        internal OptionsViewModel<T> Save(T model)
        {
            model.Accounts = GetDataForSave(model.Accounts, _accountCacheKey, "SerialNumber", _accountFilter);

            var data = Service.Save(model);
            var userMessage = new UserMessage(data, CommonResx.SaveSuccessMessage);

            SessionHelper.Remove(_accountCacheKey);

            return GetViewModel(data, userMessage);
        }

        internal OptionsViewModel<T> SendTestEmail(T model)
        {
            var data = Service.SendTestEmail(model);
            var userMessage = new UserMessage(data, OptionsResx.EmailTestSuccessed);

            return GetViewModel(data, userMessage);
        }

        internal OptionsViewModel<T> UpdateCalculatedFields(T model)
        {
            var data = Service.UpdateCalculatedFields(model);
            var userMessage = new UserMessage(data, CommonResx.SaveSuccessMessage);

            return GetViewModel(data, userMessage);
        }
        #endregion Internal Methods

        #region Helpers
        private OptionsViewModel<T> GetViewModel(T model, UserMessage userMessage)
            => new OptionsViewModel<T>
            {
                Data = model,
                UserMessage = userMessage,
                UserAccess = GetAccessRights(),
            };
        #endregion Helpers

        #region Accounts
        private readonly string _accountCacheKey;
        private readonly Func<Account, long> _accountFilter;

        internal EnumerableResponse<Account> GetAccounts(T model, int pageNumber, int pageSize)
        {
            return GetData(model, pageNumber, pageSize);
        }

        private EnumerableResponse<Account> GetData(T model, int pageNumber, int pageSize)
        {
            Account newLine = GetLine(null);
            EnumerableResponse<Account> enumerableResponse = MergeChangeItemToCache(
                model.Accounts,
                pageNumber,
                pageSize,
                0,
                "SerialNumber",
                _accountCacheKey,
                GetPagedData,
                _accountFilter,
                null);

            return enumerableResponse;
        }

        private EnumerableResponse<Account> GetPagedData(int pageNumber, int pageSize)
            => Service.GetAccounts(pageNumber, pageSize);

        private Account GetLine(T model)
        {
            Account account = new Account();
            account.SerialNumber = GenerateKey();
            return account;
        }
        #endregion Accounts

        //#region Base debug
        //protected new EnumerableResponse<TModel> MergeChangeItemToCache<TModel, TKeyType>(EnumerableResponse<TModel> model, int pageNumber, int pageSize, int insertIndex, string keyProperty, string cacheKey, Func<int, int, EnumerableResponse<TModel>> getPagedData, Func<TModel, TKeyType> keyFilter, TModel newLineModel) where TModel : ModelBase where TKeyType : struct
        //{
        //    List<TModel> list = this.SessionHelper.Get<List<TModel>>(cacheKey);
        //    bool flag = false;
        //    if (model != null && model.Items != null)
        //    {
        //        flag = (Enumerable.Any<TModel>(model.Items, (Func<TModel, bool>)((TModel c) => c.HasChanged)) || Enumerable.Any<TModel>(model.Items, (Func<TModel, bool>)((TModel c) => c.IsNewLine)) || Enumerable.Any<TModel>(model.Items, (Func<TModel, bool>)((TModel c) => c.IsDeleted)) || insertIndex > 0);
        //    }
        //    if (list == null)
        //    {
        //        if (!flag)
        //        {
        //            return getPagedData(pageNumber, pageSize);
        //        }
        //        EnumerableResponse<TModel> enumerableResponse = getPagedData(-1, -1);
        //        list = Enumerable.ToList<TModel>(enumerableResponse.Items);
        //        this.SessionHelper.Set<List<TModel>>(cacheKey, list);
        //    }
        //    if (model != null && model.Items != null)
        //    {
        //        if (flag)
        //        {
        //            if (Enumerable.Any<TModel>((IEnumerable<TModel>)list))
        //            {
        //                foreach (TModel item in model.Items)
        //                {
        //                    Filter filter = new Filter();
        //                    filter.Field = new GridField
        //                    {
        //                        field = keyProperty
        //                    };
        //                    filter.Operator = Operator.Equal;
        //                    filter.Value = keyFilter(item);
        //                    Filter filter2 = filter;
        //                    Expression<Func<TModel, bool>> predicate = ExpressionBuilder<TModel>.CreateExpression(filter2, (ParameterExpression)null);
        //                    TModel val = Queryable.FirstOrDefault<TModel>(Queryable.AsQueryable<TModel>((IEnumerable<TModel>)list), predicate);
        //                    if (val != null)
        //                    {
        //                        list.Remove(val);
        //                    }
        //                }
        //            }
        //            list.AddRange(model.Items);
        //            this.SessionHelper.Set<List<TModel>>(cacheKey, list);
        //        }
        //        list = Enumerable.ToList<TModel>((IEnumerable<TModel>)list);
        //    }
        //    if (insertIndex > 0)
        //    {
        //        IEnumerable<TModel> collection = Enumerable.Where<TModel>((IEnumerable<TModel>)list, (Func<TModel, bool>)((TModel d) => d.IsDeleted));
        //        list = AddNewLine(Enumerable.Where<TModel>((IEnumerable<TModel>)list, (Func<TModel, bool>)((TModel d) => !d.IsDeleted)), newLineModel, insertIndex);
        //        list.AddRange(collection);
        //        this.SessionHelper.Set<List<TModel>>(cacheKey, list);
        //    }
        //    int count = list.Count;
        //    list = Enumerable.ToList<TModel>((IEnumerable<TModel>)Enumerable.OrderBy<TModel, int>(Enumerable.Where<TModel>((IEnumerable<TModel>)list, (Func<TModel, bool>)((TModel c) => !c.IsDeleted)), (Func<TModel, int>)((TModel c) => c.DisplayIndex)));
        //    EnumerableResponse<TModel> enumerableResponse2 = new EnumerableResponse<TModel>();
        //    enumerableResponse2.Items = Enumerable.Take<TModel>(Enumerable.Skip<TModel>((IEnumerable<TModel>)list, pageNumber * pageSize), pageSize);
        //    enumerableResponse2.TotalResultsCount = Enumerable.Count<TModel>((IEnumerable<TModel>)list);
        //    enumerableResponse2.CachedListCount = count;
        //    return enumerableResponse2;
        //}

        //protected new EnumerableResponse<TModel> GetDataForSave<TModel, TKeyType>(EnumerableResponse<TModel> model, string cacheKey, string keyProperty, Func<TModel, TKeyType> keyFilter) where TModel : ModelBase where TKeyType : struct
        //{
        //    List<TModel> list = this.SessionHelper.Get<List<TModel>>(cacheKey);
        //    if (list != null)
        //    {
        //        MergeChangeItemToCache(model, 0, 0, 0, keyProperty, cacheKey, null, keyFilter, null);
        //        list = this.SessionHelper.Get<List<TModel>>(cacheKey);
        //    }
        //    else if (model.Items != null)
        //    {
        //        list = Enumerable.ToList<TModel>(model.Items);
        //    }
        //    if (list != null && Enumerable.Any<TModel>((IEnumerable<TModel>)list))
        //    {
        //        list.RemoveAll((Predicate<TModel>)delegate (TModel c)
        //        {
        //            if (c.IsDeleted)
        //            {
        //                return c.IsNewLine;
        //            }
        //            return false;
        //        });
        //        list = Enumerable.ToList<TModel>(Enumerable.Where<TModel>((IEnumerable<TModel>)list, (Func<TModel, bool>)delegate (TModel c)
        //        {
        //            if (!c.HasChanged && !c.IsNewLine)
        //            {
        //                return c.IsDeleted;
        //            }
        //            return true;
        //        }));
        //    }
        //    EnumerableResponse<TModel> enumerableResponse = new EnumerableResponse<TModel>();
        //    enumerableResponse.Items = list;
        //    return enumerableResponse;
        //}
        //#endregion
    }
}