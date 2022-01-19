#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int MAX = 8;
using namespace std;
int N, M;
int lab[MAX][MAX];
int lab_copy[MAX][MAX];
int max_safe_field = 0; // 최대 안전영역 개수
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector <pair<int, int>> v; // 바이러스 좌표 저장하는 벡터


// 바이러스 퍼뜨리고 안전영역 개수 반환하는 함수
int BFS() {
	// BFS가 수행될 때마다 안전영역을 새로 계산하므로 전역변수가 아닌 로컬변수로 생성
	queue <pair<int, int>> q;
	
	for (int i = 0; i < v.size(); i++)
		q.push(make_pair(v[i].first, v[i].second));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (lab_copy[nx][ny] == 0) { // 빈공간
				lab_copy[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int size = 0; // 각 BFS에서 0의 개수
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (lab_copy[i][j] == 0) size++;

	max_safe_field = max(max_safe_field, size);
	
	return max_safe_field;

}


// 벽 3개 세우는 함수
int wall(int cnt) {

	// 벽이 3개일 경우마다, 바이러스 퍼뜨리기
	if (cnt == 3) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				lab_copy[i][j] = lab[i][j];
		return BFS();
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			if (lab[i][j] == 0){
				lab[i][j] = 1;
				wall(cnt + 1);
				lab[i][j] = 0;
		}
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2)
				v.push_back(make_pair(i, j));
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1; // 0이면 벽 세워보기
				wall(1);
				lab[i][j] = 0;
			}
		}

	cout << max_safe_field << endl;
	return 0;
}
