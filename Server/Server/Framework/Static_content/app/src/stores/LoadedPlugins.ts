import { makeObservable, observable, action } from "mobx"


interface plugin{
    name : string,
    url : string
}

class LoadedPlugins{

    plugins : plugin[];
    widgits : string;

    constructor(){
        makeObservable(this, {
            plugins: observable,
            widgits : observable,
            updatePlugins: action
        })

        this.plugins = [];
        this.widgits = '';
    }

    updatePlugins(root_url : string){
        
        fetch(root_url + 'pluginWigits').then(req=>{
            req.text().then(text=>{
                this.widgits =text;
            })
        })

        fetch(root_url + 'plugins').then(req=>{
            req.json().then(json=>{
                this.plugins =json;
            })
        })

        
        
    }

}

export default LoadedPlugins;