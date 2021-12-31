#include <iostream>
#include<queue>

using namespace std;

const int MAX=250;
int R, C;
char field[MAX][MAX];
int visited[MAX][MAX];

void BFS(int a, int b) {

	int cur_sheep, cur_wolf;
	cur_sheep = cur_wolf = 0;
	queue<pair<int, int>> Q;
	
	Q.push(make_pair(a, b));
	visited[a][b] = 1; // 방문 표시

	if (field[a][b] == 'k') cur_sheep++;
	if (field[a][b] == 'v') cur_wolf++;

	// BFS 로직 짜기

}

int main() {

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) 
			cin >> field[i][j];
		

	for (int i = 0; i < R;i++) {
		for (int j = 0; j < C; j++) {
			if (field[i][j] == '#') continue;
			if (!visited[i][j])
				BFS(i, j);
		
		}
	
	}

	// 전체 양의 개수랑 전체 늑대 개수 출력하기


	return 0;
}
