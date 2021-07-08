import React, { useEffect } from "react";
import classes from "./Cockpit.css";

const cockpit = (props) => {
  //Can use multiple useEffects

  //The Argument props.show_persons means the UseEffect will only trigger if my show_persons changes
  //Improvement performence wise

  // useEffect(() => {
  //   console.log("in Cockpit.js useEffect");

  //   // Simulating an HTTP Request
  //   setTimeout(() => {
  //     alert("Data Toggled");
  //   }, 500);
  // }, [props.show_persons]);

  //__________________________________________________________

  //Only run the first time, similar to componentDidMount

  // useEffect(() => {
  //   console.log("in Cockpit.js useEffect");

  //   // Simulating an HTTP Request
  //   setTimeout(() => {
  //     alert("Data Toggled");
  //   }, 500);
  // }, []);

  //__________________________________________________________

  //similar to componentWillUnmount
  useEffect(() => {
    console.log("in Cockpit.js useEffect");

    // Simulating an HTTP Request
    setTimeout(() => {
      alert("Data Toggled");
    }, 500);
    return () => {
      console.log("Cockpit.js cleanup useEffect");
    };
  }, []);

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
      <h1 className={classes.app_name}>{props.app_name}</h1>
      <h2>Hello This is abdullah</h2>
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
