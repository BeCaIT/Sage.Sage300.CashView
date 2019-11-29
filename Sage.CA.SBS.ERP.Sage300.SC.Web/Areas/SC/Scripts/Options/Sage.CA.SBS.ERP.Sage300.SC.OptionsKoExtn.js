/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var scOptionsKoExtn = scOptionsKoExtn || {};

scOptionsKoExtn = {
    scOptionsModelExtension: function (model, uiMode) {
        model.UIMode = ko.observable(uiMode);
    },

    getCompanyProfile: function (model) {
        var strBuilder = "", newLine = "\n", paraghStrtBold = "<b>", paraghEndBold = "</b>", paraghStarthdr = "<label class='company-name'>", paraghStart = "<label>", paraghEnd = "</label>";
        strBuilder += paraghStarthdr + sg.utls.toTrim(model.CompanyProfile.CompanyProfileContact.Name()) + paraghEnd;
        strBuilder += paraghStart + sg.utls.toTrim(model.CompanyProfile.Address.AddressLine1()) + paraghEnd;
        strBuilder += paraghStart + sg.utls.toTrim(model.CompanyProfile.Address.AddressLine2()) + paraghEnd;
        strBuilder += paraghStart + sg.utls.toTrim(model.CompanyProfile.Address.AddressLine3()) + paraghEnd;
        strBuilder += paraghStart + sg.utls.toTrim(model.CompanyProfile.Address.AddressLine4()) + paraghEnd;
        strBuilder += paraghStart + sg.utls.toTrim(model.CompanyProfile.Address.City()) + paraghEnd;
        strBuilder += paraghStart + sg.utls.toTrim(model.CompanyProfile.Address.State()) + paraghEnd;
        strBuilder += paraghStart + sg.utls.toTrim(model.CompanyProfile.Address.ZipCode()) + paraghEnd;
        strBuilder += paraghStart + sg.utls.toTrim(model.CompanyProfile.Address.Country()) + paraghEnd;
        $("#cmpny_profile_address").html(strBuilder);
    }
};

//function optionsObservableExtension(viewModel, uiMode) {

//    var model = viewModel.Data;
//    model.UIMode = ko.observable(uiMode);

//    // Computed Fields go here
//};