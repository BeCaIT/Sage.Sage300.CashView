using AccpacCOMAPI;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sage.CA.SBS.ERP.Sage300.SC.Processor
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            if (args == null || args.Length < 1)
                return;

            AccpacSession session = null;

            try
            {
                session = new AccpacSession();
                session.Init("", "SC", "SC0800", "63A");
                session.OpenWin(Environment.UserDomainName, Environment.UserName, string.Empty, args[0], DateTime.Now, 0, string.Empty);
                session.Close();
            }
            catch
            {

            }
            finally
            {
                if (session != null)
                {
                    Marshal.ReleaseComObject(session);
                    session = null;
                }
            }
        }
    }
}
