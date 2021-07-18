export function color(element) {

    var text = parseFloat(element.text());

    if (text < 0) 
        element.css('color', 'red'); 
    else 
        element.css('color', 'green'); 

}