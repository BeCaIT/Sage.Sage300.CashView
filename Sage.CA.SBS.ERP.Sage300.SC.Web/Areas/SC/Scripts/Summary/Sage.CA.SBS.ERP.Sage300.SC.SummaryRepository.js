/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

// Ajax call to controller
var scSummaryAjax = {

    call: function (method, data, callbackMethod) {
        var url = sg.utls.url.buildUrl("SC", "Summary", method);
        sg.utls.ajaxPost(url, data, callbackMethod);
    }
};

var scSummaryRepository = {

    // Get
    get: function (id, callbackMethod) {
        var data = {};
        scSummaryAjax.call("Get", data, callbackMethod);
    },

    // Update
    update: function (data, callbackMethod) {
        scSummaryAjax.call("Save", data, callbackMethod);
    }

    // Additional methods go here
};

/****************************** scForecastEntry - BEGIN ******************************/
var scForecastEntryAjax = {
    call: function (method, data, callbackMethod) {
        var url = sg.utls.url.buildUrl("SC", "ForecastEntry", method);
        sg.utls.ajaxPost(url, data, callbackMethod);
    }
};

var scForecastEntryRepository = {

    // Get
    get: function (data, callbackMethod) {
        scForecastEntryAjax.call("Get", data, callbackMethod);
    },
    
    // Add
    add: function (model, pageOptions, callbackMethod) {
        var data = {
            model: model,
            pageOptions: pageOptions
        };
        scForecastEntryAjax.call("Add", data, callbackMethod);
    },
    //add2: function (model, pageNumber, pageSize, callbackMethod) {
    //    var data = {
    //        model: model,
    //        pageNumber: pageNumber,
    //        pageSize: pageSize
    //    };
    //    scForecastEntryAjax.call("Add2", data, callbackMethod);
    //},

    // Update
    update: function (data, callbackMethod) {
        scForecastEntryAjax.call("Save", data, callbackMethod);
    },

    // Delete
    delete: function (data, callbackMethod) {
        //var data = { id: id };
        scForecastEntryAjax.call("Delete", data, callbackMethod);
    },
};
/****************************** scForecastEntry - END ******************************/