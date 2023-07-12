function solution(relation) {
	let answer = 0
	let col = relation[0].length

	let result = new Array(col).fill(0).map((_, i) => i)
	console.log(result)

	let combination = [] // 가능한 모든 후보키들의 조합 우선 넣기
	for (let i = 0; i < col; i++) {
		combination.push(...getCombination(result, i + 1))
	}

	console.log(combination)

	combination = checkUniqueness(relation, combination) // 유일성 체크해서 갱신
	combination = checkMinimality(combination) // 최소성 체크해서 갱신
	return combination.length
}

const checkMinimality = (combination) => {
	let results = []

	while (combination.length) {
		results.push(combination[0])
		combination = combination.reduce((acc, cur) => {
			// 하나라도 cur에 col이 포함되어 있다면 false
			let notMinimal = combination[0].every((col) => cur.includes(col))
			if (!notMinimal) acc.push(cur)
			return acc
		}, [])
	}

	return results
}

const checkUniqueness = (relation, combination) => {
	let results = [] // 유일성 만족하는 것만 리턴
	combination.forEach((combi) => {
		let set = new Set()
		relation.forEach((rel) => {
			set.add(combi.map((col) => rel[col]).join(","))
		})
		if (set.size == relation.length) results.push(combi)
	})
	return results
}

function getCombination(arr, selectNum) {
	let result = []
	if (selectNum === 1) {
		return arr.map((a) => [a])
	}
	arr.forEach((fix, i, origin) => {
		const rest = origin.slice(i + 1)
		const combi = getCombination(rest, selectNum - 1)
		const attach = combi.map((c) => [fix, ...c])
		result.push(...attach)
	})
	return result
}

let relation = [
	["100", "ryan", "music", "2"],
	["200", "apeach", "math", "2"],
	["300", "tube", "computer", "3"],
	["400", "con", "computer", "4"],
	["500", "muzi", "music", "3"],
	["600", "apeach", "music", "2"],
]

solution(relation)
