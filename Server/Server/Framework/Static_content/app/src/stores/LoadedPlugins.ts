import { makeObservable, observable, action } from "mobx"


class LoadedPlugins{

    plugins : string;

    constructor(){
        makeObservable(this, {
            plugins: observable,
            updatePlugins: action
        })

        this.plugins = '';
    }

    updatePlugins(root_url : string){
        
        fetch(root_url + 'pluginWigits').then(req=>{
            req.text().then(text=>{
                this.plugins =text;
            })
        })
        
    }

}

export default LoadedPlugins;