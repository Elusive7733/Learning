import FullCalendar from "@fullcalendar/react";
import dayGridPlugin from "@fullcalendar/daygrid";
import listPlugin from "@fullcalendar/list";
import timeGridPlugin from "@fullcalendar/timegrid";
import interactionPlugin from "@fullcalendar/interaction";
import { INITIAL_EVENTS, createEventId } from "event-utils";

const Calender = () => {
  return (
    <div style={{ marginTop: "20px" }}>
      <FullCalendar
        plugins={[dayGridPlugin, listPlugin, timeGridPlugin, interactionPlugin]}
        headerToolbar={{
          left: "prev,next today",
          center: "title",
          right: "dayGridMonth,timeGridWeek,listWeek",
        }}
        initialView="dayGridMonth"
        editable={true}
        selectable={true}
        selectMirror={true}
        dayMaxEvents={true}
        weekends={false}
        events={[
          {
            title: "Community Of Hope",
            daysOfWeek: ["1", "2", "4", "5"],
            date: "2022-02-14",
            backgroundColor: "#FA3604",
            borderColor: "grey",
          },
          {
            title: "ICU Cyclic",
            daysOfWeek: ["1"],
            date: "2022-02-14",
            backgroundColor: "#00B4D8",
            borderColor: "grey",
          },
          {
            title: "BRS Cyclic",
            daysOfWeek: ["2"],
            date: "2022-02-14",
            backgroundColor: "#00B4D8",
            borderColor: "grey",
          },
          {
            title: "WIPSAM",
            daysOfWeek: ["1", "3"],
            date: "2022-02-14",
            backgroundColor: "#1CDF07",
            borderColor: "grey",
          },
          {
            title: "Template Resupply",
            daysOfWeek: ["1", "2", "4"],
            date: "2022-02-14",
            backgroundColor: "#1CDF07",
            borderColor: "grey",
          },
          {
            title: "Driver Monitoring",
            daysOfWeek: ["1", "2", "4"],
            date: "2022-02-14",
            backgroundColor: "#00B4D8",
            borderColor: "grey",
          },
          {
            title: "Brightree Xcelence",
            daysOfWeek: ["2", "4", "5"],
            date: "2022-02-14",
            backgroundColor: "#00B4D8",
            borderColor: "grey",
          },
          {
            title: "BRS Survey Forms",
            daysOfWeek: ["2", "5"],
            date: "2022-02-14",
            backgroundColor: "#1CDF07",
            borderColor: "grey",
          },
          {
            title: "Audit",
            daysOfWeek: ["2", "4"],
            date: "2022-02-14",
            backgroundColor: "#FA3604",
            borderColor: "grey",
          },
        ]}
      />{" "}
    </div>
  );
};

export default Calender;
