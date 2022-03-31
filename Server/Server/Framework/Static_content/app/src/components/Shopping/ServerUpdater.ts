import SelectedMeal from './stores/selectedMeals'
import IngredientsStore from './stores/ingredientsStore'
import {Dispatcher} from '../../Dispatcher'

import RootURLStore from '../../stores/RootURLStore'

import {autorun} from 'mobx'

interface IExtras {
    extras:
        {
            store : string,
            ingred: string
        }[]
};

class ServerUpdater{

    private meal : SelectedMeal; 
    private ingredStore : IngredientsStore;


    constructor(
        meal : SelectedMeal, 
        ingredStore : IngredientsStore,
        dispacher : Dispatcher,
        urlStore : RootURLStore
    ){
        this.meal = meal ;
        this.ingredStore = ingredStore;

        fetch(urlStore.rootURL + 'plugins/ShoppingList').then((res)=>{
            res.json().then((json : object)=>{

                let meals :string[] = [];
                let sainsmap = new Map<string, {name : string, id : number}[]>();

                let selectedMeals : string[] = [];
                for (const [meal, value] of Object.entries(json)) {
                    let sainsIngreds : {name : string, id : number, sel : boolean}[] = [];
                    meals.push(meal);

                    if(value.selected === 1){
                        selectedMeals.push(meal);
                    }

                    value.ingreds.forEach((ingred : any)=>{
                        let sel = ingred.selected === "1" ? true : false;
                        sainsIngreds.push({name : ingred.ingred, id : ingred.id, sel : sel});
                    });

                    if(sainsIngreds.length !== 0){
                        sainsmap.set(meal, sainsIngreds);
                    }
                }

                dispacher.dispatch("MealsLoaded", meals);
                selectedMeals.forEach((selected)=>{
                    dispacher.dispatch("SelectMeal", selected);
                });

                dispacher.dispatch("ingredsLoaded",sainsmap);

                let init = true; // flag for first time running autorun
                autorun(() => {
                    this.updateServer(init)
                    init = false;
                })
            })
        });

        fetch(urlStore.rootURL + 'plugins/ShoppingList/GetExtras').then((res)=>{
            res.json().then((json : IExtras)=>{
                json.extras.forEach((val)=>{
                    this.ingredStore.addExtra(val.ingred, 'extra');
                });
            });
        });

    }

    private updateSelected(init : boolean){
        let state : any = {};
        this.meal.allMeals.forEach((meal)=>{

            let mealState : any = {
                selected : false,
                ingreds : []
            };
            if(this.meal.meals.indexOf(meal) !== -1){
                mealState.selected = "1";
            }

            this.ingredStore.ingredients.forEach((val)=>{
                if(val.meal !== 'extra' && val.meal === meal){
                    mealState.ingreds.push({
                        id : val.ingredID,
                        ingred : val.ingred,
                        store : 'sainsbury',
                        selected : "1"
                    })
                }
            })

            state[meal] = mealState;

        });

        if(init) return;

        fetch('/plugins/ShoppingList/UpdateSelected', {
            method: 'POST', // *GET, POST, PUT, DELETE, etc.
            mode: 'cors', // no-cors, *cors, same-origin
            headers: {
              'Content-Type': 'application/json'
            },
            body: JSON.stringify(state) // body data type must match "Content-Type" header
          });
    }

    private updateExtras(init : boolean){
        let extras : IExtras = {
            extras : []
        };

        this.ingredStore.ingredients.forEach((val)=>{
            if(val.meal === 'extra'){
                extras.extras.push({store : 'Sainsbury', ingred : val.ingred});
            }
        });

        if(init) return;

        fetch('/plugins/ShoppingList/UpdateExtras', {
            method: 'POST', // *GET, POST, PUT, DELETE, etc.
            mode: 'cors', // no-cors, *cors, same-origin
            headers: {
              'Content-Type': 'application/json'
            },
            body: JSON.stringify(extras) // body data type must match "Content-Type" header
          });


    }

    private updateServer(init : boolean){
        this.updateSelected(init);
        this.updateExtras(init);
    }

}

export default ServerUpdater;