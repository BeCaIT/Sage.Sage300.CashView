/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

// Ajax call to controller
var scDashboardAjax = {
    call: function (method, data, callbackMethod) {
        var url = sg.utls.url.buildUrl("SC", "Dashboard", method);
        sg.utls.ajaxPost(url, data, callbackMethod);
    }
};

var scDashboardRepository = {

    // Get
    get: function (id, callbackMethod) {
        var data = {};
        scDashboardAjax.call("Get", data, callbackMethod);
    },

    // Update
    update: function (data, callbackMethod) {
        scDashboardAjax.call("Save", data, callbackMethod);
    },

    getThresholdAlert: function (callbackMethod) {
        scDashboardAjax.call("GetThresholdAlert", null, callbackMethod);
    },
};