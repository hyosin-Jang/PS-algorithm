class PriorityQueue {
	constructor() {
		this.elements = []
	}

	enqueue(element) {
		let added = false
		for (let i = 0; i < this.elements.length; i++) {
			if (element < this.elements[i]) {
				this.elements.splice(i, 0, element)
				added = true
				break
			}
		}
		if (!added) this.elements.push(element)
	}

	dequeue() {
		let maxVal = this.elements[this.elements.length - 1]
		this.elements.pop() // 제일 뒤에서 빼기
		return maxVal
	}
	isEmpty() {
		return this.elements.length === 0
	}
}

function solution(n, works) {
	var answer = 0

	let pq = new PriorityQueue()
	while (works.length) {
		pq.enqueue(works.shift())
	}

	while (n > 0) {
		let maxFatigue = pq.dequeue()
		maxFatigue-- // 3
		if (maxFatigue > 0) pq.enqueue(maxFatigue)
		n--
	}
	pq.elements.map((work) => (answer += work * work))

	return answer
}

let works = [4, 3, 3]
let n = 4

solution(n, works)

// 다른 풀이
const noOvertime = (no, works) => {
	while (no > 0) {
		works.sort((a, b) => b - a)
		works[0] -= 1
		no--
	}
	return works.map((a) => a * a).reduce((a, b) => a + b)
}
