import {observable, action} from 'mobx'


class VersionStore{

    @observable version : string;


    constructor(){
        this.version = 'undefined';
    }

    @action getVerion(root_url : string){
        
        fetch(root_url + 'getVersion').then(req=>{
            req.text().then(text=>{
                this.version =text;
            })
        })
        
    }

}

export default VersionStore;