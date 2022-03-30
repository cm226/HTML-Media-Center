import { makeObservable, observable, action } from "mobx"
import {Dispatcher} from '../../../Dispatcher'

class FilterViewStore{

    filtered : boolean;


    constructor(){
        makeObservable(this, {
            filtered: observable,
            SetFiltered: action
        })
        this.filtered = false;
    }


    register(dis : Dispatcher){
        dis.addListener("Filter", (show : boolean)=>{
            this.SetFiltered(show);
        });
    }

    SetFiltered(state : boolean){
        this.filtered = state;
    }


}

export default FilterViewStore;