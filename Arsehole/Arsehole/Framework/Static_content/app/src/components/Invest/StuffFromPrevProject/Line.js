export class Line{

  constructor(lineData){
    this.lineData = lineData;
    this.styler = function(line){};
    this.area_styler = function(line){};
  }
  
  Styler(styler){
    this.styler = styler;
  }
  
  Area_Styler(styler){
    this.area_styler = styler;
  }
  
  
  Set_Y_parser(y_parser){
    if(!y_parser){
      console.log("invalid Y parser set");
    }
    this.y_parser = y_parser;
  }
  
  Set_X_parser(x_parser){
    if(!x_parser){
      console.log("invalid X parser set");
    }
    this.x_parser = x_parser;
  }
  
  Parse_X(){return this.x_parser;}
  Parse_Y(){return this.y_parser;}

  Set_X_Bounds(f_x){
    this.x = f_x;
  }
  
  Set_Y_Bounds(f_y){
    this.y = f_y;
  }
  


}