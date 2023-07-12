function solution(n, computers) {
	var answer = 0

	// 유니온 파인드 문제

	// 초기화: 자기 자신 가리키도록 설정

	function union(i, j) {
		// 0 0
		if (i == j) return

		i = getParent(i)
		j = getParent(j)

		if (i < j) parent[j] = i
		else parent[i] = j
	}

	let parent = new Array(n).fill(0).map((_, i) => i)

	for (let i = 0; i < n; i++) {
		for (let j = 0; j < n; j++) {
			if (computers[i][j]) {
				union(i, j)
			}
		}
	}

	/*
	computers.map((computer, i) => {
		computer.map((c, j) => {
			// console.log(i, j)
			if (computers[i][j] === 1) {
				union(i, j)
			}
		})
	})
   */
	function getParent(n) {
		if (n !== parent[n]) {
			parent[n] = getParent(parent[n])
		}
		return parent[n]
	}

	// n=총 참여자수
	const uniqueCnt = new Set(parent).size
	console.log("uniqueCnt", uniqueCnt)
	// parent unique한 값의 개수
	return uniqueCnt
}

let n = 1
let computers = [[1]]
solution(n, computers)
