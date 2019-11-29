/* Copyright © 2019 Sage Software Asia Pte Ltd */

"use strict";

var scReportsUtil = {
    printReport: function (name) {
        $("#success").empty();
        $("#message").empty();
        scReportsRepository.print(name, scReportsCallbacks.printReport);
    }
};

var scReportsCallbacks = {
    printReport: function (result) {
        if (result !== null && result.UserMessage.IsSuccess) {
            window.sg.utls.openReport(result.ReportToken);
        } else {
            window.sg.utls.showMessage(result);
            $(window).scrollTop(0);
        }
    }
};