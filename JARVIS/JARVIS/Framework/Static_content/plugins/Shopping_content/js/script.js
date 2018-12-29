// install our service worker
if ('serviceWorker' in navigator) {
    navigator.serviceWorker.register('shopping-worker.js');
}

navigator.serviceWorker.ready.then(function(swRegistration) {
    return swRegistration.sync.register('sync');
});


var _meals;

var _selectedMeals = {
}

function removeSelectedMeal(meal){
    if(_selectedMeals[meal] !== undefined){
        delete _selectedMeals[meal];
        SendSelectedToServer();
        displaySelected();
    }
}

function displaySelected(){

    let meal_html = '';
    let sainsbo_html = '';
    let alid_html = '';


    $.each(_selectedMeals, (meal, ingredients)=>{
        meal_html += '<tr><td>' + meal +
         '</td><td><button onClick=\'removeSelectedMeal("'+
            meal+
          '");\'>Delete</button></td></tr>';

        $.each(ingredients, (index, ingredient)=>{
            if(ingredient.store === 'Sainsbury'){
                sainsbo_html += '<li>'+ingredient.ingred+'</li>';
            } else if(ingredient.store === 'Aldi') {
                alid_html += '<li>'+ingredient.ingred+'</li>';
            }
            
        });
    });

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
    });

});