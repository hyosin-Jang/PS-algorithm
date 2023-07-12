//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h> 
//
//// 잘안나옴 ㅠㅠ 다시 해보기!
//typedef struct Edge {
//	int vNum1;
//	int vNum2;
//	struct Edge* next;
//}Edge;
//
//typedef struct IncidentEdge {
//	int adjVertex; // 인접정점번호
//	Edge* e; // 간선 연결
//	struct IncidentEdge* next;
//}IncidentEdge;
// 
//typedef struct Vertex{
//	int num;
//	//fresh인지, visited 인지 기록
//	int isFresh;
//	struct Vertex* next;
//
//	// 각각의 인접간선 기록
//	IncidentEdge* top;
//}Vertex;
//
//Vertex* vHead = NULL; 
//Edge* eHead = NULL;
//int vCount; // 정점개i
//#define N 10
//int in[6];
//
////배열로 구현한 원형큐, 스택으로 구현도 가능
//typedef struct {
//	int element[N];
//	int front, rear;
//}Queue;
//
//void initQueue(Queue* Q) {
//	Q->front = 0;
//	Q->rear = 0;
//}
//
//// dequeue가 front에서 일어남, enqueue는 rear!
//
//int isEmpty(Queue* Q) {
//	return Q->rear == Q->front;
//}
//
//int isFull(Queue* Q) {
//	return (Q->rear + 1) % N == Q->front;
//}
//
//void enqueue(Queue* Q, char elem) {
//	if (isFull(Q)) {
//		printf("Full\n");
//		return;
//	}
//	Q->rear = (Q->rear + 1) % N;
//	Q->element[Q->rear] = elem;
//}
//int dequeue(Queue* Q) {
//	if (isEmpty(Q)) {
//		printf("Empty\n");
//		return;
//	}
//	Q->front = (Q->front + 1) % N;
//	return Q->element[Q->front];
//}
//
//// 정점 만드는 함수
//void makeVertices() {
//
//	Vertex* p = (Vertex*)malloc(sizeof(Vertex));
//	// 초기화
//	p->num = ++vCount; //1부터 시작
//	p->top = NULL;
//	p->next = NULL;
//
//	p->isFresh = 0;
//	Vertex* q = vHead;
//	if (q == NULL) // 연결리스트가 비어있으면
//		vHead = p;
//	else {
//		// addLast 형태로 붙이기
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//
//}
//
//// 찾고싶은 정점 위치 return
//Vertex* findVertex(int v) {
//	Vertex* p = vHead;
//	while (p->num != v)
//		p = p->next;
//	return p;
//}
//
//
//// 정점, 인접정점, edge 받기
//void insertIncidentEdge(Vertex* v, int av, Edge* e) {
//	IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
//	p->adjVertex = av;
//	p->e = e;
//	p->next = NULL;
//
//	// addLast 처리
//	IncidentEdge* q = v->top;
//	if (q == NULL)
//		v->top = p;
//	else{
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//}
//
//void inDegree() {
//	Vertex* p = vHead;
//	IncidentEdge* q;
//	for (;p != NULL; p = p->next)
//		for (q = p->top; q != NULL; q = q->next)
//			in[q->adjVertex - 1]++;
//}
//
////위상정렬
//void topologicalSort() {
//	Queue q;
//	initQueue(&q);
//	//따라다닐 애들
//	Vertex* p;
//	IncidentEdge* r;
//	inDegree(); //진입차수 넣어놓기
//
//	for (int i = 0; i < 6; i++)
//		if (in[i] == 0)
//			enqueue(&q, i + 1);
//
//	while (!isEmpty(&q)) {
//		int w = dequeue(&q);
//		printf("[%d] ",w);
//		p = findVertex(w);
//		r = p->top; // 인접정점과 연결된 애들 찾아가기
//		while (r != NULL) {
//			in[r->adjVertex - 1]--;
//			if (in[r->adjVertex] == 0)
//				enqueue(&q, r->adjVertex);
//			r = r->next;
//		}
//	}
//
//
//}
//
//// print 함수, 정점별로 인접간선 통해서 인접정점 출력하도록
//void print() {
//	Vertex* p = vHead;
//	IncidentEdge* q;
//	for (; p != NULL; p = p->next) {
//		printf("정점 %d : ", p->num);
//		for (q = p->top; q != NULL; q = q->next)
//			printf("[%d]",q->adjVertex);
//		printf("\n");
//	}
//}
//
//// v1, v2가 간선에 정점 붙이는 것
//void insertEdges(int v1, int v2) {
//	Edge* p = (Edge*)malloc(sizeof(Edge));
//	p->vNum1 = v1;
//	p->vNum2 = v2;
//	p->next = NULL;
//
//	Edge* q = eHead;
//	if (q == NULL)
//		eHead = p;
//	else {
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//	Vertex* v = findVertex(v1);
//	insertIncidentEdge(v, v2, p);
//}
//
//int main() {
//
//	for (int i = 0; i < 6; i++)
//		makeVertices();
//
//	insertEdges(1, 2);
//	insertEdges(1, 5);
//	insertEdges(2, 3);
//	insertEdges(4, 5);
//	insertEdges(5, 2);
//	insertEdges(5, 3);
//	insertEdges(5,6);
//	insertEdges(6,3);
//	
//	print();
//	topologicalSort();
//	return 0;
//}