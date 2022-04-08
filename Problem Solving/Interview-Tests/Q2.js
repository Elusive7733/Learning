function solution(message) {
  let solutionString = "";
  let vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"];

  for (let i = 0; i < message.length; i++) {
    if (vowels.includes(message[i][0])) {
      solutionString += message[i][0];
    } else {
      let letter = message[i][0];
      if (/[a-zA-Z]/.test(letter)) {
        if (letter === "Z") {
          letter = "B";
        } else if (letter === "z") {
          letter = "b";
        } else {
          letter = letter.charCodeAt(0);
          letter += 1;
          if (vowels.includes(String.fromCharCode(letter))) {
            letter += 1;
          }
          letter = String.fromCharCode(letter);
        }
        solutionString += letter;
      } else {
        solutionString += message[i][0];
      }
    }
  }
  return solutionString;
}

let message = "U";
console.log(solution(message));
