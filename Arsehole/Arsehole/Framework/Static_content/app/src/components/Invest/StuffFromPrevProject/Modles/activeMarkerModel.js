import {Observable} from {../Observable}

class ActiveMarkerModel extends Observable {


    constructor(){
        super();
        this.Reset();
    }

    Set(value){
        this.activeMarker = value;
        this.placedMarkers[value-1]=true;

        if (this.placedMarkers[0] &&
        this.placedMarkers[1]) {
            this.bothMarkersPlaced = true;
        }
        
        this.Notify();
    }
    
    Reset(){
      this.placedMarkers = [false, false];
      this.bothMarkersPlaced = false;
      this.activeMarker = 1;
    }

    Get(){
        return this.activeMarker;
    }

    Next() {
        if ( !this.bothMarkersPlaced){
            this.activeMarker = this.activeMarker + 1;
        } else{
            this.activeMarker = 3;
        }
    }


}