#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000 + 1;

int graph[MAX][MAX] = {0, };
int N, M, cnt=0;
int nowX, nowY, nextX, nextY;

int x[4] = { -1, 1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };


typedef struct {
	int x;
	int y;
} tomato;

queue <tomato> Q;

void BFS() {
	while (!Q.empty()) {
		 
		nowX = Q.front().x; // 0
		nowY = Q.front().y; // 0
		Q.pop();

		// 해당 위치의 주변을 확인
		for (int i = 0; i < 4; i++) {
			nextX = nowX + x[i]; 
			nextY = nowY + y[i]; 

			if (graph[nextX][nextY]==0 && nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				graph[nextX][nextY] = graph[nowX][nowY] + 1;
				Q.push({nextX, nextY}); // 다음 위치 Q에 넣기
	
			}
		}
	}

}



int main() {

	cin >> M>> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
		cin >> graph[i][j];
		if (graph[i][j] == 1) {
			Q.push({i, j});
		}
	}

	
	BFS();


	// BFS를 수행하고도 0인 토마토가 있다면, 토마토가 모두 익지 못하는 상황임
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				cout <<"-1\n";
				return 0;
			}
			// cnt 갱신
			if (cnt < graph[i][j])
				cnt = graph[i][j];
		}
	

	cout << cnt-1 << endl;


	return 0;
}
