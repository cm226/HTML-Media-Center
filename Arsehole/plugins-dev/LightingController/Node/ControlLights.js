

function parseArgs(){ 
  let args = process.argv.slice(2);

  let parsed = {};
  let arg_index = 0;
  while (arg_index < args.length){
    switch (args[arg_index]){

      case 'state' : 
        parsed.state = args[arg_index+1] == 'on' ? true : false;
        arg_index = arg_index+2;
      break;
      case 'brightness' :
        parsed.brightness = parseInt(args[arg_index+1]);
        
        if(parsed.brightness === NaN ||
          parsed.brightness < 0 ||
          parsed.brightness > 255){
            console.log("Failed to convert brighness to value, enter between 0 - 255");
            process.exit(1);
        } 
        arg_index = arg_index+2;
      break;
      default :
        console.log("unknown arg" + args[arg_index]);
        process.exit(1);
      break;
    }
  }
  

  return parsed;

}

const Light = require('./Light.js');

const parsedArgs = parseArgs();

let light1 = new Light({
  ip : '192.168.1.83',
  id: '63466630cc50e322ed67',
  key: 'c96540c52518dcd6' 
});

let light2 = new Light({ 
  ip : '192.168.1.84',
  id: '63466630cc50e3c99342',
  key: '262fda50ddb03d07' 
});

let light1Promice = new Promise((resolve, reject)=>{
  light1.SendState(parsedArgs,resolve);
});

let light2Promice = new Promise((resolve, reject)=>{
  light2.SendState(parsedArgs,resolve);
});


light1Promice.then((light1Data)=>{
  light2Promice.then((light2Data)=>{
    console.log(JSON.stringify({
      light1 : light1Data,
      light2 : light2Data
    }));
    process.exit(0);
  });
}).catch((e)=>{
  console.log(JSON.stringify({
    error : e.toString()
  }));
  process.exit(1);
});

