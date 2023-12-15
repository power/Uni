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
    
    <h1>CMP204 Requirements Page - Unit 2 Assessment</h1>
    <p>Login details are Username: test@email.com Password: password123</p>
    <p>If you have not met a requirement, do not delete it from the table.</p>

        <table id="reqTable">
        <thead>
            <tr>
            <th class="reqCol">Requirement</th>
            <th class="metCol">How did you meet this requirement?</th>
            <th class="fileCol">File name(s), line no.</th>
            </tr>
        </thead>

        <tbody>
            <tr>
            <td>HTML, CSS, JavaScript has been contained within separate files.</td>
            <td>HTML has been used throughout the entire website and stored in seperate files depending on where it is appropriate. For example, a discography of the artists albums and mixtapes is kept in a seperate file to a brief description of who the artist is and what they have accomplished. CSS has been used to style the various sections of the website using different styles to make each page on the website appropriate for its use. JavaScript has been used to add additional functionality to the website and more specifically for error checking registration and showing pop-ups with information regarding the artists album on the Discography page.</td>
            <td>index.php Line 5-41, style.css Line 49-266, script.js Line 1-55</td>
            </tr>

            <tr>
            <td>A clear use of HTML5.</td>
            <td>HTML has been used on every page throughout the website. One example of a clear use of HTML5 could be for the Discography. The discography is created through a collection of div, headers and img tags.</td>
            <td>discography.php Line 7-154</td>
            </tr>
            <tr>
            <td>Use of the Bootstrap framework providing a responsive layout.</td>
            <td>I have used the bootstrap framework to create a responsive navigation bar. The navigation bar highlights depending on the active page, and contains a dropdown menu for logging in or registering an account and also changes depending on whether the user is logged in or not.</td>
            <td> includes/links.php Line 4-172</td>
            </tr>
            <tr>
            <td>Use of JavaScript to manipulate the DOM based on an event.</td>
            <td>On my discography page I am manipulating the DOM by creating new nodes, to create the pop-up that shows when hovering over an album cover. When the user puts their mouse over the image cover it manipulates the DOM and brings up a small window, and then removes the window when they move their mouse off of the cover.</td>
            <td> javascript/script.js Line 11-27</td>
            </tr>
            <tr>
            <td>Javascript loading of dynamically changing information.</td>
            <td>The information for the discography page should change depending on the album cover to show different tracklists and information</td>
            <td>javascript/script.js Line 8-19</td>
            <tr>
            <td>Use of jQuery in conjunction with the DOM.</td>
            <td></td>
            <td></td>
            </tr>
            <tr>
            <td>Use of AJAX (pure JavaScript i.e. without the use of a library).</td>
            <td>Validation of user inputs is done through the use of AJAX and calls elements from the document to check and save the inputs, using if statements to compare them</td>
            <td> javascript/script.js Line 35-45</td>
            </tr>
            <tr>
            <td>Use of the jQuery AJAX function.</td>
            <td></td>
            <td></td>
            </tr>
            <tr>
            <td>User login functionality (PHP/MySQL).</td>
            <td>A registration and login page has been implemented that hashes the users password upon registering and checks to ensure the user is not already registered with that email, they are then able to login using those credentials. There is pre-defined SQL queries to prevent SQL injection and login data is hashed at every point.</td>
            <td>PHP: login.php Line 31-50, register.php Line 16-34 
                SQL: processRegistration.php Line 1-27, processLogin.php Line 1-63</td>
            </tr>
            <tr>
            <td>Ability to select (SELECT), add (INSERT), edit (UPDATE) and delete (DELETE) information from a database (PHP/MySQL).</td>
            <td>Within processing a registration and login, SQL queries are used to SELECT & INSERT data into the table.</td>
            <td>processRegistration.php Line 1-27</td>
            </tr>
            <tr>
            <td>Inclusion of GDPR and the Cookie Law.</td>
            <td>A cookie pop-up has been implemented on the register & login pages that requires the user to give consent before they can provide any data</td>
            <td>login.php Line 13-23, register.php Line 11-18 & 50</td>
            </tr>
            <tr>
            <td>SQL queries written as prepared statements.</td>
            <td>As previously stated the statements for process registration and logins uses prepared statements</td>
            <td>processRegistration.php Line 1-27, processLogin.php Line 1-63</td>
            </tr>
            <tr>
            <td>Passwords should be salted and hashed.</td>
            <td>When an account is created the password is hashed using the password_hash function which creates a one way hash which is also salted. The only way it can be verified is through the password_verify function which requires the original password.</td>
            <td>processRegistration.php Line 16 & processLogin Line 20</td>
            </tr>
            <tr>
            <td>Validation of user input.</td>
            <td>Both the registration and login form require the user to have input valid inputs, this is checked through javascript and PHP</td>
            <td>javascript/script.js Line 27-38</td>
            </tr>
        </tbody>



        </table>

    <!--these scripts are necessary for Bootstrap and must be before the close body tag-->
    <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
</body>
</html>