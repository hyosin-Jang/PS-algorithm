//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h> 
//#define max(x,y) ((x)>(y) ? (x):(y))
//#define min(x,y) ((x)<(y) ? (x):(y))
//#define n1 5
//// 전역변수로 호텔비, 항공비 선언
//int A[] = { 0,1,3,6,11,17 }; //항공요금
//int H[] = { 0,2,5,1,5,0 }; // 숙박요금
//int m[10]; // k를 거쳐갔을 때, 최솟값. 
// 
////동적프로그래밍 정방향, 역방향은 직접해보기
//// 손으로 써가면서 공부하기!! 내가 컴파일러다. 
//int airtel(int n) {
//	m[0] = 0;
//	int cost;
//	for (int d = 1; d < n; d++) {
//		m[d] = 10000;
//		for (int k = 0; k < d; k++) {
//			// airtel[k]+H[k]+A[d-k]
//			cost = m[k] + H[k] + A[d - k];
//			m[d] = min(m[d], cost);	
//		}
//	}
//	return m[n - 1]; // 마지막까지 가는데 최솟값
//}
//
////분할통치법 정방향, 역방향은 직접 구현해보기
//int rAirtelForward(int d) {
//	if (d == 0)
//		return 0;
//	int minCost = 10000;
//	int cost;
//
//	for (int k = 0; k < d - 1; k++) {
//		cost = rAirtelForward(k) + H[k] + A[d - k];
//		minCost = min(minCost, cost);
//	}
//	return minCost;
//}
//
//////분할통치법 역방향
////int rAirtelBackward(int d) {
////	if (d == n1-1)
////		return 0;
////	int minCost = 10000;
////	int cost;
////
////	for (int k = d+1 ; k < n1 ; k--) {
////		cost = rAirtelBackward(k) + H[k] + A[k-d];
////		minCost = min(minCost, cost);
////	}
////	return minCost;
////}
//int main() {
//	printf("%d\n", rAirtelForward(0));
//	return 0;
//}