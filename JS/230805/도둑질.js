function solution(money) {
    // console.log("money", money)

    // case1: 마지막하나 제거 (처음 원소 선택한 경우)
    let money1 = [...money]
    let money2 = [...money]
    money1.pop()
    money1.unshift(0)

    // case2: 처음원소 제거 (마지막 선택한 경우)
    money2.splice(0, 1, 0)

    let dp1 = Array.from({length: money1.length}).fill(0)
    let dp2 = Array.from({length: money1.length}).fill(0)
    // money1
    dp1[1] = money1[1]

    for (let i = 2; i < money1.length; i++) {
        dp1[i] =
            dp1[i - 2] + money1[i] > dp1[i - 1]
                ? dp1[i - 2] + money1[i]
                : dp1[i - 1]
    }
    // money2
    dp2[1] = money2[1]

    for (let i = 2; i < money2.length; i++)
        dp2[i] =
            dp2[i - 2] + money2[i] > dp2[i - 1]
                ? dp2[i - 2] + money2[i]
                : dp2[i - 1]

    return Math.max(dp1[dp1.length - 1], dp2[dp2.length - 1])
}

money = [1, 2, 3, 1]

console.log(solution(money))
