#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 30

double fac(double n) {
	double e = 1;
	for (int i = 1; i <= n; i++)
		e *= i;
	return e;
}

int main() {

	int n[SIZE], m[SIZE], t=0, d[SIZE];
	int num;

	scanf("%d",&t);

	for (int i = 0; i < t; i++)
		scanf("%d %d",&n[i],&m[i]);

	for (int i = 0; i < t; i++) {
		int a = 1;
		a = fac(m[i]) / (fac(n[i]) * fac(m[i] - n[i]));
		printf("%d\n",a);
	}


	return 0;
}