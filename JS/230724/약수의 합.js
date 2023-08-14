function solution(n) {
  var answer = 0;
  let num = [];

  let double = Math.sqrt(n);

  for (let i = 1; i < double; i++) {
    if (n % i === 0) {
      num.push(i, n / i);
    }
  }

  if (Math.floor(double) ** 2 === n) {
    // 처음에 double ** 2 === n 으로 했다가 틀렸음
    // double은 n의 제곱근이므로 제곱했을 때 n이 나오는 건 당연함
    // 제곱근이 정수인지 확인해야 하므로 Math.floor를 추가함
    num.push(Math.floor(double));
  }
  answer = num.reduce((acc, val) => acc + val, 0);

  return answer;
}

n = 33;
console.log(solution(n));
