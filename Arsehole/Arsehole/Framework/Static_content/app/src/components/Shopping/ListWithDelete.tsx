import React from 'react';
import {observer} from 'mobx-react'

import * as CSS from 'csstype'

interface ListViewType{
    key : number, 
    value : string
}

export interface IListView{
    listView : ListViewType[],
}

interface ListProps{
    store : IListView,
    onDel : (id : number )=>void
}

@observer
export class ListWithDelete extends React.Component<ListProps>{

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
                {this.props.store.listView.map((el)=>
                    <tr key={el.key}>
                        <td><input type="checkbox" id="cbox" /></td>
                        <td>{el.value}</td>
                        <td>
                            <button style={buttonStyle} onClick={()=>{this.props.onDel(el.key)}}>
                                <img alt="" style={imgStyle} src="https://image.flaticon.com/icons/png/128/579/579006.png" />
                            </button>
                        </td>
                        
                    </tr>
                )}
                </tbody>
            </table>
        );
    }
}   
