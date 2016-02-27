$(document).ready(function(){

	//var websocket;
	//var apiKey = 'o.MzWdvlC42NMaUlyr8rBnTqaCert5frFr';
	//var apiKey = 'o.WdMp1Mnur5DnjRY00R8gW9la6dMB7Wai';
	//websocket = new WebSocket('wss://stream.pushbullet.com/websocket/' + apiKey);
	
	//websocket.onmessage = function(e) {
	//	//console.log('e.data: ' + JSON.stringify(e.data));
	//	//console.log(JSON.parse(e.data).push.type);
	//	if (JSON.parse(e.data).push.type == "sms_changed") {
	//		$.post('sendTerminalCommand.php',{data: "z"});
	//	}
	//}

	$('#both_people').click(function(){
                $.post('sendTerminalCommand.php',{data: "0"});
	});

	$('#shane').click(function(){
                $.post('sendTerminalCommand.php',{data: "1"});
	});

	$('#william').click(function(){
                $.post('sendTerminalCommand.php',{data: "2"});
	});
	
	$('#off').click(function(){
                $.post('sendTerminalCommand.php',{data: "a"});
	});

	$('#on').click(function(){
                $.post('sendTerminalCommand.php',{data: "b"});
	});

	$('#red').click(function(){
                $.post('sendTerminalCommand.php',{data: "c"});
	});

	$('#green').click(function(){
                $.post('sendTerminalCommand.php',{data: "d"});
	});

	$('#blue').click(function(){
                $.post('sendTerminalCommand.php',{data: "e"});
	});

	$('#rainbow').click(function(){
                $.post('sendTerminalCommand.php',{data: "f"});
	});

	$('#redChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "g"});
	});

	$('#greenChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "h"});
	});

	$('#blueChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "i"});
	});

	$('#random').click(function(){
                $.post('sendTerminalCommand.php',{data: "j"});
	});
});