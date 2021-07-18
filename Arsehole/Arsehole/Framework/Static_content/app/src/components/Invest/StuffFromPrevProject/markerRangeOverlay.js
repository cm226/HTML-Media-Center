class MarkerRangeOverlay
{

    constructor(
        element,
        height,
        lineData,
        startDate,
        endDate,
        activemarker,
        mouseClickModel
    ){
        var self = this;
        this.marker1 = new MarkerOverlay(element, height, startDate,activemarker, lineData,4);
        this.marker2 = new MarkerOverlay(element, height, endDate, activemarker,lineData,5);
        

        this.eventCallbacks = [];
        this.done = false;

        this.start_date = startDate;
        this.end_date = endDate;

        mouseClickModel.Observe((mouse_state)=>{

            if(mouse_state == 'up' &&
               activemarker.Get() == 3){
                this.marker1.UnMark();
                this.marker2.UnMark();

                startDate.Set(0);
                endDate.Set(0);
                activemarker.Reset();

                return;
            }


            if(activemarker.Get() == 1 &&
                mouse_state == 'down'){
                activemarker.Set(1);
            } else if (activemarker.Get() == 2 &&
                    mouse_state == 'up') {
                
                this.marker1.Mark();
                this.marker2.Mark();
                activemarker.Set(2);
            }

            activemarker.Next();
        });

    }

}