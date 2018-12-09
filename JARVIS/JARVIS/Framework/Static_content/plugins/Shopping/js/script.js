$( document ).ready(function() {
	var meals = [
      "Korma",
      "Chicken",
    ];
	
	var recipes = [
		["Korma",['cream','korma sauce']],
		["Chicken Roast",['chicken','carrots','parsnips','potatos','trex']],
	];
    $( "#meal-list" ).autocomplete({
      source: meals,
	  select: function (event, ui) {
        
        console.log(ui.item.value);
		console.log(recipes);
      }
    });
});