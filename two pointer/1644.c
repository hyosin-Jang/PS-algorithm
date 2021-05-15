#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,cnt=0, low=0, high=0, sum=0,result=0;
	long long prime[4000000];
	long long prime_num[4000000];

	scanf("%d", &n);

	// 1. n이하의 에라토스테네스의 체 이용한 소수 배열 만들기
	for (long long i = 0; i <= n; i++)               
		prime[i] = i;

	for (long long i= 2; i <= n; i++) {
		if (prime[i] == 0)
			continue; // 0이면 다음인덱스로 이동
		for (long long j = i; i * j <= n;j++) {
			prime[i * j] = 0;
			prime_num[cnt++] = i * j;
		}
	}

	//for (int i = 0; i < cnt; i++)
	//	printf("%d", prime_num[i]);

	for (int i = low; i < cnt; i++) {
		while (high < cnt && sum < n)
			sum += prime_num[high++];
		if (sum == n)
			result++;
		sum -= prime_num[low++];
	}
	printf("%d", result);




	return 0;
}