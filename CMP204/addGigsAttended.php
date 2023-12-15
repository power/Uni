<?php

    include_once ("includes/connection.php");


    $addGig = $_POST['doIAdd'];
    if ($addGig == "1")
    {
        $query = "ALTER TABLE cmp204accountss ADD gig4 varchar(255)";
        mysqli_query($conn, $query);
    }
    //SQL query to insert gig to database

    //redirect user back to profile
    //header("Location: http://www.example.com/");

?>