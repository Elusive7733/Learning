import React, { Component } from 'react';
import './App.css';
import Person from './Person/Person';
import styled from 'styled-components';

const StyledButton = styled.button`
color: white;
background-color: ${props => props.style_changeOn ? 'Maroon' : 'Green'};
font: inherit;
border: 1px solid grey;
padding: 8px;
cursor: pointer;
&:hover{background-color: ${props => props.style_changeOn ? 'crimson' : 'lightgreen'};}
`

class App extends Component {
  state = {
    persons: [
      { id: "asd", name: "Abdullah", nick: "Abduls"},
      { id: "asd1", name: "Hiba", nick: "Hibs"},
      { id: "sfg1", name: "Elusive", nick: "Elu" },
    ],
    show_persons: false,
  }
  
  deletePersonHandler = (person_index) => {
      let temp = [...this.state.persons];
      temp.splice(person_index, 1);
      this.setState({persons: temp});
  }

  nameChangeHandler = (event, id) => {
    const person_index = this.state.persons.findIndex(element => {
        return element.id === id;
    });

    // This ^^ above step can be skipped if we pass in the index directly

    const temp_persons = [...this.state.persons];
    temp_persons[person_index].name = event.target.value;

    this.setState({persons: temp_persons});
  }

  togglePersonHander = () => {
    const is_displayed = this.state.show_persons;
    this.setState({show_persons: !is_displayed});
  }

  render() {
    let persons = null;
    if(this.state.show_persons){
        persons = (
        <div>
            {/* For loop to display each element in a list */}
            {/* Mapping a JavaScript array into a jsx elements */}
            {this.state.persons.map((element, index) => { 
                return (
                    <Person
                    click = {() => this.deletePersonHandler(index)}
                    changed = {(event) => this.nameChangeHandler(event, element.id)}
                    name = {element.name}
                    nick = {element.nick}
                    key = {element.id}
                    />
                );
            })}
        </div>
        )
    }

    let classes = [];
    if(this.state.persons.length <= 2){ 
      classes.push('red');
    }
    if(this.state.persons.length <= 1){
      classes.push('bold');
    }

    return (
        <div className="App">
          <h1>Hello This is abdullah</h1>
            <p className={classes.join(' ')}><em>This is Italic</em></p>
            <StyledButton
              onClick={this.togglePersonHander}
              style_changeOn={this.state.show_persons}
              > Display Persons </StyledButton>
          {persons}
        </div> 
    );
  }
}

export default App;
