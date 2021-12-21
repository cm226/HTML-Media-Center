import {observable, action} from 'mobx' 

interface logMsg{
    sev : string,
    ts : string, 
    msg : string
}

class LogStore{

    @observable
    public logs : logMsg[];

    @observable
    public loading : boolean = false

    private numLogs : number = 50;

    public get LogSize(){
        return this.numLogs
    }

    constructor(){
        this.logs = [];
        this.GetLogs()
    }

    @action
    SetNumEntries(num : number){
        this.numLogs = num
        this.GetLogs()
    }


    GetLogs(){
        this.loading = true
        fetch(`/plugins/LogViewer/Entries?size=${this.numLogs}`)
        .then(res => res.json())
        .then((json : logMsg[])=>{
            this.logs = json
            this.loading = false
        })
    }
}

export default LogStore;