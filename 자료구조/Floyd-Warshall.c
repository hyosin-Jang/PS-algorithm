//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 10
//#define INF 1000000
//
//typedef struct GraphType {
//	//정점 개수
//	int n;
//	//인접행렬
//	int weight[SIZE][SIZE];
//}GraphType;
//
////결과 저장하는 배열
//int A[SIZE][SIZE];
//
//void printA(GraphType* g) {
//	int i, j;
//	printf("==================================\n");
//	for (i = 0; i < g->n; i++) {
//		for (j = 0; j < g->n; j++) {
//			if (A[i][j] == INF)
//				// INF면 *로 출력
//				printf("  *");
//			else printf("%3d", A[i][j]);
//		}
//		printf("\n");
//	}
//	printf("====================================\n");
//}
//
//
//void floyd(GraphType* g) {
//	int i, j, k;
//	for (i = 0; i < g->n; i++)
//		for (j = 0; j < g->n; j++)
//			A[i][j] = g->weight[i][j];
//	printA(g);
//
//	//새로운 경로 찾는 알고리즘
//	for (k = 0; k < g->n; k++) {
//		// i는 행, j는 열
//		for (i = 0; i < g->n; i++)
//			for (j = 0; j < g->n; j++)
//				// 만약, i와 k가 인접하고, k와 j가 인접하다면
//				// 즉, 경로가 있다면
//				if (A[i][k] == 1 && A[k][j] == 1)
//					// 해당위치를 경로가 존재한다고 표시하기
//					A[i][j] = 1;
//		printA(g);  
//	}
//}
//
//
//// 만약 , 간선이 가중치 값이 있다면, 삼중 for문 
////if (A[i][k] + A[k][j] < A[i][j])
////	A[i][j] = A[i][k] + A[k][j];
//// 작은 값으로 대체해주기, 최적의 탐색 경로 구하기
//
//
//
//int main() {
//
//	// g초기화, 0은 자기자신 간선 없으니까 루프가 없다는 뜻, 
//	// 경로가 있으면 1, 경로 없으면 Infinity(1000000), 
//	GraphType g = { 5,
//		{{0, 1, INF, 1, INF},
//		{INF, 0, INF, INF, INF},
//		{1, INF, 0, INF, INF},
//		{INF, INF, INF, 0, 1},
//		{1, INF, INF, INF, 0} }
//	};
//	floyd(&g);   
//
//	return 0;
//}