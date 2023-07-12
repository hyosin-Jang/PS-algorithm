//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//// 정점 노드
//typedef struct {
//	char vName;
//}Vertex;
//
//// 간선 노드
//typedef struct {
//	int eNo; // 간선번호
//	int weight; // 가중치
//	Vertex v1, v2; // 시점 노드, 종점 노드
//}Edge;
//
//typedef struct {
//	Vertex v[10];
//	Edge e[30];
//	int vCount; // 정점개수
//	int eCount; // 간선개수
//}Graph;
//
//void init(Graph* G) {
//	G->vCount = 0;
//	G->eCount = 0;
//
//}
//
//void makeVertex(Graph* G) {
//	// a부터 초기화
//	G->v[G->vCount].vName = 97 + G->vCount;
//	G->vCount++;
//}
//
//void insertEdge(Graph* G, int w, Vertex v1, Vertex v2) {
//	G->e[G->eCount].eNo = G->eCount; // 간선번호 = 간선 개수
//	G->e[G->eCount].weight = w;
//	G->e[G->eCount].v1 = v1;
//	G->e[G->eCount].v2 = v2;
//	G->eCount++;
//}
//
//int main() {
//	Graph G;
//	init(&G);
//	for (int i = 0; i < 6; i++)
//		makeVertex(&G);
//
//	insertEdge(&G, 1, G.v[0], G.v[1]);
//	insertEdge(&G, 1, G.v[0], G.v[2]);
//	insertEdge(&G, 1, G.v[0], G.v[3]);
//	insertEdge(&G, 2, G.v[0], G.v[5]);
//	insertEdge(&G, 1, G.v[1], G.v[2]);
//	insertEdge(&G, 4, G.v[2], G.v[4]);
//	insertEdge(&G, 3, G.v[4], G.v[5]);
//
//	for (int i = 0; i < G.vCount; i++)
//		printf("[%c] ", G.v[i].vName);
//	printf("\n");
//
//	for (int i = 0; i < G.eCount; i++)
//		printf("[%d : %c - %c - %d] ", G.e[i].eNo, G.e[i].v1.vName, G.e[i].v2.vName, G.e[i].weight );
//	printf("\n");
//
//} 