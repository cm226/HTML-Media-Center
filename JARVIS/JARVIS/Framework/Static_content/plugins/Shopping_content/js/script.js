// install our service worker
if ('serviceWorker' in navigator) {
    navigator.serviceWorker.register('shopping-worker.js');

    navigator.serviceWorker.addEventListener('message', function(event){
        if(event.data === "connected"){
            $(".status").css("background-color", "green");
            $(".status").html(event.data);
        }
        
    });
}

navigator.serviceWorker.ready.then(function(swRegistration) {
    return swRegistration.sync.register('sync');
});


var _server_state;
var _extraIngreds = [];


function removeSelectedMeal(meal){
    if(_server_state[meal] !== undefined){
        _server_state[meal].selected = 0;
        $.each(_server_state[meal].ingreds, (index, ingred)=>{
            ingred.selected = "0";
        });

        SendStateToServer();
        displaySelected();
    }
}

function displaySelected(){

    let meal_html = '';
    let sainsbo_html = '<form><fieldset data-role="controlgroup"><div class="ui-controlgroup-controls">';
    let alid_html = '<form><fieldset data-role="controlgroup"><div class="ui-controlgroup-controls">';

    let checkbox_id = 0;
    let ingreds = [];
    $.each(_server_state, (meal_name, meal)=>{

        if(meal.selected){
            meal_html += '<tr><td>' + meal_name +
            '</td><td><button onClick=\'removeSelectedMeal("'+
            meal_name+
             '");\'>Delete</button></td></tr>';
        }
        
        ingreds = ingreds.concat(meal.ingreds);
    });

    ingreds = ingreds.concat(_extraIngreds);

    $.each(ingreds, (index, ingredient)=>{
        if(ingredient.selected === "0"){
            return true;// contune
        }
        checkbox_id++;

        let html = 
        '<div class="ui-checkbox">\
        <label for="checkbox'+checkbox_id+'" class="ui-btn ui-corner-all ui-btn-b ui-btn-icon-left ui-first-child">'+ingredient.ingred+'\
        <input type="checkbox" name="checkbox'+checkbox_id+'" id="checkbox'+checkbox_id+'">\
        </input></label></div>';

        if(ingredient.store === 'Sainsbury'){
            sainsbo_html += html;

        } else if(ingredient.store === 'Aldi') {
            alid_html += html;
        }
        
    });

    alid_html += '</div></fieldset></form>';
    sainsbo_html += '</div></fieldset></form>';

    $('#meals').html(meal_html);

    $('#aldi_list').html(alid_html);
    $('#sainsbury_list').html(sainsbo_html);
}

function SendStateToServer(){

    $.post("/plugins/ShoppingList/UpdateSelected",
    JSON.stringify(_server_state),
    function(data, status){
        // handle error, should prob look for ack of some kind ..... w/e
    });
}

function SendExtrasToServer(){
    if(_extraIngreds.length !== 0){
        $.post("/plugins/ShoppingList/UpdateExtras",
        "{ \"extras\" : " + JSON.stringify(_extraIngreds) + "}",
        function(data, status){
            // handle error, should prob look for ack of some kind ..... w/e
        });
    }
}

$( document ).ready(function() {

    $.get("/plugins/ShoppingList",{},
    function(data, status){

        data = data.replace("\n", "");

        // contains all meals, ingredients and selected state in the format
        /*
        {
            mealname : {
                selected: true/false,
                ingreds : [
                    {
                        ingred : name
                        store: store,
                        selected : true/false
                    }
                ]
            },
            ...
        }
        */
        _server_state = JSON.parse(data);

        displaySelected();

        $( "#meal-list" ).autocomplete({
            source: Object.keys(_server_state),
            select: function (event, ui) {

                _server_state[ui.item.value].selected = "1";
                $.each(_server_state[ui.item.value].ingreds, (index, ingred)=>{
                    ingred.selected = "1"
                });

                SendStateToServer();

                displaySelected();
            }
          });

    });

    $.get("/plugins/ShoppingList/GetExtras",{},
    function(data,status){
        var i = 0;

        _extraIngreds = JSON.parse(data).extras;
        displaySelected();
        $("#aldi_extras").keyup(function(event) {
            if (event.keyCode === 13) {

                _extraIngreds.push({
                    ingred : $("#aldi_extras").val(),
                    store : "Aldi"
                });
                SendExtrasToServer();
                displaySelected();
                $("#aldi_extras").val("");
            }
        });

        $("#sainsbo_extras").keyup(function(event) {
            if (event.keyCode === 13) {
                _extraIngreds.push({
                    ingred : $("#sainsbo_extras").val(),
                    store: "Sainsbury"
                });
                SendExtrasToServer();
                displaySelected();
                $("#sainsbo_extras").val("");
            }
        });
        
    });

    
        

});