#include<iostream>
#include<cstring>
using namespace std;
bool check[51][51];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int a[51][51];

int m, n, k; // m 가로길이, n 세로길이, k 배추 개수
void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (a[nx][ny] == 1) {
				if (!check[nx][ny]) {
					dfs(nx, ny);
				}
			}
		}
		else continue;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y; // x 가로좌표 y 세로좌표
			a[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) {
					if (!check[i][j]) {
						cnt++;
						dfs(i, j);
					}
				}
			}
		}
		cout << cnt << '\n';
		memset(check, false, sizeof(check));
		memset(a, 0, sizeof(a));
	}
}