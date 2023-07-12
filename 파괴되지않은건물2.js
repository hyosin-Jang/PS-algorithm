function effect(board, skill) {
	let [type, r1, c1, r2, c2, degree] = skill
	let [n, m] = [board.length, board[0].length]
	if (type === 1) degree *= -1
	board[r1][c1] += degree
	if (c2 + 1 < m) board[r1][c2 + 1] -= degree
	if (r2 + 1 < n) board[r2 + 1][c1] -= degree
	if (r2 + 1 < n && c2 + 1 < m) board[r2 + 1][c2 + 1] += degree
}

function solution(board, skill) {
	let answer = 0
	let aBoard = Array.from({length: board.length}, () => new Array(board[0].length).fill(0))
	let [n, m] = [board.length, board[0].length]
	for (let i in skill) {
		effect(aBoard, skill[i])
	}

	// 가로 누적합 계산
	for (let i = 0; i < n; i++) {
		for (let j = 1; j < m; j++) {
			aBoard[i][j] += aBoard[i][j - 1]
		}
	}

	// 세로 누적합 계산
	for (let i = 0; i < n; i++) {
		for (let j = 1; j < n; j++) {
			aBoard[j][i] += aBoard[j - 1][i]
		}
	}

	// aBoard -> board로 옮기기
	for (let i = 0; i < n; i++) {
		for (let j = 0; j < m; j++) {
			board[i][j] += aBoard[i][j]
		}
	}

	// answer 계산
	for (let i = 0; i < n; i++) {
		for (let j = 0; j < m; j++) {
			if (board[i][j] > 0) answer++
		}
	}

	return answer
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
