#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[10001], dp[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0] = arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[2] + arr[1];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n] << endl;

	return 0;
}
