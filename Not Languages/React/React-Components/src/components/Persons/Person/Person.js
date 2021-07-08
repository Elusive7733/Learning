import React, { Component } from "react";
import classes from "./Person.css";

//__________Function Based Component__________

// const person = (props) => {
//   // Displaying Custom Error (used with error boundry)
//   // const rnd = Math.random();
//   // if (rnd >= 0.7) {
//   //   throw new Error("Something WONG!!!");
//   // }
//   console.log("1 Person.js rendering...");
//   return (
//     <div className={classes.Person}>
//       <p onClick={props.clicked}>
//         Hello There {props.name} you are also called {props.nick}
//       </p>
//       <p>You are {Math.floor(Math.random() * 30)} years old</p>
//       <p>{props.children}</p>
//       <input type="text" onChange={props.changed} value={props.name}></input>
//     </div>
//   );
// };

// export default person;

//__________Class Based Component__________

class Person extends Component {
  render() {
    console.log("1 Person.js rendering...");
    return (
      <div className={classes.Person}>
        <p onClick={this.props.clicked}>
          Hello There {this.props.name} you are also called {this.props.nick}
        </p>
        <p>You are {Math.floor(Math.random() * 30)} years old</p>
        <p>{this.props.children}</p>
        <input
          type="text"
          onChange={this.props.changed}
          value={this.props.name}
        ></input>
      </div>
    );
  }
}

export default Person;
