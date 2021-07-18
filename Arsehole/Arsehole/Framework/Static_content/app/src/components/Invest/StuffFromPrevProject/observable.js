export class Observable{

    constructor(){

        this.observers = [];
    }

    Notify(
    ){
        var self = this;
        this.observers.forEach((element) => { element(self.value); });
    }

    Observe(
        callaback
    ) {
        this.observers.push(callaback);
    }

}