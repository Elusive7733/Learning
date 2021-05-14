import React from 'react'
// import Radium from 'radium'
// import './Person.css'
import styled from 'styled-components';

const Divstyle = styled.div`
width: 60%;
margin: 16px auto;
border: 1px solid grey;
box-shadow: 0 2px 3px #ccc;
padding: 16px;
text-align: center;
cursor: pointer;

@media (min-width: 500px) { width: 450px;}
&:hover{     
    backgroundColor: Azure;
    transition: transform 0.5s;
    box-shadow: 0px 0px 5px rgb(190, 255, 255), inset 0px 0px 5px rgb(190, 255, 255);
    transform: scale(1.08);
}
`

const person = (props) => {
    return(
        // <div className="Person" style={style} onClick={props.click}>
        <Divstyle>
            <p onClick={props.click}>Hello There {props.name} you are also called { props.nick }</p>
            <p>You are {Math.floor(Math.random() * 30)} years old</p>
            <p>{props.children}</p>
            <input type="text" onChange={props.changed} value={props.name}></input>
        </Divstyle>
    )
}


export default person; 