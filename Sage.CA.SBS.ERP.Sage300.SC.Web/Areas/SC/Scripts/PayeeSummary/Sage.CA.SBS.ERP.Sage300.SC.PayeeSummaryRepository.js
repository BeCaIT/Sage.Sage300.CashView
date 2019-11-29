/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

// Ajax call to controller
var scPayeeSummaryAjax = {

    call: function (method, data, callbackMethod) {
        var url = sg.utls.url.buildUrl("SC", "Summary", method);
        sg.utls.ajaxPost(url, data, callbackMethod);
    }
};

var scPayeeSummaryRepository = {

    // Get
    get: function (id, callbackMethod) {
        var data = {};
        scPayeeSummaryAjax.call("Get", data, callbackMethod);
    },

    // Update
    update: function (data, callbackMethod) {
        scPayeeSummaryAjax.call("Save", data, callbackMethod);
    }

    // Additional methods go here
};