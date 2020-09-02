$(document).ready(function() {
  $("#add_ingredient_s").keyup(function(event) {
    if (event.keyCode === 13) {
      var new_item  = "<li><div class='li-content'><span class='item'>"+$('#add_ingredient_s').val()+"</span><span class='delete-btn'>x</span></div></li>"
      $('#ingredient_list_sains').append(new_item);
      $('#add_ingredient_s').val('');
    }
  });

  $("#add_ingredient_a").keyup(function(event) {
    if (event.keyCode === 13) {
      var new_item  = "<li><div class='li-content'><span class='item'>"+$('#add_ingredient_a').val()+"</span><span class='delete-btn'>x</span></div></li>"
      $('#ingredient_list_aldi').append(new_item);
      $('#add_ingredient_a').val('');
    }
  });

  $(document).on('click','.delete-btn',function(){
    $(this).parents('li').remove();
  });
});


function submitIngreds(){
  let name = $("#meal_name").val();
  
   let aldi_ingreds = [];
  $("#ingredient_list_aldi").children().each((i, li)=>{
      let ingred = li.children[0].children[0].innerText;
      aldi_ingreds.push(ingred);
  });
  
  let sains_ingreds = [];
  $("#ingredient_list_sains").children().each((i, li)=>{
      let ingred = li.children[0].children[0].innerText;
      sains_ingreds.push(ingred);
  });
  
  
  $.post("/plugins/ShoppingList/AddMeal",
  "{  \"name\" : \""+name+"\",\
      \"aldi\" : " + JSON.stringify(aldi_ingreds) + ",\
      \"sains\" : "+JSON.stringify(sains_ingreds)+ "\
  }").done(
  function(data){
      if(data.trim() !== "OK"){
          window.alert("that meal didnt add correctly.... cba imp reason");
      } else {
        $('#add_ingredient_a').val('');
        $('#add_ingredient_s').val('');
        $('#meal_name').val('');

        document.getElementById('ingredient_list_aldi').innerHTML = ""
        document.getElementById('ingredient_list_sains').innerHTML = ""
      }
  });

}
