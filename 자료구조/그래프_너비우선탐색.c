#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define QSIZE 50
//���� ���Ḯ��Ʈ
typedef struct Edge{
	int isTree; // Ʈ��, �� ��ŷ�ϴ� ����
	struct Edge* next; // ���� ���Ḯ��Ʈ
	int v1, v2; // ���۳��, �����
}Edge;

// ��������
typedef struct IncidentEdge{
	Edge* e; // ���� ����!
	int adjVertex; // ��������
	struct IncidentEdge* next; // �������� ���Ḯ��Ʈ
}IncidentEdge;
//���� ���Ḯ��Ʈ
typedef struct Vertex{
	int num; // ������ȣ
	IncidentEdge* top; // ��������
	struct Vertex* next; // ���� ���� ����
	int isFresh;
}Vertex;

typedef struct Queue{
	Vertex* v[QSIZE];
	int top, rear;
}QueueType;

void initQueue(QueueType* q) {
	q->top = 0;
	q->rear = 0;
}

Vertex* vHead = NULL;
Edge* eHead = NULL;
IncidentEdge* top = NULL;
int vCount;
int eCount;
QueueType* queue;

void makeVertices() {
	Vertex* v = (Vertex*)malloc(sizeof(Vertex));
	v->num = ++vCount; //1���� ����
	v->top = NULL;
	v->next = NULL;

	v->isFresh = 0;
	Vertex* p = vHead; // ������
	if (vHead == NULL) {
		vHead = v;
	}
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = v;
	}
}
Vertex* findVertex(Vertex* v) {
	Vertex* p = vHead;
	while (p->num != v)
		p = p->next;
	return p;
}

// ****** int av �ΰ� ����
void InsertIncidentEdges(Vertex* v, int av, Edge* e) {
	IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
	p->adjVertex = av; // ��������
	p->e = e; // ����
	p->next = NULL;

	//addLast ó��
	IncidentEdge* q = v->top;
	if (q == NULL)
		v->top = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

// v1�� v2���̿� edge �����
void insertEdges(int v1, int v2) {
	Edge* e = (Edge*)malloc(sizeof(Edge));
	e->isTree = 0;
	e->next = NULL;
	e->v1 = v1;
	e->v2 = v2;

	//���� ���Ḯ��Ʈ ����
	Edge* p = eHead;
	if (p == NULL) {
		eHead = e;
	}
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = e;
	}

	// incidentEdge ����
	Vertex* v = findVertex(v1);
	InsertIncidentEdges(v, v2, e);

	v = findVertex(v2);
	InsertIncidentEdges(v, v1, e);
}

// p->next!=NULL �� p!=NULL
void print() {
	Vertex* p = vHead;
	for (; p!= NULL; p = p->next) {
		printf("[%d]=> ", p->num);
		IncidentEdge* q = p->top;
		for (; q!= NULL; q = q->next)
			printf("[%d]", q->adjVertex);
		printf("\n");
	}
}

void enqueue(QueueType* q, Vertex* v) {
	if (q->top != QSIZE) {
		q->v[q->top] = v;
		q->top++;
		//printf("enqueue ����, top: %d\n", q->top);
	}
}
Vertex* dequeue(QueueType* q) {
	if (q->top != q->rear) {
		Vertex* v = q->v[q->rear];
		q->rear++;
		//printf("dequeue ����, rear: %d\n", q->rear);
		return v;
	}
	else
		return 0;
}
void bfs(Vertex* v) {

	v->isFresh = 1; // �湮��� �߰�

	//1. ť�� v �ֱ�
	enqueue(queue, v);

	// 2. ť�� ������ ������ �ݺ�
	while (queue->top != queue->rear) {
		Vertex* p = dequeue(queue);
		p->isFresh = 1; // ť���� ������ ���� �湮
		
		printf("[%d]=> ",p->num);

		IncidentEdge* q = p->top;
		// ���������� �������� 
		while (q!= NULL) {

			int av = q->adjVertex;
			Vertex* next_vt = findVertex(av);
			if (next_vt->isFresh == 1)
				q = q->next;
			else {
				next_vt->isFresh = 1; //�湮�� ��� üũ
				//printf("%d�� adjVertex: %d\n", p->num, av);
				enqueue(queue, next_vt);
				q = q->next;
			}
		}
	}
}

int main() {
	// ť �ʱ�ȭ
	queue = (QueueType*)malloc(sizeof(queue));
	initQueue(queue);

	// �ʱ�ȭ
	for (int i = 0; i < 9; i++)
		makeVertices();

	insertEdges(1, 2);
	insertEdges(1, 3);
	insertEdges(2, 4);
	insertEdges(2, 5);
	insertEdges(3,5);
	insertEdges(3,6);
	insertEdges(4,7);
	insertEdges(5, 7);
	insertEdges(5,8);
	insertEdges(6,8);
	insertEdges(7,9);
	insertEdges(8,9);
	print();
	//printf("vHead: %d\n",vHead->num);

	bfs(vHead);

	return 0;

}