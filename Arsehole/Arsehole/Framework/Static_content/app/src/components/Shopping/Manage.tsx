import React from 'react'
import { observer } from 'mobx-react'
import { ShoppingContext } from './context'
import IngredPicker from './ingredPicker'

import IngredientsStore from './stores/ingredientsStore'

import * as CSS from 'csstype'

const sainsIngred = new IngredientsStore();
const aldiIngred = new IngredientsStore();


function Manage() {
        const store = React.useContext(ShoppingContext);
        const inputEl = React.useRef<HTMLInputElement>(null);

        React.useEffect(()=>{
            sainsIngred.register(store.dispacher,"manage_sains");
            aldiIngred.register(store.dispacher, "manage_aldi");
            // eslint-disable-next-line
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
                <h2>Aldi</h2>
                <IngredPicker store={aldiIngred} dispatcher={store.dispacher} storeName="manage_aldi"/>
                <hr />
                <h2>Sainsburys</h2>
                <IngredPicker store={sainsIngred} dispatcher={store.dispacher} storeName="manage_sains"/>
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
                    aldiIngred.ingredients.forEach((ingred)=>{
                        mealObj.aldi.push(ingred.ingred);
                    });
                    sainsIngred.ingredients.forEach((ingred)=>{
                        mealObj.sains.push(ingred.ingred);
                    });
                    mealObj.name = inputEl.current?.value;

                    fetch('/plugins/ShoppingList/AddMeal', {
                        method: 'POST', // *GET, POST, PUT, DELETE, etc.
                        mode: 'cors', // no-cors, *cors, same-origin
                        headers: {
                          'Content-Type': 'application/json'
                        },
                        body: JSON.stringify(mealObj) // body data type must match "Content-Type" header
                      });
                    


                }}>Add</button>
            </div>
        );
    }   

export default (observer(Manage));