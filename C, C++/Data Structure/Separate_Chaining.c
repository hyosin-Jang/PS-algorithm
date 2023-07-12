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
//	// addFirst����
//	node->next = HT[v].next; // ���� ���� node�� next�� ���� HT[v]�� first ��������
//	HT[v].next = node;
//}
//int removeElement(HashType* HT, int key) {
//	int v = h(key);
//	int count = 0; // ���� Ű�� � �����ƴ���
//	// ������ ��� ���
//	// HashType�� �ּҸ� ����ϴ� ������ ���� p
//	// ����, HT[v]�� HashType��. HashType�� �ּ� ����!
//	HashType* p = &HT[v];
//	HashType* q;
//
//	while (p->next) {
//		if (p->next->key == key) {
//			count++;
//			//q�� ������ ���
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
//	printf("\n ������ Ű �Է�: ");
//	int key;
//	scanf("%d",&key);
//	printf("\nŰ �� %d�� %d�� �����Ǿ����ϴ�.\n\n", key, removeElement(HT, key));
//	printHash(HT); // �迭�� �ּ� ����
//
//	return 0;
//}