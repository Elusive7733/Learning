import React, { Component } from 'react';
import './App.css';
import Person from './Person/Person';

class App extends Component {
  state = {
    persons: [
      {name: "Abdullah", nick: "Abduls"},
      {name: "Hiba", nick: "Hibs"},
      {name: "Elusive", nick: "Elu" },
    ],
    show_persons: false,
  }
  
  deletePersonHandler = () => {}

  nameChangeHandler = (event) => {
    this.setState({
        persons: [
          {name: "Abdullah", nick: "Abduls"},
          {name: event.target.value, nick: "Hibs"},
          {name: "Elusive", nick: "Elu" },
        ]
      })
  }

  togglePersonHander = () => {
    const is_displayed = this.state.show_persons
    this.setState({show_persons: !is_displayed})
  }

  render() {
    const style = {
        color: "white", 
        backgroundColor: "black",
        font: "inherit",
        border: "1px solid grey",
        padding: "8px",
        cursor: "pointer"
    }

    let persons = null
    if(this.state.show_persons){
        persons = (
        <div>
            {/* For loop to display each element in a list */}
            {this.state.persons.map(element => { 
                return (
                    <Person
                    name = {element.name}
                    nick = {element.nick}
                    />
                )
            })}
        </div>
        )
    }

    return (
      <div className="App">
        <h1>Hello This is abdullah</h1>
          <p><em>This is Italic</em></p>
          <button
            style={style}
            onClick={this.togglePersonHander}
            >Display Persons</button>
        {persons}
      </div> 
    );

  }
}

export default App;
