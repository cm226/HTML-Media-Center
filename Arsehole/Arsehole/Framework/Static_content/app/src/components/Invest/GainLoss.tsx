import React, { RefObject } from 'react';
const charts = require('./StuffFromPrevProject/Charts.js');

interface IProps{
    value : number,
    day_change : number,
    gain_loss : number
}

class GainLoss extends React.Component {

    private myRef : RefObject<HTMLDivElement>;

    constructor(props : IProps) {
      super(props);
      this.myRef = React.createRef();
    }

    componentDidMount() {
        charts.draw_gainLoss(100,100,this.myRef.current);
    }
    // componentDidUpdate() {
        
    // }

    render() {
      return <div ref={this.myRef} />;
    }
  }

export default GainLoss;