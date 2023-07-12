// 1. dfs 11C5 중복허용으로 뽑기
// 2. 5개 뽑았을 때, 점수 계산
// 3. 라이언이 이겼을 때, 점수 차이가 가장 큰 걸로 갱신
// 3-1. 만약, 이 전 값이랑 동일하다면, 가장 낮은 점수를 많이 맞힌 경우로 갱신 (점수 배열 + 점수차도 가지고 있어야 함)

let maxScoreDiffArr = new Array(11).fill(0) // 가장 큰 점수 차이일 때, 점수 배열
// -> 시간초과
function solution(n, info) {
	let maxScoreDiff = 0 // 가장 큰 점수 차

	// 중복허용해서 11개 중 5개 뽑는 함수
	let result = new Array(11).fill(0)

	const getScore = (ryanScoreArr) => {
		let ryanScore = 0
		let appeachScore = 0
		for (let i = 0; i < 11; i++) {
			if (ryanScoreArr[i] === 0 && info[i] === 0) continue
			if (ryanScoreArr[i] > info[i]) ryanScore += 10 - i
			else appeachScore += 10 - i
		}
		return [ryanScore, appeachScore]
	}

	const getMoreLowerScore = (result, maxScoreDiffArr) => {
		for (let i = result.length - 1; i >= 0; i--) {
			if (result[i] !== maxScoreDiffArr[i]) {
				return result[i] - maxScoreDiffArr[i]
			}
		}
	}

	const dfs = (cnt, index, ryanScoreArr, ryanScore) => {
		if (cnt >= n) {
			// 끝까지 오든, 안오든 개수가 n개가 되면 여기 걸림
			// 종료 시 로직 계산
			if (cnt > n) return // 초과

			let [rScore, aScore] = getScore(ryanScoreArr)
			if (maxScoreDiff < rScore - aScore) {
				maxScoreDiffArr = ryanScoreArr
				maxDiffScore = rScore - aScore
				//console.log("1) ryanScoreArr", ryanScoreArr)
				console.log("2) maxScoreDiffArr", maxScoreDiffArr)
			} else if (maxScoreDiff == rScore - aScore) {
				if (getMoreLowerScore(ryanScoreArr, maxScoreDiffArr)) {
					// 갱신
					maxScoreDiffArr = ryanScoreArr
					console.log("3) maxScoreDiffArr", maxScoreDiffArr)
				}
			}

			return
		}
		if (index === 11) {
			// 무조건 개수가 N개 보다 적다는 뜻이니까, 그냥 종료
			return
		}

		// 현재 점수 먹기로 결정한 경우
		ryanScoreArr[index] = info[index] + 1
		dfs(cnt + ryanScoreArr[index], index + 1, ryanScoreArr, ryanScore + (10 - index))

		// 현재 점수 안먹기로 결정한 경우
		ryanScoreArr[index] = 0
		dfs(cnt, index + 1, ryanScoreArr, ryanScore)
	}

	dfs(0, 0, result, 0) // 뽑은 개수, 현재 보고 있는 인덱스,

	console.log("maxScoreDiffArr", maxScoreDiffArr)

	if (maxScoreDiff === 0) return [-1]

	return maxScoreDiffArr
}

let n = 5
let info = [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0]
solution(n, info)
