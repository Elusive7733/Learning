import React from 'react'
import './Validation.css'

const validation = (props) => {
    if(props.length <= 5){
        return(
            <div className="Short">
                <p>Length Too short</p>
            </div>
        );
    }
    else if(props.length >= 15){
        return(
            <div className="Long">
                <p>Length Too Long</p>
            </div>
        );
    }
    else{
        return null;
    }
}


export default validation;
