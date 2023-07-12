//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//// BFS는 L넣고, 큐 넣어서 구현해보기. 
//// 간선리스트, 인접리스트, 인접행렬??? 이 뭔지,,
//
//// 가중치도 넣어보기
//typedef struct Edge {
//	// 엣지에서 정점이름으로 참고가능
//	int vNum1;
//	int vNum2;
//	// 트리, 백 마킹하는 변수
//	int isTree;
//	struct Edge* next;
//}Edge;
//
//typedef struct IncidentEdge {
//	// 인접정점
//	int adjVertex;
//	Edge* e;
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
//int vCount; // 정점개수
//int eCount; // 간선개수
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
//void dfs(Vertex* v) {
//	IncidentEdge* q;
//	//첫번째 정점이 fresh라면, 방문하기
//	if (v->isFresh == 0) {
//		printf("[%d]", v->num);
//		v->isFresh = 1;
//		//엣지도 기록해보기
//	}
//	//q는 v의 인접간선에서 시작
//	for (q = v->top; q != NULL; q = q->next) {
//		//q의 인접정점 위치 찾기
//		v = findVertex(q->adjVertex);
//		// q의 인접정점 v가 아직 방문안한곳이면, 재귀
//		if (v->isFresh == 0)
//			dfs(v);
//	
//	
//	
//	}
//
//
//
//
//}
//
//
//
//
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
//	p->isTree = 0; // fresh 로 초기화
//	p->next = NULL;
//
//	// 간선 ehaed 가리키도록 하고, 
//	Edge* q = eHead;
//	if (q == NULL) // 연결리스트가 비어있으면
//		eHead = p;
//	else {
//		// addLast 형태로 붙이기
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//	// 정점을 리턴받아서, 정점과 incident edge 연결.
//	Vertex* v = findVertex(v1);
//
//	insertIncidentEdge(v, v2, p);
//
//	// 방향그래프가 아니니까 반대쪽에서도 연결시켜야 함
//	v = findVertex(v2);
//
//	// v2 입장에서는 v1과 연결
//	insertIncidentEdge(v, v1, p);
//
//}
//
//int main() {
//
//	for (int i = 0; i < 9; i++)
//		makeVertices();
//
//	insertEdges(1, 2);
//	insertEdges(1, 3);
//	insertEdges(2, 4);
//	insertEdges(2, 5);
//	insertEdges(3, 5);
//	insertEdges(3,6);
//	insertEdges(4,7);
//	insertEdges(5,7);
//	insertEdges(5,8);
//	insertEdges(6,8);
//	insertEdges(7,9);
//	insertEdges(8, 9);
//	print();
//
//	dfs(vHead);
//
//	return 0;
//}