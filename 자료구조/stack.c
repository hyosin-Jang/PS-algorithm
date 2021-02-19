#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10000

typedef int element;
element stack[SIZE];
int top = -1;

// ���� ���� ���� �Լ�
void is_empty() {
	if (top == -1) 
		printf("-1\n");
	else
		printf("0\n");
}

// ���� �Լ�
void push(element item) {
	stack[++top] = item;
}

void pop() {
	if (top==-1)
		printf("-1\n");
	else 
		printf("%d\n", stack[top--]);
}

// ������ ���� ���� ���� ���
void peek() {
	if (top==-1)
		printf("-1\n");
	else
		printf("%d\n", stack[top]);
}

// ���ÿ� ����ִ� ������ ���� ���
void size() {
	printf("%d\n", top + 1);
}
 
int main() {
	int N; // ����� ��
	scanf("%d", &N);
	int i;
	int item;
	char cmd[10];
	for (i = 0; i < N; i++) {
		scanf("%s", cmd);

		// strcmp�� �� ���ڿ��� ���ٸ� 0�� ��ȯ
		// 0! = 1�̹Ƿ� ���� ���� ����
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