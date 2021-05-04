import React, { Component } from 'react';
import './App.css';
import Person from './Person/Person';


class App extends Component {
  state = {
    persons: [
      {name: "Abdullah", nick: "Abduls"},
      {name: "Hiba", nick: "Hibs"},
      {name: "Elusive", nick: "Elu" },
    ]
  }
  
  switchNameHandler = (newName) => {
     this.setState({
      persons: [
        {name: newName, nick: "Abduls"},
        {name: "Hiba", nick: "Hibs"},
        {name: "Elusive", nick: "Elu" },
      ]
    })
  }

  nameChangeHandler = (event) => {
    this.setState({
        persons: [
          {name: "Abdullah", nick: "Abduls"},
          {name: event.target.value, nick: "Hibs"},
          {name: "Elusive", nick: "Elu" },
        ]
      })
  }

  render() {
    return (

      <div className="App">
        <h1>Hello This is abdullah
          <p><em>This is Italic</em></p>
          <button onClick={this.switchNameHandler.bind(this, "Abdullah")}>Switch Name</button>
          <Person
            name={this.state.persons[0].name}
            nick={this.state.persons[0].nick} /> <br></br>
          <Person
            name={this.state.persons[1].name}
            nick={this.state.persons[1].nick}
            click={this.switchNameHandler.bind(this, "Nibba")}
            changed={this.nameChangeHandler} >You like Sekiro</Person> <br></br>
          <Person
            name={this.state.persons[2].name}
            nick={this.state.persons[2].nick}/> <br></br>
          {/* Custom HTML element */}
        </h1>
      </div> 
    );

  }
}

export default App;
