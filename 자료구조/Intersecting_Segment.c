//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 6
//
////����
//typedef struct {	
//	int num; //���� ��ȣ
//	float s, e; // ����, ��
//}Segment;
//
//// (����, ����)�̺�Ʈ
//typedef struct {
//	float coor; // ��ǥ 0.6, 0.8, 1.0 , ...
//	char code; // 'S' �� 'E'
//	int id; // ���� ��ȣ
//}Event;
//
//typedef struct {
//	int id1, id2;
//}interSegment;
//
//void insertion_sort(Event ev[], int n) {
//	// n�� �迭 ������
//	int i, j;
//	Event item;
//	for (i = 0; i < n; i++) {
//		item = ev[i];
//		//������ ������ ���ϱ�, �ڸ� �̵�
//		for (j = i - 1; j >= 0 && ev[j].coor > item.coor ; j--)
//			ev[j + 1] = ev[j];
//		//�󵥴� �־��ֱ�
//		ev[j + 1] = item;
//	}
//}
//
//void findIntersectingSegment(Event ev[]) {
//	int openSegments[SIZE];
//	interSegment is[SIZE * 2];
//	int oCnt = 0; //���¼��׸�Ʈ ����
//	int iCnt = 0; // intersegment ����
//
//	for (int i = 0; i < SIZE * 2; i++) {
//		if (ev[i].code == 'S') {
//			// S��, 1. �������� = (������������, ���缱��)
//			for(int j=0 ; j<oCnt ; j++)
//				if (openSegments[j] != 0) { //���������Ŵ� 0ó��
//					is[iCnt].id1 = openSegments[j];
//					is[iCnt].id2 = ev[i].id;
//					iCnt++;
//				}
//			// S��, 2. �������� = �������� U ���缱��
//			openSegments[oCnt++] = ev[i].id;
//		}
//		else { //E���, �������п��� ���缱�� ����
//			for (int j = 0; j < oCnt; j++)
//				if (openSegments[j] == ev[i].id)
//					openSegments[j] = 0; // 0 = ����
//		}
//	}
//	// ���ͼ��׸�Ʈ ���
//	for (int i = 0; i < iCnt; i++)
//		printf("(%d, %d)",is[i].id1, is[i].id2);
//	printf("\n");
//}
//
//int main() {
//	Segment lines[] = {
//		{1, 1.0, 3.2}, {2, 0.8, 3.0}, {3, 0.6, 2.8},{4,1.1,2.0},{5,5.4,7.0},{6,2.9,5.0}
//	};
//	Event ev[SIZE * 2];
//	for (int i = 0; i < SIZE; i ++)
//		printf("%d, (%.1f ~ %.1f)\n",lines[i].num, lines[i].s,lines[i].e);
//	printf("\n");
//	getchar();
//
//	for (int i = 0, j=0; i < SIZE * 2; i++, j++) {
//		ev[i].coor = lines[j].s;
//		ev[i].code = 'S';
//		ev[i].id = lines[j].num;
//
//		ev[i+1].coor = lines[j].e;
//		ev[i+1].code = 'E';
//		ev[++i].id = lines[j].num;
//	}
//
//	for (int i = 0; i < SIZE*2; i++)
//		printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
//	printf("\n");
//
//	// ���� ��������
//	insertion_sort(ev, SIZE * 2);
//	for (int i = 0; i < SIZE * 2; i++)
//		printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
//	printf("\n");
//
//	findIntersectingSegment(ev);
//}