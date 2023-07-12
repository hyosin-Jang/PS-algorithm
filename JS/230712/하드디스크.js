// 지금 처리해야할게 여러개면 먼저 끝나는 것 먼저 처리

// 스택에 [요청시간, 소요시간, 들어온 순서(인덱스)] 쌓고
// 소요시간 짧은거 내뱉기

// 만약, 요청시간 > 현재시간(앞에꺼 끝나는 시간) 이라면, 인덱스 작은거 내뱉기

function solution(jobs) {
	var answer = 0

	// 1. 하드디스크가 비었을 때, 요청시간 순서로 처리해야 하므로, 요청시간 기준 정렬
	// 2. 처리시간이 적은 순서대로 처리함
	// 2-1. 해당 작업을 처리하고 있을 때, 요청이 들어오는 애들은 우선순위 큐에 넣어줌
	// 2-2. 우선순위 큐에 작업이 있으면, 가장 처리시간이 짧은 애 처리
	// 3. jobs가 빌 때까지 반복, pq가 비면 끝나는게 아니라, jobs에 있는 애들은 요청 순서대로 처리해줘야 함
	jobs.sort((a, b) => a[1] - b[1]) // 1.
	let tick = 0 // 시간
	let total = jobs.length
	let queue = []

	// [[0, 3], [1, 9], [2, 6]]
	while (true) {
		let idx = 0

		while (true) {
			// 2-1.
			if (idx >= jobs.length) break
			if (jobs[idx][0] <= tick) queue.push(jobs.splice(idx, 1))
			else idx++
			console.log("2-1")
		}

		if (queue.length > 0) {
			// 2-2.
			console.log("2-2")
			let minIndex = 0
			for (let i = 1; i < queue.length; i++) {
				if (queue[i][1] < queue[minIndex][1]) minIndex = i
			}
			tick += queue[minIndex][1]
			answer += tick - queue[minIndex][0]
			queue.splice(minIndex, 1)
		} else if (queue.length === 0) {
			// 3.
			console.log("3")
			if (jobs.length === 0) break
			else {
				//tick += jobs[0][1];
				//answer += tick-jobs[0][0]; => 시간가지고 빼는 로직이 위랑 2-1이랑 겹침
				tick++
			}
		}
	}

	return parseInt(answer / total)
}
solution([
	[0, 3],
	[1, 9],
	[2, 6],
])
