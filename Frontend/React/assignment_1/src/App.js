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

  deleteCharHandler = (index) => {
    let temp_input = this.state.userInput.split('');
    // console.log(temp_input)
    temp_input.splice(index, 1);
    temp_input = temp_input.join('');
    this.setState({userInput: temp_input});
  };

  render(){
    const my_string = this.state.userInput.split('').map((single_character, index) => {
      return(
        <Character
        letter={single_character}
        key = {index}
        clicked = {() => this.deleteCharHandler(index)}
        />
      );
    })

    return(
      <div className="App">
        <div className="InputBox">
          <input type="text" onChange={(event) => this.updateInputHandler(event)} value={this.state.userInput} />
          <p>{this.state.userInput.length}</p>
          <Validation 
            length = {this.state.userInput.length}
          />
        </div>
      {my_string}
      </div>
    );
  };
};

export default App;