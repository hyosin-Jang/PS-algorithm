#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int left, right;
}Node;

Node node[26];

// ���� ��ȸ
void preOrder(int cur) {
	printf("%c", cur + 'A');
	if (node[cur].left != -1)
		preOrder(node[cur].left);
	if (node[cur].right != -1)
		preOrder(node[cur].right);
	return;
}

// ���� ��ȸ
void inOrder(int cur) {
	if (node[cur].left != -1)
		inOrder(node[cur].left);
	printf("%c", cur + 'A');
	if (node[cur].right != -1)
		inOrder(node[cur].right);
	return;
}

// ���� ��ȸ
void postOrder(int cur) {
	if (node[cur].left != -1)
		postOrder(node[cur].left);
	if (node[cur].right != -1)
		postOrder(node[cur].right);
	printf("%c", cur + 'A');
	return;
}


int main() {
	int n;
	scanf("%d", &n);
	getchar(); // getchar �� �־��ֱ�!!

	// -1�� �ʱ�ȭ
	for (int i = 0; i < 26; i++)
		node[i].left = node[i].right = -1;

	for (int i = 0; i < n; i++) {
		char p, l, r;
		scanf("%c %c %c", &p, &l, &r);
		getchar();// ����Ű �Ա�
		if (l != '.')
			node[p - 'A'].left = l - 'A'; // ���ڷ� ����
		if (r != '.')
			node[p - 'A'].right = r - 'A'; // ���ڷ� ����

	}

	preOrder(0); printf("\n");
	inOrder(0); printf("\n");
	postOrder(0); printf("\n");
	return 0;
}