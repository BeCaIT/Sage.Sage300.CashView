/* Copyright (c) 1994-2014 Sage Software, Inc.  All rights reserved. */

var Customization = {
    set: function (model, root) {
        if (model) {
            var rootNode = root || window.document.body;
            $(rootNode).find("*[data-sg-default]").each(function() {
                var property = $(this);
                var defaultValue = property.attr("data-sg-default");
                //logic if the databind is applied
                var attribute = property.attr("data-bind")
                if (typeof attribute !== 'undefined' && attribute !== "") {
                    if (property.is(':text')) {
                        modelProperty = Customization.getModelProperty(model, $(this), "value")
                        if (modelProperty() == null || modelProperty() == "") {
                            modelProperty(defaultValue);
                        }
                    } else if (property[0].nodeName === "SELECT") {
                        property.find("option").each(function() {
                            if ($(this).text() === defaultValue) {
                                $(this).attr("selected", "selected");
                            }
                        });
                    } else if (property.is(':checkbox')) {
                        var modelProperty = Customization.getModelProperty(model, property, "sagechecked")
                        if (modelProperty() == null || modelProperty() == 0) {
                            modelProperty(defaultValue);
                        }
                    } else if (property.is(':radio')) {
                        if ($(this).attr("value") === defaultValue) {
                            var modelProperty = Customization.getModelProperty(model, property, "sagechecked")
                            if (modelProperty() == null || modelProperty() == 0) {
                                modelProperty(defaultValue);
                            }
                        }
                    }
                } else {
                    if (property.is(':text')) {
                        property.val(defaultValue);
                    } else if (property[0].nodeName === "SELECT") {
                        property.find("option").each(function() {
                            if ($(this).text() === defaultValue) {
                                $(this).attr("selected", "selected");
                            }
                        });
                    } else if (property.is(':checkbox')) {
                        property.prop('checked', defaultValue);
                    } else if (property.is(':radio')) {
                        if (property.attr("value") === defaultValue) {
                            property.prop('checked', true);
                        }
                    }
                }

            });
        }
    },
    getModelProperty: function (model,control, attrToCheck) {
        var databind = control.attr("data-bind");
        var properties = databind.split(',');
        var checkedProperty, modelProperty;
        $.each(properties, function (index, value) {
            checkedProperty = value.split(':');
            if (checkedProperty[0] === attrToCheck) {
                modelProperty = eval((model + "." + checkedProperty[1]));
                modelProperty;
            }
        });
        return modelProperty;

    }
}
 
