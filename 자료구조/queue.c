#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10000

typedef struct {
	int front;
	int rear;
	int data[SIZE];
	int size;
}QueueType;

void init_queue(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}

int is_full(QueueType* q) {
	if (q->rear == SIZE - 1)
		return 1;
	else return 0;
}

void is_empty(QueueType* q) {
	if (q->front == q->rear)
		printf("1\n");
	else
		printf("0\n");
}
void push(QueueType* q, int item) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 포화상태입니다.");
		exit(1);
	}
	else {
		q->data[++(q->rear)] = item;
		q->size = q->rear - q->front;
	}
}

void pop(QueueType* q) {
	if (q->front == q->rear) {
		printf("-1\n");
		q->size = 0;
	}
	else {
		printf("%d\n", q->data[++(q->front)]);
		q->size = q->rear - q->front;
	}
}

void size(QueueType* q) {
	printf("%d\n",q->size);
}

void front(QueueType* q) {
	if (q->front == q->rear) {
		printf("-1\n");
	}
	else
		printf("%d\n", q->data[(q->front)+1]);

}

void back(QueueType* q) {
	if (q->front == q->rear) {
		printf("-1\n");
	}
	else
		printf("%d\n", q->data[q->rear]);

}

int main(void) {

	int item = 0;
	int N,i;
	char cmd[10];
	QueueType q;

	init_queue(&q);

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", cmd);
	
		// strcmp는 두 문자열이 같다면 0을 반환
		// 0! = 1이므로 다음 문장 실행
		if (!strcmp(cmd, "push")) {
			scanf("%d", &item);
			push(&q, item);
		}
		else if (!strcmp(cmd, "front"))
			front(&q);
		else if (!strcmp(cmd, "back"))
			back(&q);
		else if (!strcmp(cmd, "empty"))
			is_empty(&q);
		else if (!strcmp(cmd, "size"))
			size(&q);
		else if (!strcmp(cmd, "pop"))
			pop(&q);
			
		}
		return 0;
	
	}
