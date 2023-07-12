function solution(routes) {
	// 정렬
	routes.sort((a, b) => a[0] - b[0])
	let [min, max] = routes[0]
	let answer = 1

	for (let i = 1; i < routes.length; i++) {
		if (routes[i][1] <= max) {
			;[min, max] = routes[i]
			continue
		}
		if (routes[i][0] <= max) continue // 진입점이 max보다 작다면
		answer++
		;[min, max] = routes[i]
	}
	//console.log("answer", answer)
	return answer
}

let routes = [
	[-20, -15],
	[-14, -5],
	[-18, -13],
	[-5, -3],
]

solution(routes)

// 파이썬 풀이
/**
 * def solution(routes):
    routes.sort(key=lambda x: x[0])
    a = 1
    m = 30_000
    for i, j in routes:
        if i > m:
            a += 1
            m = j
        m = min(m, j)
    return a
 * 
 * 
 * 
 */
