import React, { Component } from "react";
// import classes from "./Persons.css";
import Person from "./Person/Person";

//__________Function Based Component__________

//if only want to return in a function and do nothing else we can use round () paranthesis
// const persons = (props) => {
//   console.log("Persons.js rendering...");
//   return props.persons.map((element, index) => {
//     return (
//       <Person
//         key={element.id}
//         clicked={() => props.clicked(index)}
//         changed={(event) => props.changed(event, element.id)}
//         name={element.name}
//         nick={element.nick}
//       />
//     );
//   });
// };

// export default persons;

//__________Class Based Component__________

class Persons extends Component {
  static getDerivedStateFromProps(props, state) {
    console.log("in Persons.js getDerivedStateFromProps");
    return state;
  }

  shouldComponentUpdate(nextProps, nextState) {
    console.log("in Persons.js shouldComponentUpdate");
    return true;
  }

  getSnapshotBeforeUpdate(prevProps, prevState) {
    console.log("in Persons.js getSnapshotBeforeUpdate");
  }

  componentDidUpdate(prevProps, prevState) {
    console.log("in Persons.js componentDidUpdate");
  }

  render() {
    console.log("Persons.js rendering...");
    return this.props.persons.map((element, index) => {
      return (
        <Person
          key={element.id}
          clicked={() => this.props.clicked(index)}
          changed={(event) => this.props.changed(event, element.id)}
          name={element.name}
          nick={element.nick}
        />
      );
    });
  }
}

export default Persons;
