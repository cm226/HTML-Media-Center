import $ from "jquery";

export class ValueAtCursorOverlay {

    constructor(
        valueCaches,
        mouseModel
    ) {
        this.valueCaches = valueCaches;
        this.lineColors = [
            '--primary-color',
            '--secondary-color'
        ];
        this.mousePosition = mouseModel.Position;


        valueCaches.forEach(cache => {
            cache.Observe(this.UpdateValue.bind(this));    
        });
        this.mousePosition.Observe(this.onMouseMove.bind(this));
        mouseModel.Click.Observe(this.onMouseDown.bind(this));
    }

    UpdateValue(){
        let popupStr = "";
        let colorCount = 0;
        let lineColors = this.lineColors;
        this.valueCaches.forEach(cache=>{
            if(cache.HasValue()){
                popupStr += "<span style=\"color: var(" + lineColors[colorCount++] + ")\"> £ " +
                    Math.floor(cache.Value()).toLocaleString() +
                    "</span><br/>";
            }
        });
        $("#valuePopup").html(popupStr)
        .attr("pointer-events","none");
    }

    onMouseMove(){
        let mousePosition = this.mousePosition.page;
        $("#valuePopup").css("left",mousePosition.x + 20);
        $("#valuePopup").css("top",mousePosition.y);
    }

    onMouseDown(mouse_state){
        if(mouse_state === 'down'){
            $("#valuePopup").css("display", "none");
        } else {
            $("#valuePopup").css("display", "block");
        }
    }



}