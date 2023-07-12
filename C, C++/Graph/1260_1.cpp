#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1000 + 1;
int adjacent[MAX][MAX];
int visited[MAX];
int visitedBFS[MAX];
queue <int> Q;
int n, m, v;

void DFS(int num) { 
	visited[num] = 1;
	cout << num << " ";

	for (int i = 1; i <= n; i++)
		if (adjacent[num][i] == 1 && visited[i]==0) 
			DFS(i); // i번재 node 탐색함
}

void BFS(int num) {

	Q.push(num);
	// 방문했다고 표시
	visitedBFS[num] = 1;


	while (!Q.empty()) {

		num = Q.front();
		Q.pop();

		cout << num << " ";

		// 큐에다가 다음에 방문할 인접 정점 저장
		for (int i = 1; i <= n; i++)
			if (adjacent[num][i]==1 && !visitedBFS[i]) {
				visitedBFS[i] = 1;
				Q.push(i); // 인접 노드 저장
			}
	}

}

int main() {
	
	int n1, n2;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		adjacent[n1][n2] = 1;
		adjacent[n2][n1] = 1;
	}

	DFS(v);
	cout << "\n";
	BFS(v);

	return 0;
}
