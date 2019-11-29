/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

// Ajax call to controller
var scLoanAjax = {

    call: function (method, data, callbackMethod) {
        var url = sg.utls.url.buildUrl("SC", "Loan", method);
        sg.utls.ajaxPost(url, data, callbackMethod);
    }
};

var scLoanRepository = {
    save: function (data, callbackMethod) {
        scLoanAjax.call("Save", data, callbackMethod);
    },

    submit: function (data, callbackMethod) {
        scLoanAjax.call("Submit", data, callbackMethod);
    },

    cancel: function (data, callbackMethod) {
        scLoanAjax.call("Cancel", data, callbackMethod);
    },

    rejected: function (data, callbackMethod) {
        scLoanAjax.call("Rejected", data, callbackMethod);
    },

    approved: function (data, callbackMethod) {
        scLoanAjax.call("Approved", data, callbackMethod);
    },
};