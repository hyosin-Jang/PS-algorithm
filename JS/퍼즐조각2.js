// 1. table에서 퍼즐 조각 담기
// 2. game_board를 네 방향으로 돌려가며
// 2-1. 빈칸이 나오면, 길이가 퍼즐 길이랑 같은지 검사
// 2-2. 모양이 퍼즐 모양이랑 같은지 검사
// 3. 맞으면, 해당 빈칸을 1로 채우고, 해당 퍼즐 조각 제거 (퍼즐 조각 길이만큼 answer++)

function solution(game_board, table) {
	var answer = 0
	let length = game_board.length
	inBound = isValidInBound(length)

	const puzzles = []

	for (let r = 0; r < length; r++) {
		for (let c = 0; c < length; c++) {
			if (table[r][c]) puzzles.push(getPieces(table, r, c, 0, 0))
		}
	}
	// console.log("puzzles", puzzles)

	for (let rotate = 0; rotate < 4; rotate++) {
		for (let r = 0; r < length; r++) {
			for (let c = 0; c < length; c++) {
				if (!game_board[r][c]) {
					for (let i = 0; i < puzzles.length; i++) {
						const puzzle = puzzles[i]
						// 2-1.
						let cnt = getEmptyLength(game_board, r, c)
						if (cnt !== puzzle.length) continue

						const check = checkPuzzleFit(game_board, puzzle, r, c) // 2-2. 모양 검사
						if (check) {
							// 3. 퍼즐 제거
							puzzles.splice(i, 1)
							updateBoard(game_board, puzzle, r, c)
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
	const len = board.length
	const newMatrix = Array.from({length: len}, () => new Array(len).fill(0))

	for (let i = 0; i < len; i++) {
		for (let j = 0; j < len; j++) {
			newMatrix[j][len - i - 1] = board[i][j]
		}
	}
	return newMatrix
}

const updateBoard = (board, puzzle, r, c) => {
	puzzle.map((piece) => {
		const {row, col} = piece
		board[r + row][c + col] = 1
	})
}

const checkPuzzleFit = (board, puzzle, r, c) =>
	puzzle.every((piece) => {
		const {row, col} = piece
		return inBound(r + row) && inBound(c + col) && board[r + row][c + col] === 0
	})

const getEmptyLength = (board, r, c, visited = []) => {
	visited.push({
		row: r,
		col: c,
	})
	const isVisited = (row, col) => visited.some((piece) => piece.row === row && piece.col === col)

	let count = 1

	if (!isVisited(r + 1, c) && inBound(r + 1) && !board[r + 1][c]) count += getEmptyLength(board, r + 1, c, visited)
	if (!isVisited(r - 1, c) && inBound(r - 1) && !board[r - 1][c]) count += getEmptyLength(board, r - 1, c, visited)
	if (!isVisited(r, c + 1) && inBound(c + 1) && !board[r][c + 1]) count += getEmptyLength(board, r, c + 1, visited)
	if (!isVisited(r, c - 1) && inBound(c - 1) && !board[r][c - 1]) count += getEmptyLength(board, r, c - 1, visited)

	return count
}

const getPieces = (table, r, c, r_off, c_off) => {
	// r, c를 기준으로 탐색
	table[r][c] = 0 // 방문처리

	let pieces = [
		{
			row: r_off,
			col: c_off,
		},
	]
	if (inBound(r + 1) && table[r + 1][c]) {
		pieces.push(...getPieces(table, r + 1, c, 1, 0))
	}
	if (inBound(r - 1) && table[r - 1][c]) {
		pieces.push(...getPieces(table, r - 1, c, -1, 0))
	}
	if (inBound(c + 1) && table[r][c + 1]) {
		pieces.push(...getPieces(table, r, c + 1, 0, 1))
	}
	if (inBound(c - 1) && table[r][c - 1]) {
		pieces.push(...getPieces(table, r, c - 1, 0, -1))
	}

	return pieces
}

const isValidInBound = (length) => (val) => val >= 0 && val < length
