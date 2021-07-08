import React, { Component } from "react";
import classes from "./App.css";
import Persons from "../components/Persons/Persons";
import Cockpit from "../components/Cockpit/Cockpit";

class App extends Component {
  constructor(props) {
    super(props);
    console.log("in App.js constructor");
  }

  state = {
    persons: [
      { id: "asd", name: "Abdullah", nick: "Abduls" },
      { id: "asd1", name: "Hiba", nick: "Hibs" },
      { id: "sfg1", name: "Elusive", nick: "Elu" },
    ],
    show_persons: false,
    show_cockpit: true,
  };

  //not often used
  static getDerivedStateFromProps(props, state) {
    console.log("in App.js getDerivedStateFromProps", props);
    return state;
  }

  componentDidMount() {
    console.log("in App.js componentDidMount");
  }

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
    console.log("in App.js render");
    let persons_list = null;

    if (this.state.show_persons) {
      persons_list = (
        <div>
          <Persons
            persons={this.state.persons}
            clicked={this.deletePersonHandler}
            changed={this.nameChangeHandler}
          />
        </div>
      );
    }

    let btnClasses = [classes.Button];
    if (this.state.show_cockpit) {
      btnClasses.push(classes.Black);
    }

    return (
      <div className={classes.App}>
        <button
          className={btnClasses.join(" ")}
          onClick={() => {
            this.setState({ show_cockpit: !this.state.show_cockpit });
          }}
        >
          Toggle Clockpit
        </button>
        {this.state.show_cockpit ? (
          <Cockpit
            // this.props are used in class based components
            app_name={this.props.app_name}
            show_persons={this.state.show_persons}
            persons={this.state.persons}
            clicked={this.togglePersonHander}
          />
        ) : null}
        {this.state.show_cockpit ? { persons_list } : null}
      </div>
    );
  }
}

export default App;
