let fs = require("fs");

let env = "/dev/stdin"; //"./1152.txt"; //
//let env = "./18258.txt";
let input = fs.readFileSync(env).toString().split("\n");

//console.log("input", input);
let n = Number(input.shift());

let stack1 = [],
  stack2 = [];

//console.log("n", n);
for (let i = 0; i < n; i++) {
  let [op, num] = input[i].split(" ");
  switch (op) {
    case "push":
      //console.log("push");
      stack1.push(num);
      break;
    case "front":
      //console.log("front");
      if (!stack2.length && !stack1.length) {
        console.log(-1);
        break;
      }
      if (stack2.length) {
        console.log(stack2.at(-1));
        break;
      }
      console.log(stack1[0]);
      break;

    case "pop":
      //console.log("pop");
      if (!stack2.length && !stack1.length) {
        console.log(-1);
        break;
      }
      if (!stack1.length) {
        // stack2가 비어있으면
        console.log(stack2.pop());
        break;
      }
      if (!stack2.length) {
        // stack1 -> stack2로 옮기기
        while (stack1.length) {
          stack2.push(stack1.pop());
        }
        console.log(stack2.pop());
        break;
      }

    case "back":
      if (!stack1.length) {
        console.log(-1);
        break;
      }
      //console.log("back");
      console.log(stack1.at(-1));
      break;

    case "empty":
      //console.log("empty");
      if (!stack2.length && !stack1.length) {
        console.log(1);
        break;
      }
      console.log(0);
      break;

    case "size":
      //console.log("size");
      console.log(stack2.length || 0 + stack1.length || 0);
  }
}
