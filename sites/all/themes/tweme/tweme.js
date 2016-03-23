(function($) {
  $(function () {
    // Code to get user location.
    $.cookie.json = true;
    if ($.cookie("user_location") !== '') {
      console.log($.cookie("user_location"));
    }
    else {
      if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(function(position) {
          // console.log(position.coords);
          var requestUrl = "http://ip-api.com/json";
          $.ajax({
            url: requestUrl,
            type: 'GET',
            success: function(json){
              // console.log(json);
              $.cookie("user_location", json);
            },
            error: function(err){
              alert("Request failed, error= " + err);
            }
          });
        });
      }
    }
  });
})(jQuery);
