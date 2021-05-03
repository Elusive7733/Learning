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
  render() {
    return (
      // Can not use more than 1 root element, can do it in React 16 but not a good practice
      // This is JSX (Javascript XML) not HTML
      // Class can not be used because it is a reserved word in javascript 
      <div className="App">
        <h1>Hello This is abdullah
          <p><em>This is Italic</em></p>
          <button>Switch Name</button>
          <Person name={this.state.persons[0].name} nick={this.state.persons[0].nick} /> <br></br>
          <Person name={this.state.persons[1].name} nick={this.state.persons[1].nick} >You like Sekiro</Person> <br></br>
          <Person name={this.state.persons[2].name} nick={this.state.persons[2].nick}/> <br></br>
          {/* Custom HTML element */}
        </h1>
      </div> 
    );

    // The Above code^^ compiles to the code below
    // Quite Cumbersome to write the code below
    // React is used under the hood

    // return (
    //   React.createElement(
    //     'div', {className: 'App'}, React.createElement(
    //       'h1', null, "Hello This is abdullah", React.createElement(
    //         "p", null, React.createElement(
    //         'em', null, "This is italic")
    //         )
    //       )
    //     )
    //   );
  }
}

export default App;
