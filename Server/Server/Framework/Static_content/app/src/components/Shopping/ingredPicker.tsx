import React from 'react';
import {observer} from 'mobx-react'
import { ShoppingContext } from './context'
import {ListWithDelete} from './ListWithDelete'

import * as CSS from 'csstype';
import { Dispatcher } from '../../Dispatcher';
import { IListView, IListViewType } from './types/listView';
import { checkIngredMsg } from './types/dispatchMessages/CheckIngred';

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

          let ingredView : IListViewType[] = [...props.store.listView];
          let extrasView : IListViewType[] = [...context.extras.listView];

          if(props.filter){
            const checkedStore = context.checkedIngredStore;
            ingredView = ingredView.filter((el)=>!checkedStore.checked.get(el.id))
            extrasView = extrasView.filter((el)=>!checkedStore.checked.get(el.id))
          }

        function makeInput(){
            if(props.filter)return;

            return <input style={inputStyle} onFocus={(e)=>{e.currentTarget.style.outline = "none";}} 
                    onKeyDown={(e)=>{
                    if(e.keyCode === 13){
                        props.dispatcher.dispatch("AddExtra",e.currentTarget.value);
                        e.currentTarget.value = ""
                    }
                }}
                placeholder="extra"></input>
        }

        return (
            <div>
                {makeInput()}
                <ListWithDelete listView={ingredView} onDel={
                    (k)=>{
                        props.dispatcher.dispatch("RemoveIngred", k)
                    }}
                    onCheck={(k, checked)=>{
                        const msg : checkIngredMsg = {key : k, check : checked};
                        props.dispatcher.dispatch("CheckIngred", msg);
                    }}
                    checkedMap={context.checkedIngredStore.checked} />
                <ListWithDelete listView={extrasView} onDel={
                    (k)=>{
                        console.log("event dispatched");
                        props.dispatcher.dispatch("RemoveExtra", k)
                    }}
                    onCheck={(k, checked)=>{
                        props.dispatcher.dispatch("CheckIngred", {key : k, check : checked});
                    }}
                    checkedMap={context.checkedIngredStore.checked}/>
            </div>
        );
    }   

export default (observer(IngredPicker));