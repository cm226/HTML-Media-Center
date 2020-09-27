import SelectedMeal from './stores/selectedMeals'
import IngredientsStore from './stores/ingredientsStore'
import {Dispatcher} from '../../Dispatcher'

import RootURLStore from '../../stores/RootURLStore'

import {observe} from 'mobx'

class ServerUpdater{

    private meal : SelectedMeal; 
    private aldiIngrd : IngredientsStore;
    private sainsIngred : IngredientsStore;
    private urlStore : RootURLStore;


    constructor(
        meal : SelectedMeal, 
        aldiIngrd : IngredientsStore,
        sainsIngred : IngredientsStore,
        dispacher : Dispatcher,
        urlStore : RootURLStore
    ){
        this.urlStore = urlStore;
        fetch(urlStore.rootURL + 'plugins/ShoppingList').then((res)=>{
            res.json().then((json : object)=>{

                let meals :string[] = [];
                let aldiMap = new Map<string, {name : string, id : number}[]>();
                let sainsmap = new Map<string, {name : string, id : number}[]>();

                let selectedMeals : string[] = [];
                for (const [meal, value] of Object.entries(json)) {
                    let aldiIngred : {name : string, id : number, sel : boolean}[] = [];
                    let sainsIngreds : {name : string, id : number, sel : boolean}[] = [];
                    meals.push(meal);

                    if(value.selected === 1){
                        selectedMeals.push(meal);
                    }

                    value.ingreds.forEach((ingred : any)=>{
                        let sel = ingred.selected === "1" ? true : false;
                        if(ingred.store==='Aldi'){
                            aldiIngred.push({name : ingred.ingred, id : ingred.id, sel : sel});
                        } else{
                            sainsIngreds.push({name : ingred.ingred, id : ingred.id, sel : sel});
                        }
                    });
                    
                    if(aldiIngred.length !== 0){
                        aldiMap.set(meal, aldiIngred);
                    }

                    if(sainsIngreds.length !== 0){
                        sainsmap.set(meal, sainsIngreds);
                    }
                }

                dispacher.dispatch("MealsLoaded", meals);
                selectedMeals.forEach((selected)=>{
                    dispacher.dispatch("SelectMeal", selected);
                });

                dispacher.dispatch("aldi_ingredsLoaded",aldiMap);
                dispacher.dispatch("sains_ingredsLoaded",sainsmap);

                observe(meal.meals, ()=>{this.updateServer()});
                observe(aldiIngrd.ingredients, ()=>{this.updateServer()});
                observe(sainsIngred.ingredients, ()=>{this.updateServer()});
            })
        });

        this.meal = meal ;
        this.aldiIngrd = aldiIngrd;
        this.sainsIngred = sainsIngred;
        

    }

    private updateServer(){
        let state : any = {};
        this.meal.allMeals.forEach((meal)=>{

            let mealState : any = {
                selected : false,
                ingreds : []
            };
            if(this.meal.meals.indexOf(meal) !== -1){
                mealState.selected = "1";
            }

            this.aldiIngrd.ingredients.forEach((val)=>{
                if(val.meal !== 'extra' && val.meal === meal){
                    mealState.ingreds.push({
                        id : val.ingredID,
                        ingred : val.ingred,
                        store : 'aldi',
                        selected : "1"
                    })
                }
            })

            this.sainsIngred.ingredients.forEach((val)=>{
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

        fetch('/plugins/ShoppingList/UpdateSelected', {
            method: 'POST', // *GET, POST, PUT, DELETE, etc.
            mode: 'cors', // no-cors, *cors, same-origin
            headers: {
              'Content-Type': 'application/json'
            },
            body: JSON.stringify(state) // body data type must match "Content-Type" header
          });
    }

}

export default ServerUpdater;