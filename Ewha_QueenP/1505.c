#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//���α׷��ӽ������� main�Լ� �� ����¹��� �ʿ����� �ʽ��ϴ�. ��� solution�Լ��� �ۼ��ϸ� �˴ϴ�.

char* solution(const char* s) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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
		// ch�� 1�� �����ϸ�
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
				//ch�� 0�̸�
				while (ch == '0') {
					len++;
					ch = s[i++];
				}
				answer[k++] = (char)(64 + len);
			}	
		}
		//ch�� 0���� �����ϸ�
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
				//ch�� 1�̸�
				while (ch == '1') {
					len++;
					ch = s[i++];
				}
				answer[k++] = (char)(64 + len);
			}

		}
		//���ڿ� ���� '\0'�̶�� NULL�κ� 
		// ó�������� ������ �����Ⱚ ���.
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
