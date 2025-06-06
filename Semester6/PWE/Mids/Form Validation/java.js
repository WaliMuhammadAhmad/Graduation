function myFunction() {
var myname = document.getElementById("name").value.trim();
var mypass1 = document.getElementById("pass1").value.trim();
var mypass2 = document.getElementById("pass2").value.trim();
var phonenumber = document.getElementById("phone").value.trim();
var myemail = document.getElementById("email").value.trim();


var x = document.getElementById("myDIV");
var mypasstext1 = document.getElementById("passtext1");
var mypasstext2 = document.getElementById("passtext2");
var myphonetext = document.getElementById("phonetext");
var myemailtext = document.getElementById("emailtext");

if(myname == ""){
      document.getElementById("name").className = "form-control newinput";
	 
}
else{
	document.getElementById("name").className = "form-control simpleinput";
	 if(!isNaN(myname)){
alert("Enter Alphabets Only");

}
}

if(mypass1 == ""){
      mypasstext1.style.display = "block";
}
else{
	mypasstext1.style.display = "none";
	if(mypass1.length < 6){
alert("passwords length must be at least 6");
}
}
if(mypass2 == ""){
      mypasstext2.style.display = "block";
}
else{
	mypasstext2.style.display = "none";
	if(mypass2.length < 6){
alert("passwords length must be at least 6");
}
}
if(mypass1 !== mypass2){
alert("passwords do not match");
}
if(phonenumber == ""){
myphonetext.style.display="block";
}
else{
myphonetext.style.display="none";
if(isNaN(phonenumber)){
alert("Enter Numeric Values Only");
}
}
if(myemail == ""){
myemailtext.style.display="block";
}
else{
myemailtext.style.display="none";
var atposition=myemail.indexOf("@");  
var dotposition=myemail.lastIndexOf(".");  
if (atposition<1 || dotposition<atposition+2 || dotposition+2>=myemail.length){  
  alert("Please enter a valid e-mail address");  
  return false;  
  }  

}
}