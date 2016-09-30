$(document).ready(function(){
		
		$('#off').click(function(){
        $.post('sendTerminalCommand.php',{data: "0"});
		});

		$('#on').click(function(){
        $.post('sendTerminalCommand.php',{data: "1"});
		});

		$('#red').click(function(){
        $.post('sendTerminalCommand.php',{data: "2"});
		});

		$('#green').click(function(){
        $.post('sendTerminalCommand.php',{data: "3"});
		});

		$('#blue').click(function(){
        $.post('sendTerminalCommand.php',{data: "4"});
		});

		$('#fullRainbow').click(function(){
        $.post('sendTerminalCommand.php',{data: "5"});
		});

    $('#rainbow').click(function(){
        $.post('sendTerminalCommand.php',{data: "6"});
    });

		$('#redChase').click(function(){
        $.post('sendTerminalCommand.php',{data: "7"});
		});

		$('#greenChase').click(function(){
        $.post('sendTerminalCommand.php',{data: "8"});
		});

		$('#blueChase').click(function(){
        $.post('sendTerminalCommand.php',{data: "9"});
		});

		$('#random').click(function(){
        $.post('sendTerminalCommand.php',{data: "10"});
		});

		$(document).keypress(function(e) {
				if(e.which == 13) {
						console.log("hooray!");
				}
		});
});
