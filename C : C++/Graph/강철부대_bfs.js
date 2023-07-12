function solution(n, roads, sources, destination) {
	let graph = new Array(n + 1).fill(null).map((_) => [])

	let visited = new Array(n + 1).fill(Infinity)
	console.log(graph, visited)

	for (let [start, end] of roads) {
		graph[start].push(end)
		graph[end].push(start)
	}

	const bfs = (destination) => {
		let q = [destination]
		visited[destination] = 0 // 자기자신은 0

		// dst부터 모든 노드까지의 최단거리를 계산하고 싶음
		while (q.length) {
			let idx = q.shift() // 제일 앞에꺼 하나 꺼내기
			for (let newIdx of graph[idx]) {
				if (visited[idx] + 1 < visited[newIdx]) {
					visited[newIdx] = visited[idx] + 1 // 갱신
					q.push(newIdx)
				}
			}
		}
	}

	bfs(destination)

	// console.log("final visited", visited)

	return sources.map((v) => (visited[v] === Infinity ? -1 : visited[v]))
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
