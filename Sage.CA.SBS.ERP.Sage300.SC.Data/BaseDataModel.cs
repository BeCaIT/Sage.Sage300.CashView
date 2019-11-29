using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Data
{
    public abstract class BaseDataModel : INotifyPropertyChanged
    {
        #region INotifyPropertyChanged Support
        public event PropertyChangedEventHandler PropertyChanged;

        protected bool SetProperty<T>
            (ref T backingField,
            T value,
            string[] relatedProperties = null,
            [CallerMemberName]string propertyName = null)
        {
            if (EqualityComparer<T>.Default.Equals(backingField, value))
                return false;

            backingField = value;
            RaisePropertyChanged(propertyName);

            if (relatedProperties != null)
                foreach (var relatedProperty in relatedProperties)
                    RaisePropertyChanged(relatedProperty);

            return true;
        }

        protected void RaisePropertyChanged(
            [CallerMemberName]string propertyName = null)
            => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        #endregion INotifyPropertyChanged Support
    }
}
