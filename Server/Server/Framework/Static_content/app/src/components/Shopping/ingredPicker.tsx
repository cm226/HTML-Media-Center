import React from 'react';
import {observer} from 'mobx-react'
import { ShoppingContext } from './context'
import {ListWithDelete, IListViewType} from './ListWithDelete'

import * as CSS from 'csstype';
import { Dispatcher } from '../../Dispatcher';

interface IListView{
    listView : IListViewType[]
}

interface IngredProps{
    store : IListView
    dispatcher : Dispatcher
    filter? : boolean
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

          let listView : IListViewType[] = [...props.store.listView];
          if(props.filter){
            listView  = [];
            props.store.listView.forEach((el, i)=>{
                if(!el.checked){
                    listView.push(el);
                }
              })
          }

        function makeInput(){
            if(props.filter)return;

            return <input style={inputStyle} onFocus={(e)=>{e.currentTarget.style.outline = "none";}} 
                    onKeyDown={(e)=>{
                    if(e.keyCode === 13){
                        context.dispacher.dispatch("addingred",{
                            meal : 'extra',
                            ingred : e.currentTarget.value
                        } );
                        e.currentTarget.value = ""
                    }
                }}
                placeholder="extra"></input>
        }

        return (
            <div>
                {makeInput()}
                <ListWithDelete listView={listView} onDel={
                    (k)=>{
                        context.dispacher.dispatch("delIngred", k)
                    }}
                    onCheck={(k, checked)=>{
                        context.dispacher.dispatch("CheckIngred", {key : k, check : checked});
                    }}/>
            </div>
        );
    }   

export default (observer(IngredPicker));