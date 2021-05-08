import React, { Component } from 'react';
import './App.css';
import Validation from './Validation/Validation';
import Character from  './Character/Character';


class App extends Component {
  state = {
    userInput: ''
  };

  updateInputHandler = (event) => {
    this.setState({userInput: event.target.value})
  };

  deleteCharHandler = () => {
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
      {this.state.userInput.split('').map((single_character, index) => {
        return(
          <Character
          letter={single_character}
          key = {index}
          clicked = {() => this.deleteCharHandler(index)}
          />
        );
      })}
      </div>
    );
  };
};

export default App;