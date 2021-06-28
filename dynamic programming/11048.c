#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(x,y) ((x)>(y) ? (x):(y))
#define SIZE 1000

int arr[SIZE][SIZE];
int candy[SIZE][SIZE];

void maxCandy(int n, int m) {
	int i, j;
	int cost;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cost = max(max(candy[i - 1][j], candy[i][j - 1]), candy[i - 1][j - 1]);
			candy[i][j] = cost + arr[i][j];
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
		getchar();
	}

	maxCandy(n, m);
	printf("%d", candy[n][m]);
}