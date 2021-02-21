#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {

	int inputNumber;
	scanf("%d", &inputNumber);
	char bracket[50];
	for (int i = 0; i < inputNumber; i++) {
		int cnt = 0;
		scanf("%s", bracket);
		// strlen은 문자열 길이 알아내는 함수
		for (int j = 0; j < strlen(bracket); j++) {
			if (bracket[j] == '(')
				cnt++;
			else
				cnt--;
			if (cnt < 0) {
				printf("NO\n");
				break;
			}
		}
		if (cnt == 0) {
			printf("YES\n");
		}
		else if (cnt > 0) {
			printf("NO\n");
		}


	}
	return 0;


}