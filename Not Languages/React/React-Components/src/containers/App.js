import React, { Component } from "react";
import classes from "./App.css";
import Person from "./Person/Person";

class App extends Component {
  state = {
    persons: [
      { id: "asd", name: "Abdullah", nick: "Abduls" },
      { id: "asd1", name: "Hiba", nick: "Hibs" },
      { id: "sfg1", name: "Elusive", nick: "Elu" },
    ],
    show_persons: false,
  };

  deletePersonHandler = (person_index) => {
    let temp = [...this.state.persons];
    temp.splice(person_index, 1);
    this.setState({ persons: temp });
  };

  nameChangeHandler = (event, id) => {
    const person_index = this.state.persons.findIndex((element) => {
      return element.id === id;
    });

    // This ^^ above step can be skipped if we pass in the index directly

    const temp_persons = [...this.state.persons];
    temp_persons[person_index].name = event.target.value;

    this.setState({ persons: temp_persons });
  };

  togglePersonHander = () => {
    const is_displayed = this.state.show_persons;
    this.setState({ show_persons: !is_displayed });
  };

  render() {
    let persons = null;
    let btnClasses = [classes.Button]; //creating an array here

    console.log(btnClasses);

    if (this.state.show_persons) {
      persons = (
        <div>
          {/* For loop to display each element in a list */}
          {/* Mapping a JavaScript array into jsx elements */}
          {this.state.persons.map((element, index) => {
            return (
              <Person
                key={element.id}
                click={() => this.deletePersonHandler(index)}
                changed={(event) => this.nameChangeHandler(event, element.id)}
                name={element.name}
                nick={element.nick}
              />
            );
          })}
        </div>
      );
      // Dynamic Styling
      btnClasses.push(classes.Maroon);
      //________________
    }

    let assigned_class = [];
    if (this.state.persons.length <= 2) {
      assigned_class.push(classes.red);
    }
    if (this.state.persons.length <= 1) {
      assigned_class.push(classes.bold);
    }

    return (
      <div className={classes.App}>
        <h1>Hello This is abdullah</h1>
        <p className={assigned_class.join(" ")}>
          <em>This is Italic</em>
        </p>
        <button
          className={btnClasses.join(" ")}
          onClick={this.togglePersonHander}
        >
          Display Persons
        </button>
        {persons}
      </div>
    );
  }
}

export default App;
