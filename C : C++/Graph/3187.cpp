#include <iostream>
#include<queue>

using namespace std;

const int MAX=250;
int R, C, total_sheep=0, total_wolf=0;
char field[MAX][MAX];
int visited[MAX][MAX];

// 아래, 위, 오른쪽, 왼쪽
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void BFS(int a, int b) {

	int cur_sheep=0, cur_wolf=0;
	queue<pair<int, int>> Q;
	
	Q.push(make_pair(a, b));
	visited[a][b] = 1; // 방문 표시

	if (field[a][b] == 'k') cur_sheep++;
	if (field[a][b] == 'v') cur_wolf++;

	while (!Q.empty()) {
		// 하나 pop하기
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		// 동서남북중에 갈 수 있는 곳 Q에 넣기
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			// 다음 칸이 들판 밖인지 검사
			if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C)
				continue;

			// 다음 칸이 울타리인지 검사
			if (field[nextX][nextY] == '#' || visited[nextX][nextY])
				continue;

			if (field[nextX][nextY] == '.') {
				visited[nextX][nextY] = 1;
				Q.push(make_pair(nextX, nextY));
			}

			else if (field[nextX][nextY] == 'v') {
				visited[nextX][nextY] = 1;
				cur_wolf++;
				Q.push(make_pair(nextX, nextY));
			}
			else if (field[nextX][nextY] == 'k') {
				visited[nextX][nextY] = 1;
				cur_sheep++;
				Q.push(make_pair(nextX, nextY));
			}

		}
	}
	
	if (cur_sheep > cur_wolf)
		total_sheep += cur_sheep;
	else
		total_wolf += cur_wolf;
}

int main() {
	
	// 1. field 입력받기
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) 
			cin >> field[i][j];
		
	// 2. 각 칸에 대해 BFS 수행하기
	for (int i = 0; i < R;i++) {
		for (int j = 0; j < C; j++) {
			if (field[i][j] == '#') continue;
			if (!visited[i][j])
				BFS(i, j);
		}
	}

	// 전체 양의 개수랑 전체 늑대 개수 출력하기
	cout << total_sheep << " " << total_wolf << endl;



	return 0;
}
