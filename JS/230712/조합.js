const getCombination = (arr, selectNumber) => {
	let result = []
	if (selectNumber === 1) {
		return arr.map((el) => [el])
	}

	arr.forEach((fixed, index, origin) => {
		const rest = origin.slice(index + 1)
		const combination = getCombination(rest, selectNumber - 1)
		const attach = combination.map((el) => [fixed, ...el])
		console.log(combination)
		result.push(...attach)
	})

	return result
}

let result = getCombination([3, 4, 5, 6, 7], 3)

console.log(result)
