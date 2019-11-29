/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var modelData;
var scOptionsUI = scOptionsUI || {};

scOptionsUI = {
    hasKoBindingApplied: false,
    isKendoControlNotInitialised: false,
    optionsModel: {},
    ignoreIsDirtyProperties: ["EmailTest"],
    computedProperties: [
        "UIMode",
        "Industry", "EntityType"
    ],
    //
    init: function () {
        scOptionsUISuccess.displayResult(scOptionsViewModel);
        //
        scOptionsUI.initTabstrip();
        scOptionsUI.initTextBoxes();
        scOptionsUI.initDropDownLists();
        scOptionsUI.initButtons();
        scOptionsUI.setupForecastPeriods();
        scOptionsUI.setupDocumentNumbers();
        scOptionsUI.initNumericTextBoxes();
        scOptionsUI.initCheckBoxes();
    },

    initTabstrip: function () {
        $("#scOptionsTabStrip").kendoTabStrip({
            animation: {
                open: {
                    effects: "fadeIn"
                }
            }
        });
        sg.utls.kndoUI.selectTab("scOptionsTabStrip", "tabCompany");
    },

    initTextBoxes: function () {
        //$("#Data_LastProcessedTime").kendoTimePicker();
        $("#Data_BRN").bind("change", function () {
            sg.utls.SyncExecute(scOptionsUI.updateCalculatedFields);
        });
    },

    initDropDownLists: function () {
        var kendoUI = sg.utls.kndoUI;
        var fields = [
            "Country",
            "Industry", "IndustrySG", "IndustryMY",
            "EntityType", "EntityTypeSG", "EntityTypeMY",
            "JobTitle",
            "EmailAlert", "EmailSSL"
        ];
        $.each(fields, function (index, field) {
            kendoUI.dropDownList(field);
        });

        $("#Country").data("kendoDropDownList").bind("change", function () {
            sg.utls.SyncExecute(scOptionsUI.updateCalculatedFields);
        });
    },

    initButtons: function () {
        // Save Button
        $("#btnSave").bind('click', function () {
            sg.utls.SyncExecute(scOptionsUI.saveOptions);
        });
        // Send Test Email Button
        $("#btnSendTestEmail").bind('click', function () {
            sg.utls.SyncExecute(scOptionsUI.sendTestEmail);
        });
    },

    initNumericTextBoxes: function () {
        sg.utls.kndoUI.decimalTextbox(
            "Data_Threshold",
            "n" + sg.utls.homeCurrency.Decimals,
            false,
            sg.utls.getMinValue("9", 2, 16, true),
            sg.utls.getMaxVale("9", 2, 16, true),
            sg.utls.homeCurrency.Decimals);
        sg.utls.addMaxLength("#Data_Threshold", 17);
    },

    initCheckBoxes: function () {
        $("#scAccountsGrid .k-grid-content").on("change", "input.chkInclude", function (e) {
            var dataItem = scAccountsGrid.grid.dataItem($(e.target).closest("tr"));
            dataItem.Include = this.checked;
            dataItem.HasChanged = true;

            var account = scOptionsUI.optionsModel.Data.Accounts.Items()[$(e.target).closest("tr")[0].rowIndex];
            account.Include(this.checked);
            account.HasChanged(true);
        });
    },

    initBrowserBackIsDirty: function () {
        $(window).bind("beforeunload", function () {
            if (scOptionsUI.optionsModel.isModelDirty.isDirty())
                return;

            $("<div />").html($.validator.format(globalResource.SaveConfirm2, scOptionsResources.Title)).text();
        });
    },

    updateCalculatedFields: function () {
        var data = sg.utls.ko.toJS(modelData, scOptionsUI.computedProperties);
        scOptionsRepository.updateCalculatedFields(data, scOptionsUISuccess.updateCalculatedFields);
    },

    /****************************** Forecast Periods - Start ******************************/
    // Forecast Period Model
    forecastPeriodModel: function () {
        var self = this;
        self.from = ko.observable();
        self.to = ko.observable();
        self.SerialNumber = ko.observable();
    },
    // Forecast Period Array
    forecastPeriodsArray: [],
    // Forecast Period Model
    setupForecastPeriods: function () {
        if (scOptionsUI.optionsModel.Data === null)
            return;

        scOptionsUI.forecastPeriodsArray = [];

        for (var i = 0; i <= 6; i++) {
            var forecastPeriod = new scOptionsUI.forecastPeriodModel();

            forecastPeriod.SerialNumber = i;

            switch (i) {
                case 0:
                    forecastPeriod.from = scOptionsResources.ForecastPeriodsCurrent;
                    forecastPeriod.to = "";
                    break;
                case 1:
                    forecastPeriod.from = "1";
                    forecastPeriod.to = scOptionsUI.optionsModel.Data.Period1End();
                    break;
                case 2:
                    forecastPeriod.from = parseInt(scOptionsUI.optionsModel.Data.Period1End()) + 1;
                    forecastPeriod.to = scOptionsUI.optionsModel.Data.Period2End();
                    break;
                case 3:
                    forecastPeriod.from = parseInt(scOptionsUI.optionsModel.Data.Period2End()) + 1;
                    forecastPeriod.to = scOptionsUI.optionsModel.Data.Period3End();
                    break;
                case 4:
                    forecastPeriod.from = parseInt(scOptionsUI.optionsModel.Data.Period3End()) + 1;
                    forecastPeriod.to = scOptionsUI.optionsModel.Data.Period4End();
                    break;
                case 5:
                    forecastPeriod.from = parseInt(scOptionsUI.optionsModel.Data.Period4End()) + 1;
                    forecastPeriod.to = scOptionsUI.optionsModel.Data.Period5End();
                    break;
                case 6:
                    forecastPeriod.from = scOptionsResources.ForecastPeriodsOver;
                    forecastPeriod.to = scOptionsUI.optionsModel.Data.Period5End();
                    break;
            }

            forecastPeriod.SerialNumber = i;
            scOptionsUI.forecastPeriodsArray.push(forecastPeriod);
        }

        var grid = $("#scOptionsForecastPeriodsGrid").data("kendoGrid");
        grid.dataSource.data(scOptionsUI.forecastPeriodsArray);
    },
    /****************************** Forecast Periods - End ******************************/

    /****************************** Document Numbers - Start ******************************/
    // Document Number Model
    documentNumber: function () {
        var self = this;
        self.description = ko.observable();
        self.length = ko.observable();
        self.prefix = ko.observable();
        self.nextNumber = ko.observable();
    },
    // Document Numbers observable array
    documentNumbers: [],
    // Add new Document Number
    addDocumentNumber: function (data) {
        scOptionsUI.documentNumbers.push(data);
    },
    // Setup Document Numbers data model
    setupDocumentNumbers: function () {
        if (scOptionsUI.optionsModel.Data === null || scOptionsUI.optionsModel.Data === undefined)
            return;

        scOptionsUI.documentNumbers = [];

        var fcEntry = new scOptionsUI.documentNumber();
        fcEntry.description = scOptionsResources.DocumentNumberFE;
        fcEntry.length = scOptionsUI.optionsModel.Data.FELength();
        fcEntry.prefix = scOptionsUI.optionsModel.Data.FEPrefix();
        fcEntry.nextNumber = scOptionsUI.optionsModel.Data.FENextNumber();
        scOptionsUI.addDocumentNumber(fcEntry);

        var grid = $("#scOptionsDocumentNumbersGrid").data("kendoGrid");
        grid.dataSource.data(scOptionsUI.documentNumbers);
    },
    /****************************** Document Numbers - End ******************************/

    saveOptions: function () {
        if ($("#formSCOptions").valid()) {
            var data = sg.utls.ko.toJS(modelData, scOptionsUI.computedProperties);
            scOptionsRepository.update(data, scOptionsUISuccess.save);
        }
    },

    sendTestEmail: function () {
        var data = sg.utls.ko.toJS(modelData, scOptionsUI.computedProperties);
        scOptionsRepository.sendTestEmail(data, scOptionsUISuccess.sendTestEmail);
    },

    isEditable: function (n) {
        return !n.hasOwnProperty("isToEditable") || n.isToEditable;
    }
};

/****************************** Forecast Periods Grid - Start ******************************/
var scOptionsUIForecastPeriodsGrid = {
    grid: null,
    scOptionsUIForecastPeriodsGridConfig: {
        editable: {
            mode: "incell",
            confirmation: false
        },
        autoBind: false,
        scrollable: false,
        sortable: false,
        isServerPaging: false,
        page: 0,
        pageSize: sg.utls.gridPageSize,
        selectable: true,
        resizable: true,
        navigatable: true,
        columns: [
            {
                field: "from",
                attributes: { "class": "w120 input_Number_Right_Align" },
                headerAttributes: { "class": "w120 k-header align-left" },
                title: scOptionsResources.ForecastPeriodsFrom,
                width: "50%",
                editor: function (container, options) {
                    //making from column to non editable column
                    var grid = $("#scOptionsForecastPeriodsGrid").data("kendoGrid");
                    //grid.select(container.closest("tr"));
                    sg.utls.kndoUI.nonEditable(grid, container);
                }
            }, {
                field: "to",
                attributes: { "class": "w100 input_Number_Right_Align" },
                headerAttributes: { "class": "w100 k-header align-left" },
                title: scOptionsResources.ForecastPeriodsTo,
                width: "50%",
                editor: function (container, options) {
                    var rowIndex = container.parent()[0].rowIndex;
                    if (rowIndex > 1 && rowIndex < 7) {
                        var input = $('<input name="' + options.field + '" id="' + options.field + '" data-bind="value:' + options.field + '" class="align-right"/>');
                        $(input).appendTo(container).kendoNumericTextBox({
                            format: "n0",
                            spinners: !1,
                            min: 0, //-99999,
                            max: 99999,
                            decimals: 0
                        });
                    } else
                        sg.utls.kndoUI.nonEditable($("#scOptionsForecastPeriodsGrid").data("kendoGrid"), container);
                }
            }, {
                field: "SerialNumber",
                title: "SerialNumber",
                hidden: true
            }
        ],
        //
        //// Events
        dataBound: function () {
            scOptionsUIForecastPeriodsGrid.grid = $("#scOptionsForecastPeriodsGrid").data("kendoGrid");
        },
        dataChange: function (data) {
            if (data.rowData.SerialNumber > 0 && data.rowData.SerialNumber < 6) {
                if (data.rowData.SerialNumber > 0 && data.rowData.SerialNumber < 5) {
                    $("#scOptionsForecastPeriodsGrid").data("kendoGrid").dataSource.data()[data.rowData.SerialNumber + 1].from = data.rowData.to + 1;
                }
                else if (data.rowData.SerialNumber === 5) {
                    $("#scOptionsForecastPeriodsGrid").data("kendoGrid").dataSource.data()[data.rowData.SerialNumber + 1].to = data.rowData.to;
                }
                var propName = "Period" + data.rowData.SerialNumber + "End";
                scOptionsUI.optionsModel.Data[propName](data.rowData.to);
            }
        }
    }
};
/****************************** Forecast Periods Grid - End ******************************/

/****************************** Document Numbers Grid - Start ******************************/
var scOptionsUIDocumentNumbersGrid = {
    scOptionsUIDocumentNumbersGridConfig: {
        editable: {
            mode: "incell",
            confirmation: true
        },
        autoBind: false,
        scrollable: false,
        sortable: false,
        isServerPaging: false,
        page: 0,
        pageSize: sg.utls.gridPageSize,
        selectable: true,
        resizable: true,
        navigatable: true,
        columns: [
            {
                field: "description",
                attributes: { "class": "w10" },
                headerAttributes: { "class": "w10 k-header" },
                title: scOptionsResources.DocumentNumberType,
                width: "25%",
                editor: function (container, options) {
                    sg.utls.kndoUI.nonEditable($("#scOptionsDocumentNumbersGrid").data("kendoGrid"), container);
                }
            },
            {
                field: "length",
                attributes: { "class": "w20 input_Number_Right_Align" },
                headerAttributes: { "class": "w30 k-header align-left" },
                title: scOptionsResources.DocumentNumberLength,
                width: "25%",
                //template: '#= numberingDocumentUIGrid.getLength(length) #',
                editor: function (container, options) {
                    var input = $('<input name="' + options.field + '" id="' + options.field + '" data-bind="value:' + options.field + '" class="align-right"/>');
                    $(input).appendTo(container).kendoNumericTextBox({
                        format: "n0",
                        spinners: !1,
                        min: 0, //-99999,
                        max: 22,
                        decimals: 0
                    });
                }
            },
            {
                field: "prefix",
                attributes: { "class": "w30 grid_Cell_Number_Left_Align txt-upper" },
                headerAttributes: { "class": "w10 k-header" },
                title: scOptionsResources.DocumentNumberPrefix,
                width: "25%",
                editor: function (container, options) {
                    var input = $('<input name="' + options.field + '" id="' + options.field + '" data-bind="value:' + options.field + '" class="align-left"/>');
                    sg.utls.addMaxLength(input, 6);
                    $(input).appendTo(container);
                }
            },
            {
                field: "nextNumber",
                attributes: { "class": "w45 input_Number_Right_Align" },
                headerAttributes: { "class": "w30 k-header align-left" },
                title: scOptionsResources.DocumentNumberNextNumber,
                width: "25%",
                editor: function (container, options) {
                    var input = $('<input name="' + options.field + '" id="' + options.field + '" data-bind="value:' + options.field + '" class="align-right"/>');
                    var maxLength = scOptionsUI.optionsModel.Data.FELength() - scOptionsUI.optionsModel.Data.FEPrefix().length;
                    $(input).appendTo(container).kendoNumericTextBox({
                        format: "n0",
                        spinners: !1,
                        min: 0, //-99999,
                        max: sg.utls.getMaxVale("9", 0, maxLength, true),
                        decimals: 0
                    });
                    sg.utls.addMaxLength(input, maxLength);
                }
            }
        ],
        //
        //// Events
        dataChange: function (data) {
            switch (data.columnName) {
                case "length":
                    scOptionsUI.optionsModel.Data.FELength(data.cellData);
                    break;
                case "prefix":
                    scOptionsUI.optionsModel.Data.FEPrefix(data.cellData);
                    break;
                case "nextNumber":
                    scOptionsUI.optionsModel.Data.FENextNumber(data.cellData);
                    break;
            }
        }
    }
};
/****************************** Document Numbers Grid - End ******************************/

/****************************** Accounts Grid - Start ******************************/
var scAccountsGrid = {
    grid: null,
    data: ko.observableArray(),
    saveRecord: function (data) {
        scAccountRepository.update(data, scAccountAjax.update);
    },
    config: {
        pageSize: sg.utls.gridPageSize,
        pageable: {
            input: true,
            numeric: false,
            refresh: false,
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
            //createAt: "top"
        },
        pageUrl: sg.utls.url.buildUrl("SC", "Options", "GetAccounts"),
        buildGridData: function (successData) {
            if (scAccountsGrid.grid === null)
                scAccountsGrid.grid = $("#scAccountsGrid").data("kendoGrid");

            var gridData = [];
            gridData.data = successData.Items;

            var isDirty = scOptionsUI.optionsModel.isModelDirty.isDirty();

            ko.mapping.fromJS(successData.Items, {}, scOptionsUI.optionsModel.Data.Accounts.Items);
            scOptionsUI.optionsModel.Data.Accounts.Items.TotalResultsCount = successData.TotalResultsCount;
            //successData.TotalResultsCount = successData.TotalResultsCount;
            if (!isDirty)
                scOptionsUI.optionsModel.isModelDirty.reset();

            //var grid = $("#scForecastEntriesGrid").data("kendoGrid");
            //var pageNumber = grid.dataSource.page();
            //if (successData.TotalResultsCount === 0) {
            //    pageNumber = 0;
            //}
            gridData.totalResultsCount = successData.TotalResultsCount;
            //scLoanUICallbacks.bindData(successData);

            //scAccountsGrid.config.param = {
            //    model: scOptionsUI.optionsModel.Data,
            //    pageNumber: 1, //scAccountsGrid.grid.dataSource.page(),
            //    pageSize: 10, //scAccountsGrid.grid.dataSource.pageSize(),
            //};

            return gridData;
        },
        getParam: function () {
            var grid = $("#scAccountsGrid").data("kendoGrid");
            return {
                model: ko.mapping.toJS(scOptionsUI.optionsModel.Data),
                pageNumber: grid.dataSource.page() - 1,
                pageSize: grid.dataSource.pageSize(),
            };
        },
        columns: [
            {
                field: "Include",
                attributes: { "class": "align-center" },
                //headerAttributes: {},
                title: scOptionsResources.Include,
                width: "20%",
                template: '<span class="icon checkBox #= Include ? "selected" : "" #"><input type="checkbox" value="#= Include #" #= Include ? "checked=checked" : "" # class="chkInclude" /></span>'
            },
            {
                field: "AccountNumberFormatted",
                //attributes: {},
                //headerAttributes: {},
                title: scOptionsResources.AccountNumber,
                width: "30%",
                editor: function (container, options) {
                    //making from column to non editable column
                    //scAccountsGrid.grid.select(container.closest("tr"));
                    sg.utls.kndoUI.nonEditable(scAccountsGrid.grid, container);
                }
            },
            {
                field: "AccountDescription",
                //attributes: {},
                //headerAttributes: {},
                title: scOptionsResources.AccountDescription,
                width: "50%",
                editor: function (container, options) {
                    //making from column to non editable column
                    //scAccountsGrid.grid.select(container.closest("tr"));
                    sg.utls.kndoUI.nonEditable(scAccountsGrid.grid, container);
                }
            }
        ],
        //
        //// Events
        dataChange: function (data) {
            //if (data.columnName === "Include") {
            //    sg.utls.SyncExecute(scAccountsGrid.saveRecord(data.rowData));
            //}
        }
    }
};
/****************************** Accounts Grid - End ******************************/

// Callbacks
var scOptionsUISuccess = {

    get: function (jsonResult) {
        if (jsonResult === null) return;

        if (jsonResult.UserMessage.IsSuccess) {
            scOptionsUISuccess.displayResult(jsonResult, sg.utls.OperationMode.LOAD);
        }
    },

    save: function (jsonResult) {
        if (jsonResult.UserMessage.IsSuccess) {
            scOptionsUISuccess.displayResult(jsonResult, sg.utls.OperationMode.SAVE);
            scAccountsGrid.grid.dataSource.read();
        }
        sg.utls.showMessage(jsonResult);
    },

    sendTestEmail: function (jsonResult) {
        sg.utls.showMessage(jsonResult);
    },

    updateCalculatedFields: function (jsonResult) {
        scOptionsUISuccess.displayResult(jsonResult);
        scOptionsUI.optionsModel.Data.ETag(jsonResult.Data.ETag);
        scAccountsGrid.grid.dataSource.read();
    },

    displayResult: function (jsonResult, uiMode) {
        if (jsonResult !== null) {
            if (!scOptionsUI.hasKoBindingApplied) {
                scOptionsUI.optionsModel = ko.mapping.fromJS(jsonResult);
                modelData = scOptionsUI.optionsModel.Data;
                scOptionsKoExtn.scOptionsModelExtension(scOptionsUI.optionsModel, uiMode);
                ko.applyBindings(scOptionsUI.optionsModel);
                scOptionsUI.hasKoBindingApplied = true;

                scOptionsUI.optionsModel.isModelDirty = new ko.dirtyFlag(modelData, scOptionsUI.ignoreIsDirtyProperties);

                $("#scOptionsTabStrip").show();
            } else {
                ko.mapping.fromJS(jsonResult, scOptionsUI.optionsModel);
                //modelData.UIMode(uiMode);
                if (uiMode !== undefined && uiMode !== null)
                    scOptionsUI.optionsModel.isModelDirty.reset();
            }

            if (!scOptionsUI.isKendoControlNotInitialised) {
                scOptionsUI.isKendoControlNotInitialised = true;
            }
        }
    }
};

var scAccountCallbacks = {
    update: function (jsonResult) {
        if (jsonResult) {
            if (jsonResult.UserMessage) {
                if (jsonResult.UserMessage.IsSuccess) {
                    for (var i = 0; i < scAccountsGrid.grid.dataSource.data().length; i++) {
                        var dataItem = scAccountsGrid.grid.dataSource.data()[i];
                        //if (dataItem.HasChanged) {
                        if (dataItem.AccountNumber === jsonResult.Data.AccountNumber) {
                            dataItem.set("ETag", jsonResult.Data.ETag);
                            dataItem.set("Include", jsonResult.Data.Include);
                            dataItem.set("HasChanged", false);

                            //scAccountsGrid.currentRecord = null;
                            //scAccountsGrid.grid.select(scForecastEntryGrid.grid.tbody.find("tr:eq(" + i + ")"));
                            //scAccountsGrid.grid.tbody.find("tr:eq(" + i + ") td:eq(0)").click();
                            //scAccountsGrid.grid.closeCell();
                            break;
                        }
                    }
                }
                sg.utls.showMessage(jsonResult);
            }
        }
    },
};

// Initial Entry
$(function () {
    scOptionsUI.init();
    $(window).bind('beforeunload', function () {
        if (globalResource.AllowPageUnloadEvent && scOptionsUI.optionsModel.isModelDirty.isDirty()) {
            return jQuery('<div />').html(jQuery.validator.format(globalResource.SaveConfirm2, scOptionsResources.Title)).text();
        }
    });
});
