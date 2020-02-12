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

function onClearAll(){
    
    _server_state = {};
    _extraIngreds = [];
        
    SendStateToServer();
    SendExtrasToServer();
    displaySelected();
}

function selectMeal(mealName){
    _server_state[mealName].selected = "1";
    $.each(_server_state[mealName].ingreds, (index, ingred)=>{
        ingred.selected = "1"
    });
}


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

function unselectIngredient(ingred_name){
    let found = false;
    $.each(_server_state, (index, meal)=>{
        $.each(meal.ingreds, (index, ingred)=>{
            if(ingred.ingred === ingred_name &&
                ingred.selected === "1"){
                ingred.selected = "0";
                SendStateToServer();
                displaySelected();
                found = true;  
                return; 
            }
        });
        if(found) return;
    });

    if(found) return;

    let index_to_remove = -1;
    $.each(_extraIngreds, (index, ingred)=>{
        if(ingred.ingred === ingred_name){
            index_to_remove = index;
            found = true;   
            return
        }
    });
    
    if(found){
        _extraIngreds.splice(index_to_remove,1);
        SendExtrasToServer();
        displaySelected();
        return;
    }

    console.error("failed to find ingredient: "+ingred_name + " in ingreds list");
}

function displaySelected(){

    let meal_html = '';
    let sainsbo_html = '<form><fieldset data-role="controlgroup"><div class="ui-controlgroup-controls">';
    let alid_html = '<form><fieldset data-role="controlgroup"><div class="ui-controlgroup-controls">';

    let checkbox_id = 0;
    let ingreds = {};
    
    $('#fullMealList').empty();

    $.each(_server_state, (meal_name, meal)=>{

        $('#fullMealList').append('<li class="fullMealListSelectBttn ui-li-static ui-body-inherit ui-first-child">'+meal_name+'</li>');

        if(!meal.selected){
            return;
        }

        meal_html += '<tr><td class="meal-name">' + meal_name +
        '</td><td class="meal-delete"><button class="delete-bttn" onClick=\'removeSelectedMeal("'+
        meal_name+
            '");\'><img src="https://image.flaticon.com/icons/png/128/579/579006.png"/></button></td></tr>';
        
        
        $.each(meal.ingreds, (index, ingredient)=>{
            if(ingreds[ingredient.ingred] === undefined){
                ingreds[ingredient.ingred] = ingredient;
                ingreds[ingredient.ingred].meals = [];
            }
            
            ingreds[ingredient.ingred].meals.push(meal_name);
            
        });
    });

    $(".fullMealListSelectBttn").on("tap", (event)=>{

        selectMeal(event.target.innerText);
        
        SendStateToServer();

        $( '#dialogPage' ).dialog( 'close' );
        displaySelected();

    });

    $.each(_extraIngreds, (index, ingredient)=>{
        if(ingreds[ingredient.ingred] === undefined){
            ingreds[ingredient.ingred] = ingredient;
            ingreds[ingredient.ingred].meals = [];
        }

        ingreds[ingredient.ingred].meals.push("extra");
    });


    $.each(ingreds, (name, ingredient)=>{
        if(ingredient.selected === "0"){
            return true;// contune
        }
        checkbox_id++;

        let html = 
        '<div class="ui-checkbox">\
        <label for="checkbox'+checkbox_id+'" class="ui-btn ui-corner-all ui-btn-b ui-btn-icon-left ui-first-child">'+ingredient.ingred+'\
        <span class="meal_list">('+ingredient.meals.toString()+') </span>\
        <input type="checkbox" name="checkbox'+checkbox_id+'" id="checkbox'+checkbox_id+'">\
        <button class="delete-bttn" onClick="unselectIngredient(\''+ingredient.ingred+'\')">\
        <img src="https://image.flaticon.com/icons/png/128/579/579006.png"/>\
        </button>\
        </input></label>\
        </div>';

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
    $.post("/plugins/ShoppingList/UpdateExtras",
    "{ \"extras\" : " + JSON.stringify(_extraIngreds) + "}",
    function(data, status){
        // handle error, should prob look for ack of some kind ..... w/e
    });
}

window.onerror = function(message, source, lineno, colno, error) {

    $.post("/plugins/ClientLogger/logError",
    JSON.stringify({
        message : message, 
        source : source,
        lineno : lineno,
        colno : colno,
        stack : error.stack
    }));

}

$( document ).ready(function() {

    let error_handler = function(jqXHR, textStatus, errorThrown){
        $.post("/plugins/ClientLogger/logError",
        JSON.stringify({
            jqXHR : jqXHR, 
            textStatus : textStatus,
            errorThrown : errorThrown,
        }));
    };

    let extras_handler = function(data,status){
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
        
    };

    let list_handler = function(data, status){

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

        $.get("/plugins/ShoppingList/GetExtras",{},extras_handler).error(error_handler);
        displaySelected();

        $( "#meal-list" ).autocomplete({
            source: Object.keys(_server_state),
            select: function (event, ui) {

                selectMeal(ui.item.value);

                SendStateToServer();

                displaySelected();

                $(this).val('');
                return false;
            }
          });

        $( "#dialog" ).dialog({ autoOpen: false });

    }

    $.get("/plugins/ShoppingList",{},list_handler)
    .error(error_handler);

    
        

});