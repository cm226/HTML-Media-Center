import React from 'react';

interface IProps{
    value : number,
    day_change : number,
    gain_loss : number
}

function Summary(props : IProps) {

    return (
        <div className="row header">
            <div className="col-md-6 col-xs-6">
                <div className="row">
                    <div className="col-md-6 col-xs-6"><h1 id="current_value">Value:</h1></div>
                    <div className="col-md-6 col-xs-6"><h1 className="value_total">{props.value}</h1></div>
                </div>
            </div>
            <div className="col-md-6 col-xs-6">
                    <div className="row">
                        <div className="col-md-6 col-xs-6"> <h2 id="day_change">Day Change:</h2> </div>
                        <div className="col-md-6 col-xs-6"> <h2 className="day_change_total">{props.day_change}</h2></div>
                    </div>
                    <div className="row">
                        <div className="col-md-6 col-xs-6"> <h2 id="gain_loss">Gain Loss:</h2></div>
                        <div className="col-md-6 col-xs-6"> <h2 className="gain_total">{props.gain_loss}</h2></div>
                    </div> 
            </div>
        </div>
    );
}

export default Summary;