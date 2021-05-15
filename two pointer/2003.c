//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int n, m, result=0;
//	int A[10000];
//	int low = 0, high = 0;
//	scanf("%d %d",&n,&m);
//
//	for (int i = 0; i < n; i++)
//		scanf("%d", &A[i]);
//
// // low 이상, high 이하. sum을 구해놓고 시작
//	while (high < n) {
//		//sum 초기화
//		int sum = 0;
//		for (int i = low; i <= high; i++)
//			sum += A[i];
//		
//		if (sum == m)
//			result++;
//
//		if (sum <= m) 
//			high++;
//		else if (sum > m) 
//			low++;
//	3 8
// 10 7 6
//
//		if (low > high)
//			high++;
//	}
//	printf("%d",result);
//
//	return 0;
//}