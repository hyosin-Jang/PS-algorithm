#include <iostream>

using namespace std;
const int MAX = 51;

// 벽 or 칸
// (r,c) 
// => r: 북쪽으로부터 떨어진 칸의 개수
// => c: 서쪽으로부터 떨어진 칸의 개수

// 반시계방향
// 0: 북, 1: 동, 2: 남, 3:서
int N, M; // 세로, 가로
int r, c, d, result=0;
int arr[MAX][MAX];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 현재 위치, 방향
void robot(int r, int c, int d) {
	// 1. 청소 표시 => 2로 하기
	if (arr[r][c] == 0) {
		arr[r][c] = 2;
		result++;
	}

	// 2. 네 방향 검사 (갈 곳 있는 경우)
	for (int i = 0; i < 4; i++) {
		// nd: 다음 방향, 반시계 방향으로 회전하기
		int nd = (d - i + 3) % 4;
		int nx = r + dx[nd];
		int ny = c + dy[nd];

		// 2.5 경계 검사
		if (nx < 0 || ny <0 || nx >= N || ny >M)
			continue;

		if (arr[nx][ny] == 0)
			robot(nx, ny, nd);

	}

	// 3. 후진하기 (갈 곳 없는 경우)
	int nd = (d + 2) % 4;
	int nx = r + dx[nd];
	int ny = c + dy[nd];

	if (arr[nx][ny] == 1) {
		cout << result;
		exit(0);
	}

	// 현재 방향으로 후진하기
	robot(nx, ny, d);

}

int main() {
	
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	robot(r, c, d);

	return 0;
}
