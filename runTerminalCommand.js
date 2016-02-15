var xhttp;

if (window.XMLHttpRequest) {
	//code for modern browsers
	xhttp = new XMLHttpRequest();
}
else {
	//code to support IE6, IE5
	xhttp = new ActiveXObject("Microsoft.XMLHTTP")
}

var on = document.getElementById("on");
var off = document.getElementById("off");

on.onclick = function() {turnOn()};

function turnOn() {
	request.open( "GET", "sendTerminalCommand.php?switchCase=" + switchCase, true);
}