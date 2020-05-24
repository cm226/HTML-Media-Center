const TuyAPI = require('tuyapi');

class Light {

    constructor(def){
        
        this.status = {
            connected : false,
        };
          
        this.device = new TuyAPI(def);

        // Add event listeners
        this.device.on('connected', () => {
            this.status.connected = true;
        });
        
        this.device.on('disconnected', () => {
            this.status.connected = false;
            this.onSet(this.status);
        });
        
        this.device.on('error', error => {
            this.status.error = error;
            this.onSet(this.status);
        });

        this.device.on('data', data => {

            if(data.dps['1'] != this.targetState.state ||
            data.dps['3'] != this.targetState.brightness){
              this.device.set({
                  multiple : true,
                  data : {
                  "1" : true,
                  "3": this.targetState.brightness
              }});

             } else {
                this.device.disconnect();
                this.status.state = data.dps['1'];
             }
        });

        
    }

    ResolveDeviceIP(device) {
        // Find device on network
        this.device.find().then(() => {
            //Connect to device
            this.device.connect();
        });
    }

    SendState(targetState, onSet){
        
        this.targetState = targetState;
        this.onSet = onSet;

        if(this.device.device.ip == undefined){
            this.ResolveDeviceIP();
        } else {
            this.device.connect();
        }
    }
}
module.exports = Light;