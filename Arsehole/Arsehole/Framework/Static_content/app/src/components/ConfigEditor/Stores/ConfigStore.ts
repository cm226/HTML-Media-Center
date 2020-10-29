import {observable, action} from 'mobx' 
import {Dispatcher} from '../../../Dispatcher'


class ConfigStore{

    @observable
    public DBName : string;

    @observable
    public DBUser : string;

    @observable
    public DBPW : string;

    @observable
    public MetOfficeKey : string;

    @observable
    public changed : boolean;

    constructor(){

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

    @action
    SetDBName(name : string){
        this.DBName = name;
        this.changed = true;
    }

    @action
    SetDBUser (user : string){
        this.DBUser = user;
        this.changed = true;
    }

    @action
    SetDBPW(pw : string){
        this.DBPW = pw;
        this.changed = true;
    }

    @action
    SetMetofficeKey(key : string){
        this.MetOfficeKey = key;
        this.changed = true;
    }

    @action
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