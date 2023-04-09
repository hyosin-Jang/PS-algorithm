// 시작 > 끝, 최소 몇 번만에 도달
// 장애물이나 끝까지 이동하는 게 한번 이동

function solution(board) {
	let start, end
	let cnt = 0
	let answer = Infinity

	board = board.map((str) => str.split(""))

	let [n, m] = [board.length, board[0].length]

	let visit = Array.from({length: n}, () => Array.from({length: m}, () => Infinity))

	// R, G 저장
	for (let i = 0; i < n; i++) {
		for (let j = 0; j < m; j++) {
			if (board[i][j] === "R") {
				start = [i, j]
				continue
			} else if (board[i][j] === "G") {
				end = [i, j]
			}
		}
	}

	// 문제는 종료조건을 어떻게 잡을지, 목표위치에 도달할 수 없는 경우를 어떻게 찾을지인데
	// 갈 수 있는 곳은 다 방문해서 방문했던 곳 또방문하게 되면 -1

	// 상, 하, 좌, 우
	let dir = [
		[-1, 0],
		[1, 0],
		[0, -1],
		[0, 1],
	]

	function getNextCoord(start, dir) {
		let [curX, curY] = start

		while (1) {
			let nx = curX + dir[0]
			let ny = curY + dir[1]
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] === "D")
				return [curX, curY] // 현재 위치가 최종
			;(curX = nx), (curY = ny) // 갱신
		}
	}

	function dfs(start, cnt) {
		if (start[0] === end[0] && start[1] === end[1]) {
			answer = Math.min(answer, cnt)
			return
		}

		// 2-1. 먼저 현재 위치 방문 표시
		visit[start[0]][start[1]] = Math.min(visit[start[0]][start[1]], cnt)

		let isAllVisit = 0

		for (let i = 0; i < 4; i++) {
			let [nx, ny] = getNextCoord(start, dir[i])

			if (visit[nx][ny] > cnt) {
				// 더 작은 횟수로 이동할 수 있다면
				dfs([nx, ny], cnt + 1)
				continue
			} else isAllVisit++

			if (isAllVisit === 4) return -1 //모두 방문해서 방문할 수 없다면 -1 리턴
		}
	}

	dfs(start, cnt)
	return answer == Infinity ? -1 : answer
}

let board = [".D.R", "....", ".G..", "...D"]

solution(board)
