//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 6
//
////선분
//typedef struct {	
//	int num; //선분 번호
//	float s, e; // 시작, 끝
//}Segment;
//
//// (시작, 종료)이벤트
//typedef struct {
//	float coor; // 좌표 0.6, 0.8, 1.0 , ...
//	char code; // 'S' 나 'E'
//	int id; // 선분 번호
//}Event;
//
//typedef struct {
//	int id1, id2;
//}interSegment;
//
//void insertion_sort(Event ev[], int n) {
//	// n은 배열 사이즈
//	int i, j;
//	Event item;
//	for (i = 0; i < n; i++) {
//		item = ev[i];
//		//작은게 앞으로 가니까, 자리 이동
//		for (j = i - 1; j >= 0 && ev[j].coor > item.coor ; j--)
//			ev[j + 1] = ev[j];
//		//빈데다 넣어주기
//		ev[j + 1] = item;
//	}
//}
//
//void findIntersectingSegment(Event ev[]) {
//	int openSegments[SIZE];
//	interSegment is[SIZE * 2];
//	int oCnt = 0; //오픈세그먼트 개수
//	int iCnt = 0; // intersegment 개수
//
//	for (int i = 0; i < SIZE * 2; i++) {
//		if (ev[i].code == 'S') {
//			// S면, 1. 교차선분 = (열린선분집합, 현재선분)
//			for(int j=0 ; j<oCnt ; j++)
//				if (openSegments[j] != 0) { //빠져나간거는 0처리
//					is[iCnt].id1 = openSegments[j];
//					is[iCnt].id2 = ev[i].id;
//					iCnt++;
//				}
//			// S면, 2. 열린선분 = 열린선분 U 현재선분
//			openSegments[oCnt++] = ev[i].id;
//		}
//		else { //E라면, 열린선분에서 현재선분 빼기
//			for (int j = 0; j < oCnt; j++)
//				if (openSegments[j] == ev[i].id)
//					openSegments[j] = 0; // 0 = 빼기
//		}
//	}
//	// 인터세그먼트 출력
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
//	// 점들 삽입정렬
//	insertion_sort(ev, SIZE * 2);
//	for (int i = 0; i < SIZE * 2; i++)
//		printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
//	printf("\n");
//
//	findIntersectingSegment(ev);
//}