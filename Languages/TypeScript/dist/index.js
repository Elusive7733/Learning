"use strict";
let My_Name = "Hibi";
// My_Name = 4;
console.log("Name: ", My_Name);
// Handle null
let my_h1 = document.getElementById("greeting");
if (my_h1 === null) {
    alert("something wong");
}
else {
    my_h1.innerHTML = `Hello ${My_Name}`;
}
// Basic Types
let id = 69;
let planet = "Saturn";
let exit_flag = true;
let xyz = "what";
xyz = true; //not an error because of :any type
