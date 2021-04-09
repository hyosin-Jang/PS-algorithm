#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
	int data;
	struct QueueNode* link;

}QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
}LinkedQueue;

void init(LinkedQueue* queue) {
	queue->front = queue->rear = NULL;
}
int is_empty(LinkedQueue* queue) {
	if (queue->front == queue->rear)
		return 1;
	else
		return 0;
}
int dequeue(LinkedQueue* queue) {
	QueueNode* temp = queue -> front;
	int data;
	if (is_empty(queue)) {
		fprntf(stderr,"Queue is empty\n");
		exit(1);
	}
	else {
		data = temp->data;
		queue->front = temp->link;
		if (queue->front == NULL) // �ϳ� ����־ �ϳ� �����ϸ� ��� �� ���
			queue->rear = NULL; // rear�� NULL�� �ʱ�ȭ�����ֱ�
		free(temp); //�޸� �ݳ�
		return data;
	}
}

void enqueue(LinkedQueue* queue, int data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(queue)) {
		queue->front = temp;
		queue->rear = temp;
	}
	else {
		queue->rear->link = temp;
		queue->rear = temp;
	}
}
void print_queue(LinkedQueue* queue) {
	QueueNode* p;
	for (p = queue->front; p != NULL; p = p->link)
		printf("[%d]->",p->data);
	printf("[NULL]\n");
	
}


void main() {
	LinkedQueue queue;
	init(&queue);

	enqueue(&queue, 10);print_queue(&queue);
	enqueue(&queue, 20);print_queue(&queue);
	enqueue(&queue, 30);print_queue(&queue);
	getch();
	enqueue(&queue, 10);print_queue(&queue);
	enqueue(&queue, 10);print_queue(&queue);

}