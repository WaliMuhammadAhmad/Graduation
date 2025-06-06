console.log("In Js");

function validateForm(event) {
    event.preventDefault();
    console.log("In function");
    let name = document.getElementById('name').value;
    let address = document.getElementById('address').value;
    let city = document.getElementById('city').value;
    let postcode = document.getElementById('postcode').value;

    if (name==""&&address==""&&city==""&&postcode==""){
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

    if (address === "") {
        alert("Address field is Empty!");
    }
    else {
        if (3 < address.length > 50) {
            alert("Address length should in between 3 and 50 characters");
        }
    }

    if (city === ""){
        alert("Phone number is Empty!");
    }
    else {
        if (!isNaN(city)) {
            alert("City contains number!");
        }
    }

    if (postcode === ""){
        alert("Postcode number is Empty!");
    }
    else {
        if (isNaN(postcode)) {
            alert("Postcode contains alphabets or symbols!");
        }
    }
}