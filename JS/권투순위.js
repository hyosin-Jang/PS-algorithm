function solution(n, results) {
	// 플로이드 와샬 알고리즘 선수 한명이 다른 모든 선수들과 승/패 관계가 맺어져 있는지 확인해야 함
	// 1. result.map으로 winner, loser = 1, loser, winner = -1 적기
	// 2. 삼중 for문 돌면서 만약, 표시가 안되어 있는 경우, k(중간지점) 거쳐가면 표시할 수 있는지 확인
	// 2-1. i k 1이고, k j 가 1이라면, i j 도 1
	// 2-2. i k -1이고, k j 가 -1이라면, i j도 -1
	// 3. 이중 for문 돌면서, accurate로 시작해서, i!=j인데, 2(초기값)이 있다면 false,
	//    반복문 돌고 나서도, true면, answer++
	let answer = 0
	let graph = Array.from(Array(n), () => Array(n).fill(2)) // 2로 초기화

	results.forEach((result) => {
		const [winner, loser] = result.map((x) => x - 1)
		graph[winner][loser] = 1
		graph[loser][winner] = -1
	})

	console.log(graph)

	for (let k = 0; k < n; k++) {
		// 2.
		for (let i = 0; i < n; i++) {
			for (let j = 0; j < n; j++) {
				if (graph[i][j] == 2) {
					// 2-1.
					if (graph[i][k] == 1 && graph[k][j] == 1) graph[i][j] = 1
					if (graph[i][k] == -1 && graph[k][j] == -1) graph[i][j] = -1 // 2-2.
				}
			}
		}
	}
	// 3.
	for (let i = 0; i < n; i++) {
		let accurate = true
		for (let j = 0; j < n; j++) {
			if (i !== j && graph[i][j] === 2) {
				accurate = false
			}
		}
		if (accurate) answer++
	}

	return answer
}
