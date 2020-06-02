let eventToValue = event => ReactEvent.Form.target(event)##value;

type localState = {
  name: string,
  phone: string,
  address: string,
};

type localAction =
  | UpdateLocalState(localState);

[@react.component]
let make = () => {
  let globalState = Store1.api.useStore();
  /* let (name, setName) = React.useState(_ => ""); */
  /* let (address, setAddress) = React.useState(_ => ""); */
  /* let (phone, setPhone) = React.useState(_ => ""); */

  let (localState, localDispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | UpdateLocalState(state) => state
        },
      {name: "", phone: "", address: ""}: localState,
    );

  /* use this to update local state after global state
     otherwise what is below in '| Some(company) =>' will cause an infinite loop
  */ 
  React.useEffect1(
    () => {
      switch (globalState.editCompany) {
      | Some(company) =>
        localDispatch(
          UpdateLocalState({
            name: company.name,
            address: company.address,
            phone: company.phone,
          }),
        )
      | None => ()
      };
      None;
    },
    [|globalState.editCompany|],
  );

  switch (globalState.editCompany) {
  | None => <div> {React.string("not editing at the moment")} </div>
  | Some(company) =>
    /* these both cause an infinite loop */
    /* have to use useEffect1 */
    /* setName(_ => company.name); */
    /* setAddress(_ => company.address); */
    /* setPhone(_ => company.phone); */

    /* React.useEffect0(() => { */
    /*   localDispatch(UpdateLocalState({...localState, name: company.name})); */
    /*   None; */
    /* }); */

    <div>
      <form>
        <label> {React.string("Name: ")} </label>
        <input
          key="data-entry-name"
          placeholder="Company name"
          value={localState.name}
          type_="text"
          onChange={ev => {
            ReactEvent.Synthetic.persist(ev);
            let name = eventToValue(ev);
            localDispatch(UpdateLocalState({...localState, name}));
          }}
        />
        <label> {React.string("Address: ")} </label>
        <input
          key="data-entry-address"
          placeholder="Company address"
          value={localState.address}
          type_="text"
          onChange={ev => {
            ReactEvent.Synthetic.persist(ev);
            let address = eventToValue(ev);
            localDispatch(UpdateLocalState({...localState, address}));
          }}
        />
        <label> {React.string("Phone: ")} </label>
        <input
          key="data-entry-phone"
          placeholder="Company phone number"
          value={localState.phone}
          type_="text"
          onChange={ev => {
            ReactEvent.Synthetic.persist(ev);
            let phone = eventToValue(ev);
            localDispatch(UpdateLocalState({...localState, phone}));
          }}
        />
      </form>
      <button
        onClick={ev => {
          ReactEvent.Synthetic.persist(ev);
          Store1.(
            api.dispatch(
              UpdateCompany(
                {
                  id: company.id,
                  Store1.name: localState.name,
                  Store1.address: localState.address,
                  Store1.phone: localState.phone,
                }: company,
              ),
            )
          );
          Store1.(api.dispatch(EditCompany(None)));
        }}>
        {React.string("Update company")}
      </button>
      <button
        onClick={ev => {
          ReactEvent.Synthetic.persist(ev);
          Store1.(api.dispatch(EditCompany(None)));
        }}>
        {React.string("Cancel")}
      </button>
    </div>
  };
};
