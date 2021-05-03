import React from 'react'

const person = (props) => {
    return(
        <div>
            <p>Hello There {props.name} you are also called { props.nick }</p>
            <p>You are {Math.floor(Math.random() * 30)} years old</p>
            <p>{props.children}</p>
        </div>
    )
}


export default person 