let fs = require("fs");

let env = "/dev/stdin"; //"./1152.txt"; //
// let env = "./1018.txt";
let input = fs.readFileSync(env).toString().trim().split("\n");

let [n, m] = input.shift().split(" ").map(Number);

//console.log(n, m);

function check8x8(r, c) {
  let diff = 0;
  for (let i = r; i < r + 8; i++) {
    for (let j = c; j < c + 8; j++) {
      // 홀홀 W, 짝짝이 W인지 검사
      if ((i % 2 == 0 && j % 2 == 0) || (i % 2 === 1 && j % 2 === 1)) {
        if (input[i][j] === "B") diff++;
        continue;
      }
      // 홀 짝이면 B여야 함
      if ((i % 2 == 0 && j % 2 == 1) || (i % 2 === 1 && j % 2 === 0)) {
        if (input[i][j] === "W") diff++;
      }
    }
  }

  diff = Math.min(diff, 64 - diff);

  return diff;
}

let totalMin = Infinity;
let tempMin = Infinity;
for (let r = 0; r < n - 7; r++) {
  for (let c = 0; c < m - 7; c++) {
    tempMin = check8x8(r, c);

    if (totalMin > tempMin) totalMin = tempMin;
  }
}

console.log(totalMin);
// 8x8씩 순회하면서, check8x8
// check8x8은 홀수열-홀수번째 W, 짝수번째 B
// 짝수열-짝수번째가 W, 홀수번째가 B인지 검사
// 다른개수랑 64-다른개수 중 작은 것을 리턴.
// 최솟값 전체 갱신 후 최솟값 리턴
