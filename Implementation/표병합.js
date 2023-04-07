function isMerged(merge, [r, c]) {
	if (!merge.length) return []

	for (let i = 0; i < merge.length; i++) {
		for (let j = 0; j < merge[i].length; j++) {
			if (JSON.stringify(merge[i][j]) == JSON.stringify([r, c])) {
				let temp = merge[i]
				merge.splice(i, 1) // 잘라내기
				return temp
			}
		}
	}
	return []
}

function updateAllValue(board, value1, value2) {
	for (let i = 0; i < 51; i++) {
		for (let j = 0; j < 51; j++) {
			if (board[i][j] === value1) {
				board[i][j] = value2
			}
		}
	}
}

function isMergedSameCell(merge, [r1, c1], [r2, c2]) {
	let mergeArr1 = isMerged(merge, [r1, c1]) // [2, 1]
	if (mergeArr1.length) merge.push(mergeArr1)

	// r1, c1이 속해 있는 MergeArr1에서 r2, c2 있나 확인
	let isInMergeArr1 = mergeArr1.filter((coor) => coor[0] == r2 && coor[1] === c2)
	if (isInMergeArr1.length) return true

	return false
}

// 0: 둘다 빈 경우
// 1: r1, c1에만 값이 있음
// 2: r2, c2에만 값이 있음
// 3: 둘 다 값이 있음
function checkEmpty(board, [r1, c1], [r2, c2]) {
	let val1 = board[r1][c1]
	let val2 = board[r2][c2]
	if (!val1 && !val2) return 0
	if (!val2) return 1
	if (!val1) return 2
	return 3
}

function solution(commands) {
	var answer = []
	var merge = []

	// 50x50
	let r, c, word, r1, c1, r2, c2
	let board = Array.from({length: 51}, () => Array.from({length: 51}, () => 0))

	for (let i = 0; i < commands.length; i++) {
		const command = commands[i].split(" ")[0]

		switch (command) {
			case "UPDATE":
				const len = commands[i].split(" ").length
				if (len === 3) {
					;[_, value1, value2] = commands[i].split(" ")
					updateAllValue(board, value1, value2)
				} else {
					// UPDATE r c value가 온 경우
					;[_, r, c, word] = commands[i].split(" ")
					r = Number(r)
					c = Number(c)

					// [r, c]와 병합된 셀이 있는지 확인
					let mergeArr = isMerged(merge, [r, c])
					if (!mergeArr.length) board[r][c] = word
					else {
						// mergeArr 에 든거 다 업데이트
						mergeArr.forEach((coor) => (board[coor[0]][coor[1]] = word))
						merge.push(mergeArr)
					}
				}
				break
			case "MERGE":
				;[_, r1, c1, r2, c2] = commands[i].split(" ").map(Number)
				// 선택된 셀이 같은 셀인 경우 무시
				if (r1 == r2 && c1 == c2) break
				else if (isMergedSameCell(merge, [r1, c1], [r2, c2])) break

				let mergeArr1 = isMerged(merge, [r1, c1])
				let mergeArr2 = isMerged(merge, [r2, c2])

				// 둘 다 속한 곳이 없는 경우
				if (!mergeArr1.length && !mergeArr2.length) {
					let checkValFlag = checkEmpty(board, [r1, c1], [r2, c2])
					switch (checkValFlag) {
						case 0:
							// 0: 둘다 빈 경우
							break
						case 1:
							// r1, c1만 값이 있음
							board[r2][c2] = board[r1][c1]
							break
						case 2:
							board[r1][c1] = board[r2][c2]
							break
						case 3:
							// 둘 다 값이 있음
							board[r2][c2] = board[r1][c1]
							break
					}
					merge.push([
						[r1, c1],
						[r2, c2],
					])
				} else if (!mergeArr1.length) {
					// r1,c1은 소속된 데가 없는데, r2, c2는 소속된 데가 있는 경우
					let checkValFlag = checkEmpty(board, [r1, c1], [r2, c2])
					switch (checkValFlag) {
						case 0:
							// 0: 둘다 빈 경우
							break
						case 1:
							// r1, c1만 값이 있음
							mergeArr2.forEach((coor) => (board[coor[0]][coor[1]] = board[r1][c1]))
							break
						case 2:
							// r2, c2만 값이 있음
							board[r1][c1] = board[r2][c2]
							break
						case 3:
							// 둘 다 값이 있음
							mergeArr2.forEach((coor) => (board[coor[0]][coor[1]] = board[r1][c1]))
							break
					}
					mergeArr2 = [...mergeArr2, [r1, c1]]
					merge.push(mergeArr2)
				} else if (!mergeArr2.length) {
					// r1, c1는 소속이 있는데 r2, c2는 없는 경우
					let checkValFlag = checkEmpty(board, [r1, c1], [r2, c2])
					switch (checkValFlag) {
						case 0:
							// 0: 둘다 빈 경우
							break
						case 1:
							// r1, c1만 값이 있음
							board[r2][c2] = board[r1][c1]
							break
						case 2:
							// r2, c2만 값이 있음
							mergeArr1.forEach((coor) => (board[coor[0]][coor[1]] = board[r2][c2]))
							break
						case 3:
							// 둘 다 값이 있음
							board[r2][c2] = board[r1][c1]
							break
					}
					mergeArr1 = [...mergeArr1, [r2, c2]]
					merge.push(mergeArr1)
				}
				// 둘 다 속한데가 있는 경우
				else {
					let checkValFlag = checkEmpty(board, [r1, c1], [r2, c2])
					// 값 합치기
					switch (checkValFlag) {
						case 0:
							// 0: 둘다 빈 경우
							break
						case 1:
							// r1, c1만 값이 있음
							mergeArr2.forEach((coor) => (board[coor[0]][coor[1]] = board[r1][c1]))
							break
						case 2:
							// r2, c2만 값이 있음
							mergeArr1.forEach((coor) => (board[coor[0]][coor[1]] = board[r2][c2]))
							break
						case 3:
							// 둘 다 값이 있음
							mergeArr2.forEach((coor) => (board[coor[0]][coor[1]] = board[r1][c1]))
							break
					}
					let newMergeArr = [...mergeArr1, ...mergeArr2]
					merge.push(newMergeArr)
				}
				break
			case "UNMERGE":
				;[_, r, c] = commands[i].split(" ").map(Number)
				let mergeArr = isMerged(merge, [r, c]) // [r, c]가 포함된 셀 mergeArr에서 빠짐
				if (board[r][c] !== 0) {
					let temp = board[r][c]
					// 모든 셀 값 0으로 만들고 board[r][c]만 해당 값 유지
					mergeArr.forEach((coor) => (board[coor[0]][coor[1]] = 0))
					board[r][c] = temp
				} else {
					// 값이 없는 경우
					mergeArr.forEach((coor) => (board[coor[0]][coor[1]] = 0))
				}
				break
			case "PRINT":
				;[_, r, c] = commands[i].split(" ")
				if (board[r][c] === 0) answer.push("EMPTY")
				else answer.push(board[r][c])
				break
		}
	}
	return answer
}

commands = [
	"UPDATE 1 1 menu",
	"UPDATE 1 2 category",
	"UPDATE 2 1 bibimbap",
	"UPDATE 2 2 korean",
	"UPDATE 2 3 rice",
	"UPDATE 3 1 ramyeon",
	"UPDATE 3 2 korean",
	"UPDATE 3 3 noodle",
	"UPDATE 3 4 instant",
	"UPDATE 4 1 pasta",
	"UPDATE 4 2 italian",
	"UPDATE 4 3 noodle",
	"MERGE 1 2 1 3",
	"MERGE 1 3 1 4",
	"UPDATE korean hansik",
	"UPDATE 1 3 group",
	"UNMERGE 1 4",
	"PRINT 1 3",
	"PRINT 1 4",
]

solution(commands)
