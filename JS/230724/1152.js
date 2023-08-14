let fs = require("fs");

// let env = "/dev/stdin"; //"./1152.txt"; //
let env = "./1152.txt";
let input = fs.readFileSync(env).toString().trim(); //.split();

// 예외 케이스: 공백 하나만 들어오는 경우
if (input.split(" ")[0] === "") {
  console.log(0);
  return;
}
console.log(input.split(" ").length);
