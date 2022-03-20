import React from 'react';
import {observer} from 'mobx-react'

import * as CSS from 'csstype'

export interface IListViewType{
    key : number, 
    value : string,
    checked : boolean
}


interface ListProps{
    listView : IListViewType[],
    onDel : (id : number )=>void
    onCheck? : (id : number, checked : boolean)=>void
}

@observer
export class ListWithDelete extends React.Component<ListProps>{

    makeCheckbox(checked : boolean, key : number){
        
        if(!this.props.onCheck)return;
        const checkboxStyle : CSS.Properties = {
            height : "22px",
            width : "22px"
        }

        return <input style={checkboxStyle}
        type="checkbox"
        id="cbox"
        defaultChecked={checked} 
        onChange={(e : any)=>{
            if(this.props.onCheck)
                this.props.onCheck(key, e.target.checked) 
        }} />;
    }

    render(){
        const imgStyle : CSS.Properties ={
            height: "20px",
            width: "20px",
            cursor: "pointer"
        };

        const buttonStyle : CSS.Properties = {
            background: "inherit",
            border: "0",
            margin:"auto",
            
        };

        const tableBodyStyle : CSS.Properties = {
            textAlign: "left",
            color: "#3d3d3d",
            fontWeight: "bold",
            paddingTop : "20px",
            paddingBottom : "20px"
        }

        const tableStyle : CSS.Properties = {
            paddingTop : "20px",
            paddingBottom : "20px"
        }

        

        return (
            <table style={tableStyle}>
                <tbody style={tableBodyStyle}>
                {this.props.listView.map((el)=>
                    <tr key={el.key}>
                        <td>{this.makeCheckbox(el.checked, el.key)}</td>
                        <td>{el.value}</td>
                        <td>
                            <button style={buttonStyle} onClick={()=>{this.props.onDel(el.key)}}>
                                <img alt="" style={imgStyle} src="/assets/shopping/red-cross-icon.png" />
                            </button>
                        </td>
                        
                    </tr>
                )}
                </tbody>
            </table>
        );
    }
}   
