// 1. 테이블에서 퍼즐 줍기
// 2. 게임보드를 네 방향으로 돌려가며 맞으면 넣기
// 2-1. 길이 맞는지 검사
// 2-2. 모양 맞는지 검사
// 3. 맞으면 해당 조각으로 보드를 1로 채우고, 퍼즐 빼고, answer 퍼즐 길이만큼 증가

function solution(game_board, table) {
	var answer = 0
	let length = game_board.length

	inBound = isValidBound(length)
	const puzzles = []

	for (let r = 0; r < length; r++) {
		for (let c = 0; c < length; c++) {
			if (table[r][c]) puzzles.push(getPieces(table, r, c, 0, 0)) // 1.
		}
	}

	for (let rotate = 0; rotate < 4; rotate++) {
		for (let r = 0; r < length; r++) {
			for (let c = 0; c < length; c++) {
				if (!game_board[r][c]) {
					for (let i = 0; i < puzzles.length; i++) {
						const puzzle = puzzles[i]

						let cnt = getEmptySize(game_board, r, c)

						if (cnt !== puzzle.length) continue // 지금 퍼즐 안맞으면 다음 퍼즐 맞춰보기
						// 모양 맞는지 검사
						const check = checkPuzzleFit(game_board, r, c, puzzle)
						if (check) {
							puzzles.splice(i, 1)

							updateBoard(game_board, r, c, puzzle)
							answer += puzzle.length
							break
						}
					}
				}
			}
		}
		game_board = rotateBoard(game_board)
	}

	return answer
}

const rotateBoard = (board) => {
	const length = board.length
	let newBoard = Array.from({length: length}, () => new Array(length).fill(0))
	for (let i = 0; i < length; i++) {
		for (let j = 0; j < length; j++) {
			newBoard[j][length - i - 1] = board[i][j]
		}
	}
	return newBoard
}

const updateBoard = (board, r, c, puzzle) => {
	puzzle.map((piece) => {
		const {row, col} = piece
		board[r + row][c + col] = 1 // 1로 채우기
	})
}

const checkPuzzleFit = (board, r, c, puzzle) =>
	puzzle.every((piece) => {
		const {row, col} = piece
		return inBound(r + row) && inBound(c + col) && board[r + row][c + col] === 0
	})

const getEmptySize = (board, r, c, visited = []) => {
	visited.push({
		row: r,
		col: c,
	})

	// visited에 있는 모든 원소에 대해서 달라야 함.
	// 하나라도 같은게 있다면 종료.
	const isVisited = (row, col) => visited.some((piece) => piece.row === row && piece.col === col) // 하나라도 true면 종료

	let count = 1

	if (!isVisited(r + 1, c) && inBound(r + 1) && !board[r + 1][c]) {
		count += getEmptySize(board, r + 1, c, visited)
	}
	if (!isVisited(r - 1, c) && inBound(r - 1) && !board[r - 1][c]) {
		count += getEmptySize(board, r - 1, c, visited)
	}
	if (!isVisited(r, c + 1) && inBound(c + 1) && !board[r][c + 1]) {
		count += getEmptySize(board, r, c + 1, visited)
	}
	if (!isVisited(r, c - 1) && inBound(c - 1) && !board[r][c - 1]) {
		count += getEmptySize(board, r, c - 1, visited)
	}

	return count
}

const getPieces = (table, r, c, r_off, c_off) => {
	table[r][c] = 0 //주웠으니까

	let pieces = [
		{
			row: r_off,
			col: c_off,
		},
	]

	if (inBound(r + 1) && table[r + 1][c]) {
		pieces.push(...getPieces(table, r + 1, c, r_off + 1, c_off))
	}
	if (inBound(r - 1) && table[r - 1][c]) {
		pieces.push(...getPieces(table, r - 1, c, r_off - 1, c_off))
	}
	if (inBound(c + 1) && table[r][c + 1]) {
		pieces.push(...getPieces(table, r, c + 1, r_off, c_off + 1))
	}
	if (inBound(c - 1) && table[r][c - 1]) {
		pieces.push(...getPieces(table, r, c - 1, r_off, c_off - 1))
	}

	return pieces
}

const isValidBound = (len) => (val) => val >= 0 && val < len
