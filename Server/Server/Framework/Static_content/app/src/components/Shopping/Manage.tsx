import React from 'react'
import { observer } from 'mobx-react'
import { ShoppingContext } from './context'
import IngredPicker from './ingredPicker'

import IngredientsStore from './stores/ingredientsStore'

import * as CSS from 'csstype'
import { Dispatcher } from '../../Dispatcher'

const sainsIngred = new IngredientsStore();
const dispacher = new Dispatcher();

function Manage() {
        const store = React.useContext(ShoppingContext);
        const inputEl = React.useRef<HTMLInputElement>(null);

        React.useEffect(()=>{
            sainsIngred.register(dispacher);
        },[])

        const inputStyle : CSS.Properties ={
            height: "40px",
            borderRadius: "10px",
            borderWidth : "0px",
            boxShadow:"inset 1px 1px 4px 0px rgba(0,0,0,0.44)",
            width: "100%",
            fontSize: "1em",
            paddingLeft:"1em"
          };
        
        return (
            <div style={{"width" :"70%", "margin" : "auto"}}>
                <button onClick={()=>store.dispacher.dispatch("ShowManage",false)}>Close</button>
                <h2>Name</h2>
                <input ref={inputEl} style={inputStyle} onFocus={(e)=>{e.currentTarget.style.outline = "none";}} 
                placeholder="extra"></input>
                <hr />
                <h2>Sainsburys</h2>
                <IngredPicker store={sainsIngred} dispatcher={dispacher}/>
                <button onClick={()=>{

                    let mealObj : {
                        name : string | undefined, 
                        aldi : string[],
                        sains : string[]
                    } = {
                        name : "",
                        aldi : [],
                        sains : []
                    };
                    sainsIngred.selectedIngredients.forEach((ingred)=>{
                        mealObj.sains.push(ingred.name);
                    });
                    mealObj.name = inputEl.current?.value;

                    fetch('/plugins/ShoppingList/AddMeal', {
                        method: 'POST', // *GET, POST, PUT, DELETE, etc.
                        mode: 'cors', // no-cors, *cors, same-origin
                        headers: {
                          'Content-Type': 'application/json'
                        },
                        body: JSON.stringify(mealObj) // body data type must match "Content-Type" header
                      }).then((res)=>res.text().then(
                          (text)=>{
                            if(text.trim() === "OK"){
                                alert("Meal Added successfully, refresh to see new meals")
                            } else{
                                alert("Failed to insert meal, see error console.")
                            }
                          })
                    );
                }}>Finish</button>
            </div>
        );
    }   

export default (observer(Manage));