#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, parent, del, cnt = 0, k = 0, num = 0;

typedef struct TreeNode {
	int key;
	TreeNode* left, * right;
}TreeNode;

typedef struct TreeType {
	TreeNode* root;
}TreeType;

void initTree(TreeType* T) {
	// ��Ʈ��常���
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	T->root->left = T->root->right = NULL;
}
int dfs(TreeNode* T) {
	// 1. k�� �����ٸ�
	if (T->key == NULL) {
		return 0;
	}
	// 2. 0�� �ƴ� k�� 0�̶��, 
	if (k != 0 && T->key == NULL) {
		return 0;
	}
	// 3. ��������� cnt++�ϱ�
	if (T->left->key == NULL && T->right->key == NULL) {
		cnt++;
		return 0;
	}
	// 4. ���� �ڽ����� ����
	if (T->left->key != NULL)
		dfs(T->left);
	// 4. ������ �ڽ����� ����
	if (Tree[2 * k + 2] != 0)
		dfs(2 * k + 2);

	printf("������ ��");

	return 0;
}
int isExternal(TreeNode* w) {
	// �ܺγ���, true ����
	return (w->left == NULL && w->right == NULL);
}

void expandExternal(TreeNode* w) {
	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
	l->left = NULL;
	l->right = NULL;
	r->left = NULL;
	r->right = NULL;
	w->left = l;
	w->right = r;
}
TreeNode* treeSearch(TreeNode* v, int k) {
	//����Ž��
	if (isExternal(v)) //��Ʈ���� -1 ����.
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key)
		return treeSearch(v->left, k);
	else
		return treeSearch(v->right, k);
}
TreeNode* findElement(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w))
		return 0;
	else
		return w;
}

int main() {
	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
	initTree(T);
	TreeNode* w;
	scanf("%d", &n);

	// �����ϸ� 1, ������ 0
	for (int i = 0; i < n;i++) {
		scanf("%d", &parent);
		if (parent == -1)
			T->root->key = k;
		else {
			// parent ���ã��
			w = findElement(T, parent);
			if (w->left == NULL) {
				w->left = k;
				expandExternal(w);
			}
			else {
				expandExternal(w);
				w->right = k;
			}
			}
		k++;
	}
	
	scanf("%d", &del);
	w = findElement(T, del);
	w->key = NULL;
	dfs(T->root);
	printf("%d", cnt);
	return 0;
}