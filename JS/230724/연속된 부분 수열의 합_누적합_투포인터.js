function solution(sequence, k) {
  let answer = [];
  let prefix = [0]; // 시작 0 미리 넣어놓기
  let maxL = Infinity;
  sequence.forEach((num, i) => prefix.push(num + prefix[i]));

  let left = 0;
  let right = 0;

  // 투포인터는 이 문제처럼 같은 방향으로 갈수도 있고
  // 이분탐색처럼 반대 방향에서 출발할 수도 있음

  while (left <= right) {
    let sum = prefix[right] - prefix[left];
    if (sum === k) {
      // 정답 수열을 찾았을 때 현재 수열의 길이를 체크하고 작은 걸로 갱신
      let nowL = right - 1 - left;
      if (maxL > nowL) {
        answer = [lett, right - 1];
        maxL = nowL;
      }
    }
    // sum 키워야 하니까 right 증가
    if (sum < k) right++;
    else left++;
  }
}
