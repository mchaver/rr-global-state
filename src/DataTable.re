[@react.component]
let make = () => {
  let state = Store1.api.useStore();
  <div>
    <table>
      <thead>
        <tr>
          <th> {React.string("Name")} </th>
          <th> {React.string("Address")} </th>
          <th> {React.string("Phone")} </th>
          <th> {React.string("Action")} </th>
        </tr>
      </thead>
      <tbody>
        {Array.mapi(
           (i, company: Store1.company) => {
             <tr key={string_of_int(i)}>
               <td> {React.string(company.name)} </td>
               <td> {React.string(company.address)} </td>
               <td> {React.string(company.phone)} </td>
               <td>
                 <button
                   onClick={ev => {
                     ReactEvent.Synthetic.persist(ev);
                     ReactEvent.Synthetic.preventDefault(ev);
                     Store1.(api.dispatch(EditCompany(Some(company))));
                   }}>
                   {React.string("edit")}
                 </button>
                 <button
                   onClick={ev => {
                     ReactEvent.Synthetic.persist(ev);
                     Store1.(api.dispatch(DeleteCompany(company.id)));
                   }}>
                   {React.string("X")}
                 </button>
               </td>
             </tr>
           },
           state.companies,
         )
         |> React.array}
      </tbody>
    </table>
  </div>;
};
