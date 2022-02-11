import employeeData from "../data.json";
import reportData from "../data2.json";
import MyResponsiveBar from "../components/MyResponsiveBar";

function App() {
  let mylist = [];
  // for (let i = 0; i < employeeData.length; i++) {
  //   mylist.push(employeeData[i]);
  // }
  for (let i = 0; i < reportData.length; i++) {
    mylist.push(reportData[i]);
  }

  console.log(mylist);
  return (
    <div style={{ width: "100vw", height: "100vh" }}>
      <div style={{ margin: "0 auto", width: "30%", height: "70%" }}>
        <MyResponsiveBar data={mylist} />
      </div>
    </div>
  );
}

export default App;
