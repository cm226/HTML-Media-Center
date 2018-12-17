var _meals;

var _selectedMeals = {
}

function removeSelectedMeal(meal){
    if(_selectedMeals[meal] !== undefined){
        delete _selectedMeals[meal];
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

$( document ).ready(function() {

    

    $.post("/plugins/ShoppingList",{},
    function(data, status){

        data = data.replace("\n", "");

        _meals = JSON.parse(data).meals;

        console.log("Data: " + _meals + "\nStatus: " + status);

        $( "#meal-list" ).autocomplete({
            source: Object.keys(_meals),
            select: function (event, ui) {

                _selectedMeals[ui.item.value] = _meals[ui.item.value];

                displaySelected();
            }
          });
    });

});