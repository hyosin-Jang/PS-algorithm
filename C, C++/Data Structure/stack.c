#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10000

typedef int element;
element stack[SIZE];
int top = -1;

// 공백 상태 검출 함수
void is_empty() {
	if (top == -1) 
		printf("-1\n");
	else
		printf("0\n");
}

// 삽입 함수
void push(element item) {
	stack[++top] = item;
}

void pop() {
	if (top==-1)
		printf("-1\n");
	else 
		printf("%d\n", stack[top--]);
}

// 스택의 가장 위의 정수 출력
void peek() {
	if (top==-1)
		printf("-1\n");
	else
		printf("%d\n", stack[top]);
}

// 스택에 들어있는 정수의 개수 출력
void size() {
	printf("%d\n", top + 1);
}
 
int main() {
	int N; // 명령의 수
	scanf("%d", &N);
	int i;
	int item;
	char cmd[10];
	for (i = 0; i < N; i++) {
		scanf("%s", cmd);

		// strcmp는 두 문자열이 같다면 0을 반환
		// 0! = 1이므로 다음 문장 실행
		if (!strcmp(cmd, "push")) {
			scanf("%d", &item);
			push(item);
		}
		else if (!strcmp(cmd, "top"))
			peek();
		else if (!strcmp(cmd, "size"))
			size();
		else if (!strcmp(cmd, "pop"))
			pop();
		else
			is_empty();

	}
	return 0;

}