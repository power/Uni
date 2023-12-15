<?php
if(isset($_COOKIE["loggedin"]) || $_COOKIE["loggedin"] == 1){
    ?>
    <nav class="navbar navbar-expand-lg navbar-dark">
        <a class="navbar-brand" id="navbar-name" href="index.php">J. Cole</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav mr-auto navbar-center" id="navbar-links">
                <li
                    <?php
                    if($_SERVER['PHP_SELF']=="index.php") {

                        ?>
                        class="nav-item active"
                        <?php
                    }
                    else{
                        ?>
                        class="nav-item"
                        <?php
                    }
                    ?>>
                    <a class="nav-link" href="index.php">Home</a>
                </li>
                <li
                    <?php
                    if($_SERVER['PHP_SELF']=="/tourInfo.php") {
                        ?>
                        class="nav-item active"
                        <?php
                    }
                    else{
                        ?>
                        class="nav-item"
                        <?php
                    }
                    ?>>
                    <a class="nav-link" href="tourInfo.php">Tour Info</a>
                </li>
                <li
                    <?php
                    if($_SERVER['PHP_SELF']=="/discography.php") {
                        ?>
                        class="nav-item active"
                        <?php
                    }
                    else{
                        ?>
                        class="nav-item"
                        <?php
                    }
                    ?>>
                    <a class="nav-link" href="discography.php">Discography</a>
                </li>
                <li
                    <?php
                    if($_SERVER['PHP_SELF']=="/req.php") {
                        ?>
                        class="nav-item active"
                        <?php
                    }
                    else{
                        ?>
                        class="nav-item"
                        <?php
                    }
                    ?>>
                    <a class="nav-link" href="req.php">Requirements</a>
                </li>
            </ul>
            <ul class="navbar-nav navbar-right">
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                        Account
                    </a>
                    <div class="dropdown-menu dropdown-menu-lg-right dropdown-menu-md-left dropdown-menu-sm-left dropdown-menu-left" aria-labelledby="navbarDropdown">
                        <a class="dropdown-item" href="userProfile.php">Profile</a>
                        <div class="dropdown-divider"></div>
                        <a class="dropdown-item" href="logout.php">Logout</a>
                    </div>
                </li>
            </ul>
        </div>
    </nav>
    <?php
}
else {
    ?>
    <nav class="navbar navbar-expand-lg navbar-dark">
        <a class="navbar-brand" id="navbar-name" href="index.php">J. Cole</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav mr-auto navbar-center" id="navbar-links">
                <li
                    <?php
                    if($_SERVER['PHP_SELF']=="index.php") {
                        ?>
                        class="nav-item active"
                        <?php
                    }
                    else{
                        ?>
                        class="nav-item"
                        <?php
                    }
                    ?>>
                    <a class="nav-link" href="index.php">Home</a>
                </li>
                <li
                    <?php
                    if($_SERVER['PHP_SELF']=="/tourInfo.php") {
                        ?>
                        class="nav-item active"
                        <?php
                    }
                    else{
                        ?>
                        class="nav-item"
                        <?php
                    }
                    ?>>
                    <a class="nav-link" href="tourInfo.php">Tour Info</a>
                </li>
                <li
                    <?php
                    if($_SERVER['PHP_SELF']=="/discography.php") {
                        ?>
                        class="nav-item active"
                        <?php
                    }
                    else{
                        ?>
                        class="nav-item"
                        <?php
                    }
                    ?>>
                    <a class="nav-link" href="discography.php">Discography</a>
                </li>
                <li
                    <?php
                    if($_SERVER['PHP_SELF']=="/req.php") {
                        ?>
                        class="nav-item active"

                        <?php
                    }
                    else{
                        ?>
                        class="nav-item"
                        <?php
                    }
                    ?>>
                    <a class="nav-link" href="req.php">Requirements</a>
                </li>
            </ul>
            <ul class="navbar-nav navbar-right">
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                        Account
                    </a>
                    <div class="dropdown-menu dropdown-menu-lg-right dropdown-menu-md-left dropdown-menu-sm-left dropdown-menu-left" aria-labelledby="navbarDropdown">
                        <a class="dropdown-item loginLink" href="login.php">Login</a>
                        <a class="dropdown-item regLink" href="register.php">Register</a
                    </div>
                </li>
            </ul>
        </div>
    </nav>
    <?php 
}