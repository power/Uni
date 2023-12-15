<?php


    include_once ("includes/connection.php");

    $gigID1 = $_POST['removeGig1'];
    $gigID2 = $_POST['removeGig2'];
    $gigID3 = $_POST['removeGig3'];


    if ($gigID == "1")
    {
        $query = "DELETE FROM gig1";
        mysqli_query($conn, $query);
    }
    if ($gigID == "2")
    {
        $query = "DELETE FROM gig2";
        mysqli_query($conn, $query);
    }
    if ($gigID == "3")
    {
        $query = "DELETE FROM gig3";
        mysqli_query($conn, $query);
    }

    header("Location: index.php");
    //SQL query to delete gig from database

    //redirect user back to profile
    //header("Location: http://www.example.com/");

?>