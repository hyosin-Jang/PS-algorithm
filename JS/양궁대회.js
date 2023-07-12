// 0점부터 시작해서, 10점까지 각 칸에 대해, 이길지 말지를 결정하며 이긴다면 어피치 + 1개의 화살을 쏨
// 1. 만약, count(현재까지 쏜 화살의 갯수) > n(최대 화살 수) 리턴
// 1-1. idx == 10, 10점까지 다 쐈다는 것이므로, 점수 계산 후 갱신
//  - 만약, 남은 화살 수가 있다면 (count < n ) scoreBoard[10] = n-count(남은 화살수)를 넣어줌
// 2. 재귀 파트
// 2-1. n > count인지 검사(쏠 수 있다면, 현재 idx 라이언이 먹기)
// 2-2. n===count라면, 이미 화살 다 쏜거니까 어피치가 이김.
// 2-3. n===count인데, 둘 다 0이라면 둘 다 점수 못먹으니까, idx만 증가시킴

function solution(n, info) {
	let result = Array.from({length: 11}, () => 0) // maxDiff일 때 라이언 점수 배열
	let max = 0

	function shot(peachScore, ryanScore, count, idx, scoreBoard) {
		if (n < count) return
		if (idx > 10) {
			if (n > count) {
				scoreBoard[10] = n - count
			}
			// 낮은 점수부터 채워가므로, max가 갱신될 때만 갈아낌(동점처리 로직은 없어도 됨)
			if (max < ryanScore - peachScore) {
				max = ryanScore - peachScore
				result = scoreBoard
			}
			return
		}
		if (n > count) {
			// 남은 화살 수 있는 경우
			let candidate = [...scoreBoard]
			candidate[10 - idx] = info[10 - idx] + 1
			shot(peachScore, ryanScore + idx, count + candidate[10 - idx], idx + 1, candidate)
		}
		// 어피치가 점수 먹음
		if (info[10 - idx] > 0) {
			shot(peachScore + idx, ryanScore, count, idx + 1, scoreBoard)
		} else {
			// 둘 다 못먹음
			shot(peachScore, ryanScore, count, idx + 1, scoreBoard)
		}
	}
	shot(0, 0, 0, 0, result)

	if (max <= 0) return [-1]

	return result
}
