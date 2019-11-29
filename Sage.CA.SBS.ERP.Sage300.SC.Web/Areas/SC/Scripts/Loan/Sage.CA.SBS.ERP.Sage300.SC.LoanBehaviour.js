/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var modelData;
var scLoanUI = scLoanUI || {};

scLoanUI = {
    viewModel: {},
    ignoreIsDirtyProperties: ["ETag", "LoanNumber", "TermsAndConditions", "DateSubmitted", "UserSubmitted", "EmailSubmitted"],
    computedProperties: ["UIMode"],
    hasKoBindingApplied: false,
    isKendoControlNotInitialised: false,
    loanNumber: null,

    // Init
    init: function () {
        //
        scLoanUI.initPanels();
        scLoanUI.initButtons();
        scLoanUICallbacks.bindData(scLoanViewModel);
        //scLoanUI.initDropDownLists();
        //scLoanUI.initTextBoxes();
        scLoanUI.initDatePickers();
        $("#contactInformation").click();
        $("#statusUpdate").click();
    },

    initButtons: function () {
        $("#contactInformation").click(function () {
            $(this).siblings(".panel-content").slideToggle(400, function () {
                if (!isNewLayout) {
                    if ($(this).is(':visible')) {
                        $(this).parent().find(".panel-icon").css("background-position", "-41px -73px");
                    } else {
                        $(this).parent().find(".panel-icon").css("background-position", "-154px -130px");
                    }
                } else {
                    if ($(this).is(':visible')) {
                        $(this).parent().find(".panel-icon").addClass("panel-icon-up");
                        $(this).parent().find(".glyphicon-more").addClass("hide");
                    } else {
                        $(this).parent().find(".panel-icon").removeClass("panel-icon-up");
                        $(this).parent().find(".glyphicon-more").removeClass("hide");
                    }
                }
            });
        });
        $("#statusUpdate").click(function () {
            $(this).siblings(".panel-content").slideToggle(400, function () {
                if (!isNewLayout) {
                    if ($(this).is(':visible')) {
                        $(this).parent().find(".panel-icon").css("background-position", "-41px -73px");
                    } else {
                        $(this).parent().find(".panel-icon").css("background-position", "-154px -130px");
                    }
                } else {
                    if ($(this).is(':visible')) {
                        $(this).parent().find(".panel-icon").addClass("panel-icon-up");
                        $(this).parent().find(".glyphicon-more").addClass("hide");
                    } else {
                        $(this).parent().find(".panel-icon").removeClass("panel-icon-up");
                        $(this).parent().find(".glyphicon-more").removeClass("hide");
                    }
                }
            });
        });

        $("#btnViewTermsAndConditions").click(function () {
            var html = $(scLoanResources.TermsAndConditionsHtml).attr("id", "termsAndConditions");
            $(html).find(".msg-content").html(scLoanUI.viewModel.Data.TermsAndConditions());
            sg.utls.showMessageDialog(
                function () {
                    scLoanUI.viewModel.IsTnCViewed(true);
                },
                function () { },
                null,
                sg.utls.DialogBoxType.OKCancel,
                scLoanResources.TermsAndConditions,
                html);
            $(html).data("kendoWindow").wrapper.removeClass("k-window-titleless");
            $(html).css("margin", "0px");
            $(html).data("kendoWindow").center();
        });

        $("#btnSave").click(function () {
            if ($("#frmLoan").valid()) {
                var currentRow = scLoansGrid.grid.select()[0];
                if (currentRow) {
                    scLoansGrid.currentRowIndex = currentRow.rowIndex;
                    scLoanRepository.save(ko.mapping.toJS(scLoanUI.viewModel.Data), scLoanUICallbacks.update);
                }
            }
        });

        $("#btnResubmit").click(function () {
            sg.utls.showKendoConfirmationDialog(
                function () {
                    var currentRow = scLoansGrid.grid.select()[0];
                    if (currentRow) {
                        scLoansGrid.currentRowIndex = currentRow.rowIndex;
                        scLoanRepository.save(ko.mapping.toJS(scLoanUI.viewModel.Data), scLoanUICallbacks.update);
                    }
                },
                null,
                scLoanResources.ConfirmationResubmit,
                "YesNo",
                false,
                null);
        });

        $("#btnSubmit").click(function () {
            sg.utls.showKendoConfirmationDialog(
                function () {
                    var currentRow = scLoansGrid.grid.select()[0];
                    if (currentRow) {
                        scLoansGrid.currentRowIndex = currentRow.rowIndex;
                        scLoanRepository.submit(ko.mapping.toJS(scLoanUI.viewModel.Data), scLoanUICallbacks.update);
                    }
                },
                null,
                scLoanResources.ConfirmationSubmit,
                "YesNo",
                false,
                null);
        });

        $("#btnUpdateCancel").click(function () {
            sg.utls.showKendoConfirmationDialog(
                function () {
                    var currentRow = scLoansGrid.grid.select()[0];
                    if (currentRow) {
                        scLoansGrid.currentRowIndex = currentRow.rowIndex;
                        scLoanRepository.cancel(ko.mapping.toJS(scLoanUI.viewModel.Data), scLoanUICallbacks.update);
                    }
                },
                null,
                scLoanResources.ConfirmationCancel,
                "YesNo",
                false,
                null);
        });

        $("#btnUpdateRejected").click(function () {
            sg.utls.showKendoConfirmationDialog(
                function () {
                    var currentRow = scLoansGrid.grid.select()[0];
                    if (currentRow) {
                        scLoansGrid.currentRowIndex = currentRow.rowIndex;
                        scLoanRepository.rejected(ko.mapping.toJS(scLoanUI.viewModel.Data), scLoanUICallbacks.update);
                    }
                },
                null,
                scLoanResources.ConfirmationRejected,
                "YesNo",
                false,
                null);
        });

        $("#btnUpdateApproved").click(function () {
            sg.utls.showKendoConfirmationDialog(
                function () {
                    var currentRow = scLoansGrid.grid.select()[0];
                    if (currentRow) {
                        scLoansGrid.currentRowIndex = currentRow.rowIndex;
                        scLoanRepository.approved(ko.mapping.toJS(scLoanUI.viewModel.Data), scLoanUICallbacks.update);
                    }
                },
                null,
                scLoanResources.ConfirmationApproved,
                "YesNo",
                false,
                null);
        });
    },

    initDropDownLists: function () {
        var kendoUI = sg.utls.kndoUI;
        var fields = [
            "Status",
        ];
        $.each(fields, function (index, field) {
            kendoUI.dropDownList(field);
        });
    },

    initPanels: function () {
        $(".panel-icon").parent().siblings(".panel-content").slideDown(400, function () {
            if (!isNewLayout) {
                if ($(this).is(':visible')) {
                    $(this).parent().find(".panel-icon").css("background-position", "-41px -73px");
                } else {
                    $(this).parent().find(".panel-icon").css("background-position", "-154px -130px");
                }
            }
        });
        //$("#contactInformation").parent().siblings(".panel-content").slideToggle(400, function () {
        //    if ($(this).is(':visible')) {
        //        $(this).parent().find(".panel-icon").css("background-position", "-41px -73px");
        //    } else {
        //        $(this).parent().find(".panel-icon").css("background-position", "-154px -130px");
        //    }
        //});
        //$("#statusUpdate").parent().siblings(".panel-content").slideToggle(400, function () {
        //    if ($(this).is(':visible')) {
        //        $(this).parent().find(".panel-icon").css("background-position", "-41px -73px");
        //    } else {
        //        $(this).parent().find(".panel-icon").css("background-position", "-154px -130px");
        //    }
        //});
    },

    initNumericTextBoxes: function () {
        //var numericTextBoxes = ["Data_AmountOffer", "Data_AmountRequest"];
        //$.each(numericTextBoxes, function (index, numericTextBox) {
        //    $("#" + numericTextBox).kendoNumericTextBox();
        //});
        //var numericTextBoxes = ["Data_AmountOffer", "Data_AmountRequest"];
        //$.each(numericTextBoxes, function (index, numericTextBox) {
        //    sg.utls.kndoUI.decimalTextbox(numericTextBox, "n" + sg.utls.homeCurrency.Decimals, false, 0, null, sg.utls.homeCurrency.Decimals);
        //});
        sg.utls.kndoUI.decimalTextbox("Data_AmountOffer", "n" + sg.utls.homeCurrency.Decimals, false, 0, null, sg.utls.homeCurrency.Decimals);
        sg.utls.kndoUI.decimalTextbox("Data_AmountRequest", "n" + sg.utls.homeCurrency.Decimals, false, 0, null, sg.utls.homeCurrency.Decimals);
        $("#Data_AmountOffer").data("kendoNumericTextBox").value(scLoanUI.viewModel.Data.AmountOffer());
        $("#Data_AmountRequest").data("kendoNumericTextBox").value(scLoanUI.viewModel.Data.AmountRequest());
        //$("#Data_AmountOffer").kendoNumericTextBox({
        //    format: "n" + sg.utls.homeCurrency.Decimals,
        //    spinners: false,
        //    step: 0,
        //    min: 0,
        //    max: sg.utls.getMaxVale("13", 3, 16, true),
        //    decimals: sg.utls.homeCurrency.Decimals
        //}).data("kendoNumericTextBox").unbind("change");
        //$("#Data_AmountRequest").kendoNumericTextBox({
        //    format: "n" + sg.utls.homeCurrency.Decimals,
        //    spinners: false,
        //    step: 0,
        //    min: 0,
        //    max: sg.utls.getMaxVale("13", 3, 16, true),
        //    decimals: sg.utls.homeCurrency.Decimals
        //}).data("kendoNumericTextBox").unbind("change");
    },

    initDatePickers: function () {
        $("#Data_DateSubmitted").attr("placeholder", "");
    },

    checkUnsavedRecord: function () {
        if (globalResource.AllowPageUnloadEvent && scLoanUI.viewModel.isModelDirty.isDirty()) {
            return jQuery('<div />').html(jQuery.validator.format(globalResource.SaveConfirm2, scLoanResources.LoanTitle)).text();
        }
    },

    showScreen: function () {
        $.each(["scLoanRequestDetails", "scLoanContactInformation", "scLoanSubmissionDetails", "scLoanActivities"], function (index, panel) {
            $("#" + panel).show();
        });
    }
};

// Callbacks
var scLoanUICallbacks = {
    update: function (jsonResult) {
        if (jsonResult !== null) {
            if (jsonResult.UserMessage.IsSuccess) {
                var currentRowIndex = scLoansGrid.grid.select()[0].rowIndex; //scLoansGrid.grid.select().parent().index();

                scLoansGrid.isClientUpdating = true;

                scLoansGrid.currentRow.set("ETag", jsonResult.Data.ETag);
                scLoansGrid.currentRow.set("Status", jsonResult.Data.Status);
                scLoansGrid.currentRow.set("DateSubmitted", jsonResult.Data.DateSubmitted);
                scLoansGrid.currentRow.set("UserSubmitted", jsonResult.Data.UserSubmitted);
                scLoansGrid.currentRow.set("EmailSubmitted", jsonResult.Data.EmailSubmitted);
                scLoansGrid.currentRow.set("AmountRequest", jsonResult.Data.AmountRequest);
                scLoansGrid.currentRow.set("Contact", jsonResult.Data.Contact);
                scLoansGrid.currentRow.set("Email", jsonResult.Data.Email);
                scLoansGrid.currentRow.set("Phone", jsonResult.Data.Phone);
                scLoansGrid.currentRow.set("Mobile", jsonResult.Data.Mobile);
                scLoansGrid.currentRow.set("Message", jsonResult.Data.Message);
                scLoansGrid.currentRow.set("CompanyName", jsonResult.Data.CompanyName);
                scLoansGrid.currentRow.set("Address1", jsonResult.Data.Address1);
                scLoansGrid.currentRow.set("Address2", jsonResult.Data.Address2);
                scLoansGrid.currentRow.set("Address3", jsonResult.Data.Address3);
                scLoansGrid.currentRow.set("Address4", jsonResult.Data.Address4);
                scLoansGrid.currentRow.set("City", jsonResult.Data.City);
                scLoansGrid.currentRow.set("State", jsonResult.Data.State);
                scLoansGrid.currentRow.set("Country", jsonResult.Data.Country);
                scLoansGrid.currentRow.set("PostalCode", jsonResult.Data.PostalCode);
                scLoansGrid.currentRow.set("EmailCC", jsonResult.Data.EmailCC);

                scLoansGrid.isClientUpdating = false;
                scLoansGrid.currentRow = null;

                scLoanUI.viewModel.isModelDirty.reset();

                scLoansGrid.grid.select(scLoansGrid.grid.tbody.find("tr:eq(" + currentRowIndex + ")"));
            }
            sg.utls.showMessage(jsonResult);
        }
    },

    bindData: function (jsonResult) {
        if (jsonResult.UserMessage.IsSuccess) {
            if (!scLoanUI.hasKoBindingApplied) {
                scLoanUI.viewModel = ko.mapping.fromJS(jsonResult);
                scLoanKoExtn.scLoanModelExtension(scLoanUI.viewModel, 1);

                ko.applyBindings(scLoanUI.viewModel);
                scLoanUI.hasKoBindingApplied = true;
                scLoanUI.viewModel.isModelDirty = new ko.dirtyFlag(scLoanUI.viewModel.Data, scLoanUI.ignoreIsDirtyProperties);

                scLoanUI.initNumericTextBoxes();
                scLoanUI.showScreen();
            } else {
                ko.mapping.fromJS(jsonResult, scLoanUI.viewModel);
                scLoanUI.viewModel.isModelDirty.reset();
            }
        } else {
            sg.utls.showMessage(jsonResult);
        }
    },
};

/****************************** Loans Grid - End ******************************/
var scLoansGrid = {
    grid: null,
    currentRow: null,
    currentRowIndex: null,
    isClientUpdating: false,
    config: {
        pageSize: sg.utls.gridPageSize,
        pageable: {
            input: true,
            numeric: false
        },
        navigatable: true,
        scrollable: true,
        resizable: true,
        selectable: "row",
        sortable: false,
        isServerPaging: true,
        editable: false,
        pageUrl: sg.utls.url.buildUrl("SC", "Loan", "Get"),
        buildGridData: function (successData) {
            if (scLoansGrid.grid === null)
                scLoansGrid.grid = $("#scLoansGrid").data("kendoGrid");

            var gridData = [];
            gridData.data = successData.DataList;

            gridData.totalResultsCount = successData.TotalResultsCount;

            return gridData;
        },
        afterDataBind: function (e) {
            if (!scLoansGrid.isClientUpdating) {
                scLoansGrid.grid.select(scLoansGrid.grid.tbody.find("tr:eq(0)"));
            }
        },
        change: function (e) {
            var selectedRow = this.select();
            if (selectedRow) {
                var rowIndex = selectedRow[0].rowIndex;

                var rowData = this.dataItem(selectedRow);
                if ((rowData && scLoansGrid.currentRow === null)
                    || rowData.uid !== scLoansGrid.currentRow.uid) {
                    //
                    // Check save record
                    //
                    var msg = scLoanUI.checkUnsavedRecord();
                    if (msg) {
                        sg.utls.showKendoConfirmationDialog(
                            function () {
                                //
                                // Display new Row
                                //
                                scLoansGrid.currentRowIndex = rowIndex;
                                scLoansGrid.currentRow = rowData;
                                ko.mapping.fromJS(rowData, {}, scLoanUI.viewModel.Data);
                                scLoanUI.viewModel.isModelDirty.reset();
                                scLoanUI.viewModel.TnCAgreed(scLoanUI.viewModel.Data.Status() > 0 && scLoanUI.viewModel.Data.Status() !== 2);
                                scLoanUI.initDropDownLists();
                                scLoanUI.initNumericTextBoxes();
                            },
                            function () {
                                if (scLoansGrid.currentRowIndex !== null && scLoansGrid.currentRowIndex !== undefined) {
                                    scLoansGrid.grid.select(scLoansGrid.grid.tbody.find("tr:eq(" + scLoansGrid.currentRowIndex + ")"));
                                }
                            },
                            msg,
                            "YesNo", //sg.utls.DialogBoxType.YesNo,
                            false,
                            null);//scLoanResources.TermsAndConditionsHtml);
                    } else {
                        //
                        // Display new Row
                        //
                        scLoansGrid.currentRowIndex = rowIndex;
                        scLoansGrid.currentRow = rowData;
                        ko.mapping.fromJS(rowData, {}, scLoanUI.viewModel.Data);
                        scLoanUI.viewModel.isModelDirty.reset();
                        scLoanUI.viewModel.TnCAgreed(scLoanUI.viewModel.Data.Status() > 0 && scLoanUI.viewModel.Data.Status() !== 2);
                        scLoanUI.initDropDownLists();
                        scLoanUI.initNumericTextBoxes();
                    }
                }
            }
        },
        columns: [{
                field: "Status",
                attributes: { "class": "" },
                headerAttributes: { "class": "" },
                title: "Status",
                width: "20%",
                values: [
                    { text: scLoanResources.LoanStatusNew, value: 0 },
                    { text: scLoanResources.LoanStatusSubmitted, value: 1 },
                    { text: scLoanResources.LoanStatusCancelled, value: 2 },
                    { text: scLoanResources.LoanStatusRejected, value: 3 },
                    { text: scLoanResources.LoanStatusApproved, value: 4 },
                ]
            },
            {
                field: "LoanNumber",
                title: "Loan Number",
                attributes: { "class": "" },
                headerAttributes: { "class": "" },
                hidden: true
            },
            {
                field: "Reference",
                attributes: { "class": "" },
                headerAttributes: { "class": "" },
                title: scLoanResources.Reference,
                width: "15%",
            },
            {
                field: "DateSubmitted",
                attributes: { "class": "" },
                headerAttributes: { "class": "" },
                title: scLoanResources.DateSubmitted,
                width: "15%",
                template: sg.utls.kndoUI.getDateTemplate("DateSubmitted"),
            },
            {
                field: "AmountOffer",
                attributes: { "class": "align-right" },
                headerAttributes: { "class": "" },
                title: scLoanResources.AmountOffer,
                width: "25%",
                template: "#= sg.utls.kndoUI.getFormattedDecimalNumber(AmountOffer, sg.utls.homeCurrency.Decimals) #"
            },
            {
                field: "AmountRequest",
                attributes: { "class": "align-right" },
                headerAttributes: { "class": "" },
                title: scLoanResources.AmountRequest,
                width: "25%",
                template: "#= sg.utls.kndoUI.getFormattedDecimalNumber(AmountRequest, sg.utls.homeCurrency.Decimals) #"
            }
        ],
    }
};
/****************************** Loans Grid - End ******************************/

// Initial Entry
$(function () {
    scLoanUI.init();
    //$(window).bind('beforeunload', function () {
    //    if (globalResource.AllowPageUnloadEvent && scLoanUI.viewModel.isModelDirty.isDirty()) {
    //        return jQuery('<div />').html(jQuery.validator.format(globalResource.SaveConfirm2, scLoanResources.LoanTitle)).text();
    //    }
    //});
    $(window).bind('beforeunload', scLoanUI.checkUnsavedRecord);
});