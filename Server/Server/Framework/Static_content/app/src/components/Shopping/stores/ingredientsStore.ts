import { makeObservable, observable, action, computed } from "mobx"
import { produce } from "immer";
import { Dispatcher } from '../../../Dispatcher'
import { IListView } from "../types/listView";
import { mealList } from "../types/meal";

interface SelectedIngred {
    id : string,
    name : string, 
    meal : string
}


export class IngredientsStore implements IListView{

    public _model : mealList = {};

    constructor() {
        makeObservable(this, {
            selectedIngredients: computed,
            _model : observable,
            removeIngredients: action,
            removeIngredient: action,
            addAllInMeal: action,
            deleteAllFromMeal: action,
            clearAll: action
        });
    }
    get listView (){
        return this.selectedIngredients;
    }

    toJson() { 

        // mobX needs to see us access these.....
        for(const meal in this._model){
            const m = this._model[meal];
            const s = m.selected;
            for(const ingred of m.ingreds){
                const s2 = ingred.selected;
            }
        }
        return this._model;
    }

    get selectedIngredients () {
        const selectedIngreds : SelectedIngred[] = [];
        for (const meal in this._model) {
            const ingreds = this._model[meal]
            for(const ingredient of ingreds.ingreds) {
                if(ingredient.selected)
                    selectedIngreds.push({id : ingredient.id, name : ingredient.ingred, meal : meal});
            }

        }
        return selectedIngreds;
    }

    register(dis : Dispatcher){
        dis.addListener("AddMeal", (meal : string)=>{
            this.addAllInMeal(meal);
        });

        dis.addListener("RemoveMeal", (meal : string)=>{
            this.deleteAllFromMeal(meal);
        });

        dis.addListener("RemoveIngred", (ingredientID:string)=>{
            this.removeIngredient(ingredientID);
        })

        dis.addListener("ingredsLoaded", (ingreds : mealList)=>{
            this._model = ingreds;
        });

        dis.addListener("ClearAll", ()=>{
            this.clearAll();
        });
        
    }

    removeIngredients(keys : string[]) {
        for(const key of keys){
            this.removeIngredient(key);
        }
    }

    removeIngredient(key : string){
        this._model = produce(this._model, recipe =>{
            const findIngred = (id : string) =>{
                for(const meal in recipe){
                    const ingreds = recipe[meal];
                    for(const ingred of ingreds.ingreds){
                        if(ingred.id === id) return ingred;
                    }
                }
                return null;
            }
            const ingred = findIngred(key);
            if(ingred !== null)
                ingred.selected = false;
        });
    }

    addAllInMeal(mealName: string){
        let meal = this._model[mealName];
        meal.selected = true;
        meal.ingreds.forEach((ingred)=>ingred.selected = true);
    }

    deleteAllFromMeal(mealName : string) {
        let meal = this._model[mealName];
        meal.selected = false;
        meal.ingreds.forEach((ingred)=>ingred.selected = false);
    }

    clearAll(){
        for (const mealName in this._model){
            this.deleteAllFromMeal(mealName);
        }
    }
}

export default IngredientsStore;