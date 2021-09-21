#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000 + 1;

int N, M;
int newNext = 0;
int visited[MAX] = {0,};
int connectedComponent=0;
vector <int> graph[MAX];

void findConnectedComponent(int nodeNum) {
	visited[nodeNum] = 1; 

	//DFS
	for (int i = 0; i < graph[nodeNum].size(); i++) {
		int next = graph[nodeNum][i];
		int count = 0;
		if (visited[next]) {
			count++;
			if (count == graph[nodeNum].size()) {
				connectedComponent++;
				for (int j = 1; j <= N; j++) 
					if (visited[j] != 1) {
						newNext = j;
						break;
					} 
				findConnectedComponent(newNext);
			}
		}
		else
			findConnectedComponent(next);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
		
	}
	findConnectedComponent(1);

	cout << connectedComponent;

	return 0;


}
