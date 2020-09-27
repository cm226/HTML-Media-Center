import React from 'react';
import {observer} from 'mobx-react'
import { ShoppingContext } from './context'
import {ListWithDelete, IListView} from './ListWithDelete'

import * as CSS from 'csstype';


interface IngredProps{
    store : IListView
    storeName : string
};

function IngredPicker(props : IngredProps) {
        const inputStyle : CSS.Properties ={
            height: "40px",
            borderRadius: "10px",
            borderWidth : "0px",
            boxShadow:"inset 1px 1px 4px 0px rgba(0,0,0,0.44)",
            width: "100%",
            fontSize: "1em",
            paddingLeft:"1em"
          };
          let context = React.useContext(ShoppingContext);
        return (
            <div>
                <input style={inputStyle} onFocus={(e)=>{e.currentTarget.style.outline = "none";}} 
                    onKeyDown={(e)=>{
                    if(e.keyCode === 13){
                        context.dispacher.dispatch(props.storeName+"_addExtraIngred",{
                            meal : 'extra',
                            ingred : e.currentTarget.value
                        } );
                        e.currentTarget.value = ""
                    }
                }}
                placeholder="extra"></input>
                <ListWithDelete store={props.store} onDel={
                    (k)=>{
                        context.dispacher.dispatch(props.storeName+"_delIngred", k)
                    }
                }/>
            </div>
        );
    }   

export default (observer(IngredPicker));