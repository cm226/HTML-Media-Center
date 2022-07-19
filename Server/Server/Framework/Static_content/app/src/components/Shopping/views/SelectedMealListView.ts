import ingredientsStore, { IngredientsStore } from "../stores/ingredientsStore";
import { IListView, IListViewType } from "../types/listView";

export class SelectedMealListView implements IListView{    

    private _store : ingredientsStore;

    constructor (ingredStore : ingredientsStore){
        this._store = ingredStore;
    }

    get listView(): IListViewType[] {
        const model = this._store._model;
        const list : IListViewType[] = [];
        for(const meal in model){
            if(model[meal].selected)
                list.push({name : meal, id : meal});
        }
        return list;
    }
    

}