#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define QSIZE 50
//간선 연결리스트
typedef struct Edge{
	int isTree; // 트리, 백 마킹하는 변수
	struct Edge* next; // 간선 연결리스트
	int v1, v2; // 시작노드, 끝노드
}Edge;

// 부착간선
typedef struct IncidentEdge{
	Edge* e; // 간선 정보!
	int adjVertex; // 인접정점
	struct IncidentEdge* next; // 부착간선 연결리스트
}IncidentEdge;
//정점 연결리스트
typedef struct Vertex{
	int num; // 정점번호
	IncidentEdge* top; // 부착간선
	struct Vertex* next; // 다음 정점 연결
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
	v->num = ++vCount; //1부터 저장
	v->top = NULL;
	v->next = NULL;

	v->isFresh = 0;
	Vertex* p = vHead; // 포인터
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

// ****** int av 인것 주의
void InsertIncidentEdges(Vertex* v, int av, Edge* e) {
	IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
	p->adjVertex = av; // 인접정점
	p->e = e; // 간선
	p->next = NULL;

	//addLast 처리
	IncidentEdge* q = v->top;
	if (q == NULL)
		v->top = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

// v1과 v2사이에 edge 만들기
void insertEdges(int v1, int v2) {
	Edge* e = (Edge*)malloc(sizeof(Edge));
	e->isTree = 0;
	e->next = NULL;
	e->v1 = v1;
	e->v2 = v2;

	//엣지 연결리스트 연결
	Edge* p = eHead;
	if (p == NULL) {
		eHead = e;
	}
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = e;
	}

	// incidentEdge 연결
	Vertex* v = findVertex(v1);
	InsertIncidentEdges(v, v2, e);

	v = findVertex(v2);
	InsertIncidentEdges(v, v1, e);
}

// p->next!=NULL 과 p!=NULL
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
		//printf("enqueue 성공, top: %d\n", q->top);
	}
}
Vertex* dequeue(QueueType* q) {
	if (q->top != q->rear) {
		Vertex* v = q->v[q->rear];
		q->rear++;
		//printf("dequeue 성공, rear: %d\n", q->rear);
		return v;
	}
	else
		return 0;
}
void bfs(Vertex* v) {

	v->isFresh = 1; // 방문기록 추가

	//1. 큐에 v 넣기
	enqueue(queue, v);

	// 2. 큐가 소진될 때까지 반복
	while (queue->top != queue->rear) {
		Vertex* p = dequeue(queue);
		p->isFresh = 1; // 큐에서 추출한 정점 방문
		
		printf("[%d]=> ",p->num);

		IncidentEdge* q = p->top;
		// 인접간선이 빌때까지 
		while (q!= NULL) {

			int av = q->adjVertex;
			Vertex* next_vt = findVertex(av);
			if (next_vt->isFresh == 1)
				q = q->next;
			else {
				next_vt->isFresh = 1; //방문한 노드 체크
				//printf("%d의 adjVertex: %d\n", p->num, av);
				enqueue(queue, next_vt);
				q = q->next;
			}
		}
	}
}

int main() {
	// 큐 초기화
	queue = (QueueType*)malloc(sizeof(queue));
	initQueue(queue);

	// 초기화
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
