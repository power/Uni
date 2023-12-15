<?php
    include_once ("includes/connection.php");

    $id = $_COOKIE['id'];

    $query = "DELETE FROM cmp204accountss WHERE '".$id."'";

    header("Location: logout.php");
?>