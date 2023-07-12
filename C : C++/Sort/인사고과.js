function solution(scores) {
	let answer = 1
	const target = scores[0]

	// 앞에꺼는 내림차순, 뒤에꺼는 오름차순
	scores.sort((a, b) => {
		if (a[0] !== b[0]) return b[0] - a[0]
		return a[1] - b[1]
	})

	let before = 0
	for (const s of scores) {
		console.log("s: ", s, "before", before, "answer", answer)
		if (target[0] < s[0] && target[1] < s[1]) return -1
		if (before <= s[1]) {
			if (target[0] + target[1] < s[0] + s[1]) answer++ // 앞에 몇명이 있는지 세어주는거
			before = s[1]
		}
	}

	return answer
}

let scores = [
	[2, 2],
	[1, 4],
	[3, 2],
	[3, 2],
	[2, 1],
]
solution(scores)
