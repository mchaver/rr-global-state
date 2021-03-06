// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Restorative = require("restorative/lib/js/src/Restorative.bs.js");

function reducer(state, action) {
  switch (action.tag | 0) {
    case /* AddCompany */0 :
        return /* record */[
                /* companies */$$Array.append(state[/* companies */0], /* array */[action[0]]),
                /* editCompany */state[/* editCompany */1]
              ];
    case /* DeleteCompany */1 :
        var id = action[0];
        return /* record */[
                /* companies */state[/* companies */0].filter((function (c) {
                        return c[/* id */0] !== id;
                      })),
                /* editCompany */state[/* editCompany */1]
              ];
    case /* UpdateCompany */2 :
        var company = action[0];
        var cs = state[/* companies */0];
        Caml_array.caml_array_set(cs, company[/* id */0], company);
        return /* record */[
                /* companies */cs,
                /* editCompany */state[/* editCompany */1]
              ];
    case /* EditCompany */3 :
        return /* record */[
                /* companies */state[/* companies */0],
                /* editCompany */action[0]
              ];
    
  }
}

var api = Restorative.createStore(/* record */[
      /* companies : array */[/* record */[
          /* id */0,
          /* name */"Book store",
          /* address */"1020 W. 3rd Street",
          /* phone */"918-222-3333"
        ]],
      /* editCompany */undefined
    ], reducer);

exports.reducer = reducer;
exports.api = api;
/* api Not a pure module */
