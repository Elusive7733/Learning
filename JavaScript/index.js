//dont use var...var old boi
let variable = 'Test';

console.log(variable);

const rate = 123 //doesnt change


// objects

let Player = {

    username: 'Elusive',
    rank: 'Nigga'

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
Player[user_selected] = 'Elusive_Nibba'

console.log(Player);