function solution(numbers) {
    let binary = numbers.map((number) => {
        let n = 1
        while (n <= number.toString(2).length) n *= 2
        return "0".repeat(n - 1 - len) + temp
    })

    function isBinaryTree(tree) {
        if (tree.length <= 1) return 1

        let rootIndex = Math.floor(tree.length / 2)

        if (tree[rootIndex] === "0") {
            // root가 0이라면
            let leftRoot = Math.floor(rootIndex / 2)
            let rightRoot = rootIndex + Math.floor(rootIndex / 2) + 1
            if (tree[leftRoot] !== "0" || tree[rightRoot] !== "0") {
                return 0
            }
        }

        return (
            isBinaryTree(tree.slice(0, rootIndex)) &&
            isBinaryTree(tree.slice(rootIndex + 1))
        )
    }

    let answer = binary.map((tree) => isBinaryTree(tree))

    return answer
}

const numbers = [1, 2, 63, 111, 95, 96]
solution(numbers)
