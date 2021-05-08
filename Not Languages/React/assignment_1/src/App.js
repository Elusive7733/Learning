import React, { Component } from 'react';
import './App.css';
import Validation from './Validation/Validation'


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
        <div className="InputBox">
          <input type="text" onChange={(event) => this.updateInputHandler(event)} value={this.state.userInput} />
          <p>{this.state.userInput.length}</p>
          <Validation 
            length = {this.state.userInput.length}
          />
        </div>
      </div>
    );
  };
};

export default App;