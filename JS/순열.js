// 11111 ~ 55555

const getCombinations = (arr, selectNubmer) => {
	let result = []
	if (selectNubmer === 1) {
		return arr.map((el) => [el])
	}

	arr.forEach((fixed, index, origin) => {
		// 조합이랑 다른 점이, 현재꺼 제외하고 앞에 나온거 제외하고 뽑는게 아니라,
		// 현재 fixed된 것 제외하고 앞에 나온 것에서도 뽑는거
		const rest = [...origin.slice(0, index), ...origin.slice(index + 1)]
		const combination = getCombinations(rest, selectNubmer - 1)
		const attached = combination.map((el) => [fixed, ...el])
		result.push(...attached)
	})

	return result
}

let result = getCombinations([3, 4, 5, 6, 7], 3)

console.log(result)
