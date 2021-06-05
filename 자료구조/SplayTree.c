#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

// �� ����(����, ����, Ž��)�������� splay�ؾ� ��. 
typedef struct TreeNode {
	int key, height; // ������ ���̱���(�¿���) �� ���
	struct TreeNode* parent, * left, * right;
	// �׳� TreeNode�� struct TreeNode ������?, c�� �����ؾߴ�
}TreeNode;

typedef struct {
	TreeNode* root;
}TreeType;

void initTree(TreeType* T) {
	// ��Ʈ��常���
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	// parent, left, right, NULL�� �ʱ�ȭ
	T->root->parent = T->root->left = T->root->right = NULL;
	// �¿����� 0�̴ϱ� height 0���� �ʱ�ȭ
	T->root->height = 0;
}

int isExternal(TreeNode* w) {
	return (w->left == NULL && w->right == NULL);
}

TreeNode* treeSearch(TreeNode* v, int k) {
	// root�� ,k ���� �ִ��� ����. 
	if (isExternal(v)) // ��Ʈ�� �ܺγ���� 
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
// ������ �������� �˻��ؼ� true�� 1, false�� 0
int heightUpdateAndBalanceCheck(TreeNode* w) {
	// w���� ��Ʈ�� �ö󰡸鼭, ó������ balance�ȸ´� �� return 
	TreeNode* l, * r;
	int b; // b= balance

	if (w == NULL) /// Q. w�� NULL�̸� �������
		return 1; // ������ �ȱ����ٴ� ��

	l = w->left;
	r = w->right;

	w->height = max(r->height, l->height) + 1; // +1�ϴ°�, ���߿� ū�����ٰ� ���� ��尡 �θ���ϱ� �ϳ� �����ִ� ��
	b = r->height - l->height;
	if (b * b < 2) // �����ϼ��� �����ϱ� �������ְ�
		return 1; // -1, 1, 0 �̳����� true => �����´�.
	else
		return 0; // false. �׿ܴ� 2���� ũ�ų� ���ٴ� �� = ���� �ȸ´�.
}
TreeNode* restructure(TreeType* T, TreeNode* x) {
	// ���ڷ� ���� x�� ���� �Ʒ� �ִ� ��. 
	TreeNode* y, * z, * a, * b, * c, * T0, * T1, * T2, * T3;

	// y�� x�� �θ�
	y = x->parent;
	// z�� x�� �θ�
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
	//3. z�� ��Ʈ�� �ϴ� ��Ʈ���� b�� ��Ʈ�� �ϴ� ��Ʈ���� ��ü 
	if (z == T->root) { // ����, z�� ��Ʈ�����
		T->root = b;
		b->parent = NULL;
	}
	else if (z->parent->left == z) { // z�� �θ��� ���� �ڽ��̶��
		z->parent->left = b;
		b->parent = z->parent;
	}
	else // if(z->parent->right == z) z�� �θ��� ������ �ڽ��̶��
	{
		z->parent->right = b;
		b->parent = z->parent;
	}

	//4. T0�� T1�� ���� a�� ���� �� ������ ��Ʈ���� �����. 
	a->left = T0;
	T0->parent = a;
	a->right = T1;
	T1->parent = a;
	a->height = max(T0->height, T1->height) + 1; //���̵� ����

	//5. T2�� T3�� ���� c�� ���� �� ������ ��Ʈ���� �����.
	c->left = T2;
	T2->parent = c;
	c->right = T3;
	T3->parent = c;
	c->height = max(T2->height, T3->height) + 1;

	//6.a�� c�� ���� b�� ���� �� ������ �ڽ����� �����. 
	b->left = a;
	a->parent = b;
	b->right = c;
	c->parent = b;
	b->height = max(a->height, c->height) + 1;

	return b;
}

void searchAndFixAfterInsertion(TreeType* T, TreeNode* w) {
	TreeNode* z = w; // ���۳��
	TreeNode* y, * x =NULL;

	// 1. --------------------------
	while (heightUpdateAndBalanceCheck(z)) {
		if (z == NULL)
			return; // ��Ʈ���� ���ٴ°Ŵϱ�
		z = z->parent; // �θ� ���� �̵��ؼ� balance üũ
	}
	//2. -------------------- �߶��� �ȸ����� ����� ��������
	if (z->left->height > z->right->height)
		y = z->left; // z�� �����ڽ��� y�� �ֱ�
	else
		y = z->right;

	//3.--------------------- y�� ���� �ڽ��� x�� ����
	if (y->left->height > y->right->height)
		x = y->left;
	else if (y->left->height < y->right->height)
		x = y->right;

	//4.---------------------- ����
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
		return; // �������� return
	printf("[%d] ", root->key); // 1. V���
	preOrder(root->left); // 2. L���
	preOrder(root->right); //3. R���
}


// ���÷��� Ʈ���� Ʈ���� ��尡 ���ٵ� ��, ���÷��̵Ǵ� ����Ž��Ʈ��
// ���x�� ���� => ��� x�� ��Ʈ�� �̵�
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

// x�� ��Ʈ���� �ٲٴ� �Լ�
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

	//6. ���ȣ��
	splay(T, x);
}

void insertItem(TreeType* T, int k) {
	// k���� ����ִ� treeNode�� w�� �ްԵ�.
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w)) //w�� ���γ���� �̹� ���� �ִٴ� ���̴ϱ� return 
		return;
	else {
		w->key = k;
		expandExternal(w);
		// ������ �Ŀ� ���̱��� ���߱�
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