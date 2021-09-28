//__________________Basic Types__________________

let id: number = 69;
let planet: string = "Saturn";
let exit_flag: boolean = true;
let date: Date = new Date("2019-01-16");
let xyz: any = "what";

xyz = true; //not an error because of :any type

// __________________Arrays__________________

let names: string[] = ["Abdullah", "Elusive", "Raheel"]; // string[] tells the compiler that each element must be a string
// names.push(12);

let test: any[] = [1, "Hello", true];

// __________________Tupples__________________

let person: [number, string, boolean] = [22, "Hiba", true];

// __________________Tupples Array__________________
let students: [number, string][];

students = [
  [180170, "Abdullah"],
  [181137, "Hiba"],
];

// __________________Union__________________
let name_or_num: string | number = 22;
name_or_num = "Qasim";
// name_or_num = true; Error

// __________________Enums__________________

enum direction {
  up,
  down,
  left,
  right,
}

// __________________Objects__________________

const user = {
  id: 1,
  name: true,
};

const user_with_types: { id: number; name: string } = {
  id: 1,
  name: "Abd",
};

type News = { date: Date; headline: string };

const news: News = {
  date: new Date(), // Current Date and Time
  headline: "Elusive learned Typescript !",
};

console.log(news.date);

// __________________ __________________

// __________________ __________________

// __________________ __________________

// __________________ __________________
