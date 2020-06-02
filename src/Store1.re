type company = {
  id: int,
  name: string,
  address: string,
  phone: string,
};

type state = {
  companies: array(company),
  editCompany: option(company),
};

type action =
  | AddCompany(company)
  | DeleteCompany(int)
  | UpdateCompany(company)
  | EditCompany(option(company));

let reducer = (state, action) => {
  switch (action) {
  | AddCompany(company) => {
      ...state,
      companies: Array.append(state.companies, [|company|]),
    }
  | DeleteCompany(id) => {
      ...state,
      companies:
        Js.Array.filter((c: company) => c.id != id, state.companies),
    }
  | UpdateCompany(company) =>
    let cs = state.companies;
    cs[company.id] = company;
    {...state, companies: cs};
  | EditCompany(editCompany) => {...state, editCompany}
  };
};

// api is a record with six functions
// getState, subscribe, subscribeWithSelector, dispatch, useStore, useStoreWithSelector
let api =
  Restorative.createStore(
    {
      editCompany: None,
      companies: [|
        {
          id: 0,
          name: "Book store",
          address: "1020 W. 3rd Street",
          phone: "918-222-3333",
        },
      |],
    },
    reducer,
  );
