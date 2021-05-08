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

    return (
      <div className="App">
        <h1>Hello This is abdullah</h1>
          <p><em>This is Italic</em></p>
          <button
            style={style}
            onClick={this.togglePersonHander}
            >Display Persons</button>
        <div>
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
        </div>
      </div> 
    );

  }
}

export default App;
