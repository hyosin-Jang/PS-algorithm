function solution(n, s) {
	var answer = []

	if (n > s) return [-1]

	let quote = Math.floor(s / n)

	answer = Array.from({length: n}, () => quote)
	let idx = 0
	let remainder = s - quote * n // 무조건 n보다 작음 , 1씩 분배
	while (remainder > 0) {
		answer[idx++] = answer[idx] + 1
		remainder--
	}
	answer.sort()

	return answer
}

let n = 2
let s = 8
solution(n, s)

function bestSet(n, s) {
	let answer = new Array.fill(Math.floor(s / n))
	b = s - answer.reduce((a, b) => a + b)

	if (b != s) {
		for (let i = 0; i <= b; i++) answer[answer.length - i]++
	} else answer = [-1] // 누적합이 0이면 b==s

	return answer
}
