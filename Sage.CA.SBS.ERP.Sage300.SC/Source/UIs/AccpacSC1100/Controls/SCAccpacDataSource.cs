using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    public partial class SCAccpacDataSource : Component
    {
        public SCAccpacDataSource()
        {
            InitializeComponent();
        }

        public SCAccpacDataSource(IContainer container)
        {
            container.Add(this);

            InitializeComponent();
        }
    }
}
