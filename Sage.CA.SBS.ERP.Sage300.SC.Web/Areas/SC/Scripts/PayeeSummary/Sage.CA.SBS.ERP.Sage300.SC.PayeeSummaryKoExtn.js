/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var scPayeeSummaryKoExtn = scPayeeSummaryKoExtn || {};

scPayeeSummaryKoExtn = {
    modelExtension: function (model, uiMode) {
        model.UIMode = ko.observable(uiMode);
    },
};