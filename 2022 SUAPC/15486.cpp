#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1500005;
int N, answer;
int dp[MAX];
int price[MAX], t[MAX];
int main() {
	
	cin >> N;

	// 1-N 까지 저장
	for (int i = 1; i <=N; i++)
		cin >> t[i] >> price[i];
		
	int cur_max = 0;

	for (int i = 1; i <= N + 1; i++) {
		cur_max = max(cur_max, dp[i]); // i-1번째까지 금액 최댓값
		if (i + t[i] > N + 1) continue;
		dp[i + t[i]] = max(cur_max + price[i], dp[i + t[i]]);
		answer = cur_max;
	}
	
	cout << answer << endl;
	
	return 0;
}
