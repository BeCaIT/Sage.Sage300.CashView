/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var scDashboardKoExtn = scDashboardKoExtn || {};

scDashboardKoExtn = {
    modelExtension: function (model, uiMode) {
        model.UIMode = ko.observable(uiMode);

        model.InValue = ko.computed(function () {
            return kendo.toString(model.Data.NetAR(), "n2");
        });

        model.OutValue = ko.computed(function () {
            return kendo.toString(model.Data.NetAP(), "n2");
        });

        model.NetValue = ko.computed(function () {
            return kendo.toString(model.Data.NetOperations(), "n2");
        });

        model.DSOValue = ko.computed(function () {
            return kendo.toString(model.Data.DSO(), "n2");
        });

        model.DPOValue = ko.computed(function () {
            return kendo.toString(model.Data.DPO(), "n2");
        });

        model.ARCValue = ko.computed(function () {
            return kendo.toString(model.Data.ARC(), "p2");
        });

        model.CCCValue = ko.computed(function () {
            return kendo.toString(model.Data.CCC(), "n2");
        });
    }
};