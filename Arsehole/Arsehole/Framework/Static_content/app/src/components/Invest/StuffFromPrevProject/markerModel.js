import {Observable} from "../observable"
export class markerModel extends Observable{

    constructor(

    ){
        super();
        this.value = 0;
    }

    Set(
        date
    ) {
        this.value = date;
        this.Notify();
    }

}