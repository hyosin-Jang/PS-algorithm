function solution(maps) {
    var answer = 0

    let start, end, lever

    let [n, m] = [maps.length, maps[0].length]

    let [startToLever, leverToEnd] = [0, 0]

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (maps[i][j] === "S") start = [i, j]
            else if (maps[i][j] === "E") end = [i, j]
            else if (maps[i][j] === "L") lever = [i, j]
        }
    }

    function bfs(start, goal) {
        // start에서 goal까지의 최단거리 리턴

        let visited = Array.from({length: n}, () => Array(m).fill(0))
        visited[start[0]][start[1]] = 1

        let queue = [[...start, 0]]

        let dx = [0, 0, 1, -1]
        let dy = [1, -1, 0, 0]

        //  console.log("queue", queue)

        let answer = Infinity

        while (queue.length) {
            // 선입선출이므로 shift
            let [cx, cy, cnt] = queue.shift()

            for (let i = 0; i < 4; i++) {
                let nx = cx + dx[i]
                let ny = cy + dy[i]

                // 도착하면 cnt + 1 리턴
                if (nx === goal[0] && ny === goal[1]) {
                    answer = Math.min(answer, cnt + 1)
                }
                if (
                    nx >= 0 &&
                    nx < n &&
                    ny >= 0 &&
                    ny < m &&
                    maps[nx][ny] !== "X" && // 통로면 지나가는게 아니라, 못 지나가는 경우를 제외해야 함
                    !visited[nx][ny]
                ) {
                    visited[nx][ny] = 1 // 방문 표시
                    queue.push([nx, ny, cnt + 1])
                }
            }
        }
        return answer === Infinity ? 0 : answer // 못 도착하면 0
    }

    startToLever = bfs(start, lever)
    if (!startToLever) return -1
    leverToEnd = bfs(lever, end)

    return !leverToEnd ? -1 : startToLever + leverToEnd
}

maps = ["LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"]

console.log(solution(maps))
