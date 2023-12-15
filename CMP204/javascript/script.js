var requestObject = false;
if (window.XMLHttpRequest) {
    requestObject = new XMLHttpRequest();
}

function getData(data, divID) {
    if (requestObject) {
        var obj = document.getElementById(divID);
        requestObject.open("GET", data);
        requestObject.onreadystatechange = function () {
            if (requestObject.readyState == 4 && requestObject.status == 200) {
                obj.innerHTML = requestObject.responseText;
            }
        }
        requestObject.send();
    }
}

function clearData(divID) {
    var obj = document.getElementById(divID);

    obj.innerHTML = "";
}

function validateRegistration() {
    var username = document.register.email.value;
    var cUsername = document.register.cEmail.value;
    var pass = document.register.pwd.value
    var cPass = document.register.cpwd.value

    if (username != cUsername || pass != cPass) {
        alert("Your email/password did not match.");
        return false;
    }
}
