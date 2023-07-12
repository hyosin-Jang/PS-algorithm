#include<iostream>

using namespace std;

int main() {
	int T, N, dp[41] = {0,1};
	cin >> T;

	for (int i = 2; i <= 40; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	while (T--) {
		cin >> N;
		if (N == 0)
			printf("1 0\n");
		else
			printf("%d %d\n", dp[N - 1], dp[N]);
	
	}
	return 0;
}