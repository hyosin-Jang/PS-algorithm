//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//// BFS�� L�ְ�, ť �־ �����غ���. 
//// ��������Ʈ, ��������Ʈ, �������??? �� ����,,
//
//// ����ġ�� �־��
//typedef struct Edge {
//	// �������� �����̸����� ������
//	int vNum1;
//	int vNum2;
//	// Ʈ��, �� ��ŷ�ϴ� ����
//	int isTree;
//	struct Edge* next;
//}Edge;
//
//typedef struct IncidentEdge {
//	// ��������
//	int adjVertex;
//	Edge* e;
//	struct IncidentEdge* next;
//}IncidentEdge;
//
//typedef struct Vertex{
//	int num;
//	//fresh����, visited ���� ���
//	int isFresh;
//	struct Vertex* next;
//
//	// ������ �������� ���
//	IncidentEdge* top;
//}Vertex;
//
//Vertex* vHead = NULL; 
//Edge* eHead = NULL;
//int vCount; // ��������
//int eCount; // ��������
//
//// ���� ����� �Լ�
//void makeVertices() {
//
//	Vertex* p = (Vertex*)malloc(sizeof(Vertex));
//	// �ʱ�ȭ
//	p->num = ++vCount; //1���� ����
//	p->top = NULL;
//	p->next = NULL;
//
//	p->isFresh = 0;
//	Vertex* q = vHead;
//	if (q == NULL) // ���Ḯ��Ʈ�� ���������
//		vHead = p;
//	else {
//		// addLast ���·� ���̱�
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//
//}
//
//// ã����� ���� ��ġ return
//Vertex* findVertex(int v) {
//	Vertex* p = vHead;
//	while (p->num != v)
//		p = p->next;
//	return p;
//}
//
//
//// ����, ��������, edge �ޱ�
//void insertIncidentEdge(Vertex* v, int av, Edge* e) {
//	IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
//	p->adjVertex = av;
//	p->e = e;
//	p->next = NULL;
//
//	// addLast ó��
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
//	//ù��° ������ fresh���, �湮�ϱ�
//	if (v->isFresh == 0) {
//		printf("[%d]", v->num);
//		v->isFresh = 1;
//		//������ ����غ���
//	}
//	//q�� v�� ������������ ����
//	for (q = v->top; q != NULL; q = q->next) {
//		//q�� �������� ��ġ ã��
//		v = findVertex(q->adjVertex);
//		// q�� �������� v�� ���� �湮���Ѱ��̸�, ���
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
//// print �Լ�, �������� �������� ���ؼ� �������� ����ϵ���
//void print() {
//	Vertex* p = vHead;
//	IncidentEdge* q;
//	for (; p != NULL; p = p->next) {
//		printf("���� %d : ", p->num);
//		for (q = p->top; q != NULL; q = q->next)
//			printf("[%d]",q->adjVertex);
//		printf("\n");
//	}
//}
//
//// v1, v2�� ������ ���� ���̴� ��
//void insertEdges(int v1, int v2) {
//	Edge* p = (Edge*)malloc(sizeof(Edge));
//	p->vNum1 = v1;
//	p->vNum2 = v2;
//	p->isTree = 0; // fresh �� �ʱ�ȭ
//	p->next = NULL;
//
//	// ���� ehaed ����Ű���� �ϰ�, 
//	Edge* q = eHead;
//	if (q == NULL) // ���Ḯ��Ʈ�� ���������
//		eHead = p;
//	else {
//		// addLast ���·� ���̱�
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//	// ������ ���Ϲ޾Ƽ�, ������ incident edge ����.
//	Vertex* v = findVertex(v1);
//
//	insertIncidentEdge(v, v2, p);
//
//	// ����׷����� �ƴϴϱ� �ݴ��ʿ����� ������Ѿ� ��
//	v = findVertex(v2);
//
//	// v2 ���忡���� v1�� ����
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