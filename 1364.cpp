#include <iostream>
using namespace std;
int dp[1000001] = { 0 };

int main() {
	int n, j=0;
	cin >> n;
	//0 으로 초기화
	
	for (int i = 0; i <= 5; i++)
		dp[i] = i;

	for (int i = 6; i <= n; i++) {
		dp[i] = i + dp[(i/6-1)*6] + dp[i%6];
		if (i % 6 == 0)
			dp[i] += 1;
	}
	cout << dp[n];


	return 0;
}