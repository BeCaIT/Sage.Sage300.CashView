/* Copyright © 2019 Sage Software Asia Pte Ltd */

var scReportsRepository = {
    print: function (name, callbackMethod) {
        var data = { Name: name };
        window.sg.utls.ajaxPost(window.sg.utls.url.buildUrl("SC", "Reports", "Execute"), data, callbackMethod);
    }
};