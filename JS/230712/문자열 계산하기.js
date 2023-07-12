function solution(my_string) {
	let curNum = 0
	let curOp = 0 // 1: +, 2: -

	// 공백으로 자른 다음에 숫자에 접근해야 함.
	// 음수로 시작할 수도 있기 때문.
	let myNum = my_string.split(" ")

	var answer = Number(myNum[0])

	for (let i = 1; i < myNum.length; i++) {
		if (!isNaN(myNum[i])) {
			console.log(myNum[i])
			curNum = Number(myNum[i]) // 4
			if (curOp === 1) {
				answer += curNum // 7
				curOp = 0
			} else if (curOp === 2) {
				answer -= curNum
				curOp = 0
			}
		} else if (myNum[i] === "+") {
			curOp = 1
		} else if (myNum[i] === "-") {
			curOp = 2
		}
	}

	console.log("answer", answer)
	return answer
}

solution("-5 + 7 - 10")
