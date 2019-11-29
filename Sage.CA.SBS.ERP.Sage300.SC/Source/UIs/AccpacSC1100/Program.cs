using System;
using System.Linq;
using System.Windows.Forms;

namespace Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100
{
    static class Program
    {
        [System.Runtime.InteropServices.DllImport("kernel32.dll")]
        static extern uint GetSystemDefaultLCID();

        //static Telerik.WinControls.Themes.TelerikMetroTheme applicationTheme = new Telerik.WinControls.Themes.TelerikMetroTheme();

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            //
            // Enforce the proper language settings for older version than 2019 (Broken vietnamese in ViewList)
            //
            Application.CurrentCulture = new System.Globalization.CultureInfo((int)GetSystemDefaultLCID());

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            Telerik.WinControls.ThemeResolutionService.LoadPackageResource("Sage.CA.SBS.ERP.Sage300.SC.AccpacSC1100.Themes.Sage300.tssp");
            Telerik.WinControls.ThemeResolutionService.ApplicationThemeName = "Sage300";

            string objectHandle = string.Empty;
            if (args != null && args.Length > 0)
                objectHandle = args[0];

            try
            {
                using (Sage300Application app = new Sage300Application(objectHandle))
                {
                    Application.Run(new FormMain());
                }
            }
            catch { }
        }
    }
}