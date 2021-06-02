//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define M 13
//
//typedef struct HashNode {
//	int key;
//	struct HashNode* next;
//}HashType;
//
//void init(HashType* HT) {
//	for (int i = 0; i < M; i++) {
//		HT[i].key = 0;
//		HT[i].next = NULL;
//	}
//}
//
//void insertItem(HashType* HT, int key) {
//	int v = h(key);
//	HashType* node = (HashType*)malloc(sizeof(HashType));
//	node->key = key;
//	// addFirst연산
//	node->next = HT[v].next; // 지금 만든 node의 next에 현재 HT[v]의 first 연결해줌
//	HT[v].next = node;
//}
//int removeElement(HashType* HT, int key) {
//	int v = h(key);
//	int count = 0; // 같은 키가 몇개 삭제됐는지
//	// 삭제한 노드 기억
//	// HashType의 주소를 기억하는 포인터 변수 p
//	// 에다, HT[v]는 HashType임. HashType의 주소 저장!
//	HashType* p = &HT[v];
//	HashType* q;
//
//	while (p->next) {
//		if (p->next->key == key) {
//			count++;
//			//q는 삭제될 노드
//			q = p->next;
//			p->next = q->next;
//			free(q);
//		}
//		else
//			p = p->next;
//	}
//	return count;
//}
//int findElement(HashType* HT, int key) {
//	int v = h(key);
//	int count;
//	HashType* p;
//	for (p = HT[v].next; p != NULL; p = p->next) {
//		if (p->key == key)
//			count++;
//	}
//	return count; 
//}
//
//void printHash(HashType* HT) {
//	HashType* p;
//	for (int i = 0; i < M; i++) {
//		printf("HT[%02d] : ", i);
//		for (p = HT[i].next; p != NULL; p = p->next)
//			printf("(%d) ", p->key);
//		printf("\n");
//	}
//}
//int h(int key) {
//	return key % M;
//}
//
//int main() {
//
//	HashType HT[M];
//	init(HT);
//
//	srand(time(NULL));
//
//	for (int i = 0; i < 20; i++)
//		insertItem(HT, rand() % 90 + 10);
//	printHash(HT);
//
//
//	printf("\n 삭제할 키 입력: ");
//	int key;
//	scanf("%d",&key);
//	printf("\n키 값 %d가 %d개 삭제되었습니다.\n\n", key, removeElement(HT, key));
//	printHash(HT); // 배열은 주소 전달
//
//	return 0;
//}