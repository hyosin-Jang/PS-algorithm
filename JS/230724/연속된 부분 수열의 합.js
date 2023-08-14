function solution(sequence, k) {
  const prefix = [0]; // 누적합

  sequence.forEach((num, i) => prefix.push(num + prefix[i]));

  let left = 0,
    right = 0;

  let minIdx = Infinity;
  while (left <= right) {
    let sum = prefix[right] - prefix[left];

    if (sum === k) {
      if (minIdx > right - left) {
        minIdx = right - left;
        answer = [left, right - 1]; // right-1: 앞에 0 넣어줘서, left: left-1인데 left -1 까지의 누적합이 left에 있음
      }
    }
    if (sum < k) right++;
    else left++; // sum === k 여도 left++, left > right이면 종료됨
  }
  return answer;
}

sequence = [1, 2, 3, 4, 5];
k = 7;
solution(sequence, k);
