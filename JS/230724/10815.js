// O(1)만에 접근해야 함 -> 해시맵

let fs = require("fs");

let env = "/dev/stdin"; //"./1152.txt"; //
//let env = "./10815.txt";
let input = fs.readFileSync(env).toString().trim().split("\n");

let n = parseInt(input.shift());
let sCard = input.shift().split(" ").map(Number);
let map = new Map();
for (let i = 0; i < n; i++) {
  map[sCard[i]] = 1;
}

let m = parseInt(input.shift());
let gCard = input.shift().split(" ").map(Number);

let answer = [];
for (let i = 0; i < m; i++) {
  if (map[gCard[i]]) {
    answer.push(1);
  } else answer.push(0);
}

console.log(answer.join(" "));
