import {MousePosition} from './MousePosition'
import {MouseClick} from './MouseClick'

export class Mouse {

    constructor(element){

        this.Position = new MousePosition(element);
        this.Click = new MouseClick(element);
    }


}