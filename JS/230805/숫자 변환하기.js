function solution(x, y, n) {
    if (x === y) return 0

    let queue = [[y, 0]]
    let answer = Infinity

    while (queue.length) {
        let [cur, cnt] = queue.shift()

        if (cur === x) {
            answer = cnt
            break
        }

        // x -> y로 가기보다, y-> x로 가면 나누기했을 때 경우의 수가 더 좁혀지므로 y->x로 좁혀가기
        if (cur % 2 === 0) {
            queue.push([cur / 2, cnt + 1])
        }
        if (cur % 3 === 0) {
            queue.push([cur / 3, cnt + 1])
        }
        if (cur - n >= x) {
            queue.push([cur - n, cnt + 1])
        }
    }
    return answer === Infinity ? -1 : answer
}

x = 4
y = 100
n = 4

console.log(solution(x, y, n))
