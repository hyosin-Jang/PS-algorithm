function solution(elements) {
	let twoElements = [...elements, ...elements]
	let sumSet = new Set()

	for (let i = 0; i < elements.length; i++) {
		let sliceLength = 1
		for (let j = 0; j < elements.length; j++) {
			let sum = twoElements.slice(j, sliceLength + i).reduce((acc, cur) => acc + cur, 0)
			// console.log("sum", sum)
			sumSet.add(sum)
			sliceLength++
		}
	}

	return sumSet.size
}

let elements = [7, 9, 1, 1, 4]

solution(elements)
