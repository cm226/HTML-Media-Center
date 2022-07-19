import React from 'react';
import { runInAction } from 'mobx'
import {observer} from 'mobx-react'
import { ShoppingContext } from './context'
import {ListWithDelete} from './ListWithDelete'
import { SelectedMealListView } from './views/SelectedMealListView';


function MealPicker() {
        const store = React.useContext(ShoppingContext);
        return (
            <div>
                <div>
                    <button onClick={()=>store.dispacher.dispatch('ShowMealList', true)}>All Meals</button>
                </div>
                
                <ListWithDelete listView={new SelectedMealListView(store.sainsIngred).listView} onDel={
                    (name)=>{
                        runInAction(()=>{
                            store.dispacher.dispatch("RemoveMeal",name)
                        })
                    }
                }
                checkedMap={new Map()}/>
            </div>
        );
    }   

export default (observer(MealPicker));