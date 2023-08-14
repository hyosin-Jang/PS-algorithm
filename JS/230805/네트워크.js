function solution(n, computers) {
    let parent = Array(n)
        .fill(0)
        .map((el, idx) => idx)

    function findParent(node) {
        if (parent[node] === node) return node
        return findParent(parent[node])
    }

    function union(nodeA, nodeB) {
        let parentA = findParent(nodeA) // 1
        let parentB = findParent(nodeB) // 0
        // 작은 쪽으로 합치기
        if (parentA > parentB) parent[parentA] = parentB
        else parent[parentB] = parentA
    }

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            // 1. 연결이 양방향이 아님
            if (i !== j && computers[i][j] === 1) {
                union(i, j)
                union(j, i)
            }
        }
    }

    let parentParent = []

    // 마지막에 i가 아니라 i의 부모를 기준으로 세어야 문제가 되지 않는다.
    for (let i = 0; i < parent.length; i++) {
        parentParent[i] = findParent(parent[i])
    }

    let set = new Set(parentParent)
    return set.size
}

n = 7
computers = [
    [1, 0, 0, 0, 0, 0, 1],
    [0, 1, 1, 0, 1, 0, 0],
    [0, 1, 1, 1, 0, 0, 0],
    [0, 0, 1, 1, 0, 0, 0],
    [0, 1, 0, 0, 1, 1, 0],
    [0, 0, 0, 0, 1, 1, 1],
    [1, 0, 0, 0, 0, 1, 1],
]
console.log(solution(n, computers))
