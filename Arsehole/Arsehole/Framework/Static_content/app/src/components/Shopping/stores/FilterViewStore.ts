import {observable, action} from 'mobx' 
import {Dispatcher} from '../../../Dispatcher'

class FilterViewStore{

    @observable filtered : boolean;


    constructor(){
        this.filtered = false;
    }


    register(dis : Dispatcher){
        dis.addListener("Filter", (show : boolean)=>{
            this.SetFiltered(show);
        });
    }

    @action SetFiltered(state : boolean){
        this.filtered = state;
    }


}

export default FilterViewStore;