#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void min_coin() {
	int i;
	int N;
	int M;
	int* arr;
	int cnt = 0;
	scanf("%d %d", &N, &M);
	arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	//cnt �� ū �ͺ��� �� ����
	// M�� ������ ������ ��� ����
	for (i = 0; i < N; i++) {
		cnt += M / arr[N - i - 1];
		M %= arr[N - i - 1];
	}
	printf("%d", cnt);
	//�޸� �Ҵ� ����
	free(arr);




}

int main(void) {

	min_coin();





}