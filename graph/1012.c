#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 51
int arr[SIZE][SIZE] = {0};
int visited[SIZE][SIZE] = {0};
int dRow[4] = { 1, -1,0,0 }; // 아래, 위, 오른쪽, 왼쪽
int dCol[4] = { 0,0,1,-1 };

 // 틀렸다고 나옴.. 왜??
typedef struct Coor {
	int x; //x좌표
	int y; //y좌표
}Coor;

Coor queue[2501];
int front = 0, end = 0;

Coor deque() {
	Coor temp = queue[front];
	front = front + 1;
	return temp;
}

void enque(int x, int y) {
	queue[end].x = x;
	queue[end].y = y;
	end = end + 1;
}

int BFScall(int row, int col) {
	int x, y;
	int cnt = 0;

	// 1. 이중 for문 BFS
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			// 방문하지 않았고, 갈 수 있는 곳
			if (visited[i][j] == 0 && arr[i][j]== 1) {
				visited[i][j] = 1;
				enque(i, j);
				cnt += BFS(i, j);
			}
		}
	}
	return cnt;
}

int BFS(int row, int col) {
	int x, y;

	while (front != end) {
		Coor c = deque();
		x = c.x;
		y = c.y;

		for (int i = 0; i < 4; i++) {
			int nextX = x + dRow[i];
			int nextY = y + dCol[i];

			// 방문X and 갈 수 있는 길이면 enque
			if (visited[nextX][nextY] == 0 && arr[nextX][nextY] != 0) {
				enque(nextX, nextY);
				visited[nextX][nextY] = 1;
			}
		}
	}
	return 1;
}


int main() {
	int t, row,col,k, x,y;
	scanf("%d",&t); // 테스트케이스

	while (t--) {
		scanf("%d %d %d", &col, &row, &k);

		for (int i = 0; i < k; i++) {
			scanf("%d %d", &y, &x);
			arr[x][y] = 1;
		}
		printf("%d\n", BFScall(row, col));
	}


	return 0;
}