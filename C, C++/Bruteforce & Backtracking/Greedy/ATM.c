#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// ���� �����ϴµ� �ɸ��� �ð��� ª�� ������� ������ �� ������ �� �ҿ�ð���
// �����ָ� �ּ� ����ð��� ��

//bubble sort �������� ����
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