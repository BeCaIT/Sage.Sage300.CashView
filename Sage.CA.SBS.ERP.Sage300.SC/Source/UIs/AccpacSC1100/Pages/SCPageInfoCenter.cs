using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Design;
using Sage.CA.SBS.ERP.Sage300.SC.Data;
using AccpacCOMAPI;
using System.Runtime.InteropServices;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages
{
    [ToolboxItem(true)]
    [ComplexBindingProperties("DataSource", "DataMember")]
    public partial class SCPageInfoCenter : UserControl
    {
        [Browsable(true)]
        [Category("Data")]
        [DefaultValue(null)]
        [RefreshProperties(RefreshProperties.Repaint)]
        [AttributeProvider(typeof(IListSource))]
        public object DataSource
        {
            get => bsInfoCenter.DataSource;
            set => bsInfoCenter.DataSource = value;
        }

        [Browsable(true)]
        [Category("Data")]
        [DefaultValue("")]
        [Editor("System.Windows.Forms.Design.DataMemberListEditor, System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", typeof(UITypeEditor))]
        public string DataMember
        {
            get => bsInfoCenter.DataMember;
            set => bsInfoCenter.DataMember = value;
        }

        public SCPageInfoCenter()
        {
            InitializeComponent();
        }

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
        }

        private void MnuSnooze_07days_Click(object sender, EventArgs e)
        {
            Snooze(7);
        }

        private void MnuSnooze_14days_Click(object sender, EventArgs e)
        {
            Snooze(14);
        }

        private void MnuSnooze_30days_Click(object sender, EventArgs e)
        {
            Snooze(30);

        }

        private void Snooze(int days)
        {
            AccpacProperty propThresholdAlert = null;
            try
            {
                ApplicationData.Current.ThresholdAlertSnooze = DateTime.Now.AddDays(days);

                object snoozeUntil = ApplicationData.Current.ThresholdAlertSnooze.ToString("yyyyMMdd");
                propThresholdAlert = Sage300Application.Current.Session.GetAccpacProperty();
                propThresholdAlert.objectID = propThresholdAlert.menuID = Sage300Application.Current.Session.ProgramName;
                propThresholdAlert.keyword = "SNOOZEALERT";
                propThresholdAlert.PropPut(ref snoozeUntil, (snoozeUntil as string).Length);

            }
            catch (COMException)
            {
                Sage300Application.Current.ReportErrors();
            }
            finally
            {
                if (propThresholdAlert != null)
                {
                    Marshal.ReleaseComObject(propThresholdAlert);
                    propThresholdAlert = null;
                }
            }

            btnThresholdBreachedAlert.Visible = false;
            if (!picBIL.Visible)
                OnDismiss(new EventArgs());
        }

        private void BsInfoCenter_BindingComplete(object sender, BindingCompleteEventArgs e)
        {
            btnThresholdBreachedAlert.Visible = ApplicationData.Current.ShowThresholdAlert;
            picBIL.Visible = ApplicationData.Current.HasNewLoanRecord;
        }

        private void PicBIL_Click(object sender, EventArgs e)
            => OnClick(e);

        public event EventHandler Dismiss;

        private void OnDismiss(EventArgs e)
            => Dismiss?.Invoke(this, e);
    }
}
