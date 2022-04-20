let s = "hheelloo";
let letterFrequencies = [...s].reduce((array, element) => {
  array[element] = array[element] ? array[element] + 1 : 1;
  return array;
}, {});

Object.filter = (obj, predicate) =>
  Object.keys(obj)
    .filter((key) => predicate(obj[key]))
    .reduce((res, key) => ((res[key] = obj[key]), res), {});

let filtered = Object.filter(letterFrequencies, (frequency) => frequency === 1);

let firstUnique = Object.keys(filtered)[0];

console.log(firstUnique);

console.log(s.indexOf(firstUnique));
