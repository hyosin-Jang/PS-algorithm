// 이분탐색
// 최소로 건너는 친구들 인원: left
// 최대로 건널 수 있는 인원: right
// mid만큼 각 징검다리에서 빼줬을 때, 연속하는 0의 개수가 k보다 적다면,
// left = mid + 1
// k보다 많다면, right = mid - 1;
// front, back 역전되면 종료. front 반환.

function solution(stones, k) {
	let left = 0
	let right = 200000000

	function isValidBridge(mid) {
		let cnt = 0
		for (let i = 0; i < stones.length; i++) {
			if (stones[i] <= mid) {
				cnt++
			} else cnt = 0
			if (cnt >= k) return true
		}

		return false
	}

	while (left <= right) {
		let mid = Math.floor((left + right) / 2)
		if (isValidBridge(mid)) {
			// k개 보다 적으면 true
			right = mid - 1
		} else {
			left = mid + 1
		}
		//console.log("left", left, "right", right, "mid", mid)
	}
	//console.log("frot", left)
}

solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3)
