#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 101

int arr[SIZE][SIZE];
int visit[SIZE][SIZE];

typedef struct node {
	int x;
	int y;
}Node;

// queue라는 이름의 node 배열
Node queue[10001];

int front = 0, end = 0, max = 0;
int vectX[4] = { 0,0,1,-1 };
int vectY[4] = { 1,-1,0,0 };

Node deque() {
	Node temp = queue[front];
	front = (front + 1) % 10000;
	return temp;
}

int main() {
	int row = 0, col = 0;
	scanf("%d %d", &row, &col);

	// scanf는 문자 하나만 
	for (int i = 1; i <= row;i++) {
		for (int j = 1; j <= col; j++)
			scanf("%1d", &arr[i][j]);
	}

	visit[1][1] = 1;
	enque(1, 1);
	//너비 우선탐색
	BFS();
	printf("%d\n", visit[row][col]);

	return 0;
}
