/* Copyright (c) 2019 Sage Software Asia Pte Ltd.  All rights reserved. */

using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Menu;
using Sage.CA.SBS.ERP.Sage300.Common.BusinessRepository.Utilities;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Bootstrap;
using Sage.CA.SBS.ERP.Sage300.Common.Interfaces.Repository.Menu;
using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.Common.Models.Portal;
using Sage.CA.SBS.ERP.Sage300.Core.Logging;
using Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Interfaces.BusinessRepository;
using Sage.CA.SBS.ERP.Sage300.SC.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.Diagnostics;

namespace Sage.CA.SBS.ERP.Sage300.SC.BusinessRepository.Menu
{
    /// <summary>
    /// SC Menu Module helper
    /// </summary>
    [Export(typeof(IMenuModuleHelper))]
    [BootstrapMetadataExport("SC", new[] { BootstrapAppliesTo.Web }, 10)]
    class SCMenuModuleHelper : AbstractMenuModuleHelper
    {
        /// <summary>
        /// Return Module specified
        /// </summary>
        public override string Module
        {
            get { return "SC"; }
        }

        /// <summary>
        /// Return Name of the screen file
        /// </summary>
        public override string MenuDetailFileName
        {
            get { return "SCMenuDetails.xml"; }
        }

        /// <summary>
        /// Return MultiCurrency status
        /// </summary>
        public bool IsMultiCurrency { get; private set; }


        /// <summary>
        /// Initialize the module manager
        /// </summary>
        /// <param name="company">string</param>
        /// <param name="context">Context</param>
        public override void Initialize(string company, Context context)
        {
            _context = context;

            //using (ProcessorRepository processorRepository = new ProcessorRepository(_context))
            //{
            //    _hasLoanRecords = processorRepository.Process();
            //    Logger.Error("Initialize - hasLoans: " + _hasLoanRecords.ToString(), "SC", _context);
            //}

            PrepareDataFile(company);
        }

        /// <summary>
        /// Return Menu Items with activation filter applied
        /// </summary>
        /// <returns>List</returns>
        public override List<NavigableMenu> GetFilteredMenuItems()
        {
            //using (ProcessorRepository processorRepository = new ProcessorRepository(_context))
            //{
            //    _hasLoanRecords = processorRepository.Process();
            //    Logger.Error("GetFilteredMenuItems - hasLoans: " + _hasLoanRecords.ToString(), "SC", _context);
            //}

            var criteriaList = new List<Func<NavigableMenu, bool>>();
            criteriaList.Add(AccessToLoanMenu);

            return GetApplyFilteredMenuItems(criteriaList);
        }

        /// <summary>
        /// Flag to indicate whether the menu is third party development menu
        /// </summary>
        public override bool IsPlugInMenu
        {
            get { return true; }
        }

        private Context _context;
        private bool _hasLoanRecords = true;

        public bool AccessToLoanMenu(NavigableMenu menu)
        {
            if (menu.MenuId == "SC1105")
            {
                using (ProcessorRepository processorRepository = new ProcessorRepository(_context))
                {
                    _hasLoanRecords = processorRepository.Process();
                    Logger.Error("AccessToLoanMenu - hasLoans: " + _hasLoanRecords.ToString(), "SC", _context);

                    return _hasLoanRecords;
                }
            }
            else
                return true;
        }
    }
}
