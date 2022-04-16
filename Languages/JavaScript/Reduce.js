let input = [1, 2, 3, 4, 5];

//. Output [24, 12, 8, 6];

let output = [];
let temp;

for (let i = 0; i < input.length; i++) {
  output.push(
    input.reduce((prevValue, currentValue, index) => {
      if (index !== i) {
        return prevValue * currentValue;
      } else {
        return prevValue;
      }
    })
  );
}

console.log(output);
