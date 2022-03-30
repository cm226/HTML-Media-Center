import { makeObservable, observable, action } from "mobx"
import {Dispatcher} from '../../../Dispatcher'


export enum Status{
    CONNECTED = 1,
    OFFLINE
}

export class WorkerStatusStore{

    status : Status ;


    constructor(){
        makeObservable(this, {
            status: observable,
            SetStatus: action
        })
        this.status = Status.OFFLINE;
    }


    register(dis : Dispatcher){
        dis.addListener("ServiceWorkerCallback", (connected : boolean)=>{
            this.SetStatus(connected ? Status.CONNECTED : Status.OFFLINE);
        });
    }

    SetStatus(status : Status){
        this.status = status ;
    }


}
