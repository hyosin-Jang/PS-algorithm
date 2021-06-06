#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 13

typedef struct {
	int key;
	int probeCount; //몇번에 걸쳐서 저장이되는지
}Bucket;

typedef struct {
	Bucket A[M];
}HashType;

void initHash(HashType* HT) {
	for (int i = 0; i < M; i++) {
		HT->A[i].key = 0;
		HT->A[i].probeCount = 0;
	}
}

int h(int key) {
	return key % M;
}

//이중해싱에선, 13보다 작은 가장 큰 소수를 사용
int h2(int key) {
	return 11 - (key % 11);
}

//선형조사법
int getNextBucketLinear(int v, int i) {
	return (v + i) % M;
}

//이차조사법
int getNextBucketQuadratic(int v, int i) {
	return (v + i*i) % M;

}

//이중해싱법
int getNextBucketDouble(int v, int i, int key) {
	return (v + i * h2(key)) % M;
}
int isEmpty(HashType* HT, int b) {
	// b는 인덱스
	return HT->A[b].key == 0;
	// 0이면 비어있는 것
}

int findElement(HashType* HT, int key) {
	int v = h(key); //v는 위치
	int i = 0;

	while (i < M) {
		int b = getNextBucketQuadratic(v, i); //=> 이차조사법

		if (isEmpty(HT, b))
			return 0;
		else if (HT->A[b].key == key)
			return key;
		else
			i++;
	}
	return 0;
}

void insertItem(HashType* HT, int key) {
	int v = h(key); //v는 위치
	int i = 0;
	int count = 0;//시도횟수
	while (i < M) {
		count++;
		//int b = getNextBucketLinear(v, i); //선형조사법
		int b = getNextBucketQuadratic(v, i); //이차조사법
		//int b = getNextBucketDouble(v, i, key); //이중해싱법
		
		if (isEmpty(HT, b)) {
			HT->A[b].key = key;
			HT->A[b].probeCount = count;
			return; // 삽입됐으면 return
		}
		else
			i++;
	}
}


int removeElement(HashType* HT, int key) {
	int v = h(key); //v는 위치
	int i = 0;

	while (i < M) {
		int b = getNextBucketQuadratic(v, i); //이차조사법

		if (isEmpty(HT, b)) 
			return 0; 
		
		else if (HT->A[b].key == key) {
			HT->A[b].key = 0; //key값을 0으로 만들면, 비어있다는 의미!
			return key;
		}
		else
			i++;
	}
	return 0;
}




void printHashTable(HashType* HT) {
	// probe는 시도횟수.
	printf("Bucket Key Probe\n");
	printf("============================\n");
	for (int i = 0; i < M; i++)
		printf("HT[%02d]: %2d    %d\n",i, HT->A[i].key, HT->A[i].probeCount);
}

int main(){
	HashType HT;
	initHash(&HT);

	insertItem(&HT,25 );
	insertItem(&HT, 13);
	insertItem(&HT, 16);
	insertItem(&HT, 15);
	insertItem(&HT, 7);
	insertItem(&HT,28 );
	insertItem(&HT, 31);
	insertItem(&HT, 1);
	insertItem(&HT, 38);
	printHashTable(&HT);

	int key;
	printf("탐색할 키 입력: ");
	scanf("%d",&key);
	if (findElement(&HT, key))
		printf("\n키 값 %d이(가) 존재합니다.\n", key);
	else
		printf("\n키 값 %d이(가) 없습니다.\n", key);


	printf("삭제할 키 입력: ");
	scanf("%d", &key);
	if (removeElement(&HT, key))
		printf("\n키 값 %d이(가) 삭제되었습니다.\n", key);
	else
		printf("\n키 값 %d이(가) 없습니다.\n", key);
	printf("\n");
	printHashTable(&HT);


	return 0;

}