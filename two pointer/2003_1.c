//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int n, m, result = 0;
//	int A[10000];
//	int low = 0, high = 0,sum=0;
//	scanf("%d %d", &n, &m);
//
//	for (int i = 0; i < n; i++)
//		scanf("%d", &A[i]);
//
//	// 마지막 인덱스 포함하기
//	// low 이상, high 미만
//	while (high <= n) {
//		// 부분합이 m보다 크거나 같다면, low 값 빼고 증가시키기
//		if (sum >= m)
//			sum -= A[low++];
//		// 부분합이 m보다 작다면, high 값 더하고, 증가시키기
//		else if (sum < m)
//			sum += A[high++];
//		if (sum == m)
//			result++;
//	}
//	printf("%d", result);
//
//	return 0;
//}