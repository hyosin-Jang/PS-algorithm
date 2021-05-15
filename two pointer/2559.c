//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int n, k, low, high,max, cmp;
//	int A[100000];
//	low = high = max = cmp = 0;
//	scanf("%d %d",&n,&k);
//
//	for (int i = 0; i < n; i++)
//		scanf("%d",&A[i]);
//
//	for(int i =0 ; i< k ; i++)
//		max+= A[high++];
//	cmp = max;
//	printf("max: %d\n", max);
//
//	// high == n-1 까지
//	// low 이상, high 미만
//	while (high <n) {
//		cmp += A[high++];
//		cmp -= A[low++];
//
//		//max 갱신
//		if (cmp > max)
//			max = cmp;
//	}
//	printf("%d",max);
//
//
//	return 0;
//}