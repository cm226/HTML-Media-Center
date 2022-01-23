import React from 'react';
import { runInAction } from 'mobx'
import {observer} from 'mobx-react'
import { ShoppingContext } from './context'
import {ListWithDelete} from './ListWithDelete'


function MealPicker() {
        const store = React.useContext(ShoppingContext);
        return (
            <div>
                <div>
                    <button onClick={()=>store.dispacher.dispatch('ShowMealList', true)}>All Meals</button>
                </div>
                
                <ListWithDelete listView={store.selectedMeals.listView} onDel={
                    (k)=>{
                        runInAction(()=>{
                            store.dispacher.dispatch("UnSelectMeal",{k : k, v : store.selectedMeals.listView[k].value})
                        })
                    }
                }/>
            </div>
        );
    }   

export default (observer(MealPicker));