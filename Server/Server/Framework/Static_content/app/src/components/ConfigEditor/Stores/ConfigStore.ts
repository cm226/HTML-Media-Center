import { makeObservable, observable, action } from "mobx"


class ConfigStore{

    public DBName : string;
    public DBUser : string;
    public DBPW : string;
    public MetOfficeKey : string;
    public changed : boolean;

    constructor(){

        makeObservable(this, {
            DBName: observable,
            DBUser: observable,
            DBPW: observable,
            MetOfficeKey: observable,
            changed: observable,
            SetDBName: action,
            SetDBUser: action,
            SetDBPW: action,
            SetMetofficeKey: action,
            CommitConfig: action
        })

        this.DBName = "";
        this.DBUser = "";
        this.DBPW = "";
        this.MetOfficeKey = "";
        this.changed = false;

        fetch("/plugins/ConfigEditor/get")
        .then(res => res.json())
        .then(json=>{
            this.DBName = json.DBName;
            this.DBPW = json.DBPW;
            this.DBUser = json.DBUser;
            this.MetOfficeKey = json.MetOfficeKey; 
        })
    }

    SetDBName(name : string){
        this.DBName = name;
        this.changed = true;
    }

    SetDBUser (user : string){
        this.DBUser = user;
        this.changed = true;
    }

    SetDBPW(pw : string){
        this.DBPW = pw;
        this.changed = true;
    }

    SetMetofficeKey(key : string){
        this.MetOfficeKey = key;
        this.changed = true;
    }

    CommitConfig(){
        fetch("/plugins/ConfigEditor/set", {
            method : 'post',
            body: JSON.stringify({
                DBName : this.DBName,
                DBPW : this.DBPW,
                DBUser : this.DBUser,
                MetOfficeKey : this.MetOfficeKey
            })
        });
        this.changed = false;
    }


}

export default ConfigStore;