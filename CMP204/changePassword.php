<?php 

    include_once ("includes/connection.php");


    $currentPW = $_POST['currentPassword'];
    $newPW = $_POST['newPassword'];
    $id = $_COOKIE['id'];

    $query2 = "SELECT password FROM cmp204accountss WHERE id = '$id'";
    $result2 = mysqli_query($conn, $query2);
    $row2 = mysqli_fetch_array($result2);
    $hash = $row2['password'];

    if(password_verify($currentPW, $hash))
    {
        $newHash = password_hash($newPW);
        $query = "UPDATE cmp204accountss SET password = '$newHash' WHERE id = '$id'";
        $result = mysqli_query($conn, $query);
    }

    header("Location: index.php");
?>

