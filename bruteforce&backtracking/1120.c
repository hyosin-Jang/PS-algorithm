#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 50

int main() {

	int dif, cnt, max=0;
	char A[SIZE];
	char B[SIZE];

	scanf("%s %s",&A, &B);
	//printf("%s %s",A, B);

	dif = strlen(B) - strlen(A);
	for (int i = 0; i < dif+1; i++) {
		cnt = 0;
		for (int j = 0; j < strlen(A); j++) {
			if (A[j] == B[i+j]) cnt++;
		}
		if(max < cnt) max = cnt;
	}
	printf("%d", strlen(A)-max);


	return 0;
}