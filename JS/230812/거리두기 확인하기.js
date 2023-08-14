// 18분

function solution(places) {
    var answer = []

    function isRightPlace(place) {
        let people = []
        for (let i = 0; i < 5; i++) {
            for (let j = 0; j < 5; j++) {
                if (place[i][j] === "P") people.push([i, j])
            }
        }

        for (let cur = 0; cur < people.length; cur++) {
            let [curX, curY] = people[cur]
            for (let other = cur + 1; other < people.length; other++) {
                let [otherX, otherY] = people[other]
                let distance = Math.abs(curX - otherX) + Math.abs(curY - otherY)

                if (distance >= 3) continue
                if (distance === 2) {
                    // 사이 2개가 모두 X여야 함
                    // PX
                    // XP
                    if (curX !== otherX && curY !== otherY) {
                        if (
                            place[curX][otherY] !== "X" ||
                            place[otherX][curY] !== "X"
                        )
                            return 0
                    } else if (curX === otherX) {
                        // PXP
                        if (place[curX][Math.min(curY, otherY) + 1] !== "X")
                            return 0
                    } else {
                        // P
                        // X
                        // P
                        if (place[Math.min(curX, otherX) + 1][curY] !== "X")
                            return 0
                    }
                }

                if (distance === 1) return 0
            }
        }
        return 1
    }

    for (let place of places) answer.push(isRightPlace(place))

    return answer
}

const places = [
    ["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"],
    ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
    ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"],
    ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
    ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"],
]

console.log(solution(places))
