<?php
	$protocol=$_POST['data'];

	//echo exec("sudo python sendSerial.py $protocol 2>&1");
	exec("sudo python sendSerial.py $protocol");
?>