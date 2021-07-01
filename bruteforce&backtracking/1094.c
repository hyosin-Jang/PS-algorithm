#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int X, T, i=64, cnt=0;
	scanf("%d",&X);
	while (1) {
		if (X == 0)
			break;
		while (i > X)
			i /= 2;
		cnt += 1;
		X -= i;
	}
	printf("%d",cnt);
	return 0;
}