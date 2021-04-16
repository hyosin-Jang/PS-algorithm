#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fib(int n) {
	if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else return fib(n - 1) + fib(n - 2);
}

int main() {

	int n, a=1, result;
	scanf("%d",&n);

	if (n == 1)
		printf("0 1");
	else
		printf("%d %d",fib(n-1) , fib(n));

	return 0;
}
