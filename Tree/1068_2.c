#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

typedef struct Node {
	int key;
	int parent; // 부모인덱스, 만약 부모 삭제했으면 이거 0으로 바꿔주기
	int child; // 자식 개수
}Node;

Node node[51];
int arr[51];
int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}
int main() { 
	int n, p, k, root, cnt = 0; 
	scanf("%d", &n); 
	getchar();

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	getchar();

	printf("입력만받고 정렬 전\n");
	for (int i = 0; i < n;i++)
		printf("%d ", arr[i]);
	printf("\n");

	// arr 오름차순 정렬 - bubble sort
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}




	//qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);

	for (int i = 0; i < n ; i++)
		printf("%d ", arr[i]);
	printf("\n");


	//node 배열 초기화
	for (int i = 0; i < 51; i++) {
		node[i].key = -2;
		node[i].parent = -2;
		node[i].child = 0;
	}

	for(int i = 0; i < n; i++){ 
		int p = arr[i];
		if (p == -1) node[0].key = i; // p가 -1이면 루트노드 key있다고 설정
		else {
			node[i].key=i; 
			node[i].parent = p; // 부모 인덱스 표시
			node[p].child++;
			}
		} 

	scanf("%d", &k); 
	node[k].key = -2; // 지우는 것 = -2
	node[k].child = 0; // 자식 개수 -2

	for (int i = 0; i < n;i++) {
		if (i == 0)
			continue;
		int num = node[i].parent;
		if (node[num].key == -2) {
			node[i].child = 0;
			node[i].parent = -2;
			node[i].key = -2;
		}
	}
	
	//리프노드 = 부모는 있지만, 자신 key는 0
	for(int i = 0; i < n; i++) {
		printf("node[%2d].key: %2d\n", i, node[i].key);
		printf("node[%2d].parent: %2d\n", i, node[i].parent);
		printf("node[%2d].childnum: %2d\n", i, node[i].child);
		printf("\n");
		// 루트를 지웠다면
		if (node[0].key == -2)
			break;
		// 처음부터 순회하면서 parent는 인덱스니까 0이상
		if (node[i].key >0 && node[i].parent >= 0 && node[i].child==0)
			cnt++;
		printf("cnt: %d\n", cnt);
	}
	printf("%d", cnt); 
}

