import React from 'react';

import * as CSS from 'csstype';

interface row{
    row : string[]
}

interface IProps{
    headers : string[],
    rows : row[];
}

function QueryResultsView(props : IProps){
    
    const header : CSS.Properties ={
        gridColumn : "3 / span 1 ",
        gridRow : "1"
    };

    if(props.headers.length === 0){
        props.headers.push("QueryHeaders");
        props.rows.push({row:["Results"]});
    }
    
    return <div>
        <table>
            {props.headers.map(header=><th>{header}</th>)}
            <tbody>
{props.rows.map(row=><tr>{row.row.map(element=><td>element</td>)}</tr>)}
            </tbody>
        </table>
    </div>;
}

export default QueryResultsView;