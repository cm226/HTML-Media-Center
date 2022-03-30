import { makeObservable, observable, action, runInAction } from "mobx"

export interface light{
    name : string,
    state : string
}

class LightingStore{

    public lights : light[];
    public sleeping: boolean = false;
    public hoursUntillNotSleeping : number = 0;
    public loading : boolean = false

    constructor(){
        makeObservable(this, {
            lights: observable,
            loading: observable,
            sleeping : observable,
            hoursUntillNotSleeping : observable,
            GetLights: action,
            setSleeping :action,
            ToggleLight : action
        })
        this.lights = [];
        this.GetLights()
    }

    GetLights(){
        this.loading = true
        fetch(`/plugins/Lighting/AllLights`)
        .then(res => res.json())
        .then((json : light[])=>{
            this.lights = json
            this.loading = false
        })
    }

    ToggleLight(light : light) {
        
        const url = `/plugins/Lighting/${light.state==="1"?'TurnOffLight' : 'TurnOnLight'}`;
        fetch(`${url}?name=${light.name}`).then((resp)=>{
            resp.json().then((json: light)=>{
                light.state = json.state;
            });
        })
    }

    setSleeping(newValue : boolean) {
        fetch(`/plugins/Lighting/Sleeping`, {
            method: 'POST',
            body: (newValue).toString()
        }).then(()=>{
            fetch(`/plugins/Lighting/SleepingStatus`).then((resp)=>{
                resp.text().then((text)=>{
                    this.hoursUntillNotSleeping = parseInt(text);
                    runInAction(()=>{
                        if(this.hoursUntillNotSleeping > 0){
                            this.sleeping = true;
                        } else{
                            this.sleeping = false;
                        }
                    })
                })
            })
        })
    }
}

export default LightingStore;