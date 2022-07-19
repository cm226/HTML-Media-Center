import { makeObservable, observable, action } from "mobx"
import {Dispatcher} from '../../../Dispatcher'
import { checkIngredMsg } from "../types/dispatchMessages/CheckIngred";


export class CheckedIngredStore{

    public checked : Map<string,boolean> = new Map()

    constructor() {
        makeObservable(this, {
            checked : observable,
            checkIngred : action
        });
    }

    register(dis : Dispatcher){

        dis.addListener("CheckIngred", (msg : checkIngredMsg)=>{
            this.checkIngred(msg.key, msg.check);
        });
        
    }

    checkIngred(key : string, checked: boolean){
        this.checked.set(key, checked);
    }

}

export default CheckedIngredStore;