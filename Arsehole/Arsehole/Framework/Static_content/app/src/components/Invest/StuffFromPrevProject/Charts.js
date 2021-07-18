import * as d3 from "d3";
import $ from "jquery";
import {MarkerOverlayManager} from './markerOverlayManager'
import {Line} from './Line'
import {Mouse} from './Modles/Mouse'
import {markerModel} from './markerModel'
import {MarkerValueCache} from './Cache/MarkerValueCache'
import {ValueRangeOverlay} from './ValueRangeOverlay'
import {ValueAtCursorOverlay} from './ValueAtCursorOverlay'
import {HoldingRangeOverlay} from './HoldingRangeOverlay'
import {color} from './helpers'


function clear_chart(chart_id) {
    $("#"+chart_id).empty();
}

var margin = {top: 20, right: 20, bottom: 30, left: 50};

var marker_overlay_manager = new MarkerOverlayManager();
var overlays = [];
var chart_data = [];

var add_chart = function ( svg_id ) {

                var svg = d3.select(svg_id);
                return svg.append("g").attr("transform", "translate(" + margin.left + "," + margin.top + ")");
};

var scale_element = function( element, line, height,width) {

    element.append("g")
        .attr("transform", "translate(0," + height + ")")
        .call(d3.axisBottom(line.x))
        .selectAll("text")
        .attr("y", 10)
        .attr("x", 15)
        .attr("transform", "rotate(20)")

    element.append("g")
        .call(
            d3.axisLeft(line.y)
            .tickSizeInner(-width))
        .append("text")
        .attr("transform", "rotate(-90)")
        .attr("y", 6)
        .attr("dy", "0.71em")
        .attr("text-anchor", "end")
        .text("Value (£)");

    return element;
}

//-------------------------------------------------------------------------------------------------

// creates the data line that folows the cursor 
var add_data_line_overlay = function(
	element,
	chartData,
	height,
    width,
    dateAtCursor,
    mouseClickModel
) {
	marker_overlay_manager.addMarkerOverlay(
        element,
        chartData,
        height,
        width,
        dateAtCursor,
        mouseClickModel
    );
	
}

//-------------------------------------------------------------------------------------------------

var create_mouse_model = function(
    element,
    width, 
    height,
    line
){
    

    let hitbox = element.append("rect")
        .attr("class", "overlay")
        .attr("width", width)
        .attr("height", height)
        .style("opacity", "0.0");

    let mouse = new Mouse(hitbox);
        
    return mouse;
}

//-------------------------------------------------------------------------------------------------

var create_line = function(
    height,
    width,
    element,
    scaler,
    data,
    data_reader = null_reader) {

    var d3_line_bounds = {};
    d3_line_bounds.x = d3.scaleTime()
        .rangeRound([0, width]);

    d3_line_bounds.y = d3.scaleLinear()
        .rangeRound([height, 0]);


    data(function(lines){
        
        let line_id = 0;
        if(lines[line_id].lineData.length == 0){
            return;
        }

        let max_val = lines[line_id].y_parser(
          lines[line_id].lineData.reduce(function(a, b){
            if(lines[line_id].y_parser(a) > lines[line_id].y_parser(b)) return a;
            else return b;
        }));

        let min_val = Number.MAX_SAFE_INTEGER;
        
        lines.forEach((line)=>{

            if(line.lineData.length == 0){
                return;
            }

            let line_min = line.lineData.reduce(function(a,b){
                if(line.y_parser(a) < line.y_parser(b)) return a;
                else return b;
            });
            
            line_min = line.y_parser(line_min) *0.90;
            
            if(line_min < min_val){
              min_val = line_min;
            }
        });
        

        d3_line_bounds.x.domain(d3.extent(lines[0].lineData, function(d) { return lines[0].x_parser(d); }));
        d3_line_bounds.y.domain(d3.extent([min_val, max_val], function(d) { return d; }));
        scaler(element, d3_line_bounds, height, width);

  
        d3_line_bounds.lines = lines;
          
        // create d3 elements for each line and append to SVG
        lines.forEach((line)=>{
            
          d3_line_bounds.d3_line = d3.line()
          .x(function(d) { return d3_line_bounds.x(line.x_parser(d)) })
          .y(function(d) { return d3_line_bounds.y(line.y_parser(d)) });
  
          
          line.Set_X_Bounds(d3_line_bounds.x);
          line.Set_Y_Bounds(d3_line_bounds.y);
  
          // define the area
          var area = d3.area()
          .x(function(d) {
            return d3_line_bounds.x(
              line.x_parser(d)); })
          .y0(height)
          .y1(function(d) {
            return d3_line_bounds.y(
              line.y_parser(d)); });
      
            // add the area
          line.area_styler(
            element.append("path")
              .datum(line.lineData)
              .attr("d", area));
  
          line.styler(element.append("path")
              .datum(line.lineData)
              .attr("fill", "none")
              .attr("stroke", "rgb(234, 234, 234)")
              .attr("stroke-linejoin", "round")
              .attr("stroke-linecap", "round")
              .attr("stroke-width", 1.5)
              .attr("d", d3_line_bounds.d3_line));
    
        });
        
        data_reader(d3_line_bounds);

    });
}

var create_bars = function(height, width, element, scaler, data, X, Y) {

    var margin = {top: 20, right: 20, bottom: 30, left: 60};
    d3.tsv(data, function(error, data) {

        if(data.length == 0){
            return;
        }
        var x = d3.scaleBand().rangeRound([0, width]).padding(0.1),
            y = d3.scaleLinear().rangeRound([height, 0]);
        
        x.domain(data.map(function(d) { return X(d); }));
        y.domain([0, data[data.length -1].value ]);

        element.append("g")
            .attr("class", "axis axis--x")
            .attr("transform", "translate(0," + height + ")")
            .call(d3.axisBottom(x));

        element.append("g")
            .attr("class", "axis axis--y")
            .call(d3.axisLeft(y))
            .append("text")
            .attr("transform", "rotate(-90)")
            .attr("y", 6)
            .attr("dy", "0.71em")
            .attr("text-anchor", "end")
            .text("Value");

        element.selectAll(".bar")
            .data(data)
            .enter().append("rect")
            .attr("fill", "rgb(89, 89, 89)")
            .attr("class", "bar")
            .attr("x", function(d) { return x(X(d)); })
            .attr("y", function(d) { return y(Y(d)); })
            .attr("width", x.bandwidth())
            .attr("height", function(d) { return height - y(Y(d)); });

});

}


var null_styler = function(line){};
var null_reader = function ( data ){};

var dummy_scale = function (element, line ) { return element;}


function draw_gainLoss(chart_width, chart_height, gain_loss) {

    var gain_loss_data = {
        name : "gainloss"
    }
    chart_data.push(gain_loss_data);
    var height = chart_height - margin.top - margin.bottom;
    var width = chart_width - margin.left - margin.right;
    
    
    let val_parser = (d)=>{return parseFloat(d.gain_loss.replace(",", ""))};
    let time_parser = (d)=>{return d3.timeParse("%Y-%m-%e")(d.valid_on)};

    create_line(
             height,
             width,
             gain_loss,
             scale_element,
             function(func){
                d3.tsv("Data/GainLoss.tsd", function(error, data) {
                  
                let gain_loss_line = new Line(data);
                gain_loss_line.Set_Y_parser(val_parser);
                gain_loss_line.Set_X_parser(time_parser);
                gain_loss_line.Area_Styler(function(element){ element.attr("class", "area")});
                gain_loss_line.Styler(function(element){ element.attr("class", "primary_line")});
                  
                func([gain_loss_line]);
             })},
             function(d3_line_bounds){
                    var gain_loss_line = d3_line_bounds.lines[0];
                    var gain_loss_line_data = gain_loss_line.lineData;
                    
                    $(".gain_total").html("£"+gain_loss_line_data[gain_loss_line_data.length-1].gain_loss);
 
                    var day_gain = parseFloat(gain_loss_line_data[gain_loss_line_data.length-1].gain_loss.replace(",",""));
                    day_gain -= parseFloat(gain_loss_line_data[gain_loss_line_data.length-2].gain_loss.replace(",",""));
                    day_gain = day_gain.toFixed(2);
                     
                    $(".day_change_total").html(gain_loss_line_data[gain_loss_line_data.length-1].day_change+"% / £"+ day_gain);
 
                    color($(".day_change_total"));

                    // Overlays
                    gain_loss_data.lineData = gain_loss_line_data;
                    
                    let mouse = create_mouse_model(
                        gain_loss,
                        width,
                        height,
                        gain_loss_line
                    );
                    
                    let dateAtCursor = new markerModel();
                    mouse.Position.Observe(
                        (position)=>{
                            if(position.x > 0 &&
                               position.x <= width){
                                    var date = gain_loss_line.x.invert(position.x);
                                    dateAtCursor.Set(date);
                               }
                            
                        }
                    )

                    add_data_line_overlay(
                        gain_loss, // element
                        gain_loss_line, // line
                        height, // element height
                        width, // element width
                        dateAtCursor,
                        mouse.Click
                    );

                    var startMarkerCache = new MarkerValueCache(gain_loss_line_data, gain_loss_line.x_parser, gain_loss_line.y_parser);
                    var endMarkerCache = new MarkerValueCache(gain_loss_line_data, gain_loss_line.x_parser, gain_loss_line.y_parser);

                    marker_overlay_manager.attachStartRangeListener(
                        startMarkerCache.rangeChange.bind(startMarkerCache));

                    marker_overlay_manager.attachEndRangeListener(
                        endMarkerCache.rangeChange.bind(endMarkerCache));


                    let valueMarkerCache = new MarkerValueCache(gain_loss_line_data, time_parser, val_parser);
                    dateAtCursor.Observe(valueMarkerCache.rangeChange.bind(valueMarkerCache));
                    
                    // create the text overlay
                    overlays.push(new ValueRangeOverlay(
                        gain_loss,
                        startMarkerCache,
                        endMarkerCache,
                        d3_line_bounds));

                    // create a Value at cursor overlay

                    let valAtCurOverlay = 
                        new ValueAtCursorOverlay(
                            [valueMarkerCache],
                            mouse
                        );



             },
             gain_loss_data);
	
	
}

function draw_value(chart_width, chart_height) {
    var value = add_chart("#value_chart");

    var value_data = {
        name : "value"
    }
    chart_data.push(value_data);

    var height = chart_height - margin.top - margin.bottom;
    var width = chart_width - margin.left - margin.right;

    create_line(
             height,
             width,
             value,
             scale_element,
             function(func){
                d3.tsv("Data/Value.tsd", function(error, data) {
                  d3.tsv("Data/1Yearforecast.tsv", function(error, pred_data) {
                    d3.tsv("Data/GainLoss.tsd", function(error, gain_loss_data){
                  
                      let value_line = new Line(data);
                      value_line.Set_Y_parser(function(d){return parseInt(d.current_value.replace(",", ""));});
                      value_line.Set_X_parser(function(d){return d3.timeParse("%Y-%m-%e")(d.valid_on);});
                      value_line.Area_Styler(function(element){ element.attr("class", "area")});
                      value_line.Styler(function(element){ element.attr("class", "primary_line")});
                      
                      // calculate the input value by subtracting value form gainloss
                      // reusing gain_loss_data object for convienence.
                      for(let i = 0; i < data.length; i++){
                            gain_loss_data[i].gain_loss =
                                parseFloat(data[i].current_value.replace(",", ""))
                                    - parseFloat(gain_loss_data[i].gain_loss.replace(",", ""));
                        }
                      
                      
                      let purchased_line = new Line(gain_loss_data);
                      purchased_line.Set_Y_parser(function(d){return parseInt(d.gain_loss);});
                      purchased_line.Set_X_parser(function(d){return d3.timeParse("%Y-%m-%e")(d.valid_on);});
                      purchased_line.Area_Styler(function(element){ element.attr("class", "secondary_area")});
                      purchased_line.Styler(function(element){ element.attr("class", "secondary_line")});
                        
                      // only care about data up to the latest data available so cut off the rest
                      for(let i = 0; i < pred_data.length; i++){
                        if(d3.timeParse("%d/%m/%y")(pred_data[i].date)
                          > d3.timeParse("%Y-%m-%e")(data[data.length-1].valid_on)){
                            
                            pred_data.splice(i);
                            break;
                          }
                      }
                      
                      
                      let prediction_line = new Line(pred_data);
                      prediction_line.Set_Y_parser(function(d){return parseInt(d.value.replace(",", ""));});
                      prediction_line.Set_X_parser(function(d){return d3.timeParse("%d/%m/%y")(d.date);});
                      prediction_line.Area_Styler(function(element){ element.attr("class", "no_area")});
                      prediction_line.Styler(function(element){ element.attr("class", "secondary_line")});
                        
                      func([value_line, purchased_line, prediction_line]);
                      
                    });
                  });
              })},
             function( all_lines ){
               
                 var value_line = all_lines.lines[0];
                 var value_line_data = value_line.lineData;
                 
                 $(".value_total").html("£" + value_line_data[value_line_data.length-1].current_value);

                 // Overlays
                 value_data.lineData = value_line_data;

                 let mouse = create_mouse_model(
                    value,
                    width,
                    height,
                    value_line
                );
                
                let dateAtCursor = new markerModel();
                mouse.Position.Observe(
                    (position)=>{
                        if(position.x > 0 &&
                            position.x <= width){
                                var date = value_line.x.invert(position.x);
                                dateAtCursor.Set(date);
                            }
                    }
                )

                add_data_line_overlay(
                    value, // element
                    value_line, // line
                    height, // element height
                    width, // element width
                    dateAtCursor,
                    mouse.Click
                );

                 var startMarkerCache = new MarkerValueCache(value_line_data, value_line.x_parser, value_line.y_parser);
                 var endMarkerCache = new MarkerValueCache(value_line_data, value_line.x_parser, value_line.y_parser);

                 marker_overlay_manager.attachStartRangeListener(
                    startMarkerCache.rangeChange.bind(startMarkerCache));

                marker_overlay_manager.attachEndRangeListener(
                    endMarkerCache.rangeChange.bind(endMarkerCache));

                 overlays.push(new ValueRangeOverlay(
                    value,
                    startMarkerCache,
                    endMarkerCache,
                    all_lines));

                // create a Value at cursor overlay

                let valueMarkerCache = new MarkerValueCache(value_line_data, value_line.x_parser, value_line.y_parser);
                dateAtCursor.Observe(valueMarkerCache.rangeChange.bind(valueMarkerCache));

                let purchased_line = all_lines.lines[1];
                var purchased_line_data = purchased_line.lineData;
                let purchasedMarkerCache = new MarkerValueCache(purchased_line_data, purchased_line.x_parser, purchased_line.y_parser);
                dateAtCursor.Observe(purchasedMarkerCache.rangeChange.bind(purchasedMarkerCache));
                
                let valAtCurOverlay = 
                new ValueAtCursorOverlay(
                    [valueMarkerCache, purchasedMarkerCache],
                    mouse
                );

                },
             value_data);
}

function draw_10YearPred(chart_width, chart_height) {
    var year_predicions = add_chart("#tenyearPred");

    create_bars(
        chart_height - margin.top - margin.bottom,
        chart_width - margin.left - margin.right,
        year_predicions, scale_element, "Data/year_predictions.tsv",
        function(d){return (d3.timeParse("%d/%m/%y")(d.date)).getFullYear()},
        function(d){return d.value;} );
}

function draw_1YearPred(chart_width, chart_height) {
    var year_predicions = add_chart("#oneyearPred");

    var oneYear = {
        name : "oneYear"
    }
    chart_data.push(oneYear);

    var height =  chart_height - margin.top - margin.bottom;
    var width = chart_width - margin.left - margin.right;

    create_line(
        height,
        width,
        year_predicions, scale_element,
        function(func){
            d3.tsv("Data/1Yearforecast.tsv", function(error, data) {
    
            let forecast_line = new Line(data);
            forecast_line.Set_Y_parser(function(d){return d.value.replace(",", "");});
            forecast_line.Set_X_parser(function(d){return d3.timeParse("%d/%m/%y")(d.date);});
            forecast_line.Area_Styler(function(element){ element.attr("class", "no_area")});
            forecast_line.Styler(function(element){ element.attr("stroke", "rgb(89, 89, 89)")});
    
            func([forecast_line]);
         })},
        function(all_lines){
            
            // Overlays
            oneYear = all_lines.lines[0];


            let mouse = create_mouse_model(
                year_predicions,
                width,
                height,
                oneYear
            );
            
            let dateAtCursor = new markerModel();
            mouse.Position.Observe(
                (position)=>{
                    var date = oneYear.x.invert(position.x);
                    dateAtCursor.Set(date);
                }
            )


            add_data_line_overlay(
                year_predicions,
                 oneYear,
                  height,
                   width,
                    dateAtCursor,
                mouse.Click);
        },
        oneYear);

}

function draw_monthGainsPred(chart_width, chart_height) {

    var monthly_gains = add_chart("#monthGains");
    create_bars(
        chart_height - margin.top - margin.bottom,
        chart_width - margin.left - margin.right,
        monthly_gains, scale_element, "Data/monthly_gains.tsv",
        function(d){return (d3.timeParse("%d/%m/%y")(d.date)).getFullYear()},
        function(d){return d.value;} );
}


function draw_weight(chart_width, chart_height) {

    var radius = Math.min(chart_width, chart_height) / 2;

    var color = d3.scaleOrdinal()
        .range(["#cecece","#b7b7b7", "#7a7a7a"]);

    var arc = d3.arc()
        .outerRadius(radius - 10)
        .innerRadius(0);

    var labelArc = d3.arc()
        .outerRadius(radius - 40)
        .innerRadius(radius - 40);

    var pie = d3.pie()
        .sort(null)
        .value(function(d) { return d.Weight; });

    var svg = d3.select("#weight_chart")
        .attr("width", chart_width)
        .attr("height", chart_height)
    .append("g")
        .attr("transform", "translate(" + chart_width / 2 + "," + chart_height / 2 + ")");

    d3.tsv("/Data/HoldingData.tsd", type, function(error, data) {
        if (error) throw error;

        var g = svg.selectAll(".arc")
            .data(pie(data))
            .enter().append("g")
            .attr("class", "arc");

        g.append("path")
            .attr("d", arc)
            .style("fill", function(d) { return color(d.data.Name); });

    });

function type(d) {
  d.Weight = +d.Weight;
  return d;
}

}


function draw_holding_value(chart_name, holding_name, chart_width, chart_height) {
    var value = add_chart("#"+chart_name);

    var holding = {
        name : "holding"
    }
    chart_data.push(holding);

    let height = chart_height - margin.top - margin.bottom;
    let width = chart_width - margin.left - margin.right;

    let time_parser = function(d){return d3.timeParse("%Y-%m-%e")(d.ValidOn);};
    let val_parser = function(d){return parseFloat(d.Value.replace(",", ""));};

    create_line(
             height,
             width,
             value,
             scale_element,
             function(func){
                 d3.tsv("Data/HoldingGainLoss.tsd?holding="+holding_name, function(error, gain_loss_data) {
                    d3.tsv("Data/HoldingValue.tsd?holding="+holding_name, function(error, value_data) {
                        
                        for(let i = 0; i < value_data.length; i++){
                            gain_loss_data[i].Value =
                                parseFloat(value_data[i].Value.replace(",", ""))
                                    - parseFloat(gain_loss_data[i].Gain_Loss.replace(",", ""));
                        }

                        let gain_loss_line = new Line(gain_loss_data);
                        gain_loss_line.Set_Y_parser(function(d){return d.Value;});
                        gain_loss_line.Set_X_parser(function(d){return d3.timeParse("%Y-%m-%e")(d.ValidOn);});
                        gain_loss_line.Area_Styler(function(element){ element.attr("class", "secondary_area")});
                        gain_loss_line.Styler(function(element){ element.attr("class", "secondary_line")});
                        
                        let value_line = new Line(value_data);
                        value_line.Set_Y_parser(function(d){return parseFloat(d.Value.replace(",", ""))});
                        value_line.Set_X_parser(function(d){return d3.timeParse("%Y-%m-%e")(d.ValidOn);});
                        value_line.Area_Styler(function(element){ element.attr("class", "area")});
                        value_line.Styler(function(element){ element.attr("class", "primary_line")});
                        
                        
                        
                        let lines = [];
                        lines.push(value_line);
                        lines.push(gain_loss_line);
                        
                        
                        func(lines);
                    });
             })},
             function(all_lines){
               
                var value_line = all_lines.lines[0];
                var value_line_data = value_line.lineData;
                
                // Overlays
                holding.lineData = value_line_data;


                let mouse = create_mouse_model(
                    value,
                    width,
                    height,
                    value_line
                );
                
                let dateAtCursor = new markerModel();
                mouse.Position.Observe(
                    (position)=>{
                        var date = value_line.x.invert(position.x);
                        dateAtCursor.Set(date);
                    }
                )

                add_data_line_overlay(value, value_line, height, width, dateAtCursor, mouse.Click);

                var startMarkerCache = new MarkerValueCache(value_line_data, time_parser, val_parser);
                var endMarkerCache = new MarkerValueCache(value_line_data, time_parser, val_parser);

                marker_overlay_manager.attachStartRangeListener(
                    startMarkerCache.rangeChange.bind(startMarkerCache));

                marker_overlay_manager.attachEndRangeListener(
                    endMarkerCache.rangeChange.bind(endMarkerCache));

                
                // create the text overlay
                overlays.push(new HoldingRangeOverlay(
                    value,
                    startMarkerCache,
                    endMarkerCache,
                    all_lines));

                    let valueMarkerCache = new MarkerValueCache(value_line_data, value_line.x_parser, value_line.y_parser);
                    dateAtCursor.Observe(valueMarkerCache.rangeChange.bind(valueMarkerCache));
    
                    let purchased_line = all_lines.lines[1];
                    var purchased_line_data = purchased_line.lineData;
                    let purchasedMarkerCache = new MarkerValueCache(purchased_line_data, purchased_line.x_parser, purchased_line.y_parser);
                    dateAtCursor.Observe(purchasedMarkerCache.rangeChange.bind(purchasedMarkerCache));
                    
                    let valAtCurOverlay = 
                    new ValueAtCursorOverlay(
                        [valueMarkerCache, purchasedMarkerCache],
                        mouse
                    );

            },
             holding);
      
}