import React from 'react';
import { runInAction } from 'mobx'
import {observer} from 'mobx-react'
import { ShoppingContext } from './context'

import * as CSS from 'csstype';

function FullMealList() {
        const store = React.useContext(ShoppingContext);

        const div_container : CSS.Properties ={
            width: "80%",
            margin: "auto"
          };

        const ul_style : CSS.Properties = {
            listStyleType : "none",
            padding: "0px"
        }

        const li_style : CSS.Properties = {
            padding:"10px"
        }

        return (
            <div style={div_container}>
                <button onClick={()=>store.dispacher.dispatch('ShowMealList', false)}>Close</button>
                <ul style={ul_style}>
                    {Object.keys(store.sainsIngred._model).map(
                        (meal, index)=> <li key={index} onClick={
                            (e)=>{
                                e.currentTarget.style.backgroundColor = "#bfbfbf";
                                runInAction(()=>{
                                    store.dispacher.dispatch('AddMeal', meal);
                                })
                                
                                window.setTimeout(()=>{
                                    store.dispacher.dispatch('ShowMealList', false)
                                }, 50);
                            }
                        } style={li_style}>{meal}</li>
                    )}
                </ul>
            </div>
        );
    }   

export default (observer(FullMealList));