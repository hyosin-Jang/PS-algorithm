// (x,y) 에서 (r,c)까지 이동하는 거리가 총 k여야 함
// (x,y)와 (r,c)를 포함해 같은 격자를 두 번 이상 방문해도 됨
// 문자열이 사전 순으로 가장 빠른 경로 (이거는 마지막에 리턴할 때 사전순 리턴)

function solution(n, m, x, y, r, c, k) {
	var answer = []
	let start = [x - 1, y - 1]

	/**
    * ....
      ..S.
      E...
    */
	// 출구까지 거리 검사

	// start = [2, 3], end = [3,1]
	// 1+ 2 = 3
	if ((Math.abs(r - x) + Math.abs(c - y)) % 2 !== k % 2) {
		return "impossible"
	}

	// 사전 순 정렬
	let dir = [
		[1, 0, "d"],
		[0, -1, "l"],
		[0, 1, "r"],
		[-1, 0, "u"],
	]
	function bfs(cur, cnt, result) {
		//console.log("cur", cur, "cnt", cnt, "result", result)
		if (cnt === k) {
			// 기저조건
			// k번 움직였을 때, E에 도착했다면 넣기
			let [curX, curY] = cur
			if (curX == r - 1 && curY == c - 1) {
				//console.log("result 만족", result)
				answer.push(result)
				answer.sort() // 항상 사전 순 유지
			}
			return
		}
		for (let i = 0; i < 4; i++) {
			let nx = cur[0] + dir[i][0]
			let ny = cur[1] + dir[i][1]
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue
			if (cnt === 0 && answer.length > 0 && answer[0][0] < dir[i][2]) {
				continue
				// cnt가 1일 때, 이미 answer에 담긴 것보다 사전 순으로 뒤에 나온다면 탐색 안하기
			}
			if (cnt === 1 && answer.length > 0 && answer[0][1] < dir[i][2]) {
				continue
				// cnt가 1일 때, 이미 answer에 담긴 것보다 사전 순으로 뒤에 나온다면 탐색 안하기
			}
			if (cnt === 2 && answer.length > 0 && answer[0][2] < dir[i][2]) {
				continue
				// cnt가 1일 때, 이미 answer에 담긴 것보다 사전 순으로 뒤에 나온다면 탐색 안하기
			}
			if (cnt === 3 && answer.length > 0 && answer[0][3] < dir[i][2]) {
				continue
				// cnt가 1일 때, 이미 answer에 담긴 것보다 사전 순으로 뒤에 나온다면 탐색 안하기
			}
			bfs([nx, ny], cnt + 1, result + dir[i][2])
		}
	}

	bfs(start, 0, "")

	//console.log("final answer", answer)
	answer.sort()
	// Array.prototype.sort()는 원본 배열을 복사하기 때문에
	// 변경하고 싶지 않다면 먼저 배열을 복사해야 함

	// const sortedArr = [...arr].sort()
	//console.log("sort answer", answer)
	if (!answer.length) return "impossible"
	return answer[0]
}

let [n, m, x, y, r, c, k] = [3, 4, 2, 3, 3, 1, 5]
solution(n, m, x, y, r, c, k)
