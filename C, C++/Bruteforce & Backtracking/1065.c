#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d",&N);
	if (N < 100)
		printf("%d", N);
	else {
		int i, cnt=99, A, B, C;
		for (i = 100; i <= N; i++) {
			A = i / 100;
			B = i / 10 % 10;
			C =i % 10;
			if ((C - B) == (B - A))
				cnt++;
		
		}
		printf("%d", cnt);
	}

}