<!doctype html>

<html lang="en">
<head>
	<meta charset="utf-8">
	<title>CMP204 Unit Two Coursework Template</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
	<link rel="stylesheet" href="css/style.css">
	<script src="javascript/script.js"></script>
    <!-- Cookie Consent by FreePrivacyPolicy.com https://www.FreePrivacyPolicy.com -->
    <script type="text/javascript" src="//www.freeprivacypolicy.com/public/cookie-consent/4.0.0/cookie-consent.js" charset="UTF-8"></script>
    <script type="text/javascript" charset="UTF-8">
    document.addEventListener('DOMContentLoaded', function () {
    cookieconsent.run({"notice_banner_type":"simple","consent_type":"express","palette":"dark","language":"en","page_load_consent_levels":["strictly-necessary"],"notice_banner_reject_button_hide":false,"preferences_center_close_button_hide":false,"page_refresh_confirmation_buttons":false,"website_name":"mayar.abertay.ac.uk/~2101758/cmp204/coursework/"});
    });
    </script>

    <noscript>Cookie Consent by <a href="https://www.freeprivacypolicy.com/" rel="noopener">Free Privacy Policy Generator</a></noscript>
    <!-- End Cookie Consent by FreePrivacyPolicy.com https://www.FreePrivacyPolicy.com -->





    <!-- Below is the link that users can use to open Preferences Center to change their preferences. Do not modify the ID parameter. Place it where appropriate, style it as needed. -->
</head>
<body>
    <nav>
        <?php include_once "includes/links.php" ?>
    </nav>

    <h1> Register </h1>
    <div class="registration">
        <form id="register" name="register" action="processRegistration.php" onsubmit="return validateRegistration()" method="post">
            <label for="email">
            </label>
            Email: <input type="text" id="email" name="email" required><br />
            <label for="cEmail">
            </label>
            Confirm Email: <input type="text" id="cEmail" name="cEmail" required><br />
            <label for="pwd">
            </label>            
            Password: <input type="password" id="pwd" name="pwd" required><br />
            <label for="cpwd">
            </label>            
            Confirm Password: <input type="password" id="cpwd" name="cpwd" required><br />
            <input id="btn" type="submit">   
        </form>
        <a href="#" id="open_preferences_center">Update cookies preferences</a>
        <a href="includes/info/gdpr.php"> GDPR </a>
    </div>


    <!--these scripts are necessary for Bootstrap and must be before the close body tag-->
    <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
</body>
</html>