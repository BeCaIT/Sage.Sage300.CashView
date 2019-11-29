/* Copyright (c) 1994-2015 Sage Software, Inc.  All rights reserved. */

"use strict";

/* Label Menu Popup Customization */
var LabelMenuHelper = LabelMenuHelper || {};
LabelMenuHelper = {

    initialize: function (data, btnHamburger, viewModelName) {

        $(document).off('.labelMenu');
        ko.cleanNode($("#divLabelMenu")[0]);
        $("#" + btnHamburger).attr('tabindex', '-1');

        // Mouse enter event
        $("#" + btnHamburger).on('mouseenter.labelMenu', function (e) {

            // Load Menu
            var ulMenu = $('#lstLabelMenu');
            ulMenu.empty();
            for (var i = 0; i < data.length; i++) {
                ulMenu.append(window.hamburgerElements.menuItem);
                var val = data[i];
                var btnId = val.Id;
                var btn = ulMenu.find("#btnNewHamburgerMenu").attr({
                    "id": val.Id,
                    "name": val.Id,
                    "class": "action-btn",
                    "type": "button",
                    "value": val.Value,
                    "data-bind": val.koAttributes,
                }).on("click", val.callback);
            }
            
            LabelMenuHelper.ShowMenu($('#divLabelMenu'), $(this));

            var viewModel = eval(viewModelName);

            if (viewModel != undefined) {
                ko.applyBindings(viewModel, $("#divLabelMenu")[0]);
            }
        });

        // Mouse leave event
        $(document).contents().find('[class^="label-menu"]').on('mouseleave.labelMenu', function (e) {
            var container = $('#divLabelMenu');
            var list = $('#divLabelMenu ul:first');
            if ($(this).is(e.relatedTarget) || container.is(e.relatedTarget) || list.is(e.relatedTarget)) {
                LabelMenuHelper.ShowMenu(container, $(this));
            }
            else {
                container.hide();
            }
        });

        // Menu Item click event
        $(document).on('click.labelMenu', function (e) {
            var container = $('#divLabelMenu');
            // if the target of the click isn't the container... nor a descendant of the container
            if (!container.is(e.target) && container.has(e.target).length === 0) {
                // Detach and Append the container (div) to the current parent, 
                // because this container not gets scrolled along with the page when loaded inside the popup
                var parentForm = window.top.$('iframe.screenIframe:visible').contents().find('form:first');
                var kendoWindowContainer = container.closest('.k-window-content.k-content');
                if (parentForm !== null && parentForm.length > 0 && kendoWindowContainer !== null && kendoWindowContainer.length > 0) {
                    container.detach();
                    parentForm.append(container);
                }
            }
        });
    },

    /**
     * Display the menu items.
     * @method ShowMenu      
     * @param {} container - Parent div element.
     * @param {} e - anchor button.
     */
    ShowMenu: function (container, e) {

        var targetOffset = e.offset();
        if (targetOffset !== null && e.attr('id') != "divLabelMenu") {
            var containerTopPos = targetOffset.top + e.outerHeight();
            var containerLeftPos = targetOffset.left;
            var containerWidth = container.width();
            var iframeContentWidth = 960;

            // Detach and Append the container (div) to the current parent, 
            // because this container not gets scrolled along with the page when loaded inside the popup
            var kendoWindowContainer = e.closest('.k-window-content.k-content');
            if (kendoWindowContainer !== null && kendoWindowContainer.length > 0) {
                container.detach();
                e.closest('.k-window-content.k-content').append(container);
                var parentKendoWindowPosition = kendoWindowContainer.closest('.k-widget.k-window').offset();
                containerTopPos = containerTopPos - (parentKendoWindowPosition.top - kendoWindowContainer.scrollTop() + 72);
                containerLeftPos = containerLeftPos - (parentKendoWindowPosition.left + 21);
            }
            else {
                // Display the menu at available place, in case the button placed at corners.
                if (($(document).height() - (targetOffset.top + 40)) < container.height()) {
                    containerTopPos = targetOffset.top - parseInt(container.css('height'), 10);
                }
                if ((containerLeftPos + containerWidth) > iframeContentWidth) {
                    containerLeftPos = targetOffset.left - (containerWidth + e.width());
                }
            }
            container.css({ top: containerTopPos, left: containerLeftPos, position: 'absolute', "z-index": "10003" });
            container.show();
        }
    },
}
