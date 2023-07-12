#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int k, n, s[100000], top=0, sum=0;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		// n이 0이 아니라면
		if (n != 0)
			s[top++] = n;
		else
			top--;
	}
	for (int i = 0; i < top; i++)
		sum += s[i];
	printf("%d", sum);

	return 0;
}