#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char>> tree;


void preOrder(char v) {
	if (v == '.') return;
	cout << v;
	preOrder(tree[v].first);
	preOrder(tree[v].second);
}

void inOrder(char v) {
	if (v == '.') return;
	inOrder(tree[v].first);
	cout << v;
	inOrder(tree[v].second);
}

void postOrder(char v) {
	if (v == '.') return;
	postOrder(tree[v].first);
	postOrder(tree[v].second);
	cout << v;
}

int main() {
	int n;

	cin >> n;
	char root, left, right;

	while (n--) {
		cin >> root >> left >> right;
		tree[root] = { left, right };
	}

	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');

	return 0;
}
