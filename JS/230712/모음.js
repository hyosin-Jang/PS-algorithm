// 모음 사전: https://han-joon-hyeok.github.io/posts/programmers-vowel-dictionary/
function solution(word) {
	let result = []
	let str = ""
	for (let i = 1; i <= 5; i++) dfs(str, i, result)

	return result.sort().indexOf(word) + 1
}
// dfs("", 1, [])
// - dfs("A", 1, [])
// - dfs("E", 1, [])
// ...

// dfs("", 2, [])
// dfs("A", 2, [])
// dfs("AA", 2, [])
// dfs("AE", 2, [])
// ...

// dfs("", 5, [])
// dfs("A", 5, [])
// dfs("AA", 5, [])
// ...
// dfs("UUUUU", 5, [])
const dfs = (word, length, result) => {
	const vowels = [..."AEIOU"]
	if (word.length === length) {
		result.push(word)
		return
	}
	vowels.forEach((vowel) => dfs(word + vowel, length, result))
}
word = "AAAAE"

solution(word)
