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
//	for (i = first+gap; i <= last; i+=gap) { // i�� gap��ŭ ����
//		save = list[i];
//		for (j = i - gap; j >= first && list[j] > save; j-=gap) // j�� gap��ŭ �̵�
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
//			inc_insertion_sort(list, i, n - 1, gap); // i�� �����ε���
//	}
//
//}
//
//
//void main() {
//	int list[MAX_SIZE];
//	srand(time(NULL)); // �õ弳���ؼ� ������ �� �ȳ����� ��
//
//	for (int i = 0; i < MAX_SIZE; i++) {
//		list[i] = rand() % 100; //0~99���� ���� �߻�
//		for (int j = 0; j < i; j++)
//			if (list[j] == list[i])
//				i--; // �ߺ�����, �ٽ� ������ �ޱ�
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
//		Sleep(500); // 0.5�� ������
//	}
//	printf("\n\n");
//}