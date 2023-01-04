"use strict";
// TODO: https://www.youtube.com/watch?v=BCg4U1FzODs&t=729s
//*__________________Basic Types__________________
let id = 69;
let planet = "Saturn";
let exit_flag = true;
let date = new Date("2019-01-16");
let xyz = "what";
xyz = true; //!not an error because of :any type
//*__________________Arrays__________________
let names = ["Abdullah", "Elusive", "Raheel"]; //? string[] tells the compiler that each element must be a string
//! names.push(12);
let test = [1, "Hello", true];
//*__________________Tupples__________________
let person = [22, "Bruce", true];
//*__________________Tupples Array__________________
let students;
students = [
    [180170, "Abdullah"],
    [999900, "Goku"],
];
//*__________________Union__________________
let name_or_num = 22;
name_or_num = "Qasim";
//! name_or_num = true; Error
//*__________________Enums__________________
var direction;
(function (direction) {
    direction[direction["up"] = 0] = "up";
    direction[direction["down"] = 1] = "down";
    direction[direction["left"] = 2] = "left";
    direction[direction["right"] = 3] = "right";
})(direction || (direction = {}));
//*__________________Objects__________________
const user = {
    id: 1,
    name: true,
};
const user_with_types = {
    id: 1,
    name: "Abd",
};
const news = {
    date: new Date(),
    headline: "Elusive learned Typescript !",
};
console.log(news.date);
//*__________________Type Assertion__________________
//*__________________ __________________
//*__________________ __________________
//*__________________ __________________
