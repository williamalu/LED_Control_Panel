$(document).ready(function(){	
	$('#off').click(function(){
                $.post('sendTerminalCommand.php',{data: "a"},function(response){
                });
	});

	$('#on').click(function(){
                $.post('sendTerminalCommand.php',{data: "b"},function(response){
                });
	});

	$('#red').click(function(){
                $.post('sendTerminalCommand.php',{data: "c"},function(response){
                });
	});

	$('#green').click(function(){
                $.post('sendTerminalCommand.php',{data: "d"},function(response){
                });
	});

	$('#blue').click(function(){
                $.post('sendTerminalCommand.php',{data: "e"},function(response){
                });
	});

	$('#rainbow').click(function(){
                $.post('sendTerminalCommand.php',{data: "5"},function(response){
                });
	});

	$('#redChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "6"},function(response){
                });
	});

	$('#greenChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "7"},function(response){
                });
	});

	$('#blueChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "8"},function(response){
                });
	});

	$('#rainbowChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "9"},function(response){
                });
	});
});