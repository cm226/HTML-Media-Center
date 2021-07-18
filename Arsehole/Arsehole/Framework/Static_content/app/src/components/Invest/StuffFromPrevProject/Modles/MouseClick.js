import {Observable} from '../observable'

export class MouseClick extends Observable{


    constructor(element){
        super();

        element.on("pointerup", (event)=>{
            this.value = 'up';
            element.node().releasePointerCapture(event.pointerId);
            this.Notify();
        });

        element.on("pointerdown", (event)=>{
            this.value = 'down'
            element.node().setPointerCapture(event.pointerId);
            this.Notify();
        });
    }





}