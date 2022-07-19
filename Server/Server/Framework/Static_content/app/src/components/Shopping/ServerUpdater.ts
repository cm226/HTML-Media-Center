import IngredientsStore from './stores/ingredientsStore'
import {Dispatcher} from '../../Dispatcher'

import RootURLStore from '../../stores/RootURLStore'

import {autorun} from 'mobx'
import { mealList } from './types/meal'
import { Extra } from './types/extras'
import ExtrasStore from './stores/extrasStore'

class ServerUpdater{

    private ingredStore : IngredientsStore;
    private extrasStore : ExtrasStore;

    constructor( 
        ingredStore : IngredientsStore,
        extrasStore : ExtrasStore,
        dispacher : Dispatcher,
        urlStore : RootURLStore
    ){
        this.extrasStore = extrasStore ;
        this.ingredStore = ingredStore;

        fetch(urlStore.rootURL + 'plugins/ShoppingList').then((res)=>{
            res.json().then((meals : mealList)=>{


                dispacher.dispatch("ingredsLoaded",meals);

                let init = true; // flag for first time running autorun
                autorun(() => {
                    console.log("server Updated");
                    this.updateServer(init)
                    init = false;
                })
            })
        });

        fetch(urlStore.rootURL + 'plugins/ShoppingList/GetExtras').then((res)=>{
            res.json().then((extras : {extras : Extra[]})=>{
                dispacher.dispatch("ExtrasLoaded", extras.extras);
            });
        });

    }

    private updateSelected(init : boolean){
        let state = this.ingredStore.toJson();

        if(init) return;

        fetch('/plugins/ShoppingList/UpdateSelected', {
            method: 'POST',
            headers: {
              'Content-Type': 'application/json'
            },
            body: JSON.stringify(state)
          });
    }

    private updateExtras(init : boolean){

        const extras = this.extrasStore._extras;
        const body = JSON.stringify({extras});

        if(init) return;

        fetch('/plugins/ShoppingList/UpdateExtras', {
            method: 'POST',
            headers: {
              'Content-Type': 'application/json'
            },
            body: body
          });


    }

    private updateServer(init : boolean){
        this.updateSelected(init);
        this.updateExtras(init);
    }

}

export default ServerUpdater;