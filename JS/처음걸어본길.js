function solution(dirs) {
	var answer = 0

	let board = Array.from({length: 11}, () => new Array(11).fill(0))
	let set = new Set()
	// console.log(board)
	// 방문 횟수 기록
	let start = [5, 5]

	function getOppositeDir(dir) {
		if (dir === "U") return "D"
		if (dir === "D") return "U"
		if (dir === "L") return "R"
		return "L"
	}
	let dir = {U: [-1, 0], D: [1, 0], L: [0, -1], R: [0, 1]} // 상 하 좌 우
	for (let i = 0; i < dirs.length; i++) {
		let [cx, cy] = start
		let [dx, dy] = dir[dirs[i]] // [-1. 0]
		let [nx, ny] = [dx + cx, dy + cy]

		if (nx < 0 || ny < 0 || nx >= 11 || ny >= 11) continue

		set.add(JSON.stringify([cx, cy, dirs[i]])) // 현재 위치 기준으로 올라가는 것과
		set.add(JSON.stringify([nx, ny, getOppositeDir(dirs[i])])) // U(0) <-> D(1), L(2) <-> R(3)

		//board[nx][ny] += 1 // 다음 위치에 현재 위치 + 1한 값 기록

		//console.log("cx", cx, "cy", cy, "dirs[i]", dirs[i])
		//console.log("nx", nx, "ny", ny, "getOppositeDir(dirs[i])", getOppositeDir(dirs[i]))
		start = [nx, ny]
	}
	//console.log("set.size", set.size, set.size / 2)

	//for (let i of set) {
	//console.log("set) ", i)
	//}

	// 값이 1인 칸의 개수 세서 리턴 >
	/*
	for (let i = 0; i < board.length; i++) {
		for (let j = 0; j < board[0].length; j++) {
			if (board[i][j] === 1) {
				answer++
			}
		}
	}
   */

	//console.log("answer", answer)

	return set.size / 2
}

let dirs = "ULURRDLLU"

solution(dirs)
