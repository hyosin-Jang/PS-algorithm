//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <time.h>
//#include <Windows.h>
//
//#define MAX_SIZE 15
//
//// 매크로함수
//#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
//
//void selection_sort(int list[], int n) {
//	int least, temp;
//	for (int i = 0; i < n - 1; i++) {
//		least = i;
//		for (int j = i + 1; j < n; j++)
//			if (list[j] < list[least])
//				least = j;
//		SWAP(list[i], list[least], temp);
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
//		printf("%d ",list[i]);
//	printf("\n\n"); getch();
//
//	selection_sort(list, MAX_SIZE);
//
//	for (int i = 0; i < MAX_SIZE; i++) {
//		printf("%d ",list[i]);
//		Sleep(500); // 0.5초 딜레이
//	}
//	printf("\n\n");
//}
