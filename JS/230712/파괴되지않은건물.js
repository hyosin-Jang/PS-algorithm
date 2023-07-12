// 결국 n*2의 시간복잡도를 가진 자료를 어떻게 압축하냐의 문제
// 상수 시간만에 skill 한 개에 대한 작업을 완료해야 함

function effect(board, skill) {
	let [type, r1, c1, r2, c2, damage] = skill
	let [n, m] = [board.length, board[0].length]
	if (type === 1) damage *= -1 // 적군

	// (r1,c1) ~ (r2, c2)까지 공격/회복
	// 왼쪽위, 오른쪽 아래는 damage 그대로 적용
	// 오른쪽 위, 왼쪽 아래는 damage 반대로 해야 멈춤

	// 왼쪽 아래, 오른쪽 위, 아래는 각각 원래 좌표 한칸뒤
	board[r1][c1] += damage
	if (c2 + 1 < m) board[r1][c2 + 1] -= damage // 반대
	if (r2 + 1 < n) board[r2 + 1][c1] -= damage //반대
	if (c2 + 1 < m && r2 + 1 < n) board[r2 + 1][c2 + 1] += damage

	// 4모서리만 계산
}

function solution(board, skill) {
	var answer = 0
	let aBoard = Array.from({length: board.length}, () => new Array(board[0].length).fill(0))
	//console.log(aBoard)

	for (let i in skill) {
		effect(aBoard, skill[i])
	}

	// 왼쪽 -> 오른쪽
	for (let i = 0; i < aBoard.length; i++) {
		for (let j = 1; j < aBoard.length; j++) {
			aBoard[i][j] += aBoard[i][j - 1]
		}
	}

	// 위 -> 아래
	for (let i = 0; i < aBoard.length; i++) {
		for (let j = 1; j < aBoard.length; j++) {
			aBoard[j][i] += aBoard[j - 1][i]
		}
	}

	// board에 갱신
	for (let i = 0; i < aBoard.length; i++) {
		for (let j = 0; j < aBoard.length; j++) {
			board[i][j] += aBoard[i][j]
		}
	}

	// answer 갱신
	for (let i in board) {
		for (let j in board[i]) {
			if (board[i][j] > 0) answer += 1
		}
	}
}

let board = [
	[5, 5, 5, 5, 5],
	[5, 5, 5, 5, 5],
	[5, 5, 5, 5, 5],
	[5, 5, 5, 5, 5],
]

let skill = [
	[1, 0, 0, 3, 4, 4],
	[1, 2, 0, 2, 3, 2],
	[2, 1, 0, 3, 1, 2],
	[1, 0, 1, 3, 3, 1],
]

solution(board, skill)

/* -- 효율성 테스트 시간초과 풀이
function solution(board, skill) {
	var answer = 0

	// skill: [type, r1, c1, r2, c2, degree]

	// 250,000 x 1,000,000 > skill.map으로 board 탐색하면, 시간초과 날 거 같은데 일단 해보자

	for (let i = 0; i < skill.length; i++) {
		let [type, r1, c1, r2, c2, degree] = skill[i]
		if (type === 1) {
			// 적의 공격, degree만큼 감소
			for (let n = r1; n <= r2; n++) {
				for (let m = c1; m <= c2; m++) {
					board[n][m] -= degree
				}
			}
		} else {
			// 아군의 회복, degree만큼 증가
			for (let n = r1; n <= r2; n++) {
				for (let m = c1; m <= c2; m++) {
					board[n][m] += degree
				}
			}
		}
	}

	for (let i = 0; i < board.length; i++) {
		for (let j = 0; j < board[0].length; j++) {
			if (board[i][j] > 0) answer++
		}
	}

	console.log("answer", answer)
	return answer
}

*/
