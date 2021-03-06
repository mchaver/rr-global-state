// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Store1$ReactHooksTemplate = require("./Store1.js");

function DataTable(Props) {
  var state = Curry._2(Store1$ReactHooksTemplate.api[/* useStore */5], undefined, /* () */0);
  return React.createElement("div", undefined, React.createElement("table", undefined, React.createElement("thead", undefined, React.createElement("tr", undefined, React.createElement("th", undefined, "Name"), React.createElement("th", undefined, "Address"), React.createElement("th", undefined, "Phone"), React.createElement("th", undefined, "Action"))), React.createElement("tbody", undefined, $$Array.mapi((function (i, company) {
                            return React.createElement("tr", {
                                        key: String(i)
                                      }, React.createElement("td", undefined, company[/* name */1]), React.createElement("td", undefined, company[/* address */2]), React.createElement("td", undefined, company[/* phone */3]), React.createElement("td", undefined, React.createElement("button", {
                                                onClick: (function (ev) {
                                                    ev.persist();
                                                    ev.preventDefault();
                                                    return Curry._1(Store1$ReactHooksTemplate.api[/* dispatch */4], /* EditCompany */Block.__(3, [company]));
                                                  })
                                              }, "edit"), React.createElement("button", {
                                                onClick: (function (ev) {
                                                    ev.persist();
                                                    return Curry._1(Store1$ReactHooksTemplate.api[/* dispatch */4], /* DeleteCompany */Block.__(1, [company[/* id */0]]));
                                                  })
                                              }, "X")));
                          }), state[/* companies */0]))));
}

var make = DataTable;

exports.make = make;
/* react Not a pure module */
