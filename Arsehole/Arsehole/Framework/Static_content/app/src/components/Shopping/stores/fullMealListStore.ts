import {observable, action} from 'mobx' 
import {Dispatcher} from '../../../Dispatcher'


class FullMealListStore{

    @observable displayed : boolean;


    constructor(){
        this.displayed = false;
    }


    register(dis : Dispatcher){
        dis.addListener("ShowMealList", (show : boolean)=>{
            this.Display(show);
        });
    }

    @action Display(state : boolean){
        this.displayed = state ;
    }


}

export default FullMealListStore;