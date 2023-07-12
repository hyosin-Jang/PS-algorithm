function solution(n, roads, sources, destination) {
	var answer = []

	// 1. nxn의 2차원 배열 있어야 할거같고
	let graph = Array.from({length: n + 1}, () => new Array(n + 1).fill(Infinity))
	// 1-1. 자기자신은 0
	graph = graph.map((row, i) => {
		row[i] = 0
		return row
	})

	// 2. 각 노드에서 dest까지의 최단경로 구하고 싶음
	roads.forEach((road) => {
		let [start, end] = road
		graph[start][end] = 1
		graph[end][start] = 1
		//graph[][]
	})
	//console.log(graph)

	for (let i = 0; i < sources.length; i++) {
		let src = sources[i]
		if (src === destination) {
			answer.push(0)
			continue
		}
		if (graph[src][destination] === 1) {
			answer.push(1)
			continue
		}

		for (let k = 1; k <= n; k++) {
			if (graph[src][k] + graph[k][destination] < graph[src][destination]) {
				// 자기자신
				graph[src][destination] = graph[src][k] + graph[k][destination] // 갱신
			}
		}
		// 한바퀴 다 돌고 작은 값으로 갱신: 그래도 inf라면 못감
		graph[src][destination] === Infinity ? answer.push(-1) : answer.push(graph[src][destination])
	}

	// 3. 갱신할거니까 첨에 다 Infinity로 시작

	// - 현재 노드에서 dest까지 가는 거리 있다면 그걸로 갱신
	//console.log("answer", answer)

	return answer
}

let [n, roads, sources, destination] = [
	5,
	[
		[1, 2],
		[1, 4],
		[2, 4],
		[2, 5],
		[4, 5],
	],
	[1, 3, 5],
	5,
]

solution(n, roads, sources, destination)
