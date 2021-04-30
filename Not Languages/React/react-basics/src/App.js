import React, { Component } from 'react';
import './App.css';

class App extends Component {
  render() {
    return (
      // Can not use more than 1 root element, can do it in React 16 but not a good practice
      // This is JSX (Javascript XML) not HTML
      // Class can not be used because it is a reserved word in javascript 
      <div className="App">
        <h1>Hello This is abdullah
          <p><em>This is Italic</em></p>
        </h1>
      </div> 
    );

    // The Above code^^ compiles to the below code
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
