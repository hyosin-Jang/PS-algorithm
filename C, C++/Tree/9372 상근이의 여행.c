#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 비행 스케줄이 연결그래프고, 
// 모든 국가들을 여행해야 하니까
// 최소 간선의 개수 = (정점 -1) 개
int main() {
	int t, n ,m, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d %d", &a, &b);
		printf("%d\n", n-1);
	}
}