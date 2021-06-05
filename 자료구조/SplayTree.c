#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

// 각 과정(삽입, 제거, 탐색)에서마다 splay해야 함. 
typedef struct TreeNode {
	int key, height; // 각각의 높이균형(좌우차) 값 기억
	struct TreeNode* parent, * left, * right;
	// 그냥 TreeNode랑 struct TreeNode 차이점?, c언어도 공부해야댐
}TreeNode;

typedef struct {
	TreeNode* root;
}TreeType;

void initTree(TreeType* T) {
	// 루트노드만들고
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	// parent, left, right, NULL로 초기화
	T->root->parent = T->root->left = T->root->right = NULL;
	// 좌우차가 0이니까 height 0으로 초기화
	T->root->height = 0;
}

int isExternal(TreeNode* w) {
	return (w->left == NULL && w->right == NULL);
}

TreeNode* treeSearch(TreeNode* v, int k) {
	// root랑 ,k 값이 있는지 받음. 
	if (isExternal(v)) // 루트가 외부노드라면 
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key)
		return treeSearch(v->left, k);
	else
		return treeSearch(v->right, k);
}


void expandExternal(TreeNode* w) {// 172p
	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
	l->left = NULL;
	l->right = NULL;
	l->parent = w;
	r->left = NULL;
	r->right = NULL;
	r->parent = w;
	w->left = l;
	w->right = r;
}
int findElement(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w))
		return 0;
	else
		return w->key;
}
// 균형이 깨졌는지 검사해서 true면 1, false면 0
int heightUpdateAndBalanceCheck(TreeNode* w) {
	// w부터 루트로 올라가면서, 처음으로 balance안맞는 애 return 
	TreeNode* l, * r;
	int b; // b= balance

	if (w == NULL) /// Q. w가 NULL이면 모조노드
		return 1; // 균형이 안깨졌다는 뜻

	l = w->left;
	r = w->right;

	w->height = max(r->height, l->height) + 1; // +1하는건, 둘중에 큰값에다가 지금 노드가 부모노드니까 하나 더해주는 것
	b = r->height - l->height;
	if (b * b < 2) // 음수일수도 있으니까 제곱해주고
		return 1; // -1, 1, 0 이나오면 true => 균형맞다.
	else
		return 0; // false. 그외는 2보다 크거나 같다는 것 = 균형 안맞다.
}
TreeNode* restructure(TreeType* T, TreeNode* x) {
	// 인자로 받은 x는 제일 아래 있는 애. 
	TreeNode* y, * z, * a, * b, * c, * T0, * T1, * T2, * T3;

	// y는 x의 부모
	y = x->parent;
	// z는 x의 부모
	z = y->parent;

	if (z->key < y->key && y->key < x->key) //RR
	{
		a = z;
		b = y;
		c = x;
		T0 = a->left;
		T1 = b->left;
		T2 = c->left;
		T3 = c->right;

	}
	else if (x->key < y->key && y->key < z->key) //LL
	{
		a = x;
		b = y;
		c = z;
		T0 = a->left;
		T1 = a->right;
		T2 = b->right;
		T3 = c->right;
	}

	else if (z->key < x->key && x->key < y->key) //RL
	{
		a = z;
		b = x;
		c = y;
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;	}

	else //LR
	{
		a = y;
		b = x;
		c = z;
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}
	//3. z를 루트로 하는 부트리를 b를 루트로 하는 부트리로 대체 
	if (z == T->root) { // 만약, z가 루트노드라면
		T->root = b;
		b->parent = NULL;
	}
	else if (z->parent->left == z) { // z가 부모의 왼쪽 자식이라면
		z->parent->left = b;
		b->parent = z->parent;
	}
	else // if(z->parent->right == z) z가 부모의 오른쪽 자식이라면
	{
		z->parent->right = b;
		b->parent = z->parent;
	}

	//4. T0와 T1을 각각 a의 왼쪽 및 오른쪽 부트리로 만든다. 
	a->left = T0;
	T0->parent = a;
	a->right = T1;
	T1->parent = a;
	a->height = max(T0->height, T1->height) + 1; //높이도 갱신

	//5. T2와 T3를 각각 c의 왼쪽 및 오른쪽 부트리로 만든다.
	c->left = T2;
	T2->parent = c;
	c->right = T3;
	T3->parent = c;
	c->height = max(T2->height, T3->height) + 1;

	//6.a와 c를 각각 b의 왼쪽 및 오른쪽 자식으로 만든다. 
	b->left = a;
	a->parent = b;
	b->right = c;
	c->parent = b;
	b->height = max(a->height, c->height) + 1;

	return b;
}

void searchAndFixAfterInsertion(TreeType* T, TreeNode* w) {
	TreeNode* z = w; // 시작노드
	TreeNode* y, * x =NULL;

	// 1. --------------------------
	while (heightUpdateAndBalanceCheck(z)) {
		if (z == NULL)
			return; // 루트까지 갔다는거니까
		z = z->parent; // 부모 노드로 이동해서 balance 체크
	}
	//2. -------------------- 발란스 안맞으면 여기로 빠져나옴
	if (z->left->height > z->right->height)
		y = z->left; // z의 높은자식을 y에 넣기
	else
		y = z->right;

	//3.--------------------- y의 높은 자식을 x라 하자
	if (y->left->height > y->right->height)
		x = y->left;
	else if (y->left->height < y->right->height)
		x = y->right;

	//4.---------------------- 개조
	restructure(T, x);
}

TreeNode* sibling(TreeNode* z) {
	if (z->parent->left == z)
		return z->parent->right;
	else
		return z->parent->left;
}

void preOrder(TreeNode* root) {
	if (isExternal(root))
		return; // 모조노드면 return
	printf("[%d] ", root->key); // 1. V출력
	preOrder(root->left); // 2. L출력
	preOrder(root->right); //3. R출력
}


// 스플레이 트리는 트리의 노드가 접근된 후, 스플레이되는 이진탐색트리
// 노드x에 접근 => 노드 x를 루트로 이동
void rightRotate(TreeType* T, TreeNode* x, TreeNode* y) {
	TreeNode* T0, * T1, * T2, * p;
	p = y->parent;
	T0 = x->left;
	T1 = x->right;
	T2 = y->right;

	y->parent = x;
	x->parent = p;

	if (x->parent == NULL)
		T->root = x;
	
	x->left = T0;
	y->left = T1;
	y->right = T2;
}

void leftRotate(TreeType* T, TreeNode* x, TreeNode* y) {
	TreeNode* T0, * T1, * T2, * p;
	p = y->parent;
	T0 = y->left;
	T1 = x->left;
	T2 = x->right;

	y->parent = x;
	x->parent = p;

	if (x->parent == NULL)
		T->root = x;

	x->right = T2;
	y->left = T0;
	y->right = T1;
}

// x를 루트노드로 바꾸는 함수
void splay(TreeType* T, TreeNode* x) {
	TreeNode* p, * g;
	//1.
	if (T->root == x)
		return;
	//2. 
	if (T->root == x->parent) {
		if (x == T->root->left)
			rightRotate(T, x, T->root);
		else
			leftRotate(T, x, T->root);
		return;
	}
	//3.
	p = x->parent;
	g = p->parent;

	//5.
	if (x == g->left->left) {
		rightRotate(T, p, g);
		rightRotate(T, x, p);
	}
	else if (x == g->right->right) {
		leftRotate(T, p, g);
		leftRotate(T, x, p);
	}

	else if (x == g->right->left) {
		rightRotate(T, x, p);
		leftRotate(T, x, g);
	}

	else {
		leftRotate(T, x, p);
		rightRotate(T, x, g);
	}

	//6. 재귀호출
	splay(T, x);
}

void insertItem(TreeType* T, int k) {
	// k값이 들어있는 treeNode를 w로 받게됨.
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w)) //w가 내부노드라면 이미 값이 있다는 것이니까 return 
		return;
	else {
		w->key = k;
		expandExternal(w);
		// 삽입한 후에 높이균형 맞추기
		searchAndFixAfterInsertion(T, w);
	}
	splay(T, w);
}
int main() {
	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
	initTree(T);

	insertItem(T, 9);
	insertItem(T, 2);
	insertItem(T, 1);
	insertItem(T, 7);
	insertItem(T, 15);
	insertItem(T, 11);

	preOrder(T->root); printf("\n");
	getchar();
	preOrder(T->root); printf("\n");


}