// (x,y) 에서 (r,c)까지 이동하는 거리가 총 k여야 함
// (x,y)와 (r,c)를 포함해 같은 격자를 두 번 이상 방문해도 됨
// 문자열이 사전 순으로 가장 빠른 경로 (이거는 마지막에 리턴할 때 사전순 리턴)

function solution(n, m, x, y, r, c, k) {
	var answer = []
	let start = [x - 1, y - 1]

	;(x -= 1), (y -= 1) // 0, 1
	;(r -= 1), (c -= 1) // 2, 2
	// 시작위치 = x,y
	// 종료 위치 = r,c

	if ((Math.abs(r - x) + Math.abs(c - y)) % 2 !== k % 2) {
		return "impossible"
	}

	let cnt = 0
	// d, l, r, u 순서
	result = ""
	while (x !== r || y !== c || cnt < k) {
		if (cnt == k) break
		// 종료지점에 도착할 때까지 반복
		// 1. 아래
		if (x + 1 < n) {
			// x < 49
			x++
			result += "d"
		}
		// 2. 왼쪽
		else if (y - 1 >= 0) {
			y--
			result += "l"
		} else if (y + 1 < m) {
			// 오른쪽으로 이동 가능한 경우
			y++
			result += "r"
		} else if (x - 1 >= 0) {
			// 위로 이동 가능한 경우
			x--
			result += "u"
		}
		cnt++
	}

	console.log("result", result, typeof result)

	//console.log("final answer", answer)
	//answer.sort()
	// Array.prototype.sort()는 원본 배열을 복사하기 때문에
	// 변경하고 싶지 않다면 먼저 배열을 복사해야 함

	// const sortedArr = [...arr].sort()
	//console.log("sort answer", answer)
	// if (!answer.length) return "impossible"
	return result
}

let [n, m, x, y, r, c, k] = [3, 4, 3, 1, 2, 3, 5]
solution(n, m, x, y, r, c, k)
