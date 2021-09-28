let My_Name: string = "Hibi";
let my_h1 = document.getElementById("greeting");
if (my_h1 === null) {
  alert("something wong");
} else {
  my_h1.innerHTML = `Hello ${My_Name}`;
}
