#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector <int> tree(200001);

int main() {
	int n, node1, node2;
	scanf("%d", &n);

	tree[1] = 1;

	for (int i = 1; i < n ; i++) {
		scanf("%d %d", &node1, &node2);

		// 1. node1이 tree에 있는 값인지 확인
		auto node = find(tree.begin(), tree.end(), node1);
		if (node == tree.end()) // node1은 찾을 수 없는 경우, 
		{
			if (tree[node2 * 2] == 0)
				tree[node2 * 2] = node1;
			else
				tree[node2 * 2 + 1] = node1;

		}
		else {
		// node1이 존재하는 경우, 
			if (tree[node1 * 2] == 0)
				tree[node1 * 2] = node2;
			else 
				tree[node1 * 2 + 1] = node2;
		}
	}

	for (int i = 2; i <= n; i++)
		printf("%d\n", (find(tree.begin(), tree.end(), i) - tree.begin()) / 2);

	return 0;
}
