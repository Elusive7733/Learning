import { ResponsiveBar } from "@nivo/bar";

const MyResponsiveBar = ({ data }) => (
  <ResponsiveBar
    data={data}
    keys={["Late", "On Time", "In Progress"]}
    indexBy="country"
    margin={{ top: 50, right: 130, bottom: 50, left: 60 }}
    padding={0.1}
    groupMode="stacked"
    valueScale={{ type: "linear" }}
    indexScale={{ type: "band", round: true }}
    colors={["#FA3604", "#1CDF07", "#00B4D8"]}
    // colorBy="index"
    colorBy="id"
    // layout="horizontal"
    borderRadius="2px"
    borderWidth="1px"
    borderColor={{
      from: "color",
      modifiers: [["darker", 1.6]],
    }}
    axisTop={null}
    axisRight={null}
    axisBottom={{
      tickSize: 5,
      tickPadding: 5,
      tickRotation: 0,
      // legend: "Number Of Reports",
      // legendPosition: "middle",
      // legendOffset: 32,
    }}
    axisLeft={{
      tickSize: 5,
      tickPadding: 5,
      tickRotation: 0,
      //   legend: "Employees",
      //   legendPosition: "middle",
      //   legendOffset: -55,
    }}
    labelSkipWidth={12}
    labelSkipHeight={12}
    labelTextColor="white"
    legends={[
      {
        dataFrom: "keys",
        anchor: "bottom-right",
        direction: "column",
        justify: false,
        translateX: 120,
        translateY: 0,
        itemsSpacing: 2,
        itemWidth: 100,
        itemHeight: 20,
        itemDirection: "left-to-right",
        itemOpacity: 0.85,
        symbolSize: 20,
        effects: [
          {
            on: "hover",
            style: {
              itemOpacity: 1,
            },
          },
        ],
      },
    ]}
    role="application"
    ariaLabel="Nivo bar chart demo"
    barAriaLabel={function (e) {
      return e.id + ": " + e.formattedValue + " in country: " + e.indexValue;
    }}
  />
);

export default MyResponsiveBar;
