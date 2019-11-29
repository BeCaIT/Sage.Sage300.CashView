/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var modelData;
var scDashboardUI = scDashboardUI || {};

scDashboardUI = {
    hasKoBindingApplied: false,
    isKendoControlNotInitialised: false,
    viewModel: {},
    ignoreIsDirtyProperties: [],
    chartData: [],
    computedProperties: [
        "UIMode",
    ],
    //
    init: function () {
        if (scDashboardUISuccess.ensureOptions(scDashboardViewModel)) {
            //
            scDashboardUISuccess.displayResult(scDashboardViewModel);
            //
            scDashboardUI.initButtons();
            scDashboardUI.initGauges();
            scDashboardUI.initChart();
            //
            sc.utls.checkShowAlert(scDashboardUI.viewModel);
        }
    },

    initGauges: function () {
        var gaugeAreaDefault = {
            margin: 0,
            width: 100,
            height: 100
        };

        var isIE = function () {
            return window.navigator.userAgent.indexOf("MSIE") > 0 || !!navigator.userAgent.match(/Trident.*rv\:11\./);
        };

        var getRanges = function (maxValue, medValue, value) {
            return [{
                from: 0,
                to: maxValue
            }, {
                from: 0,
                to: maxValue,
                color: isIE() ? "#37b400" : "url(#linear)"
            }, {
                from: value < 0 ? 0 : value > maxValue ? maxValue : value,
                to: maxValue,
                color: "#e6e6e6"
            }];

            //return [{
            //    from: 0,
            //    to: maxValue,
            //    color: "#e6e6e6"
            //}];

            //if (value <= medValue) {
            //    return [{
            //        from: 0,
            //        to: value,
            //        color: "#37b400"
            //    }, {
            //        from: value,
            //        to: maxValue
            //    }];
            //} else {
            //    return [{
            //        from: 0,
            //        to: value,
            //        color: "red"
            //    }, {
            //        from: value,
            //        to: maxValue
            //    }];
            //}
        };

        var defaultScale = function (maxValue, medValue, value) {
            return {
                startAngle: -30,
                endAngle: 210,
                min: 0,
                max: maxValue,
                labels: { position: "inside" },
                majorTicks: { visible: true },
                minorTicks: { visible: false },
                majorUnit: maxValue,
                ranges: [{
                    from: 0,
                    to: maxValue
                }, {
                    from: 0,
                    to: maxValue,
                    color: "url(#linear)"
                }, {
                    from: value < 0 ? 0 : value > maxValue ? maxValue : value,
                    to: maxValue,
                    color: "#e6e6e6"
                }],
                rangeSize: 13,
                rangeDistance: -10
            };
        };
        var addLinearRange = function (id, maxValue, medValue) {
            if (!isIE()) {
                //
                //// Add linear            
                var defs = $("#" + id + " svg defs").html('<linearGradient id="linear" x1="0%" y1="0%" x2="100%" y2="0%">'
                    + '<stop offset="0%" stop-color="#37b400"></stop>'
                    + '<stop offset="' + (medValue * 100 / maxValue) + '%" stop-color="yellow"></stop>'
                    + '<stop offset="100%" stop-color="red"></stop>'
                    + '</linearGradient>');
            }
        };

        var setLabelColor = function (id, medValue, value) {
            if (value <= medValue) {
                $("#" + id).siblings("label").css("color", "#37b400");
            } else {
                $("#" + id).siblings("label").css("color", "red");
            }
        };

        //
        //// DSO
        $("#gaugeDSO").kendoRadialGauge({
            theme: "metro",
            gaugeArea: gaugeAreaDefault,
            pointer: {
                value: scDashboardUI.viewModel.Data.DSO()
            },
            scale: defaultScale(scDashboardUI.viewModel.Data.DSOMaximum(), scDashboardUI.viewModel.Data.DSOMedian(), scDashboardUI.viewModel.Data.DSO())
        });
        addLinearRange("gaugeDSO", scDashboardUI.viewModel.Data.DSOMaximum(), scDashboardUI.viewModel.Data.DSOMedian());
        setLabelColor("gaugeDSO", scDashboardUI.viewModel.Data.DSOMedian(), scDashboardUI.viewModel.Data.DSO());
        //
        //// ARC
        $("#gaugeARC").kendoRadialGauge({
            theme: "metro",
            gaugeArea: gaugeAreaDefault,
            pointer: {
                color: "white"
            },
            scale: {
                startAngle: 90,
                endAngle: 450,
                min: 0,
                max: 100,
                labels: { visible: false },
                majorTicks: { visible: false },
                minorTicks: { visible: false },
                ranges: [{
                    from: 0,
                    to: scDashboardUI.viewModel.Data.ARC() * 100 < 0 ? 0 : scDashboardUI.viewModel.Data.ARC() * 100 > 100 ? 100 : scDashboardUI.viewModel.Data.ARC() * 100,
                    //to: 80,
                    color: "#37b400"
                }],
                rangeSize: 13,
                rangeDistance: -10,
            }
        });
        //
        //// DPO
        $("#gaugeDPO").kendoRadialGauge({
            theme: "metro",
            gaugeArea: gaugeAreaDefault,
            pointer: {
                value: scDashboardUI.viewModel.Data.DPO()
            },
            scale: defaultScale(scDashboardUI.viewModel.Data.DPOMaximum(), scDashboardUI.viewModel.Data.DPOMedian(), scDashboardUI.viewModel.Data.DPO())
        });
        addLinearRange("gaugeDPO", scDashboardUI.viewModel.Data.DPOMaximum(), scDashboardUI.viewModel.Data.DPOMedian());
        setLabelColor("gaugeDPO", scDashboardUI.viewModel.Data.DPOMedian(), scDashboardUI.viewModel.Data.DPO());
        //
        //// CCC
        $("#gaugeCCC").kendoRadialGauge({
            theme: "metro",
            gaugeArea: gaugeAreaDefault,
            pointer: {
                value: scDashboardUI.viewModel.Data.CCC()
            },
            scale: defaultScale(scDashboardUI.viewModel.Data.CCCMaximum(), scDashboardUI.viewModel.Data.CCCMedian(), scDashboardUI.viewModel.Data.CCC())
        });
        addLinearRange("gaugeCCC", scDashboardUI.viewModel.Data.CCCMaximum(), scDashboardUI.viewModel.Data.CCCMedian());
        setLabelColor("gaugeCCC", scDashboardUI.viewModel.Data.CCCMedian(), scDashboardUI.viewModel.Data.CCC());
    },

    buildChartData: function () {
        scDashboardUI.chartData = [];
        for (var i = 0; i <= 6; i++) {
            scDashboardUI.chartData.push({
                "Category": scDashboardUI.viewModel.Data.CashFlowChartNetIn()[i].Category(),
                "CashIn": scDashboardUI.viewModel.Data.CashFlowChartNetIn()[i].Value(),                
                "CashOut": scDashboardUI.viewModel.Data.CashFlowChartNetOut()[i].Value(),
                "EndingBalance": scDashboardUI.viewModel.Data.CashFlowChartEndingBalance()[i].Value()
            });
        }
    },

    initChart: function () {
        scDashboardUI.buildChartData();

        //$("#chartCashFlow").kendoChart(scDashboardUIChart.config);
        $("#chartCashFlow").kendoChart({
            theme: "metro",
            dataSource: scDashboardUI.chartData,
            legend: {
                position: "bottom"
            },
            seriesDefaults: {
                field: "Value",
                categoryField: "Category",
                type: "column"
            },
            series: [
                {
                    name: scDashboardResources.CashIn,
                    field: "CashIn",
                },
                {
                    name: scDashboardResources.CashOut,
                    field: "CashOut",
                },
                {
                    name: scDashboardResources.CashEndingBalance,
                    type: "line",
                    field: "EndingBalance",
                }
            ],
            categoryAxis: {
                field: "Category",
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
                }
            },
            tooltip: {
                visible: true,
                format: "{0}%",
                template: "#= series.name #: #= sg.utls.kndoUI.getFormattedDecimalNumber(value, sg.utls.homeCurrency.Decimals) #"
            }
        });

        $(window).resize(function () {
            $("#chartCashFlow").data("kendoChart").refresh();
        });
    },

    initButtons: function () {
        // Save Button
        $("#btnPrint").bind('click', function () {
            sg.utls.SyncExecute(scReportsUtil.printReport("SCSUM01"));
        });
    },

    printDashboardReport: function () {
        $("#success").empty();
        $("#message").empty();
        scDashboardRepository.printDashboardReport(scDashboardUISuccess.printDashboardReport);
    },

    showOffer: function (result) {
        if (result.UserMessage !== null) {
            var offerWindow = window.top.document.createElement("div");
            $(window.top.document.body).append(offerWindow);
            //var messageDiv = $("#message", window.parent.document);
            var messageDiv = $(offerWindow);
            var css = "message-control";
            var messageHTML = "";
            var isSuccessMessage = false;

            $("#success").stop(true, true).hide();

            $("#success").empty();
            //$("#message").empty();
            messageDiv.empty();

            //Info
            if (result.UserMessage.Info != null && result.UserMessage.Info.length > 0) {
                //messageDiv.show();
                var defaultErrorMsg = null;
                isSuccessMessage = result.UserMessage.IsSuccess;
                if (!result.UserMessage.IsSuccess) {
                    defaultErrorMsg = result.UserMessage.Message;
                }
                css = css + " message-control multiInfo-msg";
                var warnHTML = sg.utls.generateList(result.UserMessage.Info, defaultErrorMsg);
                if (isSuccessMessage) {
                    $("#success").show();
                    messageDiv = $("#success");
                    messageHTML = sg.utls.isSuccessMessage(warnHTML);
                } else {
                    //messageDiv.show();
                    //messageHTML = "<div class='" + css + "'><div class='top'></div><div class='title'><span class='icon success-icon'></span><h3>" + warnHTML + "</h3><span class='icon msgCtrl-close'>Close</span></div><div class='msg-content'> </div></div><div class='msg-overlay'></div>";
                    messageHTML = "<div class='" + css + "'>     <div class='title'><span class='icon multiInfo-icon'></span><h3>" + globalResource.Info + "</h3><span class='icon msgCtrl-close'>Close</span></div><div class='msg-content'>" + warnHTML + "</div></div>";
                    //messageHTML = "<div class='" + errorCSS + "'><div class='title'><span class='icon multiError-icon'></span><h3>" + warnHTML + "</h3><span class='icon msgCtrl-close'>Close</span></div><div class='msg-content'> " + errorHTML + " </div></div>";
                }
                messageDiv.html(messageHTML);
                messageDiv.kendoWindow({
                    title: false,
                    modal: true
                    //content: messageHTML
                }).data("kendoWindow").center().open();
            }
        }
    }
};

/****************************** Gauges - Start ******************************/
var scDashboardUIGauges = {
    //
    //// DSO
    gaugeDSOConfig: {

    },
    //
    //// DPO
    gaugeDPOConfig: {

    },
    //
    //// CCC
    gaugeCCCConfig: {

    },
    //
    //// ARC
    gaugeARCConfig: {

    }
};
/****************************** Gauges - End ******************************/

/****************************** Dashboard Chart - Start ******************************/
var scDashboardUIChart = {
};
/****************************** Dashboard Chart - End ******************************/

// Callbacks
var scDashboardUISuccess = {

    get: function (jsonResult) {
        if (jsonResult === null) return;

        if (jsonResult.UserMessage.IsSuccess) {
            scDashboardUISuccess.displayResult(jsonResult, sg.utls.OperationMode.LOAD);
        }
    },

    save: function (jsonResult) {
        if (jsonResult.UserMessage.IsSuccess) {
            scDashboardUISuccess.displayResult(jsonResult, sg.utls.OperationMode.SAVE);
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
            if (!scDashboardUI.hasKoBindingApplied) {
                scDashboardUI.viewModel = ko.mapping.fromJS(jsonResult);
                modelData = scDashboardUI.viewModel.Data;
                scDashboardKoExtn.modelExtension(scDashboardUI.viewModel, uiMode);
                scDashboardUI.viewModel.isModelDirty = new ko.dirtyFlag(modelData, scDashboardUI.ignoreIsDirtyProperties);

                ko.applyBindings(scDashboardUI.viewModel);
                scDashboardUI.hasKoBindingApplied = true;
            } else {
                ko.mapping.fromJS(jsonResult, scDashboardUI.viewModel);
                scDashboardUI.viewModel.isModelDirty.reset();
            }

            if (!scDashboardUI.isKendoControlNotInitialised) {
                scDashboardUI.isKendoControlNotInitialised = true;
            }
        }
    },
};

// Initial Entry
$(function () {
    scDashboardUI.init();
});