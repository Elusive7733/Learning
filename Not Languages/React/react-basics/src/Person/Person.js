import React from 'react'
import Radium from 'radium'
import './Person.css'

const person = (props) => {
    const style = {
        '@media (min-width: 500px)': {width: '450px'},
        ':hover': {     
            backgroundColor: 'Azure',
            transition: 'transform 0.5s',
            boxShadow: '0px 0px 5px rgb(190, 255, 255), inset 0px 0px 5px rgb(190, 255, 255)',
            transform: 'scale(1.08)',
        }
    } 

    return(
        <div className="Person" style={style} onClick={props.click}>
            <p>Hello There {props.name} you are also called { props.nick }</p>
            <p>You are {Math.floor(Math.random() * 30)} years old</p>
            <p>{props.children}</p>
            <input type="text" onChange={props.changed} value={props.name}></input>
        </div>
    )
}


export default Radium(person); 