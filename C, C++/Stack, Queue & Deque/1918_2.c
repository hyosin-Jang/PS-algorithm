#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int stack[100];
	int top;
}Stack;

int isEmpty(Stack* s) {
	if (s->top == 0)
		return 1;
	else
		return 0;
}

char pop(Stack* s) {
	if (!isEmpty(s))
		return s->stack[--(s->top)];
	else
		return -1;
}

void push(Stack* s, char ch) {
	s->stack[s->top++] = ch;
}

char peek(Stack* s) {
	return s->stack[s->top];
}

// 우선순위 return 
int priority(char ch) {
	switch (ch) {
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
	case ')':
		return 0;
	}
	return -1;
}

int main() {
	Stack stack;
	char s[100], sb[100];
	int len=0, ptr=0;

	while (1) {
		scanf("%c", s);
		// 입력 문자열 길이
		len++;
		if (s == '\n') break;
	}

	for (int i = 0; i < len; i++) {
		int p = priority(s[i]);
		char ch = s[i];

		switch (ch) {
			case'+':
			case'-':
			case'*':
			case'/':
				while (isEmpty(&stack) && priority(peek(&stack)) >= p) {
					sb[ptr++] = pop(&stack);
				}
				push(&stack,ch);
				break;
			case '(':
				push(&stack, ch);
				break;
			case ')':
				while (!isEmpty(&stack) && peek(&stack) != '(') {
					sb[ptr++] = pop(&stack);
				}
				pop(&stack);
				break;
			default:
				sb[ptr++] = ch;
		}

		while (!isEmpty(&stack))
			sb[ptr++] = pop(&stack);

		for (int i = 0; i < ptr; i++)
			printf("%c", sb[i]);
		}


	return 0;
}