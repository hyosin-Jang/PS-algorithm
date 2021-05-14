#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	int A[10000];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d ",&A[i]);

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);



	return 0;
}