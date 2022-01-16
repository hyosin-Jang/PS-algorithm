#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100 + 1;
queue <pair<int, int>> Q;
int visited[MAX][MAX];
int maze[MAX][MAX];
int N, M;
string s;
int cnt = 0;

// 상하좌우 만들어야 함
int x[4] = { -1, 1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };

// BFS 사용

void BFS() {
	int popX, popY;
	// 현재 위치 큐에 입력
	Q.push(make_pair(1, 1));
	cnt++;

	while (!Q.empty()) {
		
		
		// 하나 빼기 
		popX = Q.front().first; // 1
		popY = Q.front().second; // 1
		if(popX == )
	
	
			// 정지 조건
	}



}
int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s; // s=110110
		for (int j = 0; j < M; j++)
			maze[i][j] = s[j]-'0';
	}

	
	BFS();


	return 0;
}
