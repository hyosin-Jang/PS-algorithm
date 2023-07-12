#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int T;
	int i = 0,c=0;
	int arr[50];
	int count0 = 0, count1 = 0;
	char N[50];
	char M[50];

	scanf("%d", &T);

	scanf("%s %s",&N[i], &M[i]);
	while (1) {
		if (N[i] == '\n')
			break;

		else if (N[i] == M[i])
			i++;
		else {
			arr[c++] = N[i]; // arr은 N과 M의 다른 값만 넣기
			i++;
		}	
	}
	for (int i = 0; i < c;i++) {
		if (arr[i] == '0')
			count0 += 1;
		else
			count1 += 1;
	}
	if (count0 > count1)
		printf("%d", count0);
	else 
		printf("%d", count1);
		

	return 0;
}