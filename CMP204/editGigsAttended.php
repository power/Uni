<?php

    include_once ("includes/connection.php");


    $gigID = $_POST['changeGigID'];
    $id = $_COOKIE["id"];

    if($gigID == "gig1")
    {
        $query = "SELECT gig1 FROM cmp204accountss WHERE id='".$id."'";
        $result = mysqli_query($conn, $query);
        $row = mysqli_fetch_array($result);
        $output = $row[$gigID];
        if($output == 0)
        {
            $query = "UPDATE cmp204accountss SET gig1='1' WHERE id='".$id."'";
            mysqli_query($conn, $query);
        }
        if($output == 1)
        {
            $query = "UPDATE cmp204accountss SET gig1='0' WHERE id='".$id."'";
            mysqli_query($conn, $query);
        }
    }

    if($gigID == "gig2")
    {
        $query = "SELECT gig2 FROM cmp204accountss WHERE id='".$id."'";
        $result = mysqli_query($conn, $query);
        $row = mysqli_fetch_array($result);
        $output = $row[$gigID];
        if($output == 0)
        {
            $query = "UPDATE cmp204accountss SET gig2='1' WHERE id='".$id."'";
            mysqli_query($conn, $query);
        }
        if($output == 1)
        {
            $query = "UPDATE cmp204accountss SET gig2='0' WHERE id='".$id."'";
            mysqli_query($conn, $query);
        }
    }

    if($gigID == "gig3")
    {
        $query = "SELECT gig3 FROM cmp204accountss WHERE id='".$id."'";
        $result = mysqli_query($conn, $query);
        $row = mysqli_fetch_array($result);
        $output = $row[$gigID];
        if($output == 0)
        {
            $query = "UPDATE cmp204accountss SET gig3='1' WHERE id='".$id."'";
            mysqli_query($conn, $query);
        }
        if($output == 1)
        {
            $query = "UPDATE cmp204accountss SET gig3='0' WHERE id='".$id."'";
            mysqli_query($conn, $query);
        }
    }


    
    /*
    $query = mysqli_prepare($conn, "UPDATE cmp204accountss SET ?='0' WHERE id=2");
    mysqli_stmt_bind_param($stmt, "s", $gigID);
    mysqli_stmt_execute($stmt);
    
    $stmt = mysqli_prepare($conn, "UPDATE cmp204accountss SET ?='1' WHERE id=?");
    mysqli_stmt_bind_param($stmt, "si", $gigID, $id);
    mysqli_stmt_execute($stmt);
    
    $query = "UPDATE cmp204accountss SET gig1='0' WHERE id=2";
    mysqli_query($conn, $query);
    */
    header("Location: index.php");
    //SQL query to update gig in database

    //redirect user back to profile
    //header("Location: http://www.example.com/");

?>