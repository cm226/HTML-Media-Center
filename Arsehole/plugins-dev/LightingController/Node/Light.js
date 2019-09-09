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
        });
        
        this.device.on('error', error => {
            this.status.error = error;
        });

        this.device.on('data', data => {

            if(data.dps['1'] != this.targetState){
              this.device.set({
                  dps : 1,
                  set: this.targetState
              });
            } else {
                this.device.disconnect();
                this.status.state = data.dps['1'];
                this.onSet(this.status);
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