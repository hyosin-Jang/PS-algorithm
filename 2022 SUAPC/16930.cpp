#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K;
int arr[1005][1005];
int x1, y1, x2, y2;
int visit[1005][1005];
struct Node {
	int x;
	int y;
	int cnt;
};


queue<Node> Q;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// cnt: 이동한 횟수
void BFS() {
	
	Q.push({ x1, y1, 0 });

	while (!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		int cnt = Q.front().cnt;
		Q.pop();

		if (x == x2 && y == y2) {
			cout << cnt << endl;
			return;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= K; j++) {
				int nx = x + j * dx[i];
				int ny = y + j * dy[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny]==0) {
					if (visit[nx][ny] == 1e9) {
						// 처음 방문
						visit[nx][ny] = cnt + 1; // cnt+1 번만에 도착
						Q.push({ nx, ny, cnt + 1 });

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
}

int main() {
	cin >> N >> M >> K;
	// 가로, 세로, 최대 개수

	int tmp;
	// 빈칸은 0, 벽은 1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			if (tmp == '.')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
			visit[i][j] = 1e9; // 초기화
		}
	}

	cin >> x1 >> y1 >> x2 >> y2;

	BFS();

	cout << -1 << endl;

	return 0;
}
