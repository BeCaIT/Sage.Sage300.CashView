/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var scSummaryKoExtn = scSummaryKoExtn || {};

scSummaryKoExtn = {
    modelExtension: function (model, uiMode) {
        model.UIMode = ko.observable(uiMode);
    },
};