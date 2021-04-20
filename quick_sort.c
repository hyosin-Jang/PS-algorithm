#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int partition(int list[], int left, int right) {

	int pivot, temp, low, high;
	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do
			low++;
		while (list[low] < pivot); // pivot보다 작으면 움직임

		do
			high--;
		while (list[high] > pivot);

		for (int i = 0; i < MAX_SIZE; i++)
			printf("[%d] ", list[i]);
		printf("\nlow = %d, high = %d\n", low, high); 
		Sleep(500);

		if (low < high)
			SWAP(list[low], list[high], temp);
	} while (low < high);
	// 한번의 파티션이 끝남. 이때, pivot과 high가 가리키는 값을 swap
	SWAP(list[left], list[high], temp); // pivot과 가장 작은 high를 리턴
	return high;
}


void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right); //분할하는 함수
		quick_sort(list, left, q - 1); // 왼쪽 서브
		quick_sort(list, q + 1, right);
	}
}

void main() {
	int list[MAX_SIZE];
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;

	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ",list[i]);
	printf("\n\n");
	getch(); 
	
	quick_sort(list, 0, MAX_SIZE - 1); //배열, 왼쪽 인덱스, 오른쪽 인덱스

	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n");

}