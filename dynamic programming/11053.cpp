#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int arr[MAX];
int dp[MAX]; // 가장 긴 증가하는 부분 수열 길이 세는 배열
int N, cnt=0;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];


	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		cnt = max(dp[i], cnt);
		
	}

	cout << cnt << endl;

	return 0;
}
