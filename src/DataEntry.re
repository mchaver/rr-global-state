let eventToValue = event => ReactEvent.Form.target(event)##value;

// note that we have to use ReactEvent.Synthetic.persist(ev) or it will crash

[@react.component]
let make = () => {
  let state = Store1.api.useStore();
  let (name, setName) = React.useState(_ => "");
  let (address, setAddress) = React.useState(_ => "");
  let (phone, setPhone) = React.useState(_ => "");
  <div>
    <form>
      <label> {React.string("Name: ")} </label>
      <input
        key="data-entry-name"
        placeholder="Company name"
        value=name
        type_="text"
        onChange={ev => {
          ReactEvent.Synthetic.persist(ev);
          setName(_ => {eventToValue(ev)});
        }}
      />
      <label> {React.string("Address: ")} </label>
      <input
        key="data-entry-address"
        placeholder="Company address"
        value=address
        type_="text"
        onChange={ev => {
          ReactEvent.Synthetic.persist(ev);
          setAddress(_ => {eventToValue(ev)});
        }}
      />
      <label> {React.string("Phone: ")} </label>
      <input
        key="data-entry-phone"
        placeholder="Company phone number"
        value=phone
        type_="text"
        onChange={ev => {
          ReactEvent.Synthetic.persist(ev);
          setPhone(_ => {eventToValue(ev)});
        }}
      />
    </form>
    <button
      onClick={_ => {
        Store1.(
          api.dispatch(
            AddCompany(
              {id: Array.length(state.companies), name, address, phone}: company,
            ),
          )
        );
        setName(_ => "");
        setAddress(_ => "");
        setPhone(_ => "");
      }}>
      {React.string("Add company")}
    </button>
  </div>;
};
