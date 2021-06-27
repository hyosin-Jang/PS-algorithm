#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

typedef struct Node {
	int key;
	int parent; // �θ��ε���, ���� �θ� ���������� �̰� 0���� �ٲ��ֱ�
	int child; // �ڽ� ����
}Node;

Node node[51];
int arr[51];
int compare(const void* a, const void* b)    // �������� �� �Լ� ����
{
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}
int main() { 
	int n, p, k, root, cnt = 0; 
	scanf("%d", &n); 
	getchar();

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	getchar();

	printf("�Է¸��ް� ���� ��\n");
	for (int i = 0; i < n;i++)
		printf("%d ", arr[i]);
	printf("\n");

	// arr �������� ���� - bubble sort
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


	//node �迭 �ʱ�ȭ
	for (int i = 0; i < 51; i++) {
		node[i].key = -2;
		node[i].parent = -2;
		node[i].child = 0;
	}

	for(int i = 0; i < n; i++){ 
		int p = arr[i];
		if (p == -1) node[0].key = i; // p�� -1�̸� ��Ʈ��� key�ִٰ� ����
		else {
			node[i].key=i; 
			node[i].parent = p; // �θ� �ε��� ǥ��
			node[p].child++;
			}
		} 

	scanf("%d", &k); 
	node[k].key = -2; // ����� �� = -2
	node[k].child = 0; // �ڽ� ���� -2

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
	
	//������� = �θ�� ������, �ڽ� key�� 0
	for(int i = 0; i < n; i++) {
		printf("node[%2d].key: %2d\n", i, node[i].key);
		printf("node[%2d].parent: %2d\n", i, node[i].parent);
		printf("node[%2d].childnum: %2d\n", i, node[i].child);
		printf("\n");
		// ��Ʈ�� �����ٸ�
		if (node[0].key == -2)
			break;
		// ó������ ��ȸ�ϸ鼭 parent�� �ε����ϱ� 0�̻�
		if (node[i].key >0 && node[i].parent >= 0 && node[i].child==0)
			cnt++;
		printf("cnt: %d\n", cnt);
	}
	printf("%d", cnt); 
}

