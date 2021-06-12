//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//// �ߺ�Ű �ִ� ����Ž��Ʈ��
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
//	//����Ž��
//	if (isExternal(v)) //��Ʈ���� -1 ����.
//		return v;
//	if (k == v->key)
//		return v;
//	else if (k < v->key)
//		return treeSearch(v->left, k);
//	else
//		return treeSearch(v->right, k);
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
//	r->parent = w;
//	w->left = l;
//	w->right = r;
//}
//
//int isExternal(TreeNode* w) {
//	// �ܺγ���, true ����
//	return (w->left == NULL && w->right == NULL);
//}
//
//void findAllElements(TreeType* T, int k) {
//	int count = 0;
//	TreeNode* w = treeSearch(T->root, k); 
//	while (!isExternal(w)) {
//		count++;
//		w = treeSearch(w->right, k);
//	}
//	printf("%d���� %d ���� �����մϴ�.\n", count, k);
//
//}
//
//void insertItem(TreeType* T, int k) {
//	// �ݺ������� k�� �� ã��. 
//	TreeNode* w = treeSearch(T->root, k);
//
//	while (!isExternal(w)) //���ͳ��̿��� ���� �ϰԲ�. 
//		w = treeSearch(w->right, k);
//
//	// 3. set node w to (k,e)
//	w->key = k; //w�� key���� k �ֱ�
//	expandExternal(w);	//�ܺγ�� Ȯ��
//	
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
//		T->root = zs; //w�� ��Ʈ����� ���
//	}
//	else {
//		if (w == g->left)
//			g->left = zs;
//		else
//			g->right = zs;
//	}
//	return zs;
//}
//
//TreeNode* inOrderSucc(TreeNode* w) {
//	w = w->right;
//	while (w->left != NULL)
//		w = w->left;
//	return w;
//}
//
//void removeAllElement(TreeType* T, int k) {
//	TreeNode* w = treeSearch(T->root, k);
//	TreeNode* z, * y;
//
//	while (!isExternal(w)) { // ���γ���� ����
//		z = w->left;
//
//		if (!isExternal(z))
//			z = w->right;
//		if (isExternal(z))
//			w = reduceExternal(T, z);
//		else
//		{
//			z = inOrderSucc(w);
//			y = z->parent; 
//			w->key = y->key;
//			reduceExternal(T, z);
//		}
//		w = treeSearch(w, k);
//	}
//}
//
//void preOrder(TreeNode* root) {
//	if (isExternal(root))
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
//	insertItem(T, 15);
//	insertItem(T, 1);
//	insertItem(T, 15);
//	insertItem(T, 7);
//	insertItem(T, 15);
//	insertItem(T, 11);
//
//	preOrder(T->root); printf("\n");
//	getchar();
//
//	findAllElements(T, 15);
//	removeAllElement(T, 15);
//
//	preOrder(T->root); printf("\n");
//	getchar();
//
//
//}