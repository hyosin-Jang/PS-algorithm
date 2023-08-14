function solution(scores) {
    // 첫번째 기준 내림차순 정렬
    const wanho = scores[0]

    // MP: 정렬할 때, 0번째 기준 내림차순 + 같은 점수일 경우, 1번째 컬럼이 작은 값이 우선순위
    scores.sort((a, b) => {
        if (b[0] === a[0]) return a[1] - b[1]
        else return b[0] - a[0]
    })

    let maxScore = scores[0][1]
    for (let i = 1; i < scores.length; i++) {
        // 첫번째 컬럼 값이 다른데 (더 작은 값인데) 두번째 컬럼도 앞에 나온 값보다 값이 작은 경우가 있다면
        if (scores[i][0] !== scores[i - 1][0] && scores[i][1] < maxScore) {
            if (scores[i] === wanho) return -1
            scores.splice(i--, 1)
        }
        maxScore = Math.max(maxScore, scores[i][1])
    }

    // 석차 계산
    const wanhoSum = wanho[0] + wanho[1]

    // 점수 합 큰 순서대로 정렬
    scores.sort((a, b) => b[0] + b[1] - (a[0] + a[1]))

    for (let i = 0; i < scores.length; i++) {
        if (scores[i][0] + scores[i][1] === wanhoSum) {
            let sameCount = 0
            while (
                i < scores.length &&
                scores[i][0] + scores[i][1] === wanhoSum
            ) {
                i++
                sameCount++
            }
            // 여기서 i는 가장 마지막 idx + 1 까지 왔음
            return i - (sameCount - 1)
        }
    }
    return 0
}

const scores = [
    [2, 2],
    [2, 2],
    [2, 3],
    [3, 2],
]
console.log(solution(scores))
