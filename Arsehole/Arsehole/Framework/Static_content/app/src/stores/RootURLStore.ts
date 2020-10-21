import {observable, action} from 'mobx'


class RootURLStore{

    @observable rootURL : string;


    constructor(){
        this.rootURL = '';
    }

    @action setRootURL(url : string){
        
        this.rootURL = '/'
    }

}

export default RootURLStore;