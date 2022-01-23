import React from 'react';
import {observer} from 'mobx-react'
import { ShoppingContext } from './context'
import MealPicker from './MealPicker'
import IngredPicker from './ingredPicker'
import FullMealList from './FullMealList'
import WrokerStatus from './WorkerStatus'
import Manage from './Manage'

import {homeContext} from '../../contexts/homeContext'

import ServerUpdater from './ServerUpdater'
import {views} from './stores/DisplayedViewStore';

let updater : ServerUpdater; // eslint-disable-line @typescript-eslint/no-unused-vars

function Shopping() {
        const home = React.useContext(homeContext);
        const store = React.useContext(ShoppingContext);

        React.useEffect(() => {
            
            navigator.serviceWorker.addEventListener('message', function(event){
                if(event.data === "connected"){
                    store.dispacher.dispatch("ServiceWorkerCallback",  true);
                }
                
            });

            updater = new ServerUpdater(
                store.selectedMeals,
                store.sainsIngred,
                store.dispacher,
                home.urlStore
            );

         }, [store.selectedMeals,
            store.sainsIngred,
            store.dispacher,
            store.workerStatus,
            home.urlStore]);

        let content;
        if(store.displayedView.displayed === views.Main){

            content = <div>
                <WrokerStatus statusStore={store.workerStatus} />
                <img src={home.urlStore.rootURL +"plugins/Shopping_content/logo.png"} alt="Shopping List" />
                <div style={{"width" :"70%", "margin" : "auto"}}>
                    <MealPicker />
                    <hr />
                    <h2>Sainsburys</h2>
                    <IngredPicker dispatcher={store.dispacher} store={store.sainsIngred} filter={store.filter.filtered}/>
                    <hr />
                    <button onClick={()=>store.dispacher.dispatch('ClearAll', {})}>Clear All</button>
                    <button onClick={()=>store.dispacher.dispatch('ShowManage', true)}>Manage</button>
                    <button onClick={()=>store.dispacher.dispatch('Filter', !store.filter.filtered)}>{store.filter.filtered?'Un-Shop Mode' : 'Shop Mode'}</button>
                </div>
            </div>
        } else if (store.displayedView.displayed === views.FullMealList){
            content = <FullMealList />
        } else if (store.displayedView.displayed === views.Manage){
            content= <Manage/>
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