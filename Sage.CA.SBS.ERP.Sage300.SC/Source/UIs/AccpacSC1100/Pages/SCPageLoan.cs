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

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Pages
{
    [ToolboxItem(true)]
    [ComplexBindingProperties("DataSource", "DataMember")]
    public partial class SCPageLoan : UserControl
    {
        [Browsable(true)]
        [Category("Data")]
        [DefaultValue(null)]
        [RefreshProperties(RefreshProperties.Repaint)]
        [AttributeProvider(typeof(IListSource))]
        public object DataSource
        {
            get => grdLoans.DataSource;
            set
            {
                string dataMember = grdLoans.DataMember;
                grdLoans.DataSource = value;
                ////
                //// Fix radGridView losing datamember
                ////
                grdLoans.DataMember = dataMember;
            }
        }

        [Browsable(true)]
        [Category("Data")]
        [DefaultValue("")]
        [Editor("System.Windows.Forms.Design.DataMemberListEditor, System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", typeof(UITypeEditor))]
        public string DataMember
        {
            get => grdLoans.DataMember;
            set => grdLoans.DataMember = value;
        }

        private string _formatString = "n";
        public string FormatString
        {
            get => _formatString;
            set
            {
                _formatString = value;

                string internalFormatString = "{0:" + _formatString + "}";
            }
        }

        public SCPageLoan()
        {
            InitializeComponent();
        }

        private void GrdLoans_CurrentRowChanged(object sender, Telerik.WinControls.UI.CurrentRowChangedEventArgs e)
        {
            scLoan.DataSource = e.CurrentRow.DataBoundItem;
        }
    }
}
