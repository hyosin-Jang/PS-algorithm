// 처음과 끝이 연결되어 있는 원형수열로부터 길이마다 연속 부분 수열의 합을 구해야하므로
// 원형 수열로부터 접근해야 되는 문제는 주어진 배열 2개를 이어붙인다

// 1. 반복문을 통해 twoElement를 slice로 자르고
// 2. reduce로 합을 구해
// 3. sumSet에 add
// - 이때, sliceLength는 슬라이스를 각 길에 맞게 잘라줄 때 사용하는 변수

function solution(elements) {
	var answer = 0

	const twoElements = [...elements, ...elements] // [7, 9, 1, 1, 4, 7, 9, 1, 1, 4]
	const sumSet = new Set() // 중복된 합의 개수 제거

	for (let i = 0; i < elements.length; i++) {
		let sliceLength = 1

		// Array.prototype.slice(start, end): start부터 end 미포함 인덱스임, 자르는 개수가 아니라.
		// 그래서 j가 증가함에 따라 같이 증가시켜야 함

		// i가 자르는 개수네
		// i:0일 때, 길이 1짜리 저장됨 [7], [9], [1], [1], [4]

		// ㅑ

		for (let j = 0; j < elements.length; j++) {
			// i = 0, j = 0
			// [7]

			const sum = twoElements.slice(j, sliceLength + i).reduce((acc, cur) => acc + cur, 0)

			// ..slice(1, 2 + 0)
			sumSet.add(sum)
			sliceLength++ // 2
		}
	}

	return sumSet.size
}
let elements = [7, 9, 1, 1, 4]
// 길이 1: [7, 9, 1, 1, 4]
// 길이 2: [7, 9, 1, 1, 4, 7]
// 길이 3: [7, 9, 1, 1, 4, 7, 9]
// 길이 4: [7, 9, 1, 1, 4, 7, 9, 1]
// 길이 5: [7, 9, 1, 1, 4, 7, 9, 1, 1]

// 누적합, dp

solution(elements)
