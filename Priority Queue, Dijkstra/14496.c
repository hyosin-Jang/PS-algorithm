#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define min(x,y)((x) < (y) ? (x) : (y))
#define SIZE 1000
int a, b, N, M, r, c, cnt=10001;
int arr[SIZE][SIZE] = {0};

int FindMinChangeNum(int a, int b) {
	// a에서 b로 가고 싶음
	int num=1;
	if (arr[a][b] == 1) // 경로가 존재한다는 것 
		return num;
	if (arr[b][a] == 1)
		return num;

	else {
		for (int i = 1; i <= N; i++) {
			if (arr[a][i] == 1) {
				num += FindMinChangeNum(i, b);
				cnt = min(cnt, num);
				printf("[%d행 %d열] 에서 cnt: %d\n", a, i, cnt);
			}
			if (arr[b][i] == 1) {
				num += FindMinChangeNum(i, a);
				cnt = min(cnt, num);
				printf("[%d행 %d열] 에서 cnt: %d\n", a, i, cnt);
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d %d", &a, &b); getchar();
	scanf("%d %d", &N, &M); getchar();
	for (int i = 0; i < M; i++) {
		scanf("%d %d",&r, &c);
		arr[r][c] = 1;
		arr[c][r] = 1;
		getchar();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

	FindMinChangeNum(a, b);
	printf("cnt: %d M: %d\n",cnt, M);
	if (cnt <= M)
		printf("%d", cnt);
	else
		printf("-1");


	return 0;
}
