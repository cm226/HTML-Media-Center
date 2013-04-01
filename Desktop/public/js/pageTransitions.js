$(document).ready(function() {
    $("#content").css("display", "none");
 
    $("#content").fadeIn(2000);
 
    $("a.navLink").click(function(event){
        event.preventDefault();
        linkLocation = this.href;
        $("#content").fadeOut(1000, redirectPage);     
    });
         
    function redirectPage() {
        window.location = linkLocation;
    }
});
