function solution(n, t, m, p) {
	let answer = ""
	let cur = 0
	let nNum = 0
	let result = ""

	// mxt개
	while (answer.length < m * t) {
		nNum = cur.toString(n)
		cur++
		console.log("nNum", nNum)
		answer += nNum
		console.log("answer", answer, answer.length)
	}
	for (let i = 0; i < answer.length; i++) {
		//      0 , 1, 2, 3, 4, 5, 6, 7, 8
		// i%2  0   1  0 1   0  1  0  1  0
		// t개를 말해야 함
		if (t == 0) break
		if (i % m == p - 1) {
			console.log("i: ", i, answer[i])
			result += answer[i]
			t--
		}
	}
	console.log("result", result.toUpperCase())

	return result.toUpperCase()
}

solution(16, 16, 2, 2)
