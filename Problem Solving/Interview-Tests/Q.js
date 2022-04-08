function solution(words) {
  let solutionArray = [];

  for (let i = 0; i < words.length - 1; i++) {
    let booleanExpression =
      words[i][0] === words[i + 1][0] &&
      words[i][words[i].length - 1] === words[i + 1][words[i + 1].length - 1];

    solutionArray.push(booleanExpression);
  }
}

let words = ["abcd", "abdd", "da", "dd"];
solution(words);
