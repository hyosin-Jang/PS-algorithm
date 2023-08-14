let fs = require("fs");

let env = "/dev/stdin"; //"./1152.txt"; //
//let env = "./2444.txt";
let n = fs.readFileSync(env).toString().trim();

let answer = [];
for (let row = 0; row < n; row++) {
  // 공백 출력
  let el = [];
  for (let space = n - 1 - row; space > 0; space--) {
    el.push(" ");
  }
  for (let start = 0; start < 2 * row + 1; start++) {
    el.push("*");
  }
  answer.push(el);

  // * 출력
}

for (let row = n - 1; row > 0; row--) {
  // 공백 출력
  let el = [];
  for (let space = 0; space < n - row; space++) {
    el.push(" ");
  }
  for (let start = 2 * row - 1; start > 0; start--) {
    el.push("*");
  }
  answer.push(el);

  // * 출력
}

answer = answer.map((row) => row.join("")).join("\n");

console.log(answer);
