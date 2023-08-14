let fs = require("fs");

let env = "/dev/stdin"; //"./1152.txt"; //
//let env = "./10798.txt";
let input = fs.readFileSync(env).toString().trim().split("\n");

// console.log("input", input);

const r = input.length;

let c = -Infinity;

input.forEach((row) => {
  if (row.length > c) {
    c = row.length;
  }
});

let newArr = Array.from({ length: c }, () => Array(r).fill(0));

//console.log("newArr", newArr);

for (let i = 0; i < c; i++) {
  for (let j = 0; j < r; j++) {
    newArr[i][j] = input[j][i];
  }
}

let answer = "";
for (let i = 0; i < c; i++) {
  for (let j = 0; j < r; j++) {
    if (newArr[i][j]) {
      answer += newArr[i][j];
    }
  }
}

console.log(answer.trim());
