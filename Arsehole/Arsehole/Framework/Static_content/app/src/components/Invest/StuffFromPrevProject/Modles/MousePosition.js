import * as d3 from "d3";
import {Observable} from '../observable'

export class MousePosition extends Observable {

    constructor(element){

        super();
        this.value = {x : 0, y : 0};
        this.page = {x : 0, y : 0};
        this.element = element;
        element.on("mousemove", this.mouseMove.bind(this));
    }

    mouseMove(event){
        
        let position = d3.pointer(this.element.node());

        this.value.x = position[0];
        this.value.y = position[1];

        this.page.x = event.pageX;
        this.page.y = event.pageY;

        this.Notify();
    }




    

}