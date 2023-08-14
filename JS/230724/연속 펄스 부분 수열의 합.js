function solution(sequence) {
  var answer = 0;

  // 1로 시작하는 케이스, -1로 시작하는 케이스에대해 DP를 수행하기
  const dpPos = [];
  const dpNeg = [];

  sequence.forEach((s, i) => {
    if (i === 0) {
      dpPos.push(s);
      dpNeg.push(-s);
    } else if (i % 2 === 0) {
      dpPos.push(Math.max(dpPos[i - 1] + s, s));
      dpNeg.push(Math.max(dpNeg[i - 1] - s, -s));
    } else {
      dpPos.push(Math.max(dpPos[i - 1] - s, -s));
      dpNeg.push(Math.max(dpNeg[i - 1] + s, s));
    }
    answer = Math.max(answer, dpPos[i], dpNeg[i]);
  });

  return answer;
}

sequence = [2, 3, -6, 1, 3, -1, 2, 4];

solution(sequence);
