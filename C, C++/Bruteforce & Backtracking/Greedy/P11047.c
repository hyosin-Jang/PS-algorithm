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

	//cnt 는 큰 것부터 몫 저장
	// M은 나머지 값으로 계속 갱신
	for (i = 0; i < N; i++) {
		cnt += M / arr[N - i - 1];
		M %= arr[N - i - 1];
	}
	printf("%d", cnt);
	//메모리 할당 해제
	free(arr);




}

int main(void) {

	min_coin();





}