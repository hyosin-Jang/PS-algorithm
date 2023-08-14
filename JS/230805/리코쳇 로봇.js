function solution(board) {
    const [n, m] = [board.length, board[0].length]
    let visited = Array.from({length: n}, () => Array(m).fill(0))

    // 최단거리이므로 bfs 이용
    let queue = []

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (board[i][j] === "R") {
                queue.push([i, j, 0])
                visited[i][j] = 1
                break
            }
        }
    }

    let dir = [
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],
    ]

    let answer = Infinity

    // 오른쪽, 왼쪽, 아래, 위
    while (queue.length) {
        let [cx, cy, cnt] = queue.shift()

        for (let i = 0; i < 4; i++) {
            // 오른쪽
            let nx = cx + dir[i][0]
            let ny = cy + dir[i][1]

            let index = 1
            while (
                nx >= 0 &&
                nx < n &&
                ny >= 0 &&
                ny < m &&
                board[nx][ny] !== "D"
            ) {
                index++
                nx = cx + dir[i][0] * index
                ny = cy + dir[i][1] * index
            }

            // 최종 갱신
            nx = cx + dir[i][0] * (index - 1)
            ny = cy + dir[i][1] * (index - 1)

            if (board[nx][ny] === "G") answer = Math.min(answer, cnt + 1)

            if (!visited[nx][ny]) {
                visited[nx][ny] = 1
                queue.push([nx, ny, cnt + 1])
            }
        }
    }
    return answer !== Infinity ? answer : -1
}

let board = ["..R", "...", "...", "..D", "DG."]

console.log(solution(board))
