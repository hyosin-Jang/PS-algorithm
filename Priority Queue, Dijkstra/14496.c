#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define min(x,y)((x) < (y) ? (x) : (y))
#define SIZE 1000
int a, b, N, M, r, c, cnt=0;
int arr[SIZE][SIZE] = {0};

int FindMinChangeNum(int a, int b) {
	// a에서 b로 가고 싶음
	int num=0;
	if (arr[a][b] == 1) // 경로가 존재한다는 것 
		return 1;

	else {
		for (int i = 1; i <= N; i++) 
			if (arr[a][i] == 1) {
				num += FindMinChangeNum(i, b);
				cnt = min(cnt, num);
			}
	}

	return 0;
}

int main() {
	scanf("%d %d",&a, &b);
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d",&r, &c);
		arr[r][c] = 1;
		getchar();
	}
	if (cnt <= M)
		printf("%d", cnt);
	else
		printf("-1");


	return 0;
}