import { ImageListItem } from "@mui/material";
import { makeObservable, observable, action, computed } from "mobx"
import {Dispatcher} from '../../../Dispatcher'
import { Extra } from "../types/extras";
import { IListView, IListViewType } from "../types/listView";


export class ExtrasStore implements IListView{

    public _extras : Extra[] = [];

    constructor() {
        makeObservable(this, {
            _extras : observable,
            setExtras : action,
            Extras: computed,
            addExtra: action,
            removeExtra: action,
            clearAll: action,
        });
    }
    
    get listView () {
        return this.Extras.map(extra=>{return {id : extra.ingred, name : extra.ingred}});
    }

    get Extras () {
        // for mobx
        const l = this._extras.length;
        for( const extra of this._extras){
            const i = extra.ingred
        }
        return this._extras;
    }

    register(dis : Dispatcher){

        dis.addListener("ExtrasLoaded", (extras : Extra[])=>{
            this.setExtras(extras);
        });

        dis.addListener("AddExtra", (name : string)=>{
            this.addExtra(name);
        });

        dis.addListener("RemoveExtra", (name : string)=>{
            this.removeExtra(name);
        });

        dis.addListener("ClearAll", ()=>{
            this.clearAll();
        });
        
    }

    setExtras(extras : Extra[]){
        this._extras = extras;
    }

    addExtra(name : string){
        // mobx.... 
        this._extras = [...this._extras, {ingred : name, store : 'Sainsbury' }];
    }

    removeExtra(name : string){
        console.log("event handled " +name);
        const idx = this._extras.findIndex((extra)=>extra.ingred === name);
        console.log("index : " + idx);
        this._extras.splice(idx, 1);
    }

    clearAll(){
        this._extras = [];
    }

}

export default ExtrasStore;