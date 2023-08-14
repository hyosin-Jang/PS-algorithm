function solution(numbers) {
    var answer = Array(numbers.length)
    let stack = [0]

    for (let cur = 1; cur < numbers.length; cur++) {
        while (stack.length && numbers[cur] > numbers[stack.at(-1)]) {
            answer[stack.pop()] = numbers[cur]
        }
        stack.push(cur)
    }

    while (stack.length) {
        answer[stack.pop()] = -1
    }
    return answer
}

numbers = [9, 1, 5, 3, 6, 2]

solution(numbers)
