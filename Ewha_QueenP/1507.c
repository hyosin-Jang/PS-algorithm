#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//그리디 회의실 배정 문제랑 동일

typedef struct meeting {
	int start;
	int end;
}Meeting;

int compare(const void* a, const void* b) {
	Meeting* n1 = (Meeting*)a;
	Meeting* n2 = (Meeting*)b;

	if (n1->end > n2->end)
		return 1;
	else if (n1->end < n2->end)
		return -1;
	else {
		if (n1->start > n2->start)
			return 1;
		else if (n1->start < n2->start)
			return -1;
		else
			return 0;
	}
}
int main(void) {
	int N = 0, cur = 0, cnt = 0;
	Meeting* meet;
	scanf("%d",&N);
	meet = (Meeting*)malloc(sizeof(Meeting) * N);
	for (int i = 0; i < N; i++)
		scanf("%d",&meet[i].start);
	for (int i = 0; i < N; i++)
		scanf("%d", &meet[i].end);
	// 배열의 0번째 요소 포인터, 배열의 요소 개수, 각 요소 하나의 크기를 바이트로, 비교 함수
	qsort(meet, N, sizeof(Meeting), compare);

	for (int i = 0; i < N; i++) {
		if (meet[i].start >= cur) {
			cur = meet[i].end;
			cnt++;
		}

	}
	printf("%d",cnt);
	free(meet);
	return 0;


}