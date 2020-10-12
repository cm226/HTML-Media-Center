import {observable, action} from 'mobx' 
import {Dispatcher} from '../../../Dispatcher'


enum Status{
    CONNECTED,
    OFFLINE
}

class WorkerStatusStore{

    @observable status : Status ;


    constructor(){
        this.status = Status.CONNECTED;
    }


    register(dis : Dispatcher){
        dis.addListener("ServiceWorkerCallback", (connected : boolean)=>{
            this.SetStatus(connected ? Status.CONNECTED : Status.OFFLINE);
        });
    }

    @action SetStatus(status : Status){
        this.status = status ;
    }


}

export default WorkerStatusStore;