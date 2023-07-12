#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100 + 1;
queue <pair<pair<int, int>, int>> Q;
int visited[MAX][MAX] = {0, };
int maze[MAX][MAX] = {0, };
int N, M;
string s;

int x[4] = { -1, 1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };

// BFS 사용

void BFS() {
	int nowX, nowY, nextX, nextY, cnt;
	// 현재 위치 큐에 입력
	Q.push(make_pair(make_pair(0, 0), 1));

	// 방문했다고 표시
	visited[0][0] = 1;

	while (!Q.empty()) {
		
		
		// 하나 빼기 
		nowX = Q.front().first.first; // 1
		nowY = Q.front().first.second; // 1
		cnt = Q.front().second;
		Q.pop();

		// 정지 조건
		if (nowX == N-1 && nowY == M-1) {
			cout << cnt << "\n";
			return;
		}
		cnt++;

		for (int i = 0; i < 4; i++) {
			
			nextX = nowX + x[i]; // 다음 x 좌표
			nextY = nowY + y[i]; // 다음 y 좌표
			if (!visited[nextX][nextY] && maze[nextX][nextY]==1 && nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
	
				Q.push(make_pair(make_pair(nextX, nextY), cnt)); // 다음 위치 Q에 넣기
				visited[nextX][nextY] = 1;
			
			}
		}
	}

}
int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s; 
		for (int j = 0; j < M; j++)
			maze[i][j] = s[j]-'0';
	}

	
	BFS();


	return 0;
}
