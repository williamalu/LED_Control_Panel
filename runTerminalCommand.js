$(document).ready(function(){
	$('#both_people').click(function(){
                $.post('sendTerminalCommand.php',{data: "0"},function(response){
                });
	});

	$('#shane').click(function(){
                $.post('sendTerminalCommand.php',{data: "1"},function(response){
                });
	});

	$('#william').click(function(){
                $.post('sendTerminalCommand.php',{data: "2"},function(response){
                });
	});
	
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
                $.post('sendTerminalCommand.php',{data: "f"},function(response){
                });
	});

	$('#redChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "g"},function(response){
                });
	});

	$('#greenChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "h"},function(response){
                });
	});

	$('#blueChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "i"},function(response){
                });
	});

	$('#random').click(function(){
                $.post('sendTerminalCommand.php',{data: "j"},function(response){
                });
	});
});