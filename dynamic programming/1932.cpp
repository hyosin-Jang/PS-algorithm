#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 500 + 1;

int N;
int arr[MAX][MAX];
int answer[MAX][MAX];

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];
}

void Solution() {
	int ans = 0;

	answer[0][0] = arr[0][0];
	
	for (int i = 1; i < N; i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				answer[i][j] = answer[i - 1][j] + arr[i][j];
			else if (j == i)
				answer[i][j] = answer[i - 1][j - 1] + arr[i][j];
			else {
				answer[i][j] = max(answer[i - 1][j - 1], answer[i - 1][j]) + arr[i][j];
			}
		}

	for (int i = 0; i < N; i++)
		ans = max(answer[N - 1][i], ans);
	cout << ans << endl;
			
}

void Solve() {
	Input();
	Solution();
}

int main() {

	Solve();

	return 0;
}
