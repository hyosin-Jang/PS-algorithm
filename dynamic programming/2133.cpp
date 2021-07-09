#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[31] = { 0 };

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 2] * 3; 
		// 오른쪽에 3*2가 고정되어 있다고 생각

		// 새로 추가된 도형 각각을 dp[i]에 더하기
		for (int j = 4; j <= i; j += 2)
			dp[i] += dp[i - j] * 2;
	}
	cout << dp[n];
	return 0;
}
 
