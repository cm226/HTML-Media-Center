import React from 'react';
import {observer} from 'mobx-react'

import * as CSS from 'csstype'
import { IListViewType } from './types/listView';

interface ListProps{
    listView : IListViewType[],
    onDel : (id : string )=>void
    onCheck? : (id : string, checked : boolean)=>void,
    checkedMap : Map<string, boolean>
}

@observer
export class ListWithDelete extends React.Component<ListProps>{

    makeCheckbox(checked : boolean, key : string){
        
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
                    <tr key={el.id}>
                        <td>{this.makeCheckbox(this.props.checkedMap.get(el.id) || false, el.id)}</td>
                        <td>{el.name}({(el as any).meal || 'extra'})</td>
                        <td>
                            <button style={buttonStyle} onClick={()=>{console.log("delete clicked"); this.props.onDel(el.id)}}>
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
