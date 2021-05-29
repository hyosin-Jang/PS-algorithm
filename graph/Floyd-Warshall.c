//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 10
//#define INF 1000000
//
//typedef struct GraphType {
//	//���� ����
//	int n;
//	//�������
//	int weight[SIZE][SIZE];
//}GraphType;
//
////��� �����ϴ� �迭
//int A[SIZE][SIZE];
//
//void printA(GraphType* g) {
//	int i, j;
//	printf("==================================\n");
//	for (i = 0; i < g->n; i++) {
//		for (j = 0; j < g->n; j++) {
//			if (A[i][j] == INF)
//				// INF�� *�� ���
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
//	//���ο� ��� ã�� �˰���
//	for (k = 0; k < g->n; k++) {
//		// i�� ��, j�� ��
//		for (i = 0; i < g->n; i++)
//			for (j = 0; j < g->n; j++)
//				// ����, i�� k�� �����ϰ�, k�� j�� �����ϴٸ�
//				// ��, ��ΰ� �ִٸ�
//				if (A[i][k] == 1 && A[k][j] == 1)
//					// �ش���ġ�� ��ΰ� �����Ѵٰ� ǥ���ϱ�
//					A[i][j] = 1;
//		printA(g);  
//	}
//}
//
//
//// ���� , ������ ����ġ ���� �ִٸ�, ���� for�� 
////if (A[i][k] + A[k][j] < A[i][j])
////	A[i][j] = A[i][k] + A[k][j];
//// ���� ������ ��ü���ֱ�, ������ Ž�� ��� ���ϱ�
//
//
//
//int main() {
//
//	// g�ʱ�ȭ, 0�� �ڱ��ڽ� ���� �����ϱ� ������ ���ٴ� ��, 
//	// ��ΰ� ������ 1, ��� ������ Infinity(1000000), 
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