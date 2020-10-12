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
            updater = new ServerUpdater(
                store.selectedMeals,
                store.aldiIngreds,
                store.sainsIngred,
                store.dispacher,
                home.urlStore
            );

            // install our service worker
            if ('serviceWorker' in navigator) {
                navigator.serviceWorker.register(home.urlStore.rootURL +'/plugins/shopping-worker.js');

                navigator.serviceWorker.addEventListener('message', function(event){
                    if(event.data === "connected"){
                        store.dispacher.dispatch("ServiceWorkerCallback", {connected : true});
                    }
                    
                });
            }

            navigator.serviceWorker.ready.then(function(swRegistration) {
                return swRegistration.sync.register('sync');
            });

         }, [store.selectedMeals,
            store.aldiIngreds,
            store.sainsIngred,
            store.dispacher,
            store.workerStatus,
            home.urlStore]);

        let content;
        if(store.displayedView.displayed === views.Main){

            content = <div style={{"width" :"70%", "margin" : "auto"}}>
                <img src={home.urlStore.rootURL +"plugins/Shopping_content/logo.png"} alt="Shopping List" />
                <MealPicker />
                <hr />
                <h2>Aldi</h2>
                <IngredPicker dispatcher={store.dispacher} store={store.aldiIngreds} storeName="aldi" filter={store.filter.filtered}/>
                <hr />
                <h2>Sainsburys</h2>
                <IngredPicker dispatcher={store.dispacher} store={store.sainsIngred} storeName="sains" filter={store.filter.filtered}/>
                <hr />
                <button onClick={()=>store.dispacher.dispatch('ClearAll', {})}>Clear All</button>
                <button onClick={()=>store.dispacher.dispatch('ShowManage', true)}>Manage</button>
                <button onClick={()=>store.dispacher.dispatch('Filter', !store.filter.filtered)}>{store.filter.filtered?'Un-Shop Mode' : 'Shop Mode'}</button>
                <WrokerStatus statusStore={store.workerStatus} />
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