function solution(board) {
  let totalO = 0,
    totalX = 0;

  // 1. 항상 O의 개수 - X의 개수 = 0 아니면 1인지 검사
  board.forEach((row) => {
    for (let i = 0; i < row.length; i++) {
      if (row[i] === "O") totalO++;
      if (row[i] === "X") totalX++;
    }
  });

  if (totalO - totalX !== 0 && totalO - totalX !== 1) return 0;

  function isRowThree(char) {
    for (let i = 0; i < 3; i++)
      if (board[i][0] === char && board[i][1] === char && board[i][2] === char)
        return 1;
    return 0;
  }

  // 세로 검사
  function isColThree(char) {
    for (let i = 0; i < 3; i++)
      if (board[0][i] === char && board[1][i] === char && board[2][i] === char)
        return 1;
    return 0;
  }

  // 대각선 검사
  function isCrossThree(char) {
    if (board[0][0] === char && board[1][1] === char && board[2][2] === char)
      return 1;
    if (board[0][2] === char && board[1][1] === char && board[2][0] === char)
      return 1;
    return 0;
  }

  // 셋 중 하나라도 O
  if (isRowThree("O") || isColThree("O") || isCrossThree("O"))
    if (totalO === totalX) return 0;

  if (isRowThree("X") || isColThree("X") || isCrossThree("X"))
    if (totalO > totalX) return 0;

  return 1;
}

board = ["...", "...", "..."];
console.log(solution(board));

// <게임규칙>
// 보드판은 3x3
// 선공이 O, 후공이 X
// 가로, 세로, 대각선으로 3개의 같은 표시가 만들어지면 같은 표시를 만든 사람이
// 승리하고 게임이 종료되며 9칸이 모두 차서 더이상 표시할 수 없으면 무승부로
// 게임이 종료
// 규칙에 맞게 진행한 게임판이면 1, 아니면 0 return

// <규칙>
// 1. 항상 O의 개수 - X의 개수 = 0 아니면 1이여야 함
// 2. 가로, 세로, 대각선에 3개가 같은 표시 (X나 O)가 만들어지면 종료되어야 함
//  - O O O 가 있으면, O의 개수 > X여야 함 (O의 개수 <= X의 개수)면 종료 => 0 return
//  - X X X 가 있으면, O의 개수가 X의 개수보다 많으면 안됨  => 0 return
// 3. 그 외의 경우는 올바르게 진행된 경우이므로 1 return
