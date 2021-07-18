export class ValueRangeOverlay {

    constructor(element,
         rangeStartCache,
         rangeEndCache,
        lineData) {

            this.start = rangeStartCache;
            this.end = rangeEndCache;

            this.lineData = lineData;

            this.height = element.node().getBBox().height;
            this.width = element.node().getBBox().width;

            this.element = element.append("text")
                .attr("font-size","20")
                .attr("x","100")
                .attr("y",this.height-60);

            this.textStart = element.append("text")
                .attr("font-size","10")
                .attr("x","100")
                .attr("y",this.height-40);

            this.textEnd = element.append("text")
                .attr("font-size","10")
                .attr("x","100")
                .attr("y",this.height-40);
            
            this.textDateRange = element.append("text")
                .attr("font-size","10")
                .attr("x","100")
                .attr("y",this.height-40);

            this.start.Observe(this.updateValue.bind(this));
            this.end.Observe(this.updateValue.bind(this));


    }

    formDateRangeString(){

        var startDate = this.start.Date();
        var endDate = this.end.Date();
        var deltaDate = new Date(endDate - startDate);

        var years = deltaDate.getFullYear() - 1970;
        var months = deltaDate.getMonth();
        var days = deltaDate.getDate();

        var dateRange = "";
        if(years > 0)
            dateRange += years + " years, ";
        if(months > 0)
            dateRange += months + " months, ";
        if(days > 0)
            dateRange += days + " days"

        return dateRange;

    }
    
    clearText(){
      this.textStart.text("");
      this.textEnd.text("");
      this.textDateRange.text("");
      this.element.text("");
      
    }

    updateValue() {

        if(!this.start.HasValue() || !this.end.HasValue()) {
            this.clearText();
            return;
        }
        var diff = this.end.Value() - this.start.Value();
        this.element.text("£"+diff.toFixed(2).toString());

        var startDate = this.start.Date();
        var endDate = this.end.Date();

        this.textStart.text(startDate.getDate() + "/" + startDate.getMonth() + "/" + (startDate.getFullYear()));
        this.textEnd.text(endDate.getDate() + "/" + endDate.getMonth() + "/" + (endDate.getFullYear()));
        this.textDateRange.text(this.formDateRangeString());

        var startX = this.lineData.x(this.start.Date());
        var endX = this.lineData.x(this.end.Date());
        let textLength = this.element.node().getComputedTextLength();
        
        if((endX - startX) < textLength){

            // The text is too big to fit between the lines 
            
            if((this.width - endX) >= textLength){
                // there is enough room to fit the text on after the end line
                this.element.attr("y", this.height - 70);
                this.element.attr("x", endX + 10);

                this.textDateRange.attr("y", this.height - 50)
                this.textDateRange.attr("x", endX + 10)
            } else{
                // there is enough room to fit it at the start
                this.element.attr("y", this.height - 70);
                this.element.attr("x", startX - textLength);

                this.textDateRange.attr("y", this.height - 50)
                this.textDateRange.attr("x", startX - textLength)
            }

        }else{

            let centerx = startX +
                (((endX - startX)- this.element.node().getComputedTextLength())/2);

            this.element.attr("y", this.height - 60);
            this.element.attr("x", centerx);
            this.textDateRange.attr("x", centerx)
            this.textDateRange.attr("y", this.height - 40)
            
        }
        this.textStart.attr("x", startX - this.textStart.node().getComputedTextLength() - 10);
        this.textEnd.attr("x", endX + 10);
    }


}