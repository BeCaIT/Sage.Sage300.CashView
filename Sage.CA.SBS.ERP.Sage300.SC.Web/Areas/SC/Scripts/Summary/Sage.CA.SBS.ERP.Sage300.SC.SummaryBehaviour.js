/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var modelData;
var scSummaryUI = scSummaryUI || {};

scSummaryUI = {
    hasKoBindingApplied: false,
    isKendoControlNotInitialised: false,
    viewModel: {},
    ignoreIsDirtyProperties: [],
    computedProperties: [
        "UIMode",
    ],
    //
    init: function () {
        if (scSummaryUISuccess.ensureOptions(scSummaryViewModel)) {
            scSummaryUISuccess.displayResult(scSummaryViewModel);
            //
            scSummaryUI.initGrid();
            scSummaryUI.initButtons();
            scSummaryUI.initFCButtons();
            //
            sc.utls.checkShowAlert(scSummaryUI.viewModel);
        }
    },

    initGrid: function () {
        var grid = $("#scSummaryGrid").data("kendoGrid");
        //
        //// Set column titles
        $("#scSummaryGrid th[data-field=AmountPeriod0]").html(scSummaryUI.viewModel.Data.UIOptions.Period0Name());
        $("#scSummaryGrid th[data-field=AmountPeriod1]").html(scSummaryUI.viewModel.Data.UIOptions.Period1Name());
        $("#scSummaryGrid th[data-field=AmountPeriod2]").html(scSummaryUI.viewModel.Data.UIOptions.Period2Name());
        $("#scSummaryGrid th[data-field=AmountPeriod3]").html(scSummaryUI.viewModel.Data.UIOptions.Period3Name());
        $("#scSummaryGrid th[data-field=AmountPeriod4]").html(scSummaryUI.viewModel.Data.UIOptions.Period4Name());
        $("#scSummaryGrid th[data-field=AmountPeriod5]").html(scSummaryUI.viewModel.Data.UIOptions.Period5Name());
        $("#scSummaryGrid th[data-field=AmountPeriod6]").html(scSummaryUI.viewModel.Data.UIOptions.Period6Name());
        //
        ////
        grid.bind("dataBound", function (e) {
            var rows = e.sender.tbody.children();
            for (var i = 0; i < rows.length; i++) {
                var row = $(rows[i]);
                row.removeClass("k-state-selected");

                var dataItem = e.sender.dataItem(row);
                var important = dataItem.get("Important");
                if (important) {
                    row.addClass("bold");
                }
            }
        });
    },

    initButtons: function () {
        /***** REPORT BUTTONS ****/
        // Print Cash Flow Summary
        $("#btnPrintCashFlowSummary").bind('click', function () {
            //sg.utls.SyncExecute(scSummaryUI.saveOptions);
            sg.utls.SyncExecute(scReportsUtil.printReport("SCSUM03"));
        });
        // Print Cash and Bank Accounts
        $("#btnPrintCashBankAccounts").bind('click', function () {
            //sg.utls.SyncExecute(scSummaryUI.saveOptions);
            sg.utls.SyncExecute(scReportsUtil.printReport("SCCABK"));
        });
        // Print Inflow and Outflow Entries
        $("#btnPrintInflowOutflowEntries").bind('click', function () {
            //sg.utls.SyncExecute(scSummaryUI.saveOptions);
            sg.utls.SyncExecute(scReportsUtil.printReport("SCINOUT"));
        });
    },

    initMenus: function () {
        $("#btnPrintReport").kendoMenu();
    },

    initBrowserBackIsDirty: function () {
        $(window).bind("beforeunload", function () {
            if (scSummaryUI.viewModel.isModelDirty.isDirty())
                return;

            $("<div />").html($.validator.format(globalResource.SaveConfirm2, scSummaryResources.Title)).text();
        });
    },

    initFCButtons: function () {
        $("#btnCreateForecast").bind("click", function () {
            //$("#scForecastEntryGrid").data("kendoGrid").dataSource.insert(0, scForecastEntryGrid.createNewLine());
            scForecastEntryGrid.grid.dataSource.insert(0, scForecastEntryGrid.createNewLine());
            scForecastEntryGrid.grid.tbody.find("tr:eq(0) td:eq(0)").click();
        });

        $("#btnDeleteForecast").unbind("click").bind("click", function () {
            $("#message").empty();

            var grid = $("#scForecastEntryGrid").data("kendoGrid");
            var selectedRow = grid.select()[0];
            if (selectedRow) {
                sg.utls.showKendoConfirmationDialog(
                    function () { scForecastEntryGrid.deleteLine(selectedRow); },
                    null,
                    sg.utls.formatString(scSummaryResources.DeleteConfirmMessage, scForecastEntryResources.Title),
                    scSummaryResources.DeleteTitle);
            }
        });
    }
};

/****************************** Summary Grid - Start ******************************/
var scSummaryUIGrid = {
    scSummaryUIGridConfig: {
        pageSize: 13, //sg.utls.gridPageSize,
        pageable: false,
        navigatable: false,
        scrollable: false,
        resizable: true,
        selectable: false,
        sortable: false,
        isServerPaging: true,
        editable: false,
        pageUrl: sg.utls.url.buildUrl("SC", "Summary", "Get"),
        buildGridData: function (successData) {
            var gridData = [];
            gridData.data = successData.DataList;
            gridData.totalResultsCount = successData.TotalResultsCount;

            return gridData;
        },
        columns: [
            {
                field: "Description",
                attributes: { "class": "w120" },
                headerAttributes: { "class": "w120 k-header align-center" },
                title: scSummaryResources.Description,
                width: "20%",
            },
            {
                field: "AmountPeriod0",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                template: "#= AmountPeriod0 == 0 ? '' : sg.utls.kndoUI.getFormattedDecimalNumber(AmountPeriod0, sg.utls.homeCurrency.Decimals) #",
                width: "7%",
            },
            {
                field: "AmountPeriod1",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                template: "#= AmountPeriod1 == 0 ? '' : sg.utls.kndoUI.getFormattedDecimalNumber(AmountPeriod1, sg.utls.homeCurrency.Decimals) #",
                width: "7%",
            },
            {
                field: "AmountPeriod2",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                template: "#= AmountPeriod2 == 0 ? '' : sg.utls.kndoUI.getFormattedDecimalNumber(AmountPeriod2, sg.utls.homeCurrency.Decimals) #",
                width: "7%",
            },
            {
                field: "AmountPeriod3",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                template: "#= AmountPeriod3 == 0 ? '' : sg.utls.kndoUI.getFormattedDecimalNumber(AmountPeriod3, sg.utls.homeCurrency.Decimals) #",
                width: "7%",
            },
            {
                field: "AmountPeriod4",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                template: "#= AmountPeriod4 == 0 ? '' : sg.utls.kndoUI.getFormattedDecimalNumber(AmountPeriod4, sg.utls.homeCurrency.Decimals) #",
                width: "7%",
            },
            {
                field: "AmountPeriod5",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                template: "#= AmountPeriod5 == 0 ? '' : sg.utls.kndoUI.getFormattedDecimalNumber(AmountPeriod5, sg.utls.homeCurrency.Decimals) #",
                width: "7%",
            },
            {
                field: "AmountPeriod6",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                template: "#= AmountPeriod6 == 0 ? '' : sg.utls.kndoUI.getFormattedDecimalNumber(AmountPeriod6, sg.utls.homeCurrency.Decimals) #",
                width: "7%",
            },
            {
                field: "AmountTotal",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                template: "#= AmountTotal == 0 ? '' : sg.utls.kndoUI.getFormattedDecimalNumber(AmountTotal, sg.utls.homeCurrency.Decimals) #",
                title: scSummaryResources.Total,
                width: "7%",
            }
        ],
        //
        //// Events
        dataBound: function (e) {
            var rows = e.sender.tbody.children();
            for (var i = 0; i < rows.length; i++) {
                var row = $(rows[i]);
                var dataItem = e.sender.dataItem(row);
                var important = dataItem.get("Important");
                if (important) {
                    row.addClass("bold");
                }
            }
        }
    }
};
/****************************** Summary Grid - End ******************************/

// Callbacks
var scSummaryUISuccess = {

    get: function (jsonResult) {
        if (jsonResult === null) return;

        if (jsonResult.UserMessage.IsSuccess) {
            scSummaryUISuccess.displayResult(jsonResult, sg.utls.OperationMode.LOAD);
        }
    },

    ensureOptions: function (jsonResult) {
        if (jsonResult !== null
            && jsonResult.UserMessage !== null
            && jsonResult.UserMessage.IsSuccess)
            return true;
        else
            sg.utls.showMessage(jsonResult);

        return false;
    },

    displayResult: function (jsonResult, uiMode) {
        if (jsonResult !== null) {
            if (!scSummaryUI.hasKoBindingApplied) {
                scSummaryUI.viewModel = ko.mapping.fromJS(jsonResult);
                modelData = scSummaryUI.viewModel.Data;
                scSummaryKoExtn.modelExtension(scSummaryUI.viewModel, uiMode);
                scSummaryUI.viewModel.isModelDirty = new ko.dirtyFlag(modelData, scSummaryUI.ignoreIsDirtyProperties);

                ko.applyBindings(scSummaryUI.viewModel);
                scSummaryUI.hasKoBindingApplied = true;
            } else {
                ko.mapping.fromJS(jsonResult, scSummaryUI.viewModel);
                scSummaryUI.viewModel.isModelDirty.reset();
            }

            if (!scSummaryUI.isKendoControlNotInitialised) {
                scSummaryUI.isKendoControlNotInitialised = true;
            }
        }
    }
};


/****************************** ForecastEntry Grid - Start ******************************/
var scForecastEntryGrid = {
    grid: null,
    data: ko.observableArray(),
    currentRecord: null,
    currentRowIndex: -1,
    editing: false,
    timeOut: 1000,
    createNewLine: function () {
        return {
            "RecordType": 0,
            "Source": "SC",
            "CustomerVendor": null,
            "DocumentNumber": "*** NEW ***",
            "PaymentNumber": 0,
            "EffectiveDate": sg.utls.kndoUI.getDate(new Date()),
            "Description": "",
            "AmountDue": 0,
            "AmountPaid": 0,
            "Inflow": 0,
            "Outflow": 0,
            "IsNewLine": true,
            "IsDeleted": false,
            "HasChanged": false
        };
    },
    createNewLineParam: function (data, pageNumber, pageSize, newinsertIndex) {

    },
    getPageOptions: function () {
        return {
            "PageNumber": scForecastEntryGrid.grid.dataSource.page(),
            "PageSize": scForecastEntryGrid.grid.dataSource.pageSize()
        };
    },
    deleteLine: function (selectedRow) {
        var dataItem = $("#scForecastEntryGrid").data("kendoGrid").dataItem(selectedRow);
        dataItem.set("IsDeleted", true);
        scForecastEntryRepository.delete(dataItem, scForecastEntryCallbacks.delete);
    },
    queueSaveRecord: function (rowIndex) {
        if (scForecastEntryGrid.editing)
            return;

        setTimeout(function () {
            scForecastEntryGrid.checkSaveRecord(rowIndex);
        }, scForecastEntryGrid.timeOut);
    },
    checkSaveRecord: function (rowIndex) {
        if (scForecastEntryGrid.editing)
            return;

        scForecastEntryGrid.editing = true;

        if (rowIndex !== -1) {
            //scForecastEntryGrid.grid.closeCell();

            var dataItem = scForecastEntryGrid.grid.dataItem("tbody tr:eq(" + rowIndex + ")");
            if (dataItem) {
                if (dataItem.IsNewLine) {
                    if (dataItem.HasChanged) {
                        // Add
                        scForecastEntryRepository.add(
                            dataItem,
                            scForecastEntryGrid.getPageOptions(),
                            scForecastEntryCallbacks.add);
                        dataItem.set("IsNewLine", false);
                        dataItem.set("HasChanged", false);
                    } else {
                        // Cancel
                        scForecastEntryGrid.grid.dataSource.remove(dataItem);
                    }
                } else if (dataItem.HasChanged) {
                    console.log("Saving record: " + rowIndex + " - " + dataItem.DocumentNumber + " - ETag: " + dataItem.ETag);
                    //
                    scForecastEntryRepository.update(dataItem, scForecastEntryCallbacks.update);
                    dataItem.set("HasChanged", false);
                }
            }
        }

        scForecastEntryGrid.editing = false;
    },
    config: {
        pageSize: 7, //sg.utls.gridPageSize,
        pageable: {
            input: true,
            numeric: false,
            refresh: true,
        },
        navigatable: true,
        scrollable: true,
        resizable: true,
        selectable: "row",
        sortable: false,
        isServerPaging: true,
        editable: {
            mode: "incell",
            confirmation: true,
            createAt: "top"
        },
        pageUrl: sg.utls.url.buildUrl("SC", "ForecastEntry", "Get"),
        buildGridData: function (successData) {
            if (scForecastEntryGrid.grid === null)
                scForecastEntryGrid.grid = $("#scForecastEntryGrid").data("kendoGrid");

            var gridData = [];
            gridData.data = successData.DataList;
            ko.mapping.fromJS(successData.DataList, {}, scForecastEntryGrid.data);
            //successData.TotalResultsCount = successData.TotalResultsCount;

            //var grid = $("#scForecastEntriesGrid").data("kendoGrid");
            //var pageNumber = grid.dataSource.page();
            //if (successData.TotalResultsCount === 0) {
            //    pageNumber = 0;
            //}
            gridData.totalResultsCount = successData.TotalResultsCount;
            //scLoanUICallbacks.bindData(successData);

            return gridData;
        },
        columns: [
            {
                field: "DocumentNumber",
                title: scForecastEntryResources.DocumentNumber,
                attributes: { "class": "" },
                headerAttributes: { "class": "" },
                width: "20%",
                editor: function (container, options) {
                    //var grid = $('#scForecastEntryGrid').data("kendoGrid");
                    sg.utls.kndoUI.nonEditable(scForecastEntryGrid.grid, container);
                }
            }, {
                field: "EffectiveDate",
                title: scForecastEntryResources.EffectiveDate,
                attributes: { "class": "w160 jGrddate" },
                headerAttributes: { "class": "w160 jGrddate" },
                format: "{0:d}",
                width: "20%",
                template: sg.utls.kndoUI.getDateTemplate("EffectiveDate"),
                editor: function (container, options) {
                    if (scSummaryUI.viewModel.Data.UIOptions.HasForecastEntryRight()) {
                        var html = scForecastEntryGridFields.txtEffectiveDate;
                        $(html).appendTo(container);
                        sg.utls.kndoUI.datePicker("txtEffectiveDate");
                        $(container).off("focusout").on("focusout", function () {
                            scForecastEntryGrid.editing = false;
                            scForecastEntryGrid.currentRowIndex = container.parent()[0].rowIndex;
                            scForecastEntryGrid.queueSaveRecord(scForecastEntryGrid.currentRowIndex);

                            console.log("effectivedate blur", scForecastEntryGrid);
                        });
                    } else {
                        sg.utls.kndoUI.nonEditable(scForecastEntryGrid.grid, container);
                    }
                }
            }, {
                field: "Description",
                title: scForecastEntryResources.Description,
                attributes: { "class": "w250" },
                headerAttributes: { "class": "w250" },
                width: "20%",
                editor: function (container, options) {
                    if (scSummaryUI.viewModel.Data.UIOptions.HasForecastEntryRight()) {
                        var html = scForecastEntryGridFields.txtDescription;
                        $(html).appendTo(container);
                        $(container).off("focusout").on("focusout", function () {
                            scForecastEntryGrid.editing = false;
                            scForecastEntryGrid.currentRowIndex = container.parent()[0].rowIndex;
                            scForecastEntryGrid.queueSaveRecord(scForecastEntryGrid.currentRowIndex);

                            console.log("description blur", scForecastEntryGrid);
                        });
                    } else {
                        sg.utls.kndoUI.nonEditable(scForecastEntryGrid.grid, container);
                    }
                }
            }, {
                field: "Inflow",
                title: scForecastEntryResources.Inflow,
                attributes: { "class": "w250 align-right" },
                headerAttributes: { "class": "w250" },
                width: "20%",
                template: "#= sg.utls.kndoUI.getFormattedDecimalNumber(Inflow, sg.utls.homeCurrency.Decimals) #",
                editor: function (container, options) {
                    if (scSummaryUI.viewModel.Data.UIOptions.HasForecastEntryRight()) {
                        if ($(scForecastEntryGridFields.txtInflow).data("kendoNumericTextBox") !== undefined)
                            sg.utls.kndoUI.decimalTextbox("txtInflow", "n" + sg.utls.homeCurrency.Decimals, false, 0, null, sg.utls.homeCurrency.Decimals);

                        $(scForecastEntryGridFields.txtInflow).appendTo(container);

                        $(container).off("focusout").on("focusout", function () {
                            scForecastEntryGrid.editing = false;
                            scForecastEntryGrid.currentRowIndex = container.parent()[0].rowIndex;
                            scForecastEntryGrid.queueSaveRecord(scForecastEntryGrid.currentRowIndex);
                        });
                    } else {
                        sg.utls.kndoUI.nonEditable(scForecastEntryGrid.grid, container);
                    }
                }
            }, {
                field: "Outflow",
                title: scForecastEntryResources.OutFlow,
                attributes: { "class": "w250 align-right" },
                headerAttributes: { "class": "w250" },
                width: "20%",
                template: "#= sg.utls.kndoUI.getFormattedDecimalNumber(Outflow, sg.utls.homeCurrency.Decimals) #",
                editor: function (container, options) {
                    if (scSummaryUI.viewModel.Data.UIOptions.HasForecastEntryRight()) {
                        if ($(scForecastEntryGridFields.txtOutflow).data("kendoNumericTextBox") !== undefined)
                            sg.utls.kndoUI.decimalTextbox("txtOutflow", "n" + sg.utls.homeCurrency.Decimals, false, 0, null, sg.utls.homeCurrency.Decimals);

                        $(scForecastEntryGridFields.txtOutflow).appendTo(container);

                        $(container).off("focusout").on("focusout", function () {
                            scForecastEntryGrid.editing = false;
                            scForecastEntryGrid.currentRowIndex = container.parent()[0].rowIndex;
                            scForecastEntryGrid.queueSaveRecord(scForecastEntryGrid.currentRowIndex);
                        });
                    } else {
                        sg.utls.kndoUI.nonEditable(scForecastEntryGrid.grid, container);
                    }
                }
            }
        ],
        //
        //// Events
        dataChange: function (changedData) {
            if (changedData.columnName === "Inflow") {
                if (changedData.cellData !== null) {
                    if (changedData.cellData < 0) {
                        changedData.rowData.Inflow = 0;
                        changedData.rowData.Outflow = -changedData.cellData;
                    } else {
                        changedData.rowData.Inflow = changedData.cellData;
                        changedData.rowData.Outflow = 0;
                    }
                }
            } else if (changedData.columnName === "Outflow") {
                if (changedData.cellData !== null) {
                    if (changedData.cellData < 0) {
                        changedData.rowData.Outflow = 0;
                        changedData.rowData.Inflow = -changedData.cellData;
                    } else {
                        changedData.rowData.Outflow = changedData.cellData;
                        changedData.rowData.Inflow = 0;
                    }
                }
            }

            //scForecastEntryGrid.hasChanged = changedData.rowData.HasChanged;
            if (changedData.rowData.HasChanged) {
                scForecastEntryGrid.currentRecord = changedData.rowData;
                //if (changedData.rowData.IsNewLine) {
                //    scForecastEntryRepository.add(changedData.rowData, scForecastEntryCallbacks.add);
                //} else {
                //    scForecastEntryRepository.update(changedData.rowData, scForecastEntryCallbacks.update);
                //}
                //scForecastEntryGrid.grid.closeCell();
                //scForecastEntryGrid.grid.table.focus();
                //scForecastEntryGrid.editing = false;
                //scForecastEntryGrid.currentRowIndex = 
                //setTimeout(function () {
                //    scForecastEntryGrid.checkSaveRecord();
                //}, scForecastEntryGrid.timeOut);
            }
        },
        //
        //// Event: change
        change: function (e) {
            var currentRowIndex = scForecastEntryGrid.grid.select()[0].rowIndex;

            if (scForecastEntryGrid.currentRowIndex !== currentRowIndex) {
                //    console.log("rowChanged", e);
                scForecastEntryGrid.checkSaveRecord(scForecastEntryGrid.currentRowIndex);

            //    //if (scForecastEntryGrid.currentRecord) {
            //    //    var currentRecord = sg.utls.kndoUI.getSelectedRowData(scForecastEntryGrid.grid);
            //    //    if (currentRecord) {
            //    //        scForecastEntryGrid.checkSaveRecord();
            //    //        //        if (currentRecord.uid !== scForecastEntryGrid.currentRecord.uid) {
            //    //        //            if (scForecastEntryGrid.currentRecord.IsNewLine) {
            //    //        //                var pageNumber = scForecastEntryGrid.grid.dataSource.page();
            //    //        //                var pageSize = 5;
            //    //        //                scForecastEntryRepository.add2(
            //    //        //                    scForecastEntryGrid.currentRecord,
            //    //        //                    pageNumber,
            //    //        //                    pageSize,
            //    //        //                    scForecastEntryCallbacks.add);
            //    //        //            } else {
            //    //        //                scForecastEntryRepository.update(scForecastEntryGrid.currentRecord, scForecastEntryCallbacks.update);
            //    //        //            }
            //    //        //        }
            //    //    }
            //    //}

                scForecastEntryGrid.currentRowIndex = currentRowIndex;
            }
        },
        edit: function (e) {
            scForecastEntryGrid.editing = true;

            console.log("edit", e);
            var currentRowIndex = scForecastEntryGrid.grid.select()[0].rowIndex;

            if (scForecastEntryGrid.currentRowIndex !== currentRowIndex) {
                //
            }
        },
        cancel: function (e) {
            scForecastEntryGrid.queueSaveRecord(e.container.parent()[0].rowIndex);
        },
        save: function (e) {
            scForecastEntryGrid.currentRowIndex = e.container.parent()[0].rowIndex;
        },
    }
};

var scForecastEntryCallbacks = {
    add: function (jsonResult) {
        if (jsonResult) {
            if (jsonResult.UserMessage) {
                if (jsonResult.UserMessage.IsSuccess) {
                    //for (var i = 0; i < scForecastEntryGrid.grid.dataSource.data().length; i++) {
                    //    var dataItem = scForecastEntryGrid.grid.dataSource.data()[i];
                    //    if (dataItem.IsNewLine) {
                    //        dataItem.set("ETag", jsonResult.Data.ETag);
                    //        dataItem.set("DocumentNumber", jsonResult.Data.DocumentNumber);
                    //        dataItem.set("EffectiveDate", jsonResult.Data.EffectiveDate);
                    //        dataItem.set("Description", jsonResult.Data.Description);
                    //        dataItem.set("AmountDue", jsonResult.Data.AmountDue);
                    //        dataItem.set("AmountPaid", jsonResult.Data.AmountPaid);
                    //        dataItem.set("Inflow", jsonResult.Data.Inflow);
                    //        dataItem.set("Outflow", jsonResult.Data.Outflow);
                    //        dataItem.set("IsNewLine", false);
                    //        dataItem.set("HasChanged", false);

                    //        scForecastEntryGrid.currentRecord = null;
                    //        //scForecastEntryGrid.grid.select(scForecastEntryGrid.grid.tbody.find("tr:eq(" + i + ")"));
                    //        scForecastEntryGrid.grid.tbody.find("tr:eq(" + i + ") td:eq(0)").click();
                    //        scForecastEntryGrid.grid.closeCell();
                    //        break;
                    //    }
                    //}
                    //scForecastEntryGrid.currentRecord = null;
                    scForecastEntryGrid.grid.dataSource.page(0);
                    //scForecastEntryGrid.grid.dataSource.read();
                    $("#scSummaryGrid").data("kendoGrid").dataSource.read();
                    scSummaryUI.viewModel.isModelDirty.reset();

                    jsonResult.UserMessage.Message = sg.utls.formatString(jsonResult.UserMessage.Message, scForecastEntryResources.Title, jsonResult.Data.DocumentNumber);
                }
                sg.utls.showMessage(jsonResult);
            }
        }
    },

    update: function (jsonResult) {
        if (jsonResult) {
            if (jsonResult.UserMessage) {
                if (jsonResult.UserMessage.IsSuccess) {
                    for (var i = 0; i < scForecastEntryGrid.grid.dataSource.data().length; i++) {
                        var dataItem = scForecastEntryGrid.grid.dataSource.data()[i];
                        //if (dataItem.HasChanged) {
                        if (dataItem.DocumentNumber === jsonResult.Data.DocumentNumber) {
                            dataItem.set("ETag", jsonResult.Data.ETag);
                            dataItem.set("EffectiveDate", jsonResult.Data.EffectiveDate);
                            dataItem.set("Description", jsonResult.Data.Description);
                            dataItem.set("AmountDue", jsonResult.Data.AmountDue);
                            dataItem.set("AmountPaid", jsonResult.Data.AmountPaid);
                            dataItem.set("Inflow", jsonResult.Data.Inflow);
                            dataItem.set("Outflow", jsonResult.Data.Outflow);
                            dataItem.set("HasChanged", false);

                            scForecastEntryGrid.currentRecord = null;
                            //scForecastEntryGrid.grid.select(scForecastEntryGrid.grid.tbody.find("tr:eq(" + i + ")"));
                            scForecastEntryGrid.grid.tbody.find("tr:eq(" + i + ") td:eq(0)").click();
                            scForecastEntryGrid.grid.closeCell();
                            break;
                        }
                    }
                    $("#scSummaryGrid").data("kendoGrid").dataSource.read();

                    scSummaryUI.viewModel.isModelDirty.reset();

                    jsonResult.UserMessage.Message = sg.utls.formatString(jsonResult.UserMessage.Message, scForecastEntryResources.Title, jsonResult.Data.DocumentNumber);
                }
                sg.utls.showMessage(jsonResult);
            }
        }
    },

    delete: function (jsonResult) {
        if (jsonResult !== null) {
            if (jsonResult.UserMessage.IsSuccess) {
                for (var i = 0; i < scForecastEntryGrid.grid.dataSource.data().length; i++) {
                    var dataItem = scForecastEntryGrid.grid.dataSource.data()[i];
                    if (dataItem.IsDeleted) {
                        scForecastEntryGrid.grid.dataSource.remove(dataItem);
                        break;
                    }
                }

                //scForecastEntryGrid.grid.dataSource.read();
                scForecastEntryGrid.grid.dataSource.page(scForecastEntryGrid.grid.dataSource.page());
                $("#scSummaryGrid").data("kendoGrid").dataSource.read();                
                scSummaryUI.viewModel.isModelDirty.reset();

                jsonResult.UserMessage.Message = sg.utls.formatString(jsonResult.UserMessage.Message, scForecastEntryResources.Title, jsonResult.Data.DocumentNumber);
            }
            sg.utls.showMessage(jsonResult);
        }
    },

    displayResult: function (jsonResult, mode) {
        scForecastEntryGrid.grid.dataSource.read();
    }
};
/****************************** ForecastEntry Grid - End ******************************/

// Initial Entry
$(function () {
    scSummaryUI.init();
    scSummaryUI.initBrowserBackIsDirty();
});
