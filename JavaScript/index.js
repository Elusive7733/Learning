//dont use var...var old boi
let variable = 'Test';

console.log(variable);

const rate = 123 //doesnt change

// objects
let Player = {

    username: 'Elusive',
    rank: 'gold'

};
console.log(Player);

//dot
Player.rank = 'Gold';

//bracket
Player['username'] = 'Abdulah';

console.log(Player);


//Benifit of Bracket Notation
let user_selected = 'username'
// let user_input = window.prompt("Enter Username: ");
Player[user_selected] = 'Elusive_Player'

console.log(Player);

// loop
let list = ["hello", "nibba", 2, 3, 5, 7]

for(let i = 0; i < list.length; i++){
    console.log(list[i])
}

// using string literals use back ticks ` tilde key ~
const name = "Abdullah"
console.log(`Hello my name is ${name}`)

//object deconstruction 
const { username, rank } = Player //attributes of player stored in variables of the same name
console.log(username)
console.log(rank)

//Arrow Funtions

//basic funtion
function display_rank1(){
    console.log(rank)
}
display_rank1();

//this
const display_rank2 = function(){
    console.log(rank)
}
display_rank2();

// becomes this
const display_rank3 = () =>{
    console.log(rank)
}
display_rank3();

const user = {
    name: "Elusive",
    age: 22,
    speakName: function(){
        console.log(`name is ${this.name}`)
        const name_age = () => {
            console.log(`name is ${this.name} and the age is ${this.age}`) //this keyword wont work without the arrow functions
        }
        name_age();
    }
}
user.speakName();


const add = (x = 1, y = 2) => {
    console.log(x + y)
}

add()

console.clear()

list.forEach((product, index) => {
    console.log(`${product}: ${index}`)
});