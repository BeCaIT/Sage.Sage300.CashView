/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var scLoanKoExtn = scLoanKoExtn || {};

scLoanKoExtn = {
    scLoanModelExtension: function (model, uiMode) {
        model.UIMode = ko.observable(uiMode);

        model.DateSubmitted = ko.computed({
            read: function () {
                var dateSubmitted = model.Data.DateSubmitted();
                return (dateSubmitted === "0001-01-01T00:00:00") ? null : dateSubmitted;
            },
            write: function (value) {
                model.Data.DateSubmitted(value);
            }
        });

        model.IsReadOnly = ko.computed(function () {
            var isReadOnly = model.Data.Status() > 0;
            return isReadOnly;
        });

        model.IsTnCViewed = ko.observable(false);

        model.TnCAgreeDisabled = ko.computed(function () {
            return model.IsReadOnly() || !model.IsTnCViewed();
        });

        model.TnCAgreed = ko.observable(model.Data.Status() > 0 && model.Data.Status() !== 2);
    }
};