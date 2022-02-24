#include <iostream>
#include <vector>

using namespace std;
const int MAX = 21;


char arr[MAX][MAX];
int N, M;

vector<pair<int, int>> c;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int answer = 987654321;

void DFS(int x1, int y1, int x2, int y2, int cnt) {

	if (cnt == 10)
		return;

	for (int k = 0; k < 4; k++) {
		int nx1 = x1 + dx[k]; 
		int ny1 = y1 + dy[k];
		int nx2 = x2 + dx[k];  
		int ny2 = y2 + dy[k];


		if (nx1 >= 0 && nx1 < N && ny1 >= 0 && ny1 < M && nx2 >= 0 && nx2 < N && ny2 >= 0 && ny2 < M) {
			if (arr[nx1][ny1] == '#' && arr[nx2][ny2] == '#') // 둘 다 벽이라면
				continue;
			if (arr[nx1][ny1] == '#')
				nx1 = x1, ny1 = y1;
			else if (arr[nx2][ny2] == '#')
				nx2 = x2, ny2 = y2;
			DFS(nx1, ny1, nx2, ny2, cnt + 1);
		}
		// 둘 다 떨어지는 경우
		else if ((nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= M) && (nx2 < 0 || nx2 >= N) || (ny2 < 0 || ny2 >= M))
			continue;
		// 하나만 떨어지는 경우
		else {
			answer = min(answer, cnt + 1);
			return;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >>	M;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				c.push_back(make_pair(i, j));
			}
		}
	}

	// x1, y1, x2, y2, cnt
	DFS(c[0].first, c[0].second, c[1].first, c[1].second, 0);
	
	if (answer == 987654321)
		cout << -1 << endl;
	else
		cout << answer << endl;

	return 0;
}
