import React from "react";
import classes from "./Cockpit.css";

const cockpit = (props) => {
  let assigned_class = [];
  let btnClasses = [classes.Button];

  if (props.show_persons) {
    btnClasses.push(classes.Maroon);
  }

  if (props.persons.length <= 2) {
    assigned_class.push(classes.red);
  }
  if (props.persons.length <= 1) {
    assigned_class.push(classes.bold);
  }

  return (
    <div className={classes.Cockpit}>
      <h1>Hello This is abdullah</h1>
      <p className={assigned_class.join(" ")}>
        <em>This is Italic</em>
      </p>
      <button className={btnClasses.join(" ")} onClick={props.clicked}>
        Display Persons
      </button>
    </div>
  );
};

export default cockpit;
