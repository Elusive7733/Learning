import React, { Component } from 'react';
import './App.css';


class App extends Component {
  state = {
    userInput: ''
  };

  updateInputHandler = (event) => {
    this.setState({userInput: event.target.value})
  };

  render(){
    return(
      <div className="App">
          <input type="text" onChange={(event) => this.updateInputHandler(event)} value={this.state.userInput} />
          <p>{this.state.userInput.length}</p>
      </div>
    );
  };
};

export default App;