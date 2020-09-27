import {observable, action} from 'mobx'


class RootURLStore{

    @observable rootURL : string;


    constructor(){
        this.rootURL = '';
    }

    @action setRootURL(url : string){
        
        this.rootURL = 'https://127.0.0.1:8442/'
    }

}

export default RootURLStore;