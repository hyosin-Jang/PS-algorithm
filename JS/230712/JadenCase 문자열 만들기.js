function solution(s) {
	s = s.split(" ").map((str) => {
		if (str === "") {
			return null
		}

		if (isNaN(str[0])) {
			if (str.length === 1) {
				return str[0].toUpperCase()
			} else {
				return str[0].toUpperCase() + str.substring(1).toLowerCase()
			}
		} else {
			return str.toLowerCase()
		}
	})

	return s.join(" ")
}

s = "for    t 3ast week     "

solution(s)
