import { makeObservable, observable, action, computed } from "mobx"
import {Dispatcher} from '../../../Dispatcher'


interface IlistViewType {
    key : number, 
    value : string,
    checked : boolean
}

class SelectedMeals{

    meals : string[];
    allMeals : string[];

    constructor(){
        makeObservable(this, {
            meals: observable,
            allMeals: observable,
            delete: action,
            add: action,
            listView: computed

        })
        this.meals = [];
        this.allMeals = [];
    }

    register(dis : Dispatcher){
        dis.addListener("SelectMeal", (meal : any)=>{
            this.add(meal);
        });
        dis.addListener("UnSelectMeal", (meal : any)=>{
            this.delete(meal.k);
        });
        dis.addListener("MealsLoaded", (all : string[])=>{
            this.allMeals = all;
        });
        dis.addListener("ClearAll", (all : string[])=>{
            this.meals = [];
        });
        
    }

    delete(index : number){
        
        let meals = this.meals.splice(0);
        meals.splice(index, 1);
        this.meals = meals;
    }

    add(meal : string){
        let meals = this.meals.splice(0);
        meals.push(meal);
        this.meals = meals;
    }

    get listView(){
        let view :IlistViewType[] = [];
        this.meals.forEach((v, i)=>{
            view.push({key:i, value : v , checked : false})
        })
        return view;
    }

}

export default SelectedMeals;