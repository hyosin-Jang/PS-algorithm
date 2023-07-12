//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 101
//
//int arr[SIZE][SIZE] = {0};
//int visited[SIZE][SIZE] = {0};
//
//typedef struct Coor {
//	int x; //x��ǥ
//	int y; //y��ǥ
//}Coor;
//
//
//Coor queue[10001];
//
//int front = 0, end = 0, max = 0;
//
//
//Coor deque() {
//	Coor temp = queue[front];
//	front = (front + 1) % 10000;
//	return temp;
//}
//
//void enque(int x, int y) {
//	queue[end].x = x;
//	queue[end].y = y;
//	end = (end + 1) % 10000;
//}
//
//void BFS() {
//	int x, y;
//
//	while (front!=end) {
//		// 1. dequeue�Ѵ�.
//		Coor c = deque();
//
//		// 2. deque�� ��ǥ���� �� �� �ְ�, �湮���� ���� ������ enque�Ѵ�.
//		x = c.x;
//		y = c.y;
//
//		// �湮�� ���� 1�� ǥ��
//
//		// ������, �湮���� �ʾҰ�, �� �� �ִ� ���̸� 
//		if (visited[x - 1][y] == 0 && arr[x - 1][y] != 0) {
//			enque(x - 1, y);
//			visited[x - 1][y] = visited[x][y] + 1;
//		}
//		// ������
//		if (visited[x][y + 1] == 0 && arr[x][y + 1] != 0) {
//			enque(x, y + 1);
//			visited[x][y + 1] = visited[x][y] + 1;
//		}
//		// �Ʒ�
//		if (visited[x + 1][y] == 0 && arr[x + 1][y] != 0) {
//			enque(x + 1, y);
//			visited[x +1][y] =  visited[x][y] + 1;
//		}
//		// ����
//		if (visited[x][y - 1] == 0 && arr[x][y - 1] != 0) {
//			enque(x, y - 1);
//			visited[x][y-1] = visited[x][y] + 1;
//		}
//	}
//}
//
//int main() {
//	int row = 0, col = 0;
//	scanf("%d %d", &row, &col);
//
//	// scanf�� ���� �ϳ��� 
//	for (int i = 1; i <= row;i++) {
//		for (int j = 1; j <= col; j++)
//			scanf("%1d", &arr[i][j]);
//	}
//
//	visited[1][1] = 1;
//	enque(1, 1);
//	//�ִܰŸ� => �ʺ� �켱Ž��
//	BFS();
//	printf("\n\n");
//
//	for (int i = 1; i <= row;i++) {
//		for (int j = 1; j <= col; j++)
//			printf("%3d", visited[i][j]);
//		printf("\n");
//	}
//	
//
//	printf("%d\n", visited[row][col]);
//
//	return 0;
//}