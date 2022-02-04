#include <iostream>
using namespace std;
const int MAX = 501;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int n, m, map[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0;
int max(int a, int b) {
	return a > b ? a : b;
}


void solve(int x, int y, int sum, int cnt) {
	if (cnt == 4) { // 테트로미노 완성(4개 탐색 완료) ->종료
		ans = max(ans, sum);
		return;
	}

	// 범위 넘어가는 경우 종료
	if (y < 0 || x < 0 || y >= n || x >= m)
		return;

	// 이미 방문한 경우 종료
	if (visited[y][x]) return;

	// 탐색 시작
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		solve(y + dy[i], x + dx[i], sum + map[y][x], cnt + 1);
	}

	// 방문한 경우의 수에 대해서 탐색해야하므로
	// 백트래킹
	visited[y][x] = false;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			// 4가지 테트로미노 검사
			solve(i, j, 0, 0);
		
			// ㅜ 모양 검사
			if (j + 2 < m) {
				int tmp = map[i][j] + map[i][j + 1] + map[i][j + 2];
				if (i - 1 >= 0) // ㅗ 검사
					ans = max(ans, tmp + map[i - 1][j + 1]);
				if (i + 1 < n) // ㅜ 검사
					ans = max(ans, tmp + map[i + 1][j + 1]);
			}
			// ㅓ, ㅏ 검사
			if (i + 2 < n) {
				int tmp = map[i][j] + map[i + 1][j] + map[i + 2][j];
				if(j-1 >=0)
					ans = max(ans, tmp + map[i+1][j - 1]);
				if (j + 1 < m) // ㅜ 검사
					ans = max(ans, tmp + map[i + 1][j + 1]);	
			}
		}

	}
	cout << ans << endl;

	return 0;
}
