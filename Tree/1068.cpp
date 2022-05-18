#include <iostream>
#include <vector>
using namespace std;


void deleteNode(int node, vector<vector<int>> &tree) { // node를 삭제함
	for (int i = tree[node].size(); i >= 0; i--) {
		deleteNode(tree[node][i], tree);
		tree[node].pop_back();
	}
}


int main() {
	int n, node;

	vector<vector<int>> tree(n, vector<int>(n, 0));
	cin >> n;
	for (int i = 0; i < n; i++) { // 입력
		cin >> node;
		tree[i].push_back(node);
	}

	cin >> node;
	deleteNode(node, tree);
	// 부모가 2인 애들을 다 지움
	// 그럼 다시 부모가 a인 애를 지움

	// Q. 리프 노드를 어떻게 알 수 있을까?

	// 자식 개수가 0인 노드

	// -1 0 0 1 1

	// Q. 자식 개수가 여러 개 있을 수 있지?

	// 0 1 2 3 4 5 6 7 8 9 10
	//-1 0 0 1 1
	//   
	//   

	// 자식이 없으면 리프 노드. 

	// 2차원 벡터로 구현할 것 .

	return 0;
}
