/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var sc = sc || {};
sc.utls = sc.utls || {};

$.extend(sc.utls, {
    checkShowAlert: function (viewModel) {
        if (!sc.utls.showThresholdAlert(viewModel)) {
            sc.utls.showOffer(viewModel);
        }
    },

    getWarningHeader: function () {
        return '<div class="message-control multiWarn-msg" style="float: left; margin-top: -14px; margin-right: 46px; max-height: 46px; max-width: 90%;">' 
            + '<div class="title">'
            + '<span class="icon multiWarn-icon"></span>'
            + '<h3 id="dialogConfirmation_header">' + globalResource.Warning + '</h3>'
            + '</div></div>';
    },

    getInfoHeader: function () {
        return '<div class="message-control multiInfo-msg" style="float: left; margin-top: -14px; margin-right: 46px; max-height: 46px; max-width: 90%;">'
            + '<div class="title">'
            + '<span class="icon multiInfo-icon"></span>'
            + '<h3 id="dialogConfirmation_header">' + globalResource.Info + '</h3>'
            + '</div></div>';
    },

    showThresholdAlert: function (viewModel) {
        if (viewModel === null
            || viewModel.Data === null
            || viewModel.Data.UIOptions === null
            || !viewModel.Data.UIOptions.ThresholdBreached())
            return false;

        var dialogDiv = window.top.document.getElementById("scAlertDialog");
        if (dialogDiv === null) {
            dialogDiv = window.top.document.createElement("div");
            window.top.document.body.insertBefore(dialogDiv, window.top.document.body.firstChild);
            window.top.$(dialogDiv).attr("id", "scAlertDialog");
            
            //
            //// Create Window
            window.top.$(dialogDiv).kendoWindow({
                title: globalResource.Warning,
                modal: true,
                visible: false,
                resizable: false,
                close: function (e) {
                    sc.utls.showOffer(viewModel);
                    //
                    //// Destroy
                    //window.top.$(dialogDiv).data("kendoWindow").destroy();
                    //window.top.$(dialogDiv).empty();
                    //window.top.$(dialogDiv).remove();
                }
            });
            //
            ////
            $(dialogDiv).text(viewModel.ThresholdMessage());

            //
            //// Set Title
            window.top.$(dialogDiv).data("kendoWindow").wrapper.find('.k-window-titlebar').css('padding-left', '0px');
            window.top.$(dialogDiv).data("kendoWindow").wrapper.find('.k-window-title').replaceWith(sc.utls.getWarningHeader());

            //
            //// Show Window
            window.top.$(dialogDiv).data("kendoWindow").center().open();
        }

        return true;
    },

    showOffer: function (viewModel) {
        if (viewModel === null
            || viewModel.Data === null
            || viewModel.Data.UIOptions === null
            || !viewModel.Data.UIOptions.HasLoanAccess()
            || !viewModel.Data.UIOptions.HasNewLoanRecord()
            || !viewModel.Data.UIOptions.HasNewLoanRecord())
            return;

        var dialogDiv = window.top.document.getElementById("scOfferDialog");
        if (dialogDiv === null) {
            dialogDiv = window.top.document.createElement("div");
            window.top.document.body.insertBefore(dialogDiv, window.top.document.body.firstChild);
            window.top.$(dialogDiv).attr("id", "scOfferDialog");
            window.top.$(dialogDiv).css("height", "auto");
            //
            //// Offer Image
            $(dialogDiv).empty();
            var image = window.top.document.createElement("img");
            $(image).appendTo(dialogDiv);
            $(image).css("max-width", "600px");
            $(image).attr("src", "data:image/png;base64, " + viewModel.Data.UIOptions.OfferImage());
            $(image).click(function () {
                window.top.$(dialogDiv).data("kendoWindow").close();
                //
                //// Open scLoan
                //var scLoanUrl = sg.utls.url.buildUrl("SC", "Loan", "");
                //if (!sg.utls.isPortalIntegrated()) {
                //    window.open(scLoanUrl);
                //} else {
                //    window.top.postMessage(scLoanUrl, "*");
                //}
                var scLoan = window.top.$("a[data-menuId='SC1105'");
                if (scLoan)
                    scLoan.click();
            });
            //
            //// Create Window
            window.top.$(dialogDiv).kendoWindow({
                title: globalResource.Info,
                modal: true,
                visible: false,
                width: 640,
                height: 490,
                close: function (e) {
                    //
                    //// Destroy
                    //window.top.$(dialogDiv).data("kendoWindow").destroy();
                    //window.top.$(dialogDiv).empty();
                    //window.top.$(dialogDiv).remove();
                }
            });
            //
            //// Set Title
            window.top.$(dialogDiv).data("kendoWindow").wrapper.find('.k-window-titlebar').css('padding-left', '0px');
            window.top.$(dialogDiv).data("kendoWindow").wrapper.find('.k-window-title').replaceWith(sc.utls.getInfoHeader());

            //
            //// Show Window
            window.top.$(dialogDiv).data("kendoWindow").center().open();
        }
    },

    showMessage: function (result) {
        if (result.UserMessage === null)
            return;

        var messageDiv = window.top.document.createElement("div");
        window.top.document.body.insertBefore(messageDiv, window.top.document.body.firstChild);
        window.top.$(messageDiv).attr("id", "scMessage");

        var image = window.top.document.createElement("img");
        $(image).appendTo(messageDiv);
        $(image).css("max-width", "600px");
        $(image).attr("src", "data:image/png;base64, " + result.UserMessage.Info[0].ImageData);
        $(image).click(function () {
            window.top.$(messageDiv).data("kendoWindow").close();
        });
        window.top.$(messageDiv).kendoWindow({
            title: "Offer",
            modal: true,
            visible: false,
        }).data("kendoWindow").center().open();
    }
});