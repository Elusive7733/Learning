import React from "react";
import classes from "./Person.css";

const person = (props) => {
  // Displaying Custom Error (used with error boundry)
  // const rnd = Math.random();
  // if (rnd >= 0.7) {
  //   throw new Error("Something WONG!!!");
  // }
  console.log("1 Person.js rendering...");
  return (
    <div className={classes.Person}>
      <p onClick={props.clicked}>
        Hello There {props.name} you are also called {props.nick}
      </p>
      <p>You are {Math.floor(Math.random() * 30)} years old</p>
      <p>{props.children}</p>
      <input type="text" onChange={props.changed} value={props.name}></input>
    </div>
  );
};

export default person;
