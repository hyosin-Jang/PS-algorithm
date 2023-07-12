// 1. table로부터 퍼즐 조각 추출해서 저장
// 2. game_baord를 회전해가며 빈 부분들에 퍼즐 조각들을 끼우고,
// -- 맞을 경우 퍼즐 조각 삭제 + 보드 빈 공간 채움

function solution(game_board, table) {
	var answer = 0
	const length = game_board.length
	inBound = isValueInBound(length)

	const puzzles = []
	for (let r = 0; r < length; r++) {
		for (let c = 0; c < length; c++) {
			if (table[r][c]) {
				puzzles.push(getPieces(table, r, c, 0, 0))
			}
		}
	}

	for (let rotate = 0; rotate < 4; rotate++) {
		for (let r = 0; r < length; r++) {
			for (let c = 0; c < length; c++) {
				if (!game_board[r][c]) {
					// 빈칸이라면 퍼즐 배열에 있는 퍼즐들 조회
					for (let i = 0; i < puzzles.length; i++) {
						const puzzle = puzzles[i] // 현재 맞춰볼 퍼즐
						const emptySize = getEmptySize(game_board, r, c) // 현재 보드 빈칸의 개수
						if (emptySize !== puzzle.length) continue // 다음 퍼즐 맞춰보기

						const check = checkPuzzleFit(game_board, puzzle, r, c)
						if (check) {
							puzzles.splice(i, 1) // 현재 퍼즐 제거
							updateBoard(game_board, puzzle, r, c)
							answer += puzzle.length
							break
						}
					}
				}
			}
		}
		game_board = rotateMatrix(game_board)
	}

	// 1. table로부터 퍼즐 조각 추출 (값이 1)

	// 2. game_baord에서 값이 0인 부분 확인

	// 3. 모든 퍼즐에 대해 빈부분이 일치하는지 확인
	// 3-1. 퍼즐의 사이즈와 빈 부분의 사이즈가 동일한지 확인
	// 3-2. 퍼즐의 모양과 빈 부분의 모양이 동일한지 확인
	// 3-3. 둘다 만족하면, 사용된 퍼즐 삭제 + 퍼즐이 들어간 부분 값 1로 변경, answer 증가
	// 4. game_board 회줜

	return answer
}

const rotateMatrix = (matrix) => {
	const length = matrix.length
	const newMatrix = Array.from({length: length}, () => new Array(length).fill(0))
	for (let r = 0; r < length; r++) {
		for (let c = 0; c < length; c++) {
			newMatrix[c][length - r - 1] = matrix[r][c]
		}
	}
	return newMatrix
}

// 보드 내 퍼즐이 채워진 부분 값 변경
const updateBoard = (board, puzzle, r, c) => {
	puzzle.map((piece) => {
		const {row, col} = piece // offset
		board[r + row][c + col] = 1 // 1로 채우기
	})
}

// 해당 위치에 퍼즐 맞는지 확인
const checkPuzzleFit = (board, puzzle, r, c) =>
	puzzle.every((piece) => {
		const {row, col} = piece
		return inBound(r + row) && inBound(c + col) && board[r + row][c + col] === 0
	})

// 해당 빈 공간의 크기 측정
const getEmptySize = (board, r, c, visited = []) => {
	visited.push({
		row: r,
		col: c,
	})
	// 하나라도 만족하는게 있으면 true
	const isVisited = (row, col) => visited.some((piece) => piece.row === row && piece.col === col)

	let count = 1

	// 방문 안했고 + 바운더리 안 + 빈칸
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

// 테이블에서 퍼즐 추출
const getPieces = (table, r, c, r_off, c_off) => {
	const len = table.length
	table[r][c] = 0
	const pieces = [
		{
			row: r_off,
			col: c_off,
		},
	]
	// 범위 내에 있고, 다음도 1인 경우
	if (inBound(r + 1) && table[r + 1][c]) {
		pieces.push(...getPieces(table, r + 1, c, r_off + 1, c_off)) // offset: 현지 위치와의 인덱스 차이
	} // 기존 [{0, 0}, {-1, 0}, {0, 1}]
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

const isValueInBound = (len) => (val) => val >= 0 && val < len // len은 미리 넣어놓음!, 클로저 개념
