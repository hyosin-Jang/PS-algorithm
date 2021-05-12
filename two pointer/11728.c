#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int n, m;
long long A[1000000];
long long B[1000000];

int main() {

	int a=0, b=0;
	scanf("%d %d", &n, &m);

	// 한 줄에 어떻게 입력받을지가 문제!
	for (int i = 0; i < n; i++)
		scanf("%lld ", &A[i]);
	for (int i = 0; i < m; i++)
		scanf("%lld ", &B[i]);

	while (1) {
		// a나 b가 마지막 인덱스까지 갔으면 while문 빠져나오기
		if (a == n || b == m) break;
		if (A[a] == B[b]) {
			printf("%lld %lld ", A[a], B[b]);
			a++;
			b++;
		}
		else if (A[a] < B[b]) {
			printf("%lld ", A[a]);
			a++;
		}
		else {
			printf("%lld ", B[b]);
			b++;
		}
	}
	// a는 끝까지 안갔고, b는 끝까지 갔다
	while (a != n) {
		printf("%lld ", A[a]);
		a++;
	}
	while (b != m) {
		printf("%lld ", B[b]);
		b++;
	}

	return 0;
}