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
});