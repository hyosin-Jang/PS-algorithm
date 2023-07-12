#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 301;
int l, cur_x, cur_y, goal_x, goal_y;
int visit[MAX][MAX];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

struct Knight{
	int x, y, cnt;
};
void bfs(int cur_x, int cur_y) {

	visit[cur_x][cur_y] = 1;
	queue <Knight> q;
	q.push({ cur_x, cur_y, 0 });

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
		q.pop();

		if (x == goal_x && y == goal_y) {
			cout << cnt << "\n";
			return; // cnt가 최솟값이니까 바로 끝내기
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx <= l - 1 && ny >= 0 && ny <= l - 1) {
				if (visit[nx][ny] != 1) {
					visit[nx][ny] = 1;
					q.push({ nx, ny, cnt + 1 });
				}
			}
		}
	}
}

int main() {

	int T;
	cin >> T;

	while (T--) {
		Knight knight;
		cin >> l;
		cin >> knight.x >> knight.y;
		cin >> goal_x >> goal_y;
		// 초기화
		memset(visit, 0, sizeof(visit));
		bfs(knight.x, knight.y);

	}
	return 0;
}
