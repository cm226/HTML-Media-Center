import { makeObservable, observable, action } from "mobx"


class RootURLStore{

    rootURL : string;


    constructor(){
        makeObservable(this, {
            rootURL: observable,
            setRootURL: action
        })
        this.rootURL = '';
    }

    setRootURL(url : string){
        
        this.rootURL = '/'
    }

}

export default RootURLStore;