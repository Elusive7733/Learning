let allSubstrings = [];
let rightString = "";
let leftString = "";

const generateSubstring = (leftString, rightString) => {
  if (leftString == null || leftString.length == 0) {
    //not taking empty strings
    if (rightString.length >= 1) {
      allSubstrings.push(rightString);
    }
    return;
  }

  //Left Subtree
  generateSubstring(leftString.substring(1), rightString + leftString[0]);

  //Right Subtree
  generateSubstring(leftString.substring(1), rightString);
};

const keepGoodSubstrings = () => {
  //looping through all substrings
  for (let i = 0; i < allSubstrings.length; i++) {
    let countAlphabets = new Array(26).fill(0);

    let currentString = allSubstrings[i];
    currentString = currentString.toLowerCase();

    for (let j = 0; j < currentString.length; j++) {
      let index = currentString.charCodeAt(j) - 97;
      countAlphabets[index]++;
    }

    for (let k = 0; k < countAlphabets.length; k++) {
      if (countAlphabets[k] === 0) {
        countAlphabets.splice(k, 1);
      }
    }

    const isGoodSubstring = (count) =>
      count.every((letter) => {
        letter === count[0];
      });

    if (isGoodSubstring(countAlphabets)) {
      allSubstrings.splice(i, 1);
    }
  }
};

function countGoodSubsequences(word) {
  leftString = word;
  generateSubstring(leftString, rightString);
  keepGoodSubstrings();

  let count = 0;
  for (let i = 0; i < allSubstrings.length; i++) {
    count += 1;
  }
  count = count % (Math.pow(10, 9) + 7);

  return count;
}

console.log(countGoodSubsequences("abcd"));
