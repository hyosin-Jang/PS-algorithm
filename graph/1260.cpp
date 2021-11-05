#include <iostream>
#include <queue>


using namespace std;
int N, M, V;

const int MAX = 1001;
int adjacent[MAX][MAX];
bool visited[MAX];
queue<int> q;

void DFS(int idx) {
	cout << idx << " ";
	
	for (int i = 1; i <= N; i++) {
		if (adjacent[idx][i] && !visited) {
			visited[i] = 1;
			DFS(i);
		}

	}

}

void BFS(int idx) {
	q.push(idx);
	visited[idx] = 1;

	while (!q.empty()) {
		idx = q.front();
		q.pop();

		cout << idx << " ";

		for(int i =1 ; i<=N ; i++)
			if (adjacent[idx][i] && !visited[i]) {
				visited[i] = 1;
				q.push(i);		
			}
	}
}




int main() {

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adjacent[a][b] = 1;
		adjacent[b][a] = 1;
	}
	visited[V] = 1;
	DFS(V);
	cout << endl;

	memset(visited, false, sizeof(visited);
	BFS(V);
	cout << endl;

	return 0;
}
