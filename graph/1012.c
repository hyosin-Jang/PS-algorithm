#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 51
int arr[SIZE][SIZE] = {0};
int visited[SIZE][SIZE] = {0};
int dRow[4] = { 1, -1,0,0 }; // �Ʒ�, ��, ������, ����
int dCol[4] = { 0,0,1,-1 };

 // Ʋ�ȴٰ� ����.. ��??
typedef struct Coor {
	int x; //x��ǥ
	int y; //y��ǥ
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

	// 1. ���� for�� BFS
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			// �湮���� �ʾҰ�, �� �� �ִ� ��
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

			// �湮X and �� �� �ִ� ���̸� enque
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
	scanf("%d",&t); // �׽�Ʈ���̽�

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