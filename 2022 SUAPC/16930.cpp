#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K;
char arr[1005][1005];
int sx, sy, ex, ey;
int visit[1005][1005];


struct Node {
	int x, y, cnt;
};

queue<Node> Q;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// cnt: 이동한 횟수
void BFS() {
	
	Q.push({ sx, sy, 0 });

	visit[sx][sy] = 0;

	while (!Q.empty()) {
		int x = Q.front().x, y = Q.front().y;
		int cnt = Q.front().cnt;
		Q.pop();

		if (x == ex && y == ey) {
			cout << cnt << endl;
			exit(0);
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= K; j++) {
				int nx = x + j * dx[i];
				int ny = y + j * dy[i];

				// cout << "nx: " << nx << " ny: " << ny << "\n";
				if (nx<1 || nx>N || ny<1 || ny>M || arr[nx][ny]== '#') break;
					if (visit[nx][ny] == 1e9) {
						// 처음 방문
						visit[nx][ny] = cnt + 1; // cnt+1 번만에 도착
						Q.push({ nx, ny, cnt + 1 });
						// cout << "nx: " << nx << " ny: " << ny << " cnt: " << cnt +1<< "\n";
					}
					// 이미 방문한 지점일 때 같은 가중치면 계속 가보기
					else if (visit[nx][ny] == cnt + 1) {
						continue;

					}
					else break;
				
				}	
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	// 빈칸은 0, 벽은 1
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			visit[i][j] = 1e9; // 초기화
		}
	}

	cin >> sx >> sy >> ex >> ey;

	BFS();

	cout << -1 << endl;

	return 0;
}
