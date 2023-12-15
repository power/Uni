
<?php
    include_once ("includes/connection.php");

    // prevent sql injection by sanitising the 

    function strip($data){
        $data = trim($data);
        $data = htmlspecialchars($data);
        return $data;
    }

    
    $user = strip($_POST['email']);
    $pass = strip($_POST['pwd']);
    $hash = password_hash($pass, PASSWORD_DEFAULT);
    $statement = "INSERT INTO `cmp204accountss` (`email`, `password` ) VALUES ('$user', '$hash')";
    // hash the password for security then submit to the database
    mysqli_query($conn, $statement);



    //redirect user back to registration page if unsuccessful, else go to user profile
    //header("Location: http://www.example.com/");
    header("Location: https://mayar.abertay.ac.uk/~2101758/cmp204/coursework/");

?>