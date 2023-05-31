// 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 탐색

// 1. begin에서 시작해서, getDifferentCharCnt 함수로 알파벳 차이가 1개인 단어들을 방문한다.
// 2. 각 단어가 target이면 count 출력하고 종료한다.
// 3. 다 visit여서 갈 곳이 없는 경우 0 출력한다.
function solution(begin, target, words) {
  var answer = 0;

  // words 배열 길이만큼 방문 확인할 visit 배열 필요함
  const visit = Array.from({ length: words.length }).fill(0);
  let cnt = 0;

  const dfs = (begin, cnt, visit) => {
    // target인지 확인한다.
    if (begin === target) {
      answer = cnt;
      return;
    }
    // visit을 복사해준다.
    let copy = [...visit];

    // target이 아닌데 모두 방문했다면 target을 만들 수 없다는 것이므로 종료한다.
    if (copy.filter((el) => el === 1).length === words.length) {
      answer = 0;
      return;
    }

    for (let i = 0; i < words.length; i++) {
      // 방문하지 않았고 차이가 1이 난다면 방문한다.
      if (!copy[i] && getDifferentCharCnt(begin, words[i])) {
        copy[i] = 1; // 방문처리
        dfs(words[i], cnt + 1, copy);
      }
    }
  };
  dfs(begin, cnt, visit);

  return answer;
}

const getDifferentCharCnt = (begin, word) => {
  const n = begin.length;
  let diff = 0;

  for (let i = 0; i < n; i++) if (begin[i] !== word[i]) diff++;
  if (diff === 1) return true;

  return false;
};
