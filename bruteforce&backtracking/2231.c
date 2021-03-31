#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	int n, sum=0,  num=0, generator=0;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		sum = 0;
		num = i;
		sum += num;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum == n) {
			generator = i;
			break;
		}
	}
	printf("%d", generator);

	return 0;
}