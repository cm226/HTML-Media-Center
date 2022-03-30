import { makeObservable, observable, action } from "mobx"


class ServerTimeStore{

    serverTime : Date;

    private serverStartTime : Date;
    private clientStartTime : Date;


    constructor(){
        makeObservable(this, {
            serverTime: observable,
            getServerTime: action,
            UpdateServerTime: action,
        })

        this.serverTime = new Date();
        this.serverStartTime = new Date();
        this.clientStartTime = new Date();
    }

    getServerTime(root_url : string){
        
        fetch(root_url + 'serverTime').then(req=>{
            req.text().then(server_time_str=>{
                this.serverStartTime.setTime(Date.parse(server_time_str.trim()));
                this.clientStartTime.setTime(Date.now());
            })
        })
    }

    UpdateServerTime(){
        const ellapsed = Date.now() - this.clientStartTime.getTime();
        let newTime = new Date();
        newTime.setTime(this.serverStartTime.getTime() + ellapsed);

        this.serverTime = newTime;
    }

}

export default ServerTimeStore;