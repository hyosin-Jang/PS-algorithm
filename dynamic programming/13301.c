#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fib(int n) {
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else return fib(n - 1) + fib(n - 2);
}

int main() {

	int n, result;
	scanf("%d", &n);

	printf("%d",fib(n)*4 + 2*fib(n-1));
	return 0;
}
