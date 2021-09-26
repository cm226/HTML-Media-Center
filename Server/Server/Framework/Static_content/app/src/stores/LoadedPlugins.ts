import {observable, action} from 'mobx'


class LoadedPlugins{

    @observable plugins : string;


    constructor(){
        this.plugins = '';
    }

    @action updatePlugins(root_url : string){
        
        fetch(root_url + 'pluginWigits').then(req=>{
            req.text().then(text=>{
                this.plugins =text;
            })
        })
        
    }

}

export default LoadedPlugins;