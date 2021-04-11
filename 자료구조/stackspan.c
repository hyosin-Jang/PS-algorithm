//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//#define SIZE 6
//
//void spans(int arr[], int S[]) {
//	int s;
//	for (int i = 0; i < SIZE; i++) {
//		s = 1;
//		while ((s <= i) && (arr[i - s]) <= arr[i])
//			s++;
//		S[i] = s;
//	}
//}
//
//int main() {
//
//	int arr[SIZE] = { 6,3,4,2,5,3 };
//	int S[SIZE] = { 0 };
//
//	spans(arr, S);
//
//	for (int i = 0; i < SIZE; i++)
//		printf("[%d] ", S[i]);
//	printf("\n");
//
//
//	return 0;
//}