function solution(maps) {
  var answer = [];

  const [r, c] = [maps.length, maps[0].length];
  const visited = Array.from({ length: r }, () => new Array(c).fill(0));

  function dfs(i, j, maps, visited, cnt) {
    let dx = [-1, 1, 0, 0];
    let dy = [0, 0, -1, 1];

    let sum = Number(cnt);

    for (let d = 0; d < 4; d++) {
      const nx = i + dx[d];
      const ny = j + dy[d];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (maps[nx][ny] !== "X" && visited[nx][ny] === 0) {
        visited[nx][ny] = 1;
        sum += dfs(nx, ny, maps, visited, maps[nx][ny]);
      }
    }

    return sum;
  }

  for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) {
      if (maps[i][j] !== "X" && visited[i][j] === 0) {
        visited[i][j] = 1;
        let maxDate = dfs(i, j, maps, visited, maps[i][j]);
        answer.push(maxDate);
      }
    }
  }

  if (!answer.length) return [-1];

  // array.sort() => 숫자를 문자열로 변환한다음에 정렬해서
  // 사전식으로 정렬한 결과가 나옴
  // [10 ,2 , 30, 5]

  // array.sort((a,b) => a-b)
  // 숫자 간의 값을 비교해서 오름차순으로 정렬
  return answer.sort((a, b) => a - b);
}

maps = ["X591X", "X1X5X", "X231X", "1XXX1"];

console.log(solution(maps));
