function solution(record) {
	var answer = []

	let map = new Map()

	record.forEach((chat) => {
		const [command, userId, nickname] = chat.split(" ")
		if (command === "Leave") return // 다음 걸로 넘어가기
		//if (command === "Enter") map.set(userId, nickname)
		//else map.set(userId, nickname)
		map.set(userId, nickname)
	})

	// map에 최신 닉네임이 기록되어 있음
	let str = ""
	record.forEach((chat) => {
		const [command, userId, _] = chat.split(" ")

		if (command === "Enter") {
			//console.log(`${map.get(userId)}님이 들어왔습니다.`)
			str = `${map.get(userId)}님이 들어왔습니다.`
			answer.push(str)
		} else if (command === "Leave") {
			//console.log(`${map.get(userId)}님이 나갔습니다.`)
			str = `${map.get(userId)}님이 나갔습니다.`
			answer.push(str)
		}
	})

	//console.log("final", answer)

	return answer
}

const record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]

solution(record)
