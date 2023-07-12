function solution(n, k, enemy) {
	let [left, right] = [0, enemy.length]
	let mid = Math.floor((left + right) / 2)

	while (left <= right) {
		const round = enemy.slice(0, mid).sort((a, b) => b - a) // 내림차순

		let fever = k
		const remain = round.reduce((acc, val) => {
			if (fever > 0) {
				fever--
				return acc
			} else return acc + val
		}, 0)

		console.log(round, fever, remain, mid)
		if (n - remain >= 0 && fever >= 0) left = mid + 1 // 더 라운드 진행시킬 수 있으므로 미드 증가
		else right = mid - 1
		mid = Math.floor((left + right) / 2)
	}

	console.log(left - 1)

	return left - 1
}

solution(20, 3, [3, 5, 8, 10, 14])
