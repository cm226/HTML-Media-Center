class MonthlyReport{

    constructor(){

        this._months = new Array();
        this._months[0] = "Jan";
        this._months[1] = "Feb";
        this._months[2] = "Mar";
        this._months[3] = "Apr";
        this._months[4] = "May";
        this._months[5] = "Jun";
        this._months[6] = "Jul";
        this._months[7] = "Aug";
        this._months[8] = "Sep";
        this._months[9] = "Oct";
        this._months[10] = "Nov";
        this._months[11] = "Dec";
  
    }

    mod (n, m) {
        return ((n % m) + m) % m;
    }

    find_first_of_month(start_index, month){

        for(let i = start_index; i < this._gain_loss_data.length; i++){
            let time = d3.timeParse("%Y-%m-%e")(this._gain_loss_data[i].valid_on);
            
            if((time.getMonth() == month &&
               time.getDay() == 1) ||
               time.getMonth() == this.mod(month-1 , 12)){
                return i;
            }
        }
        return -1;

    }

    gain_loss_to_int (gain){
        return parseInt(gain.replace(',', ''));
    }

    calc_month_gain (start_index, end_index){

        let month_gain = 
            this.gain_loss_to_int(this._gain_loss_data[end_index].gain_loss) - 
            this.gain_loss_to_int(this._gain_loss_data[start_index].gain_loss);
  
        return month_gain
    }

    fill_in_report(element, report){
    
        let html = '<table class="report"><tr>';
        for(let i = 0; i < 3; i++){
            html += '<th class="report_header">' + report[i].month + '</th>';
        }
        html += '</tr><tr>';
        for(let i = 0; i < 3; i++){
            html+= '<td>£' + report[i].gain + '</td>';
        }
        html += '</tr>';
        html += '</table>';

        let total = report.reduce(
            (total, number)=>{
                total.gain += number.gain;
                return total;
          }
          );
          html += '<span> Yr : £'+
            total.gain +
            '</span>/ £'+Math.round(total.gain/report.length)+ '<span class="small"> per month</span>';
          
          element.append(html);
    }

    Populate(element){

        d3.tsv("Data/GainLoss.tsd", (error, data)=> {
                  
            this._gain_loss_data = data.reverse();
            let now = new Date();
  
            let last_index = 0;
            let report_data = [];
            let date = now;
            date.setDate(1);
            for(let i = 0; i < 12; i++){
                
                let first_of_month = this.find_first_of_month(last_index,date.getMonth());
                if(first_of_month == -1){
                    console.log("Failed to find the first of month"+date);
                    break;
                }
                report_data[i] = {
                    gain    :  this.calc_month_gain(first_of_month, last_index),
                    month   :  this._months[date.getMonth()]
                }

                last_index = first_of_month;
                date.setMonth(date.getMonth()-1)
                date.setDate(1);

            }
            this.fill_in_report(element, report_data);

        });
    }


}

