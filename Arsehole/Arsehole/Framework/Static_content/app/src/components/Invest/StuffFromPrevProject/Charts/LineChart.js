// This class is currently unused, i should refactor to use it but havent got round to it yet :/

class LineChart extends Chart{
  
  constructor(chart_size, raw_data){
    
    this.chart_size = chart_size;
    this.lines_data = [];
    this.master_line = 0;
    
    
  }
  
  draw_chart(){
    
    if(this.lines_data.length === 0 ){
      console.log("drawing empty chart posible error?")
      return;
    }
    
    
    // do chart draw
    
    
    
    //need to find the min y in all lines
    let min_y = Number.MAX_SAFE_INTEGER;
    for(let i = 0; i < this.lines_data.length; i++){
      let line_min = line_min_y(i);
      if(line_min < min_y) min_y = line_min;
    }
    
    
    scale_element(
      {
        max: line_max_y(this.master_line),
        min: min_y
      }
    );
    
    
    
  }
  
  add_line(line_data){
    
    this.lines_data.push(line_data);
    
  }
  
  
  scale_element(y_domain_extents){
    
    this.d3_line_bounds = {};
    d3_line_bounds.x = d3.scaleTime()
        .rangeRound([0, this.chart_size.width]);

    d3_line_bounds.y = d3.scaleLinear()
        .rangeRound([this.chart_size.height, 0]);
    
    
    d3_line_bounds.x.domain(
      d3.extent(
        this.lines_data[this.master_line].lineData,
        function(d) {
          return this.lines_data[this.master_line].x_parser(d)}
      )
    );
    
    d3_line_bounds.y.domain(
      d3.extent(
        [y_domain_extents.min, y_domain_extents.max],
        function(d) { return d; }
      )
    );
        
    super.scale_element(
      this.d3_line_bounds
    );
    
  }
  
  
  line_max_y(line_id){
    
    return
      lines[line_id].y_parser(
        lines[line_id].lineData.reduce(function(a, b){
          if(lines[line_id].y_parser(a) > lines[line_id].y_parser(b)) return a;
          else return b;
      }));
    
  }
  
  
  line_min_y(line_id){
    
    let line = this.lines_data[line_id];
    
    let line_min = line.lineData.reduce(function(a,b){
        if(line.y_parser(a) < line.y_parser(b)) return a;
        else return b;
    });
    
    return line.y_parser(line_min)
    
  }
  
  
}