console.log("In Js");

function validateForm(event) {
    event.preventDefault();
    console.log("In function");
    let name = document.getElementById('name').value;
    let fatherName = document.getElementById('fname').value;
    let phone = document.getElementById('phone').value;
    let email = document.getElementById('email').value;
    let password = document.getElementById('password').value;

    if (name==""&&fatherName==""&&phone==""&&email==""&&password==""){
        alert("Field Empty!");
        return false;
    }

    if (name === "") {
        alert("Name field is Empty!");
    }
    else {
        if (!isNaN(name)) {
            alert("Name contains number!");
        }
        if (3 < name.length > 20) {
            alert("Name length should in between 3 and 20 characters");
        }
    }

    if (fatherName === "") {
        alert("Father Name field is Empty!");
    }
    else {
        if (!isNaN(fatherName)) {
            alert("Father Name contains number!");
        }
        if (3 < fatherName.length > 20) {
            alert("Father Name length should in between 3 and 20 characters");
        }
    }

    if (phone === ""){
        alert("Phone number is Empty!");
    }
    else {
        if (isNaN(phone)){
            alert("Phone Number must contains Number only!");
        }

        if (phone.length != 11) {
            alert("Invalid Phone Number");
        }

    }

    var atPosition = email.indexOf("@");
    var dotPosition = email.lastIndexOf(".");
    if(email===""){
        alert("Email is Empty!");
    }
    else {
        if(!isNaN(email)){
            alert("Email contains Number only!");
        }
        if (atPosition < 1 || dotPosition < atPosition + 2 || dotPosition + 2 >= email.length) {
            alert("Invalid Email!");
        }
    }

    if (password === "") {
        alert("Password is Empty!");
    }
    else {
        if (8 < password > 14) {
            alert("Password length should be 8 to 14 charcters");
        }
    }
}