$(document).ready(function(){	
	$('#off').click(function(){
                $.post('sendTerminalCommand.php',{data: "0"},function(response){
                });
	});

	$('#on').click(function(){
                $.post('sendTerminalCommand.php',{data: "1"},function(response){
                });
	});

	$('#red').click(function(){
                $.post('sendTerminalCommand.php',{data: "2"},function(response){
                });
	});

	$('#green').click(function(){
                $.post('sendTerminalCommand.php',{data: "3"},function(response){
                });
	});

	$('#blue').click(function(){
                $.post('sendTerminalCommand.php',{data: "4"},function(response){
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