function getNextChar(char) {
  let charCode = char.charCodeAt(0);

  charCode++;
  if (charCode > 122) {
    charCode = 97;
  }

  char = String.fromCharCode(charCode);

  return String.fromCharCode(charCode);
}

function rollTheString(s, roll) {
  let result = "";

  for (let i = 0; i < roll.length; i++) {
    for (let j = 0; j < roll[i]; j++) {
      s.replace(`/${s[i]}`, getNextChar(s[j]));
    }
  }

  return s;
}

let s = "abz";
let roll = [3, 2, 1];

console.log(rollTheString(s, roll));
