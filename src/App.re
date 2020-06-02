[@react.component]
let make = () => {
  <div>
    <h2> {React.string("Data entry")} </h2>
    <DataEntry />
    <h2> {React.string("Data table")} </h2>
    <DataTable />
    <h2> {React.string("Data edit")} </h2>
    <DataEdit />
  </div>;
};
