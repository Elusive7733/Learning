import { ResponsiveBar } from "@nivo/bar";

const EmployeeStatus = ({ data }) => {
  return (
    <ResponsiveBar
      data={data}
      keys={["Late", "On Time", "In Progress"]}
      indexBy="employee"
      margin={{
        top: 5,
        right: 10,
        bottom: 35,
        left: 55,
      }}
      padding={0.1}
      groupMode="stacked"
      valueScale={{ type: "linear" }}
      indexScale={{ type: "band", round: true }}
      colors={["#FA3604", "#1CDF07", "#00B4D8"]}
      // colorBy="index"
      colorBy="id"
      layout="horizontal"
      borderRadius="2px"
      borderWidth="1px"
      borderColor={{
        from: "color",
        modifiers: [["darker", 1.6]],
      }}
      axisTop={null}
      axisRight={null}
      axisBottom={{
        tickSize: 3,
        tickPadding: 2,
        tickRotation: 0,
        legend: "Number Of Reports",
        legendPosition: "middle",
        legendOffset: 25,
      }}
      axisLeft={{
        tickSize: 3,
        tickPadding: 5,
        tickRotation: 0,
      }}
      labelSkipWidth={12}
      labelSkipHeight={12}
      labelTextColor="white"
      // legends={[
      //   {
      //     dataFrom: "keys",
      //     anchor: "bottom",
      //     direction: "row",
      //     justify: false,
      //     translateX: 30,
      //     translateY: 45,
      //     itemsSpacing: 0,
      //     itemWidth: 80,
      //     itemHeight: 10,
      //     itemDirection: "left-to-right",
      //     itemOpacity: 1,
      //     symbolSize: 20,
      //     effects: [
      //       {
      //         on: "hover",
      //         style: {
      //           itemOpacity: 1,
      //         },
      //       },
      //     ],
      //   },
      // ]}
      role="application"
      ariaLabel="Nivo bar chart demo"
      barAriaLabel={function (e) {
        return e.id + ": " + e.formattedValue + " in country: " + e.indexValue;
      }}
    />
  );
};

export default EmployeeStatus;
