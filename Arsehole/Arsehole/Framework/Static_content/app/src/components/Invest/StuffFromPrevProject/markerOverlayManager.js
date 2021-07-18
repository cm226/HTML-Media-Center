
export class MarkerOverlayManager
{
    constructor()
    {
        this.rangeStart = new markerModel();
        this.rangeEnd = new markerModel();
        this.activeRange = new ActiveMarkerModel();
        this.overlays = [];
    }

    attachStartRangeListener(
        listener
    ) {
        this.rangeStart.Observe(listener);
    }

    attachEndRangeListener(
        listener
    ) {
        this.rangeEnd.Observe(listener);
    }

    addMarkerOverlay(
        element,
        line,
        height,
        width,
        dateAtCursor,
        mouseClickModel
    ) {


        dateAtCursor.Observe((date) => {
                if (this.activeRange.Get() == 1){
                    this.rangeStart.Set(date)
                } else if(this.activeRange.Get() == 2) {
                    this.rangeEnd.Set(date);
                }
            });

        this.overlays.push(new MarkerRangeOverlay(
                element,
                height,
                line,
                this.rangeStart,
                this.rangeEnd,
                this.activeRange,
                mouseClickModel
            )
        );
    }
}