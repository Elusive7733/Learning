import employeeData from "../data/employeeData.json";
import reportData from "../data/reportData.json";
import testData from "../data/testData.json";
import EmployeeStatus from "../components/EmployeeStatus/EmployeeStatus";
import ReportStatus from "../components/ReportStatus/ReportStatus";
import Calender from "../components/Calender/Calender";
import { useEffect } from "react";

const styles = {
  fontFamily: "Roboto",
  width: "100vw",
  height: "100vh",
};
const App = () => {
  let employeeList = [];
  let reportList = [];
  let testList = [];

  useEffect(() => {
    for (let i = 0; i < employeeData.length; i++) {
      employeeList.push(employeeData[i]);
    }
    for (let i = 0; i < reportData.length; i++) {
      reportList.push(reportData[i]);
    }
    for (let i = 0; i < testData.length; i++) {
      testList.push(testData[i]);
    }
  }, []);

  console.log(employeeList);
  console.log(reportList);

  return (
    <div style={styles}>
      <div
        style={{
          // margin: "0 auto",
          width: "30%",
          height: "20%",
          backgroundColor: "#F6F6F6",
        }}
      >
        <ReportStatus data={reportList} />
      </div>

      <div
        style={{
          // margin: "0 auto",
          width: "30%",
          height: "70%",
          backgroundColor: "#F6F6F6",
        }}
      >
        <EmployeeStatus data={employeeList} />
      </div>

      <div
        style={{
          margin: "0 auto",
          width: "70%",
          height: "50%",
          backgroundColor: "white",
        }}
      >
        <Calender />
      </div>
    </div>
  );
};

export default App;
