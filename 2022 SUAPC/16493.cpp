#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int days[21], pages[21];
int dp[21][201];

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> days[i] >> pages[i];
		

	// 챕터 수만큼 반복문 돌리기
	for (int i = 0; i < M + 1 ; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (i == 0 || j == 0) // 0행, 0열은 0으로 초기화
				dp[i][j] = 0;
			else if (days[i-1] <= j) {  // 무게 확보한 상태에서 넣었을 때랑 안넣었을 때 중 큰거 선택
				dp[i][j] = max(pages[i-1] + dp[i - 1][j - days[i - 1]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j]; // 못 넣는 경우
			}
	
		}
	}

	cout << dp[M][N] << endl;



	return 0;
}
