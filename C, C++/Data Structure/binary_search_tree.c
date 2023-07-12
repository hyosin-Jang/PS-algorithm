//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//// �޼ҵ� ��������
//typedef struct TreeNode {
//	int key;
//	struct TreeNode* parent, * left, * right;
//	// �׳� TreeNode�� struct TreeNode ������?
//}TreeNode;
//
//typedef struct {
//	TreeNode* root;
//}TreeType;
//
//void initTree(TreeType* T) {
//	//��Ʈ ��� ����
//	T->root = (TreeNode*)malloc(sizeof(TreeNode));
//	//��Ʈ ��� �θ�, �����ڽ�, �������ڽ� �ʱ�ȭ
//	T->root->parent = T->root->left = T->root->right = NULL;
//}
//TreeNode* treeSearch(TreeNode* v, int k) {
//	if (!isExternal(v))
//		return v; 
//	if (k == v->key)
//		return v;
//	else if (k < v->key)
//		return treeSearch(v->left, k);
//	else
//		return treeSearch(v->right, k);
//
//}
//
//
//int findElement(TreeType* T, int k) {
//	TreeNode* w = treeSearch(T->root, k);
//	if (!isExternal(w))
//		return 0;
//	else
//		return w->key;
//}
//
//void expandExternal(TreeNode* w) {// 172p
//	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
//	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
//	l->left = NULL;
//	l->right = NULL;
//	l->parent = w;
//	r->left = NULL;
//	r->right = NULL;
//
//	r->parent = w;
//
//	w->left = l;
//	w->right = r;
//}
//
//int isExternal(TreeNode* w) {
//	// �ܺγ���, true ����
//	return (w->left == NULL && w->right == NULL);
//}
//
//void insertItem(TreeType* T, int k) {
//	// treesearch �Լ��� key�� �ִ��� Ȯ��
//	TreeNode* w = treeSearch(T->root, k);
//	if (!isExternal(w)) // ���ζ��
//		return;
//	else {
//		w->key = k;
//		expandExternal(w);	
//	}
//}
//
//
//TreeNode* sibling(TreeNode* z) {
//	if (z->parent->left == z)
//		return z->parent->right;
//	else
//		return z->parent->left;
//}
//
//TreeNode* reduceExternal(TreeType* T, TreeNode* z) {// 175p
//
//	TreeNode* w = z->parent;
//	TreeNode* g = w->parent;
//	TreeNode* zs = sibling(z);
//	zs->parent = g;
//
//	if (g == NULL) {
//		T->root = zs;
//	}
//	else {
//		if (w == g->left)
//			g->left = zs;
//		else
//			g->right = zs;
//	}
//}
//TreeNode* inOrderSucc(TreeNode* w) {
//	w = w->right;
//	while (w->left != NULL)
//		w = w->left;
//	return w;
//}
//
//int removeElement(TreeType* T, int k) {
//	TreeNode* w = treeSearch(T->root, k);
//	if (!isExternal(w))
//		return 0;
//
//	TreeNode* z, *y;
//	z = w->left;
//	// z�� ���γ����
//	if (!isExternal(z))
//		//�����ʳ�嵵����
//		z = w->right;
//	if (!isExternal(z))
//		// z�� ���γ����
//		reduceExternal(T, z);
//	//case 2 �� ��� ���� ��������� ã��
//	else
//	{
//		z = inOrderSucc(w);
//		y = z->parent; //�����Ǿ��� ��
//		w->key = y->key;
//		reduceExternal(T, z);
//	}
//	return k;
//}
//
//void preOrder(TreeNode* root) {
//	if (!isExternal(root))
//		return; // �������� return
//	printf("[%d]", root->key); // 1. V���
//	preOrder(root->left); // 2. L���
//	preOrder(root->right); //3. R���
//}
//
//
//int main() {
//	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
//	initTree(T);
//
//	insertItem(T, 9);
//	insertItem(T, 2);
//	insertItem(T, 1);
//	insertItem(T, 7);
//	insertItem(T, 15);
//	insertItem(T,11);
//
//	preOrder(T->root); printf("\n");
//	getchar();
//
//	printf("������ Ű �Է�: ");
//	int key;
//	scanf("%d", &key);
//	removeElement(T, key);
//	preOrder(T->root); printf("\n");
//
//
//}