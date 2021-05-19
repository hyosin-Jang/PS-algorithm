#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int queue[10000];
	int n, front=0, end=0;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		queue[front++] = i;
	while (front != end) {
		printf("%d ",queue[end++]);
		queue[front++] = queue[end++];
	}


	return 0;
}