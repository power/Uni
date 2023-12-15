<?php

session_start();
?>
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
        <?php include_once "includes/links.php" ?>
    </nav>


    <h1>Studio Albums</h1>
    <div class="albums">
        <div class="album">
            <img class="artwork" src="images/4YEO.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv')" onmouseleave="clearData('targetDiv')">
            <div class="album_info">
                <h4>4 Your Eyez Only</h4>
                <!-- https://en.wikipedia.org/wiki/File:J._Cole_%E2%80%94_4_Your_Eyez_Only_album_cover.jpg -->
            </div>
            <div id="targetDiv">

            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/Born_Sinner.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv2')" onmouseleave="clearData('targetDiv2')">
            <div class="album_info">
                <h4>Born Sinner</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/2/21/J_Cole_Born_Sinner1.jpg/220px-J_Cole_Born_Sinner1.jpg -->
            </div>
            <div id="targetDiv2">
            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/Cole_World.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv3')" onmouseleave="clearData('targetDiv3')">
            <div class="album_info">
                <h4>Cole World</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/7/76/ColeWorld.jpeg/220px-ColeWorld.jpeg -->
            </div>
            <div id="targetDiv3">

            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/FHD.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv4')" onmouseleave="clearData('targetDiv4')">
            <div class="album_info">
                <h4>Forest Hill Drives</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/2/2a/2014ForestHillsDrive.jpg/220px-2014ForestHillsDrive.jpg -->
            </div>
            <div id="targetDiv4">

            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/KOD.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv5')" onmouseleave="clearData('targetDiv5')">
            <div class="album_info">
                <h4>KOD</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/d/d3/JColeKOD.jpg/220px-JColeKOD.jpg -->
            </div>
            <div id="targetDiv5">

            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/The_Off_Season.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv6')" onmouseleave="clearData('targetDiv6')">
            <div class="album_info">
                <h4>The Off Season</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/7/7d/TheOff-Season.jpeg/220px-TheOff-Season.jpeg -->
            </div>
            <div id="targetDiv6">

            </div>
        </div>
    </div>

    <h1>Compilations<h1>
    <div class="albums">
        <div class="album">
            <img class="artwork" src="images/ROTD.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv7')" onmouseleave="clearData('targetDiv7')">
            <div class="album_info">
                <h4>Revenge of The Dreamers</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/4/4c/Dreamvillerotd.jpg/220px-Dreamvillerotd.jpg -->
            </div>
            <div id="targetDiv7">
            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/ROTD2.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv8')" onmouseleave="clearData('targetDiv8')">
            <div class="album_info">
                <h4>Revenge of The Dreamers 2</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/3/3f/DreamvilleROTD2.jpeg/220px-DreamvilleROTD2.jpeg -->
            </div>
            <div id="targetDiv8">

            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/ROTD3.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv9')" onmouseleave="clearData('targetDiv9')">
            <div class="album_info">
                <h4>Revenge of The Dreamers 3</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/0/02/Dreamville_-_Revenge_of_the_Dreamers_III.png/220px-Dreamville_-_Revenge_of_the_Dreamers_III.png -->
            </div>
            <div id="targetDiv9">

            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/DDAY.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv10')" onmouseleave="clearData('targetDiv10')">
            <div class="album_info">
                <h4>D-Day</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/7/70/Dreamville_D-Day.jpeg/220px-Dreamville_D-Day.jpeg -->
            </div>
            <div id="targetDiv10">

            </div>
        </div>
    </div>

    <h1>Mixtapes<h1>
    <div class="albums">
        <div class="album">
            <img class="artwork" src="images/TCU.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv11')" onmouseleave="clearData('targetDiv11')">
            <div class="album_info">
                <h4>The Come Up</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/0/0d/JColeTheComeUp.jpg/220px-JColeTheComeUp.jpg -->
            </div>
            <div id="targetDiv11">

            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/TWU.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv12')" onmouseleave="clearData('targetDiv12')">
            <div class="album_info">
                <h4>The Warmup</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/2/2e/J-cole-the-warm-up.jpg/220px-J-cole-the-warm-up.jpg -->
            </div>
            <div id="targetDiv12">

            </div>
        </div>
        <div class="album">
            <img class="artwork" src="images/FNL.jpg" onmouseover="getData('includes/info/4YEO.txt', 'targetDiv13')" onmouseleave="clearData('targetDiv13')">
            <div class="album_info">
                <h4>Friday Night Lights</h4>
                <!-- https://upload.wikimedia.org/wikipedia/en/thumb/6/64/Fridaynightlightsjcole.png/220px-Fridaynightlightsjcole.png -->
            </div>
            <div id="targetDiv13">

            </div>
        </div>
    </div>

    <!--these scripts are necessary for Bootstrap and must be before the close body tag-->
    <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
</body>
</html>