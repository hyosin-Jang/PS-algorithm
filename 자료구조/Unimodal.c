//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 10
//
//int findMaxOfUnimodalArray(int list[], int n) {
//	int a = 0, mid;
//	int b = n - 1;
//	while (a < b) {
//		mid = (a + b) / 2;
//		if (list[mid] < list[mid + 1])
//			a = mid + 1;
//		if (list[mid] > list[mid + 1])
//			b = mid;
//	}
//	return list[a];
//}
//
//int main() {
//	int list[SIZE] = { -21,8,12,13,35,41,23,20,17,10 };
//	int max_elem = findMaxOfUnimodalArray(list, SIZE);
//
//	printf("최댓 값은 %d입니다.",max_elem);
//
//}