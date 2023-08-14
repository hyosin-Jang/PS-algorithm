function solution(n, m, x, y, r, c, k) {
    var answer = []

    // 아래, 왼쪽, 오른쪽, 위
    let dx = [1, 0, 0, -1]
    let dy = [0, -1, 1, 0]
    let dir = ["d", "l", "r", "u"]

    // impossible case
    // MP: 홀/짝이 안맞아서 도착 못하는 경우가 있고, 거리가 멀어서 도착 못하는 경우가 있음
    if (
        (Math.abs(x - r) + Math.abs(y - c)) % 2 !== k % 2 ||
        Math.abs(x - r) + Math.abs(y - c) > k
    ) {
        return "impossible"
    }

    function getFastRoute(str, k, x, y) {
        // 남은 횟수가 0이라면 현재 위치가 E인지 검사 후 answer에 푸쉬
        if (answer.length > 0) return

        // 남은 거리로 못 도착하면 가지치기
        let dist = Math.abs(x - r) + Math.abs(y - c)
        if (dist > k) return
        // 남은 횟수에서 (현재위치 - 목표지점까지 거리)를 뺐을 때 홀수번 남았다면 가지치기
        if (k % 2 !== dist % 2) return

        if (k === 0) {
            if (x === r && y === c) {
                //console.log("도착함", str)
                answer.push(str)
                return
            } else {
                //console.log("k 소진했지만 도착못함", str, "\n\n")
                return
            }
        }
        for (let i = 0; i < 4; i++) {
            let nx = x + dx[i]
            let ny = y + dy[i]
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                getFastRoute(str + dir[i], k - 1, nx, ny)
            }
        }
    }

    getFastRoute("", k, x, y)

    //console.log("answer", answer)

    return answer[0]
}

n = 3
m = 3
x = 1
y = 2
r = 3
c = 3
k = 4

console.log(solution(n, m, x, y, r, c, k))
