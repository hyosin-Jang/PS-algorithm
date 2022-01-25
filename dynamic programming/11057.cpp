#include <iostream>

using namespace std;

const int MAX = 1001;
const int mod = 10007;
long long dp[MAX][11] = {0, };
int N, ans;

int main() {
	cin >> N;

	// 첫 번째 줄에 1 넣기
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
		

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		ans += dp[N][i];

	cout << ans % mod << endl;

	return 0;
}
