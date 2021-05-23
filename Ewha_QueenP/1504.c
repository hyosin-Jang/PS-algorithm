#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 정수 배열 numbers 의 길이는 9 입니다.
int* solution(int numbers[]) {
	//할당 길이는 상황에 맞게 변경해주세요.
	int* answer = (int*)malloc(sizeof(int)*7);
	int sum = 0,ptr=0,p=0;
	for (int i = 0; i < 9; i++)
		sum += numbers[i];

	for (int i = 0; i < 9; i++) {
		for(int j= i+1 ; j< 9 ; j++)
			if (sum - numbers[i] - numbers[j] == 100) {
				while (ptr!=7) {
					if (p == i || p == j) {
						p++;
						continue;
					}
					answer[ptr++] = numbers[p++];
				}
			}
	}


	return answer;
}

int main(void) {
	int numbers[9];
	int i;
	int* r = NULL;

	for (i = 0; i < 9; i++) {
		scanf("%d", &numbers[i]);
	}

	r = solution(numbers);
	for (i = 0; i < 7; i++) {
		printf("%d ", r[i]);
	}
}
