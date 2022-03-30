import { makeObservable, observable, action } from "mobx"
import {Dispatcher} from '../../../Dispatcher'

export enum views {
    FullMealList,
    Manage,
    Main
}

class DisplayedViewStore{

    displayed : views;


    constructor(){
        makeObservable(this, {
            displayed: observable,
            SetMealList: action,
            SetManage: action
        })
        this.displayed = views.Main;
    }


    register(dis : Dispatcher){
        dis.addListener("ShowMealList", (show : boolean)=>{
            this.SetMealList(show);
        });

        dis.addListener("ShowManage", (show : boolean)=>{
            this.SetManage(show);
        });
    }

    SetMealList(state : boolean){
        if(state){
            this.displayed = views.FullMealList ;
        } else {
            this.displayed = views.Main;
        }
    }

    SetManage(state : boolean){
        if(state){
            this.displayed = views.Manage ;
        } else {
            this.displayed = views.Main;
        }
    }

}

export default DisplayedViewStore;