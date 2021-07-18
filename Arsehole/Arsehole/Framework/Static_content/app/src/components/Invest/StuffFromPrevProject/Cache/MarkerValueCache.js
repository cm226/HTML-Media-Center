import {Observable} from '../observable'

export class MarkerValueCache extends Observable {

    constructor(
            data,
            time_parser,
            val_parser
        ){
            super();
            this.value = 0;
            this.haveValue = false;
            this.data = data;
            this.date = 0;
            this.time_parser = time_parser;
            this.val_parser = val_parser;
        }

        binaryIndexOf(list, comp, searchElement) {
            'use strict';
         
            var minIndex = 0;
            var maxIndex = list.length - 1;
            var currentIndex;
            var currentElement;
         
            while (minIndex <= maxIndex) {
                currentIndex = (minIndex + maxIndex) / 2 | 0;
                currentElement = list[currentIndex];
         
                if (comp(currentElement, searchElement) < 0) {
                    minIndex = currentIndex + 1;
                }
                else if (comp(currentElement, searchElement) > 0) {
                    maxIndex = currentIndex - 1;
                }
                else {
                    return currentIndex;
                }
            }
         
            return currentIndex;
        }

        rangeChange(date) {
            if(!date){
              this.haveValue = false;
              this.Notify();
              return;
            }
            var time_parser = this.time_parser;

            var index = this.binaryIndexOf(this.data,
                (left, right)=>{return time_parser(left) - right;},
                date);

            this.value = this.val_parser(this.data[index]);
            this.date = date;
            this.haveValue = true;
            this.Notify();
            
        }

        Value(){
            return this.value;
        }

        Date() {
            return this.date;
        }

        HasValue(){
            return this.haveValue;
        }


}