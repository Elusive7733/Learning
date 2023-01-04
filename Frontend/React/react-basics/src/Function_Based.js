import React, { useState } from 'react';
//using react hooks to add functionality to functional components
import './App.css';
import Person from './Person/Person';


const app = (props) => {
    // use state always returns 2 elements
    // the first element is our current state
    // the second element is a funtion that allows us to update that state
    const [current_state, set_Person_state] = useState({  
        persons: [
          {name: "Abdullah", nick: "Abduls"},
          {name: "Bruce", nick: "Batman"},
          {name: "Elusive", nick: "Elu" },
        ]
      })

      const switchNameHandler = () => {
        // let temp_persons = current_state
        // let temp = temp_persons.persons[2]
        // temp_persons.persons[2] = temp_persons.persons[1]
        // temp_persons.persons[1] = temp_persons.persons[0]
        // temp_persons.persons[0] = temp
    
        set_Person_state({  
            persons: [
              {name: "Bruce", nick: "Batman"},
              {name: "Abdullah", nick: "Abduls"},
              {name: "Elusive", nick: "Elu" },
            ]
          })
      }
        
    //no render method in functional components
    return (
        <div className="App">
        <h1>Hello This is abdullah
            <p><em>This is Italic</em></p>
            <button onClick={switchNameHandler}>Switch Name</button>
            <Person name={current_state.persons[0].name} nick={current_state.persons[0].nick} /> <br></br>
            <Person name={current_state.persons[1].name} nick={current_state.persons[1].nick} >You like Sekiro</Person> <br></br>
            <Person name={current_state.persons[2].name} nick={current_state.persons[2].nick}/> <br></br>
        </h1>
        </div> 
    );
}

export default app; //lowercase a because of funtional component
