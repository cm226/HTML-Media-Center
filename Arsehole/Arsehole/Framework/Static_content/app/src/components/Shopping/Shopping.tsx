import React from 'react';
import {observer} from 'mobx-react'
import { ShoppingContext } from './context'
import MealPicker from './MealPicker'
import IngredPicker from './ingredPicker'
import FullMealList from './FullMealList'

import {homeContext} from '../../contexts/homeContext'

import ServerUpdater from './ServerUpdater'

let updater : ServerUpdater; // eslint-disable-line @typescript-eslint/no-unused-vars

function Shopping() {
        const home = React.useContext(homeContext);
        const store = React.useContext(ShoppingContext);

        React.useEffect(() => {
            updater = new ServerUpdater(
                store.selectedMeals,
                store.aldiIngreds,
                store.sainsIngred,
                store.dispacher,
                home.urlStore
            );
         }, [store.selectedMeals,
            store.aldiIngreds,
            store.sainsIngred,
            store.dispacher,
            home.urlStore]);

        let content;
        if(!store.fullMealList.displayed){

            content = <div style={{"width" :"70%", "margin" : "auto"}}>
                <img src={home.urlStore.rootURL +"plugins/Shopping_content/logo.png"} alt="Shopping List" />
                <MealPicker />
                <hr />
                <h2>Aldi</h2>
                <IngredPicker store={store.aldiIngreds} storeName="aldi"/>
                <hr />
                <h2>Sainsburys</h2>
                <IngredPicker store={store.sainsIngred} storeName="sains"/>
                <hr />
            </div>
        } else {
            content = <FullMealList />
        }


        return (
            <ShoppingContext.Provider value={store}>
            <div>
                {content}
            </div>
            </ShoppingContext.Provider>
        );
    }   

export default (observer(Shopping));