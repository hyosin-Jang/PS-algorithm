function solution(numbers) {
	var answer = new Array(numbers.length).fill(-1)

	let stack = []

	// 스택을 이용한 문제였음

	for (let i = 0; i < numbers.length; i++) {
		while (stack.length > 0) {
			if (stack.at(-1)[0] < numbers[i]) {
				answer[stack.at(-1)[1]] = numbers[i]
				stack.pop() // 제일 뒤에서 하나 제거
			} else {
				//stack.push([numbers[i], i]) // 지금 numbers도 넣어놓기
				break
			}
		}
		stack.push([numbers[i], i])
	}

	return answer
}
