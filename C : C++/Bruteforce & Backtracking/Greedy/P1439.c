#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int i=0, count1=0, count0=0;
	char arr[1000001];

	while (1) {
		scanf("%c", &arr[i]);
		if (arr[i++] == '\n') // 문자열 입력
			break;
	}
	i = 0;

	while (1) {
		if (arr[i] == '0') {
			while (arr[i + 1] == '0')
				i++;
			count0 += 1;
			i++;
		}
		else {
			while (arr[i + 1] == '1')
				i++;
			count1 += 1;
			i++;
		}
		if (arr[i] == '\n')
			break;
	}
	if (count0 < count1)
		printf("%d\n", count0);
	else
		printf("%d",count1);
	return 0;

}