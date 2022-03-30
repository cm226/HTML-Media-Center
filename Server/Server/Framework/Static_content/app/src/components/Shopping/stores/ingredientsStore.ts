import { makeObservable, observable, action, computed } from "mobx"
import {Dispatcher} from '../../../Dispatcher'

export interface IingredMeal{
    ingredID : number,
    ingred : string,
    meal : string,
    checked : boolean
};

interface IlistViewType {
    key : number, 
    value : string,
    checked : boolean
}


export class IngredientsStore{

    ingredients : Map<number, IingredMeal>;
    ingredUpdatded : number;

    private mealIngredMap : Map<string, {name:string, id:number}[]>;
    private _nextKey : number;

    constructor() {
        makeObservable(this, {
            ingredients: observable,
            ingredUpdatded: observable,
            checkIngredient: action,
            delete: action,
            addExtra: action,
            addAll: action,
            clearAll: action,
            deleteAllFromMeal: action,
            listView: computed

        })
        this.ingredients = new Map<number, IingredMeal>();
        this._nextKey = 0;
        this.ingredUpdatded = 0
        
        this.mealIngredMap = new Map<string, {name:string, id:number}[]>();
    }

    register(dis : Dispatcher){
        dis.addListener("SelectMeal", (meal : any)=>{
            let ingreds = this.mealIngredMap.get(meal);
            if(ingreds){
                this.addAll(ingreds, meal);
            }
        });

        dis.addListener("delIngred", (k:number)=>{
            this.delete(k);
        })

        dis.addListener("addingred", (k : any)=>{
            this.addExtra(k.ingred, k.meal);
        });

        dis.addListener("ingredsLoaded", (ingreds : Map<string, {name:string, id:number, sel : boolean}[]>)=>{
            
            ingreds.forEach((ingreds, meal)=>{
                let selectedIngreds :{name:string, id:number}[] = [];
                ingreds.forEach((ingred)=>{
                    if(ingred.sel){
                        selectedIngreds.push({name : ingred.name, id : ingred.id});
                    }
                });
                this.addAll(selectedIngreds, meal);
            });
            this.mealIngredMap = ingreds;
        });

        dis.addListener("UnSelectMeal", (meal : any)=>{
            this.deleteAllFromMeal(meal.v);
        });

        dis.addListener("ClearAll", ()=>{
            this.clearAll();
        });

        dis.addListener("CheckIngred", (ingred : {key : number, check : boolean})=>{
            this.checkIngredient(ingred.key, ingred.check);
        });
        
    }

    findIngredFromID(ingredID : number, meal : string){
        let mealIngreds = this.mealIngredMap.get(meal);
        if(mealIngreds){
            let ingred = mealIngreds.find(ingred=>ingred.id===ingredID);
            if(ingred){
                return ingred.name
            }
        }
        return undefined;
    }

    checkIngredient(key : number, check : boolean){
        
        let ingred = this.ingredients.get(key);
        if(ingred) ingred.checked = check;
    }

    delete(key : number){
        this.ingredients.delete(key);
    }

    addExtra(extra : string, meal: string){
        
        this._nextKey += 1;
        this.ingredients.set(this._nextKey, {ingred : extra, ingredID : 999, meal : meal, checked : false});
    }

    addAll(ingreds : {name:string, id:number}[], meal: string){
        
        this.ingredUpdatded += 1
        for(const ingred of ingreds){
            this._nextKey += 1;
            this.ingredients.set(this._nextKey, 
                {ingred : ingred.name, ingredID : ingred.id, meal : meal, checked : false}
            );
        };
        
    }

    clearAll(){
        this.ingredients.clear();
    }

    deleteAllFromMeal(meal : string){

        let removed : number[] = [];
        this.ingredients.forEach((v : IingredMeal, k : number)=>{
            if(v.meal === meal){
                removed.push(k);
            }
        });

        removed.forEach((n)=>{
            this.ingredients.delete(n)
        });
    }

    get listView(){
        let view :IlistViewType[] = [];
        this.ingredients.forEach((v, k)=>{
            view.push(
                {   
                    key:k,
                    value:`${v.ingred}, (${v.meal})`,
                    checked : v.checked
                });
        })
        return view;
    }


}

export default IngredientsStore;