<?php

    include_once ("includes/connection.php");
    
    
    $user = trim($_POST['email']);
    $pass = trim($_POST['pwd']);
    $query = "SELECT id FROM cmp204accountss WHERE email = '$user'";
    $result = mysqli_query($conn, $query);
    $row1 = mysqli_fetch_array($result);
    $cookie_name = "id";
    $cookie_value = $row1['id'];
    setcookie($cookie_name, $cookie_value, time() + (85400 * 30), "/");


    $query2 = "SELECT password FROM cmp204accountss WHERE email = '$user' AND id = '$cookie_value'";
    $result2 = mysqli_query($conn, $query2);
    $row2 = mysqli_fetch_array($result2);
    $hash = $row2['password'];
    if(password_verify($pass, $hash))
    {
        $cookie_name = "loggedin";
        $cookie_value = 1;
        setcookie($cookie_name, $cookie_value, time() + (85400 * 30), "/");
        header("Location: userProfile.php");
    }
    else {
        header("Location: index.php");
    }


?>