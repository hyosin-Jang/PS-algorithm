//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h> 
//#define max(x,y) ((x)>(y) ? (x):(y))
//#define min(x,y) ((x)<(y) ? (x):(y))
//#define n1 5
//// ���������� ȣ�ں�, �װ��� ����
//int A[] = { 0,1,3,6,11,17 }; //�װ����
//int H[] = { 0,2,5,1,5,0 }; // ���ڿ��
//int m[10]; // k�� ���İ��� ��, �ּڰ�. 
// 
////�������α׷��� ������, �������� �����غ���
//// ������ �ᰡ�鼭 �����ϱ�!! ���� �����Ϸ���. 
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
//	return m[n - 1]; // ���������� ���µ� �ּڰ�
//}
//
////������ġ�� ������, �������� ���� �����غ���
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
//////������ġ�� ������
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