#include <iostream>
using namespace std;

#define MAX 100

int N;
int arr[MAX][MAX];
long long dp[MAX][MAX]; // 

// dp[i][j] = a 
// => i, j까지 오는데 a가지 경우의 수 있다는 뜻

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	dp[1][1] = 1;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (dp[i][j] == 0 || (i == N && j == N)) continue;

			// 오른쪽
			if (i + arr[i][j] <= N) 
				dp[i + arr[i][j]][j] = dp[i + arr[i][j]][j] + dp[i][j];
		
			// 아래쪽
			if (j + arr[i][j] <= N) 
				dp[i][j + arr[i][j]] = dp[i][j + arr[i][j]] + dp[i][j];

		}
	}

	cout << dp[N][N] << endl;
	return 0;
}
