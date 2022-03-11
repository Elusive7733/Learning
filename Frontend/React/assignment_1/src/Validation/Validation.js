import React from 'react';
import './Validation.css';

const validation = (props) => {
    let validation_msg = null;
    if(props.length <= 5){
        validation_msg = "Length Too short"
    }
    else if(props.length >= 15){ 
        validation_msg = "Length Too Long"
    }
    return(
        <div className="Validate">
            <p>{validation_msg}</p>

        </div>
    )
}


export default validation;
