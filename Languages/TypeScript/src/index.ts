let My_Name: string = "Hibi";

// My_Name = 4;

console.log("Name: ", My_Name);

// Handle null
let my_h1 = document.getElementById("greeting");

if (my_h1 === null) {
  alert("something wong");
} else {
  my_h1.innerHTML = `Hello ${My_Name}`;
}
