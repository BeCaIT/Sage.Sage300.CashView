using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Controls
{
    public class SCAxHost : AxHost
    {
        internal event OnAttachInterfacesHandler OnAttachInterfaces;
        internal delegate void OnAttachInterfacesHandler(object ocx);

        internal SCAxHost(string progID)
            : base(Type.GetTypeFromProgID(progID).GUID.ToString()) { }

        protected override void AttachInterfaces()
        {
            base.AttachInterfaces();

            OnAttachInterfaces(GetOcx());
        }

        internal static new Color GetColorFromOleColor(uint color)
        {
            return AxHost.GetColorFromOleColor(color);
        }

        internal static new uint GetOleColorFromColor(Color color)
        {
            return AxHost.GetOleColorFromColor(color);
        }

        internal static new Font GetFontFromIFont(object font)
        {
            return AxHost.GetFontFromIFont(font);
        }

        internal static new object GetIFontFromFont(Font font)
        {
            return AxHost.GetIFontFromFont(font);
        }
    }
}
