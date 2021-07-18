export class HoldingRangeOverlay {
    
        constructor(element,
             rangeStartCache,
             rangeEndCache,
            lineData) {
    
                this.start = rangeStartCache;
                this.end = rangeEndCache;
    
                this.lineData = lineData;
    
                this.height = element.node().getBBox().height;
    
                this.element = element.append("text")
                    .attr("font-size","15")
                    .attr("x","20")
                    .attr("y","10");
    
    
                this.start.Observe(this.updateValue.bind(this));
                this.end.Observe(this.updateValue.bind(this));
    
    
        }
        
        resetValue(){
          this.element.text("")
          
        }
    
        updateValue() {
    
            if(!this.start.HasValue() || !this.end.HasValue()) {
              this.resetValue()
              return;
            }

            var diff = this.end.Value() - this.start.Value();
            this.element.text("£"+diff.toFixed(2).toString());
            if(diff > 0.0)
                this.element.attr("class", "green");
            else
                this.element.attr("class", "red");
        }
    
    
    }