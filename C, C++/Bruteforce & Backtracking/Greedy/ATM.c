#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 돈을 인출하는데 걸리는 시간이 짧은 사람부터 정렬을 한 다음에 총 소요시간을
// 더해주면 최소 경과시간이 됨

//bubble sort 오름차순 정렬
void bubble_sort(int* N, int len) {
	int i, j;
	int temp;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - (i + 1); j++)
		{
			if (N[j] > N[j + 1]) {
				temp = N[j];
				N[j] = N[j + 1];
				N[j + 1] = temp;
			}
		}
	}
}


int main(void) {

	int N=0;
	int person[1001];
	int i;
	int sum = 0;
	int sum2 = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &person[i]);
	bubble_sort(person, N);
	for (i = 0; i < N; i++) {
		sum += person[i];
		sum2 += sum;
	}


	printf("%d", sum2);
	return 0;





}