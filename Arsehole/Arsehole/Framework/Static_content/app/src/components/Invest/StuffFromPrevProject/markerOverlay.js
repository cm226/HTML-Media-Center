function S4() {
    return (((1+Math.random())*0x10000)|0).toString(16).substring(1);
}
 
// then to call it, plus stitch in '4' in the third group


class MarkerOverlay{

    constructor(
        element,
        height,
        date_model,
        activeMarkerModel,
        lineData,
        number
    ){
        var self = this;
        this.guid = (S4() + S4() + "-" + S4() + "-4" + S4().substr(0,3) + "-" + S4() + "-" + S4() + S4() + S4()).toLowerCase();
        this.activeMarkerModel = activeMarkerModel;
        this.number = number;

        this.marker = element.append("line")
            .attr('x1','0')
            .attr('y1','0')
            .attr('x2','0')
            .attr('y2',height)
            .attr("stroke-width", 2)
            .attr("stroke", "rgb(50, 50, 50)")
            .attr("fill", "none")
            .attr("id", this.guid)
            .attr("pointer-events","none")

            this.hit_box = element.append("line")
            .attr('x1','0')
            .attr('y1','0')
            .attr('x2','0')
            .attr('y2',height)
            .attr("stroke-width", 20)
            .attr("stroke", "rgb(0, 0, 0)")
            .attr("stroke-opacity","0.0")
            .attr("fill", "none")
            .attr("pointer-events","none");
    
        
        this.lineData = lineData;

        date_model.Observe(this.onDateChange.bind(this));
        this.onDateChange(date_model.value);
    }
    
    resetMarker(){
      this.marker.attr("x1", 0);
      this.marker.attr("x2", 0);

      this.hit_box.attr("x1", 0);
      this.hit_box.attr("x2", 0);
    }

    onDateChange(
        newDate
    ){
        if(!newDate){
          this.resetMarker();
          return;
        }
        this.marker.attr("x1", this.lineData.x(newDate));
        this.marker.attr("x2", this.lineData.x(newDate));

        this.hit_box.attr("x1", this.lineData.x(newDate));
        this.hit_box.attr("x2", this.lineData.x(newDate));
    }

    Mark(
    ){
        this.hit_box.attr("pointer-events","all")
    }

    UnMark(){
        this.hit_box.attr("pointer-events","none")
    }


}