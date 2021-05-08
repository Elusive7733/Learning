import React from 'react';


const character = (props) => {
    const style = {
        display: "inline-block",
        padding: "16px",
        textAlign: "center",
        margin: "16px",
        border: "1px solid"
    };

    return(
        <div style={style} onClick={props.clicked}>
            <strong>{props.letter}</strong>
        </div>
    );
}

export default character;