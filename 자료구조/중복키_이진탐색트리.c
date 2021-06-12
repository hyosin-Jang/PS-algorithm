//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//// 중복키 있는 이진탐색트리
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
//	//이진탐색
//	if (isExternal(v)) //루트노드면 -1 리턴.
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
//	// 외부노드면, true 리턴
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
//	printf("%d개의 %d 값이 존재합니다.\n", count, k);
//
//}
//
//void insertItem(TreeType* T, int k) {
//	// 반복문으로 k값 다 찾기. 
//	TreeNode* w = treeSearch(T->root, k);
//
//	while (!isExternal(w)) //인터널이여도 뭔가 하게끔. 
//		w = treeSearch(w->right, k);
//
//	// 3. set node w to (k,e)
//	w->key = k; //w의 key값에 k 넣기
//	expandExternal(w);	//외부노드 확장
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
//		T->root = zs; //w가 루트노드인 경우
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
//	while (!isExternal(w)) { // 내부노드인 동안
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