#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fib(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fib(n - 1) + fib(n - 2);
}

int main() {

	int n, num=0;
	scanf("%d",&n);

	num = fib(n);
	printf("%d",num);

	return 0;
}
