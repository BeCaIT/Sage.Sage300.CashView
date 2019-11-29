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
using Telerik.WinControls.UI;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    [ToolboxItem(true)]
    [ComplexBindingProperties("DataSource", "DataMember")]
    public partial class SCLoan : UserControl
    {
        [Browsable(true)]
        [Category("Data")]
        [DefaultValue(null)]
        [RefreshProperties(RefreshProperties.Repaint)]
        [AttributeProvider(typeof(IListSource))]
        public object DataSource
        {
            get => bsLoan.DataSource;
            set => bsLoan.DataSource = value;
        }

        [Browsable(true)]
        [Category("Data")]
        [DefaultValue("")]
        [Editor("System.Windows.Forms.Design.DataMemberListEditor, System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", typeof(UITypeEditor))]
        public string DataMember
        {
            get => bsLoan.DataMember;
            set => bsLoan.DataMember = value;
        }

        private string _formatString = "n";
        public string FormatString
        {
            get => _formatString;
            set
            {
                _formatString = value;

                string internalFormatString = "{0:" + _formatString + "}";

                //radMaskedEditBox1.Mask = _formatString;
            }
        }

        public SCLoan()
        {
            InitializeComponent();
        }
    }
}
