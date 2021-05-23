#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.

char* solution(const char* s) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	int length=0,j=0;
	int flag;
	while(s[j]!='\0'){
	flag= s[j];
	while (s[j] == flag)j++;
	length++;
	}
	if (s[0] == '1')length++;
	length++;

	char* answer = (char*)malloc(sizeof(char)*length);
	char ch='!', next='%', c;
	int i=0, len=0,k=0;
		ch = s[i++];
		// ch가 1로 시작하면
		if (ch == '1') {
			answer[k++] = '1';
			while (ch != '\0') {
				len = 0;
				while (ch == '1') {
					len++;
					ch = s[i++];
				}
				answer[k++] = (char)(64 + len);
				len = 0;
				if (ch == '\0')break;
				//ch가 0이면
				while (ch == '0') {
					len++;
					ch = s[i++];
				}
				answer[k++] = (char)(64 + len);
			}	
		}
		//ch가 0으로 시작하면
		else {
			while (ch != '\0') {
				len = 0;
				while (ch == '0') {
					len++;
					ch = s[i++];
				}
				answer[k++] = (char)(64 + len);
				len = 0;
				if (ch == '\0')break;
				//ch가 1이면
				while (ch == '1') {
					len++;
					ch = s[i++];
				}
				answer[k++] = (char)(64 + len);
			}

		}
		//문자열 끝에 '\0'이라는 NULL부분 
		// 처리해주지 않으면 쓰레기값 뜬다.
		answer[k++] = '\0';
	return answer;
}

int main() {
	char s[10000] = "";
	char* answer;

	scanf("%s", s);
	answer = solution(s);
	printf("%s \n", answer);
}
