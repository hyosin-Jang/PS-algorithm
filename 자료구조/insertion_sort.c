//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <time.h>
//#include <Windows.h>
//#define MAX_SIZE 15
//
//void insertion_sort(int list[], int n){
//	int i, j, save;
//
//	for (i = 1; i < n ; i++) {
//		save = list[i];
//		for (j = i - 1; j >= 0 && list[j]>save ; j--) 
//			list[j + 1] = list[j];
//		list[j + 1] = save;
//		
//	}
//}
//
//void inc_insertion_sort(int list[], int first, int last, int gap) {
//	int i, j, save;
//
//	for (i = first+gap; i <= last; i+=gap) { // i는 gap만큼 증가
//		save = list[i];
//		for (j = i - gap; j >= first && list[j] > save; j-=gap) // j는 gap만큼 이동
//			list[j + gap] = list[j];
//		list[j + gap] = save;
//
//	}
//}
//void shell_sort(int list[], int n) {
//	int i, gap;
//	for (gap = n / 2; gap > 0; gap =gap/ 2) {
//		if (gap % 2 == 0)
//			gap++;
//		for (i = 0; i < gap; i++)
//			inc_insertion_sort(list, i, n - 1, gap); // i는 시작인덱스
//	}
//
//}
//
//
//void main() {
//	int list[MAX_SIZE];
//	srand(time(NULL)); // 시드설정해서 고정된 값 안나오게 함
//
//	for (int i = 0; i < MAX_SIZE; i++) {
//		list[i] = rand() % 100; //0~99까지 난수 발생
//		for (int j = 0; j < i; j++)
//			if (list[j] == list[i])
//				i--; // 중복제거, 다시 난수값 받기
//	}
//
//	for (int i = 0; i < MAX_SIZE; i++)
//		printf("%d ", list[i]);
//	printf("\n\n"); 
//
//	shell_sort(list, MAX_SIZE);
//
//	for (int i = 0; i < MAX_SIZE; i++) {
//		printf("%d ", list[i]);
//		Sleep(500); // 0.5초 딜레이
//	}
//	printf("\n\n");
//}