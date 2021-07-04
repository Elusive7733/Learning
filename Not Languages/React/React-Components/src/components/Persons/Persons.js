import React from "react";
// import classes from "./Persons.css";
import Person from "./Person/Person";

//if only want to return in a function and do nothing else we can use round () paranthesis
const persons = (props) => {
  console.log("Persons.js rendering...");
  return props.persons.map((element, index) => {
    return (
      <Person
        key={element.id}
        clicked={() => props.clicked(index)}
        changed={(event) => props.changed(event, element.id)}
        name={element.name}
        nick={element.nick}
      />
    );
  });
};

export default persons;
