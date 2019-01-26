// install our service worker
if ('serviceWorker' in navigator) {
    navigator.serviceWorker.register('shopping-worker.js');

    navigator.serviceWorker.addEventListener('message', function(event){
        if(event.data === "connected"){
            $(".status").css("background-color", "green");
            $(".status").html(event.data);
        }
        
        console.log("Client 1 Received Message: " + event.data);
        
    });
}

navigator.serviceWorker.ready.then(function(swRegistration) {
    return swRegistration.sync.register('sync');
});


var _meals;

var _selectedMeals = {
}

var _extraIngreds = []
;

function removeSelectedMeal(meal){
    if(_selectedMeals[meal] !== undefined){
        delete _selectedMeals[meal];
        SendSelectedToServer();
        displaySelected();
    }
}

function displaySelected(){

    let meal_html = '';
    let sainsbo_html = '<form><fieldset data-role="controlgroup"><div class="ui-controlgroup-controls">';
    let alid_html = '<form><fieldset data-role="controlgroup"><div class="ui-controlgroup-controls">';

    let checkbox_id = 0;
    let ingreds = [];
    $.each(_selectedMeals, (meal, ingredients)=>{
        meal_html += '<tr><td>' + meal +
         '</td><td><button onClick=\'removeSelectedMeal("'+
            meal+
          '");\'>Delete</button></td></tr>';

          ingreds = ingreds.concat(ingredients);
    });

    ingreds = ingreds.concat(_extraIngreds);

    $.each(ingreds, (index, ingredient)=>{
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

function SendSelectedToServer(){

    $.post("/plugins/ShoppingList/UpdateSelected",
    JSON.stringify(_selectedMeals),
    function(data, status){
        // handle error, should prob look for ack of some kind ..... w/e
    });
}

function GetAndDisplaySelected(){
    $.get("/plugins/ShoppingList/GetSelected",
    {},
    function(data, status){
        _selectedMeals = JSON.parse(data);
        displaySelected();
    });
}


$( document ).ready(function() {

    $.get("/plugins/ShoppingList",{},
    function(data, status){

        data = data.replace("\n", "");

        _meals = JSON.parse(data);

        GetAndDisplaySelected();

        $( "#meal-list" ).autocomplete({
            source: Object.keys(_meals),
            select: function (event, ui) {

                _selectedMeals[ui.item.value] = _meals[ui.item.value];
                SendSelectedToServer();

                displaySelected();
            }
          });

        $("#aldi_extras").keyup(function(event) {
            if (event.keyCode === 13) {
                _extraIngreds.push({
                    ingred : $("#aldi_extras").val(),
                    store : "Aldi"
                });
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
                displaySelected();
                $("#sainsbo_extras").val("");
            }
        });
    });

});