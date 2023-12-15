<!doctype html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<title>CMP204 Unit Two Coursework Template</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
	<link rel="stylesheet" href="css/style.css">
	<script src="javascript/script.js"></script>
</head>
<body>
    <nav>
        <?php include_once "includes/links.php"; ?>
    </nav>

    <?php 
    if(!isset($_COOKIE['id']))
    {
        header("Location: index.php");
    }

    if(!isset($_COOKIE['firstname']))
    {
        echo '<p class="uParagraph" >We noticed you have not set up your profile yet, please fill in the information below to remove this.</p>  
    <div class="details">
        <form id="details" name="details" method="post" action="userProfile.php">
            <label for="fname">
            </label>
            First Name:<input type="text" id="fname" name="fname">
            <input id="btn" type="submit" >
        </form>
    </div>';

        $cookie_name = "firstname";
        $cookie_value = $_POST["fname"];
        setcookie($cookie_name, $cookie_value, time() + (85400 * 30), "/");
    }

    if(isset($_COOKIE['firstname']))
    {
        echo '<h1>Welcome back, '. $_COOKIE["firstname"] . '</h1>';
    }
    ?>
   

    <h1>Gigs Attended</h1>


    <?php   
    include_once ("includes/connection.php");

    $id = $_COOKIE["id"];
    $query = "SELECT gig1, gig2, gig3 FROM cmp204accountss WHERE id = '$id'";
    $result = mysqli_query($conn, $query);
    $row1 = mysqli_fetch_array($result);
    $output = $row1['gig1'];
    $output2 = $row1['gig2'];
    $output3 = $row1['gig3'];
    ?>

    <div class="container-fluid">
        <div class="row">
            <div class="col-sm-6 col-xs-12" id="gigs">

    <?php
    if($output == "1")
    {
        echo '    <hr class="rounded">
    <h5> Forest Hill Drives - London </h5>
    <p> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
    <h6> Date Attended </h6>
    <p> January 20th 2014</p>
    <hr class="rounded"> ';
    }

    if($output == "0")
    {
        echo '        <hr class="rounded">
        <h5> Forest Hill Drives - London </h5>
        <p> Not attended. Click to change that </p>
        <div class="changeGig">
        <form id="changeGig" name="changeGig" action="editGigsAttended.php" method="post">
            <input type="submit" class="changeGigID" name="changeGigID" value="gig1" action="editGigsAttended.php"/>
        </form>
    </div> 
    <hr class="rounded">';
    }

    if($output2 == "1")
    {
        echo '     <hr class="rounded">
    <h5> Listening Party - KOD </h5>
    <p> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
    <h6> Date Attended </h6>
    <p> March 11th 2018</p>
    <hr class="rounded">';
    }
    if($output2 == "0")
    {
        echo '        <hr class="rounded">
        <h5> Listening Party - KOD </h5>
        <p> Not attended. Click to change that </p>
        <div class="changeGig">
        <form id="changeGig" name="changeGig" action="editGigsAttended.php" method="post">
            <input type="submit" class="changeGigID" name="changeGigID" value="gig2" action="editGigsAttended.php"/>
        </form>
    </div> 
    <hr class="rounded">';
    }
    if($output3 == "1")
    {
        echo '     <hr class="rounded">
    <h5> Meet & Greet - Dreamville </h5>
    <p> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
    <h6> Date Attended </h6>
    <p> December 1st 2021</p>
    <hr class="rounded">';
    }
    if($output3 == "0")
    {
        echo '    
    <hr class="rounded">
        <h5> Meet & Greet - Dreamville </h5>
        <p> Not attended. Click to change that </p>
        <div class="changeGig">
        <form id="changeGig" name="changeGig" action="editGigsAttended.php" method="post">
            <input type="submit" class="changeGigID" name="changeGigID" value="gig3" action="editGigsAttended.php"/>
        </form>
    </div> 
    <hr class="rounded">';
    }
    ?>
    </div>

            <div class="col-sm-6 col-xs-0" id="accountInformation">       
            <p>Are you looking to delete a Gig from your profile? Click below.</p>
        <form id="deleteGigs" name="changeGig" action="editGigsAttended.php" method="post">
            <input type="submit" class="changeGigID" name="changeGigID" value="gig1" action="editGigsAttended.php"/>
        </form>
        <form id="deleteGig1s" name="changeGig1" action="editGigsAttended.php" method="post">
            <input type="submit" class="changeGigID" name="changeGigID" value="gig2" action="editGigsAttended.php"/>
        </form>
        <form id="deleteGigs2" name="changeGig2" action="editGigsAttended.php" method="post">
            <input type="submit" class="changeGigID" name="changeGigID" value="gig3" action="editGigsAttended.php"/>
        </form>
        <br> 

        <h7> Account Management </h7>
        <h6>Delete your account</h6>
            <div class="deleteAccounts">
                <form id="deleteAccount" name="deleteAccount" class="accountDeletion" action="processDeletion.php" method="post">
                    <input type="submit" class="btn">
                </form>
            </div>
        <h6>Update your password</h6>
            <div class="updatePasswords">
            <form id="updatePassword" name="updatePassword" class="passwordUpdate" action-"changePassword.php" method="post">
                <label for="currentPassword">Current Password:
                </label>
                <input type="password" id="currentPassword" name="currentPassword" required> <br />
                <label for="newPassword">New Password:
                </label>
                <input type="password" id="newPassword" name="newPassword" required> <br />
                <label for="cNewPassword">Confirm New Password:
                </label>
                <input type="password" id="cNewPassword" name="cNewPassword" reqiored> <br />
                <input type="submit" class="btn">
            </form>
            </div>
        </div>
    </div>
    </div>
    <!--these scripts are necessary for Bootstrap and must be before the close body tag-->
    <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
</body>
</html>