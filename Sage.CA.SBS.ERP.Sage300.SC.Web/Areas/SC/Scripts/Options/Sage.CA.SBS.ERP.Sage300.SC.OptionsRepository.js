/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

// Ajax call to controller
var scOptionsAjax = {

    call: function (method, data, callbackMethod) {
        var url = sg.utls.url.buildUrl("SC", "Options", method);
        sg.utls.ajaxPost(url, data, callbackMethod);
    }
};

var scOptionsRepository = {

    // Get
    get: function (id, callbackMethod) {
        var data = {};
        scOptionsAjax.call("Get", data, callbackMethod);
    },

    // Update
    update: function (data, callbackMethod) {
        scOptionsAjax.call("Save", data, callbackMethod);
    },

    // Additional methods go here
    sendTestEmail: function (data, callbackMethod) {
        scOptionsAjax.call("SendTestEmail", data, callbackMethod);
    },

    // Update Calculated Fields
    updateCalculatedFields: function (data, callbackMethod) {
        scOptionsAjax.call("UpdateCalculatedFields", data, callbackMethod);
    }
};


var scAccountAjax = {
    call: function (method, data, callbackMethod) {
        var url = sg.utls.url.buildUrl("SC", "Options", method);
        sg.utls.ajaxPost(url, data, callbackMethod);
    }
};

var scAccountRepository = {
    update: function (data, callbackMethod) {
        scAccountAjax.call("SaveAccount", data, callbackMethod);
    }
};