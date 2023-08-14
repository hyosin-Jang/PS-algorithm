function solution(cap, n, deliveries, pickups) {
  let sum = 0;
  let box = 0;

  // 1. index로 접근하는 것보다 배열에 push, pop
  // 2. 조건을 정교화하면 예외처리가 쉬워지고 코드로 구현하기가 수월해진다.

  // 둘다 0인 경우에만 pop하고 하나라도 0이 아니면 종료하기
  while (deliveries[n - 1] === 0 && !pickups[n - 1] === 0) {
    deliveries.pop();
    pickups.pop();
    n--;
  }
  let distance = n; //Math.max(deliveries.length, pickups.length);

  while (deliveries.length !== 0 || pickups.length !== 0) {
    while (deliveries.length) {
      box += deliveries.pop();
      if (box > cap) {
        deliveries.push(box - cap);
        break;
      }
    }
    box = 0;
    while (pickups.length) {
      box += pickups.pop();
      if (box > cap) {
        pickups.push(box - cap);
        break;
      }
    }
    box = 0;
    sum += distance;
    distance = Math.max(deliveries.length, pickups.length);
  }

  return sum * 2;
}

const deliveries = [1, 0, 3, 1, 2];
const pickups = [0, 3, 0, 4, 0];

const cap = 4;
const n = 5;

console.log(solution(cap, n, deliveries, pickups));
