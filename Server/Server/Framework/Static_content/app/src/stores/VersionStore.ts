import { makeObservable, observable, action } from "mobx"

class VersionStore{

    version : string;


    constructor(){
        makeObservable(this, {
            version: observable,
            getVerion: action
        })
        this.version = 'undefined';
    }

    getVerion(root_url : string){
        
        fetch(root_url + 'getVersion').then(req=>{
            req.text().then(text=>{
                this.version =text;
            })
        })
        
    }

}

export default VersionStore;