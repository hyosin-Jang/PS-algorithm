//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//// 메소드 순서보기
//typedef struct TreeNode {
//	int key;
//	struct TreeNode* parent, * left, * right;
//	// 그냥 TreeNode랑 struct TreeNode 차이점?
//}TreeNode;
//
//typedef struct {
//	TreeNode* root;
//}TreeType;
//
//void initTree(TreeType* T) {
//	//루트 노드 생성
//	T->root = (TreeNode*)malloc(sizeof(TreeNode));
//	//루트 노드 부모, 왼쪽자식, 오른쪽자식 초기화
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
//	// 외부노드면, true 리턴
//	return (w->left == NULL && w->right == NULL);
//}
//
//void insertItem(TreeType* T, int k) {
//	// treesearch 함수로 key값 있는지 확인
//	TreeNode* w = treeSearch(T->root, k);
//	if (!isExternal(w)) // 내부라면
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
//	// z가 내부노드라면
//	if (!isExternal(z))
//		//오른쪽노드도보기
//		z = w->right;
//	if (!isExternal(z))
//		// z가 내부노드라면
//		reduceExternal(T, z);
//	//case 2 의 경우 먼저 중위계승자 찾기
//	else
//	{
//		z = inOrderSucc(w);
//		y = z->parent; //삭제되어질 애
//		w->key = y->key;
//		reduceExternal(T, z);
//	}
//	return k;
//}
//
//void preOrder(TreeNode* root) {
//	if (!isExternal(root))
//		return; // 모조노드면 return
//	printf("[%d]", root->key); // 1. V출력
//	preOrder(root->left); // 2. L출력
//	preOrder(root->right); //3. R출력
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
//	printf("삭제할 키 입력: ");
//	int key;
//	scanf("%d", &key);
//	removeElement(T, key);
//	preOrder(T->root); printf("\n");
//
//
//}