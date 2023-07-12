// 1. 이모티콘 플러스 서비스 가입자 수 최대
// 2. 이모티콘 매출액 최대

// => 시간초과
// 700 x 2 ^ 14 = 11468800 (시간초과 안나야 되는데)
// 미리 정렬해서, 구독자가 최대인 케이스부터 검사할 수 있도록하기...?

function solution(users, emoticons) {
	let maxUserNum = 0
	let maxPurchaseAmount = 0

	// 이모티콘 판매액과 이모티콘 플러스 서비스 가입자 수 반환
	const getEmoticonServiceJoin = (result) => {
		// [10, 10, 10, 20, 40, 10, 20]
		let emoticonPlusUserNum = 0 // 가입자 수
		let emoticonTotalSellAmount = 0 // 총 판매액
		users.forEach((user) => {
			// 1. 비율대로 깎았을 때, 가격 넘는지 계산
			const [userRatio, standardPrice] = user

			let curUserTotalPurchaseAmount = 0

			emoticons.map((emoticon, idx) => {
				if (result[idx] >= userRatio) {
					// 구매 40 => 0.4
					curUserTotalPurchaseAmount += emoticon * (1 - result[idx] * 0.01)
				}
			})

			if (curUserTotalPurchaseAmount >= standardPrice) {
				emoticonPlusUserNum++
			} else {
				emoticonTotalSellAmount += curUserTotalPurchaseAmount
			}
		})

		return [emoticonPlusUserNum, emoticonTotalSellAmount]
	}

	const getMaxUser = (result) => {
		if (result.length === users.length) {
			const [userNum, sellAmount] = getEmoticonServiceJoin(result)

			if (maxUserNum > userNum) return

			if (maxUserNum === userNum) {
				maxPurchaseAmount = Math.max(maxPurchaseAmount, sellAmount)
				return
			}
			if (maxUserNum < userNum) {
				maxUserNum = userNum
				maxPurchaseAmount = sellAmount
			}
			return
		}

		const ratios = [40, 30, 20, 10]

		ratios.forEach((ratio) => {
			getMaxUser([...result, ratio])
		})
	}

	getMaxUser([])

	return [maxUserNum, maxPurchaseAmount]
}

users = [
	[40, 10000],
	[25, 10000],
]

emoticons = [7000, 9000]

solution(users, emoticons)
