class Chart{


  constructor(element, chart_size){
    
    this.element = element;
    this.chart_size = chart_size;
    
  }

  
  scale_element(line) {

    this.element.append("g")
        .attr("transform", "translate(0," + this.chart_size.height + ")")
        .call(d3.axisBottom(line.x))
        .selectAll("text")
        .attr("y", 10)
        .attr("x", 15)
        .attr("transform", "rotate(20)")

    this.element.append("g")
        .call(
            d3.axisLeft(line.y)
            .tickSizeInner(-this.chart_size.width))
        .append("text")
        .attr("transform", "rotate(-90)")
        .attr("y", 6)
        .attr("dy", "0.71em")
        .attr("text-anchor", "end")
        .text("Value (£)");
}



}