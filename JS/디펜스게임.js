function solution(n, k, enemy) {
	var answer = 0

	if (n >= enemy.reduce((acc, cur) => acc + cur, 0) || enemy.length <= k) {
		console.log(enemy.length)
		return enemy.length
	}

	// 양궁 문제랑 비슷함 dfs로
	// 10000000개 이므로 2^100000씩 시도하면 시간초과 뜸.

	const defenseEnemy = (n, k, idx, enemy) => {
		// n: 남은 화살 수
		// k: 남은 무적권 개수
		// idx: 현재 보고 있는 인덱스
		console.log("n", n, "k", k, "idx", idx)

		if (idx == enemy.length) {
			// 끝까지 왔다면 무조건 종료시킴
			answer = idx
			return
		}

		if (n == 0 && k == 0) {
			// 둘 다 0
			answer = Math.max(answer, idx)
			return
		}
		if (n == 0) {
			// n만 0 일 때, k가 남은 경우
			// k라운드 더 소진 가능
			let round = idx + k
			if (round > enemy.length) {
				round = enemy.length
			}
			answer = Math.max(answer, round)
			return
		}
		if (k == 0 && n < enemy[idx]) {
			//k가 없는데 적 처지 못한다면
			answer = Math.max(answer, idx)
			return
		}

		// n은 반드시 0이 아니고!! k도 0이 아닐 수 있음
		// n=0일 때 k는 걸러짐
		// n = 38인데, k=0일 수 있음

		// 최소 k!=0 이거나, n >= enemy[idx]라는 뜻
		// dfs + 백트래킹
		if (n >= enemy[idx]) {
			// k는 0이 아니고, n은 0이 아닌 경우
			defenseEnemy(n - enemy[idx], k, idx + 1, enemy)
		}
		if (k > 0) {
			// n!= 0 && k >0
			defenseEnemy(n, k - 1, idx + 1, enemy)
		}
	}

	defenseEnemy(n, k, 0, enemy)
	console.log(answer)

	return answer
}

solution(20, 3, [3, 5, 8, 10, 14])
