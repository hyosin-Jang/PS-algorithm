function solution(data, col, row_begin, row_end) {
    var answer = 0

    data.sort((a, b) => {
        if (a[col - 1] === b[col - 1]) return b[0] - a[0]
        else return a[col - 1] - b[col - 1]
    })
    let arr_s_i = data.map((tuple, i) =>
        tuple.reduce((acc, val) => acc + (val % (i + 1)), 0)
    )

    arr_s_i = arr_s_i.slice(row_begin - 1, row_end)
    answer = arr_s_i.reduce((acc, val) => acc ^ val)
    return answer
}

data = [
    [2, 2, 6],
    [1, 5, 10],
    [4, 2, 9],
    [3, 8, 3],
]
col = 2
row_begin = 2
row_end = 3

solution(data, col, row_begin, row_end)
