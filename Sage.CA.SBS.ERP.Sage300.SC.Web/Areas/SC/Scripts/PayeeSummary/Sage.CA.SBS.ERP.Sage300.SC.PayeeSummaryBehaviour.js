/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var modelData;
var scPayeeSummaryUI = scPayeeSummaryUI || {};

scPayeeSummaryUI = {
    hasKoBindingApplied: false,
    isKendoControlNotInitialised: false,
    viewModel: {},
    ignoreIsDirtyProperties: [],
    computedProperties: [
        "UIMode",
    ],
    //
    init: function () {
        if (scPayeeSummaryUISuccess.ensureOptions(scPayeeSummaryViewModel)) {
            scPayeeSummaryUISuccess.displayResult(scPayeeSummaryViewModel);
            //
            scPayeeSummaryUI.initButtons();
            //
            scPayeeSummaryUI.initGrid();
            scPayeeSummaryUI.initChart();
            //
            sc.utls.checkShowAlert(scPayeeSummaryUI.viewModel);
        }
    },

    initGrid: function () {
        var grid = $("#scPayeeSummaryGrid").data("kendoGrid");
        var rows = grid.tbody.children();
        for (var i = 0; i < rows.length; i++) {
            var row = $(rows[i]);
            row.removeClass("k-state-selected");
        }
    },

    initChart: function () {
        $("#chart").kendoChart({
            theme: "metro",
            dataSource: {
                data: ko.toJS(scPayeeSummaryUI.viewModel.DataList),
                schema: {
                    model: {
                        fields: {
                            PayeeNumber: { type: "text" },
                            OutstandingBalance: { type: "number" }
                        }
                    }
                }
            },
            legend: {
                position: "bottom"
            },
            series: [
                {
                    type: "bar",
                    field: "OutstandingBalance",
                    format: "{0:n" + sg.utls.homeCurrency.Decimals + "}"
                }
            ],
            categoryAxis: {
                field: "PayeeNumber",
                majorGridLines: {
                    visible: false
                }
            },
            valueAxis: {
                labels: {
                    format: "{0:n" + sg.utls.homeCurrency.Decimals + "}"
                },
                majorGridLines: {
                    visible: false
                },
            },
            tooltip: {
                visible: true,
                format: "{0}%",
                template: "#= category #: #= sg.utls.kndoUI.getFormattedDecimalNumber(value, sg.utls.homeCurrency.Decimals) #"
            }
        });
        $(window).resize(function () {
            $("#chart").data("kendoChart").refresh();
        });
    },

    initButtons: function () {
        // Print Top 10 Customers
        $("#btnTop10Customers").bind('click', function () {
            sg.utls.SyncExecute(scReportsUtil.printReport("SCARTOP"));
        });
        // Print Receivables Forecast
        $("#btnARForecast").bind('click', function () {
            sg.utls.SyncExecute(scReportsUtil.printReport("SCARAGED"));
        });
        // Print Top 10 Vendors
        $("#btnTop10Vendors").bind('click', function () {
            sg.utls.SyncExecute(scReportsUtil.printReport("SCAPTOP"));
        });
        // Print Payables Forecast
        $("#btnAPForecast").bind('click', function () {
            sg.utls.SyncExecute(scReportsUtil.printReport("SCAPCASH"));
        });
    },

    initBrowserBackIsDirty: function () {
        $(window).bind("beforeunload", function () {
            if (scPayeeSummaryUI.viewModel.isModelDirty.isDirty())
                return;

            $("<div />").html($.validator.format(globalResource.SaveConfirm2, scPayeeSummaryResources.Title)).text();
        });
    },
};

/****************************** Summary Grid - Start ******************************/
var scPayeeSummaryUIGrid = {
    scPayeeSummaryUIGridConfig: {
        editable: false,
        //autoBind: false,
        scrollable: false,
        sortable: false,
        //isServerPaging: false,
        //page: 0,
        pageSize: 11, //sg.utls.gridPageSize,
        selectable: false,
        persistSelection: false,
        resizable: true,
        navigatable: true,
        columns: [
            {
                field: "Ranking",
                attributes: { "class": "w120" },
                headerAttributes: { "class": "w120 k-header align-center" },
                title: scPayeeSummaryResources.Ranking,
                width: "10%",
            },
            {
                field: "PayeeNumber",
                //attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                //format: scPayeeSummaryResources.FormatString,
                title: scPayeeSummaryResources.Payee,
                width: "20%",
            },
            {
                field: "Name",
                //attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                //format: scPayeeSummaryResources.FormatString,
                title: scPayeeSummaryResources.Name,
                width: "30%",
            },
            {
                field: "CreditLimitString",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                //format: scPayeeSummaryResources.FormatString,
                title: scPayeeSummaryResources.CreditLimit,
                width: "15%",
            },
            {
                field: "HighestBalance",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                //format: "{0:n" + sg.utls.homeCurrency.Decimals + "}",
                template: "#= HighestBalance == 0 ? '' : sg.utls.kndoUI.getFormattedDecimalNumber(HighestBalance, sg.utls.homeCurrency.Decimals) #",
                title: scPayeeSummaryResources.HighestBalance,
                width: "15%",
            },
            {
                field: "OutstandingBalance",
                attributes: { "class": "w80 input_Number_Right_Align" },
                headerAttributes: { "class": "w80 k-header align-center" },
                //format: "{0:n" + sg.utls.homeCurrency.Decimals + "}",
                template: "#= sg.utls.kndoUI.getFormattedDecimalNumber(OutstandingBalance, sg.utls.homeCurrency.Decimals) #",
                title: scPayeeSummaryResources.OutstandingBalance,
                width: "15%",
            }
        ]
    }
};
/****************************** Summary Grid - End ******************************/

// Callbacks
var scPayeeSummaryUISuccess = {

    get: function (jsonResult) {
        if (jsonResult === null) return;

        if (jsonResult.UserMessage.IsSuccess) {
            scPayeeSummaryUISuccess.displayResult(jsonResult, sg.utls.OperationMode.LOAD);
        }
    },

    save: function (jsonResult) {
        if (jsonResult.UserMessage.IsSuccess) {
            scPayeeSummaryUISuccess.displayResult(jsonResult, sg.utls.OperationMode.SAVE);
        }
        sg.utls.showMessage(jsonResult);
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
            if (!scPayeeSummaryUI.hasKoBindingApplied) {
                scPayeeSummaryUI.viewModel = ko.mapping.fromJS(jsonResult);
                modelData = scPayeeSummaryUI.viewModel.Data;
                scPayeeSummaryKoExtn.modelExtension(scPayeeSummaryUI.viewModel, uiMode);
                scPayeeSummaryUI.viewModel.isModelDirty = new ko.dirtyFlag(modelData, scPayeeSummaryUI.ignoreIsDirtyProperties);

                ko.applyBindings(scPayeeSummaryUI.viewModel);
                scPayeeSummaryUI.hasKoBindingApplied = true;
            } else {
                ko.mapping.fromJS(jsonResult, scPayeeSummaryUI.viewModel);
                scPayeeSummaryUI.viewModel.isModelDirty.reset();
            }

            if (!scPayeeSummaryUI.isKendoControlNotInitialised) {
                scPayeeSummaryUI.isKendoControlNotInitialised = true;
            }
        }
    }
};

var scPayeeSummaryUIFilter = {

};


// Initial Entry
$(function () {
    scPayeeSummaryUI.init();
});