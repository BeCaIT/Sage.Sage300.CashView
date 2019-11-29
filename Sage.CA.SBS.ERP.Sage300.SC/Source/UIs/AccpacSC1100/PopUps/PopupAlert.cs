using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Design;
using System.Text;
using System.Windows.Forms;
using Telerik.WinControls;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.PopUps
{
    public partial class PopupAlert : Telerik.WinControls.UI.RadForm
    {
        [Browsable(true)]
        [Category("Data")]
        [DefaultValue(null)]
        [RefreshProperties(RefreshProperties.Repaint)]
        [AttributeProvider(typeof(IListSource))]
        public object DataSource
        {
            get => bsApplication.DataSource;
            set => bsApplication.DataSource = value;
        }

        [Browsable(true)]
        [Category("Data")]
        [DefaultValue("")]
        [Editor("System.Windows.Forms.Design.DataMemberListEditor, System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", typeof(UITypeEditor))]
        public string DataMember
        {
            get => bsApplication.DataMember;
            set => bsApplication.DataMember = value;
        }

        public PopupAlert()
        {
            InitializeComponent();
        }

        private void PopupLoan_Load(object sender, EventArgs e)
        {

        }

        private void BtnClose_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
