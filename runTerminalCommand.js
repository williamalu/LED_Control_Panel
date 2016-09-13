$(document).ready(function(){
	
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

	$('#fullRainbow').click(function(){
                $.post('sendTerminalCommand.php',{data: "f"});
	});

        $('#rainbow').click(function(){
        	$.post('sendTerminalCommand.php',{data: "g"});
        });

	$('#redChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "h"});
	});

	$('#greenChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "i"});
	});

	$('#blueChase').click(function(){
                $.post('sendTerminalCommand.php',{data: "j"});
	});

	$('#random').click(function(){
                $.post('sendTerminalCommand.php',{data: "k"});
	});
});