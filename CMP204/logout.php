<?php

	setcookie("loggedin", "", time() - 3600, "/");
	setcookie("id", "", time() - 3600, "/");
	header("Location: index.php");
	//redirect user to index.php
	//header("Location: https://mayar.abertay.ac.uk/~2101758/cmp204/coursework/index.php");
?>