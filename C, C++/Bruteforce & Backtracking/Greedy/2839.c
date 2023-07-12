#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N = 0, a = 0, cnt = 0, n = 0, break_flag=0;
	scanf("%d", &N); // N 입력받음

	if (N % 5 == 0)
		cnt = N / 5;
	else {
		a = N / 5;
		n = N % 5;
		while (n % 3 != 0 && N>5 && a>=0) { // 나머지가 3의 배수가 아니라면
			a--;
			n = N - a * 5;
			if (a < 0) {
				cnt = -1;
				break_flag = 1;
				break;
			}
		}
		if (break_flag == 1) {
			printf("%d", cnt);
			return 0;
		}


		cnt = a + n / 3;

		if (N % 3 == 0 && N < 5)
			cnt = N / 3;
		else if (N % 3 != 0 && N<5)
			cnt = -1;
	
	
	}
	printf("%d", cnt);




}
