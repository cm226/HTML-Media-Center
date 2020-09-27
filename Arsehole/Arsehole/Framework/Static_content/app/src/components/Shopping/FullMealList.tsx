import React from 'react';
import {observer} from 'mobx-react'
import { ShoppingContext } from './context'

function FullMealList() {
        const store = React.useContext(ShoppingContext);
        return (
            <div>
                <button onClick={()=>store.fullMealList.Display(false)}>Close</button>
                <ul>
                    {store.selectedMeals.allMeals.map(
                        (meal, index)=> <li key={index} onClick={
                            ()=>{
                                store.dispacher.dispatch('SelectMeal', meal)
                                store.dispacher.dispatch('ShowMealList', false)
                            }
                        }>{meal}</li>
                    )}
                </ul>
            </div>
        );
    }   

export default (observer(FullMealList));